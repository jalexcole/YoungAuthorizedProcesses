#pragma once


template<typename E>
class IComparable {
  virtual int compareTo(E* first) = 0;
};