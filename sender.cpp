#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Header.h"

#define MAXLINE 1024

std::string readFromFile(std::string fileName);

int main(int argc, char* argv[]) {

   std::string host; //IP to sent to
   int port; //Port being sent to
   int sockfd; // File descriptor of socket
   struct sockaddr_in servaddr, cliaddr;
   char *message = "Message from sender";
   char buffer[MAXLINE];

   // If there is an incorrect amount of inputs
   if (argc != 5 && argc != 3) {
      std::cerr << "Usage: " << argv[0] << " [-f DATA_FILE] HOST PORT" << std::endl;
      return 1;
   // If file name is inputted
   } else if (argc == 5){
      // Makes sure input is sender -f datafile host port
      if (0 != strcmp(argv[1], "-f")) {
	 std::cerr << "Usage: " << argv[0] << " [-f DATA_FILE] HOST PORT" << std::endl;
	 return 1;
      } else {
	 message = (char *)readFromFile(argv[2]).c_str();
	 host = argv[3];
	 port = atoi(argv[4]);
      }
   // No file name inputted
   } else {
      host = argv[1];
      port = atoi(argv[2]);
   }

   std::cout <<"host: " <<host <<" " <<"\nport: " <<port <<std::endl;

   // Creates the unbounded socket in IPv4
   // socket(int domain, int type, int protocol)
   if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      std::cerr <<"socket creation broke" <<std::endl;
      return 1;
   }

   memset(&servaddr, 0, sizeof(servaddr));
   memset(&cliaddr, 0, sizeof(cliaddr));

   // Completes server info
   servaddr.sin_family    = AF_INET; // IPv4
   servaddr.sin_addr.s_addr = INADDR_ANY;
   servaddr.sin_port = htons(port);

   // Binds the socket
   // bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
   if(bind(sockfd,(const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) {
      std::cerr <<"bind failed" <<std::endl;
      return 1;
   }

   int n;
   socklen_t len;

   len = sizeof(cliaddr);

   // Recieve messge from socket
   // recvfrom(int sockfd, void *buf, size_t len, int flags,
   //            struct sockaddr *src_addr, socklen_t *addrlen);
   n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);

   buffer[n] = '\0';

   std::cout <<"Message from receiver:\n" <<buffer <<std::endl;

   // Send message to socket
   // sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen)
   sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM,
	  (const struct sockaddr *)&cliaddr, len);

   std::cout <<"Sent message to " <<host <<std::endl;

   return 0;
}

std::string readFromFile(std::string fileName) {
   std::ifstream ifs(fileName);
   std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

   return content;
}
