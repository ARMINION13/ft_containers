/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/11/14 19:50:34 by rgirondo         ###   ########.fr       */
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
	
	for (test::map<int,int>::iterator it1 = mp1.begin(); it1 != mp1.end(); it1++)
	{
		std::cout << "map: ";
		std::cout << it1->first << "=>" << it1->second << '\n';
	}
		//std::cout << "[10] = " << mp1[10] << '\n';
	return(0);
}