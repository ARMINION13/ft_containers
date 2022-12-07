/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/12/07 17:08:45 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./containers/map.hpp"
#include <vector>
#include <iostream>
#include <map>


#define	test ft

int main()
{
	test::map<int, int> mp1;

	mp1.insert(std::pair<int, int>(10, 100));
	mp1.insert(std::pair<int, int>(20, 200));
	mp1.insert(std::pair<int, int>(30, 300));	
	mp1.insert(std::pair<int, int>(15, 150));
	//mp1.erase(10);
	//mp1.erase(15);
	//mp1.erase(20);
	//mp1.erase(30);
	mp1.clear();

	
	for (test::map<int,int>::iterator it1 = mp1.begin(); it1 != mp1.end(); it1++)
	{
		std::cout << "map: ";
		std::cout << it1->first << "=>" << it1->second << '\n';
	}
	std::cout << "root = " << mp1.begin()->first << std::endl;
	std::cout << "[0] = " << mp1[0] << '\n';
	std::cout << "size = " << mp1.size() << std::endl;
	return(0);
}
