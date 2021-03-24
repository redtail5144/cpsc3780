#ifndef HEADER_H
#define HEADER_H

class Header {
private:
  string type;
  string window;
  string seqNum;
  string length;
  string timestamp;
  string crc1;
  string crc2;
  bool tr;
public:
  // Constructor
  Header();
  // Destructor???????
  ~Header();

  // Sets the TYPE field in the Header
  void setType(int);
  // Gets the TYPE field in the Header
  std::string getType();

  // Sets the TR field in the Header
  void setTR(bool);
  // Gets the TR field in the Header
  bool getTR();

  // Sets the WINDOW field in the Header
  void setWindow(int);
  // Gets the WINDOW field in the Header
  std::string getWindow();

  // Sets the SEQNUM field in the Header
  void setSeqnum(int);
  // Gets the SEQNUM field in the Header
  std::string getSeqnum();

  // Sets the LENGTH field in the Header
  void setLength(int);
  // Gets the LENGTH field in the Header
  std::string getLength();

  // Sets the TIMESTAMP field in the Header
  void setTimestamp(int);
  // Gets the TIMESTAMP field in the Header
  std::string getTimestamp();

  // Sets the CRC1 field in the Header
  void setCRC1(int);
  // Gets the CRC1 field in the Header
  std::string getCRC1();

  // Sets the CRC2 field in the Header
  void setCRC2(int);
  // Gets the CRC2 field in the Header
  std::string getCRC2();

};
