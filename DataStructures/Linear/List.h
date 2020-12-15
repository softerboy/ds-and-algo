#ifndef __LIST_H__
#define __LIST_H__

/**
 * Abstract data type for list implementation
 * @tparam T - elements type being stored in List
 */
template<typename T>
class List {
 private:
  void operator=(const List &) {};    // protect assignment
  List(const List &) {};              // protect copying

 public:
  List() = default;
  virtual ~List() = default;

  /**
   * Clear list. Free memory
   */
  virtual void clear() = 0;

  /**
   * Appends new item into list
   * @param item - Item being appended to list
   */
  virtual void append(const T &item) = 0;

  /**
   * Inserts new item from given position
   * @param item - item being inserted into list
   * @param pos - position item should be inserted to
   */
  virtual void insert(const T &item, int pos) = 0;

  /**
   * Removes element in given index
   * @param index - index element being removed
   * @return Element being removed
   */
  virtual T remove(int index) = 0;

  /**
   * Returns element in given index
   * @param index - index element being returned
   * @return element in given index otherwise nullptr
   */
  virtual T get(int index) = 0;

  /**
   * Return current number of elements in the list
   * @return number of elements in the list
   */
  virtual int length() const = 0;
};

#endif // __LIST_H__