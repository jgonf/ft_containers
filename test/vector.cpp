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

#include <vector>
#include <map>
#include <stack>
#include "../srcs/vector.hpp"
#include "../srcs/map.hpp"
#include "../srcs/stack.hpp"

template<typename T>
void	print_vector(NAMESPACE::vector<T> test)
{
	typename NAMESPACE::vector<T>::iterator it;

	std::cout << "Elements: " << std::endl;
	for (it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}

void	vector_constructors(void)
{
	std::cout << "Test constructors and copy" << std::endl;
	NAMESPACE::vector<std::string> empty;
	NAMESPACE::vector<std::string, std::allocator<std::string> > v1(5);
	NAMESPACE::vector<std::string> v2(5, "toto");
	NAMESPACE::vector<std::string> v3(v2.begin()+1, v2.end() - 2);
	NAMESPACE::vector<std::string> copy(v2);
	NAMESPACE::vector<std::string> assignation;
	assignation = v1;

	std::cout << "Size of empty() : " << empty.size() << std::endl;
	std::cout << "Size of v1(5): " << v1.size() << std::endl;
	print_vector(v1);
	std::cout << "Size of v2(5, \"toto\"): " << v2.size() << std::endl;
	print_vector(v2);
	std::cout << "Size of v3(v2.begin() + 1, v2.end() - 2): " << v3.size() << std::endl;
	print_vector(v3);
	std::cout << "Size of copy(v2): " << copy.size() << std::endl;
	print_vector(copy);
	std::cout << "Size of assignation(v1): " << assignation.size() << std::endl;
	print_vector(assignation);

	std::cout << std::endl;
}

void	vector_iterators(void)
{
	std::cout << "Test iterators and iterators comparisons" << std::endl << std::endl;
	NAMESPACE::vector<bool> v1(3, true);
	NAMESPACE::vector<bool> v2(3, true);
	NAMESPACE::vector<bool>::iterator it;

	std::cout << "Comparaison between identical vectors v(3, true) :" << std::endl;
	std::cout << "v1.begin() == v1.begin() = " << (v1.begin() == v1.begin()) << std::endl;
	std::cout << "v1.begin() == v2.begin() = " << (v1.begin() == v2.begin()) << std::endl;
	std::cout << "v1.begin() != v1.begin() = " << (v1.begin() != v1.begin()) << std::endl;
	std::cout  << "v1.begin() != v2.begin() = " << (v1.begin() != v2.begin()) << std::endl;

	std::cout << "Test *it, --it, it++...: " << std::endl;
	it = v2.begin();
	std::cout << "*it: " << *it << std::endl;
	++it;
	--it;
	std::cout <<"++it ; --it; it == v2.begin() ? " << (it == v2.begin()) << std::endl;

	it++;
	it--;
	std::cout << "it++ ; it--; it == v2.begin() ? " <<(it == v2.begin()) << std::endl;

	std::cout << std::endl;
	NAMESPACE::vector<int> test(1, 0);

	for (int i = 1; i < 7; ++i)
		test.push_back(i);
	print_vector(test);

	NAMESPACE::vector<int>::iterator it_test = test.begin();
	std::cout << "it + 3: " << *(it_test + 3) << std::endl;
	std::cout << "2 + it: " << *(2 + it_test) << std::endl;
	std::cout << "it: " << *(it_test) << std::endl;
	it_test++;
	std::cout << "it++ it-1: " << *(it_test -1) << std::endl;
	std::cout << "it - (it + 3): " << it_test - (it_test + 3) << std::endl;
	std::cout << "it - (it - 3): " << it_test - (it_test - 2) << std::endl;
	std::cout << "it > it++ = " << (it_test > it_test++) << std::endl;
	std::cout << "it <= it = " << (it_test <= it_test) << std::endl;
	std::cout << "it < it-- = " << (it_test < it_test--) << std::endl;
	std::cout << "it >= it = " << (it_test >= it_test) << std::endl;
	std::cout << "*(it -= 1): " << *(it_test -= 1) << std::endl;
	std::cout << "*(it += 2): " << *(it_test += 2) << std::endl;
	std::cout << "it[3]: " << it_test[3]  << std::endl;

	std::cout << std::endl << std::endl;
}

void	vector_capacity(void)
{
	NAMESPACE::vector<int> v1(3);

	std::cout << "Test size, max_size, resize, capacity, empty and reserve" << std::endl << std::endl;

	std::cout << "Max_size of v1(3): "<< v1.max_size() << std::endl;
	v1.resize(9, 5);
	std::cout << "Resize(9, 5); size(): "<< v1.size() << std::endl;
	print_vector(v1);
	v1.resize(4, 8);
	std::cout << "Resize(4, 8);  size(): "<< v1.size() << std::endl;
	print_vector(v1);

	v1.reserve(20);
	std::cout << "Reserve(20); capacity(): "<< v1.capacity() << std::endl;
	v1.reserve(10);
	std::cout << "Reserve(10); capacity(): "<< v1.capacity() << std::endl;
	std::cout << "Is empty? " << v1.empty() << std::endl;
	std::cout << "Try reserve more than max_size" << std::endl;
	try {
		v1.reserve(v1.max_size() + 1);
	}
	catch (std::exception & e)
	{
		std::cout << "exception catch" << std::endl;
	}

	std::cout << std::endl << std::endl;
}

void	vector_elements_access(void)
{
	std::cout << "Test [], at, front, back" << std::endl << std::endl;

	NAMESPACE::vector<char> v1(3,'a');
	v1.push_back('b');
	v1.push_back('c');
	print_vector(v1);
	std::cout << "v1[0]: " << v1[0] << std::endl;
	std::cout << "v1[3]: " << v1[3] << std::endl;
	std::cout << "v1.at(1): " << v1.at(1) << std::endl;
	std::cout << "v1.at(4)]: " << v1.at(4) << std::endl;

	std::cout << "Try v1.at(12)" << std::endl;
	try {
		v1.at(12);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught" << std::endl;
	}

	v1[0] = 'w';
	v1[4] = 'z';
	std::cout << "v1[0] = 'w' and v1[4] = 'z'" << std::endl;
	std::cout << "v1.front(): " << v1.front() << std::endl;
	std::cout << "v1.back(): " << v1.back() << std::endl;

	std::cout << std::endl << std::endl;
}

void	 vector_modifiers(void)
{
	std::cout << "Test assign, push_back, pop_back, insert, erase, swap and clear" << std::endl << std::endl;

	NAMESPACE::vector<int> v1;
	NAMESPACE::vector<int> v2;
	NAMESPACE::vector<std::string> v3(2, "YOLO");
	NAMESPACE::vector<std::string> v4(4, "wesh");

	v1.assign(7, 15);
	std::cout << "Assign(7, 15); size() : " << v1.size() << std::endl;
	print_vector(v1);

	v2.assign(v1.begin(), v1.begin() + 3);
	std::cout << "Assign(v1.begin(), v1.begin() + 3); size() : " << v2.size() << std::endl;
	print_vector(v2);

	v1.push_back(6);
	std::cout << "Push_back(6); back(): " << v1.back() << std::endl;
	v1.pop_back();
	std::cout << "Pop_back(); back(): " << v1.back() << std::endl;


	v3.insert(v3.begin() + 1, "Roger");
	std::cout << std::endl << "v3(2, \"YOLO\"); v3.insert(v3.begin() + 1, \"Roger\") " << std::endl;
	print_vector(v3);

	v3.insert(v3.begin() + 2, 3, "toto");
	std::cout << "v3.insert(v3.begin() + 2, 3, \"toto\")" << std::endl;
	print_vector(v3);

	v4.insert(v4.begin() + 2, v3.begin(), v3.begin() + 3);
	std::cout << std::endl << "v4(4, \"wesh\"); v4.insert(v4.begin() + 2, v3.begin(), v3.begin() + 3)" << std::endl;
	print_vector(v4);

	v4.erase(v4.begin() + 1);
	std::cout << "v4.erase(v4.begin() + 1)" << std::endl;
	print_vector(v4);

	v4.erase(v4.begin() + 1, v4.begin() + 4);
	std::cout << "v4.erase(v4.begin() + 1, v4.begin() + 4)" << std::endl;
	print_vector(v4);

	v3.swap(v4);
	std::cout << "v3.swap(v4)" << std::endl;
	std::cout << "v3 ";
	print_vector(v3);
	std::cout << "v4 ";
	print_vector(v4);

	swap(v3, v4);
	std::cout << "swap(v3, v4)" << std::endl;
	std::cout << "v3.swap(v4)" << std::endl;
	std::cout << "v3 ";
	print_vector(v3);
	std::cout << "v4 ";
	print_vector(v4);

	std::cout << std::endl << std::endl;
}

void	vector_allocator(void)
{

	NAMESPACE::vector<char> v1;
	char *c;

	std::cout << "Test get_allocator() " << std::endl;
	c = v1.get_allocator().allocate(5);
	std::cout << "v1.get_allocator().allocate(5) " << std::endl;
	for (int i = 0; i < 5; ++i)
		v1.get_allocator().construct(&c[i], i + 42);
	for (int i = 0; i < 5; ++i)
  		std::cout << "c[i]: " << c[i] << std::endl;
	for (int i = 0; i < 5; i++)
		v1.get_allocator().destroy(&c[i]);
	v1.get_allocator().deallocate(c,5);

	std::cout << std::endl << std::endl;
}

void	vector_relational_operators(void)
{
	std::cout << "Test relational operators" << std::endl;

	NAMESPACE::vector<int> t1(4, 5);
	NAMESPACE::vector<int> t2(2, 8);
	NAMESPACE::vector<int> t3(4, 5);
	NAMESPACE::vector<int> copy(t1);
	NAMESPACE::vector<int> copy_operator = t1;

	std::cout << "Vectors:\nt1(4, 5)\nt2(2, 8)\nt3(4, 5)\ncopy(t1)\ncopy_operartor = t1\n" << std::endl;

	std::cout << "t1 == t2 = " << (t1 == t2) << std::endl;
	std::cout << "t1 == t3 = " << (t1 == t3) << std::endl;
	std::cout << "t1 == copy = " << (t1 == copy) << std::endl;
	std::cout << "t1 == copy_operator = " << (t1 == copy_operator) << std::endl;
	std::cout << "t1 != t2 = " << (t1 != t2) << std::endl;
	std::cout << "t1 != t3 = " << (t1 != t3) << std::endl;
	std::cout << "t1 != copy = " << (t1 != copy) << std::endl;
	std::cout << "t1 != copy_operator = " << (t1 != copy_operator) << std::endl;
	std::cout << "t1 < t2 = " << (t1 < t2) << std::endl;
	std::cout << "t1 < t3 = " << (t1 < t3) << std::endl;
	std::cout << "t1 <= t2 = " << (t1 <= t2) << std::endl;
	std::cout << "t1 <= t3 = " << (t1 <= t3) << std::endl;
	std::cout << "t1 > t2 = " << (t1 > t2) << std::endl;
	std::cout << "t1 > t3 = " << (t1 > t3) << std::endl;
	std::cout << "t1 >= t2 = " << (t1 >= t2) << std::endl;
	std::cout << "t1 >= t3 = " << (t1 >= t3) << std::endl;

	std::cout << std::endl << std::endl;
}

void	test_vector(void)
{
	std::cout << "/////TEST VECTOR/////" << std::endl << std::endl;
	vector_constructors();
	vector_iterators();
	vector_capacity();
	vector_elements_access();
	vector_modifiers();
	vector_allocator();
	vector_relational_operators();
}

int main()
{
	std::cout << std::boolalpha;
	test_vector();

	return 1;
}

