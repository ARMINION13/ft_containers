/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:48:49 by rgirondo          #+#    #+#             */
/*   Updated: 2022/06/08 20:40:33 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <memory>
#include <vector>

namespace ft
{
	template<typename Vector>
	class ReverseVectorIt
	{
		public:
			typedef typename Vector::value_type value_type;
			typedef value_type* pointer_type;
			typedef value_type& reference_type;
			ReverseVectorIt() : _ptr(NULL) {};
			ReverseVectorIt(pointer_type ptr) : _ptr(ptr) {};
			~ReverseVectorIt() {};
			
			ReverseVectorIt& operator++() 
			{
				_ptr--;
				return *this;    
			}
			
			ReverseVectorIt operator++(int)
			{
				ReverseVectorIt iterator = *this;
				_ptr--;
				return iterator;
			}
			
			ReverseVectorIt& operator--() 
			{
				_ptr++;
				return *this;    
			}
			
			ReverseVectorIt operator--(int)
			{
				ReverseVectorIt iterator = *this;
				_ptr++;
				return iterator;
			}
			
			reference_type operator[](int index)
			{
				return *(_ptr - index);
			}
			
			pointer_type operator->()
			{
				return _ptr;
			}
			
			reference_type operator*()
			{
				return *_ptr;
			}
			
			bool operator==(const ReverseVectorIt& other) const
			{
				return _ptr == other._ptr;
			}
			
			bool operator!=(const ReverseVectorIt& other) const
			{
				return !(_ptr == other._ptr);
			}
			
		private:
			value_type _ptr;    
	};
	
	template<typename Vector>
	class VectorIt
	{
		public:
			typedef typename Vector::value_type value_type;
			typedef value_type* pointer_type;
			typedef value_type& reference_type;
			VectorIt() : _ptr(NULL) {};
			VectorIt(pointer_type ptr) : _ptr(ptr) {};
			~VectorIt() {};
			
			VectorIt& operator++() 
			{
				_ptr++;
				return *this;    
			}
			
			VectorIt operator++(int)
			{
				VectorIt iterator = *this;
				_ptr++;
				return iterator;
			}
			
			VectorIt& operator--() 
			{
				_ptr--;
				return *this;    
			}
			
			VectorIt operator--(int)
			{
				VectorIt iterator = *this;
				_ptr--;
				return iterator;
			}
			
			reference_type operator[](int index)
			{
				return *(_ptr + index);
			}
			
			pointer_type operator->()
			{
				return _ptr;
			}
			
			reference_type operator*()
			{
				return *_ptr;
			}
			
			bool operator==(const VectorIt& other) const
			{
				return _ptr == other._ptr;
			}
			
			bool operator!=(const VectorIt& other) const
			{
				return !(_ptr == other._ptr);
			}
			
		private:
			value_type _ptr;    
	};
	
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{  
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
			typedef size_t size_type;

			//Constructor functions
			
			explicit Vector (const allocator_type& alloc = allocator_type())
			{
				_Data = NULL;
				_Size = 0;
				_Capacity = 0;
			}

			explicit Vector (size_type n, const value_type& val = value_type(),
			 const allocator_type& alloc = allocator_type())
			{
				_Data = alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					alloc.construct(_Data + i, val);
				_Size = n;
				_Capacity = n;
			}
			
			// template <class InputIterator>
			//     Vector (InputIterator first, InputIterator last,
			//      const allocator_type& alloc = allocator_type())
			// {
				
			// }

			//Capacity functions

			// size_type size() const
			// {
			//     return _Size;
			// }

			// size_type max_size() const
			// {
			//     return _Capacity;
			// }

			// void resize (size_type n, value_type val = value_type())
			// {
				
			// }

			//Iterator functions

			ft::VectorIt<value_type> begin()
			{
				ft::VectorIt<value_type> it(_Data);
				return it;
			}
			
			ft::VectorIt<value_type> end()
			{
				ft::VectorIt<value_type> it(_Data + _Size);
				return it;
			}
			
			const ft::VectorIt<value_type> begin() const
			{
				const ft::VectorIt<value_type> it(_Data);
				return it;
			}
			
			const ft::VectorIt<value_type> end() const
			{
				const ft::VectorIt<value_type> it(_Data + _Size);
				return it;
			}
			
			ft::ReverseVectorIt<value_type> rbegin()
			{
				ft::ReverseVectorIt<value_type> it(_Data);
				return it;
			}
			
			ft::ReverseVectorIt<value_type> rend()
			{
				ft::ReverseVectorIt<value_type> it(_Data + _Size);
				return it;
			}
			
			const ft::ReverseVectorIt<value_type> rbegin() const
			{
				const ft::ReverseVectorIt<value_type> it(_Data);
				return it;
			}
			
			const ft::ReverseVectorIt<value_type> rend() const
			{
				const ft::ReverseVectorIt<value_type> it(_Data + _Size);
				return it;
			}
			
		private:
			value_type* _Data;
			size_type _Size;
			size_type _Capacity;
	};
	
}

#endif