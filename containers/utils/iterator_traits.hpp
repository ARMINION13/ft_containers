/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:21:02 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/18 18:21:06 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_TRAITS_
#define _ITERATOR_TRAITS_

#include <iostream>

namespace ft
{
	template <typename _Iterator>
		struct iterator_traits
	    {
			typedef typename _Iterator::iterator_category					iterator_category;
			typedef typename _Iterator::value_type							value_type;
			typedef typename _Iterator::difference_type						difference_type;
			typedef typename _Iterator::pointer								pointer;
			typedef typename _Iterator::reference							reference;
		};
	
	
	template <typename _Tp>
		struct iterator_traits<_Tp*>
		{
			typedef std::random_access_iterator_tag							iterator_category;
			typedef _Tp														value_type;
			typedef ptrdiff_t												difference_type;
			typedef _Tp*													pointer;
			typedef _Tp&													reference;
		};
	
	
	template <typename _Tp>
		struct iterator_traits<const _Tp*>
		{
			typedef std::random_access_iterator_tag 						iterator_category;
			typedef _Tp														value_type;
			typedef ptrdiff_t												difference_type;
			typedef const _Tp*												pointer;
			typedef const _Tp&												reference;
		};
}

#endif