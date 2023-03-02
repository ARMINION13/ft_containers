/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:25:59 by rgirondo          #+#    #+#             */
/*   Updated: 2023/03/02 19:27:28 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <memory>
#include "../map.hpp"

namespace ft
{
    
    template <class f,class s>
    class pair
    {
        public :
            typedef f first_type;
            typedef s second_type;

            first_type first;
            second_type second;
            
            pair() : first(), second() {};
            template<class a, class b>
            pair (const pair<a, b>& asg) : first(asg.first), second(asg.second) {};
            pair (const first_type& asg1, const second_type& asg2) : first(asg1), second(asg2) {};
            pair& operator=(const pair& asg)
            {
                this->first = asg.first;
                this->second = asg.second;
                return (*this);
            }
    };

    template <class key, class T>
    bool operator==(const ft::pair<key, T> &pr1, const ft::pair<key, T> &pr2)
    {
        return (pr1.first == pr2.first && pr1.second == pr2.second);
    }

    template <class key, class T>
    bool operator!=(const ft::pair<key, T> &pr1, const ft::pair<key, T> &pr2)
    {
        return(!(pr1 == pr2));
    }

    template <class key, class T>
    bool operator<(const ft::pair<key, T> &pr1, const ft::pair<key, T> &pr2)
    {
        return (pr1.first < pr2.first || (!(pr2.first < pr1.first) && pr1.second < pr2.second));
    }

    template <class key, class T>
    bool operator<=(const ft::pair<key, T> &pr1, const ft::pair<key, T> &pr2)
    {
        return (!(pr2 < pr1));
    }

    template <class key, class T>
    bool operator>(const ft::pair<key, T> &pr1, const ft::pair<key, T> &pr2)
    {
        return (pr2 < pr1);
    }

    template <class key, class T>
    bool operator>=(const ft::pair<key, T> &pr1, const ft::pair<key, T> &pr2)
    {
        return !(pr1 < pr2);
    }
}