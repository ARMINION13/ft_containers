/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_it.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:05:35 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/15 20:27:52 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_IT_
#define _VECTOR_IT_

#include <iostream>
#include "../vector.hpp"

namespace ft
{
	template<typename Vector>
	class VectorIt
	{
		public:
			
			// value_type = int
			// pointer_type = *int

			typedef typename Vector::value_type value_type;
			typedef value_type* pointer_type;
			typedef value_type& reference_type;
			typedef const value_type& const_reference_type;
			typedef const value_type* const_pointer_type;
			
			VectorIt() : _ptr(0) {};
			
			template <typename N>
			VectorIt(VectorIt<N> it)
			{
				_ptr = &(*it);
			}
			
			VectorIt(value_type* ptr) : _ptr(ptr) {};
			
			~VectorIt() {};

			template <typename N>
			VectorIt &operator=(const VectorIt<N> &asg)
			{
				_ptr = &(*asg);
				return (*this);
			}
			
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
			
			VectorIt operator+(int n)
			{
				VectorIt iterator = *this;
				iterator._ptr += n;
				return iterator;
			}

			friend VectorIt	operator+(int n, VectorIt &ref)
			{
				return (ref + n);
			}

			friend VectorIt	operator-(int n, VectorIt &ref)
			{
				return (ref - n);
			}
			
			VectorIt operator-(int n)
			{
				VectorIt iterator = *this;
				iterator._ptr -= n;
				return iterator;
			}
			
			template <typename N>
			ptrdiff_t operator-(VectorIt<N> it) const
			{
				return (_ptr - &(*it));
			}
			
			template <typename N>
			ptrdiff_t operator-(VectorIt<N> it)
			{
				return (_ptr - &(*it));
			}
			
			VectorIt &operator+=(int n)
			{
				this->_ptr += n;
				return *this;
			}

			VectorIt &operator-=(int n)
			{
				this->_ptr -= n;
				return *this;
			}

			reference_type operator[](size_t index)
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

			const_reference_type operator*() const
			{
				return *_ptr;
			}
			
			
			template <typename N>
			bool operator<(const VectorIt<N>& other) const
			{
				return _ptr < &(*other);
			}
			
			template <typename N>
			bool operator>(const VectorIt<N>& other) const
			{
				return _ptr > &(*other);
			}

			template <typename N>
			bool operator<=(const VectorIt<N>& other) const
			{
				if (_ptr < &(*other) || _ptr == &(*other))
					return (true);
				else
					return (false);
			}
			
			template <typename N>
			bool operator>=(const VectorIt<N>& other) const
			{
				if (_ptr > &(*other) || _ptr == &(*other))
					return (true);
				else
					return (false);
			}
			
			template <typename N>
			bool operator==(const VectorIt<N>& other) const
			{
				return _ptr == &(*other);
			}
			
			template <typename N>
			bool operator!=(const VectorIt<N>& other) const
			{
				return !(_ptr == &(*other));
			}
			
		private:
			value_type *_ptr;    
	};
	
	template<typename Vector>
	class ReverseVectorIt
	{
		public:
			typedef typename Vector::value_type value_type;
			typedef typename Vector::iterator iterator;
			typedef iterator* pointer_it;
			typedef iterator& reference_it;
			typedef value_type& reference_type;
			typedef value_type* pointer_type;
			
			ReverseVectorIt() : _it() {};
			
			template <typename N>
			ReverseVectorIt(ReverseVectorIt<N> it)
			{
				this->_it = it.base();
			}

			template <typename N>
			ReverseVectorIt(VectorIt<N> it)
			{
				_it = it;
			}
			
			ReverseVectorIt(pointer_type ptr) : _it(iterator(ptr)) {};
			
			~ReverseVectorIt() {};
			
			template <typename N>
			ReverseVectorIt &operator=(ReverseVectorIt<N> asg)
			{
				this->_it = asg.base();
				return (*this);
			}
			
			reference_it base()
			{
				return (this->_it);
			}
			
			ReverseVectorIt& operator++() 
			{
				_it--;
				return *this;    
			}
			
			ReverseVectorIt operator++(int)
			{
				ReverseVectorIt iterator = *this;
				_it--;
				return iterator;
			}
			
			ReverseVectorIt& operator--() 
			{
				_it++;
				return *this;    
			}
			
			ReverseVectorIt operator--(int)
			{
				ReverseVectorIt iterator = *this;
				_it++;
				return iterator;
			}

			ReverseVectorIt operator+(int n)
			{
				ReverseVectorIt iterator = *this;
				iterator._it -= n;
				return iterator;
			}

			ReverseVectorIt operator-(int n)
			{
				ReverseVectorIt iterator = *this;
				iterator._it += n;
				return iterator;
			}
			
			template <typename N>
			ptrdiff_t operator-(ReverseVectorIt<N> it) const
			{
				return (it.base() - _it);
			}
			
			template <typename N>
			ptrdiff_t operator-(ReverseVectorIt<N> it)
			{
				return (it.base() - _it);
			}

			ReverseVectorIt &operator+=(int n)
			{
				this->_it -= n;
				return *this;
			}

			ReverseVectorIt &operator-=(int n)
			{
				this->_it += n;
				return *this;
			}
			
			reference_type operator[](int index)
			{
				return _it[(index + 1) * -1];
			}
			
			reference_type operator*()
			{
				iterator _aux = _it;
				_aux--;
				return *_aux;
			}
			
			pointer_type operator->()
			{
				return &this->operator*();
			}

			friend ReverseVectorIt	operator+(int n, ReverseVectorIt &ref)
			{
				return (ref + n);
			}

			friend ReverseVectorIt	operator-(int n, ReverseVectorIt &ref)
			{
				return (ref - n);
			}

			template <typename N>
			bool operator<(ReverseVectorIt<N> other) const
			{
				return _it > other.base();
			}
			
			template <typename N>
			bool operator>(ReverseVectorIt<N> other) const
			{
				return _it < other.base();
			}

			template <typename N>
			bool operator<=(ReverseVectorIt<N> other) const
			{
				return _it >= other.base();
			}
			
			template <typename N>
			bool operator>=(ReverseVectorIt<N> other) const
			{
				return _it <= other.base();
			}
			
			template <typename N>
			bool operator==(ReverseVectorIt<N> other) const
			{
				return _it == other.base();
			}
			
			template <typename N>
			bool operator!=(ReverseVectorIt<N> other) const
			{
				return _it != other.base();
			}
			
		private:
			iterator _it;
	};
}

#endif