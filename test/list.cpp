/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:18:09 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/01 11:16:48 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/list.hpp"
#include <list>
#include <stdlib.h>
#include <time.h>

bool multiple_digit (const int& value) { return (value>=10); }
bool cmp_length(const std::string& s1, const std::string& s2) { return (s1.size() < s2.size()); }

void	test_constructor(void)
{
	std::cout << "Test constructors :" << std::endl;

	ft::list<int, std::allocator<int> >	l1;
	ft::list<int>	l2(3);
	ft::list<int>	l3(10, 58);
	ft::list<int>	l4(l3.begin(), l3.end());
	ft::list<int>	copy(l2);
	ft::list<int>	assignation = l3;


	std::cout << "Test 1: ";
	if (l1.size() == 0)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 2: ";
	if (l2.size() == 3 && l2.back() == 0)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 3: ";
	if (l3.size() == 10 && l3.back() == 58)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 4: ";
	if (l4.size() == 10 && l4.back() == 58)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 5: ";
	if (copy.size() == 3 && copy.back() == 0)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	std::cout << "Test 6: ";
	if (assignation.size() == 10 && assignation.back() == 58)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

}


//void	test_iterators(void)
//{
//	std::cout << "Test iterators : " << std::endl;
//
//	ft::list<int> l1(1, 1);
//	ft::list<int>::iterator	it = l1.begin();
//	ft::list<int>::iterator copy(it);
//
//	if (l1 == copy)
//
//}
//

void	test_capacity(void)
{
	std::cout << "Test capacity :" << std::endl;

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
	std::cout << "Test access :" << std::endl;

	ft::list<int>	l1(5,4);

	std::cout << "Test 1: ";
	if (l1.front() == 4 && l1.back() == 4)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.push_front(20);
	l1.push_back(12);
	std::cout << "Test 2: ";
	if (l1.front() == 20 && l1.back() == 12)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

}

void	test_modifiers_partA(void)
{
	std::cout << "Test assign, push_front, pop_front, push_back, pop_back :" << std::endl;

	ft::list<int>	l1;
	ft::list<int>	l2;

	l1.assign(4, 12);

	std::cout << "Test 1: ";
	if (l1.front() == 12 && l1.front() == 12 && l1.size() == 4)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l2.assign(l1.begin(), l1.end());
	std::cout << "Test 2: ";
	if (l2.front() == 12 && l2.back() == 12 && l2.size() == 4)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.assign(9, 36);
	std::cout << "Test 3: ";
	if (l1.front() == 36 && l1.back() == 36 && l1.size() == 9)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l2.assign(l1.begin(), l1.end());
	std::cout << "Test 4: ";
	if (l2.front() == 36 && l2.back() == 36 && l2.size() == 9)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.push_front(45);
	std::cout << "Test 5: ";
	if (l1.front() == 45 && l1.size() == 10)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.pop_front();
	std::cout << "Test 6: ";
	if (l1.front() == 36 && l1.size() == 9)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.push_back(58);
	std::cout << "Test 7: ";
	if (l1.back() == 58 && l1.size() == 10)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.pop_back();
	std::cout << "Test 8: ";
	if (l1.back() == 36 && l1.size() == 9)
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

}

void	test_modifiers_partB(void)
{
	std::cout << "Test insert, erase :" << std::endl;

	bool error = false;

	ft::list<int>	l1(3, 12);
	ft::list<int>::iterator	it;
	ft::list<int>::iterator	it2;

	std::list<int>	s1(3, 12);
	std::list<int>::iterator	sit;
	std::list<int>::iterator	sit2;

	l1.push_back(28);
	l1.push_front(45);
	s1.push_back(28);
	s1.push_front(45);

	it = l1.begin();
	it++;
	it++;

	sit = s1.begin();
	sit++;
	sit++;

	std::cout << "Test 1: ";
	if (*l1.insert(it, 35) != *(s1.insert(sit, 35)))
		error = true;
	if (l1.size() != s1.size())
		error = true;
	sit = s1.begin();
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (sit == s1.end())
			error = true;
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	it = l1.end();
	it--;
	it--;
	l1.insert(it, 3, 106);

	sit = s1.end();
	sit--;
	sit--;
	s1.insert(sit, 3, 106);

	std::cout << "Test 2: ";
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit = s1.begin();
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (sit == s1.end())
			error = true;
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;


	ft::list<int>	l2(1, 8);
	l2.push_back(4);
	l2.push_back(3);

	std::list<int>	s2(1, 8);
	s2.push_back(4);
	s2.push_back(3);

	it = l1.begin();
	it++;
	l1.insert(it, l2.begin(), l2.end());
	sit = s1.begin();
	sit++;
	s1.insert(sit, s2.begin(), s2.end());

	std::cout << "Test 3: ";
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit = s1.begin();
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (sit == s1.end())
			error = true;
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	it = ++(++l1.begin());
	sit = ++(++s1.begin());
	l1.erase(it);
	s1.erase(sit);
	std::cout << "Test 4: ";
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit = s1.begin();
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	it2 = ++(++it);
	sit2 = ++(++sit);
	l1.erase(it, it2);
	s1.erase(sit, sit2);
	std::cout << "Test 5: ";
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit = s1.begin();
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

}


void	test_modifiers_partC(void)
{
	std::cout << "Test swap, resize and clear :" << std::endl;

	ft::list<int>	l1(3, 8);
	ft::list<int>	l2(6, 12);
	std::list<int>	s1(3, 8);
	std::list<int>	s2(6, 12);

	ft::list<int>::iterator	it;

	l1.swap(l2);
	s1.swap(s2);

	std::cout << "Test 1: ";
	if (l1.size() == s1.size() && l2.size() == s2.size() &&
		l1.front() == s1.front() && l2.back() == s2.back())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.resize(9, 5);
	s1.resize(9, 5);
	std::cout << "Test 2: ";
	if (l1.size() == s1.size() && l1.back() == s1.back())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l2.resize(4, 5);
	s2.resize(4, 5);
	std::cout << "Test 3: ";
	if (l2.size() == s2.size() && l2.back() == s2.back())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

	l1.clear();
	l2.clear();

	std::cout << "Test 4: ";
	if (l1.empty() && l2.empty())
		std::cout << "Success" << std::endl;
	else
		std::cout << "What ?" << std::endl;

}

void	test_operations_partA(void)
{
	std::cout << "Test : splice, remove, remove if" << std::endl;
	bool	error;
	ft::list<int> l1, l2;
	ft::list<int>::iterator it;
	ft::list<int>::iterator it2;
	std::list<int> s1, s2;
	std::list<int>::iterator sit;
	std::list<int>::iterator sit2;

	for (int i=1; i<=4; ++i)
		l1.push_back(i);
	for (int i=1; i<=3; ++i)
		l2.push_back(i*10);
	for (int i=1; i<=4; ++i)
		s1.push_back(i);
	for (int i=1; i<=3; ++i)
		s2.push_back(i*10);

	it = l1.begin();
	++it;
	l1.splice (it, l2);
	sit = s1.begin();
	++sit;
	s1.splice(sit, s2);

	std::cout << "Test 1: ";
	error = false;
	if (l2.empty() != s2.empty())
		error = true;
	if (*it != *sit)
		error = true;
	if (l1.size() != s1.size())
		error = true;
	sit2 = s1.begin();
	for (it2 = l1.begin(); it2 != l1.end(); ++it2)
	{
		if (sit2 == s1.end())
		{
			error = true;
			break;
		}
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::cout << "Test 2: ";
	it = ++(l1.begin());
	sit = ++(s1.begin());
//	it = l1.begin();
//	sit = s1.begin();

	l2.splice (l2.begin(), l1, it);
	s2.splice (s2.begin(), s1, sit);
	error = false;
	if (l1.size() != s1.size() || l2.size() != s2.size())
		error = true;
	if (l1.front() != s1.front())
		error = true;
	sit2 = s2.begin();
	for (it2 = l2.begin(); it2 != l2.end(); ++it2)
	{
		if (sit2 == s2.end())
		{
			error = true;
			break;
		}
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;


	std::cout << "Test 3: ";
	it = ++(++(l1.begin()));
	sit= ++(++(s1.begin()));
	l1.splice(l1.begin(), l1, it, l1.end());
	s1.splice(s1.begin(), s1, sit, s1.end());
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit2 = s1.begin();
	for (it2 = l1.begin(); it2 != l1.end(); ++it2)
	{
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::cout << "Test 4: ";
	l1.push_back(4);
	l1.push_front(4);
	l1.remove(4);
	s1.push_back(4);
	s1.push_front(4);
	s1.remove(4);
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit2 = s1.begin();
	for (it2 = l1.begin(); it2 != l1.end(); ++it2)
	{
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::cout << "Test 5: ";
	l1.remove_if(multiple_digit);
	s1.remove_if(multiple_digit);
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit2 = s1.begin();
	for (it2 = l1.begin(); it2 != l1.end(); ++it2)
	{
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;


}

void	test_operations_partB(void)
{
	std::cout << "Test : unique, sort, merge, reverse" << std::endl;

	bool	error;
	int		number;
	ft::list<int>	l1, l2;
	ft::list<int>::iterator	it;
	std::list<int>	s1, s2;
	std::list<int>::iterator	sit;
	ft::list<std::string>	l3, l4;
	ft::list<std::string>::iterator	it2;
	std::list<std::string>	s3, s4;
	std::list<std::string>::iterator	sit2;

	for (int i = 0; i < 10; ++i)
	{
		l1.push_back(i);
		l1.push_back(i);
		s1.push_back(i);
		s1.push_back(i);
	}

	std::cout << "Test 1: ";
	l1.unique();
	s1.unique();
	error = false;
	if (l1.size() != s1.size())
		error = true;
	sit = s1.begin();
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	for (int i = 0 ; i < 10 ; ++i)
	{
		number = rand() % 100;
		l2.push_back(number);
		s2.push_back(number);
	}

	std::cout << "Test 2: ";
	l2.sort();
	s2.sort();
	error = false;
	if (l2.size() != s2.size())
		error = true;
	sit = s2.begin();
	for (it = l2.begin(); it != l2.end(); ++it)
	{
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;


	l3.push_back("chouette");
	s3.push_back("chouette");
	l3.push_back("yo");
	s3.push_back("yo");
	l3.push_back("wesh");
	s3.push_back("wesh");

	std::cout << "Test 3: ";
	l3.sort(cmp_length);
	s3.sort(cmp_length);
	error = false;
	sit2 = s3.begin();
	for (it2 = l3.begin(); it2 != l3.end(); ++it2)
	{
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	l1.sort();
	l2.sort();
	s1.sort();
	s2.sort();

	std::cout << "Test 4: ";
	l1.merge(l2);
	s1.merge(s2);
	error = false;
	if (l2.empty() != s2.empty())
		error = true;
	sit = s1.begin();
	for (it = l1.begin(); it != l1.end(); ++it)
	{
		if (sit == s1.end())
		{
			error = true;
			break;
		}
		if (*it != *sit)
		{
			error = true;
			break;
		}
		++sit;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;


	l4.push_back("couette");
	s4.push_back("couette");
	l4.push_back("top");
	s4.push_back("top");
	l4.push_back("poto");
	s4.push_back("poto");
	l4.sort(cmp_length);
	s4.sort(cmp_length);


	std::cout << "Test 5: ";
	l3.merge(l4, cmp_length);
	s3.merge(s4, cmp_length);

	error = false;
	if (l4.empty() != s4.empty())
		error = true;
	sit2 = s3.begin();
	for (it2 = l3.begin(); it2 != l3.end(); ++it2)
	{
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;

	std::cout << "Test 6: ";
	l1.reverse();
	s1.reverse();
	error = false;
	sit2 = s3.begin();
	for (it2 = l3.begin(); it2 != l3.end(); ++it2)
	{
		if (*it2 != *sit2)
		{
			error = true;
			break;
		}
		++sit2;
	}
	if (error)
		std::cout << "What ?" << std::endl;
	else
		std::cout << "Success" << std::endl;
}

void	test_overloads(void)
{

	ft::list<int> a;
	ft::list<int> b;
	ft::list<int> c;

	for (int i = 10; i < 40; i = i + 10)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (int i = 30; i > 0; i = i - 10)
	{
		c.push_back(i);
	}

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	}


void	test_debug(void)
{
	ft::list<int>	l1, l2;
	ft::list<int>	l3(1);
	ft::list<int>	l4(5, 12);
	ft::list<int>::iterator	it;

	l3.push_back(8);
	for (it = l3.begin(); it != l3.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "front : " << l3.front() << std::endl;
	std::cout << "back : " << l3.back() << std::endl;
}

int main()
{
	srand(time(NULL));
//	test_debug();
	test_constructor();
	std::cout << std::endl;
//	test_iterators();
//	std::cout << std::endl;
	test_capacity();
	std::cout << std::endl;
	test_access();
	std::cout << std::endl;
	test_modifiers_partA();
	std::cout << std::endl;
	test_modifiers_partB();
	std::cout << std::endl;
	test_modifiers_partC();
	std::cout << std::endl;
	test_operations_partA();
	std::cout << std::endl;
	test_operations_partB();
	std::cout << std::endl;
	test_overloads();

	return 0;
}
