#ifndef FT_CONTAINERS_REVERSEITERATOR_HPP
#define FT_CONTAINERS_REVERSEITERATOR_HPP

#include "IteratorInterface.hpp"

namespace ft {

template<class Iterator>
class ReverseIterator {
 public:

  typedef Iterator iterator_type;

  typedef typename ft::IteratorInterface<Iterator>::difference_type difference_type;

  typedef typename ft::IteratorInterface<Iterator>::value_type value_type;

  typedef typename ft::IteratorInterface<Iterator>::pointer pointer;

  typedef typename ft::IteratorInterface<Iterator>::reference reference;

  typedef typename ft::IteratorInterface<Iterator>::iterator_category iterator_category;

  ReverseIterator() {}

  ~ReverseIterator() {}

  explicit ReverseIterator(iterator_type it) : _pointer(it) {}

  template<class iterator>
  ReverseIterator(ReverseIterator<iterator> const &temp) {
    _pointer = temp.base();
  }

  iterator_type base() const {
    return (_pointer);
  }

  reference operator*() const {
    return *(--Iterator(_pointer));
  }

  ReverseIterator &operator+(difference_type value) {
    return (ReverseIterator(_pointer - value));
  }

  ReverseIterator &operator++() {
    _pointer--;
    return (*this);
  }

  ReverseIterator operator++(int) {
    ReverseIterator tmp = *this;
    ++(*this);
    return (tmp);
  }

  ReverseIterator &operator+=(difference_type value) {
    _pointer -= value;
    return (*this);
  }

  ReverseIterator &operator-(difference_type value) {
    return (ReverseIterator(_pointer + value));
  }

  ReverseIterator &operator--() {
    _pointer++;
    return (*this);
  }

  ReverseIterator operator--(int) {
    ReverseIterator tmp = *this;
    --(*this);
    return (tmp);
  }

  ReverseIterator &operator-=(difference_type value) {
    _pointer += value;
    return (*this);
  }

  pointer operator->() const {
    return &(operator*());
  }

  reference operator[](difference_type n) const {
    return (base()[-n - 1]);
  }

 private:
  iterator_type _pointer;
};

template<class Iterator>
typename ReverseIterator<Iterator>::difference_type operator-(const ReverseIterator<Iterator> &lhs,
                                                              const ReverseIterator<Iterator> &rhs) {
  return (rhs.base() + lhs.base());
}

template<class Iterator>
typename ReverseIterator<Iterator>::difference_type operator+(typename ReverseIterator<Iterator>::difference_type n,
                                                              const ReverseIterator<Iterator> &temp) {
  return (ReverseIterator<Iterator>(temp.base() - n));
}

template<class Iterator>
bool operator==(const ReverseIterator<Iterator> &lhs,
                const ReverseIterator<Iterator> &rhs) {
  return (lhs.base() == rhs.base());
}

template<class Iterator>
bool operator!=(const ReverseIterator<Iterator> &lhs,
                const ReverseIterator<Iterator> &rhs) {
  return (lhs.base() != rhs.base());
}

template<class Iterator>
bool operator<(const ReverseIterator<Iterator> &lhs,
               const ReverseIterator<Iterator> &rhs) {
  return (lhs.base() > rhs.base());
}

template<class Iterator>
bool operator>(const ReverseIterator<Iterator> &lhs,
               const ReverseIterator<Iterator> &rhs) {
  return (lhs.base() < rhs.base());
}

template<class Iterator>
bool operator<=(const ReverseIterator<Iterator> &lhs,
                const ReverseIterator<Iterator> &rhs) {
  return (lhs.base() >= rhs.base());
}

template <typename IteratorL, typename IteratorR>
bool operator>=(const ReverseIterator<IteratorL> &lhs,
                const ReverseIterator<IteratorR> &rhs) {
  return (lhs.base() <= rhs.base());
}

}

#endif
