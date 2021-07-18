/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:38:10 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/07/18 16:36:54 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

# include "map.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T>
		struct node_tree;

	template < typename T, bool const_it>
		class TreeIterator
		{
			public:

				typedef typename ft::is_const<const_it, const T, T>::type	value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef value_type	*pointer;
				typedef node_tree<T>	*node_ptr;
				typedef value_type		&reference;
				static const bool	input_iter;
				typedef	ft::BidirectionalIteratorTag	iterator_category;

				TreeIterator(void): _ptr(NULL) {}
				template <bool is_const>
					TreeIterator (const TreeIterator<T, is_const> & src, typename ft::enable_if<!is_const, T>::type* = 0) { _ptr = src.getPtr(); }
				TreeIterator(node_ptr _ptr): _ptr(_ptr) {};
				virtual ~TreeIterator(void) {}

				node_ptr	getPtr(void) const { return _ptr; }

				template <bool is_const>
				TreeIterator	&operator=(TreeIterator<T, is_const> const & src)
				{
					_ptr = src.getPtr();
					return *this;
				}

				TreeIterator	&operator++(void)
				{
					_setNextNode();
					return *this;
				}

				TreeIterator	&operator--(void)
				{
					_setPrevNode();
					return *this;
				}

				TreeIterator	operator++(int)
				{
					TreeIterator<T, const_it> tmp = *this;
					++(*this);
					return tmp;
				}

				TreeIterator	operator--(int)
				{
					TreeIterator<T, const_it> tmp = *this;
					--(*this);
					return tmp;
				}

				template <bool is_const>
					bool operator==(TreeIterator<T, is_const> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				template <bool is_const>
					bool operator!=(TreeIterator<T, is_const> const &cmp) const
				{
					return !(*this == cmp);
				}

				reference	operator*(void) const { return (_ptr->data); }
				value_type	 	*operator->(void) const { return &(operator*()); }

			protected:
				node_ptr	_ptr;

				void	_setNextNode(void)
				{
					if (_ptr->right && !(_ptr->is_tail))
					{
						_ptr = _ptr->right;
						while (_ptr->left)
							_ptr = _ptr->left;
					}
					else
					{
						node_ptr	tmp = _ptr;
						_ptr = _ptr->parent;
						while (_ptr->left != tmp)
						{

							tmp = _ptr;
							_ptr = _ptr->parent;
						}
					}
				}

				void	_setPrevNode(void)
				{
					if (_ptr->left)
					{
						_ptr = _ptr->left;
						while (_ptr->right)
							_ptr = _ptr->right;
					}
					else
						_ptr = _ptr->parent;
				}
		};

	template < class T, bool const_it>
		const bool TreeIterator<T, const_it>::input_iter = true;

}

#endif
