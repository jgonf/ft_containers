/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:06:04 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/03/25 20:00:47 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/vector.hpp"
#include <vector>

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

	return 1;
}
