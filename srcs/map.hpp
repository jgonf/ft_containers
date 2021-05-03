/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:37:58 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/03 11:21:43 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include "reverse_iterator.hpp"
# include "TreeIterator.hpp"

namespace ft {

	template <typename T>
	struct node_tree {
		public :
			T		data;
			node_tree	*prev;
			node_tree	*left;
			node_tree	*right;
			bool		color;
	};

	template < typename Key, typename T, typename Compare=std::less<Key>, typename Alloc=std::allocator<std::pair<const Key, T> > >
		class map {

			public:

				typedef Key					key_type;
				typedef T					mapped_type;
				typedef std::pair<const key_type, mapped_type>	value_type;
				typedef Compare					key_compare;
				typedef Alloc					allocator_type;
				typedef value_type&				reference;
				typedef value_type*				pointer;
				typedef const value_type*			const_pointer;
				typedef node_tree<value_type>			node_type;
				typedef TreeIterator<value_type>		iterator;
				typedef ConstTreeIterator<value_type>		const_iterator;
				typedef reverse_iterator<iterator>		reverse_iterator;
				typedef std::ptrdiff_t				difference_type;
				typedef	size_t					size_type;

				//constructor destructor
				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _cmp(comp), _alloc(alloc), _size(0)
				{
					_init_tree();
				}

				template <class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _cmp(comp), _alloc(alloc), _size(0)
				{
					_init_tree();
//					insert(first, last);
					(void)first;
					(void)last;
				}

				map (const map& x)
				{
					_init_tree();
					_cmp = x._cmp;
					_alloc = x._alloc;
//					insert(x.begin(), x.end());
				}

				map& operator=(const map& x)
				{
					clear();	
//					insert(x.begin(), x.end());
					return *this;
				}

				~ map(void)
				{
//					clear();
					delete _tail;
				}

//iterators
				iterator begin(void)
				{
					if (!_size)
						return iterator(_tail);
					return (iterator(_sort());
				}


			private:
				key_compare	_cmp;
				allocator_type	_alloc;
				node_type*	_tail;
				size_type	_size;

				void	_init_tree(void)
				{
					_tail = new node_type;
					_tail->prev = NULL;
					_tail->left = NULL;
					_tail->right = NULL;
					_tail->color = false;
				}
		};
}

#endif
