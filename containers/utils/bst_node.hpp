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

            typedef Alloc allocator_type;

            value_type      *_data;
            node            *_right;
            node            *_left;
            node			*_parent;
            allocator_type	*_allocator;
            bool			_end;
            
            node() : _right(NULL), _left(NULL), _parent(NULL), _end(true)
            {
                _data = new value_type();
            }

            node(const value_type& val, allocator_type *alloc) : _right(NULL), _left(NULL), _parent(NULL), _end(false)
            {
                _data = new value_type();
                alloc->allocate(1);
                alloc->construct(_data, val);
                _allocator = alloc;
            }

			node(const value_type& val) : _data(val), _right(NULL), _left(NULL), _parent(NULL), _end(false) {}
            
            node(const node& node)
            {
				this = node;
            }

            ~node()
            {
				if (!_end)
                {
                    _allocator->destroy(_data);
                	_allocator->deallocate(_data, 1);
                }
            }

            node &operator=(const node &asg)
            {
				if (!_end)
                {
                    _allocator->destroy(_data);
                	_allocator->deallocate(_data, 1);
                }
                _allocator->allocate(1);
                _allocator->construct((_data), asg._data);
                _right = asg._right;
                _left = asg._left;
                _end = asg._end;
				_allocator = asg._allocator;
                return *this;
            }

    };
}
