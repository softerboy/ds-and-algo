template<typename T>
SingleLinkNode<T>::SingleLinkNode(const T &data, SingleLinkNode<T> *next)
    : _data(data), _next(next) {}
