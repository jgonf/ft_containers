/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <jgonfroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:06:36 by user42            #+#    #+#             */
/*   Updated: 2021/07/18 14:32:51 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../srcs/testeur.hpp"

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

int main()
{
	std::cout << std::boolalpha;
	test_vector();
	test_map();
	return 1;
}

