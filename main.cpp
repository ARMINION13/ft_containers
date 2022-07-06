/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/07/06 18:18:44 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Vector.hpp"

int main()
{
    std::vector<int> val1(2);
    ft::Vector<int> val2(2);

    val1.at(0) = 1;
    val1.at(1) = 10;
    val2.at(0) = 2;
    val2.at(1) = 20;

    ft::Vector<int>::iterator b2 = val2.begin();
    ft::Vector<int>::iterator e2 = val2.end();
    std::vector<int>::iterator b1 = val1.begin();
    std::vector<int>::iterator e1 = val1.end();
    
    ft::Vector<int> val3(b2, e2);
    
    for (size_t i = 0; i < val1.size(); i++)
        std::cout <<  b1[i] << std::endl; 
    std::cout << "capacity: " << val1.capacity() << std::endl;
    std::cout << "size: " << val1.size() << std::endl;
    
    for (size_t i = 0; i < val2.size(); i++)
        std::cout <<  b2[i] << std::endl; 
    std::cout << "capacity: " << val2.capacity() << std::endl;
    std::cout << "size: " << val1.size() << std::endl;
    
    for (size_t i = 0; i < val3.size(); i++)
        std::cout <<  val3[i] << std::endl; 
    std::cout << "capacity: " << val3.capacity() << std::endl; 
    std::cout << "size: " << val1.size() << std::endl;
    
    return 0;
}