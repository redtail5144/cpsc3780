#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#define MAXLINE 1024

int main(int argc, char* argv[]) {
   std::string data;
   int port;
   int sockfd;
   struct sockaddr_in servaddr;
   char *fuck = "Message from receiver";
   char buffer[MAXLINE];
   
  if (argc != 4 && argc != 2) {
    std::cerr << "Usage: " << argv[0] << " [-f DATA_FILE] PORT" << std::endl;
    return 1;
  } else if (argc == 4){
    std::string data(argv[2]);
    std::string port(argv[3]);
    data = argv[2];
    port = atoi(argv[3]);
  } else {
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

   sendto(sockfd, (const char *)fuck, strlen(fuck), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));

   n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
   
   buffer[n] = '\0';
   std::cout <<"Server: " <<buffer <<std::endl;

   close(sockfd);
   
  return 0;
}
