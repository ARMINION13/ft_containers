/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:26:09 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/18 15:45:04 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _NODE_
#define _NODE_

#include <iostream>
#include "../map.hpp"

namespace ft
{
    template<class value_type>
    class node
    {
        public:

            value_type      _data;
            node            *_right;
            node            *_left;
            node			*_parent;
            bool			_end;
            
            node() : _data(), _right(NULL), _left(NULL), _parent(NULL), _end(true) {}

            node(const value_type& val) : _data(val), _right(NULL), _left(NULL), _parent(NULL), _end(false) {}

            node(const node& node)
            {
				this = node;
            }

            ~node() {}

            node &operator=(const node &asg)
            {
                _data = asg._data;
                _right = asg._right;
                _left = asg._left;
                _end = asg._end;
                return *this;
            }

    };
}

#endif