/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:32:43 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/08 13:42:01 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <memory>

namespace ft
{

    template <class T, T v>
    struct integral_constant
    {
        static const    T value = v;
        typedef         T value_type;
        typedef         integral_constant<T,v> type;
        
        operator value_type() const { return value; }
    };

    typedef integral_constant<bool,true>    true_type;
    typedef integral_constant<bool,false>   false_type;

    template <class T>
    struct is_integral : false_type {};

    template<>
	struct is_integral<bool> : true_type {};

    template<>
	struct is_integral<char> : true_type {};

    template<>
	struct is_integral<unsigned char> : true_type {};

    template<>
	struct is_integral<int> : true_type {};

    template<>
	struct is_integral<unsigned int> : true_type {};

    template<>
	struct is_integral<long> : true_type {};

    template<>
	struct is_integral<unsigned long> : true_type {};

    template<>
	struct is_integral<long long> : true_type {};

    template<>
	struct is_integral<unsigned long long> : true_type {};

    template <bool Cond, class T = void>
    struct enable_if;

    template<class T>
    struct enable_if<true, T> { typedef T type; };

}