/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:12:36 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/07/18 11:19:45 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include <iostream>

namespace ft
{
	struct input_iterator_tag	{};
	struct OutputIteratorTag {};
	struct ForwardIteratorTag : public input_iterator_tag {};
	struct BidirectionalIteratorTag : public ForwardIteratorTag {};
	struct random_access_iterator_tag : public BidirectionalIteratorTag {};

	template < typename T, bool is_const>
		class RandomIterator;

	template <class Iterator>
		class reverse_iterator {

			public:
				typedef Iterator				iterator_type;
				typedef typename Iterator::iterator_category	iterator_category;
				typedef typename Iterator::value_type		value_type;
				typedef typename Iterator::difference_type	difference_type;
				typedef typename Iterator::pointer		pointer;
				typedef typename Iterator::reference		reference;

				reverse_iterator(void): _base(NULL) {};
				reverse_iterator(Iterator it): _base(it) {};
				reverse_iterator(reverse_iterator<iterator_type > & src): _base(src.base()) {};
				template <class T>
				reverse_iterator(reverse_iterator<T> const & src): _base(src.base()) {};
				virtual ~reverse_iterator(void) {};

				iterator_type	base() const { return _base; }
				reference	operator*(void) const
				{
					iterator_type cpy(_base);
					return *--(cpy);
				}

				reverse_iterator	operator+(difference_type n) const
				{
					reverse_iterator	tmp(*this);
					reverse_iterator	ret(tmp.base().getPtr() - n);
					return ret;
				}

				reverse_iterator&	operator++(void)
				{
					--_base;
					return *this;
				}

				reverse_iterator	operator++(int)
				{
					reverse_iterator	tmp = *this;
					++(*this);
					return tmp;
				}

				reverse_iterator&	operator+=(difference_type n)
				{
					_base -= n;
					return *this;
				}

				reverse_iterator	operator-(difference_type n) const
				{
					reverse_iterator	tmp(*this);
					reverse_iterator	ret(tmp.base().getPtr() + n);

					return ret;
				}

				difference_type operator-(reverse_iterator const& src) const
				{
					return src.base() - _base;
				}

				reverse_iterator&	operator--(void)
				{
					++_base;
					return *this;
				}

				reverse_iterator	operator--(int)
				{
					reverse_iterator	tmp = *this;
					--(*this);
					return tmp;
				}

				reverse_iterator&	operator-=(difference_type n)
				{
					_base += n;
					return *this;
				}

				pointer	operator->(void) const
				{
					return &(operator*());
				}

				reference	operator[](difference_type n) const
				{
					return base()[-n - 1];
				}

				template <typename T>
					bool operator==(reverse_iterator<T> const & src) const
				{
					return _base == src.base();
				}

				template <typename T>
					bool operator!=(reverse_iterator<T> const & src) const
				{
					return _base != src.base();
				}

				template <typename T>
					bool operator<(reverse_iterator<T> const & src) const
				{
					return _base > src.base();
				}

				template <typename T>
					bool operator<=(reverse_iterator<T> const & src) const
				{
					return _base >= src.base();
				}

				template <typename T>
					bool operator>(reverse_iterator<T> const & src) const
				{
					return _base < src.base();
				}

				template <typename T>
					bool operator>=(reverse_iterator<T> const & src) const
				{
					return _base <= src.base();
				}

			private:
				Iterator	_base;
		};
}

#endif
