#include <iostream>
#include <utility>
#include <memory>
#include "../map.hpp"

namespace ft
{
    template<class value_type, class key, class T, class Alloc >
    class node
    {
        public:

            value_type      _data;
            node            *_right;
            node            *_left;
            node            *_parent;
            
            node() : _data(), _right(NULL), _left(NULL), _parent(NULL) {}
            node(const value_type& val) : _data(val), _right(NULL), _left(NULL), _parent(NULL) {}
            
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
                return *this;
            }

            void search(key k)
            {
                search(this, k);
            }            

            void insert(const value_type& val)
            {
                insert(this, val);
            }

            private:

            //Search function

            node* search(node* root, key k)
            {
                if (root == NULL || root->_data.first == k)
                    return root;
                if (root->_data.first < k)
                    return search(root->_right, k);
                return search(root->_left, k);
            }

            //Node insert

            node *Insert(node *root, const value_type& val)
            {
                if (!root)
                    return (new node(val));
                if (val.first > root->_data.first)
                {
                    root->_right = Insert(root->_right, val);
                    root->_right->_parent = root;
                }
                else if (val.first < root->_data.first)
                {
                    root->_left = Insert(root->_left, val);
                    root->_left->_parent = root;
                }
                return root;
            }
    };
}