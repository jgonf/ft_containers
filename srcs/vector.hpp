/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:59:21 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/04 14:03:16 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <iostream>
# include <limits>
# include <sstream>
# include "reverse_iterator.hpp"
# include "RandomIterator.hpp"

namespace ft
{
	template<bool, class T>
		struct enable_if {};
	template<class T>
		struct enable_if<true, T> { typedef T type; };

	template < typename T, typename Alloc=std::allocator<T> >
		class vector {

			public:

				//variables

				typedef T			value_type;
				typedef Alloc			allocator_type;
				typedef value_type		&reference;
				typedef value_type const	&const_reference;
				typedef value_type		*pointer;
				typedef value_type const	*const_pointer;

				typedef RandomIterator<value_type>	iterator;
				typedef ConstRandomIterator<value_type>		const_iterator;
				typedef reverse_iterator<const_iterator>	const_reverse_iterator;
				typedef reverse_iterator<iterator>	reverse_iterator;

				//				typedef const reverse_iterator	const_reverse_iterator;
				typedef	std::ptrdiff_t	difference_type;
				typedef	size_t		size_type;


				//constructors and destructors

				explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _alloc(alloc)
				{
					_cont = _alloc.allocate(0);
				}

				explicit vector(size_t n, value_type val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _alloc(alloc)
				{
					_cont = _alloc.allocate(n);
					for (size_t i = 0; i < n; i++)
						_alloc.construct(&_cont[i],val);

				}

				template <class InputIterator>
					vector(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
					{
						size_type	size = 0;

						for (iterator it = first; it != last; ++it)
							size++;
						_cont = _alloc.allocate(size);
						_capacity = size;
						for (size_t i  = 0 ; i < size; ++i)
							_alloc.construct(&_cont[i], *first++);
						_size = size;
					}

				vector(vector const & x): _cont(NULL), _size(0), _capacity(0)
			{
				size_type src_size = x.size();

				_cont = _alloc.allocate(src_size);
				_capacity = src_size;
				for (size_t i  = 0 ; i < src_size; ++i)
					_alloc.construct(&_cont[i], x[i]);
				_size = src_size;

			}

				virtual ~vector(void)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_cont[i]);
					_alloc.deallocate(_cont, _capacity);
				}

				vector	& operator=(vector const & src)
				{
					size_type src_size = src.size();

					clear();
					if (_capacity < src_size)
						reserve(src_size);
					for (size_t i  = 0 ; i < src_size; ++i)
						_alloc.construct(&_cont[i], src[i]);
					_size = src_size;
					return *this;
				}

				//fonctions iterators
				iterator	begin(void) { return iterator(_cont); }

				const_iterator 	begin(void) const { return const_iterator(_cont); }

				iterator	end(void)
				{
					return iterator(_cont + _size);
				}

				const_iterator	end(void) const
				{
					return const_iterator(_cont + _size);
				}

				reverse_iterator	rbegin(void)
				{
					return reverse_iterator(end());
				}

				const_reverse_iterator	rbegin(void) const
				{
					return const_reverse_iterator(end());
				}

				reverse_iterator	rend(void)
				{
					return reverse_iterator(begin());
				}

				const_reverse_iterator	rend(void) const
				{
					return const_reverse_iterator(begin());
				}


				//capacity
				size_t	size(void) const { return _size; }

				size_t	max_size(void) const { return _alloc.max_size(); }

				void	resize(size_type n, value_type val = value_type())
				{
					iterator        start(begin());
					iterator        ending(begin() + n);

					if (n < _size)
					{
						clear();
						assign(start, ending);
					}
					else
					{
						if (_size == 0 || _size * 2 < n)
							reserve(n);
						else
							reserve(_size * 2);
						for (; _size < n; ++_size)
							_alloc.construct(&_cont[_size], val);

					}
					//						insert(end(), n, val);
					_size = n;
				}

				size_t	capacity(void)	const { return _capacity; }

				bool	empty(void)	const
				{
					if (_size == 0)
						return true;
					return false;
				}

				void	reserve(size_type n)
				{
					if (n <= _capacity)
						return ;
					if (n > this->max_size())
						throw std::length_error("vector::reserve");
					T *tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(&tmp[i], _cont[i]);
						_alloc.destroy(&_cont[i]);
					}
					_alloc.deallocate(_cont, _capacity);
					_cont = tmp;
					_capacity = n;
				}


				//elements access
				reference	operator[](size_type n)
				{
					return _cont[n];
				}

				const_reference	operator[](size_type n) const
				{
					return _cont[n];
				}

				reference	at(size_type n)
				{
					std::ostringstream error;
					error << "vector::_M_range_check: __n (which is " << n;
					error << ") >= this->size() (which is " << this->_size << ")";
					if (n >= _size)
					{
						throw std::out_of_range(error.str());
					}
					return _cont[n];
				}

				const_reference	at(size_type n) const
				{
					std::ostringstream error;
					error << "vector::_M_range_check: __n (which is " << n;
					error << ") >= this->size() (which is " << this->_size << ")";
					if (n >= _size)
					{
						throw std::out_of_range(error.str());
					}
					return _cont[n];
				}

				reference	front(void) { return _cont[0]; }
				const_reference	front(void) const { return _cont[0]; }
				reference	back(void) { return _cont[_size - 1]; }
				const_reference	back(void) const { return _cont[_size - 1]; }


				//modifiers

				template <class InputIterator>
					void assign(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)

					{
						size_t size = 0;

						for (iterator it(first); it != last; ++it)
							size++;
						clear();
						if (_capacity < size)
							reserve(size);
						insert(begin(), first, last);
					}

				void	assign(size_type n, const value_type& val)
				{
					clear();
					if (_capacity < n)
						reserve(n);
					insert(begin(), n, val);

				}

				void    assign(pointer first, pointer last)
				{
					assign(iterator(first), iterator(last));
				}

				void	push_back(const value_type& val)
				{

					size_t	new_capa = _capacity;
					if (new_capa == 0)
						new_capa = 1;
					while (_size + 1 > new_capa)
						new_capa = new_capa * 2;

					if (_size + 1 > _capacity)
						reserve(new_capa);
					_alloc.construct(&_cont[_size], val);
					_size++;
				}

				void	pop_back(void)
				{
					resize(_size - 1);
				}

				iterator	insert(iterator position, const value_type& val)
				{
					size_t  save = _size + 1;
					size_t  len = 0;
					iterator        it;

					for (it = position; it != end(); ++it)
						len++;

					if (_capacity < _size + 1)
						reserve(_size * 2);
					while (len)
					{
						push_back(*(end() - 1));
						if (_size < 2)
						{
							_size = 0;
							break;
						}
						_size -= 2;
						len--;
					}
					push_back(val);
					it = iterator(&_cont[_size - 1]);
					_size = save;
					return it;
				}

				void	insert(iterator position, size_type n, const value_type& val)
				{
					int	index = 0;

					for (iterator it = begin(); it != position; ++it)
						index++;
					reserve(_size + n);
					position = begin() + index;
					for (size_type i = 0; i < n; ++i)
						position = insert(position, val) + 1;
				}

				template <class InputIterator>
					void insert (iterator position, InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
					{
						int	len = 0;
						int	index = 0;

						for (iterator it = begin(); it != position; ++it)
							index++;
						for (iterator it = first; it != last; ++it)
							len++;
						if (_size == 0 || _size * 2 < _size + len)
							reserve(_size + len);
						else
							reserve(_size * 2);
						position = begin() + index;

						while (first != last)
						{
							position = insert(position, *first) + 1;
							++first;
						}
					}

				void    insert(iterator position, pointer first, pointer last)
				{
					insert(position, iterator(first), iterator(last));
				}


				iterator	erase(iterator position)
				{
					iterator        ret;

					ret = position;
					while (position + 1 != end())
					{
						_alloc.destroy(position.getPtr());
						_alloc.construct(position.getPtr(), *(position + 1));
						position++;
					}
					_alloc.destroy(position.getPtr());
					_size--;
					return ret;
				}

				iterator	erase(iterator first, iterator last)
				{
					iterator	ret = first;

					while (first != last)
					{
						erase(first);
						last--;
					}
					return ret;
				}

				void	swap(vector &x)
				{
					std::swap(_cont, x._cont);
					std::swap(_size, x._size);
					std::swap(_capacity, x._capacity);
				}

				void	clear()
				{
					for (size_t i = 0; i < _size; i++)
						_alloc.destroy(&_cont[i]);
					_size = 0;
				}

			protected:
				value_type		*_cont;
				size_type		_size;
				size_type		_capacity;
				allocator_type	_alloc;
		};

	template <class T>
		bool operator==(const vector<T>& lhs, const vector<T>& rhs)
		{
			if (lhs.size() != rhs.size())
				return false;
			return std::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class T>
		bool operator!=(const vector<T>& lhs, const vector<T>& rhs)
		{
			return !(lhs == rhs);
		}

	template <class T>
		bool operator<(const vector<T>& lhs, const vector<T>& rhs)
		{
			return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

	template <class T>
		bool operator<=(const vector<T>& lhs, const vector<T>& rhs)
		{
			return !(rhs < lhs);
		}

	template <class T>
		bool operator>(const vector<T>& lhs, const vector<T>& rhs)
		{
			return rhs < lhs;
		}

	template <class T>
		bool operator>=(const vector<T>& lhs, const vector<T>& rhs)
		{
			return !(lhs < rhs);
		}

	template <class T>
		void swap(vector<T>& x, vector<T>& y)
		{
			x.swap(y);
		}
}
#endif
