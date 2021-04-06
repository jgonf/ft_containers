/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:06:04 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/06 15:20:55 by jgonfroy         ###   ########.fr       */
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

void	test_relational_operator(void)
{
	std::cout << std::endl << "test relation operator" << std::endl;

	ft::vector<int> t1(4, 5);
	ft::vector<int> t2(2, 8);
	ft::vector<int> t3(4, 5);
	ft::vector<int> copy(t1);
	ft::vector<int> copy_operator = t1;

	std::cout << "Test 1: ";
	if (t1 == t2)
		std::cout << "What?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::cout << "Test 2: ";
	if (t1 == t3)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 3: ";
	if (t1 == copy)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 4: ";
	if (t1 == copy_operator)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 5: ";
	if (t1 != t2)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 6: ";
	if (t1 != t3)
		std::cout << "What?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::cout << "Test 7: ";
	if (t1 != copy)
		std::cout << "What?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::cout << "Test 8: ";
	if (t1 != copy)
		std::cout << "What?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::vector<int> s1(4, 5);
	std::vector<int> s2(2, 8);
	std::vector<int> s3(4, 5);

	std::cout << "Test 9: ";
	if ((t1 < t2) == (s1 < s2))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;
	std::cout << "Test 10: ";
	if ((t1 < t3) == (s1 < s3))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 11: ";
	if ((t1 <= t2) == (s1 <= s2))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;
	std::cout << "Test 12: ";
	if ((t1 <= t3) == (s1 <= s3))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 13: ";
	if ((t1 > t2) == (s1 > s2))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;
	std::cout << "Test 14: ";
	if ((t1 > t3) == (s1 > s3))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 15: ";
	if ((t1 >= t2) == (s1 >= s2))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;
	std::cout << "Test 16: ";
	if ((t1 <= t3) == (s1 <= s3))
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

}

void	test_constructor(void)
{
	std::cout << "Constructor and copy" << std::endl;
	ft::vector<std::string> empty;
	std::vector<std::string> emptystd;
	ft::vector<std::string> v1(5);
	std::vector<std::string> s1(5);
	ft::vector<std::string> v2(5, "toto");
	std::vector<std::string> s2(5, "toto");
	ft::vector<std::string> v3(v2.begin()+1, v2.end() - 2);
	std::vector<std::string> s3(s2.begin()+1, s2.end() - 2);
	ft::vector<std::string> copy(v2);
	ft::vector<std::string> assignation;
	assignation = v2;

	std::cout << "Test 1: ";
	if (empty.size() == emptystd.size() && empty.capacity() == emptystd.capacity())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 2: ";
	if (v1.size() == s1.size() && v1[0] == s1[0])
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 3: ";
	if (v2.size() == s2.size() && v2[0] == s2[0])
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 4: ";
	if (v3.size() == s3.size() && v3[0] == s3[0])
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 5: ";
	if (v2 == copy)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 6: ";
	if (v2 == assignation)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;


}

void	test_size_capacity(void)
{
	std::cout << "Test size, max_size, resize, capacity, empty and reserve" << std::endl;
	ft::vector<int> v1(3);
	std::vector<int> s1(3);

	std::cout << "Test 1: ";
	if (v1.size() == 3)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 2: ";
	if (v1.max_size() == s1.max_size())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	v1.resize(9, 5);
	std::cout << "Test 3: ";
	if (v1.size() == 9 && *(v1.end() -1) == 5)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	v1.resize(4, 9);
	std::cout << "Test 3: ";
	if (v1.size() == 4 && *(v1.end()-1) == 5)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	v1.reserve(20);
	std::cout << "Test 4: ";
	if (v1.capacity() == 20)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	v1.reserve(10);
	std::cout << "Test 5: ";
	if (v1.capacity() == 20)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 6: ";
	if (!v1.empty())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;


}

int main()
{
	test_constructor();
	std::cout << std::endl;

	test_iterator();
	std::cout << std::endl;

	test_size_capacity();
	//
	//	std::cout << std::endl << "Size, masx_size and resize " << std::endl;
	//	std::cout << "size v4 : " << v4.size() << std::endl;
	//
	//	std::vector<int> cmp;
	//	std::cout << "max size v1 : " << v1.max_size() << std::endl;
	//	std::cout << "max size vector from STL: " << cmp.max_size() << std::endl;
	//
	//	v2.resize(3, 4);
	//	v2.resize(9, 2);
	//
	//	std::cout << std::endl << "Capacity, empty and reserve" << std::endl;
	//	std::cout << "capacity v4: " << v4.capacity() << std::endl;
	//
	//	std::cout << "is v1 empty ? " << v1.empty() << std::endl;
	//	std::cout << "is v3 empty ? " << v3.empty() << std::endl;
	//
	//	std::cout << "capacity v1: " << v1.capacity() << std::endl;
	//	v1.reserve(3);
	//	std::cout << "capacity v1: " << v1.capacity() << std::endl;
	//	std::cout << "capacity v4: " << v4.capacity() << std::endl;
	//	v4.reserve(2);
	//	std::cout << "capacity v4: " << v4.capacity() << std::endl;
	//
	//	std::cout << std::endl << "Element access" << std::endl;
	//	std::cout << v4[3] << std::endl;
	//	std::cout << v4.at(3) << std::endl;
	//
	//	try {
	//		v4.at(12);
	//	}
	//	catch (std::exception & e)
	//	{
	//		std::cout << e.what() << std::endl;
	//	}
	//	v4[0] = "toto";
	//	v4[4] = "tata";
	//	std::cout << v4.front() << std::endl;
	//	std::cout << v4.back() << std::endl;
	//
	//
	//	std::cout << std::endl << "assign, push back and pop_back" << std::endl;
	//	v4.push_back("YOLO");
	//	std::cout << v4.back() << std::endl;
	//	v4.pop_back();
	//	std::cout << v4.back() << std::endl;
	//
	//
	//	std::cout << std::endl << "insert" << std::endl;
	//	ft::vector<std::string>::iterator itstr;
	//	std::cout << std::endl;
	//	for (itstr = v4.begin(); itstr != v4.end(); ++itstr)
	//		std::cout << *itstr << std::endl;
	//	itstr--;
	//	itstr--;
	//	v4.insert(itstr, "pouet");
	//	std::cout << std::endl;
	//	for (itstr = v4.begin(); itstr != v4.end(); ++itstr)
	//		std::cout << *itstr << std::endl;
	//	itstr = v4.begin();
	//	itstr++;
	//	v4.insert(itstr, 3, "chouette");
	//	std::cout << std::endl;
	//	std::cout << "Here" << std::endl;
	//	for (itstr = v4.begin(); itstr != v4.end(); ++itstr)
	//		std::cout << *itstr << std::endl;
	//
	//	std::cout << std::endl;
	//	ft::vector<int>::iterator it2;
	//	v2.push_back(8);
	//	v2.insert(v2.begin(), 3);
	//	it2 = v1.begin();
	//	std::cout << "Here" << std::endl;
	//	v1.push_back(18);
	//	v1.insert(it2, 29);
	//	v1.insert(it2, v2.begin(), v2.end());
	////	std::cout << "v2" << std::endl;
	////	for (it2 = v2.begin(); it2 != v2.end(); ++it2)
	////		std::cout << *it2 << std::endl;
	////	std::cout << "v1" << std::endl;
	////	for (it2 = v1.begin(); it2 != v1.end(); ++it2)
	////		std::cout << *it2 << std::endl;
	///*
	////
	//	ft::vector<int> t1(3,5);
	//	ft::vector<int>::iterator it;
	//	ft::vector<int> t2(8,56);
	//	ft::vector<int>::iterator it2;
	////	ft::vector<int>::iterator ite2;
	////	t1.insert(t1.begin(), 2, 8);
	////	it2 = t2.begin() + 3;
	////	ite2 = it2 + 5;
	////	t1.insert(t1.begin(), it2, ite2);
	////	for (it = t1.begin(); it != t1.end(); ++it)
	////		std::cout << *it << std::endl;
	////
	////
	////	std::vector<int> s1(3,5);
	////	std::vector<int>::iterator it1;
	////	std::vector<int> s2(20,56);
	////	std::vector<int>::iterator its;
	////	std::vector<int>::iterator ites;
	////	s1.insert(s1.begin(), 2, 8);
	////	its = s2.begin() + 3;
	////	ites = its + 5;
	////	s1.insert(s1.begin(), its, ites);
	////	for (it1 = s1.begin(); it1 != s1.end(); ++it1)
	////		std::cout << *it1 << std::endl;
	////
	////	t1.erase(t1.begin() + 2, t1.begin() + 9);
	////	std::cout << std::endl;
	////	for (it = t1.begin(); it != t1.end(); ++it)
	////		std::cout << *it << std::endl;
	////
	////	t1.erase(t1.begin(), t1.begin() + 4);
	////	std::cout << std::endl;
	////	for (it = t1.begin(); it != t1.end(); ++it)
	////		std::cout << *it << std::endl;
	//
	////	ft::vector<int> t1(3,5);
	////	t1.assign(2, 8);
	////	for (ft::vector<int>::iterator it = t1.begin(); it != t1.end(); ++it)
	////		std::cout << *it << std::endl;
	////
	//	std::cout << std::endl << "t1" << std::endl;
	//	for (it = t1.begin(); it != t1.end(); ++it)
	//		std::cout << *it << std::endl;
	//	
	//	std::cout << std::endl << "t2" << std::endl;
	//	for (it2 = t2.begin(); it2 != t2.end(); ++it2)
	//		std::cout << *it2 << std::endl;
	//	
	//	swap(t1, t2);
	//	std::cout << std::endl << "t1" << std::endl;
	//	for (it = t1.begin(); it != t1.end(); ++it)
	//		std::cout << *it << std::endl;
	//	
	//	std::cout << std::endl << "t2" << std::endl;
	//	for (it2 = t2.begin(); it2 != t2.end(); ++it2)
	//		std::cout << *it2 << std::endl;
	//*/
	//
	////	test_relational_operator();
	//
	return 1;
}

