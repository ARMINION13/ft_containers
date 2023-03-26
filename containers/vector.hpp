/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:48:49 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/26 21:23:58 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include "./utils/vector_it.hpp"
#include "./utils/enable_if.hpp"
#include "./utils/iterator_traits.hpp"

namespace ft
{

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{  
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef ft::VectorIt<ft::vector<value_type> > iterator;
			typedef ft::VectorIt<ft::vector<const value_type> > const_iterator;
			typedef ft::ReverseVectorIt<ft::vector<value_type> > reverse_iterator;
			typedef ft::ReverseVectorIt<ft::vector<const value_type> > const_reverse_iterator;
			typedef typename Alloc::reference reference;
			typedef typename Alloc::const_reference const_reference;
			typedef typename Alloc::pointer pointer;
			typedef typename Alloc::const_pointer const_pointer;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;

			//Constructor functions
			
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_Data = NULL;
				_Size = 0;
				_Capacity = 0;
				_Allocator = alloc;
			}

			explicit vector (size_type n, const value_type& val = value_type(),
			 const allocator_type& alloc = allocator_type())
			{
				size_type j = 2;
				
				_Size = n;
				while (j < n)
					j = j * 2;
				_Capacity = j;
				_Allocator = alloc;
				_Data = _Allocator.allocate(_Capacity);
				for (size_type i = 0; i < n; i++)
					_Allocator.construct(_Data + i, val);
			}
			
			template <class InputIterator>
			vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, 
				const allocator_type& alloc = allocator_type())
			{
				InputIterator aux = first;;
				size_type  n = 0, j = 2;

				while (aux++ != last)
					n++;
				while (j < n)
					j = j * 2;
				_Size = n;
				_Capacity = j;
				_Allocator = alloc;
				_Data = _Allocator.allocate(_Capacity);
				for (size_type i = 0; i < n; i++)
				{
					_Allocator.construct(_Data + i, *first);
					first++;
				}
			}
			
			void operator=(const vector &asg)
			{
				if (_Data != NULL)
					this->_Allocator.deallocate(_Data, _Capacity);
				_Data = NULL;
				this->_Size = asg.size();
				this->_Capacity = asg.capacity();
				this->_Allocator = asg._Allocator;

				this->_Data = this->_Allocator.allocate(this->_Capacity);
				for (size_type i = 0; i < this->_Size; i++)
					_Allocator.construct(_Data + i, asg._Data[i]);
			}			
			
			vector(vector &x)
			{
				_Data = NULL;
				_Size = 0;
				*this = x;
			}

			~vector()
			{
				if (_Data != NULL)
					this->_Allocator.deallocate(_Data, _Capacity);
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
			
			const_iterator begin() const
			{
				const_iterator it(_Data);
				return it;
			}
			
			const_iterator end() const
			{
				const_iterator it(_Data + _Size);
				return it;
			}
			
			reverse_iterator rbegin()
			{
				reverse_iterator it(end());
				return it;
			}
			
			reverse_iterator rend()
			{
				reverse_iterator it(begin());
				return it;
			}
			
			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator it(end());
				return it;
			}
			
			const_reverse_iterator rend() const
			{
				const_reverse_iterator it(begin());
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

			void	resize(size_type n, value_type val = value_type())
			{
				if (n < _Size)
				{
					while (_Size > n)
					{
						_Allocator.destroy(_Data + _Size);
						_Size--;
					}
				}
				else
				{
					if (n > _Capacity)
						reserve(n);
					while (_Size < n)
					{
						_Allocator.construct(_Data + _Size, val);
						_Size++;
					}
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
				{
					value_type	*aux;
					size_type j = 2;
			
					while (j < n)
						j = j * 2;
					_Capacity = j;
					aux = _Allocator.allocate(_Capacity);
					for (size_type i = 0; i < _Size; i++)
						_Allocator.construct(&aux[i], _Data[i]);
					if (_Data != NULL)
						_Allocator.deallocate(_Data, _Capacity);
					_Data = aux;
				}
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
			}
			
			template <class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				InputIterator aux = first;
				size_type n = 0;
				
				while (aux++ != last)
					n++;
				if (n > _Capacity)
					this->resize(n);
				for (size_type i = 0; i < n; i++)
				{
					_Allocator.construct(_Data + i, *first);
					first++;
				}
				_Size = n;
			}

			void push_back(const value_type& val)
			{
				if (_Size == _Capacity)
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
			
			iterator insert(iterator position, const value_type& val)
			{
				vector aux(_Size + 1);
				iterator ret;
				int i = 0;

				if (_Size == 0)
					aux[0] = val;
				else
				{
					for (iterator b1 = this->begin(); b1 != this->end() + 1; b1++)
					{
						if (b1 == position)
						{
							ret = &aux[i];
							aux[i++] = val;
						}
						aux[i++] = *b1;
					}
				}
				*this = aux;
				return (ret);
			}
			
			void insert(iterator position, size_type n, const value_type& val)
			{
				vector aux(_Size + n);
				int i = 0;
				if (_Size == 0)
				{
					for (size_type p = 0; p < n; p++)
						aux[p] = val;					
				}
				else
				{
					for (iterator b1 = this->begin(); b1 != this->end() + 1; b1++)
					{
						if (b1 == position)
						{
							for (size_type o = 0; o < n; o++)
								aux[i++] = val;
						}
						aux[i++] = *b1;
					}
				}
				*this = aux;
			}

			template <class InputIterator>
   			void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				size_type n = 0;
				for(InputIterator aux = first; aux != last; aux++)
					n++;
				vector aux(_Size + n);
				int i = 0;

				if (_Size == 0)
				{
					for (size_type p = 0; p < n; p++)
						aux[p] = *(first++);					
				}
				else
				{
					for (iterator b1 = this->begin(); b1 != this->end() + 1; b1++)
					{
						if (b1 == position)
						{
							for (size_type o = 0; o < n; o++)
							{
								aux[i++] = *first;
								first++;
							}
						}
						aux[i++] = *b1;
					}
				}
				
				*this = aux;
			}

			iterator erase(iterator position)
			{
				vector aux(_Size - 1);
				iterator ret;
				int i = 0;
				int a = 0;

				for (iterator b1 = this->begin(); b1 != this->end(); b1++)
				{
					if (b1 == position)
						a = i;
					else
						aux[i++] = *b1;
				}
				*this = aux;
				ret = &this->at(a);
				return (ret);
			}

			iterator erase(iterator first, iterator last)
			{
				size_type n = 0;
				iterator ret = 0;
				int i = 0;
				int a = 0;
				for(iterator aux = first; aux != last; aux++)
					n++;
				if (n > this->size())
					n = this->size();
				vector aux(_Size - (n));
				
				for (iterator b1 = this->begin(); b1 != this->end(); b1++)
				{
					if (b1 == first && first != last)
					{
						first++;
						a = i;
					}
					else
						aux[i++] = *b1;
				}
				*this = aux;
				ret = &this->at(a);
				return (ret);
			}

			void swap(vector& x)
			{
				value_type *d1 = this->_Data;
				value_type *d2 = x._Data;
				vector aux(*this);

				this->_Size = x._Size;
				x._Size = aux.size();
				this->_Capacity = x._Capacity;
				x._Capacity = aux.capacity();
				x._Data = d1;
				this->_Data = d2;
			}

			void clear()
			{
				size_type i = this->_Size;
				for(size_type b = 0; b != i; b++)
					this->pop_back();
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
	
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 b1, InputIterator1 e1, InputIterator2 b2, InputIterator2 e2)
	{
		while (b1!=e1)
		{
			if (b2 == e2 || *b2 < *b1)
				return false;
			else if (*b1 < *b2)
				return true;
			++b1;
			++b2;
		}
		return (b2!=e2);
	}
	
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}
	
	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for(size_t i = 0; i < rhs.size(); i++)
			{
				if (lhs[i] != rhs[i])
					return false;
			}
			return true;
		}	
		else
			return lhs.size() == rhs.size();
	}
	
	template <class T, class Alloc>
 	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs == rhs)
			return false;
		else
			return true;
	}
	
	template <class T, class Alloc>
  	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
    	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
  	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class T, class Alloc>
  	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
    	return rhs < lhs;
	}
	
	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
   		x.swap(y);
	}
	
}
#endif