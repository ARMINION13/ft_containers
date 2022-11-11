/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_it.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:06:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/11/11 21:11:37 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <memory>
#include "../map.hpp"

namespace ft
{
    template<class value_type, class node>
    class map_it
    {
        public:

        map_it() : _root(NULL), _current(NULL) {};
        
        map_it(node &asg)
        {
            _root = &asg;  
            _current = &asg;
        } 
        
        map_it(map_it const &asg)
        {
            *this = asg;   
        }
        
        map_it &operator=(map_it const &asg)
        {
            _root = asg._root;
            _current = asg._current;
            return (*this);
        }
        
        map_it &operator=(node &asg)
        {
            _root = &asg;
            _current = &asg;
            return (*this);
        }

        map_it& operator++()
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

        value_type *operator->()
        {
            return &((*_current)._data);
        }
        
        node &operator*()
        {
            return *_current;
        } 

        private:
            
        node        *_root;
        node        *_current; 
    };
}