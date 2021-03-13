#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
if (argc != 5 && argc != 3) {
  std::cerr << "Usage: " << argv[0] << " [-f DATA_FILE] HOST PORT" << std::endl;
  return 1;
} else if (argc == 5){
  std::string data(argv[2]);
  std::string host(argv[3]);
  std::string port(argv[4]);
} else {
  std::string host(argv[1]);
  std::string port(argv[2]);
}
  return 0;
}
