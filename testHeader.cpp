#include "Header.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

TEST(testHeader, ConstructorTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getType(), "01");
  EXPECT_EQ(h->getTR(), "0");
  EXPECT_EQ(h->getWindow(), "00000");
  EXPECT_EQ(h->getSeqnum(), "00000000");
  EXPECT_EQ(h->getLength(), "0000000000000000");
  EXPECT_EQ(h->getTimestamp(), "00000000000000000000000000000000");
  EXPECT_EQ(h->getCRC1(), "00000000000000000000000000000000");
  EXPECT_EQ(h->getCRC2(), "00000000000000000000000000000000");

  delete h;
}

TEST(testHeader, setTypeTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getType(), "01");
  h->setType(2);
  EXPECT_EQ(h->getType(), "10");
  h->setType(3);
  EXPECT_EQ(h->getType(), "11");
  h->setType(420);
  EXPECT_EQ(h->getType(), "01");

  delete h;
}

TEST(testHeader, getTypeTest) {
  Header* h = new Header();

  EXPECT_NE(h->getType(), "00");
  EXPECT_EQ(h->getType(), "01");
  h->setType(2);
  EXPECT_EQ(h->getType(), "10");
  h->setType(3);
  EXPECT_EQ(h->getType(), "11");

  delete h;
}

TEST(testHeader, setTRTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getTR(), "0");
  h->setTR(TRUE);
  EXPECT_EQ(h->getTR(), "1");
  h->setTR(FALSE);
  EXPECT_EQ(h->getTR(), "0");

  delete h;
}

TEST(testHeader, getTRTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getTR(), "0");
  h->setTR(TRUE);
  EXPECT_EQ(h->getTR(), "1");
  h->setTR(FALSE);
  EXPECT_EQ(h->getTR(), "0");

  delete h;
}

TEST(testHeader, setWindowTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getWindow(), "00000");
  h->setWindow(1);
  EXPECT_EQ(h->getWindow(), "00001");
  h->setWindow(14);
  EXPECT_EQ(h->getWindow(), "01110");
  h->setWindow(31);
  EXPECT_EQ(h->getWindow(), "11111");
  h->setWindow(55);
  EXPECT_EQ(h->getWindow(), "11111");
  h->setWindow(-20);
  EXPECT_EQ(h->getWindow(), "00000");

  delete h;
}

TEST(testHeader, getWindowTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getWindow(), "00000");
  h->setWindow(1);
  EXPECT_EQ(h->getWindow(), "00001");
  h->setWindow(14);
  EXPECT_EQ(h->getWindow(), "01110");
  h->setWindow(31);
  EXPECT_EQ(h->getWindow(), "11111");
  h->setWindow(55);
  EXPECT_EQ(h->getWindow(), "11111");
  h->setWindow(-20);
  EXPECT_EQ(h->getWindow(), "00000");

  delete h;
}

TEST(testHeader, setSeqnumTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getSeqnum(), "00000000");
  h->setSeqnum(1);
  EXPECT_EQ(h->getSeqnum(), "00000001");
  h->setSeqnum(255);
  EXPECT_EQ(h->getSeqnum(), "11111111");
  h->setSeqnum(300);
  EXPECT_EQ(h->getSeqnum(), "11111111");
  h->setSeqnum(55);
  EXPECT_EQ(h->getSeqnum(), "00110111");
  h->setSeqnum(-20);
  EXPECT_EQ(h->getSeqnum(), "00000000");

  delete h;
}

TEST(testHeader, getSeqnumTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getSeqnum(), "00000000");
  h->setSeqnum(1);
  EXPECT_EQ(h->getSeqnum(), "00000001");
  h->setSeqnum(255);
  EXPECT_EQ(h->getSeqnum(), "11111111");
  h->setSeqnum(300);
  EXPECT_EQ(h->getSeqnum(), "11111111");
  h->setSeqnum(55);
  EXPECT_EQ(h->getSeqnum(), "00110111");
  h->setSeqnum(-20);
  EXPECT_EQ(h->getSeqnum(), "00000000");

  delete h;
}

TEST(testHeader, setLengthTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getLength(), "0000000000000000");
  h->setLength(1);
  EXPECT_EQ(h->getLength(), "0000000000000001");
  h->setLength(512);
  EXPECT_EQ(h->getLength(), "0000001000000000");

  delete h;
}

TEST(testHeader, getLengthTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getLength(), "0000000000000000");
  h->setLength(1);
  EXPECT_EQ(h->getLength(), "0000000000000001");
  h->setLength(512);
  EXPECT_EQ(h->getLength(), "0000001000000000");

  delete h;
}

TEST(testHeader, setTimestampTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getTimestamp(), "00000000000000000000000000000000");
  h->setTimestamp(1);
  EXPECT_EQ(h->getTimestamp(), "00000000000000000000000000000001");
  h->setTimestamp(512);
  EXPECT_EQ(h->getTimestamp(), "00000000000000000000001000000000");

  delete h;
}

TEST(testHeader, getTimestampTest) {
  Header* h = new Header();

  EXPECT_EQ(h->getTimestamp(), "00000000000000000000000000000000");
  h->setTimestamp(1);
  EXPECT_EQ(h->getTimestamp(), "00000000000000000000000000000001");
  h->setTimestamp(512);
  EXPECT_EQ(h->getTimestamp(), "00000000000000000000001000000000");

  delete h;
}

TEST(testHeader, setCRC1Test) {
  Header* h = new Header();

  EXPECT_EQ(h->getCRC1(), "00000000000000000000000000000000");
  h->setCRC1(1);
  EXPECT_EQ(h->getCRC1(), "00000000000000000000000000000001");
  h->setCRC1(512);
  EXPECT_EQ(h->getCRC1(), "00000000000000000000001000000000");

  delete h;
}

TEST(testHeader, getCRC1Test) {
  Header* h = new Header();

  EXPECT_EQ(h->getCRC1(), "00000000000000000000000000000000");
  h->setCRC1(1);
  EXPECT_EQ(h->getCRC1(), "00000000000000000000000000000001");
  h->setCRC1(512);
  EXPECT_EQ(h->getCRC1(), "00000000000000000000001000000000");

  delete h;
}

TEST(testHeader, setCRC2Test) {
  Header* h = new Header();

  EXPECT_EQ(h->getCRC2(), "00000000000000000000000000000000");
  h->setCRC2(1);
  EXPECT_EQ(h->getCRC2(), "00000000000000000000000000000001");
  h->setCRC2(512);
  EXPECT_EQ(h->getCRC2(), "00000000000000000000001000000000");

  delete h;
}

TEST(testHeader, getCRC2Test) {
  Header* h = new Header();

  EXPECT_EQ(h->getCRC2(), "00000000000000000000000000000000");
  h->setCRC2(1);
  EXPECT_EQ(h->getCRC2(), "00000000000000000000000000000001");
  h->setCRC2(512);
  EXPECT_EQ(h->getCRC2(), "00000000000000000000001000000000");

  delete h;
}
