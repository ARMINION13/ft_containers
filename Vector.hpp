/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:48:49 by rgirondo          #+#    #+#             */
/*   Updated: 2022/07/07 19:21:17 by rgirondo         ###   ########.fr       */
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
			
			ReverseVectorIt &operator=(ReverseVectorIt &asg)
			{
				*this = asg;
				return (*this);
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
			value_type *_ptr;    
	};
	
	template<typename Vector>
	class VectorIt
	{
		public:
			typedef typename Vector::value_type value_type;
			typedef value_type* pointer_type;
			typedef value_type& reference_type;
			VectorIt() : _ptr(0) {};
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
				return _ptr;
			}

			VectorIt &operator=(VectorIt &asg)
			{
				*this = asg;
				return (*this);
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
			value_type *_ptr;    
	};
	
	template < class T, class Alloc = std::allocator<T> >
	class Vector
	{  
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef ft::VectorIt<ft::Vector<value_type> > iterator;
			typedef ft::ReverseVectorIt<ft::Vector<value_type> > reverse_iterator;
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
				int j = 2;
				
				while (j < n)
					j = j * 2;
				_Data = _Allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_Allocator.construct(_Data + i, val);
				_Size = n;
				_Capacity = j;
			}
			
			template <class InputIterator>
			Vector (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, 
				const allocator_type& alloc = allocator_type())
			{
				InputIterator aux = first;;
				int  n = 0, j = 2;

				while (aux++ != last)
					n++;
				_Data = _Allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_Allocator.construct(_Data + i, first[i]);
				_Size = n;
				while (j < n)
					j = j * 2;
				_Capacity = j;
			}
			
			void operator=(Vector &asg)
			{
				this->_Size = asg.size();
				this->_Capacity = asg.capacity();
				this->_Allocator = asg._Allocator;
				
				_Data = _Allocator.allocate(_Size);
				for (size_type i = 0; i < _Size; i++)
					_Allocator.construct(_Data + i, asg._Data[i]);
			}
			
			Vector(Vector &x)
			{
				*this = x;
			}

			~Vector()
			{
				
			}

			//Iterator functions

			iterator begin()
			{
				iterator it(_Data);
				return it;
			}
			
			iterator end()
			{
				iterator it(_Data + _Size);
				return it;
			}
			
			const iterator begin() const
			{
				const iterator it(_Data);
				return it;
			}
			
			const iterator end() const
			{
				const iterator it(_Data + _Size);
				return it;
			}
			
			reverse_iterator rbegin()
			{
				reverse_iterator it(_Data);
				return it;
			}
			
			reverse_iterator rend()
			{
				reverse_iterator it(_Data + _Size);
				return it;
			}
			
			const reverse_iterator rbegin() const
			{
				const reverse_iterator it(_Data);
				return it;
			}
			
			const reverse_iterator rend() const
			{
				const reverse_iterator it(_Data + _Size);
				return it;
			}

			//Capacity

			size_type size() const
			{
				return (_Size);	
			}

			size_type max_size() const
			{
				return (_Allocator.max_size());
			}

			void resize(size_type n, value_type val = value_type())
			{
				value_type *aux;
				size_type j = 2;
				
				if (n > _Size && n < _Capacity)
				{
					for (size_type i = _Size; i < n; i++)
						_Allocator.construct(_Data + i, val);
					_Size = n;
				}
				if (n < _Size)
				{
					for (size_type i = n; i < _Size; i++)
						_Allocator.destroy(_Data + i);
					_Size = n;
				}
				if (n > _Capacity)
				{
					aux = _Allocator.allocate(n);
					for (size_type i = 0; i < n; i++)
						_Allocator.construct(aux + i, val);
					for (size_type i = 0; i < _Size; i++)
						aux[i] = _Data[i];
					_Allocator.deallocate(_Data, _Size);
					_Data = aux;
					_Size = n;
					while (j < _Size)
						j = j * 2;
					_Capacity = j;
				}
			}

			size_type capacity() const
			{
				return _Capacity;
			}
			
			bool empty() const
			{
				if (_Size == 0)
					return true;
				else
					return false;
			}

			void reserve (size_type n)
			{	
				if (n > _Capacity)
					_Capacity = n;
			}

			//Element access

			reference operator[](size_type n)
			{
				return (_Data[n]);	
			}

			const_reference operator[](size_type n) const
			{
				return (_Data[n]);	
			}
			
			reference at(size_type n)
			{
				if (n > _Size)
					throw (std::out_of_range("out of range"));
				return (_Data[n]);
			}

			const_reference at(size_type n) const
			{
				if (n > _Size)
					throw (std::out_of_range("out of range"));
				return (_Data[n]);
			}

			reference front()
			{
				return (_Data[0]);
			}

			const_reference front() const
			{
				return (_Data[0]);
			}
			
			reference back()
			{
				return (_Data[_Size - 1]);
			}

			const_reference back() const
			{
				return (_Data[_Size - 1]);
			}
			
			//Modifiers

			void assign(size_type n, const value_type& val)
			{
				if (n > _Capacity)
					this->resize(n);
				for (size_type i = 0; i < n; i++)
					_Allocator.construct(_Data + i, val);
				_Size = n;
				std::cout << "aaa" << std::endl;
			}
			
			template <class InputIterator>
			void assign(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				InputIterator aux = first;
				int n = 0;
				
				while (aux++ != last)
					n++;
				if (n > _Capacity)
					this->resize(n);
				for (size_type i = 0; i < n; i++)
					_Allocator.construct(_Data + i, first[i]);
				_Size = n;
			}

			void push_back(const value_type& val)
			{
				if (_Size >= _Capacity)
					this->resize(_Size + 1, val);
				else
				{
					_Allocator.construct(_Data + _Size, val);
					_Size += 1;
				}
			}

			void pop_back()
			{
				_Allocator.destroy(_Data + _Size);
				_Size -= 1;			
			}

			//Allocator
			
			allocator_type get_allocator() const
			{
				return _Allocator;
			}
			
		private:
			value_type* _Data;
			size_type _Size;
			size_type _Capacity;
			allocator_type _Allocator;
	};
	
}

#endif