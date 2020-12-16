#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "../../Interfaces/List.h"

template<typename T>
class ArrayList : public List<T> {
 private:
  T *_items;      // array for holding elements
  int _count;     // current number of elements in array
  int _size;      // current max size of array

 public:
  /**
   * Initializes list with given capacity
   * @param size - initial capacity of list
   */
  explicit ArrayList(int size = 10);

  ~ArrayList() override;

  void _doubleCapacity();

 public:
  void clear() override;

  void append(const T &item) override;

  void insert(const T &item, int pos) override;

  T remove(int pos) override;

  T get(int index) override;

  int length() const override;
};

#include "ArrayList.inl"

#endif // __ARRAY_LIST_H__
