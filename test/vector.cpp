/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:06:04 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/03/27 15:22:36 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vector.hpp"
#include <vector>


int main()
{
	ft::vector<int> v1(5, 5);
	ft::vector<int> v2(5, 5);

	ft::vector<int>::itvec it;

	if (v1.begin() == v1.begin())
		std::cout << "Success" << std::endl;
	if (v1.begin() == v2.begin())
		std::cout << "What ?" << std::endl;

	if (v1.begin() != v2.begin())
		std::cout << "Success" << std::endl;
	if (v1.begin() != v1.begin())
		std::cout << "What ?" << std::endl;

	it = v2.begin();
	if(*it == 5)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;
	++it;
	--it;
	if(it == v2.begin())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	it++;
	it--;
	if(it == v2.begin())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	ft::vector<int> test1(1, 1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	ft::vector<int>::itvec it_test = test1.begin();

	std::cout << *(it_test + 3) << std::endl; 
	std::cout << *(2 + it_test) << std::endl; 
	std::cout << *(it_test) << std::endl; 
	it_test++;
	std::cout << *(it_test - 1) << std::endl; 
}

/*
int main()
{
	ft::vector<int> v1;
	ft::vector<int> v2(5,5);
	ft::vector<char> v3(5,'a');
	ft::vector<std::string> v4(5,"yo");

	ft::vector<int> copy(v1);
	copy = v2;

	std::cout << std::endl << "Iterartors " << std::endl;

	v2.end();
	for (int *it = v2.begin(); it != v2.end(); ++it)
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
	std::string *it;
	std::cout << std::endl;
	for (it = v4.begin(); it != v4.end(); ++it)
		std::cout << *it << std::endl;
	it--;
	it--;
	v4.insert(it, "pouet");
	std::cout << std::endl;
	for (it = v4.begin(); it != v4.end(); ++it)
		std::cout << *it << std::endl;
	it = v4.begin();
	it++;
	v4.insert(it, 3, "chouette");
	std::cout << std::endl;
	for (it = v4.begin(); it != v4.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;
	v2.push_back(8);
	v2.insert(v2.begin(), 3);
	v1.insert(v1.begin(), v2.begin(), v2.end());
	for (int *it2 = v2.begin(); it2 != v2.end(); ++it2)
		std::cout << *it2 << std::endl;

//	for (int *it2 = v1.begin(); it2 != v1.end(); ++it2)
//		std::cout << *it2 << std::endl;

	return 1;
}
*/
