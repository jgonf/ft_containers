/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:12:36 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/08 23:02:16 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include <iostream>

namespace ft
{
	struct InputIteratorTag	{};
	struct OutputIteratorTag {};
	struct ForwardIteratorTag : public InputIteratorTag {};
	struct BidirectionalIteratorTag : public ForwardIteratorTag {};
	struct random_access_iterator_tag : public BidirectionalIteratorTag {};

	template < typename T>
		class RandomIterator;

	template < typename T>
		class ConstRandomIterator;

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
				reverse_iterator(RandomIterator<value_type> it): _base(it) {};
				reverse_iterator(reverse_iterator<RandomIterator<value_type> > const & src): _base(src.base()) {};
				virtual ~reverse_iterator(void) {};

				iterator_type	base() const { return _base; }

				reference	operator*(void) const
				{
//					iterator_type	tmp(_base);
//					return *--tmp;
					value_type	*ptr = _base.getPtr();
					RandomIterator<value_type> it(ptr);
					return *--it;
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

//					iterator_type	tmp(_base);
//					return tmp + n;
				}

				difference_type operator-(reverse_iterator const& src)
				{
//					return _base - src.base();
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

				bool operator==(reverse_iterator const & src) const
				{
					return _base == src.base();
				}
				
				bool operator!=(reverse_iterator const & src) const
				{
					return _base != src.base();
				}
			
				bool operator<(reverse_iterator const & src) const
				{
					return _base > src.base();
				}
				
				bool operator<=(reverse_iterator const & src) const
				{
					return _base >= src.base();
				}

				bool operator>(reverse_iterator const & src) const
				{
					return _base < src.base();
				}
				
				bool operator>=(reverse_iterator const & src) const
				{
					return _base <= src.base();
				}

			private:
				Iterator	_base;
		};
/*
		template <class Iterator>
		bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return lhs.base() == rhs.base();
		}
*/		
		template <class value_type>
		bool operator==(const reverse_iterator<RandomIterator<value_type> >& lhs, const reverse_iterator<ConstRandomIterator<value_type> >& rhs)
		{
			return lhs.base() == rhs.base();
		}

		template <class value_type>
//		bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		bool operator!=(const reverse_iterator<RandomIterator<value_type> >& lhs, const reverse_iterator<ConstRandomIterator<value_type> >& rhs)
		{
			return lhs.base() != rhs.base();
		}
		
		template <class value_type>
		bool operator<(const reverse_iterator<RandomIterator<value_type> >& lhs, const reverse_iterator<ConstRandomIterator<value_type> >& rhs)
		{
			return lhs.base() > rhs.base();
		}

		template <class value_type>
		bool operator<=(const reverse_iterator<RandomIterator<value_type> >& lhs, const reverse_iterator<ConstRandomIterator<value_type> >& rhs)
		{
			return lhs.base() >= rhs.base();
		}
		
		template <class value_type>
		bool operator>(const reverse_iterator<RandomIterator<value_type> >& lhs, const reverse_iterator<ConstRandomIterator<value_type> >& rhs)
		{
			return lhs.base() < rhs.base();
		}

		template <class value_type>
		bool operator>=(const reverse_iterator<RandomIterator<value_type> >& lhs, const reverse_iterator<ConstRandomIterator<value_type> >& rhs)
		{
			return lhs.base() <= rhs.base();
		}

		template <class value_type>
		typename reverse_iterator<RandomIterator<value_type> >::difference_type operator-(const reverse_iterator<RandomIterator<value_type> >& lhs, const reverse_iterator<ConstRandomIterator<value_type> >& rhs)
		{
			return lhs.base() - rhs.base();
		}

/*		
		template <class Iterator>
		bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return lhs.base() > rhs.base();
		}

		template <class Iterator>
		bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return lhs.base() >= rhs.base();
		}

		template <class Iterator>
		bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return lhs.base() < rhs.base();
		}

		template <class Iterator>
		bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return lhs.base() <= rhs.base();
		}
*/
	        template <class Iterator>
                reverse_iterator<Iterator> operator+(int n, reverse_iterator<Iterator> &src) { return src + n; }

		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return lhs.base() - rhs.base();
		}

}

#endif
