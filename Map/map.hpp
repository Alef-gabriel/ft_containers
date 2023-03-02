#ifndef MAP_HPP
#define MAP_HPP
#include "Tree.hpp"
#include "MapIterator.hpp"
#include "../vector/vector.hpp"

namespace ft {
template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<T> >
class map
{

public:
    typedef Key key_type;

    typedef Compare key_compare;

    typedef T mapped_type;

    typedef std::size_t size_type;

    typedef ptrdiff_t difference_type;

    typedef Allocator allocator_type;

    typedef ft::pair<const key_type, mapped_type> value_type;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename MapIterator<value_type, Compare, Allocator> iterator;

    typedef typename ft::MapIterator<value_type, Compare, Allocator> const_iterator;

    typedef typename ft::ReverseIterator<iterator> reverse_iterator;

    typedef typename ft::ReverseIterator<const_iterator> const_reverse_iterator;

    explicit map(const key_compare &comp = key_compare(),
               const allocator_type &alloc = allocator_type()): _size(0), _allocator(alloc), _comparator(comp) {}
    
    map(const map &other) {
        _size = 0;
        *this = other;
    }

    class value_compare : public std::binary_function<value_type, value_type, bool> {
        friend class map;

        protected:
            Compare comp;

            explicit value_compare(Compare c) : comp(c) {}

        public:
            typedef bool result_type;

            typedef value_type first_argument_type;

            typedef value_type second_argument_type;

            bool operator()(const value_type &lhs, const value_type &rhs) const {
            return (comp(lhs.first, rhs.first));
            }
    };

    void clear() {
        _tree.clear();
        _size = 0;
    }

    size_type size(void) {
        return _size;
    }

    map& operator=( const map& other ) {
        _size = 0;  
    }

    ~map() {
        clear();
    }

    allocator_type get_allocator() const {
        return (_allocator);
    }

    key_compare key_comp() const {
        return (_comparator);
    }

    value_compare value_comp() const {
        return (value_compare(_comparator));
    }

    iterator begin() {
        if (_tree.minNode()) {
            return (iterator(_tree.minNode()->data, &_tree));
        }
        else {
            return (iterator(NULL, &_tree));
        }
    }

    iterator end() {
        return (iterator(NULL, &_tree));
    }

    const_iterator end() const {
        return const_iterator(NULL, &_tree);
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    bool empty() const {
        return _size == 0;
    }

    size_type size() const {
        return _size;
    }

    size_type max_size() const {
        return _allocator.max_size();
    }

    pair<iterator, bool> insert(const value_type &value) {
        Node<value_type, key_type, Allocator> *node = _tree.search(_tree.root, value);
        if (!node) {
            node = _tree.insert(value);
            _size++;
            return (pair<iterator, bool>(iterator(node->data, &_tree), true));
        }
        return (pair<iterator, bool>(iterator(node->data, &_tree), false));
    }

    iterator insert(iterator pos, const value_type &value) {
        (void)pos;
        return (insert(value));
    }

    template<class InputIt>
    void insert(InputIt first, InputIt last) {
        while (first != last) {
        insert(*first);
        first++;
        }
    }

    void erase(iterator pos) {
        _tree.remove(*pos);
        _size--;
    }

    void erase(iterator first, iterator last) {
        ft::vector<key_type> keys;

        while (first != last) {
            keys.push_back(first->first);
            first++;
        }
        for (size_t i = 0; i < keys.size(); i++)
        erase(keys[i]);
    }

    size_type erase(const key_type &key) {
        _size--;
        return _tree.remove(pair(key, mapped_type()));
    }

    size_type count(const key_type &key) const {
        if (_tree.search(pair(key, mapped_type())) != NULL)
            return (1);
        return (0);
    }

    iterator find(const key_type &key) {
        Node<value_type, key_type, Allocator> *node = _tree.search(pair(key, mapped_type()));
        return iterator(node ? node->data : NULL, &_tree);
    }

    const_iterator find(const key_type &key) const {
        Node<value_type, key_type, Allocator> *node = _tree.search(_tree.root, ft::make_pair(key, mapped_type()));

        return const_iterator(node ? node->data : NULL, &_tree);
    }

    pair<iterator, iterator> equal_range(const key_type &key) {
        return pair(lower_bound(key), upper_bound(key));
    }

    pair<const_iterator, const_iterator> equal_range(const key_type &key) const {
        return pair(lower_bound(key), upper_bound(key));
    }

    iterator lower_bound(const key_type &key) {
        Node<value_type, key_type, Allocator> *node = _tree.root;
        Node<value_type, key_type, Allocator> *lower = node;

        while (node != NULL) {
            if (!_comparator(node->data->first, key)) {
                lower = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return iterator(lower ? lower->data : NULL, &_tree);
    }

    const_iterator lower_bound(const key_type &key) const {
        Node<value_type, key_type, Allocator> *node = _tree.root;
        Node<value_type, key_type, Allocator> *lower = node;

        while (node != NULL) {
            if (!_comparator(node->data->first, key)) {
                lower = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return const_iterator(lower ? lower->data : NULL, &_tree);
    }

    iterator upper_bound(const key_type &key) {
        Node<value_type, key_type, Allocator> *node = _tree.root;
        Node<value_type, key_type, Allocator> *upper = node;

        while (node != NULL) {
            if (_comparator(key, node->data->first)) {
                upper = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return iterator(upper ? upper->data : NULL, &_tree);
    }

    const_iterator upper_bound(const key_type &key) const {
        Node<value_type, key_type, Allocator> *node = _tree.root;
        Node<value_type, key_type, Allocator> *upper = node;

        while (node != NULL) {
            if (_comparator(key, node->data->first)) {
                upper = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return const_iterator(upper ? upper->data : NULL, &_tree);
    }

    void swap(map &other) {
        _swap(_tree.root, other._tree.root);
        _swap(_size, other._size);
        _swap(_comparator, other._comparator);
        _swap(_allocator, other._allocator);
    }

private:
    size_type   _size;
    allocator_type _allocator;
    key_compare _comparator;
    typedef Tree< key_type , mapped_type, allocator_type> _tree;

    template<typename U>
    void _swap(U &a, U &b) {
        U tmp = a;
        a = b;
        b = tmp;
    } 
};

template<class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key, T, Compare, Allocator> &lhs,
                const map<Key, T, Compare, Allocator> &rhs) {
  return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template<class Key, class T, class Compare, class Allocator>
bool operator!=(const map<Key, T, Compare, Allocator> &lhs,
                const map<Key, T, Compare, Allocator> &rhs) {
  return !(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class Key, class T, class Compare, class Allocator>
bool operator<(const map<Key, T, Compare, Allocator> &lhs,
               const map<Key, T, Compare, Allocator> &rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key, T, Compare, Allocator> &lhs,
                const map<Key, T, Compare, Allocator> &rhs) {
  return !(lhs > rhs);
}

template<class Key, class T, class Compare, class Allocator>
bool operator>(const map<Key, T, Compare, Allocator> &lhs,
               const map<Key, T, Compare, Allocator> &rhs) {
  return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template<class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key, T, Compare, Allocator> &lhs,
                const map<Key, T, Compare, Allocator> &rhs) {
  return !(lhs < rhs);
}

template<class Key, class T, class Compare, class Allocator>
void swap(map<Key, T, Compare, Allocator> &lhs,
          map<Key, T, Compare, Allocator> &rhs) {
  lhs.swap(rhs);
}

}
#endif