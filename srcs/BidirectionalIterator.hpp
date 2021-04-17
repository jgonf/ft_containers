#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

# include "list.hpp"

namespace ft
{
	template <class T>
		struct node_list;

	template <class T>
		class ConstBidirectionalIterator;

	template < typename T>
		class BidirectionalIterator
		{
			public:

				typedef T		value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef node_list<T>	*pointer;
				typedef T		&reference;
				static const bool	input_iter;
//				typedef	ft::random_access_iterator_tag	iterator_category;

				BidirectionalIterator(void): _ptr(NULL) {}
				BidirectionalIterator(BidirectionalIterator const &src): _ptr(src._ptr) {};
				BidirectionalIterator(pointer ptr): _ptr(ptr) {};
				virtual ~BidirectionalIterator(void) {}

				pointer	getPtr(void) const { return _ptr; }

				BidirectionalIterator	&operator=(BidirectionalIterator const & src)
				{
					_ptr = src._ptr;
					return *this;
				}

				BidirectionalIterator	&operator++(void)
				{
					_ptr = _ptr->next;
					return *this;
				}

				BidirectionalIterator	&operator--(void)
				{
					_ptr = _ptr->prev;
					return *this;
				}

				BidirectionalIterator	operator++(int)
				{
					BidirectionalIterator<value_type> tmp = *this;
					_ptr = _ptr->next;
					return tmp;
				}

				BidirectionalIterator	operator--(int)
				{
					BidirectionalIterator<value_type> tmp = *this;
					_ptr = _ptr->prev;
					return tmp;
				}

				bool operator==(BidirectionalIterator const &cmp) const
				{
					return (_ptr == cmp._ptr);
				}

				bool operator==(ConstBidirectionalIterator<T> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				bool operator!=(BidirectionalIterator const &cmp) const
				{
					return !(*this == cmp);
				}

				bool operator!=(ConstBidirectionalIterator<T> const &cmp) const
				{
					return !(*this == cmp);
				}

				reference operator*(void) const { return _ptr->data; }
				T	*operator->(void) const { return _ptr->data; }

			protected:
				pointer	_ptr;
		};

	template < class T>
		const bool BidirectionalIterator<T>::input_iter = true;

	template <class T>
		class ConstBidirectionalIterator: public BidirectionalIterator<T>
	{
		public:
			typedef T		value_type;
			typedef std::ptrdiff_t 	difference_type;
			typedef node_list<T>	*pointer;
			typedef  T		&reference;
			static const bool	input_iter;
//			typedef	ft::random_access_iterator_tag	iterator_category;

			ConstBidirectionalIterator(void): _ptr(NULL) {}
			ConstBidirectionalIterator(BidirectionalIterator<T> const &src): _ptr(src.getPtr()) {};
//			ConstBidirectionalIterator(ConstBidirectionalIterator const &src): _ptr(src._ptr) {};
//			ConstBidirectionalIterator(pointer ptr): _ptr(ptr) {};
			ConstBidirectionalIterator(node_list<T> *src): _ptr(src) {};
			ConstBidirectionalIterator(node_list<T> src): _ptr(&src) {};
			virtual ~ConstBidirectionalIterator(void) {}

			pointer	getPtr(void) const { return _ptr; }

			ConstBidirectionalIterator	&operator=(ConstBidirectionalIterator const & src)
			{
				_ptr = src._ptr;
				return *this;
			}

			ConstBidirectionalIterator	&operator++(void)
			{
				_ptr = _ptr->next;
				return *this;
			}

			ConstBidirectionalIterator	&operator--(void)
			{
				_ptr = _ptr->prev;
				return *this;
			}

			ConstBidirectionalIterator	operator++(int)
			{
				ConstBidirectionalIterator<value_type> tmp = *this;
				_ptr = _ptr->next;
				return tmp;
			}

			ConstBidirectionalIterator	operator--(int)
			{
				ConstBidirectionalIterator<value_type> tmp = *this;
				_ptr = _ptr->prev;
				return tmp;
			}

			bool operator==(ConstBidirectionalIterator const &cmp) const
			{
				return (_ptr == cmp._ptr);
			}

			bool operator!=(ConstBidirectionalIterator const &cmp) const
			{
				return !(*this == cmp);
			}

			reference	operator*(void) const { return _ptr->data; }
			const T	*operator->(void) const { return _ptr->data; }

		private:
			pointer	_ptr;

	};

	template < class T>
		const bool ConstBidirectionalIterator<T>::input_iter = true;

}

#endif
