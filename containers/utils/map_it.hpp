/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_it.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:06:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/10/19 17:01:53 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <memory>
#include "../map.hpp"

namespace ft
{
    template<class node>
    class map_it
    {
        public:

        map_it() : _root(NULL), _current(NULL) {};
        map_it(node &asg)
        {
            _root = &asg;
            _current = &asg;
        } 
        map_it(map_it &asg)
        {
            *this = asg;   
        }
        
        map_it operator=(map_it &asg)
        {
            _root = asg._root;
            _current = asg._current;
            return (*this);
        }
        
        map_it operator=(node &asg)
        {
            _root = asg;
            _current = asg;
            return (*this);
        }

        map_it operator++()
        {
            node *aux;
            
            if (_current->right != NULL)
            {
                _current = _current->right;
                while (_current->left)
                    _current = _current->left;
            }
            else
            {
                aux = _current;
                _current = _current->parent;
                while (_current->left != aux)
                {
                    aux = _current;
                    _current = _current->parent;
                }       
            }
        }
        
        node &operator*()
        {
            return *_current;
        } 

        private:
            
        node *_root;
        node *_current; 
    };
}