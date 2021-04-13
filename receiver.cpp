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
#include <bitset>
#include <sstream>
#include "Header.h"

#define MAXLINE 1024

std::string readFromFile(std::string fileName);
std::string binToText(std::string bin);
void error(std::string er) {
   std::cerr<< er;
   exit(0);
}


int main(int argc, char* argv[]) {

   int port; //Port being sent to
   int sockfd; //Fie descriptor of socket
   struct sockaddr_in servaddr;
   char *message = "Message from receiver";
   char buffer[MAXLINE];

   if ((argc != 4 && argc != 2) || (argc == 4 && 0 != strcmp(argv[1], "-f")))
      error("Usage reciever -f DATA_FILE PORT");
   else if (argc == 4){
      port = atoi(argv[3]);
      message = (char *)readFromFile(argv[2]).c_str();
   } else
      port = atoi(argv[1]);
  
   // Makes socket file
   if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
      error("Socket Creation Failed");

   memset(&servaddr, 0, sizeof(servaddr));

   // Fills server information
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(port);
   servaddr.sin_addr.s_addr = INADDR_ANY;

   int n;
   socklen_t len;
   sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
   int i = 0;
   while(true){
      std::cout <<i <<std::endl;
   n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);

   buffer[n] = '\0';
   std::cout <<"Message from sender:\n" <<binToText(buffer) <<std::endl;

   sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
   i++;
   }
   close(sockfd);

  return 0;
}

std::string readFromFile(std::string fileName) {
   std::ifstream ifs(fileName);
   std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

   return content;
}

std::string binToText(std::string bin) {
   std::string text = "";
   std::string temp = bin.erase(0, 96);
   std::stringstream sstream(bin);
   
   while(sstream.good()) {
      std::bitset<8> bits;
      sstream >> bits;
      char c  = char(bits.to_ulong());
      text += c;
   }

   return text;
}
