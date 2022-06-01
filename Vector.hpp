/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:48:49 by rgirondo          #+#    #+#             */
/*   Updated: 2022/06/01 19:54:36 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <memory>

namespace ft
{
    template<typename Vector>
    class VectorIterator
    {
        
        private:
            Vector::value_type _ptr;    
    };
    
    template < class T, class Alloc = std::allocator<T> >
    class Vector
    {  
        public:
            typedef typename T value_type;
            typedef typename Alloc allocator_type;
            typedef typename Alloc::reference reference;
            typedef typename Alloc::const_reference const_reference;
            typedef typename Alloc::pointer pointer;
            typedef typename Alloc::const_pointer const_pointer;
        private:
            T* _Data = NULL;
            size_t _Size = 0;
            size_t _Capacity = 0;
    };
    
}

#endif