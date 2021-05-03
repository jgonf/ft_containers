/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:38:10 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/03 09:40:43 by jgonfroy         ###   ########.fr       */
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

	template <class T>
		class ConstTreeIterator;

	template < typename T>
		class TreeIterator
		{
			public:

				typedef T		value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef node_tree<T>	*pointer;
				typedef T		&reference;
				static const bool	input_iter;
				typedef	ft::BidirectionalIteratorTag	iterator_category;

				TreeIterator(void): _ptr(NULL) {}
				TreeIterator(TreeIterator const &src): _ptr(src._ptr) {};
				TreeIterator(pointer ptr): _ptr(ptr) {};
				virtual ~TreeIterator(void) {}

				pointer	getPtr(void) const { return _ptr; }

				TreeIterator	&operator=(TreeIterator const & src)
				{
					_ptr = src._ptr;
					return *this;
				}

				TreeIterator	&operator++(void)
				{
					_ptr = _ptr->next;
					return *this;
				}

				TreeIterator	&operator--(void)
				{
					_ptr = _ptr->prev;
					return *this;
				}

				TreeIterator	operator++(int)
				{
					TreeIterator<value_type> tmp = *this;
					_ptr = _ptr->next;
					return tmp;
				}

				TreeIterator	operator--(int)
				{
					TreeIterator<value_type> tmp = *this;
					_ptr = _ptr->prev;
					return tmp;
				}

				bool operator==(TreeIterator const &cmp) const
				{
					return (_ptr == cmp._ptr);
				}

				bool operator==(ConstTreeIterator<T> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				bool operator!=(TreeIterator const &cmp) const
				{
					return !(*this == cmp);
				}

				bool operator!=(ConstTreeIterator<T> const &cmp) const
				{
					return !(*this == cmp);
				}

				reference operator*(void) const { return _ptr->data; }
				T	*operator->(void) const { return _ptr->data; }

			protected:
				pointer	_ptr;
		};

	template < class T>
		const bool TreeIterator<T>::input_iter = true;

	template <class T>
		class ConstTreeIterator: public TreeIterator<T>
	{
		public:
			typedef T		value_type;
			typedef std::ptrdiff_t 	difference_type;
			typedef node_tree<T>	*pointer;
			typedef  T		&reference;
			static const bool	input_iter;
			typedef	ft::BidirectionalIteratorTag	iterator_category;
//			typedef	ft::random_access_iterator_tag	iterator_category;

			ConstTreeIterator(void): _ptr(NULL) {}
			ConstTreeIterator(TreeIterator<T> const &src): _ptr(src.getPtr()) {};
//			ConstTreeIterator(ConstTreeIterator const &src): _ptr(src._ptr) {};
//			ConstTreeIterator(pointer ptr): _ptr(ptr) {};
			ConstTreeIterator(node_tree<T> *src): _ptr(src) {};
			ConstTreeIterator(node_tree<T> src): _ptr(&src) {};
			virtual ~ConstTreeIterator(void) {}

			pointer	getPtr(void) const { return _ptr; }

			ConstTreeIterator	&operator=(ConstTreeIterator const & src)
			{
				_ptr = src._ptr;
				return *this;
			}

			ConstTreeIterator	&operator++(void)
			{
				_ptr = _ptr->next;
				return *this;
			}

			ConstTreeIterator	&operator--(void)
			{
				_ptr = _ptr->prev;
				return *this;
			}

			ConstTreeIterator	operator++(int)
			{
				ConstTreeIterator<value_type> tmp = *this;
				_ptr = _ptr->next;
				return tmp;
			}

			ConstTreeIterator	operator--(int)
			{
				ConstTreeIterator<value_type> tmp = *this;
				_ptr = _ptr->prev;
				return tmp;
			}

			bool operator==(ConstTreeIterator const &cmp) const
			{
				return (_ptr == cmp._ptr);
			}

			bool operator!=(ConstTreeIterator const &cmp) const
			{
				return !(*this == cmp);
			}

			reference	operator*(void) const { return _ptr->data; }
			const T	*operator->(void) const { return _ptr->data; }

		private:
			pointer	_ptr;

	};

	template < class T>
		const bool ConstTreeIterator<T>::input_iter = true;

}

#endif
