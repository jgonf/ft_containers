/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:18:09 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/11 14:45:59 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/list.hpp"
#include <list>

void	test_constructor(void)
{
	std::cout << "Test constructors :" << std::endl;

	ft::list<int>	l1;
	ft::list<int>	l2(3);
	ft::list<int>	l3(10, 58);
//	ft::list<int>	l4(l3.begin() + 2, l3.end() - 5);
	ft::list<int>	copy(l2);
	ft::list<int>	assignation = l3;


//	std::cout << "Test 1: ";
//	if (l1.size() == 0)
//		std::cout << "Success" << std::endl;
//	else
//		std::cout << "What ?" << std::endl;

//	std::cout << "Test 2: ";
//	if (l2.size() == 3 && l2.back == 0)
//		std::cout << "Success" << std::endl;
//	else
//		std::cout << "What ?" << std::endl;

//	std::cout << "Test 3: ";
//	if (l3.size() == 10 && l3.back() == 58)
//		std::cout << "Success" << std::endl;
//	else
//		std::cout << "What ?" << std::endl;

//	std::cout << "Test 4: ";
//	if (l4.size() == 2 && copy.back == 58)
//		std::cout << "Success" << std::endl;
//	else
//		std::cout << "What ?" << std::endl;

//	std::cout << "Test 5: ";
//	if (copy.size() == 3 && copy.back == 0)
//		std::cout << "Success" << std::endl;
//	else
//		std::cout << "What ?" << std::endl;

//	std::cout << "Test 6: ";
//	if (assignation.size() == 10 && assignation.back() == 58)
//		std::cout << "Success" << std::endl;
//	else
//		std::cout << "What ?" << std::endl;

}

//void	test_iterators(void) {}

void	test_capacity(void)
{
	ft::list<int>	l1;
	ft::list<int>	l2(6, 12);
	std::list<int>	s1;

	std::cout << "Test 1: ";
	if (l1.empty())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 2: ";
	if (!(l2.empty()))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 3: ";
	if (!(l1.size()))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 4: ";
	if (l2.size() == 6)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 5: ";
	if (l1.max_size() == s1.max_size())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

}

void	test_access(void)
{
	ft::list<int>	l1(5,4);

	l1.front();
	l1.back();
}

int main()
{
	test_constructor();
	std::cout << std::endl;
//	test_iterators();
	std::cout << std::endl;
	test_capacity();
	std::cout << std::endl;
	test_access();
	std::cout << std::endl;

	return 0;
}

