/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:30:55 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/15 18:21:04 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_
#define _STACK_

#include <iostream>
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:

            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        
            explicit stack(const container_type& ctnr = container_type())
            {
                _ctnr = ctnr;
                _size = ctnr.size();
            }

            size_type size() const
            {
                return(_size);
            }

            bool empty() const
            {
                if (_size == 0)
                    return (true);
                else
                    return (false);
            }

            value_type& top()
            {
                return (_ctnr.back());
            }

            const value_type& top() const
            {
                return (_ctnr.back());
            }

            void push(const value_type& val)
            {
                _ctnr.push_back(val);
                _size = _ctnr.size();
            }

            void pop()
            {
                _ctnr.pop_back();
                _size = _ctnr.size();
            }

            template <class T2, class Container2>
            friend bool operator== (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

            template <class T2, class Container2>
            friend bool operator!= (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

            template <class T2, class Container2>
            friend bool operator< (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

            template <class T2, class Container2>
            friend bool operator<= (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

            template <class T2, class Container2>
            friend bool operator> (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

            template <class T2, class Container2>
            friend bool operator>= (const ft::stack<T2, Container2>& lhs, const ft::stack<T2, Container2>& rhs);

        protected:

            size_type _size;
            container_type _ctnr;
    };

    template< class T, class Container >
    bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return(lhs._ctnr == rhs._ctnr);
    }

    template< class T, class Container >
    bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return(lhs._ctnr != rhs._ctnr);
    }

    template< class T, class Container >
    bool operator<( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return(lhs._ctnr < rhs._ctnr);
    }

    template< class T, class Container >
    bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return(lhs._ctnr <= rhs._ctnr);
    }

    template< class T, class Container >
    bool operator>( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return(lhs._ctnr > rhs._ctnr);
    }

    template< class T, class Container >
    bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return(lhs._ctnr >= rhs._ctnr);
    }
}

#endif