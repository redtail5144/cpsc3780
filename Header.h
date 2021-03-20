#ifndef HEADER_H
#define HEADER_H

class Header {
private:
  int type, window, seqNum, length, timestamp, crc1, crc2;
  bool tr;
public:
  // Constructor
  Header();
  // Destructor???????
  ~Header();

  // Sets the TYPE field in the Header
  void setType(int);
  // Gets the TYPE field in the Header
  int getType();

  // Sets the TR field in the Header
  void setTR(bool);
  // Gets the TR field in the Header
  bool getTR();

  // Sets the WINDOW field in the Header
  void setWindow(int);
  // Gets the WINDOW field in the Header
  int getWindow();

  // Sets the SEQNUM field in the Header
  void setSeqnum(int);
  // Gets the SEQNUM field in the Header
  int getSeqnum();

  // Sets the LENGTH field in the Header
  void setLength(int);
  // Gets the LENGTH field in the Header
  int getLength();

  // Sets the TIMESTAMP field in the Header
  void setTimestamp(int);
  // Gets the TIMESTAMP field in the Header
  int getTimestamp();

  // Sets the CRC1 field in the Header
  void setCRC1(int);
  // Gets the CRC1 field in the Header
  int getCRC1();

  // Sets the CRC2 field in the Header
  void setCRC2(int);
  // Gets the CRC2 field in the Header
  int getCRC2();

};
