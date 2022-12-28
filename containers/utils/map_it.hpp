/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_it.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:06:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/12/28 20:20:53 by rgirondo         ###   ########.fr       */
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
        
        map_it(node *asg) 
        { 
            _current = asg;
            _root = asg;
        }
        
        map_it(map_it const &asg)
        {
            *this = asg;   
        }
        
        map_it &operator=(const map_it &asg)
        {            
            _root = asg._root;
            _current = asg._current;
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

        map_it operator--()
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
            return &((*_current)._data);
        }
        
        node &operator*() const
        {
            return *_current;
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
            
        node        *_root;
        node        *_current; 
    };
    
    template<class value_type, class node>
    class reverse_map_it
    {
        public:
        
        typedef map_it<value_type, node> map_it;

        reverse_map_it() : _it() {};
        
        reverse_map_it(node *asg) 
        { 
            _it = map_it(asg);
        }
        
        reverse_map_it(map_it const &asg)
        {
            _it = asg;   
        }
        
        reverse_map_it(reverse_map_it const &asg)
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

        reverse_map_it &operator=(reverse_map_it const &asg)
        {
            this->_it = asg->_it;
            return (*this);
        }

        reverse_map_it& operator++()
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

        reverse_map_it operator--()
        {
            _it++;
            return *this;
        }

        value_type *operator->()
        {
            return &this->operator*();
        }
        
        node &operator*()
        {
            map_it _aux = _it;
			_aux--;
			return *_aux;
        }
		
        bool operator==(const map_it& other) const
		{
			return (_it == other._it);
		}
		
        bool operator!=(const map_it& other) const
		{
			return !(_it == other._it);
		}

        private:
            
        map_it _it;
    };
}
