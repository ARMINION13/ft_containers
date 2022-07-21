/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/07/21 16:23:25 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Vector.hpp"

void leak()
{
    system("leaks VectorTest");    
}

int main()
{
    std::vector<int> val1(2);
    ft::vector<int> val2(2);

    val1.at(0) = 1;
    val1.at(1) = 10;
    val2.at(0) = 2;
    val2.at(1) = 20;

    ft::vector<int>::iterator b2 = val2.begin();
    ft::vector<int>::iterator e2 = val2.end();
    std::vector<int>::iterator b1 = val1.begin();
    std::vector<int>::iterator e1 = val1.end();
    
    ft::vector<int> val3(val2);
    
    val3.push_back(42);
    val3.push_back(43);
    val3.push_back(44);

    val3.pop_back();
    val3.pop_back();

    ft::vector<int>::iterator i = val3.begin();

    i++;
    i++;

    std::cout << *val3.insert(i,777) << " insert " << std::endl;
    std::cout << *val3.insert(i,666) << " insert " << std::endl;
    std::cout << *val3.insert(i,555) << " insert " << std::endl;
    std::cout << *val3.erase(i, i + 6) << " erase " << std::endl;
    
    // for (size_t i = 0; i < val1.size(); i++)
    //     std::cout <<  b1[i] << std::endl; 
    // std::cout << "capacity: " << val1.capacity() << std::endl;
    // std::cout << "size: " << val1.size() << std::endl;
    
    // for (size_t i = 0; i < val2.size(); i++)
    //     std::cout <<  b2[i] << std::endl; 
    // std::cout << "capacity: " << val2.capacity() << std::endl;
    // std::cout << "size: " << val2.size() << std::endl;
    
    for (size_t i = 0; i < val3.size(); i++)
        std::cout <<  val3[i] << std::endl; 
    std::cout << "capacity: " << val3.capacity() << std::endl; 
    std::cout << "size: " << val3.size() << std::endl;
    
    //atexit(leak);
    return 0;
}