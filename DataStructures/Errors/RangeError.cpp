#include "RangeError.h"

RangeError::RangeError(int range, const char *message) : _range(range), _message(message) {}

const char *RangeError::what() const noexcept {
  return _message;
}

