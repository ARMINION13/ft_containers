/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/11/11 21:32:32 by rgirondo         ###   ########.fr       */
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
	
	test::map<int, int>::iterator it1 = mp1.begin();
	it1++;
	mp1.insert(it1, std::pair<int, int>(15, 150));
	//for (std::map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it)
	std::cout << "map: ";
	std::cout << it1->first << "=>" << it1->second << '\n';

	return(0);
}