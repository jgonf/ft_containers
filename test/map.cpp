/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:18:09 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/07/18 14:30:52 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../srcs/testeur.hpp"

template<typename key, typename value>
void	print_map(NAMESPACE::map<key, value> test)
{
	typename NAMESPACE::map<key, value>::iterator it;

	std::cout << "Elements: " << std::endl;
	for (it = test.begin(); it != test.end(); ++it)
		std::cout << "key: " << (*it).first << " -> value: " << (*it).second <<  std::endl;
	std::cout << std::endl;
}

void	map_constructors(void)
{
	std::cout << "Test constructors and copy" << std::endl;
	NAMESPACE::map<bool, char> empty;
	NAMESPACE::map<int, std::string > v1;

	v1[0] = "zero";
	v1[1] = "un";
	v1[2] = "deux";
	v1[3] = "trois";
	v1[4] = "quatre";

	NAMESPACE::map<int, std::string> v2(++v1.begin(), --v1.end());
	NAMESPACE::map<int, std::string> copy(v2);
	NAMESPACE::map<int, std::string> assignation;
	assignation = v1;

	std::cout << "Size of empty() : " << empty.size() << std::endl;
	std::cout << "V1 : size(): " << v1.size() << std::endl;
	print_map(v1);
	std::cout << "Size of v2(++v1.begin() , --v1.end()): " << v2.size() << std::endl;
	print_map(v2);
	std::cout << "Size of copy(v2): " << copy.size() << std::endl;
	print_map(copy);
	std::cout << "Size of assignation(v1): " << assignation.size() << std::endl;
	print_map(assignation);

	std::cout << std::endl << std::endl;
}
void	map_iterators(void)
{
	std::cout << "Test iterators" << std::endl;
	NAMESPACE::map<int, std::string> m1;
	NAMESPACE::map<int, std::string>::iterator it;
	NAMESPACE::map<int, std::string>::reverse_iterator rit;
	const NAMESPACE::map<int, std::string> const_m1;

	std::cout << "Empty map; map.begin() == map.end() ? " << (m1.begin() == m1.end()) << std::endl;
	std::cout << "Const empty map; const.begin() == const.end() ? " << (const_m1.begin() == const_m1.end()) << std::endl;

	m1[12] = "douze";
	m1[8] = "huit";
	m1[24] = "vingt quatre";
	m1[3] = "trois";
	std::cout << std::endl <<  "m1 : ";
	print_map(m1);
	std::cout << "Reverse iterator/rbegin()/rend():" << std::endl;
	for (rit = m1.rbegin(); rit != m1.rend(); ++rit)
		std::cout << rit->first << " -> " << rit->second << std::endl;

	std::cout << std::endl << std::endl;
}

void	map_capacity_elements_access(void)
{
	std::cout << "Test capacity : empty(), size(), max_size() and element access[]" << std::endl;

	NAMESPACE::map<int, std::string> m1;
	std::cout << "m1.empty()(): " << m1.empty() << std::endl;
	std::cout << "m1.size(): " << m1.size() << std::endl;
	std::cout << "m1.max_size(): " << m1.max_size() << std::endl;

	m1[3] = "trefle";
	std::cout << "m1[3] = \"trefle\"; m1[3]: " << m1[3] << std::endl;
	std::cout << "m1[0]: " << m1[0] << std::endl;
	std::cout << "m1.size(): " << m1.size() << std::endl;

	std::cout << std::endl << std::endl;
}

void	map_modifiers(void)
{
	std::cout << "Test modifiers : insert(), erase(), swap() and clear()" << std::endl;

	NAMESPACE::map<int, int> m1;
	NAMESPACE::map<int, int> cpy;
	NAMESPACE::map<int, int>::iterator it, ite;

	m1.insert(NAMESPACE::make_pair(10, 10));
	m1.insert(NAMESPACE::make_pair(15, 15));
	m1.insert(NAMESPACE::make_pair(16, 16));
	m1.insert(NAMESPACE::make_pair(12, 12));
	m1.insert(NAMESPACE::make_pair(2, 2));
	m1.insert(NAMESPACE::make_pair(5, 5));
	m1.insert(NAMESPACE::make_pair(3, 3));
	m1.insert(NAMESPACE::make_pair(1, 1));
	m1.insert(NAMESPACE::make_pair(17, 17));
	m1.insert(NAMESPACE::make_pair(17, 17));

	std::cout << "m1.insert() : " << std::endl;
	print_map(m1);

	it = ++m1.begin();
	cpy.insert(it, m1.end());
	m1.insert(NAMESPACE::make_pair(2, 2));
	it = ++cpy.begin();
	std::cout << "cpy.insert(++m1.begin(), m1.end()) : ";
	print_map(cpy);
	std::cout << "it " << it->first << std::endl;
	std::cout << "find: " << cpy.count(3) << std::endl;
	std::cout << "cpy.erase(++cpy.begin())" << std::endl;
	print_map(cpy);

	it= ++(++m1.begin());
	++it;
	it= --(--m1.end());
	m1.erase(it);
	std::cout << std::endl << "m1 after erase: " << std::endl;
	print_map(m1);

	std::cout << std::endl << "Ret erase key existante " << cpy.erase(1) << std::endl;
	std::cout << "Ret erase key inexistante " << cpy.erase(23) << std::endl;

	cpy.erase(cpy.begin(), cpy.end());
	std::cout << "cpy.erase(cpy.begin(), cpy.end()): " << std::endl;
	print_map(cpy);

	m1.swap(cpy);
	std::cout << std::endl << "m1.swap(cpy) " << std::endl;
	print_map(m1);
	std::cout << std::endl << "cpy after swap : " << std::endl;
	print_map(cpy);

	std::cout << std::endl << std::endl;
}

void	map_observers(void)
{
	std::cout << "Test observers : key_comp() and value_comp() " << std::endl;
	NAMESPACE::map<char, int> m1;
	NAMESPACE::map<char,int>::key_compare cmp = m1.key_comp();

	m1['a']=100;
	m1['b']=200;
	m1['c']=300;

	std::cout <<"cmp(m1['a'], m1['b']) = " << cmp(m1['a'], m1['b']) << std::endl;
	std::cout <<"cmp(m1['b'], m1['a']) = " << cmp(m1['b'], m1['a']) << std::endl;
	std::cout <<"cmp(m1['c'], m1['c']) = " << cmp(m1['c'], m1['c']) << std::endl;

	std::cout << "m1.value_comp()(*m1.begin(), *m1.end()) = " << m1.value_comp()(*m1.begin(), *m1.end()) << std::endl;
	std::cout << "m1.value_comp()(*m1.end(), *m1.begin()) = " << m1.value_comp()(*m1.end(), *m1.begin()) << std::endl;

	std::cout << std::endl << std::endl;
}

void	map_operations(void)
{
	std::cout <<"Test operations : find(), count(), lower_bound(), upper_bound() and equal_range()" << std::endl;
	NAMESPACE::map<int, int> m1;
	NAMESPACE::map<int, int>::iterator it, ite;

	m1.insert(NAMESPACE::make_pair(10, 10));
	m1.insert(NAMESPACE::make_pair(15, 15));
	m1.insert(NAMESPACE::make_pair(16, 16));
	m1.insert(NAMESPACE::make_pair(12, 12));
	m1.insert(NAMESPACE::make_pair(2, 2));
	m1.insert(NAMESPACE::make_pair(5, 5));
	m1.insert(NAMESPACE::make_pair(3, 3));
	m1.insert(NAMESPACE::make_pair(1, 1));
	m1.insert(NAMESPACE::make_pair(17, 17));

	print_map(m1);

	if (m1.find(-5) == m1.end())
		std::cout << "m1.find(-5) : Cette key n'existe pas" << std::endl;

	it = m1.find(15);
	std::cout << "m1.find(15) : " << (*it).first << std::endl;
	std::cout << "m1.count(-5) : " << m1.count(15) << std::endl;
	std::cout << "m1.count(15) : " << m1.count(15) << std::endl;

	ite = m1.lower_bound(11);
	std::cout << "lower_bound(11) : " << (*ite).first << std::endl;
	ite = m1.lower_bound(12);
	std::cout << "lower_bound(12) : " << (*ite).first << std::endl;
	ite = m1.upper_bound(11);
	std::cout << "upper_bound(11) : " << (*ite).first << std::endl;
	ite = m1.upper_bound(12);
	std::cout << "upper_bound(12) : " << (*ite).first << std::endl;

	NAMESPACE::pair<NAMESPACE::map<int,int>::iterator,NAMESPACE::map<int,int>::iterator> ret;
	std::cout << "equal range(16) : ";
	ret = m1.equal_range(16);
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;
	std::cout << ret.second->first << " => " << ret.second->second << std::endl;
}

void	map_allocator(void)
{

	NAMESPACE::map<char, int> v1;
	NAMESPACE::pair<const char, int> *c;

	std::cout << "Test get_allocator() " << std::endl;
	c = v1.get_allocator().allocate(5);
	std::cout << "v1.get_allocator().allocate(5) " << std::endl;
	for (int i = 0; i < 5; ++i)
		v1.get_allocator().construct(&c[i], NAMESPACE::make_pair(i + 42, i));
	for (int i = 0; i < 5; ++i)
  		std::cout << c[i].first << " -> " << c[i].second << std::endl;
	for (int i = 0; i < 5; i++)
		v1.get_allocator().destroy(&c[i]);
	v1.get_allocator().deallocate(c,5);

	std::cout << std::endl << std::endl;
}

void	map_relational_operators(void)
{
	std::cout << "Test relational operators" << std::endl;

	NAMESPACE::map<int, std::string> m1;
	NAMESPACE::map<int, std::string> m2;
	NAMESPACE::map<int, std::string> copy(m1);

	m1[12] = "XII";
	m1[8] = "VIII";
	m1[24] = "XXIV";
	m1[4] = "IV";
	m1[115] = "CXV";

	m2[1] = "one";
	m2[3] = "three";
	m2[24] = "twenty four";
	m2[5] = "five";
	m2[10] = "ten";


	std::cout << "m1 : ";
	print_map(m1);
	std::cout << "m2 : ";
	print_map(m2);

	std::cout << "m1 == m2 = " << (m1 == m2) << std::endl;
	std::cout << "m1 == copy = " << (m1 == copy) << std::endl;
	std::cout << "m1 != m2 = " << (m1 != m2) << std::endl;
	std::cout << "m1 != copy = " << (m1 != copy) << std::endl;
	std::cout << "m1 < m2 = " << (m1 < m2) << std::endl;
	std::cout << "m1 <= m2 = " << (m1 <= m2) << std::endl;
	std::cout << "m1 > m2 = " << (m1 > m2) << std::endl;
	std::cout << "m1 >= m2 = " << (m1 >= m2) << std::endl;

	std::cout << std::endl << std::endl;
}

