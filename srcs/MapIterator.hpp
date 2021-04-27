/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:38:10 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/27 16:41:26 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

# include "map.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T>
		struct node_list;

	template <class T>
		class ConstMapIterator;

	template < typename T>
		class MapIterator
		{
			public:

				typedef T		value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef node_list<T>	*pointer;
				typedef T		&reference;
				static const bool	input_iter;
				typedef	ft::BidirectionalIteratorTag	iterator_category;

				MapIterator(void): _ptr(NULL) {}
				MapIterator(MapIterator const &src): _ptr(src._ptr) {};
				MapIterator(pointer ptr): _ptr(ptr) {};
				virtual ~MapIterator(void) {}

				pointer	getPtr(void) const { return _ptr; }

				MapIterator	&operator=(MapIterator const & src)
				{
					_ptr = src._ptr;
					return *this;
				}

				MapIterator	&operator++(void)
				{
					_ptr = _ptr->next;
					return *this;
				}

				MapIterator	&operator--(void)
				{
					_ptr = _ptr->prev;
					return *this;
				}

				MapIterator	operator++(int)
				{
					MapIterator<value_type> tmp = *this;
					_ptr = _ptr->next;
					return tmp;
				}

				MapIterator	operator--(int)
				{
					MapIterator<value_type> tmp = *this;
					_ptr = _ptr->prev;
					return tmp;
				}

				bool operator==(MapIterator const &cmp) const
				{
					return (_ptr == cmp._ptr);
				}

				bool operator==(ConstMapIterator<T> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				bool operator!=(MapIterator const &cmp) const
				{
					return !(*this == cmp);
				}

				bool operator!=(ConstMapIterator<T> const &cmp) const
				{
					return !(*this == cmp);
				}

				reference operator*(void) const { return _ptr->data; }
				T	*operator->(void) const { return _ptr->data; }

			protected:
				pointer	_ptr;
		};

	template < class T>
		const bool MapIterator<T>::input_iter = true;

	template <class T>
		class ConstMapIterator: public MapIterator<T>
	{
		public:
			typedef T		value_type;
			typedef std::ptrdiff_t 	difference_type;
			typedef node_list<T>	*pointer;
			typedef  T		&reference;
			static const bool	input_iter;
			typedef	ft::BidirectionalIteratorTag	iterator_category;
//			typedef	ft::random_access_iterator_tag	iterator_category;

			ConstMapIterator(void): _ptr(NULL) {}
			ConstMapIterator(MapIterator<T> const &src): _ptr(src.getPtr()) {};
//			ConstMapIterator(ConstMapIterator const &src): _ptr(src._ptr) {};
//			ConstMapIterator(pointer ptr): _ptr(ptr) {};
			ConstMapIterator(node_list<T> *src): _ptr(src) {};
			ConstMapIterator(node_list<T> src): _ptr(&src) {};
			virtual ~ConstMapIterator(void) {}

			pointer	getPtr(void) const { return _ptr; }

			ConstMapIterator	&operator=(ConstMapIterator const & src)
			{
				_ptr = src._ptr;
				return *this;
			}

			ConstMapIterator	&operator++(void)
			{
				_ptr = _ptr->next;
				return *this;
			}

			ConstMapIterator	&operator--(void)
			{
				_ptr = _ptr->prev;
				return *this;
			}

			ConstMapIterator	operator++(int)
			{
				ConstMapIterator<value_type> tmp = *this;
				_ptr = _ptr->next;
				return tmp;
			}

			ConstMapIterator	operator--(int)
			{
				ConstMapIterator<value_type> tmp = *this;
				_ptr = _ptr->prev;
				return tmp;
			}

			bool operator==(ConstMapIterator const &cmp) const
			{
				return (_ptr == cmp._ptr);
			}

			bool operator!=(ConstMapIterator const &cmp) const
			{
				return !(*this == cmp);
			}

			reference	operator*(void) const { return _ptr->data; }
			const T	*operator->(void) const { return _ptr->data; }

		private:
			pointer	_ptr;

	};

	template < class T>
		const bool ConstMapIterator<T>::input_iter = true;

}

#endif
