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
# include "reverse_iterator.hpp"

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
				typedef T		&reference;
				static const bool	input_iter;
				typedef	ft::random_access_iterator_tag	iterator_category;

				VectorIterator(void): _ptr(NULL) {}
				VectorIterator(VectorIterator const &src): _ptr(src._ptr) {};
				VectorIterator(pointer ptr): _ptr(ptr) {};
				virtual ~VectorIterator(void) {}

				pointer	getPtr(void) const { return _ptr; }

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

				reference operator*(void) const { return *_ptr; }
				pointer	operator->(void) const { return _ptr; }

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

				reference operator[](difference_type n) const { return _ptr[n]; }

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

	template <class T>
		class ConstVectorIterator: public VectorIterator<T>
	{
		public:
			typedef T		value_type;
			typedef std::ptrdiff_t 	difference_type;
			typedef T		*pointer;
			typedef T		&reference;
			static const bool	input_iter;
			typedef	ft::random_access_iterator_tag	iterator_category;

			ConstVectorIterator(void): _ptr(NULL) {}
			ConstVectorIterator(VectorIterator<T> const &src): _ptr(src.getPtr()) {};
			ConstVectorIterator(ConstVectorIterator const &src): _ptr(src._ptr) {};
			ConstVectorIterator(pointer ptr): _ptr(ptr) {};
			virtual ~ConstVectorIterator(void) {}

			pointer	getPtr(void) const { return _ptr; }

			ConstVectorIterator	&operator=(ConstVectorIterator const & src)
			{
				_ptr = src._ptr;
				return *this;
			}

			ConstVectorIterator	&operator++(void)
			{
				_ptr++;
				return *this;
			}

			ConstVectorIterator	&operator--(void)
			{
				_ptr--;
				return *this;
			}

			ConstVectorIterator	operator++(int)
			{
				ConstVectorIterator<value_type> tmp = *this;
				_ptr++;
				return tmp;
			}

			ConstVectorIterator	operator--(int)
			{
				ConstVectorIterator<value_type> tmp = *this;
				_ptr--;
				return tmp;
			}

			bool operator==(ConstVectorIterator const &cmp) const
			{
				return (_ptr == cmp._ptr);
			}

			bool operator!=(ConstVectorIterator const &cmp) const
			{
				return !(*this == cmp);
			}

			const value_type  &operator*(void) const { return *_ptr; }
			pointer	operator->(void) const { return _ptr; }

/*			ConstVectorIterator operator+(difference_type n)
			{
				value_type *tmp = _ptr;
				return tmp +=n;
			}

			ConstVectorIterator operator-(difference_type n)
			{
				value_type *tmp = _ptr;
				return tmp -=n;
			}

			difference_type operator-(ConstVectorIterator const &cmp)
			{
				return _ptr - cmp._ptr;
			}
*/
			bool operator<(ConstVectorIterator const &cmp) const
			{
				return (_ptr < cmp._ptr);
			}

			bool operator>(ConstVectorIterator const &cmp) const
			{
				return (_ptr > cmp._ptr);
			}

			bool operator<=(ConstVectorIterator const &cmp) const
			{
				return (_ptr <= cmp._ptr);
			}

			bool operator>=(ConstVectorIterator const &cmp) const
			{
				return (_ptr <= cmp._ptr);
			}

			ConstVectorIterator operator+=(difference_type n)
			{
				_ptr += n;
				return *this;
			}

			ConstVectorIterator operator-=(difference_type n)
			{
				_ptr -= n;
				return *this;
			}

			const value_type &operator[](difference_type n) { return _ptr[n]; }


		private:
			pointer	_ptr;

	};

	template < class T>
		const bool ConstVectorIterator<T>::input_iter = true;

	template < typename T>
		class vector {

			public:

				//variables

				typedef T			value_type;
				typedef value_type		&reference;
				typedef value_type const	&const_reference;
				typedef value_type		*pointer;
				typedef value_type const	*const_pointer;

				typedef VectorIterator<value_type>	iterator;
				//				typedef iterator const			const_iterator;
				typedef ConstVectorIterator<value_type>		const_iterator;
				typedef reverse_iterator<iterator>	reverse_iterator;
				typedef reverse_iterator const		const_reverse_iterator;

				typedef	std::ptrdiff_t	difference_type;
				typedef	size_t		size_type;


				//constructors and destructors

				explicit vector(void): _size(0), _capacity(0)
			{
				std::allocator<T> alloc;
				_cont = alloc.allocate(0);
			}

				explicit vector(size_t n, value_type val = value_type()): _size(n), _capacity(n)
			{
				std::allocator<T> alloc;
				_cont = alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
					alloc.construct(&_cont[i],val);

			}

				template <class InputIterator>
					vector(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)
					{
						assign(first, last);
					}

				vector(vector const & x): _cont(NULL), _size(0), _capacity(0)
			{
				assign(x.begin(), x.end());
			}

				virtual ~vector(void)
				{
					std::allocator<T> alloc;
					for (size_type i = 0; i < _size; i++)
						alloc.destroy(&_cont[i]);
					alloc.deallocate(_cont, _capacity);
				}

				vector	& operator=(vector const & src)
				{
					clear();
					assign(src.begin(), src.end());
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
					//					return _cont;
				}

				const_reverse_iterator	rbegin(void) const
				{
					return const_reverse_iterator(end());
					//					return _cont;
				}

				reverse_iterator	rend(void)
				{
					return reverse_iterator(begin());
					//					return &_cont[_size];
				}

				const_reverse_iterator	rend(void) const
				{
					return const_reverse_iterator(begin());
					//					return &_cont[_size];
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
						throw std::length_error("vector::reserve");
					std::allocator<T> alloc;
					T *tmp = alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						alloc.construct(&tmp[i], _cont[i]);
						alloc.destroy(&_cont[i]);
					}
					alloc.deallocate(_cont, _capacity);
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
					void assign(InputIterator first, typename ft::enable_if<InputIterator::input_iter, InputIterator>::type last)

					{
						clear();
						insert(begin(), first, last);
					}

				void	assign(size_type n, const value_type& val)
				{
					clear();
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

					std::allocator<T> alloc;
					reserve(new_capa);
					alloc.construct(&_cont[_size], val);
					_size++;
				}

				void	pop_back(void)
				{
					std::allocator<T> alloc;
					alloc.destroy(&_cont[_size - 1]);
					_size = _size - 1;

				}

				iterator	insert(iterator position, const value_type& val)
				{
					size_t	save = _size + 1;
					size_t	len = 0;
					iterator	it;

					for (it = position; it != end(); ++it)
						len++;
					if (_capacity < _size + 1)
						reserve(_size + 1);
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
//                                        std::allocator<T> alloc;
//                                        size_type i = 0;
//                                        iterator it = begin();
//                                        while (it + i != position && i < _size)
//                                                i++;
//                                        if (_capacity < _size + 1)
//                                                reserve(_size + 1);
//                                        size_type j = _capacity - 1;
//                                        while (j > i)
//                                        {
//                                                alloc.destroy(&_cont[j]);
//                                                alloc.construct(&_cont[j], _cont[j-1]);
////                                              _cont[j] = _cont[j - 1];
//                                                j--;
//                                        }
//                                        _cont[i] = val;
//                                        _size++;
//                                        return (iterator(&_cont[i]));

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

				void    insert(iterator position, pointer first, pointer last)
				{
					insert(position, iterator(first), iterator(last));
				}


				iterator	erase(iterator position)
				{
				                                        iterator        ret;
					std::allocator<T>	alloc;

                                        ret = position;
                                        while (position + 1 != end())
                                        {
						alloc.destroy(position.getPtr());
						alloc.construct(position.getPtr(), *(position + 1));

//                                                *position = *(position + 1);
                                                position++;
                                        }
					alloc.destroy(position.getPtr());
                                        _size--;
                                        return ret;
//					iterator	end = this->end();
//
//					assign(begin(), position);
//					insert(position, position + 1, end);
//					return position;
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
					std::allocator<T> alloc;
					for (size_t i = 0; i < _size; i++)
						alloc.destroy(&_cont[i]);
					_size = 0;
				}

			protected:
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
