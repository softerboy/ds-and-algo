#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

/**
 * Dictionary abstract class
 * @tparam Key record's key type
 * @tparam Value record's value type
 */
template<typename Key, typename Value>
class Dictionary {
 private:
  void operator=(const Dictionary &) {}           // protect assignment NOLINT(cert-oop54-cpp)
  Dictionary(const Dictionary &) = default;        // protect copying

 public:
  Dictionary() = default;             // Default constructor
  virtual ~Dictionary() = default;    // Base destructor

  /**
   * Reinitialize dictionary
   */
  virtual void clear() = 0;

  /**
   * Insert a record into dictionary
   * @param key The key for the record being inserted
   * @param value The record being inserted
   */
  virtual void insert(const Key &key, const Value &value) = 0;

  /**
   * Remove and return a record
   * @param key The key of the record to be removed
   * @return A matching record. if multiple records match "key",
   * remove an arbitrary one. Return nullptr if no record
   */
  virtual Value *remove(const Key &key) = 0;

  /**
   * Remove and return arbitrary record from dictionary
   * @return The record removed, nullptr if none exists
   */
  virtual Value *removeAny() = 0;

  /**
   * Return a record matching "key"
   * @param key The key of record to find
   * @return A record matching "key", nullptr if none exists
   */
  virtual Value *find(const Key &key) = 0;

  /**
   * @return Number of records in the dictionary
   */
  virtual int size() = 0;
};

#endif // __DICTIONARY_H__