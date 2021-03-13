#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 4 && argc != 2) {
    std::cerr << "Usage: " << argv[0] << " [-f DATA_FILE] PORT" << std::endl;
    return 1;
  } else if (argc == 4){
    std::string data(argv[2]);
    std::string port(argv[3]);
  } else {
    std::string port(argv[1]);
  }
  return 0;
}
