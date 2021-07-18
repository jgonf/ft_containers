/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:18:42 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/07/18 11:18:37 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace ft
{

//ft::equal

	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
		{
			while (first1 != last1)
			{
				if (!(*first1 == *first2))
					return false;
				++first1;
				++first2;
			}
			return true;
		}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
		{
			while (first1 != last1)
			{
				if (!pred(*first1,*first2))
					return false;
				++first1;
				++first2;
			}
			return true;
		}


//ft::lexicographical_compare

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
		{
			  while (first1!=last1)
			  {
				  if (first2==last2 || *first2<*first1)
					  return false;
				  else if (*first1<*first2)
					  return true;
				  ++first1;
				  ++first2;
			  }
			  return (first2!=last2);
		}

	template <class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
		{
			  while (first1!=last1)
			  {
				  if (first2==last2 || comp(*first2,*first1))
					  return false;
				  else if (comp(*first1,*first2))
					  return true;
				  ++first1;
				  ++first2;
			  }
			  return (first2!=last2);
		}


//enable_if

	template<bool, class T>
		struct enable_if {};
	template<class T>
		struct enable_if<true, T> { typedef T type; };


//is_integral

	template <class T>
		struct is_integral {
			const static bool value = false;
		};

	template <>
		struct is_integral<int> {
			const static bool value = true;
	};

//is_const

	template<bool, typename, typename>
		struct is_const {};
	template<class T, class U>
		struct is_const<true, T, U> { typedef T type; };
	template<class T, class U>
		struct is_const<false, T, U> { typedef U type; };
}

#endif
