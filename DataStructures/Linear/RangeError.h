#ifndef __RANGE_ERROR_H__
#define __RANGE_ERROR_H__

#include <exception>

class RangeError : public std::exception {
 private:
  const char *_message;
  int _range;

 public:
  RangeError(int range, const char *message);

  const char *what() const noexcept override;
};

#endif // __RANGE_ERROR_H__
