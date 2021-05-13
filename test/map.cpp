/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:18:09 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/13 11:23:35 by jgonfroy         ###   ########.fr       */
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
	ft::map<int, int>::iterator it, ite;

	m1.insert(ft::make_pair(10, 10));
	m1.insert(ft::make_pair(15, 15));
	m1.insert(ft::make_pair(16, 16));
	m1.insert(ft::make_pair(12, 12));
	m1.insert(ft::make_pair(2, 2));
	m1.insert(ft::make_pair(5, 5));
	m1.insert(ft::make_pair(3, 3));
	m1.insert(ft::make_pair(1, 1));
	m1.insert(ft::make_pair(17, 17));

	std::cout << "m1 : " << std::endl;
	for (it = m1.begin(); it != m1.end(); ++it)
		std::cout << (*it).second << std::endl;

	std::cout << "array : " << m1[2] << std::endl;
	std::cout << "find : " << (*m1.find(8)).second << std::endl;

	it = ++m1.begin();
	cpy.insert(it, m1.end());

	std::cout << std::endl << "cpy : " << std::endl;
	for (ite = cpy.begin(); ite != cpy.end(); ++ite)
		std::cout << (*ite).second << std::endl;

	m1.insert(ft::make_pair(2, 2));
	it = ++cpy.begin();
	cpy.erase(it);

	std::cout << std::endl << "cpy after erase: " << std::endl;
	for (ite = cpy.begin(); ite != cpy.end(); ++ite)
		std::cout << (*ite).second << std::endl;

	it= ++(++m1.begin());
	++it;
	it= --(--m1.end());
	m1.erase(it);
	std::cout << std::endl << "m1 after erase: " << std::endl;
	for (ite = m1.begin(); ite != m1.end(); ++ite)
		std::cout << (*ite).second << std::endl;

	std::cout << std::endl << "ret erase key existante " << cpy.erase(2) << std::endl;
	std::cout << "ret erase key inexistante " << cpy.erase(24) << std::endl;
	std::cout << "cpy after erase: " << std::endl;
	for (ite = cpy.begin(); ite != cpy.end(); ++ite)
		std::cout << (*ite).second << std::endl;

	cpy.erase(cpy.begin(), cpy.end());
	std::cout << std::endl << "cpy after erase everything: " << std::endl;
	for (ite = cpy.begin(); ite != cpy.end(); ++ite)
		std::cout << (*ite).second << std::endl;

	m1.swap(cpy);
	std::cout << std::endl << "m1 after swap: " << std::endl;
	for (ite = m1.begin(); ite != m1.end(); ++ite)
		std::cout << (*ite).second << std::endl;
	std::cout << std::endl << "cpy after swap : " << std::endl;
	for (ite = cpy.begin(); ite != cpy.end(); ++ite)
		std::cout << (*ite).second << std::endl;

}

void	test_observers(void)
{
	ft::map<int, std::string> m1;

	m1.key_comp();
}

void	test_operations(void)
{
	ft::map<int, int> m1;
//	ft::map<int, int> const cpy = m1;
	ft::map<int, int>::iterator it, ite;

	m1.insert(ft::make_pair(10, 10));
	m1.insert(ft::make_pair(15, 15));
	m1.insert(ft::make_pair(16, 16));
	m1.insert(ft::make_pair(12, 12));
	m1.insert(ft::make_pair(2, 2));
	m1.insert(ft::make_pair(5, 5));
	m1.insert(ft::make_pair(3, 3));
	m1.insert(ft::make_pair(1, 1));
	m1.insert(ft::make_pair(17, 17));

	if (m1.find(-5) == m1.end())
		std::cout << "Cette key n'existe pas" << std::endl;
	else
		std::cout << "What" << std::endl;

	if ((it = m1.find(15)) != m1.end())
		std::cout << "La valeur associee est " << (*it).first << std::endl;
	else
		std::cout << "What" << std::endl;

	if (m1.count(-5) == 0)
		std::cout << "Cette key n'existe pas" << std::endl;
	else
		std::cout << "What" << std::endl;

	if ((m1.count(15)) == 1)
		std::cout << "Cette key existe" << std::endl;
	else
		std::cout << "What" << std::endl;

	ite = m1.lower_bound(11);
	std::cout << "lower bound : " << (*ite).first << std::endl;

	ite = m1.lower_bound(12);
	std::cout << "lower bound : " << (*ite).first << std::endl;

	ite = m1.upper_bound(11);
	std::cout << "upper bound : " << (*ite).first << std::endl;

	ite = m1.upper_bound(12);
	std::cout << "upper bound : " << (*ite).first << std::endl;

	std::cout << "equal range : ";
//	ret = m1.equal_range(11);
//	std::cout << ret.first->first << " => " << ret.first->second << '\n';
//	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

int main()
{
//	test_iterator();
//	test_capacity();
	test_modifiers();
//	test_observers();
//	test_operations();
	return 0;
}
