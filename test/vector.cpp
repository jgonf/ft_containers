/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:06:04 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/02 10:58:58 by jgonfroy         ###   ########.fr       */
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

	for (int i = 1; i < 7; ++i)
	{
		test1.push_back(i);
		cmp1.push_back(i);
	}

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

void	test_constructor(void)
{
	std::cout << "Constructor and copy" << std::endl;
	ft::vector<std::string> empty;
	std::vector<std::string> emptystd;
	ft::vector<std::string, std::allocator<std::string> > v1(5);
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

	std::cout << "Test 7: ";
	try {
		v1.reserve(v1.max_size() + 1);
		std::cout << "What? " << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << "Success" << std::endl;
	}
}

void	test_element_access(void)
{
	std::cout << "Test [], at, front, back" << std::endl;

	ft::vector<char> v1(4,'a');

	std::cout << "Test 1: ";
	if (v1[0] == 'a' && v1[3] == 'a')
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 2: ";
	if (v1.at(0) == 'a' && v1.at(3) == 'a')
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 3: ";
	try {
		v1.at(4);
		std::cout << "What? " << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << "Success" << std::endl;
	}

	v1[0] = 'b';
	v1[3] = 'c';
	std::cout << "Test 4: ";
	if (v1.front() == 'b' && v1.back() == 'c')
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

}

void	test_modifiers1(void)
{
	std::cout << "Test assign, push_back and pop_back" << std::endl;

	ft::vector<int> v1;
	ft::vector<int> v2;

	std::cout << "Test 1: ";
	v1.assign(7, 15);
	if (v1.size() == 7 && v1[6] == 15)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 2: ";
	v2.assign(v1.begin(), v1.begin() + 3);
	if (v2.size() == 3 && v2[2] == 15)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 3: ";
	v1.push_back(6);
	if (v1.back() == 6)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 4: ";
	v1.pop_back();
	if (v1.back() == 15)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

}

void	test_modifiers2(void)
{
	std::cout << "Test insert, erase, swap and clear" << std::endl;

	ft::vector<std::string> v1(2, "YOLO");
	ft::vector<std::string> v2(4, "wesh");

	std::cout << "Test 1: ";
	v1.insert(v1.begin() + 1, "Roger");
	if (v1.size() == 3 && v1[1] == "Roger")
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 2: ";
	v1.insert(v1.begin() + 2, 3, "toto");
	if (v1.size() == 6 && v1[2] == "toto" && v1[4] == "toto")
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 3: ";
	v2.insert(v2.begin() + 2, v1.begin(), v1.begin() + 3);
	if (v2[2] == "YOLO" && v2[3] == "Roger" && v2[4] == "toto" && v2[5] == "wesh")
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 4: ";
	v2.erase(v2.begin() + 1);
	if (v2[1] == "YOLO")
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;
	
	std::cout << "Test 5: ";
	v2.erase(v2.begin() + 1, v2.begin() + 4);
	if (v2[0] == "wesh" && v2[1] == "wesh")
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;

	std::cout << "Test 6: ";
	v1.swap(v2);
	if (v1.size() == 3 && v1[0] == "wesh" && v2.size() == 6 && v2[0] == "YOLO")
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;
	
	std::cout << "Test 7: ";
	swap(v1, v2);
	if (v2.size() == 3 && v2[0] == "wesh" && v1.size() == 6 && v1[0] == "YOLO")
		std::cout << "Success" << std::endl;
	else
		std::cout << "What?" << std::endl;


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

void	test_debug(void)
{
	std::string s1, s2;
}

int main()
{
//	test_debug();

	test_constructor();
	std::cout << std::endl;

	test_iterator();
	std::cout << std::endl;

	test_size_capacity();
	std::cout << std::endl;

	test_element_access();
	std::cout << std::endl;

	test_modifiers1();
	std::cout << std::endl;

	test_modifiers2();
	std::cout << std::endl;

	test_relational_operator();
	std::cout << std::endl;

	return 1;
}

