#include <iostream>
#include <utility>
#include <memory>
#include "../map.hpp"

namespace ft
{
    template<class value_type, class Alloc >
    class node
    {
        public:

            value_type      _data;
            node            *_right;
            node            *_left;
            node            *_parent;
            Alloc           _allocator;
            bool            _end;
            
            node() : _data(), _right(NULL), _left(NULL), _parent(NULL), _end(true) {}
            
            node(const value_type& val) : _data(val), _right(NULL), _left(NULL), _parent(NULL), _end(false) {}
            
            node(const node& node)
            {
                *this = node;
            }

            node &operator=(const node &asg)
            {
                _data.first = asg._data.first;
                _data.second = asg._data.second;
                _right = asg._right;
                _left = asg._left;
                _end = asg._end;
                return *this;
            }
    };
}