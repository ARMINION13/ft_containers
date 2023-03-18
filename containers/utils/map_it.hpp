/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_it.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:06:21 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/18 15:38:20 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_IT_
#define _MAP_IT_

#include <iostream>
#include "../map.hpp"

namespace ft
{
    template<class value_type, class node>
    class map_it
    {
        
        public:
        
        typedef value_type v_type;
        typedef node tree_node;
        
        node        *_root;

        map_it() : _root(NULL), _current(NULL) {};
        
        map_it(node *asg) 
        { 
            _current = asg;
            _root = asg;
        }
        
        operator map_it<const value_type, node>(void) const 
        {
            return map_it<const value_type,  node>(_current);
        }

        template<typename N>
        map_it(map_it<N, node> &asg)
        {
            *this = asg;   
        }
        
        template<typename N>
        map_it &operator=(const map_it<N, node> &asg)
        {            
            _root = asg._root;
            _current = asg.base();
            return (*this);
        }


        map_it &operator++()
        {
            node *aux;
            
            if (_current->_right != NULL)
            {
                _current = _current->_right;
                while (_current->_left)
                    _current = _current->_left;
            }
            else
            {
                aux = _current;
                _current = _current->_parent;
                while (_current->_left != aux)
                {
                    aux = _current;
                    _current = _current->_parent;
                }       
            }
            return *this;
        }

        map_it operator++(int)
        {
            node *aux;
            map_it it = *this;
            
            if (_current->_right != NULL)
            {
                _current = _current->_right;
                while (_current->_left)
                    _current = _current->_left;
            }
            else
            {
                aux = _current;
                _current = _current->_parent;
                while (_current->_left != aux)
                {
                    aux = _current;
                    _current = _current->_parent;
                }       
            }
            return it;
        }

        map_it operator--(int)
        {
            node *aux;
            map_it it = *this;
            
            if (_current->_left != NULL)
            {
                _current = _current->_left;
                while (_current->_right)
                    _current = _current->_right;
            }
            else
            {
                aux = _current;
                _current = _current->_parent;
                while (_current->_right != aux)
                {
                    aux = _current;
                    _current = _current->_parent;
                }       
            }
            return it;
        }

        map_it &operator--()
        {
            node *aux;
            
            if (_current->_left != NULL)
            {
                _current = _current->_left;
                while (_current->_right)
                    _current = _current->_right;
            }
            else
            {
                aux = _current;
                _current = _current->_parent;
                while (_current->_right != aux)
                {
                    aux = _current;
                    _current = _current->_parent;
                }       
            }
            return *this;
        }
        
        value_type *operator->() const
        {
            return &(_current->_data);
        }
        
        value_type &operator*() const
        {
            return (_current->_data);
        }

        node *base() const
        {
            return _current;
        }
		
        bool operator==(const map_it& other) const
		{
			return (_current == other._current);
		}
		
        bool operator!=(const map_it& other) const
		{
			return !(_current == other._current);
		}

        private:
            
        node        *_current; 
    };
    
    template<class map_it>
    class reverse_map_it
    {
        public:
        
        typedef typename map_it::v_type value_type;
        typedef typename map_it::tree_node node;

        reverse_map_it() : _it() {};
        
        reverse_map_it(node *asg) 
        { 
            _it = map_it(asg);
        }
        
        reverse_map_it(map_it const &asg)
        {
            _it = asg;   
        }
        
        template<typename N>
        reverse_map_it(reverse_map_it<N> const &asg)
        {
            *this = asg;
        }
        
        reverse_map_it &operator=(map_it const &asg)
        {
            _it = asg;
            return (*this);
        }
        
        reverse_map_it &operator=(node &asg)
        {
            _it = map_it(asg);
            return (*this);
        }

        template<typename N>
        reverse_map_it &operator=(reverse_map_it<N> const &asg)
        {
            this->_it = asg.base();
            return (*this);
        }

        map_it base() const
        {
            return _it;
        }        

        reverse_map_it &operator++()
        {
            _it--;
            return *this;
        }

        reverse_map_it operator++(int)
        {
            reverse_map_it aux = *this;
            _it--;
            return aux;
        }

        reverse_map_it operator--(int)
        {
            reverse_map_it aux = *this;
            _it++;
            return aux;
        }

        reverse_map_it &operator--()
        {
            _it++;
            return *this;
        }

        value_type *operator->() const
        {
            return &this->operator*();
        }
        
        value_type &operator*() const
        {
            map_it _aux = _it;
			_aux--;
			return *_aux;
        }
		
        bool operator==(const reverse_map_it& other) const
		{
			return (_it == other._it);
		}
		
        bool operator!=(const reverse_map_it& other) const
		{
			return !(_it == other._it);
		}

        private:
            
        map_it _it;
    };
}

#endif