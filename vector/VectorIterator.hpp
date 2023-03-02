#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft {

template<typename T>
class VectorIterator {
 public:
  typedef std::ptrdiff_t difference_type;

  typedef T value_type;

  typedef T *pointer;

  typedef T &reference;

  typedef std::random_access_iterator_tag iterator_category;

  VectorIterator() : _it() {}

  explicit VectorIterator(value_type *it) : _it(it) {}

  VectorIterator(const VectorIterator &copy) {
    *this = copy;
  }

  VectorIterator &operator=(VectorIterator const &copy) {
    _it = copy._it;
    return *this;
  }

  pointer base() const {
    return _it;
  }

  ~VectorIterator() {}

  bool operator==(VectorIterator<T> const &obj) {
    return _it == obj._it;
  }

  bool operator!=(VectorIterator<T> const &obj) {
    return _it != obj._it;
  }

  reference operator*() {
    return (*_it);
  }

  pointer operator->() {
    return &operator*();
  }

  VectorIterator &operator++() {
    _it++;
    return *this;
  }

  VectorIterator operator++(int) {
    VectorIterator tmp = *this;
    ++(*this);
    return tmp;
  }

  VectorIterator &operator--() {
    _it--;
    return *this;
  }

  VectorIterator operator--(int) {
    VectorIterator tmp = *this;
    --(*this);
    return tmp;
  }

  VectorIterator operator+(difference_type value) const {
    return VectorIterator(_it + value);
  }

  VectorIterator operator-(difference_type value) const {
    return VectorIterator(_it - value);
  }

  bool operator<(VectorIterator<T> const &obj) {
    return (_it < obj._it);
  }

  bool operator>(VectorIterator<T> const &obj) {
    return _it > obj._it;
  }

  bool operator<=(VectorIterator<T> const &obj) {
    return _it <= obj._it;
  }

  bool operator>=(VectorIterator<T> const &obj) {
    return _it >= obj._it;
  }

  VectorIterator &operator+=(difference_type value) {
    _it += value;
    return *this;
  }

  VectorIterator &operator-=(difference_type value) {
    _it -= value;
    return *this;
  }

  reference operator[](difference_type value) const {
    return _it[value];
  }

 private:
  pointer _it;
};

template<class Iterator>
typename VectorIterator<Iterator>::difference_type operator-(const VectorIterator<
    Iterator> &lhs,
                                                             const VectorIterator<
                                                                 Iterator> &rhs) {
  return lhs.base() - rhs.base();
}

template<class Iterator>
typename VectorIterator<Iterator>::difference_type operator+(
    typename VectorIterator<Iterator>::difference_type n,
    const VectorIterator<Iterator> &it) {
  return VectorIterator<Iterator>(it.base() + n);
}

template<typename IteratorLeft, typename IteratorRight>
bool operator==(const VectorIterator<IteratorLeft> &lhs,
                const VectorIterator<IteratorRight> &rhs) {
  return lhs.base() == rhs.base();
}

template<typename IteratorLeft, typename IteratorRight>
bool operator!=(const VectorIterator<IteratorLeft> &lhs,
                const VectorIterator<IteratorRight> &rhs) {
  return lhs.base() != rhs.base();
}

template<typename IteratorLeft, typename IteratorRight>
bool operator<(const VectorIterator<IteratorLeft> &lhs,
               const VectorIterator<IteratorRight> &rhs) {
  return lhs.base() > rhs.base();
}

template<typename IteratorLeft, typename IteratorRight>
bool operator>(const VectorIterator<IteratorLeft> &lhs,
               const VectorIterator<IteratorRight> &rhs) {
  return lhs.base() < rhs.base();
}

template<typename IteratorLeft, typename IteratorRight>
bool operator<=(const VectorIterator<IteratorLeft> &lhs,
                const VectorIterator<IteratorRight> &rhs) {
  return lhs.base() >= rhs.base();
}

template<typename IteratorLeft, typename IteratorRight>
bool operator>=(const VectorIterator<IteratorLeft> &lhs,
                const VectorIterator<IteratorRight> &rhs) {
  return lhs.base() <= rhs.base();
}

template<typename IteratorLeft, typename IteratorRight>
bool operator>=(const VectorIterator<IteratorLeft> &lhs,
                VectorIterator<IteratorRight> &rhs) {
  return lhs.base() <= rhs.base();
}

};

#endif
