/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:26:54 by rgirondo          #+#    #+#             */
/*   Updated: 2022/12/07 17:39:30 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_
#define _MAP_

#include <iostream>
#include <utility>
#include <memory>
#include <cstddef>
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
            typedef std::allocator<value_type> allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef size_t size_type;
			typedef ptrdiff_t difference_type;
            typedef ft::node<value_type, Alloc> node;
            typedef map_it<value_type, node> iterator;

            //constructors, destructors & operator=

            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _node = new node();
                _allocator = alloc;
                _comp = comp;
                _size = 0;
            }
            
            template <class InputIterator>
            map (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first,
             InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                while(first != last)
                {
                    insert(first._data);
                    first++;
                }
                _allocator = alloc;
                _comp = comp;
            }

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
                node *aux = _search(_node, k);
                if (aux == NULL)
                {
                    _insert(value_type(k, mapped_type()));
                    aux = _search(_node, k);
                    _size++;
                }
                return aux->_data.second;
            }

            node *biggest(node *root)
            {
                while (root->_right != NULL && root->_right->_end != true)
                    root = root->_right;
                return root;
            }
            
            mapped_type& at(const key_type& k)
            {
                node *aux = _search(_node, k);
                if (aux == NULL)
					throw (std::out_of_range("out of range"));
                return aux->_data.second;
            }
            
            const mapped_type& at(const key_type& k) const
            {
                node *aux = _search(_node, k);
                if (aux == NULL)
					throw (std::out_of_range("out of range"));
                return aux->_data.second;
            }

            //Modifiers

            std::pair<iterator,bool> insert(const value_type& val)
            {
                node *aux = _search(_node, val.first);
                iterator ret(aux);
                if (aux != NULL)
                    return (std::pair<iterator, bool>(ret, true));
                else
                {
                    _insert(val);
                    _size++;
                    aux = _search(val.first);
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

            iterator insert(iterator position, const value_type& val)
            {
                iterator aux;
                _insert(&(*position), val);
                aux = *(_search(&(*position), val.first));
                return aux;
            }

            void erase(iterator position)
            {
                _delete(position->first);
            }
            
            size_type erase(const key_type& k)
            {
                size_type aux = _size;
                _delete(k);
                return (aux - _size);
            }
            
            template <class InputIterator>
            void erase(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, iterator last)
            {
                InputIterator aux = first;
                size_t i = 0;
                
                while (aux != NULL && aux != last)
                {
                    i++;
                    aux++;
                }
                key_type str[i];
                aux = first;
                for (size_t o = 0; o < i; o++)
                {
                    str[o] = aux->first;
                    aux++;
                }
                for (size_t o = 0; o < i; o++)
                    _delete(str[o]);                
            }

            void swap (map& x)
            {
				node *mp1 = this->_node;
				node *mp2 = x._node;
				map<key, T> aux(*this);

				this->_size = x._size;
				x._size = aux.size();
				this->_allocator = x._allocator;
				x._comp = aux.get_allocator();
				x._Data = mp1;
				this->_Data = mp2;
			}

            void clear()
            {
                erase<iterator>(begin(), end());
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
                node *aux;
                
                aux = _node;
                while (aux->_left != NULL)
                    aux = aux->_left;
                return iterator(aux);
            }
            
            iterator end()
            {
                node *aux;
                
                aux = _node;
                while (aux->_end != true)
                    aux = aux->_right;
                return iterator(aux);
            }

            //get allocator

            allocator_type get_allocator() const
            {
                return (this->_allocator);
            }
            
        private:

        //first calls
            
            void _delete(key k)
            {
                _delete(_node, k);
                _node->_parent = NULL;
            }

            node *_search(key k)
            {
                return(_search(_node, k));
            }            

            void _insert(const value_type& val)
            {
                _node = _insert(_node, val);
                _node->_parent = NULL;
            }
            
        //second calls

            //Search function

            node* _search(node* root, key k)
            {
                if (root == NULL || (root->_data.first == k && root->_end == false))
                    return root;
                if (root->_data.first < k)
                    return _search(root->_right, k);
                return _search(root->_left, k);
            }

            //Delete function
            
            void _delete(node * &root, key k)
            {
                if (root == NULL || root->_end == true)
                    return ;
                if (root->_data.first < k)
                    _delete(root->_right, k);
                else if (root->_data.first > k)
                    _delete(root->_left, k);
                else if (root->_left != NULL && root->_right != NULL && root->_left->_end != true && root->_right->_end != true)
                {
                    root->_data = _find_replace(root->_right)->_data;
                    _delete(root->_right, root->_data.first);
                }
                else
                {
                    node *aux = root;
                    if (root->_left != NULL)      
                        root = root->_left;
                    else
                        root = root->_right;
                    if (root != NULL && root->_parent)
                        root->_parent = aux->_parent;
                    if (aux->_right != NULL && (aux->_right->_end == true && root != aux))
                    {
                        biggest(root)->_right = aux->_right;
                        aux->_right->_parent = biggest(root);
                    }
                    delete aux;
                    --_size;
                }
            }

            node *_find_replace(node *root)
            {
                 node *aux = root;
                 while (aux->_left != NULL)
                    aux = aux->_left;
                return aux;
            }

            //Node insert

            node *_insert(node *root, const value_type& val)
            {
                node *aux;
                
                if (!root)
                    return (new node(val));
                if (root->_end == true)
                {
                    aux = new node(val);
                    root->_parent = aux;
                    aux->_right = root;
                    return (aux);
                }
                if (val.first > root->_data.first)
                {
                    root->_right = _insert(root->_right, val);
                    root->_right->_parent = root;
                }
                else if (val.first < root->_data.first)
                {
                    root->_left = _insert(root->_left, val);
                    root->_left->_parent = root;
                }
                return root;
            }
            
        private:
            node            *_node;
            key_compare     _comp;
            allocator_type  _allocator;
            size_type       _size;
            
    };
}

#endif