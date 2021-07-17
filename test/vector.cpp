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

	std::cout << "	Comparaison between identical vectors v(3, true) :" << std::endl;
	std::cout << "v1.begin() == v1.begin() " << (v1.begin() == v1.begin()) << std::endl;
	std::cout << "v1.begin() == v2.begin() " << (v1.begin() == v2.begin()) << std::endl;
	std::cout << "v1.begin() != v1.begin() " << (v1.begin() != v1.begin()) << std::endl;
	std::cout << "v1.begin() != v2.begin() " << (v1.begin() != v2.begin()) << std::endl;

	std::cout << "Test *it, --it, it++...: " << std::endl;
	it = v2.begin();
	std::cout << *it << std::endl;
	++it;
	--it;
	std::cout << (it == v2.begin()) << std::endl;

	it++;
	it--;
	std::cout << (it == v2.begin()) << std::endl;

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
	std::cout << "it > it++: " << (it_test > it_test++) << std::endl;
	std::cout << "it <= it: " << (it_test <= it_test) << std::endl;
	std::cout << "it < it--: " << (it_test < it_test--) << std::endl;
	std::cout << "it >= it: " << (it_test >= it_test) << std::endl;
	std::cout << "*(it -= 1): " << *(it_test -= 1) << std::endl;
	std::cout << "*(it += 2): " << *(it_test += 2) << std::endl;
	std::cout << "it[3]: " << it_test[3]  << std::endl;
}

void	vector_capacity(void)
{
	NAMESPACE::vector<int> v1(3);

	std::cout << "Test size, max_size, resize, capacity, empty and reserve" << std::endl;

	std::cout << "Max_size of v1(3): "<< v1.max_size() << std::endl;
	v1.resize(9, 5);
	std::cout << "Resize(9, 5) >> size: "<< v1.size() << std::endl;
	print_vector(v1);
	v1.resize(4, 8);
	std::cout << "Resize(4, 8) >> size: "<< v1.size() << std::endl;
	print_vector(v1);

	v1.reserve(20);
	std::cout << "Reserve(20) >> capacity: "<< v1.capacity() << std::endl;
	v1.reserve(10);
	std::cout << "Reserve(10) >> capacity: "<< v1.capacity() << std::endl;
	std::cout << "Is empty? " << v1.empty() << std::endl;
	std::cout << "Try reserve more than max_size" << std::endl;
	try {
		v1.reserve(v1.max_size() + 1);
	}
	catch (std::exception & e)
	{
		std::cout << "exception catch" << std::endl;
	}
	std::cout << std::endl;
}

void	vector_elements_access(void)
{
	std::cout << "Test [], at, front, back" << std::endl;

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

ft::vector<int> myvector;
  int * p;
  unsigned int i;

  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);
 for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);


}

void	test_vector(void)
{
	std::cout << "/////TEST VECTOR/////" << std::endl << std::endl;
	vector_constructors();
	vector_iterators();
	vector_capacity();
	vector_elements_access();
}

int main()
{
	test_vector();

//	test_size_capacity();
//	std::cout << std::endl;
//
//	test_element_access();
//	std::cout << std::endl;
//
//	test_modifiers1();
//	std::cout << std::endl;
//
//	test_modifiers2();
//	std::cout << std::endl;
//
//	test_relational_operator();
//	std::cout << std::endl;
//
	return 1;
}

