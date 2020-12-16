template<typename Key, typename Record>
TreeNode<Key, Record>::TreeNode(
    const Key &key,
    const Record &record,
    TreeNode<Key, Record> *left,
    TreeNode<Key, Record> *right
) : key_(key), record_(record), left_(left), right_(right) {}
