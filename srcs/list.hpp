/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:43:36 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/10 19:17:15 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

# include <iostream>

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

//				typedef BidirectionalIterator<value_type>	iterator;
//				typedef BidirectionalIterator<const value_type>		const_iterator;
//				typedef reverse_iterator<const_iterator>	const_reverse_iterator;
//				typedef reverse_iterator<iterator>	reverse_iterator;

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
//					assign(n, val);
				}

				template <class InputIterator>
					list(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
				{
					list();
					assign(first, last);
				}

				list (const list &x)
				{
					list();
					assgin(x.begin(), x.end());
				}

				~list (void) { clear() }

				list	&operator=(const list &x)
				{
					clear();
					assign(x.begin(), x.end());
					return *this;
				}


			private:
				node_type	_head;
				node_type	_tail;
				size_type	_size;
	};
}

#endif