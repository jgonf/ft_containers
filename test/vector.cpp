/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:06:04 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/03/30 17:39:02 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vector.hpp"
#include <vector>


void	test_iterator(void)
{
	std::cout << "Iterator test" << std::endl;
	ft::vector<int> v1(5, 5);
	ft::vector<int> v2(5, 5);

	ft::vector<int>::iterator it;

	std::cout << "test 1: ";
	if (v1.begin() == v1.begin())
		std::cout << "Success" << std::endl;
	if (v1.begin() == v2.begin())
		std::cout << "What ?" << std::endl;

	std::cout << "test 2: ";
	if (v1.begin() != v2.begin())
		std::cout << "Success" << std::endl;
	if (v1.begin() != v1.begin())
		std::cout << "What ?" << std::endl;

	std::cout << "test 3: ";
	it = v2.begin();
	if(*it == 5)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 4: ";
	++it;
	--it;
	if(it == v2.begin())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 5: ";
	it++;
	it--;
	if(it == v2.begin())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	ft::vector<int> test1(1, 0);
	std::vector<int> cmp1(1, 0);

	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	cmp1.push_back(1);
	cmp1.push_back(2);
	cmp1.push_back(3);
	cmp1.push_back(4);

	ft::vector<int>::iterator it_test = test1.begin();
	std::vector<int>::iterator it_cmp = cmp1.begin();

	std::cout << "test 6: ";
	if (*(it_test + 3) == *(it_cmp + 3))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;
	std::cout << "test 7: ";
	if (*(2 + it_test) == *(2 + it_cmp))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;
	std::cout << "test 8: ";
	if (*(it_test) == *(it_cmp))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 9: ";
	it_test++;
	it_cmp++;
	if (*(it_test - 1) == *(it_cmp - 1))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 10: ";
	if ((it_test - (it_test + 3)) == (it_cmp - (it_cmp + 3)))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 11: ";
	if ((it_test - (it_test - 2)) == (it_cmp - (it_cmp - 2)))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 12: ";
	if ((it_test > it_test++) == (it_cmp > it_cmp++))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 13: ";
	if ((it_test <= it_test) == (it_cmp <= it_cmp))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 14: ";
	if ((it_test < it_test--) == (it_cmp < it_cmp--))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 15: ";
	if ((it_test >= it_test) == (it_cmp >= it_cmp))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "test 16: ";
	if (*(it_test -= 1) == *(it_cmp -= 1))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;
	std::cout << "test 17: ";
	if (*(it_test += 2) == *(it_cmp += 2))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;
	std::cout << "test 18: ";
	if (it_test[3] == it_cmp[3])
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;


}


int main()
{
//	test_iterator();
/*
	ft::vector<int> v1;
	ft::vector<int> v2(5,5);
	ft::vector<char> v3(5,'a');
	ft::vector<std::string> v4(5,"yo");

	ft::vector<int> copy(v1);
	copy = v2;

	std::cout << std::endl << "Iterartors " << std::endl;

	ft::vector<int>::iterator it;
	for (it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << std::endl;
	v3.rbegin();
	v3.rend();


	std::cout << std::endl << "Size, masx_size and resize " << std::endl;
	std::cout << "size v4 : " << v4.size() << std::endl;

	std::vector<int> cmp;
	std::cout << "max size v1 : " << v1.max_size() << std::endl;
	std::cout << "max size vector from STL: " << cmp.max_size() << std::endl;

	v2.resize(3, 4);
	v2.resize(9, 2);

	std::cout << std::endl << "Capacity, empty and reserve" << std::endl;
	std::cout << "capacity v4: " << v4.capacity() << std::endl;

	std::cout << "is v1 empty ? " << v1.empty() << std::endl;
	std::cout << "is v3 empty ? " << v3.empty() << std::endl;

	std::cout << "capacity v1: " << v1.capacity() << std::endl;
	v1.reserve(3);
	std::cout << "capacity v1: " << v1.capacity() << std::endl;
	std::cout << "capacity v4: " << v4.capacity() << std::endl;
	v4.reserve(2);
	std::cout << "capacity v4: " << v4.capacity() << std::endl;

	std::cout << std::endl << "Element access" << std::endl;
	std::cout << v4[3] << std::endl;
	std::cout << v4.at(3) << std::endl;

	try {
		v4.at(12);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	v4[0] = "toto";
	v4[4] = "tata";
	std::cout << v4.front() << std::endl;
	std::cout << v4.back() << std::endl;


	std::cout << std::endl << "assing, push back and pop_back" << std::endl;
	v4.push_back("YOLO");
	std::cout << v4.back() << std::endl;
	v4.pop_back();
	std::cout << v4.back() << std::endl;


	std::cout << std::endl << "insert" << std::endl;
	ft::vector<std::string>::iterator itstr;
	std::cout << std::endl;
	for (itstr = v4.begin(); itstr != v4.end(); ++itstr)
		std::cout << *itstr << std::endl;
	itstr--;
	itstr--;
	v4.insert(itstr, "pouet");
	std::cout << std::endl;
	for (itstr = v4.begin(); itstr != v4.end(); ++itstr)
		std::cout << *itstr << std::endl;
	itstr = v4.begin();
	itstr++;
	v4.insert(itstr, 3, "chouette");
	std::cout << std::endl;
	for (itstr = v4.begin(); itstr != v4.end(); ++itstr)
		std::cout << *itstr << std::endl;

	std::cout << std::endl;
	ft::vector<int>::iterator it2;
	v2.push_back(8);
	v2.insert(v2.begin(), 3);
	it2 = v1.begin();
	std::cout << "Here" << std::endl;
	v1.push_back(18);
	v1.insert(it2, 29);
	v1.insert(it2, v2.begin(), v2.end());
//	std::cout << "v2" << std::endl;
//	for (it2 = v2.begin(); it2 != v2.end(); ++it2)
//		std::cout << *it2 << std::endl;
//	std::cout << "v1" << std::endl;
	for (it2 = v1.begin(); it2 != v1.end(); ++it2)
		std::cout << *it2 << std::endl;
*/

	ft::vector<int> t1(3,5);
	ft::vector<int>::iterator it;
	ft::vector<int> t2(20,56);
	ft::vector<int>::iterator it2;
	ft::vector<int>::iterator ite2;
	t1.insert(t1.begin(), 2, 8);
	it2 = t2.begin() + 3;
	ite2 = it2 + 5;
	t1.insert(t1.begin(), it2, ite2);
	for (it = t1.begin(); it != t1.end(); ++it)
		std::cout << *it << std::endl;

//
//	std::vector<int> s1(3,5);
//	std::vector<int>::iterator it1;
//	std::vector<int> s2(20,56);
//	std::vector<int>::iterator its;
//	std::vector<int>::iterator ites;
//	s1.insert(s1.begin(), 2, 8);
//	its = s2.begin() + 3;
//	ites = its + 5;
//	s1.insert(s1.begin(), its, ites);
//	for (it1 = s1.begin(); it1 != s1.end(); ++it1)
//		std::cout << *it1 << std::endl;
//
	
	t1.erase(t1.begin() + 2, t1.begin() + 9);
	std::cout << std::endl;
	for (it = t1.begin(); it != t1.end(); ++it)
		std::cout << *it << std::endl;

//	t1.erase(t1.begin(), t1.begin() + 4);
//	std::cout << std::endl;
//	for (it = t1.begin(); it != t1.end(); ++it)
//		std::cout << *it << std::endl;

//	ft::vector<int> t1(3,5);
//	t1.assign(2, 8);
//	for (ft::vector<int>::iterator it = t1.begin(); it != t1.end(); ++it)
//		std::cout << *it << std::endl;
//
	return 1;
}

