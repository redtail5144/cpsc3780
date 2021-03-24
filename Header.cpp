#include "Header.h"
#include <string>

Header::Header(){
  setType(1);
  setTr(0);
  setWindow(0);
  setSeqnum(0);
  setLength(0);
  setTimestamp(0);
  setCRC1(0);
  setCRC2(0);
}

Header::~Header(){
  // code here
}

void Header::setType(int value){
  if(value == 2) {
    type = "10";
  } else if(value == 3) {
    type = "11";
  } else {
    type = "01";
  }
}

std::string Header::getType() {
  return type;
}

void Header::setTR(bool value) {
  if(value == TRUE) {
    tr = "1";
  } else {
    tr = "0";
  }
}

std::string Header::getTR() {
  return tr;
}

void Header::setWindow(int  value) {
  int x = value;
  std:string b;
  if(value>=32) {
    b="11111";
  } else if(value<0) {
    b="00000"
  } else {
    while((x!=0)&&(b.length()!=5)){
      if(x%2==0) {
        b="0"+b;
      } else {
        b="1"+b;
      }
      x/=2;
    }
    while(b.length()!=5) {
    b="0"+b;
    }
    window = b;
  }
}

std::string Header::getWindow() {
  return window;
}

void Header::setSeqnum(int value){
  int x = value;
  std:string b;
  if(value>=256) {
    b="11111111";
  } else if(value<0) {
    b="00000000"
  } else {
    while((x!=0)&&(b.length()!=8)){
      if(x%2==0) {
        b="0"+b;
      } else {
        b="1"+b;
      }
      x/=2;
    }
    while(b.length()!=8) {
    b="0"+b;
    }
    seqNum = b;
  }
}

std::string Header::getSeqnum(){
  return seqNum;
}

void Header::setLength(int value){
  int x = value;
  std:string b;
  if(value<0) {
    b="0000000000000000"
  } else {
    while((x!=0)&&(b.length()!=16)){
      if(x%2==0) {
        b="0"+b;
      } else {
        b="1"+b;
      }
      x/=2;
    }
    while(b.length()!=16) {
    b="0"+b;
    }
    length = b;
  }
}

std::string Header::getLength(){
  return length;
}

void Header::setTimestamp(int value){
  int x = value;
  std:string b;
  if(value<0) {
    b="00000000000000000000000000000000"
  } else {
    while((x!=0)&&(b.length()!=32)){
      if(x%2==0) {
        b="0"+b;
      } else {
        b="1"+b;
      }
      x/=2;
    }
    while(b.length()!=32) {
    b="0"+b;
    }
    timestamp = b;
  }
}

std::string Header::getTimestamp(){
  return timestamp;
}

void Header::setCRC1(int value){
  int x = value;
  std:string b;
  if(value<0) {
    b="00000000000000000000000000000000"
  } else {
    while((x!=0)&&(b.length()!=32)){
      if(x%2==0) {
        b="0"+b;
      } else {
        b="1"+b;
      }
      x/=2;
    }
    while(b.length()!=32) {
    b="0"+b;
    }
    crc1 = b;
  }
}

std::string Header::getCRC1(){
  return crc1;
}

void Header::setCRC2(int value){
  int x = value;
  std:string b;
  if(value<0) {
    b="00000000000000000000000000000000"
  } else {
    while((x!=0)&&(b.length()!=32)){
      if(x%2==0) {
        b="0"+b;
      } else {
        b="1"+b;
      }
      x/=2;
    }
    while(b.length()!=32) {
    b="0"+b;
    }
    crc2 = b;
  }
}

std::string Header::getCRC2(){
  return crc2;
}
