/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2022/10/19 16:48:17 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./containers/map.hpp"
#include <vector>
#include <iostream>
#include <map>

int main()
{
	ft::map<int, int> mp;

	mp.insert(std::pair<int, int>(10, 10));
	mp.insert(std::pair<int, int>(20, 20));
	mp.insert(std::pair<int, int>(30, 30));
	mp.insert(std::pair<int, int>(15, 15));
	mp.insert(std::pair<int, int>(5, 5));
	
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << mp[i] << std::endl;
	// }
	ft::map<int, int>::iterator i = mp.begin();
	std::cout << (*i)._data.first << "=>" << (*i)._data.second << std::endl;
	
	return(0);
}