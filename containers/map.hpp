/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:26:54 by rgirondo          #+#    #+#             */
/*   Updated: 2022/10/19 16:52:30 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_
#define _MAP_

#include <iostream>
#include <utility>
#include <memory>
#include "./utils/map_it.hpp"

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
    
    template<class key, class T, class Compare = std::less<key>, class Alloc = std::allocator<std::pair<const key, T> > >
    class map
    {
        public:
            typedef key key_type;
            typedef T mapped_type;
            typedef std::pair<key, T> value_type;
            typedef std::less<key_type> key_compare;
            typedef std::allocator<key_type> allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef size_t size_type;
			typedef ptrdiff_t difference_type;
            typedef node<value_type, key, T, Alloc> node;
            typedef map_it<node> iterator;

            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _node = node();
                _allocator = alloc;
                _comp = comp;
                _size = 0;
            }
            
            // template <class InputIterator>
            // map (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first,
            //  InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            // {
                
            // }

            //Access element
            
            mapped_type& operator[] (const key_type& k)
            {
                node *aux = _node.search(&_node, k);
                if (aux == NULL)
                {
                    aux = _node.Insert(&_node, value_type(k, mapped_type()));
                    _size++;
                }
                return aux->_data.second;
            }

            //Modifiers

            void insert(const value_type& val)
            {
                node *aux = _node.search(&_node, val.first);
                if (aux != NULL)
                {
                    
                }
                else
                {
                    _node.Insert(&_node, val);
                    _size++;
                }
            }

            //Capacity

            size_type size() const
            {
                return _size;
            }

            size_type max_size() const
            {
                return _allocator.max_size();
            }

            bool empty() const
            {
                if (_size <= 0)
                    return true;
                else
                    return false;
            }

            //Iterator

            iterator begin()
            {
                iterator aux(_node);
                return aux;
            }

            
        private:
            node            _node;
            key_compare     _comp;
            allocator_type  _allocator;
            size_type       _size;
            
    };
}

#endif