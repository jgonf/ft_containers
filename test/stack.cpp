/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:57:19 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/07/18 15:34:29 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "../srcs/testeur.hpp"

void	stack_constructors(void)
{
	std::cout << "Tests constructors: " << std::endl;

	NAMESPACE::vector<int>	v1(3, 5);
	std::list<char>	l1(8, 'a');
	NAMESPACE::stack<int> empty;
	NAMESPACE::stack<bool, NAMESPACE::vector<bool> > empty_vector;
	NAMESPACE::stack<std::string, std::list<std::string> > empty_list;
	NAMESPACE::stack<int, NAMESPACE::vector<int> > from_vector(v1);
	NAMESPACE::stack<char, std::list<char> > from_list(l1);

	std::cout << "Size empty(): " << empty.size() << std::endl;
	std::cout << "Size empty_vector(): " << empty_vector.size() << std::endl;
	std::cout << "Size empty_list(): " << empty_list.size() << std::endl;
	std::cout << "Size from_vector(3, 5): " << from_vector.size() << std::endl;
	std::cout << "Size from_list(8, 'a'): " << from_list.size() << std::endl;

	std::cout << std::endl << std::endl;
}

void	stack_member_functions(void)
{
	std::cout << "Tests : empty(), size(), top(), push() and pop(): " << std::endl;

	std::cout << std::endl << "With default container: " << std::endl;
	NAMESPACE::stack<int> s1;
	std::cout << "s1.empty() ? " << s1.empty() << std::endl;
	s1.push(3);
	std::cout << "s1.push(3); s1.empty() ? " << s1.empty() << std::endl;
	std::cout << "s1.size(): " << s1.size() << std::endl;
	std::cout << "s1.top(): " << s1.top() << std::endl;
	s1.pop();
	std::cout << "s1.pop(); s1.empty() ? " << s1.empty() << std::endl;

	std::cout << std::endl << "Same with std::list: " << std::endl;
	NAMESPACE::stack<int, std::list<int> > l1;
	std::cout << "l1.empty() ? " << l1.empty() << std::endl;
	l1.push(3);
	std::cout << "l1.push(3); l1.empty() ? " << l1.empty() << std::endl;
	std::cout << "l1.size(): " << l1.size() << std::endl;
	std::cout << "l1.top(): " << l1.top() << std::endl;
	l1.pop();
	std::cout << "l1.pop(); l1.empty() ? " << l1.empty() << std::endl;
}
