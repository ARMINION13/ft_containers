/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:26:54 by rgirondo          #+#    #+#             */
/*   Updated: 2022/11/03 18:35:05 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_
#define _MAP_

#include <iostream>
#include <utility>
#include <memory>
#include "./utils/map_it.hpp"
#include "./utils/bst_node.hpp"

namespace ft
{
    
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
            typedef map_it<value_type, node> iterator;

            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _node->_data = alloc.allocate(1);
                _allocator = alloc;
                _comp = comp;
                _size = 0;
            }
            
            // template <class InputIterator>
            // map (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first,
            //  InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            // {
            //     while(first != last)
            //     {
            //         insert();
            //     }
            // }

            map (const map& x)
            {
                *this = x;
            }

            map &operator=(const map &asg)
            {
                _node = asg._node;
                _comp = asg._comp;
                _allocator = asg._allocator;
                _size = asg._size;
                return *this;
            }

            //Access element
            
            mapped_type& operator[] (const key_type& k)
            {
                node *aux = _node.search(&_node, k);
                if (aux == NULL)
                {
                    aux = _node.Insert(value_type(k, mapped_type()));
                    _size++;
                }
                return aux->_data.second;
            }

            //Modifiers

            std::pair<iterator,bool> insert(const value_type& val)
            {
                node *aux = _node.search(&_node, val.first);
                iterator ret(*aux);
                if (aux != NULL)
                    return (std::pair<iterator, bool>(ret, true));
                else
                {
                    if (_size == 0)
                        _node = node(val);    
                    else    
                        _node.Insert(val);
                    _size++;
                    aux = _node.search(val.first);
                    ret = *aux;
                }
                std::pair<iterator, bool> par(ret, true);
                return (par);
            }
            
            template <class InputIterator>
            void insert (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                while(first != last)
                {
                    insert(first._data);
                    first++;
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
            node            *_node;
            key_compare     _comp;
            allocator_type  _allocator;
            size_type       _size;
            
    };
}

#endif