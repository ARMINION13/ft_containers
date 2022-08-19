/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/08/19 19:02:02 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#  define TESTED_NAMESPACE ft

# include <iostream>
# include <string>
# include <vector>
# include <stack>

#pragma region 

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

 #include "vector.hpp"
 #include <vector>

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}



#pragma endregion





#include <list>
#define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7

	return (0);
}

























// #include <vector>
// #include "vector.hpp"

// void leak()
// {
//     system("leaks VectorTest");    
// }

// int main()
// {
//     std::vector<int> val1(2);
//     ft::vector<int> val2(2);

//     val1.at(0) = 1;
//     val1.at(1) = 10;
//     val2.at(0) = 2;
//     val2.at(1) = 20;
    
//     ft::vector<int> val3(7, 5);
    
//     // val3.push_back(42);
//     // val3.push_back(43);
//     // val3.push_back(44);

//     // val3.pop_back();
//     // val3.pop_back();

//     ft::vector<int>::iterator b2 = val2.begin();
//     ft::vector<int>::iterator e2 = val2.end();
//     std::vector<int>::iterator b1 = val1.begin();
//     std::vector<int>::iterator e1 = val1.end();
//     ft::vector<int>::iterator b3 = val3.begin();
//     ft::vector<int>::iterator e3 = val3.end();
    
//     val3.swap(val2);

//     // ft::vector<int>::iterator i = val3.begin();

//     // i++;
//     // i++;

//     // std::cout << *val3.insert(i,777) << " insert " << std::endl;
//     // std::cout << *val3.insert(i,666) << " insert " << std::endl;
//     // std::cout << *val3.insert(i,555) << " insert " << std::endl;
//     // std::cout << *val3.erase(i, i + 6) << " erase " << std::endl;
    
//     // for (size_t i = 0; i < val1.size(); i++)
//     //     std::cout <<  b1[i] << std::endl; 
//     // std::cout << "capacity: " << val1.capacity() << std::endl;
//     // std::cout << "size: " << val1.size() << std::endl;
//     std::cout <<  "B2 y B3" << std::endl; 
//     for (size_t i = 0; b2 + i != e2; i++)
//         std::cout <<  b2[i] << std::endl; 
//     std::cout << "capacity: " << val2.capacity() << std::endl;
//     std::cout << "size: " << val2.size() << std::endl;
        
//     for (size_t i = 0; b3 + i != e3; i++)
//         std::cout <<  b3[i] << std::endl; 
//     std::cout << "capacity: " << val3.capacity() << std::endl; 
//     std::cout << "size: " << val3.size() << std::endl;

//     val2[2] = 777;

//     std::cout <<  "VAL2 y VAL3" << std::endl; 
//     for (size_t i = 0; i < val2.size(); i++)
//         std::cout <<  val2[i] << std::endl; 
//     std::cout << "capacity: " << val2.capacity() << std::endl;
//     std::cout << "size: " << val2.size() << std::endl;
        
//     for (size_t i = 0; i < val3.size(); i++)
//         std::cout <<  val3[i] << std::endl; 
//     std::cout << "capacity: " << val3.capacity() << std::endl; 
//     std::cout << "size: " << val3.size() << std::endl;
//     //atexit(leak);
//     return 0;
// }