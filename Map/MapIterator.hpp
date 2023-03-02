#ifndef FT_CONTAINERS_MAPITERATOR_HPP
#define FT_CONTAINERS_MAPITERATOR_HPP

#include <iterator>
#include <iostream>
#include "Tree.hpp"

template<typename T, typename Compare, typename Allocator>
class MapIterator {
 public:
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef Node<value_type, Allocator> node_type;

  MapIterator() : _pointer(NULL) {}

  explicit MapIterator(pointer it, const Tree<value_type, Compare, Allocator> *avl = NULL)
      : _pointer(it), _tree(avl) {}

  MapIterator(MapIterator const &copy) { *this = copy; }

  MapIterator &operator=(MapIterator const &copy) {
    _pointer = copy._pointer;
    _tree = copy._tree;
    return *this;
  }

  ~MapIterator() {}

  operator MapIterator<const T, Compare, Allocator>() const {
    return (MapIterator<const T, Compare, Allocator>(
        _pointer, reinterpret_cast<Tree<const value_type, Compare, Allocator> const *>(_tree)));
  }

  bool operator==(MapIterator const &obj) {
    return _pointer == obj._pointer;
  }

  bool operator!=(MapIterator const &obj) {
    return _pointer != obj._pointer;
  }

  reference operator*() {
    return *_pointer;
  }

  pointer operator->() {
    return &operator*();
  }

  MapIterator &operator++() {
    node_type *node = _tree->find(_tree->root, *_pointer);

    if (node) {
      node_type *tmp = _tree->next(*_pointer);

      if (tmp)
        _pointer = tmp->data;
      else
        _pointer = NULL;
    }
    return *this;
  }

  MapIterator operator++(int) {
    MapIterator tmp = *this;

    ++(*this);
    return tmp;
  }

  MapIterator &operator--() {
    node_type *node = NULL;

    if (!_pointer) {
      node = _tree->Max(_tree->root);
      if (node) _pointer = node->data;
      return (*this);
    }
    node = _tree->find(_tree->root, *_pointer);
    if (node) {
      node_type *tmp = _tree->previous(*_pointer);
      if (tmp)
        _pointer = tmp->data;
      else
        _pointer = NULL;
    }
    return *this;
  }

  MapIterator operator--(int) {
    MapIterator tmp = *this;

    --(*this);
    return tmp;
  }

 private:
  pointer _pointer;

  const Tree<value_type, Compare, Allocator> *_tree;
};

#endif 