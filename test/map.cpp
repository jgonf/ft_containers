/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:18:09 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/10 17:03:18 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/map.hpp"
#include <map>

void	test_iterator(void)
{
	ft::map<int, std::string> m1;
	ft::map<int, std::string>::iterator it;

	const ft::map<int, std::string> const_m1;
	ft::map<int, std::string>::const_iterator const_it;

	if (m1.begin() == m1.end())
		std::cout << "Bingo" << std::endl;
	else
		std::cout << "What" << std::endl;
	if (const_m1.begin() == const_m1.end())
		std::cout << "Bingo" << std::endl;
	else
		std::cout << "What" << std::endl;

	it = m1.begin();
	const_it = const_m1.begin();

	std::map <int, std::string> s1;
	std::map<int, std::string>::const_iterator sit;
	s1[12] = "12";
	s1[8] = "8";
	s1[24] = "24";
	s1[3] = "3";

//	for (sit = s1.begin(); sit != s1.end(); ++sit)
//		std::cout << sit->first << std::endl;
}

void	test_capacity(void)
{
	ft::map<int, std::string> m1;
	std::map <int, std::string> s1;

	if (!m1.size() && m1.empty())
		std::cout << "Bingo" << std::endl;
	else
		std::cout << "What" << std::endl;

	if (m1.max_size() == s1.max_size())
		std::cout << "Bingo" << std::endl;
	else
		std::cout << "What" << std::endl;

}

void	test_modifiers(void)
{
	ft::map<int, int> m1;
	ft::map<int, int> cpy;
	ft::map<int, int>::iterator it;

	m1.insert(ft::make_pair(10, 10));
	m1.insert(ft::make_pair(2, 2));
	m1.insert(ft::make_pair(5, 5));
	m1.insert(ft::make_pair(1, 1));

//	for (it = m1.begin(); it != m1.end(); ++it)
//		std::cout << (*it).second << std::endl;

	std::cout << "array : " << m1[2] << std::endl;
	std::cout << "find : " << (*m1.find(8)).second << std::endl;

	cpy.insert(m1.begin(), m1.end());

//	for (it = m1.begin(); it != m1.end(); ++it)
//		std::cout << (*it).second << std::endl;
//
//	for (it = cpy.begin(); it != cpy.end(); ++it)
//		std::cout << (*it).second << std::endl;
//
}

int main()
{
//	test_iterator();
//	test_capacity();
	test_modifiers();
	return 0;
}
