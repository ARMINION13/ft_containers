/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:26:54 by rgirondo          #+#    #+#             */
/*   Updated: 2023/01/25 22:23:31 by rgirondo         ###   ########.fr       */
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
    
    template <class f,class s>
    class pair
    {
        public :
            typedef f first_type;
            typedef s second_type;

            first_type first;
            second_type second;
            
            pair() : first(), second() {};
            template<class a, class b>
            pair (const pair<a, b>& asg) : first(asg.first), second(asg.second) {};
            pair (const first_type& asg1, const second_type& asg2) : first(asg1), second(asg2) {};
            pair& operator=(const pair& asg)
            {
                this->first = asg.first;
                this->second = asg.second;
                return (*this);
            }
    };
 
    
    template<class key, class T, class Compare = std::less<key>, class Alloc = std::allocator<ft::pair<const key, T> > >
    class map
    {
        public:
            
            typedef key key_type;
            typedef T mapped_type;
            typedef ft::pair<const key, T> value_type;
            typedef Compare key_compare;
            
        // value_compare member definition
                        
            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                friend class map<key, T, Compare, Alloc>;
                
                protected:
                
                    Compare _comp;
                    value_compare (Compare c) : _comp(c) {}
                
                public:
                
                    template<typename N, typename F>
                    bool operator() (const N& x, const F& y) const
                    {
                        return _comp(x.first, y.first);
                    }
            };
            
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef size_t size_type;
			typedef ptrdiff_t difference_type;
            typedef ft::node<value_type, Alloc> node;
            typedef map_it<value_type, node> iterator;
            typedef map_it<const value_type, node> const_iterator;
            typedef reverse_map_it<iterator> reverse_iterator;
            typedef reverse_map_it<const_iterator> const_reverse_iterator;
            

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
                _node = new node();
                _size = 0;
                while(first != last)
                {
                    this->insert(*first);
                    first++;
                }
                _allocator = alloc;
                _comp = comp;
            }

            map (const map& x)
            {
                _node = new node();
                *this = x;
            }

            map &operator=(const map &asg)
            {
                if (&asg == this)
                    return (*this);
                if (_node)
                    this->clear();
                _size = 0;
                this->insert(asg.begin(), asg.end());
                return *this;
            }

            ~map()
            {
                this->clear();
                if (_node)
                    delete _node;
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
                return aux->_data->second;
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

            ft::pair<iterator,bool> insert(const value_type& val)
            {
                node *aux = _search(_node, val.first);
                iterator ret(aux);
                if (aux != NULL)
                    return (ft::pair<iterator, bool>(ret, false));
                else
                {
                    _insert(val);
                    _size++;
                    aux = _search(val.first);
                    ret = iterator(aux);
                }
                ft::pair<iterator, bool> par(ret, true);
                return (par);
            }
            
            template <class InputIterator>
            void insert (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                while(first != last)
                {
                    insert(*first);
                    first++;
                }
            }

            iterator insert(iterator position, const value_type& val)
            {
                iterator aux;
                (void)position;
                insert(val);
                aux = iterator(_search(val.first));
                return aux;
            }

            void erase(iterator first, iterator last)
            {
                iterator aux = first;
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

            void swap (map& x)
            {
				node *mp1 = this->_node;
				node *mp2 = x._node;
				map<key, T> aux(*this);

				this->_size = x._size;
				x._size = aux.size();
				this->_allocator = x._allocator;
				x._comp = aux._comp;
				x._node = mp1;
				this->_node = mp2;
			}

            void clear()
            {
                erase(begin(), end());
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
            
            const_iterator begin() const
            {
                node *aux;
                
                aux = _node;
                while (aux->_left != NULL)
                    aux = aux->_left;
                return const_iterator(aux);
            }

            iterator end()
            {
                node *aux;
                
                aux = _node;
                while (aux->_end != true)
                    aux = aux->_right;
                return iterator(aux);
            }

            const_iterator end() const
            {
                node *aux;
                
                aux = _node;
                while (aux->_end != true)
                    aux = aux->_right;
                return const_iterator(aux);
            }

            reverse_iterator rbegin()
            {
                reverse_iterator aux = end();
                return aux;
            }
            
            const_reverse_iterator rbegin() const
            {
                const_reverse_iterator aux = end();
                return aux;
            }

            reverse_iterator rend()
            {
                reverse_iterator aux = begin();
                return aux;
            }

            const_reverse_iterator rend() const
            {
                const_reverse_iterator aux = begin();
                return aux;
            }
            
        //get allocator

            allocator_type get_allocator() const
            {
                return (this->_allocator);
            }

        //observers

            key_compare key_comp() const
            {
                key_compare aux(_comp);

                return aux;
            }

            value_compare value_comp() const
            {
                value_compare aux(_comp);

                return aux;
            }

        // operations

            iterator find(const key_type& k)
            {
                node *aux;
                
                aux = _search(k);
                if (aux == NULL)
                    return end();
                else
                    return (iterator(aux));
            }
            
            const_iterator find(const key_type& k) const
            {
                node *aux;
                
                aux = this->_search(k);
                if (aux == NULL)
                    return end();
                else
                    return (const_iterator(aux)); 
            }
            
            size_type count(const key_type& k) const
            {
                if (_search(k) != NULL)
                    return 1;
                else
                    return 0;
            }
            
            iterator lower_bound(const key_type& k)
            {
                iterator beg = begin();
                iterator en = end();

                while(beg != en)
                {
                    if (_comp(beg->first, k) == false)
                        break;
                    beg++;
                }
                return beg;
            }
            
            const_iterator lower_bound(const key_type& k) const
            {
                const_iterator beg = begin();
                const_iterator en = end();

                while(beg != en)
                {
                    if (_comp(beg->first, k) == false)
                        break;
                    beg++;
                }
                return beg;
            }

            iterator upper_bound(const key_type& k)
            {
                iterator beg = begin();
                iterator en = end();

                while(beg != en)
                {
                    if (_comp(k, beg->first) == true)
                        break;
                    beg++;
                }
                return beg;
            }
            
            const_iterator upper_bound(const key_type& k) const
            {
                const_iterator beg = begin();
                const_iterator en = end();

                while(beg != en)
                {
                    if (_comp(k, beg->first) == true)
                        break;
                    beg++;
                }
                return beg;
            }

            pair<const_iterator,const_iterator> equal_range(const key_type& k) const
            {
                return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
            }
            
            pair<iterator,iterator> equal_range(const key_type& k)
            {
                return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
            }
            
        private:

        //first calls
            
            void _delete(key_type k)
            {
                _delete(_node, k);
                _node->_parent = NULL;
            }

            node *_search(key_type const &k) const
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

            node* _search(node* root, key_type const &k) const
            {
                if (root == NULL || (!_comp(root->_data->first, k) && !_comp(k, root->_data->first) && root->_end == false))
                    return root;
                if (_comp(root->_data->first, k))
                    return _search(root->_right, k);
                else
                    return _search(root->_left, k);
            }

            //Delete function
            
            void _delete(node * &root, key_type k)
            {
                if (root == NULL || root->_end == true)
                    return ;
                if (_comp(root->_data->first, k))
                    _delete(root->_right, k);
                else if (_comp(k, root->_data->first))
                    _delete(root->_left, k);
                else if (root->_left != NULL && root->_right != NULL && root->_left->_end != true && root->_right->_end != true)
                {
                    _allocator.destroy(root->_data);
                    _allocator.construct(root->_data, *(_find_replace(root->_right)->_data));
                    _delete(root->_right, root->_data->first);
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
                    if (aux->_right != NULL && aux->_right->_end == true && root != aux && root->_end != true)
                    {
                        biggest(root)->_right = aux->_right;
                        aux->_right->_parent = biggest(root);
                    }
                    aux->_right = NULL;
                    aux->_left = NULL;
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
                    return (new node(val, &_allocator));
                if (root->_end == true)
                {
                    aux = new node(val, &_allocator);
                    root->_parent = aux;
                    aux->_right = root;
                    return (aux);
                }
                if (_comp(root->_data->first, val.first))
                {
                    root->_right = _insert(root->_right, val);
                    root->_right->_parent = root;
                }
                else if (_comp(val.first, root->_data->first))
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

    // template< class Key, class T, class Compare, class Alloc >
    // bool operator==(const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs)
    // {}
}

#endif
