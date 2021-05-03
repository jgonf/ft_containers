/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:37:58 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/03 23:13:07 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include "reverse_iterator.hpp"
# include "TreeIterator.hpp"

namespace ft {

	template <typename T>
	struct less {

			bool operator()	(const T &x, const T &y) const { return (x < y); }
		};

	template <typename T, typename U>
	class pair {

		public:
			const T	first;
			U		second;

		pair(const T& key = T(), const U& value = U()): first(key), second(value) {}
		~pair(void) {}
	};

	template< class T1, class T2 >
	std::pair<T1,T2> make_pair( T1 t, T2 u) { return pair<T1, T2>(t, u); }

	template <typename T>
	struct node_tree {
		public :
			T		data;
			node_tree	*parent;
			node_tree	*left;
			node_tree	*right;
			bool		is_black;
	};

	template < typename Key, typename T, typename Compare=less<Key>, typename Alloc=std::allocator<pair<const Key, T> > >
		class map {

			public:

				typedef Key										key_type;
				typedef T										mapped_type;
				typedef pair<const key_type, mapped_type>	value_type;
				typedef Compare									key_compare;
//				typedef Alloc									allocator_type;
				typedef	typename Alloc::template rebind<node_tree<value_type> >::other	allocator_type;
				typedef value_type&						reference;
				typedef value_type*						pointer;
				typedef const value_type*				const_pointer;
				typedef node_tree<value_type>			node_type;
				typedef TreeIterator<value_type>		iterator;
				typedef ConstTreeIterator<value_type>	const_iterator;
				typedef reverse_iterator<iterator>		reverse_iterator;
				typedef std::ptrdiff_t					difference_type;
				typedef	size_t							size_type;

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
					(void)x;
//					clear();
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
					return iterator(_get_first());
				}

				const_iterator begin(void) const
				{
					if (!_size)
						return const_iterator(_tail);
					return const_iterator(_get_first());
				}

				iterator end(void)
				{
					return iterator(_tail);
				}

				const_iterator end(void) const
				{
					return const_iterator(_tail);
				}

//capacity

				bool	empty(void)	const
				{
					if (_size == 0)
						return true;
					return false;
				}

				size_type	size(void) const { return _size; }

				size_type	max_size(void) const
				{
//					std::allocator<ft::node_tree<T> > alloc;
					return _alloc.max_size();
				}


//element access
				mapped_type& operator[] (const key_type& k)
				{
					return  (*((this->insert(make_pair(k,mapped_type()))).first)).second;
				}

				pair<iterator,bool> insert (const value_type& val)
				{
					node_type	*new_node = new node_type;

					new_node->data = val;
					new_node->is_black = false;
					new_node = _insert_node(new_node);
					_balance_tree(new_node);
				}

			private:
				key_compare	_cmp;
				allocator_type	_alloc;
				node_type*	_tail;
				size_type	_size;

				void	_init_tree(void)
				{
					_tail = new node_type;
					_tail->parent = NULL;
					_tail->left = NULL;
					_tail->right = NULL;
					_tail->is_black = false;
				}


				node_type	*_get_first(void) const
				{
					node_type	*tmp = _tail->right;
					while (tmp)
						tmp = tmp->left;
					return tmp->parent;
				}

				node_type * _insert_node(node_type* root, node_type* new_node)
				{
					if (!root)
					{
						new_node->prev = root->prev;
						root = new_node;
						_size++;
						return root;
    					}

    					if (less(new_node->data->first, root->data->first))
        					root->left = _insert_node(root->left, new_node);
    					else
        					root->right = _insert_node(root->right, new_node);
					return root;
				}
		};
}

#endif
