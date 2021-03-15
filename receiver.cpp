#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h>
#include <fstream>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#define MAXLINE 1024

std::string readFromFile(std::string fileName);

int main(int argc, char* argv[]) {
   
   int port; //Port being sent to
   int sockfd; //Fie descriptor of socket
   struct sockaddr_in servaddr;
   char *message = "Message from receiver";
   char buffer[MAXLINE];
   
  if (argc != 4 && argc != 2) {
    std::cerr << "Usage: " << argv[0] << " [-f DATA_FILE] PORT" << std::endl;
    return 1;
  } else if (argc == 4){
     if (0 != strcmp(argv[1], "-f")) {
	std::cerr << "Usage: " << argv[0] << " [-f DATA_FILE] PORT" << std::endl;
	return 1;
     } else {
	port = atoi(argv[3]);
	message = (char *)readFromFile(argv[2]).c_str();
     }
  } else { //TODO remove reduntant else
    port = atoi(argv[1]);
  }

   // Makes socket file
   if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      std::cerr <<"Socket Creation Failed";
      return 1;
   }

   memset(&servaddr, 0, sizeof(servaddr));
					       
   // Fills server information 
   servaddr.sin_family = AF_INET; 
   servaddr.sin_port = htons(port); 
   servaddr.sin_addr.s_addr = INADDR_ANY; 

   int n;
   socklen_t len;

   sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));

   n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
   
   buffer[n] = '\0';
   std::cout <<"Message from sender:\n" <<buffer <<std::endl;

   close(sockfd);
   
  return 0;
}

std::string readFromFile(std::string fileName) {
   std::ifstream ifs(fileName);
   std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    
   return content;
}
