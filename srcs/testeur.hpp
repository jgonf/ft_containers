/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:11:50 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/07/18 15:39:03 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTEUR_HPP
#define TESTEUR_HPP

# include <vector>
# include <map>
# include <stack>
# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"

/*
 * vector.cpp
 */

void	vector_constructors(void);
void	vector_iterators(void);
void	vector_capacity(void);
void	vector_elements_access(void);
void	vector_modifiers(void);
void	vector_allocator(void);
void	vector_relational_operators(void);

/*
 * map.cpp
 */

void	map_constructors(void);
void	map_iterators(void);
void	map_capacity_elements_access(void);
void	map_modifiers(void);
void	map_observers(void);
void	map_operations(void);
void	map_allocator(void);
void	map_relational_operators(void);

/*
 * stack.cpp
 */

void	stack_constructors(void);
void	stack_member_functions(void);


#endif
