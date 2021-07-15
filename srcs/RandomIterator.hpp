#ifndef RANDOMITERATOR_HPP
#define RANDOMITERATOR_HPP

#include <list>
#include "tools.hpp"

namespace ft
{
	template < typename T, bool const_it>
		class RandomIterator
		{
			public:

				typedef typename ft::is_const<const_it, const T, T>::type	value_type;
				typedef std::ptrdiff_t							difference_type;
				typedef value_type								*pointer;
				typedef value_type								&reference;
				static const bool								input_iter;
				typedef	random_access_iterator_tag			iterator_category;

				RandomIterator(void): _ptr(NULL) {}
//				RandomIterator(const RandomIterator &src) {_ptr = src.getPtr(); }
				template <bool is_const>
					RandomIterator (const RandomIterator<T, is_const> & src, typename ft::enable_if<!is_const, T>::type* = 0) { _ptr = src.getPtr(); }
//				RandomIterator(typename std::list<value_type>::iterator const &it): _ptr(&(*it)) {};
				RandomIterator(pointer ptr): _ptr(ptr) {};
				virtual ~RandomIterator(void) {}

				pointer	getPtr(void) const { return _ptr; }

				RandomIterator	&operator=(RandomIterator const & src)
				{
					_ptr = src._ptr;
					return *this;
				}

				RandomIterator	&operator++(void)
				{
					_ptr++;
					return *this;
				}

				RandomIterator	&operator--(void)
				{
					_ptr--;
					return *this;
				}

				RandomIterator	operator++(int)
				{
					RandomIterator<value_type, const_it> tmp (*this);
					_ptr++;
					return tmp;
				}

				RandomIterator operator--(int)
				{
					RandomIterator<value_type, const_it> tmp (*this);
					_ptr--;
					return tmp;
				}

				template <bool is_const>
					bool operator==(RandomIterator<T, is_const> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				template <bool is_const>
					bool operator!=(RandomIterator<T, is_const> const &cmp) const
				{
					return !(*this == cmp);
				}

				reference operator*(void) const { return *_ptr; }
				pointer	operator->(void) const { return _ptr; }

				RandomIterator operator+(difference_type n)
				{
					value_type *tmp = _ptr;
					return tmp +=n;
				}

				RandomIterator operator-(difference_type n)
				{
					value_type *tmp = _ptr;
					return tmp -=n;
				}

				difference_type operator-(const RandomIterator &cmp) const
				{
					return _ptr - cmp.getPtr();
				}

				template <bool is_const>
					bool operator<(RandomIterator<T, is_const> const &cmp) const
				{
					return (_ptr < cmp.getPtr());
				}

				template <bool is_const>
					bool operator>(RandomIterator<T, is_const> const &cmp) const
				{
					return (_ptr > cmp.getPtr());
				}

				template <bool is_const>
					bool operator<=(RandomIterator<T, is_const> const &cmp) const
				{
					return (_ptr <= cmp.getPtr());
				}

				template <bool is_const>
					bool operator>=(RandomIterator<T, is_const> const &cmp) const
				{
					return (_ptr >= cmp.getPtr());
				}

				RandomIterator operator+=(difference_type n)
				{
					_ptr += n;
					return *this;
				}

				RandomIterator operator-=(difference_type n)
				{
					_ptr -= n;
					return *this;
				}

				reference operator[](difference_type n) const { return _ptr[n]; }

			protected:
				pointer	_ptr;
		};

	template <typename T, bool const_it>
		RandomIterator<T, const_it> operator+(int n, RandomIterator<T, const_it> &src)
		{
			T *tmp = src.getPtr();
			return tmp +=n;
		}

	template <typename T, bool const_it>
		RandomIterator<T, const_it> operator+(int n, reverse_iterator< RandomIterator<T, const_it> > &src)
		{
			T *tmp = src.base().getPtr();
			return tmp - n;
		}

	template < class T, bool const_it>
		const bool RandomIterator<T, const_it>::input_iter = true;
}

#endif
