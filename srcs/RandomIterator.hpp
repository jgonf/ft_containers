#ifndef RANDOMITERATOR_HPP
#define RANDOMITERATOR_HPP

#include <list>

namespace ft
{
	template < typename T>
		class RandomIterator
		{
			public:

				typedef T		value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef T		*pointer;
				typedef T		&reference;
				static const bool	input_iter;
				typedef	ft::random_access_iterator_tag	iterator_category;

				RandomIterator(void): _ptr(NULL) {}
				RandomIterator(RandomIterator const &src): _ptr(src._ptr) {};
				RandomIterator(typename std::list<value_type>::iterator const &it): _ptr(&(*it)) {};
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
					RandomIterator<value_type> tmp = *this;
					_ptr++;
					return tmp;
				}

				RandomIterator	operator--(int)
				{
					RandomIterator<value_type> tmp = *this;
					_ptr--;
					return tmp;
				}

				bool operator==(RandomIterator const &cmp) const
				{
					return (_ptr == cmp._ptr);
				}

				bool operator==(ConstRandomIterator<T> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				bool operator!=(RandomIterator const &cmp) const
				{
					return !(*this == cmp);
				}

				bool operator!=(ConstRandomIterator<T> const &cmp) const
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

				difference_type operator-(RandomIterator const &cmp)
				{
					return _ptr - cmp._ptr;
				}

		/*		difference_type operator-(ConstRandomIterator<T> const &cmp)
				{
					return _ptr - cmp.getPtr();
				}
		*/

				bool operator<(RandomIterator const &cmp) const
				{
					return (_ptr < cmp._ptr);
				}

				bool operator<(ConstRandomIterator<T> const &cmp) const
				{
					return (_ptr < cmp.getPtr());
				}


				bool operator>(RandomIterator const &cmp) const
				{
					return (_ptr > cmp._ptr);
				}

				bool operator>(ConstRandomIterator<T> const &cmp) const
				{
					return (_ptr > cmp.getPtr());
				}

				bool operator<=(RandomIterator const &cmp) const
				{
					return (_ptr <= cmp._ptr);
				}

				bool operator<=(ConstRandomIterator<T> const &cmp) const
				{
					return (_ptr <= cmp.getPtr());
				}

				bool operator>=(RandomIterator const &cmp) const
				{
					return (_ptr >= cmp._ptr);
				}

				bool operator>=(ConstRandomIterator<T> const &cmp) const
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

	template <typename T>
		RandomIterator<T> operator+(int n, RandomIterator<T> &src)
		{
			T *tmp = src.getPtr();
			return tmp +=n;
		}

	template < class T>
		const bool RandomIterator<T>::input_iter = true;

	template <class T>
		class ConstRandomIterator: public RandomIterator<T>
	{
		public:
			typedef T		value_type;
			typedef std::ptrdiff_t 	difference_type;
			typedef  T		*pointer;
			typedef  T		&reference;
			static const bool	input_iter;
			typedef	ft::random_access_iterator_tag	iterator_category;

			ConstRandomIterator(void): _ptr(NULL) {}
			ConstRandomIterator(RandomIterator<T> const &src): _ptr(src.getPtr()) {};
//			ConstRandomIterator(ConstRandomIterator const &src): _ptr(src._ptr) {};
			ConstRandomIterator(pointer ptr): _ptr(ptr) {};
			virtual ~ConstRandomIterator(void) {}

			pointer	getPtr(void) const { return _ptr; }

			ConstRandomIterator	&operator=(ConstRandomIterator const & src)
			{
				_ptr = src._ptr;
				return *this;
			}

			ConstRandomIterator	&operator++(void)
			{
				_ptr++;
				return *this;
			}

			ConstRandomIterator	&operator--(void)
			{
				_ptr--;
				return *this;
			}

			ConstRandomIterator	operator++(int)
			{
				ConstRandomIterator<value_type> tmp = *this;
				_ptr++;
				return tmp;
			}

			ConstRandomIterator	operator--(int)
			{
				ConstRandomIterator<value_type> tmp = *this;
				_ptr--;
				return tmp;
			}

			bool operator==(ConstRandomIterator const &cmp) const
			{
				return (_ptr == cmp._ptr);
			}

			bool operator!=(ConstRandomIterator const &cmp) const
			{
				return !(*this == cmp);
			}

			const value_type  &operator*(void) const { return *_ptr; }
			const T	*operator->(void) const { return _ptr; }

			ConstRandomIterator operator+(difference_type n)
			{
				value_type *tmp = _ptr;
				return tmp +=n;
			}

			ConstRandomIterator operator-(difference_type n)
			{
				value_type *tmp = _ptr;
				return tmp -=n;
			}

			difference_type operator-(ConstRandomIterator const &cmp) const
			{
				return _ptr - cmp._ptr;
			}

			bool operator<(ConstRandomIterator const &cmp) const
			{
				return (_ptr < cmp._ptr);
			}

			bool operator>(ConstRandomIterator const &cmp) const
			{
				return (_ptr > cmp._ptr);
			}

			bool operator<=(ConstRandomIterator const &cmp) const
			{
				return (_ptr <= cmp._ptr);
			}

			bool operator>=(ConstRandomIterator const &cmp) const
			{
				return (_ptr >= cmp._ptr);
			}

			ConstRandomIterator operator+=(difference_type n)
			{
				_ptr += n;
				return *this;
			}

			ConstRandomIterator operator-=(difference_type n)
			{
				_ptr -= n;
				return *this;
			}

			const value_type &operator[](difference_type n) { return _ptr[n]; }


		private:
			pointer	_ptr;

	};

	template < class T>
		const bool ConstRandomIterator<T>::input_iter = true;

}

#endif
