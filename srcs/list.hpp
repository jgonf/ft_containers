/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:43:36 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/17 17:26:19 by jgonfroy         ###   ########.fr       */
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

				typedef node_list<value_type>	node_type;
				typedef BidirectionalIterator<T>	iterator;
				typedef ConstBidirectionalIterator<T>		const_iterator;
				typedef reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef reverse_iterator<iterator>	reverse_iterator;

				typedef	std::ptrdiff_t		difference_type;
				typedef	size_t			size_type;



				//constructors and destructor
				explicit list (void): _size(0)
				{
					_head.next = &_tail;
					_tail.prev = &_head;
				}

				explicit list (size_type n, const value_type& val = value_type()): _size(0)
				{
					_head.next = &_tail;
					_tail.prev = &_head;
					assign(n, val);
				}

				template <class InputIterator>
					list(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
				{
					_head.next = &_tail;
					_tail.prev = &_head;
					assign(first, last);
				}

				list (const list &x)
				{
					_head.next = &_tail;
					_tail.prev = &_head;
					assign(x.begin(), x.end());
				}

				~list (void) {
//					clear()
				}

				list	&operator=(const list &x)
				{
//					clear();
					_head.next = &_tail;
					_tail.prev = &_head;
					assign(x.begin(), x.end());
					return *this;
				}


//iterators
				iterator	begin(void) { return iterator(_head.next); }

				const_iterator	begin(void) const
				{
					ConstBidirectionalIterator<T> tmp(_head.next);
					return tmp;
				}


				iterator	end(void) { return iterator(_tail.prev->next); }

				const_iterator	end(void) const
				{
					ConstBidirectionalIterator<T> tmp(_tail.prev->next);
					return tmp;
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
					std::allocator<ft::node_list<T> > alloc;
					return alloc.max_size();
				}

//element access
				reference front(void) { return _head.next->data; }
				const_reference front(void) const { return _head.next->data; }
				reference back(void) { return _tail.prev->data; }
				const_reference back(void) const { return _tail.prev->data; }


//modifiers
				template <class InputIterator>
					void assign(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
				{
	//				clear();
					while (first != last)
					{
						push_back(first.getPtr()->data);
//						node_type	*tmp = new node_type();
//						tmp->data = first.getPtr()->data;
//						_tail.prev->next = tmp;
//						_tail.prev = tmp;
						first++;
					}
				}

				void	assign(size_type n, const value_type &val)
				{
				//	clear();
					for (size_type i = 0; i < n; ++i)
						push_back(val);
//						node_type	*tmp = new node_type();
//						tmp->data = val;
//						tmp->next = &_tail;
//						_tail.prev->next = tmp;
//						_tail.prev = tmp;
				}

				void	push_front(const value_type &val)
				{
					node_type	*tmp = new node_type();

					tmp->data = val;
					tmp->next = _head.next;
					tmp->prev = &_head;
					_head.next->prev = tmp;
					_head.next = tmp;
					_size++;
				}

				void	pop_front(void)
				{
					node_type *save = _head.next;

					_head.next = save->next;
					_head.next->prev = &_head;
					_size--;
					delete save;
				}

				void	push_back(const value_type& val)
				{
					node_type	*tmp = new node_type();

					tmp->data = val;
					tmp->next = &_tail;
					tmp->prev = _tail.prev;
					_tail.prev->next = tmp;
					_tail.prev = tmp;
					_size++;
				}

				void	pop_back(void)
				{
					node_type *save = _tail.prev;

					_tail.prev = save->prev;
					_tail.prev->next = &_tail;
					_size--;
					delete save;
				}

				iterator insert(iterator position, const value_type &val)
				{
					node_type	*tmp = new node_type();

					tmp->data = val;
					tmp->next = position.getPtr();
					tmp->prev = position.getPtr()->prev;
					position.getPtr()->prev = tmp;
					tmp->prev->next = tmp;
					_size++;

					return (iterator(tmp));
				}

				void insert(iterator position, size_type n, const value_type& val)
				{
					size_type	i;

					for (i = 0; i < n; ++i)
						position = insert(position, val);
				}

				template <class InputIterator>
					void insert (iterator position, InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
				{
					position--;
					for (; first != last; ++first)
						position = insert(++position, *first);
				}

				iterator erase(iterator position)
				{
					node_type	*ptr = position.getPtr();
					iterator	ret(ptr->next);

					ptr->next->prev = ptr->prev;
					ptr->prev->next = ptr->next;
					_size--;
					delete ptr;

					return ret;
				}

				iterator erase(iterator first, iterator last)
				{
					for (; first != last; ++first)
						erase(first);
					return last;
				}

				void swap(list &x)
				{
					std::swap(_head, x._head);
					std::swap(_tail, x._tail);
					std::swap(_size, x._size);
				}

				void resize (size_type n, value_type val = value_type())
				{
					iterator	it = begin();

					if (n < _size)
					{
						for (size_type i = 0; i < n; ++i)
							++it;
						erase(it, end());
					}
					if (n > _size)
						insert(it, n - _size, val);
				}

			private:
				node_type	_head;
				node_type	_tail;
				size_type	_size;

	};
}

#endif
