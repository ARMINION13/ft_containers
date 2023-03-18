/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:14:31 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/18 19:27:40 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include <sys/time.h>
# include <stdio.h>
#include "type.hpp"
#include "containers/map.hpp"
#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include <map>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>    // std::lexicographical_compare

void	ft_every_test();
void	test_constructors();
void	test_assign();
long	time_now(struct timeval	*start);
void	test_swap_external();
void	test_lexicolographical_compare();
template < typename T>
void	print_vector(TYPE::vector<T> aux);
void	test_vector_iterators();
void	test_vector_reverse_iterators();
void	test_vector();
void	test_map();
void	test_stack();

int main()
{
	ft_every_test();
}

void ft_leaks()
{
	system("leaks VectorTest");
}













long	time_now(struct timeval	*start)
{
	long				ms;
	struct timeval		end;

	gettimeofday(&end, NULL);
	ms = (((end.tv_sec * (1000000) + end.tv_usec)
				- (start->tv_sec * 1000000 + start->tv_usec)));
	return (ms);
}




void	ft_every_test()
{
	// struct timeval start;
	// gettimeofday(&start, NULL);

	test_vector();
	// test_map();
	// test_stack();

	std::cout << "___________________"	<< std::endl;
	// std::cout << "_ It took: _"			<< time_now(&start) << "_ ms" << std::endl;
	std::cout << "___________________"	<< std::endl;
}









/*
**		Vector
*/

void	test_vector()
{
	//	Construct
	// {
	// 	TYPE::vector<int>	first;                                // empty vector of ints
	// 	TYPE::vector<int>	second (4,100);                       // four ints with value 100
	// 	TYPE::vector<int>	third (second.begin(),second.end());  // iterating through second
	// 	TYPE::vector<int>	fourth (third);                       // a copy of third
		
	// 	int											myints[] = {16,2,77,29};
	// 	TYPE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		
	// 	std::cout << "The contents of fifth are:";
	// 	for (TYPE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }

	// //	Operator=
	// {
	// 	TYPE::vector<int> foo (3,0);
	// 	TYPE::vector<int> bar (5,0);
		
	// 	bar = foo;
	// 	foo = TYPE::vector<int>();
		
	// 	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	// 	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	// }	
	// //	Begin
	// {
	// 	TYPE::vector<int> myvector;
	// 	for (int i = 1; i <= 5; i++) myvector.push_back(i);
		
	// 	std::cout << "myvector contains:";
	// 	for (TYPE::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// //	End
	// {
	// 	TYPE::vector<int> myvector;
	// 	for (int i=1; i<=5; i++) myvector.push_back(i);
		
	// 	std::cout << "myvector contains:";
	// 	for (TYPE::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// //	Rbegin
	// {
	// 	TYPE::vector<int> myvector (5);  // 5 default-constructed ints

	// 	int i = 0;

	// 	TYPE::vector<int>::reverse_iterator rit = myvector.rbegin();
	// 	for (; rit!= myvector.rend(); ++rit)
	// 		*rit = ++i;

	// 	std::cout << "myvector contains:";
	// 	for (TYPE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// //	Rend
	// {
	// 	TYPE::vector<int> myvector (5);  // 5 default-constructed ints
	// 	TYPE::vector<int>::reverse_iterator rit = myvector.rbegin();
		
	// 	int i = 0;
	// 	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
	// 		*rit = ++i;
		
	// 	std::cout << "myvector contains:";
	// 	for (TYPE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// //	Size
	// {
	// 	TYPE::vector<int>	myints;
	// 	std::cout << "0. size: " << myints.size() << '\n';

	// 	for (int i = 0; i < 10; i++) myints.push_back(i);
	// 	std::cout << "1. size: " << myints.size() << '\n';

	// 	myints.insert (myints.end(), 10,100);
	// 	std::cout << "2. size: " << myints.size() << '\n';

	// 	myints.pop_back();
	// 	std::cout << "3. size: " << myints.size() << '\n';
	// }



	ft_leaks();

		// Max Size
	{
		TYPE::vector<int>	myvector;
	
		for (int i = 0; i < 100; i++) myvector.push_back(i);
	
		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	}	































	
	//Resize
	{
		TYPE::vector<int> myvector;
		
		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);
		
		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);
		
		std::cout << "myvector contains:";
		for (size_t i = 0; i < myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}




	
	// Capacity
	{
		TYPE::vector<int> myvector;
	
		// set some content in the vector:
		for (int i = 0; i < 100; i++) myvector.push_back(i);
	
		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}




	
	// //Empty
	// {
	// 	TYPE::vector<int> myvector;
	// 	int sum (0);
		
	// 	for (int i = 1; i <= 10; i++)
	// 		myvector.push_back(i);
	// 	while (!myvector.empty())
	// 	{
	// 		sum += myvector.back();
	// 		myvector.pop_back();
	// 	}
	// 	std::cout << "total: " << sum << '\n';
	// }
	// //Reserve
	// {
	// 	TYPE::vector<int>::size_type			sz;
	
	// 	TYPE::vector<int>					foo;
	// 	sz = foo.capacity();
	// 	std::cout << "making foo grow:\n";
	// 	for (int i = 0; i < 100; ++i)
	// 	{
	// 		foo.push_back(i);
	// 		if (sz!=foo.capacity())
	// 		{
	// 			sz = foo.capacity();
	// 			std::cout << "capacity changed: " << sz << '\n';
	// 		}
	// 	}
	
	// 	TYPE::vector<int>					bar;
	// 	sz = bar.capacity();
	// 	bar.reserve(100);   // this is the only difference with foo above
	// 	std::cout << "making bar grow:\n";
	// 	for (int i = 0; i < 100; ++i)
	// 	{
	// 		bar.push_back(i);
	// 		if (sz!=bar.capacity())
	// 		{
	// 			sz = bar.capacity();
	// 			std::cout << "capacity changed: " << sz << '\n';
	// 		}
	// 	}
	// }
	// //	Operator[]
	// {
	// 	TYPE::vector<int> myvector (10);   // 10 zero-initialized elements
	
	// 	TYPE::vector<int>::size_type sz = myvector.size();
	
	// 	// assign some values:
	// 	for (unsigned i=0; i<sz; i++) myvector[i]=i;
	
	// 	// reverse vector using operator[]:
	// 	for (unsigned i=0; i<sz/2; i++)
	// 	{
	// 		int temp;
	// 		temp = myvector[sz-1-i];
	// 		myvector[sz-1-i]=myvector[i];
	// 		myvector[i]=temp;
	// 	}
	
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<sz; i++)
	// 		std::cout << ' ' << myvector[i];
	// 	std::cout << '\n';
	// }
	// // at
	// {
	// 	TYPE::vector<int> myvector (10);   // 10 zero-initialized ints
	
	// 	// assign some values:
	// 	for (unsigned i=0; i<myvector.size(); i++)
	// 		myvector.at(i)=i;
	
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector.size(); i++)
	// 		std::cout << ' ' << myvector.at(i);
	// 	std::cout << '\n';
	// }
	// // front
	// {
	// 	TYPE::vector<int> myvector;

	// 	myvector.push_back(78);
	// 	myvector.push_back(16);

	// 	// now front equals 78, and back 16

	// 	myvector.front() -= myvector.back();

	// 	std::cout << "myvector.front() is now " << myvector.front() << '\n';
	// }
	// //	back
	// {
	// 	TYPE::vector<int> myvector;
		
	// 	myvector.push_back(10);
	// 	while (myvector.back() != 0)
	// 	{
	// 		myvector.push_back ( myvector.back() -1 );
	// 	}
		
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector.size() ; i++)
	// 		std::cout << ' ' << myvector[i];
	// 	std::cout << '\n';
	// }
	// //	Assign
	// {
	// 	TYPE::vector<int> first;
	// 	TYPE::vector<int> second;
	// 	TYPE::vector<int> third;

	// 	first.assign (7,100);             // 7 ints with a value of 100

	// 	TYPE::vector<int>::iterator it;
	// 	it=first.begin()+1;

	// 	second.assign (it,first.end()-1); // the 5 central values of first

	// 	int myints[] = {1776,7,4};
	// 	third.assign (myints,myints+3);   // assigning from array.

	// 	std::cout << "Size of first: " << int (first.size()) << '\n';
	// 	std::cout << "Size of second: " << int (second.size()) << '\n';
	// 	std::cout << "Size of third: " << int (third.size()) << '\n';
	// }
	// //	Push Back
	// {
	// 	TYPE::vector<int> myvector;
		
	// 	myvector.push_back (1);
	// 	myvector.push_back (2);
	// 	myvector.push_back (3);
	// 	myvector.push_back (4);
	// 	myvector.push_back (5);
		
	// 	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	// }
	// //	Pop Back
	// {
	// 	TYPE::vector<int> myvector;
	// 	int sum (0);
	// 	myvector.push_back (100);
	// 	myvector.push_back (200);
	// 	myvector.push_back (300);
		
	// 	while (!myvector.empty())
	// 	{
	// 	  sum+=myvector.back();
	// 	  myvector.pop_back();
	// 	}
	// 	std::cout << "The elements of myvector add up to " << sum << '\n';
	// }
	// //	Insert
	// {
	// 	TYPE::vector<int> myvector (3,100);
	// 	TYPE::vector<int>::iterator it;
		
	// 	it = myvector.begin();
	// 	it = myvector.insert ( it , 200 );
		
	// 	it = myvector.begin();
		
	// 	TYPE::vector<int> anothervector (2,400);
	// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());
		
	// 	int myarray [] = { 501,502,503 };
	// 	myvector.insert (myvector.begin(), myarray, myarray+3);
		
	// 	std::cout << "myvector contains:";
	// 	for (it = myvector.begin(); it < myvector.end(); it++)
	// 	  std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// //	Erase
	// {
	//   TYPE::vector<int> myvector;
	
	//   // set some values (from 1 to 10)
	//   for (int i=1; i<=10; i++) myvector.push_back(i);
	
	//   // erase the 6th element
	//   myvector.erase (myvector.begin()+5);
	
	//   // erase the first 3 elements:
	//   myvector.erase (myvector.begin(),myvector.begin()+3);
	
	//   std::cout << "myvector contains:";
	//   for (unsigned i=0; i<myvector.size(); ++i)
	//     std::cout << ' ' << myvector[i];
	//   std::cout << '\n';
	// }
	// //	Swap
	// {
	// 	TYPE::vector<int> foo (3,100);   // three ints with a value of 100
	// 	TYPE::vector<int> bar (5,200);   // five ints with a value of 200
		
	// 	foo.swap(bar);
		
	// 	std::cout << "foo contains:";
	// 	for (unsigned i=0; i<foo.size(); i++)
	// 	  std::cout << ' ' << foo[i];
	// 	std::cout << '\n';
		
	// 	std::cout << "bar contains:";
	// 	for (unsigned i=0; i<bar.size(); i++)
	// 	  std::cout << ' ' << bar[i];
	// 	std::cout << '\n';
	// }
	// //	Clear
	// {
	// 	TYPE::vector<int> myvector;
	// 	myvector.push_back (100);
	// 	myvector.push_back (200);
	// 	myvector.push_back (300);
		
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector.size(); i++)
	// 		std::cout << ' ' << myvector[i];
	// 	std::cout << '\n';
		
	// 	myvector.clear();
	// 	myvector.push_back (1101);
	// 	myvector.push_back (2202);
		
	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i<myvector.size(); i++)
	// 		std::cout << ' ' << myvector[i];
	// 	std::cout << '\n';
	// }
	// //	Get_allocator
	// {
	// 	TYPE::vector<int> myvector;
	// 	int * p;
	// 	unsigned int i;
		
	// 	// allocate an array with space for 5 elements using vector's allocator:
	// 	p = myvector.get_allocator().allocate(5);
		
	// 	// construct values in-place on the array:
	// 	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
		
	// 	std::cout << "The allocated array contains:";
	// 	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	// 	std::cout << '\n';
		
	// 	// destroy and deallocate:
	// 	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	// 	myvector.get_allocator().deallocate(p,5);
	// }
	// //	Relational operators
	// {
	// 	TYPE::vector<int> foo (3,100);   // three ints with a value of 100
	// 	TYPE::vector<int> bar (2,200);   // two ints with a value of 200

	// 	if (foo==bar) std::cout << "foo and bar are equal\n";
	// 	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	// 	if (foo< bar) std::cout << "foo is less than bar\n";
	// 	if (foo> bar) std::cout << "foo is greater than bar\n";
	// 	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	// 	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	// }
	// //	Swap external
	// {
	// 	TYPE::vector<int> foo (3,100);   // three ints with a value of 100
	// 	TYPE::vector<int> bar (5,200);   // five ints with a value of 200

	// 	foo.swap(bar);

	// 	std::cout << "foo contains:";
	// 	for (TYPE::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
	// 	  std::cout << ' ' << *it;
	// 	std::cout << '\n';

	// 	std::cout << "bar contains:";
	// 	for (TYPE::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
	// 	  std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// test_vector_iterators();
	// test_vector_reverse_iterators();
	// test_lexicolographical_compare();
}








//
//		_______________________ Lexicographical_compare _______________________
//

bool	mycomp (int c1, int c2)
{
	return (c1 == c2);
}

void	test_lexicolographical_compare()
{
	std::cout << "\n\nLexicographical_compare" << std::endl;
	TYPE::vector<int> foo1;
	TYPE::vector<int> boo1;

	foo1.push_back(1);
	foo1.push_back(1);
	foo1.push_back(5);
	
	boo1.push_back(1);
	boo1.push_back(1);
	boo1.push_back(6);

	std::cout << "Test 1: " << TYPE::lexicographical_compare(foo1.begin(), foo1.begin() + 3, boo1.begin(), boo1.begin() + 3) << std::endl;




	TYPE::vector<int> foo2;
	TYPE::vector<int> boo2;

	foo2.push_back(10);
	
	boo2.push_back(99);

	std::cout << "Test 2: " << TYPE::lexicographical_compare(foo2.begin(), foo2.begin() + 1, boo2.begin(), boo2.begin() + 1, mycomp) << std::endl;





	TYPE::vector<int> foo3;
	TYPE::vector<int> boo3;

	foo3.push_back(10);
	
	boo3.push_back(10);

	std::cout << "Test 3: " << TYPE::lexicographical_compare(foo3.begin(), foo3.begin() + 1, boo3.begin(), boo3.begin() + 1, mycomp) << std::endl;
	



	TYPE::vector<int> foo4;
	TYPE::vector<int> boo4;

	foo4.push_back(1200);
	foo4.push_back(0);
	
	boo4.push_back(1200);
	boo4.push_back(1234);

	std::cout << "Test 4: " << TYPE::lexicographical_compare(foo4.begin(), foo4.begin() + 2, boo4.begin(), boo4.begin() + 2, mycomp) << std::endl;




	TYPE::vector<int> foo5;
	TYPE::vector<int> boo5;

	foo5.push_back(1200);
	foo5.push_back(0);
	
	boo5.push_back(12);
	boo5.push_back(10);

	std::cout << "Test 5: " << TYPE::lexicographical_compare(foo5.begin(), foo5.begin() + 2, boo5.begin(), boo5.begin() + 2, mycomp) << std::endl;	

}







/*
**		Iterators
*/


void	vi_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator				it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	it++;
	itc++;

	if (it == itc)
		std::cout << "it is equal" << std::endl;
}

void	vi_not_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator				it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	itc++;

	if (it != itc)
		std::cout << "it is not equal" << std::endl;
}

void	vi_major()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	it++;

	if (it > itc)
		std::cout << "it is bigger" << std::endl;
}

void	vi_major_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	if (it >= itc)
		std::cout << "it is bigger/equal" << std::endl;
}

void	vi_minor()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	itc++;

	if (it < itc)
		std::cout << "it is smaller" << std::endl;
}

void	vi_minor_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator		itc;

	it = vector.begin();
	itc = vector.begin();

	if (it <= itc)
		std::cout << "it is smaller/equal" << std::endl;
}

void	vi_plus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	std::cout << *(it + 1) << std::endl;
	std::cout << *it << std::endl << std::endl;

}

void	vi_plus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	std::cout << *(it += 1) << std::endl;
	std::cout << *it << std::endl << std::endl;

}

void	vi_minus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	it++;
	it++;
	std::cout << *(it - 1) << std::endl;
	std::cout << *it << std::endl << std::endl;
}

void	vi_minus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::iterator			it;

	it = vector.begin();
	it++;
	it++;
	std::cout << *(it -= 1) << std::endl;
	std::cout << *it << std::endl << std::endl;
}


void	vi_incre_pre()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	itc = vector.begin();
	it = vector.begin();

	std::cout << "Const:     " << *(++itc) << std::endl;
	std::cout << "Non Const: " << *(++it) << std::endl;
}

void	vi_incre_post()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	itc = vector.begin();
	it = vector.begin();

	std::cout << "Const:     " << *(itc++) << " -> " << *itc << std::endl;
	std::cout << "Non Const: " << *(it++)  << " -> " << *it  << std::endl << std::endl;
}

void	vi_decre_pre()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;

	itc = vector.begin();
	it = vector.begin();

	it++;
	it++;

	itc++;
	itc++;

	std::cout << "Const:     " << *(--itc) << std::endl;
	std::cout << "Non Const: " << *(--it) << std::endl;
}

void	vi_decre_post()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	itc = vector.begin();
	it = vector.begin();

	it++;
	it++;

	itc++;
	itc++;

	std::cout << "Const:     " << *(itc--) << " -> " << *itc << std::endl;
	std::cout << "Non Const: " << *(it--)  << " -> " << *itc << std::endl << std::endl;
}

void	vi_copy()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);


	TYPE::vector<int>::iterator	it;
	TYPE::vector<int>::const_iterator	itc;
	
	it = vector.begin();
	it++;
	it++;

	itc = it;

	std::cout << "Copied: " << *itc << " _ Original: " << *it << std::endl;
}

void	vi_dereference()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator	itc;

	itc = vector.begin();
	it = vector.begin();

	it++;
	it++;

	itc++;
	itc++;

	std::cout << "Const:     " << *(itc) << std::endl;
	std::cout << "Non Const: " << *(it) << std::endl;

	int &og = *(it);

	og = 42;

	std::cout << og << " _ " << *(itc)<< std::endl;
}

void	vi_brackets()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::iterator			it;
	TYPE::vector<int>::const_iterator	itc;

	itc = vector.begin();
	it = vector.begin();

	std::cout << "Const:     " << itc[2] << std::endl;
	std::cout << "Non Const: " << it[2] << std::endl;
}

void	test_vector_iterators()
{
	vi_equal();
	vi_not_equal();
	vi_minor();
	vi_minor_equal();
	vi_major();
	vi_major_equal();
	vi_plus();
	vi_plus_equal();
	vi_minus();
	vi_minus_equal();
	vi_incre_pre();
	vi_incre_post();
	vi_decre_pre();
	vi_decre_post();
	vi_copy();
	vi_dereference();
	vi_brackets();
}





/*
**		rev_ite
*/



void	vri_equal()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();
	if (rit == rita)
		std::cout << "These are equal" << std::endl;
}

void	vri_not_equal()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();
	rita++;

	if (rit != rita)
		std::cout << "These are not equal" << std::endl;
}



void	vri_minor()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	rita++;
	if (rit < rita)
		std::cout << "First is minor" << std::endl;
}

void	vri_minor_equal()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	if (rit <= rita)
		std::cout << "First is minor or equal" << std::endl;
}

void	vri_major()
{
	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	rit++;
	if (rit > rita)
		std::cout << "First is mayor" << std::endl;
}

void	vri_major_equal()
{
 	TYPE::vector<int>								vector;
	TYPE::vector<int>::reverse_iterator				rit;
	TYPE::vector<int>::const_reverse_iterator		rita;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	rit = vector.rbegin();
	rita = vector.rbegin();

	if (rit >= rita && *(rit++) && rit >= rita)
		std::cout << "First is mayor/equal" << std::endl;
}


void	vri_plus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	std::cout << *(rit + 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}

void	vri_plus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	std::cout << *(rit += 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}

void	vri_minus()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	rit++;
	rit++;
	std::cout << *(rit - 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}

void	vri_minus_equal()
{
	TYPE::vector<int>						vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	
	TYPE::vector<int>::reverse_iterator			rit;

	rit = vector.rbegin();
	rit++;
	rit++;
	std::cout << *(rit -= 1) << std::endl;
	std::cout << *rit << std::endl << std::endl;
}


void	vri_incre_pre()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	rit = vector.rbegin();
	ritc = vector.rbegin();

	std::cout << "Const:     " << *(++rit) << std::endl;
	std::cout << "Non Const: " << *(++ritc) << std::endl;
}

void	vri_incre_post()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	rit = vector.rbegin();
	ritc = vector.rbegin();

	std::cout << "Const:     " << *(ritc++) << " -> " << *ritc << std::endl;
	std::cout << "Non Const: " << *(rit++)  << " -> " << *rit  << std::endl << std::endl;
}

void	vri_decre_pre()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;

	ritc = vector.rbegin();
	rit = vector.rbegin();

	rit++;
	rit++;

	ritc++;
	ritc++;

	std::cout << "Const:     " << *(--ritc) << std::endl;
	std::cout << "Non Const: " << *(--rit) << std::endl;
}

void	vri_decre_post()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	ritc = vector.rbegin();
	rit = vector.rbegin();

	rit++;
	rit++;

	ritc++;
	ritc++;

	std::cout << "Const:     " << *(ritc--) << " -> " << *ritc << std::endl;
	std::cout << "Non Const: " << *(rit--)  << " -> " << *ritc << std::endl << std::endl;
}

void	vri_copy()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);


	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;
	
	rit = vector.rbegin();
	rit++;
	rit++;

	ritc = rit;

	std::cout << "Copied: " << *ritc << " _ Original: " << *rit << std::endl;
}

void	vri_dereference()
{
	TYPE::vector<int>							vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;

	rit = vector.rbegin();
	ritc = vector.rbegin();

	rit++;
	rit++;

	ritc++;
	ritc++;

	std::cout << "Const:     " << *(ritc) << std::endl;
	std::cout << "Non Const: " << *(rit) << std::endl;

	int &og = *(rit);

	og = 42;

	std::cout << og << " _ " << *(ritc)<< std::endl;
}

void	vri_brackets()
{
	TYPE::vector<int>					vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	TYPE::vector<int>::reverse_iterator			rit;
	TYPE::vector<int>::const_reverse_iterator	ritc;

	rit = vector.rbegin();
	ritc = vector.rbegin();

	std::cout << "Non Const: " << rit[2] << std::endl;
	std::cout << "Const:     " << ritc[2] << std::endl;
}

void	test_vector_reverse_iterators()
{
	vri_equal();
	vri_not_equal();
	vri_minor();
	vri_minor_equal();
	vri_major();
	vri_major_equal();
	vri_plus();
	vri_plus_equal();
	vri_minus();
	vri_minus_equal();
	vri_incre_pre();
	vri_incre_post();
	vri_decre_pre();
	vri_decre_post();
	vri_copy();
	vri_dereference();
	vri_brackets();
}






















/*
**		Map
*/

bool fncomp (char lhs, char rhs) {	return lhs<rhs;}
struct classcomp
{
	bool operator() (const char& lhs, const char& rhs) const
		{	return lhs<rhs;	}
};


void	test_map()
{
	//Constructor
	{
		TYPE::map<char,int> first;                      

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		
		TYPE::map<char,int> second (first.begin(),first.end());
		
		TYPE::map<char,int> third (second);
		
		TYPE::map<char,int,classcomp> fourth;                 // class as Compare
		
		bool(*fn_pt)(char,char) = fncomp;
		TYPE::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	}
	// Operator=
	{
		TYPE::map<char,int> first;
		TYPE::map<char,int> second;
		
		first['x']=8;
		first['y']=16;
		first['z']=32;
		
		second = first;                // second now contains 3 ints
		first = TYPE::map<char,int>();  // and first is now empty
		
		std::cout << "Size of first: " << first.size() << '\n';
		std::cout << "Size of second: " << second.size() << '\n';
	}
	//	Begin
	{
		TYPE::map<char,int> mymap;
	
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
	
		// show content:
		for (TYPE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		  std::cout << it->first << " => " << it->second << '\n';
	}
	//	End
	{
		TYPE::map<char,int> mymap;
	
		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
	
		// show content:
		for (TYPE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	//	Rbegin
	{
		TYPE::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		TYPE::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	//	Rend
	{
		TYPE::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		// show content:
		TYPE::map<char,int>::reverse_iterator rit;
		for (rit = mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	// Empty
	{
		TYPE::map<char,int> mymap;

		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		while (!mymap.empty())
		{
		  std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		  mymap.erase(mymap.begin());
		}
	}
	//	Size
	{
		TYPE::map<char,int> mymap;

		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;
		
		std::cout << "mymap.size() is " << mymap.size() << '\n';
	}
	//	Max_size
	{
		int i;
		TYPE::map<int,int> mymap;

		if (mymap.max_size()>1000)
		{
		  for (i = 0; i < 1000; i++) mymap[i] = 0;
		  std::cout << "The map contains 1000 elements.\n";
		}
		else std::cout << "The map could not hold 1000 elements.\n";
	}
	//	Operator[]
	{
		TYPE::map<char,std::string> mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}
	//	Insert
	{
		TYPE::map<char, int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( TYPE::pair<char,int>('a',100) );
		mymap.insert ( TYPE::pair<char,int>('z',200) );

		TYPE::pair<TYPE::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( TYPE::pair<char,int>('z',500) );
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		TYPE::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, TYPE::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, TYPE::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		TYPE::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it = anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	//	Erase
	{
		TYPE::map<char,int> mymap;
		TYPE::map<char,int>::iterator it;
		
		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		
		it = mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		
		mymap.erase ('c');                  // erasing by key
		
		it = mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		
		// show content:
		for (it = mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	//	Swap
	{
		TYPE::map<char,int> foo,bar;

		foo['x'] = 100;
		foo['y'] = 200;

		bar['a'] = 11;
		bar['b'] = 22;
		bar['c'] = 33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (TYPE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (TYPE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
	}
	//	Clears
	{
		TYPE::map<char,int> mymap;
	
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
	
		std::cout << "mymap contains:\n";
		for (TYPE::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		  std::cout << it->first << " => " << it->second << '\n';
	
		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;
	
		std::cout << "mymap contains:\n";
		for (TYPE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		  std::cout << it->first << " => " << it->second << '\n';
	}
	//	Key_comp
	{
		TYPE::map<char,int> mymap;

		TYPE::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		TYPE::map<char,int>::iterator it = mymap.begin();
		do {
		  std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
	}
	//	Value_comp
	{
		TYPE::map<char,int> mymap;

		mymap['x'] = 1001;
		mymap['y'] = 2002;
		mymap['z'] = 3003;

		std::cout << "mymap contains:\n";

		TYPE::pair<char,int> highest = *mymap.rbegin();          // last element

		TYPE::map<char,int>::iterator it = mymap.begin();
		do {
		  std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}
	//	Find
	{
		TYPE::map<char,int>				mymap;
		TYPE::map<char,int>::iterator	it;

		mymap['a'] = 50;
		mymap['b'] = 100;
		mymap['c'] = 150;
		mymap['d'] = 200;

		it = mymap.find('b');
		if (it != mymap.end())
		  mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	//	Count
	{
		TYPE::map<char,int> mymap;
		char c;
		
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;
		for (c = 'a'; c < 'h'; c++)
		{
		  std::cout << c;
		  if (mymap.count(c)>0)
		    std::cout << " is an element of mymap.\n";
		  else 
		    std::cout << " is not an element of mymap.\n";
		}
	}
	//	Lower_bound
	{
		TYPE::map<char,int>				mymap;
		TYPE::map<char,int>::iterator		itlow,itup;

		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;

		itlow = mymap.lower_bound ('b');  // itlow points to b
		itup = mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (TYPE::map<char, int>::iterator it=mymap.begin(); it!= mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	//	Upper_bound
	{
		TYPE::map<char,int> mymap;
		TYPE::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow = mymap.lower_bound ('b');  // itlow points to b
		itup = mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		for (TYPE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	//	Equal Range
	{
		TYPE::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		TYPE::pair<TYPE::map<char,int>::iterator,TYPE::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	//	Get allocator
	{
		int psize;
		TYPE::map<char,int> mymap;
		TYPE::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p=mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(TYPE::map<char,int>::value_type)*5;

		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}
}





/*		
**	Stack
*/		                                                                       

void		test_stack()
{
	//	Constructor
	{
		std::deque<int> mydeque (3,100);
		TYPE::vector<int> myvector (2,200);
	
		TYPE::stack<int, std::deque<int> > first;
		first.push(2);
		
		TYPE::stack<int,TYPE::vector<int> > second;
		TYPE::stack<int,TYPE::vector<int> > third (myvector);
	
		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';

	}
	//	Empty
	{
		TYPE::stack<int> mystack;
		int sum (0);

		for (int i = 1;i <= 10; i++) mystack.push(i);

		while (!mystack.empty())
		{
		   sum += mystack.top();
		   mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	//	Size
	{
		TYPE::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	//	Top
	{
		TYPE::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	//	Push
	{
		TYPE::stack<int> mystack;

		for (int i = 0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
		   std::cout << ' ' << mystack.top();
		   mystack.pop();
		}
		std::cout << '\n';
	}
	//	Pop
	{
		TYPE::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
		   std::cout << ' ' << mystack.top();
		   mystack.pop();
		}
		std::cout << '\n';
	}
}




//
//		Aux Functions 
//

template < typename T>
void print_vector(TYPE::vector<T> aux)
{
	for (size_t i = 0; i < aux.size(); ++i)
		std::cout << aux[i] << std::endl;
}























































// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	//namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public TYPE::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename TYPE::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	TYPE::vector<std::string> vector_str;
// 	TYPE::vector<int> vector_int;
// 	TYPE::stack<int> stack_int;
// 	TYPE::vector<Buffer> vector_buffer;
// 	TYPE::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	TYPE::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	TYPE::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		TYPE::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }



