/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:08:00 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/03 19:53:23 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReverseIterator.hpp"
#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> v1(1, 5);
	typedef ft::vector<int>::iterator it_type;
	ft::reverse_iterator<it_type>	rev(v1.end());
	v1.push_back(9);
	v1.push_back(3);

	std::vector<int> s1(1, 5);
	typedef std::vector<int>::iterator its_type;
	std::reverse_iterator<its_type>	revs(s1.end());
	s1.push_back(9);
	s1.push_back(3);

	std::cout << std::endl << "Test reverse iterator" << std::endl << std::endl;

	std::cout << "Test 1: ";
	if (*rev == *revs)
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 2: ";
	if (*(rev - 1) == *(revs - 1))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 3: ";
	if (*(rev) == *(revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 4: ";
	if (*(rev--) == *(revs--))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 5: ";
	if (*(rev) == *(revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 6: ";
	if (*(--rev) == *(--revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 7: ";
	if (*(rev) == *(revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	rev = v1.rbegin();
	revs = s1.rbegin();

	std::cout << "Test 8: ";
	if (*rev == *revs)
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 9: ";
	if (*(rev + 1) == *(revs + 1))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 10: ";
	if (*(rev) == *(revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 11: ";
	if (*(rev++) == *(revs++))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 12: ";
	if (*(rev) == *(revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 13: ";
	if (*(++rev) == *(++revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 14: ";
	if (*(rev) == *(revs))
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << revs[0] << std::endl;
	std::cout << rev[0] << std::endl;
}
