#ifndef __STACK_H__
#define __STACK_H__

/**
 * Stack abstract class
 * @tparam T - an element type being saved in stack
 */
template<typename T>
class Stack {
 private:
  void operator=(const Stack &) {};   // protect assignment

  Stack(const Stack &) = default;     // protect copy constructor

 public:
  // default constructor
  Stack() = default;

  // default destructor
  virtual ~Stack() = default;

  /**
   * Push new item onto the stack
   * @param item - an item being pushed onto the stack
   */
  virtual void push(const T &item) = 0;

  /**
   * Removes (pops) and returns element from stack
   * @return first element on top of the stack
   */
  virtual T pop() = 0;

  /**
   * Clears all items from stack and frees memory
   */
  virtual void clear() = 0;

  /**
   * @return Current number of elements in the stack
   */
  virtual int length() const = 0;
};

#endif // __STACK_H__