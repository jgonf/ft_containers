/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jgonfroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:06:36 by user42            #+#    #+#             */
/*   Updated: 2021/07/18 16:05:21 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/testeur.hpp"
#include <time.h>
#include <string.h>

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

void	test_map(void)
{
	std::cout << "/////TEST MAP/////" << std::endl << std::endl;
	map_constructors();
	map_iterators();
	map_capacity_elements_access();
	map_modifiers();
	map_observers();
	map_operations();
	map_allocator();
	map_relational_operators();
}

void	test_stack(void)
{
	std::cout << "/////TEST STACK/////" << std::endl << std::endl;
	stack_constructors();
	stack_member_functions();
}

int	find(char **args, std::string cont)
{
	int i = 0;

	while (args[i] != NULL)
	{
		if (cont.compare(args[i]) == 0)
			return 1;
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{
	clock_t begin = clock();

	std::cout << std::boolalpha;
	if (ac == 1 || find(av, "vector"))
		test_vector();
	if (ac == 1 || find(av, "map"))
		test_map();
	if (ac == 1 || find(av, "stack"))
		test_stack();

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	std::cout << "\n\nEXCECUTION TIME: " <<  time_spent << std::endl;
	return 1;
}

