/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:46:21 by rgirondo          #+#    #+#             */
/*   Updated: 2023/01/25 22:20:42 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> const mp;
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(); // <-- error expected

	(void)it;
	return (0);
}