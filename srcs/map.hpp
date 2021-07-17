/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:37:58 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/06/09 15:39:25 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include <string>
# include "vector.hpp"
# include "reverse_iterator.hpp"
# include "TreeIterator.hpp"
# include "tools.hpp"

namespace ft {

	template <typename T>
		struct less {

			bool operator()	(const T &x, const T &y) const { return (x < y); }
		};

	template <typename T, typename U>
		class pair {

			public:
				T	first;
				U	second;

				pair(void): first(), second() {}
				template <class V, class W>
					pair (const pair<V,W> & src): first(src.first), second(src.second) {}
				pair(T key, U value): first(key), second(value) {}
				~pair(void) {}

				pair& operator=(const pair& src)
				{
					first = src.first;
					second = src.second;
					return *this;
				}
		};

	template< class T1, class T2 >
		const ft::pair<T1,T2> make_pair( T1 t, T2 u)
		{
			const pair<T1, T2> ret(t, u);
			return ret;
		}

	template <class T1, class T2>
		bool operator== (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			return (lhs.first == rhs.first && lhs.second == rhs.second);
		}

	template <class T1, class T2>
		bool operator< (const pair<T1,T2> & lhs, const pair<T1,T2> & rhs)
		{
			if (lhs.first < rhs.first)
				return true;
			if (lhs.first == rhs.first && lhs.second < rhs.second)
				return true;
			return false;
		}


	template <typename T>
		struct node_tree {
			public :
				T			data;
				node_tree	*parent;
				node_tree	*left;
				node_tree	*right;
				bool		is_tail;
//				typedef typename T::first	first;

		};

	template < typename Key, typename T, typename Compare=less<Key>, typename Alloc=std::allocator<pair<const Key, T> > >
		class map {

			public:

				typedef Key										key_type;
				typedef T										mapped_type;
				typedef pair<key_type, mapped_type>				value_type;
				typedef Compare									key_compare;
				//				typedef Alloc									allocator_type;
				typedef	typename Alloc::template rebind<node_tree<value_type> >::other	allocator_type;
				typedef value_type&						reference;
				typedef value_type*						pointer;
				typedef const value_type*				const_pointer;
				typedef node_tree<value_type>			node_type;
				typedef TreeIterator<value_type, false>		iterator;
				typedef TreeIterator<value_type, true>	const_iterator;
				typedef reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef reverse_iterator<iterator>		reverse_iterator;
				typedef std::ptrdiff_t					difference_type;
				typedef	size_t							size_type;

				class value_compare
				{
					public:
						value_compare(const key_compare& compare) : _comp(compare) {}
						bool operator() (const value_type& a, const value_type& b) const { return _comp(a.first, b.first); }
					private:
						key_compare _comp;
				};

				//constructor destructor
				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _cmp(comp), _alloc(alloc), _size(0)
			{
				_init_tree();
			}

				template <class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _cmp(comp), _alloc(alloc), _size(0)
				{
					_init_tree();
					insert(first, last);
				}

				map (const map& x)
				{
					_init_tree();
					_cmp = x._cmp;
					_alloc = x._alloc;
					insert(x.begin(), x.end());
				}

				map& operator=(const map& x)
				{
					(void)x;
					clear();
					insert(x.begin(), x.end());
					return *this;
				}

				~ map(void)
				{
					clear();
					delete _root;
				}

				//iterators
				iterator begin(void)
				{
					return iterator(_get_first());
				}

				const_iterator begin(void) const
				{
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

				reverse_iterator	rbegin(void)
				{ return reverse_iterator(end()); }

				const_reverse_iterator	rbegin(void) const
				{ return reverse_iterator(end()); }

				reverse_iterator	rend(void)
				{ return reverse_iterator(begin()); }

				const_reverse_iterator	rend(void) const
				{ return reverse_iterator(begin()); }

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
					return  (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
				}

				//modifiers
				pair<iterator,bool> insert (const value_type& val)
				{
					iterator	ret;
					if ((ret = find(val.first)) != end())
						return ft::make_pair<iterator, bool>(ret, false);

					if (!_size)
					{
						_root = new node_type;
//						_tail = new node_type;
						_root->data = val;
						_root->parent = NULL;
						_root->left = NULL;
						_root->right = _tail;
						_root->is_tail = false;
						_tail->parent = _root;
						_tail->right = _root;
						_tail->left = NULL;
						_tail->is_tail = true;
						_size++;
						return ft::make_pair<iterator, bool>(begin(), true);
					}
					node_type	*new_node = new node_type;
					new_node->data = val;
					new_node->parent = NULL;
					new_node->right = NULL;
					new_node->left = NULL;
					new_node->is_tail = false;
					new_node = _insert_node(_root, new_node);
					_size++;
					//					_balance_tree(new_node);
					_update_tail(new_node);
					return ft::make_pair<iterator, bool>(iterator(new_node), true);
				}

				iterator insert(iterator position, const value_type& val)
				{
					(void)position;
					return insert(val).first;

				}

				template <class InputIterator>
					void insert(InputIterator first, typename ft::enable_if<!ft::is_same<InputIterator, int>::value, InputIterator>::type last)
					{
						while (first != last)
						{
							insert(*first);
							++first;
						}
					}

				void erase(iterator position)
				{
					node_type	*node = position.getPtr();
					node_type	*tmp;

					if (_size == 0)
						return ;
					if (_size == 1)
					{
						_root->parent = NULL;
						_root->left = NULL;
						_root->right = NULL;
						delete _tail;
						_tail = _root;
						_size--;
						return ;
					}
					if (!(node->left) && !((_check_node_right(node))))
					{
						if (key_compare()(node->parent->data.first, node->data.first))
							node->parent->right = NULL;
						else
							node->parent->left = NULL;
						delete node;
						node = NULL;
						_size--;
						_update_max();
						return ;
					}
					if (!(node->left))
						tmp = node->right;
					else if (!(_check_node_right(node)))
						tmp = node->left;
					else
					{
						tmp = (++position).getPtr();
						node->data = tmp->data;
						if (node->right == tmp)
							node->right = tmp->right;
						else
						{
							if (key_compare()(tmp->data.first, node->data.first))
							{
								std::cout << "impossible ?" << std::endl;
//								node->left = NULL;
								tmp->parent->right = NULL;
							}
							else
								tmp->parent->left = NULL;
						}
						delete tmp;
						_size--;
						return ;
					}
					node->data = tmp->data;
					node->right = tmp->right;
					node->left = tmp->left;
					if (node->left)
						node->left->parent = node;
					if (node->right)
						node->right->parent = node;
					delete tmp;
					tmp = NULL;
					_size--;
				}

				size_type	erase(const	key_type& k)
				{
					iterator	it = find(k);

					if (it == end())
						return 0;
					erase(it);
					return 1;
				}

				void	erase(iterator first, iterator last)
				{
					ft::vector<Key> key;
					typename ft::vector<Key>::iterator it;

					for (; first != last; ++first)
						key.push_back((*first).first);
					for (it = key.begin(); it != key.end(); ++it)
						erase(*it);
				}

				void	swap(map& x)
				{
					node_type	*ptr;
					size_t		tmp;

					tmp = _size;
					_size = x._size;
					x._size = tmp;

					ptr = _root;
					_root = x._root;
					x._root = ptr;

					ptr = _tail;
					_tail = x._tail;
					x._tail = ptr;
				}

				void	clear(void)
				{
					erase(begin(), end());
				}

//observers
				key_compare	key_comp(void)	const
				{
					return _cmp;
				}

				value_compare	value_comp(void)	const
				{
					return value_compare(_cmp);
				}

//operations
				iterator	find(const key_type& k)
				{
					if (!_size)
						return end();
					return _find_key(_root, k);
				}

				const_iterator	find(const key_type& k) const
				{
					if (!_size)
						return end();
					return _find_key(_root, k);
				}

				size_type	count(const key_type& k) const
				{
					if (find(k) == end())
							return 0;
					return 1;
				}

				iterator lower_bound (const key_type& k)
				{
					iterator	it;

					if ((it = find(k)) != end())
						return it;
					for (it = begin(); it != end(); ++it)
						if (key_comp()(k, (*it).first))
							break ;
					return it;
				}

				const_iterator lower_bound (const key_type& k) const
				{
					iterator	it;

					if ((it = find(k)) != end())
						return it;
					for (it = begin(); it != end(); ++it)
						if (key_comp()(k, (*it).first))
							break ;
					return it;
				}

				iterator upper_bound (const key_type& k)
				{
					iterator	it;

					if ((it = find(k)) != end())
						return ++it;
					for (it = begin(); it != end(); ++it)
						if (key_comp()(k, (*it).first))
							break ;
					return it;
				}

				const_iterator upper_bound (const key_type& k) const
				{
					iterator	it;

					if ((it = find(k)) != end())
						return ++it;
					for (it = begin(); it != end(); ++it)
						if (key_comp()(k, (*it).first))
							break ;
					return it;
				}

				pair<const_iterator,const_iterator> equal_range (const key_type& k) const
				{
					ft::pair<const_iterator, const_iterator> ret(lower_bound(k), upper_bound(k));
					return ret;
				}

				pair<iterator,iterator> equal_range (const key_type& k)
				{
					ft::pair<iterator, iterator> ret(lower_bound(k), upper_bound(k));
					return ret;
				}

			private:
				key_compare	_cmp;
				allocator_type	_alloc;
				node_type*	_root;
				node_type*	_tail;
				size_type	_size;

				void	_init_tree(void)
				{
					_root = new node_type;
					_root->parent = NULL;
					_root->left = NULL;
					_root->right = NULL;
					_root->is_tail = true;
					_tail = _root;
				}

				template <typename U>
				void	_swap(U x, U y)
				{
					U	tmp;

					tmp = x;
					x = y;
					y = tmp;
				}

				node_type	*_get_first(void) const
				{
					node_type	*tmp = _root;
					while (tmp->left)
						tmp = tmp->left;
					return tmp;
				}

				void	_update_max(void)
				{
					node_type	*tmp = _root;

					if (!_size)
					{
						_tail = _root;
						return;
					}
					while (_check_node_right(tmp))
						tmp = tmp->right;
					_tail->parent = tmp;
					tmp->right = _tail;
				}

				node_type * _insert_node(node_type* root, node_type* new_node)
				{
					if (key_compare()(new_node->data.first, root->data.first))
					{
						if (root->left == NULL)
						{
							root->left = new_node;
							new_node->parent = root;
							return root->left;
						}
						else
							_insert_node(root->left, new_node);
					}
					else
					{
						if (!(_check_node_right(root)))
						{
							new_node->parent = root;
							root->right = new_node;
							return root->right;
						}
						else
							_insert_node(root->right, new_node);
					}
					return new_node;
				}

				void	_update_tail(node_type* new_node)
				{
					if (key_compare()(new_node->data.first, _tail->right->data.first))
						_tail->right = new_node;
					if ((key_compare()(_tail->parent->data.first, new_node->data.first)))
					{
						_tail->parent = new_node;
						new_node->right = _tail;
					}
				}

				iterator	_find_key(node_type *root, key_type key)
				{
					iterator	ret = end();

					if (root == NULL || root == _tail)
						return ret;
					if (root->data.first == key)
						return iterator(root);
					if (key_compare()(key, root->data.first))
						ret = _find_key(root->left, key);
					if (!(key_compare()(key, root->data.first)))
						ret = _find_key(root->right, key);
					return ret;
				}

				const_iterator	_find_key(node_type *root, key_type key) const
				{
					const_iterator	ret = end();

					if (root == NULL || root == _tail)
						return ret;
					if (root->data.first == key)
						return iterator(root);
					if (key_compare()(key, root->data.first))
						ret = _find_key(root->left, key);
					if (!(key_compare()(key, root->data.first)))
						ret = _find_key(root->right, key);
					return ret;
				}


				bool	_check_node_right(node_type *node) const
				{
					if (!node->right || node->right == _tail)
						return false;
					return true;
				}

				bool	_is_equal(key_type k1, key_type k2)
				{
					if (!(key_comp()(k1, k2)) && !(key_comp()(k2, k1)))
						return true;
					return false;
				}
		};

	template <class Key, class T, class Compare, class Alloc>
		bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(lhs == rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(rhs < lhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return rhs < lhs;
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(lhs < rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
		{
			x.swap(y);
		}
}

#endif
