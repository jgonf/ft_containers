/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:43:36 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/01 11:16:11 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

# include <iostream>
# include "ListIterator.hpp"
# include "reverse_iterator.hpp"
# include "vector.hpp"

namespace ft {


	template <typename T>
	struct node {
		public :
			node_list<T>	*next;
			node_list<T>	*prev;
	};

	template <typename T>
	struct node_list: public node<T> {
		public :
			T		data;
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
				typedef ListIterator<T>	iterator;
				typedef ConstListIterator<T>		const_iterator;
				typedef reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef reverse_iterator<iterator>	reverse_iterator;

				typedef	std::ptrdiff_t		difference_type;
				typedef	size_t			size_type;



				//constructors and destructor
				explicit list (const allocator_type& alloc = allocator_type()): _size(0), _alloc(alloc)
				{ init_list(); }

				explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(0), _alloc(alloc)
				{
					init_list();
					assign(n, val);
				}

				template <class InputIterator>
					list(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _size(0), _alloc(alloc)
				{
					init_list();
					assign(first, last);
				}

				list(pointer first, pointer last, const allocator_type& alloc = allocator_type()): _size(0), _alloc(alloc)
				{
					init_list();
					assign(first, last);
				}

				list (const list &x): _size(0), _alloc(x._alloc)
				{
					init_list();
					assign(x.begin(), x.end());
				}

				~list (void) {
					clear();
					delete _tail;
				}

				list	&operator=(const list &x)
				{
					clear();
					init_list();
					assign(x.begin(), x.end());
					return *this;
				}


//iterators
				iterator	begin(void) { return iterator(_tail->next); }

				const_iterator	begin(void) const
				{
					ConstListIterator<T> tmp(_tail->next);
					return tmp;
				}


				iterator	end(void) { return iterator(_tail); }

				const_iterator	end(void) const
				{
					ConstListIterator<T> tmp(_tail);
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
				reference front(void) { return _tail->next->data; }
				const_reference front(void) const { return _tail->next->data; }
				reference back(void) { return _tail->prev->data; }
				const_reference back(void) const { return _tail->prev->data; }


//modifiers
				template <class InputIterator>
					void assign(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
				{
					clear();
					while (first != last)
					{
						push_back(first.getPtr()->data);
						first++;
					}
				}

				void    assign(pointer first, pointer last)
				{
					clear();
					while(first != last)
					{
						push_back(*first);
						first++;
					}
				}

				void	assign(size_type n, const value_type &val)
				{
					clear();
					for (size_type i = 0; i < n; ++i)
						push_back(val);
				}

				void	push_front(const value_type &val)
				{
					node_type	*tmp = new node_type();
					node_type	*head = _tail->next;

					tmp->data = val;
					tmp->next = head;
					tmp->prev = _tail;
					head->prev = tmp;
					_tail->next = tmp;
					_size++;
				}

				void	pop_front(void)
				{
					node_type *save = _tail->next;

					_tail->next = save->next;
					_tail->next->prev = _tail;
					_size--;
					delete save;
				}

				void	push_back(const value_type& val)
				{
					node_type	*tmp = new node_type();

					tmp->data = val;
					tmp->next = _tail;
					tmp->prev = _tail->prev;
					_tail->prev->next = tmp;
					_tail->prev = tmp;
					_size++;
				}

				void	pop_back(void)
				{
					node_type *save = _tail->prev;

					_tail->prev = save->prev;
					_tail->prev->next = _tail;
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
						insert(end(), n - _size, val);

				}

				void clear()
				{
					node_type	*save;
					node_type	*to_del = _tail->next;

					while (_size)
					{
						save = to_del->next;
						delete to_del;
						to_del = save;
						_size--;
					}
					_tail->prev = _tail;
				}

//operations
				void splice(iterator position, list &x)
				{
					node_type	*end_insert = position.getPtr();
					node_type	*start_insert = end_insert->prev;
					node_type	*last = x.end().getPtr()->prev;
					node_type	*first = x.begin().getPtr();

					start_insert->next = first;
					first->prev = start_insert;
					end_insert->prev = last;
					last->next = end_insert;
					_size += x._size;
					x._tail->prev = x._tail;
					x._tail->next = x._tail;
					x._size = 0;
				}

				void splice(iterator position, list &x, iterator i)
				{
					node_type	*end_insert = position.getPtr();
					node_type	*start_insert = end_insert->prev;
					node_type	*to_insert = i.getPtr();

					to_insert->prev->next = to_insert->next;
					to_insert->next->prev = to_insert->prev;
					start_insert->next = to_insert;
					to_insert->prev = start_insert;
					end_insert->prev = to_insert;
					to_insert->next = end_insert;
					_size++;
					x._size--;
				}

				void splice(iterator position, list &x, iterator first, iterator last)
				{
					size_type	size = 0;
					node_type	*end_insert = position.getPtr();
					node_type	*start_insert = end_insert->prev;
					node_type	*first_ptr = first.getPtr();
					node_type	*last_ptr = (--last).getPtr();


					for (;first != last; ++first)
						size++;

					first_ptr->prev->next = last_ptr->next;
					last_ptr->next->prev = first_ptr->prev;
					start_insert->next = first_ptr;
					first_ptr->prev = start_insert;
					end_insert->prev = last_ptr;
					last_ptr->next = end_insert;
					_size += size;
					x._size -= size;
				}

				void remove(const value_type& val)
				{
					iterator	it = begin();

					while (it != end())
					{
						if (*it == val)
							it = erase(it);
						else
							++it;
					}
				}

				template <class Predicate>
					void remove_if(Predicate pred)
				{
					iterator	it = begin();

					while (it != end())
					{
						if (pred(*it))
							it = erase(it);
						else
							++it;
					}
				}

				void unique(void)
				{
					iterator	it = ++begin();
					iterator	cmp = begin();

					for (; it != end(); ++it)
					{
						if (*it == *cmp)
							erase(cmp++);
						else
							cmp++;
					}
				}

				void	merge(list& x)
				{
					iterator	it1 = begin();
					iterator	it2 = x.begin();

					while (it1 != end() && it2 != x.end())
					{
						if (*it1 > *it2)
						{
							splice(it1, x, it2);
							it1 = begin();
							it2 = x.begin();
						}
						++it1;
					}
					if (it2 != x.end())
						splice(it1, x);
				}

				template <class Compare>
					void merge (list& x, Compare comp)
				{
					iterator	it1 = begin();
					iterator	it2 = x.begin();

					while (it1 != end() && it2 != x.end())
					{
						if (comp(*it2, *it1))
						{
							splice(it1, x, it2);
							it1 = begin();
							it2 = x.begin();
						}
						++it1;
					}
					if (it2 != x.end())
						splice(it1, x);
				}


				void	sort(void)
				{
					iterator	it = begin();
					iterator	it2 = ++begin();

					while (it2 != end())
					{
						if (*it > *it2)
						{
							splice(it, *this, it2);
							it = begin();
							it2 = ++begin();
						}
						else
						{
							it++;
							it2++;
						}
					}
				}

				template <class Compare>
					void sort(Compare comp)
				{
					iterator	it = begin();
					iterator	it2 = ++begin();

					while (it2 != end())
					{
						if (comp(*it2, *it))
						{
							splice(it, *this, it2);
							it = begin();
							it2 = ++begin();
						}
						else
						{
							it++;
							it2++;
						}
					}
				}

				void reverse(void)
				{
					iterator	it = begin();

					while (it != end())
					{
						std::swap(it.getPtr()->prev, it.getPtr()->next);
						--it;
					}
					std::swap(_tail->next, _tail->prev);
				}

			private:
				node_type*	_tail;
				size_type	_size;
				allocator_type	_alloc;

				void	init_list(void)
				{
					_tail = new node_type;
					_tail->prev = _tail;
					_tail->next = _tail;
				}

	};

	template <class T, class Alloc>
		bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return std::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
		bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
		bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
			bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
		bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
			bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
		void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{
		return x.swap(y);
	}
}

#endif
