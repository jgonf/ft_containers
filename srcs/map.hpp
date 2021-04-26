/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:37:58 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/26 14:52:49 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

namespace ft {

	struct node {
		public :
			map::key_type	key;
			map::value_type	value;

			node *left;
			node *right;
	};

	template < typename Key, typename T, typename Compare=less<Key>, typename Alloc=std::allocator<pair<const Key, T> > >
		class map {

			public:

				typedef Key									key_type;
				typedef T									mapped_type;
				typedef pair<const key_type, mapped_type>	value_type;
				typedef Compare								key_compare;
				typedef Alloc								allocator_type;
				typedef value_type&							reference;
				typedef value_type*							pointer;
				typedef const value_type*					const_pointer;
				typedef MapIterator<value_type>				iterator;
				typedef ConstMapIterator<value_type>		const_iterator;
				typedef reverse_iterator<iterator>			reverse_iterator;
				typedef std::ptrdiff_t						difference_type;
				typedef	size_t								size_type;


		}

}

#endif
