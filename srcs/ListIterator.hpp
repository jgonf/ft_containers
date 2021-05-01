/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:38:10 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/01 12:42:32 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

# include "list.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T>
		struct node_list;

	template <class T>
		class ConstListIterator;

	template < typename T>
		class ListIterator
		{
			public:

				typedef T		value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef node_list<T>	*pointer;
				typedef T		&reference;
				static const bool	input_iter;
				typedef	ft::BidirectionalIteratorTag	iterator_category;

				ListIterator(void): _ptr(NULL) {}
				ListIterator(ListIterator const &src): _ptr(src._ptr) {};
				ListIterator(pointer ptr): _ptr(ptr) {};
				virtual ~ListIterator(void) {}

				pointer	getPtr(void) const { return _ptr; }

				ListIterator	&operator=(ListIterator const & src)
				{
					_ptr = src._ptr;
					return *this;
				}

				ListIterator	&operator++(void)
				{
					_ptr = _ptr->next;
					return *this;
				}

				ListIterator	&operator--(void)
				{
					_ptr = _ptr->prev;
					return *this;
				}

				ListIterator	operator++(int)
				{
					ListIterator<value_type> tmp = *this;
					_ptr = _ptr->next;
					return tmp;
				}

				ListIterator	operator--(int)
				{
					ListIterator<value_type> tmp = *this;
					_ptr = _ptr->prev;
					return tmp;
				}

				bool operator==(ListIterator const &cmp) const
				{
					return (_ptr == cmp._ptr);
				}

				bool operator==(ConstListIterator<T> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				bool operator!=(ListIterator const &cmp) const
				{
					return !(*this == cmp);
				}

				bool operator!=(ConstListIterator<T> const &cmp) const
				{
					return !(*this == cmp);
				}

				reference operator*(void) const { return _ptr->data; }
				T	*operator->(void) const { return &(_ptr->data); }

			protected:
				pointer	_ptr;
		};

	template < class T>
		const bool ListIterator<T>::input_iter = true;

	template <class T>
		class ConstListIterator: public ListIterator<T>
	{
		public:
			typedef T		value_type;
			typedef std::ptrdiff_t 	difference_type;
			typedef node_list<T>	*pointer;
			typedef  T		&reference;
			static const bool	input_iter;
			typedef	ft::BidirectionalIteratorTag	iterator_category;
//			typedef	ft::random_access_iterator_tag	iterator_category;

			ConstListIterator(void): _ptr(NULL) {}
			ConstListIterator(ListIterator<T> const &src): _ptr(src.getPtr()) {};
//			ConstListIterator(ConstListIterator const &src): _ptr(src._ptr) {};
//			ConstListIterator(pointer ptr): _ptr(ptr) {};
			ConstListIterator(node_list<T> *src): _ptr(src) {};
			ConstListIterator(node_list<T> src): _ptr(&src) {};
			virtual ~ConstListIterator(void) {}

			pointer	getPtr(void) const { return _ptr; }

			ConstListIterator	&operator=(ConstListIterator const & src)
			{
				_ptr = src._ptr;
				return *this;
			}

			ConstListIterator	&operator++(void)
			{
				_ptr = _ptr->next;
				return *this;
			}

			ConstListIterator	&operator--(void)
			{
				_ptr = _ptr->prev;
				return *this;
			}

			ConstListIterator	operator++(int)
			{
				ConstListIterator<value_type> tmp = *this;
				_ptr = _ptr->next;
				return tmp;
			}

			ConstListIterator	operator--(int)
			{
				ConstListIterator<value_type> tmp = *this;
				_ptr = _ptr->prev;
				return tmp;
			}

			bool operator==(ConstListIterator const &cmp) const
			{
				return (_ptr == cmp._ptr);
			}

			bool operator!=(ConstListIterator const &cmp) const
			{
				return !(*this == cmp);
			}

			reference	operator*(void) const { return _ptr->data; }
			const T	*operator->(void) const { return _ptr->data; }

		private:
			pointer	_ptr;

	};

	template < class T>
		const bool ConstListIterator<T>::input_iter = true;

}

#endif
