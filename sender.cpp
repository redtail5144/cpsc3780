#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <bitset>
#include <string.h>
#include <thread>
#include <chrono>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Header.cpp"
#include <sstream>

#define MAXLINE 1024

const int PAYLOAD = 512;

std::string readFromFile(std::string fileName);
std::vector<std::string> textTo512Bin(std::string text);
std::string addHeader(int type, bool TR, int Window, int Seq, int length, int Timestamp, int crc1);
void error(const char *msg) {
    perror(msg);
    exit(0);
}


int main(int argc, char* argv[]) {

   std::string host; //IP to sent to
   int port; //Port being sent to
   int sockfd; // File descriptor of socket
   struct sockaddr_in servaddr, cliaddr;
   std::string message = ""; //char *message = "Message from sender";
   char buffer[MAXLINE];
   std::vector<std::string> binMessage;

   // If there is an incorrect amount of inputs
   if ((argc != 5 && argc != 3) || (argc == 5 && (0 != strcmp(argv[1], "-f")))) {
      error("Useage sender -f DATA_FILE HOST PORT");
   // If file name is inputted
   } else if (argc == 5){
      message = (char *)readFromFile(argv[2]).c_str();
      host = argv[3];
      port = atoi(argv[4]);
   // No file name inputted
   } else {
      host = argv[1];
      port = atoi(argv[2]);
   }

   std::cout <<"host: " <<host <<" " <<"\nport: " <<port <<std::endl;
   
   binMessage = textTo512Bin(message);

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
   if(bind(sockfd,(const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
      error("Bind Failed");

   int n;
   socklen_t len;

   len = sizeof(cliaddr);

   // Sends each of the 512bit chunks
   for(int i = 0; i < binMessage.size(); i++) {

      std::string temp = addHeader(1, 0, 0, i, binMessage[i].length(), 1, 0);
      temp += binMessage[i];
      

      char *send = (char *)temp.c_str();
      std::cout <<"\n****************************************************************\n" <<send
		<<"\n****************************************************************\n" <<std::endl;
      sendto(sockfd, (const char *)send, strlen(send), MSG_CONFIRM,
	     (const struct sockaddr *)&cliaddr, len);

   // Recieve messge from socket
   // recvfrom(int sockfd, void *buf, size_t len, int flags,
   //            struct sockaddr *src_addr, socklen_t *addrlen);
   n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);

   buffer[n] = '\0';

   std::cout <<"Message from receiver:\n" <<buffer <<std::endl;
      
   }

   std::cout <<"Sent message to " <<host <<std::endl;

   close(sockfd);

   return 0;
}

std::string readFromFile(std::string fileName) {
   std::ifstream ifs(fileName);
   std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

   return content;
}

// Converts text to 512 bit chunks
std::vector<std::string> textTo512Bin(std::string text) {
   // Vector containing 512 chunks
   std::vector<std::string> final;
   // Text as binary
   std::string binary = "";

   // Converts text to binary
   // Saves it in binary
   for (int i = 0; i < text.size(); i++)
      binary.append(std::bitset<8>(text[i]).to_string());

   // Splits binary into 512 and pushes it into final
   for (int i = 0; i <= binary.size()/PAYLOAD; i++) {
      std::string temp = "";

      // makes sure we arn't going over the file length
      for(int j = 0; j < PAYLOAD && j + (i * PAYLOAD) < binary.size(); j++)
	 temp += binary[j + (i * PAYLOAD)];

      final.push_back(temp);
   }
   
   return final;
}

std::string addHeader(int type, bool TR, int Window, int Seq, int length, int Timestamp, int crc1){
   Header h;
   std::string send = "";
   h.setType(type);
   h.setTR(TR);
   h.setWindow(Window);
   h.setSeqnum(Seq);
   h.setLength(length);
   h.setTimestamp(Timestamp);
   h.setCRC1(crc1);

   send.append(h.getType());
   send.append(h.getTR());
   send.append(h.getWindow());
   send.append(h.getSeqnum());
   send.append(h.getLength());
   send.append(h.getTimestamp());
   send.append(h.getCRC1());

   // delete h;
   
   return send;
}
