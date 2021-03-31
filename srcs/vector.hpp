/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:59:21 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/03/31 12:33:08 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <iostream>
# include <limits>
# include <iterator>

namespace ft
{
	template<bool, class T>
		struct enable_if {};
	template<class T>
		struct enable_if<true, T> { typedef T type; };

	template < typename T>
		class vector;

	template < typename T>
		class VectorIterator
		{
			public:

				typedef T		value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef T		*pointer;
				typedef T		*reference;
				static const bool	input_iter;
				typedef	std::random_access_iterator_tag	iterator_category;

				VectorIterator(void): _ptr(NULL) {}
				VectorIterator(VectorIterator const &src): _ptr(src._ptr) {};
				VectorIterator(pointer ptr): _ptr(ptr) {};
				virtual ~VectorIterator(void) {}

				pointer	getPtr(void) { return _ptr; }

				VectorIterator	&operator=(VectorIterator const & src)
				{
					_ptr = src._ptr;
					return *this;
				}

				VectorIterator	&operator++(void)
				{
					_ptr++;
					return *this;
				}

				VectorIterator	&operator--(void)
				{
					_ptr--;
					return *this;
				}

				VectorIterator	operator++(int)
				{
					VectorIterator<value_type> tmp = *this;
					_ptr++;
					return tmp;
				}

				VectorIterator	operator--(int)
				{
					VectorIterator<value_type> tmp = *this;
					_ptr--;
					return tmp;
				}

				bool operator==(VectorIterator const &cmp) const
				{
					return (_ptr == cmp._ptr);
				}

				bool operator!=(VectorIterator const &cmp) const
				{
					return !(*this == cmp);
				}

				value_type operator*(void) const { return *_ptr; }
				value_type operator->(void) const { return _ptr; }

				VectorIterator operator+(difference_type n)
				{
					value_type *tmp = _ptr;
					return tmp +=n;
				}

				VectorIterator operator-(difference_type n)
				{
					value_type *tmp = _ptr;
					return tmp -=n;
				}

				difference_type operator-(VectorIterator const &cmp)
				{
					return _ptr - cmp._ptr;
				}

				bool operator<(VectorIterator const &cmp) const
				{
					return (_ptr < cmp._ptr);
				}

				bool operator>(VectorIterator const &cmp) const
				{
					return (_ptr > cmp._ptr);
				}

				bool operator<=(VectorIterator const &cmp) const
				{
					return (_ptr <= cmp._ptr);
				}

				bool operator>=(VectorIterator const &cmp) const
				{
					return (_ptr <= cmp._ptr);
				}

				VectorIterator operator+=(difference_type n)
				{
					_ptr += n;
					return *this;
				}

				VectorIterator operator-=(difference_type n)
				{
					_ptr -= n;
					return *this;
				}

				value_type operator[](difference_type n) const { return _ptr[n]; }

			protected:
				pointer	_ptr;
		};

	template <typename T>
	VectorIterator<T> operator+(int n, VectorIterator<T> &src)
	{
		T *tmp = src.getPtr();
		return tmp +=n;
	}

	template < class T>
	const bool VectorIterator<T>::input_iter = true;

	template < typename T>
		class vector {

			public:

				//variables

				typedef T			value_type;
				typedef value_type		&reference;
				typedef value_type const	&const_reference;
				typedef value_type		*pointer;
				typedef value_type const	*const_pointer;

				typedef VectorIterator<value_type> iterator;
				typedef iterator const	const_iterator;
				typedef iterator	reverse_iterator;
				typedef iterator const	const_reverse_iterator;

				typedef	std::ptrdiff_t	difference_type;
				typedef	size_t		size_type;


				//constructors and destructors

				vector(void): _size(0), _capacity(0)
				{
					_cont = new value_type[0];
				}

				vector(size_t n, value_type val): _size(n), _capacity(n)
				{
					_cont = new value_type[n];
					for (size_t i = 0; i < n; i++)
						_cont[i] = val;
				}

				vector(iterator first, iterator last)
				{
					assign(first, last);
				}

				vector(vector const & src): _cont(NULL), _size(0), _capacity(0)
				{
					assign(src.begin(), src.end());
				}

				virtual ~vector(void)
				{
					delete [] _cont;
				}

				vector	& operator=(vector const & src)
				{
					clear();
					assign(src.begin(), src.end());
					return *this;
				}

				//fonctions iterators
				iterator	begin(void) { return _cont; }

				const_iterator 	begin(void) const { return _cont; }

				iterator	end(void)
				{
					return &_cont[_size];
				}

				const_iterator	end(void) const
				{
					return &_cont[_size];
				}

				reverse_iterator	rbegin(void)
				{
					std::cout << "need to implement reverse iterator" << std::endl;
					return _cont;
				}

				const_reverse_iterator	rbegin(void) const
				{
					std::cout << "need to implement reverse iterator" << std::endl;
					return _cont;
				}

				reverse_iterator	rend(void)
				{
					std::cout << "need to implement reverse iterator" << std::endl;
					return &_cont[_size];
				}

				const_reverse_iterator	rend(void) const
				{
					std::cout << "need to implement reverse iterator" << std::endl;
					return &_cont[_size];
				}


				//capacity
				size_t	size(void) const { return _size; }

				size_t	max_size(void) const { return std::allocator<T>().max_size(); }

				void	resize(size_type n, value_type val = value_type())
				{
					if (n < _size)
					{
						for (size_type i = 0; i < n ; i++)
							pop_back();
					}
					else
						insert(end(), n, val);
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
						throw std::length_error("The size is too large");
					value_type *tmp = new value_type[n];
					for (size_type i = 0; i < _size; i++)
						tmp[i] = _cont[i];
					delete [] _cont;
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
					if (n >= _size)
						throw std::out_of_range("The index is out of range");
					return _cont[n];
				}

				const_reference	at(size_type n) const
				{
					if (n >= _size)
						throw std::out_of_range("The index is out of range");

					return _cont[n];
				}

				reference	front(void) { return _cont[0]; }
				const_reference	front(void) const { return _cont[0]; }

				reference	back(void) { return _cont[_size - 1]; }
				const_reference	back(void) const { return _cont[_size - 1]; }


				//modifiers

				template <class InputIterator>
					void assign(InputIterator first, InputIterator last)
				{
					clear();
					insert(begin(), first, last);
				}

				void	assign(size_type n, const value_type& val)
				{
					clear();
					insert(begin(), n, val);

				}

				void	push_back(const value_type& val)
				{
					if (_capacity <= _size)
						reserve(_size);
					_cont[_size] = val;
					_size++;
				}

				void	pop_back(void)
				{
					_size = _size - 1;
					value_type *tmp = new value_type[_size];
					for (size_type i = 0; i < _size; i++)
						tmp[i] = _cont[i];
					delete [] _cont;
					_cont = tmp;
					_capacity = _size;
				}

				iterator	insert(iterator position, const value_type& val)
				{
					size_t	save = _size + 1;
					size_t	len = 0;
					iterator	it;

					for (it = position; it != end(); ++it)
						len++;
					if (_size <= _capacity)
					{
						reserve(_size + 1);
					}
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
					for (size_type i = 0; i < n; ++i)
						position = insert(position, val) + 1;
				}

				template <class InputIterator>
					void insert (iterator position, InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
					{
						while (first != last)
						{
							position = insert(position, *first) + 1;
							++first;
						}
					}

				iterator	erase(iterator position)
				{
					iterator	end = this->end();

					assign(begin(), position);
					insert(position, position + 1, end);
					return position;
				}

				iterator	erase(iterator first, iterator last)
				{
					iterator	ret = first;

					while (last != first)
					{
						last--;
						erase(last);
					}
					return ret;
				}

				void	swap(vector &x)
				{
					std::swap(_cont, x._cont);
					std::swap(_size, x._size);
					std::swap(_capacity, x._capacity);
				}

				void	clear() { _size = 0; }

			private:
				value_type	*_cont;
				size_t		_size;
				size_t		_capacity;
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
