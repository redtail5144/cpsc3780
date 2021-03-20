#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

class invalid_parameter: public std::runtime_error {
 public:

  explicit invalid_parameter(const char* errMessage) :
  std::runtime_error(errMessage) {}
};

#endif
