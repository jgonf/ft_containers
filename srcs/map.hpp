/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:37:58 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/02 22:20:02 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

namespace ft {

	struct node_tree {
		public :
			map::value_type	data;
			node_tree	*prev;
			node_tree	*left;
			node_tree	*right;
			int		height;
	};

	template < typename Key, typename T, typename Compare=less<Key>, typename Alloc=std::allocator<pair<const Key, T> > >
		class map {

			public:

				typedef Key					key_type;
				typedef T					mapped_type;
				typedef pair<const key_type, mapped_type>	value_type;
				typedef Compare					key_compare;
				typedef Alloc					allocator_type;
				typedef value_type&				reference;
				typedef value_type*				pointer;
				typedef const value_type*			const_pointer;
				typedef MapIterator<value_type>			iterator;
				typedef ConstMapIterator<value_type>		const_iterator;
				typedef reverse_iterator<iterator>		reverse_iterator;
				typedef std::ptrdiff_t				difference_type;
				typedef	size_t					size_type;

				//constructor destructor
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _cmp(comp), _alloc(alloc)
				{
					_init_tree();
				}

			private:
				node_list*	_tail;
				key_compare	_cmp;
				allocator_type	_alloc;

				void	_init_tree(void)
				{
					_tail = new * node_tree;
					_tail->prev = NULL;
					_tail->left = NULL;
					_tail->right = NULL;
					_tail->height = NULL;
				}
		}
}

#endif
