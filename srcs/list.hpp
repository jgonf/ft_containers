/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:43:36 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/11 13:48:32 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

# include <iostream>
# include "BidirectionalIterator.hpp"
# include "reverse_iterator.hpp"
# include "vector.hpp"

namespace ft {

	template <typename T>

	struct node_list {
		public :
			T		data;
			node_list	*next;
			node_list	*prev;
	};

	template < typename T, typename Alloc=std::allocator<T> >
		class list {

			public:

				//variables

				typedef T			value_type;
				typedef Alloc			allocator_type;
				typedef value_type		&reference;
				typedef value_type const	&const_reference;
				typedef value_type		*pointer;
				typedef value_type const	*const_pointer;

				typedef BidirectionalIterator<value_type>	iterator;
				typedef BidirectionalIterator<const value_type>		const_iterator;
				typedef reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef reverse_iterator<iterator>	reverse_iterator;

				typedef	std::ptrdiff_t		difference_type;
				typedef	size_t			size_type;

				typedef node_list<value_type>	node_type;


				//constructors and destructor
				explicit list (void): _size(0)
				{
					_head.next = &_tail;
					_tail.prev = &_head;
				}

				explicit list (size_type n, const value_type& val = value_type())
				{
					list();
					(void)n;
					(void)val;
//					assign(n, val);
				}

				template <class InputIterator>
					list(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
				{
					list();
					(void)first;
					(void)last;
//					assign(first, last);
				}

				list (const list &x)
				{
					list();
					(void)x;
//					assign(x.begin(), x.end());
				}

				~list (void) {
//					clear()
				}

				list	&operator=(const list &x)
				{
					(void)x;
//					clear();
//					assign(x.begin(), x.end());
					return *this;
				}


//iterators
				iterator	begin(void) { return iterator(_head->next); }
				const_iterator	begin(void) const { return iterator(_head->next); }

				iterator	end(void) { return iterator(_tail); }
				const_iterator	end(void) const { return iterator(_tail); }

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
			private:
				node_type	_head;
				node_type	_tail;
				size_type	_size;
	};
}

#endif
