/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:48:49 by rgirondo          #+#    #+#             */
/*   Updated: 2022/08/19 19:13:26 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
#include <memory>

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
			
			VectorIt &operator=(const VectorIt &asg)
			{
				this->_ptr = asg._ptr;
				return (*this);
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
			typedef value_type* pointer_type;
			typedef value_type& reference_type;
			ReverseVectorIt() : _it() {};
			ReverseVectorIt(pointer_type ptr) : _it(ptr) {};
			~ReverseVectorIt() {};
			
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
			
			reference_type operator[](int index)
			{
				return _it[index];
			}
			
			reference_type operator*()
			{
				iterator _aux = _it;
				_aux--;
				return *_aux;
			}
			
			pointer_type operator->()
			{
				iterator *_aux;
				_aux = this->operator*();
				return _aux;;
			}
			
			ReverseVectorIt &operator=(ReverseVectorIt &asg)
			{
				this->_it = asg._it;
				return (*this);
			}
			
			bool operator==(const ReverseVectorIt& other) const
			{
				return *_it == *other._it;
			}
			
			bool operator!=(const ReverseVectorIt& other) const
			{
				return !(*_it == *other._it);
			}
			
		private:
			iterator _it;
	};
	
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
				
				while (j < n)
					j = j * 2;
				_Data = _Allocator.allocate(n + 1);
				for (size_type i = 0; i < n; i++)
					_Allocator.construct(_Data + i, val);
				_Size = n;
				_Capacity = j;
				_Allocator = alloc;
			}
			
			template <class InputIterator>
			vector (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, 
				const allocator_type& alloc = allocator_type())
			{
				InputIterator aux = first;;
				size_type  n = 0, j = 2;

				while (aux++ != last)
					n++;
				_Data = _Allocator.allocate(n + 1);
				for (size_type i = 0; i < n; i++)
				{
					_Allocator.construct(_Data + i, *first);
					first++;
				}
				_Size = n;
				while (j < n)
					j = j * 2;
				_Capacity = j;
				_Allocator = alloc;
			}
			
			void operator=(vector &asg)
			{
				this->_Size = asg.size();
				this->_Capacity = asg.capacity();
				this->_Allocator = asg._Allocator;

				this->_Data = this->_Allocator.allocate(this->_Size + 1);
				for (size_type i = 0; i < this->_Size; i++)
					_Allocator.construct(_Data + i, asg._Data[i]);
			}			
			vector(vector &x)
			{
				_Size = 0;
				*this = x;
			}

			~vector()
			{
				this->_Allocator.deallocate(_Data, _Size + 1);
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

			void resize(size_type n, value_type val = value_type())
			{
				value_type *aux;
				size_type j = 2;

				if (n < _Size)
				{
					for (size_type i = n; i < _Size; i++)
						_Allocator.destroy(_Data + i);
					_Size = n;
				}
				else if (n > _Size)
				{
					aux = _Allocator.allocate(n + 1);
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
			}
			
			template <class InputIterator>
			void assign(typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
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
				this->_Allocator.deallocate(_Data, _Size);
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
				this->_Allocator.deallocate(_Data, _Size);
				*this = aux;
			}

			template <class InputIterator>
   			void insert(iterator position, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
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
				this->_Allocator.deallocate(_Data, _Size);
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
				this->_Allocator.deallocate(_Data, _Size);
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
				this->_Allocator.deallocate(_Data, _Size);
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