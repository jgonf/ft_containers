/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:38:10 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/05/25 12:24:51 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

# include "map.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T>
		struct node_tree;

	template <class T>
		class ConstTreeIterator;

	template < typename T>
		class TreeIterator
		{
			public:

				typedef T		value_type;
				typedef std::ptrdiff_t 	difference_type;
				typedef node_tree<T>	*pointer;
				typedef T		&reference;
				static const bool	input_iter;
				typedef	ft::BidirectionalIteratorTag	iterator_category;

				TreeIterator(void): _ptr(NULL) {}
				TreeIterator(TreeIterator const &src): _ptr(src._ptr) {};
				TreeIterator(pointer _ptr): _ptr(_ptr) {};
				virtual ~TreeIterator(void) {}

				pointer	getPtr(void) const { return _ptr; }

				TreeIterator	&operator=(TreeIterator const & src)
				{
					_ptr = src._ptr;
					return *this;
				}

				TreeIterator	&operator++(void)
				{
					_setNextNode();
					return *this;
				}

				TreeIterator	&operator--(void)
				{
					_setPrevNode();
					return *this;
				}

				TreeIterator	operator++(int)
				{
					TreeIterator<value_type> tmp = *this;
					++(*this);
					return tmp;
				}

				TreeIterator	operator--(int)
				{
					TreeIterator<value_type> tmp = *this;
					--(*this);
					return tmp;
				}

				bool operator==(TreeIterator const &cmp) const
				{
					return (_ptr == cmp._ptr);
				}

				bool operator==(ConstTreeIterator<T> const &cmp) const
				{
					return (_ptr == cmp.getPtr());
				}

				bool operator!=(TreeIterator const &cmp) const
				{
					return !(*this == cmp);
				}

				bool operator!=(ConstTreeIterator<T> const &cmp) const
				{
					return !(*this == cmp);
				}

				reference	operator*(void) { return (_ptr->data); }
				reference	operator*(void) const { return (_ptr->data); }
				T			*operator->(void) { return &(this->operator*()); }
				T			*operator->(void) const { return &(this->operator*()); }


			protected:
				pointer	_ptr;

//code a changer plus tard
				void	_setNextNode(void)
				{
					if (_ptr->right)
					{
						_ptr = _ptr->right;
						while (_ptr->left)
							_ptr = _ptr->left;
					}
					else
					{
						pointer	tmp = _ptr;
						_ptr = _ptr->parent;
						while (_ptr->left != tmp)
						{

							tmp = _ptr;
							_ptr = _ptr->parent;
						}
					}
				}

				void	_setPrevNode(void)
				{
					if (_ptr->left)
					{
						_ptr = _ptr->left;
						while (_ptr->right)
							_ptr = _ptr->right;
					}
					else
						_ptr = _ptr->parent;
				}
		};

	template < class T>
		const bool TreeIterator<T>::input_iter = true;

	template <class T>
		class ConstTreeIterator: public TreeIterator<T>
	{
		public:
			typedef T		value_type;
			typedef std::ptrdiff_t 	difference_type;
			typedef node_tree<T>	*pointer;
			typedef  T		&reference;
			static const bool	input_iter;
			typedef	ft::BidirectionalIteratorTag	iterator_category;
//			typedef	ft::random_access_iterator_tag	iterator_category;

			ConstTreeIterator(void): _ptr(NULL) {}
			ConstTreeIterator(TreeIterator<T> const &src): _ptr(src.getPtr()) {};
//			ConstTreeIterator(ConstTreeIterator const &src): _ptr(src._ptr) {};
//			ConstTreeIterator(pointer _ptr): _ptr(_ptr) {};
			ConstTreeIterator(node_tree<T> *src): _ptr(src) {};
			ConstTreeIterator(node_tree<T> src): _ptr(&src) {};
			virtual ~ConstTreeIterator(void) {}

			pointer	getPtr(void) const { return _ptr; }

			ConstTreeIterator	&operator=(ConstTreeIterator const & src)
			{
				_ptr = src._ptr;
				return *this;
			}

			ConstTreeIterator	&operator++(void)
			{
				this->_setNextNode();
				return *this;
			}

			ConstTreeIterator	&operator--(void)
			{
				this->_setPrevNode();
				return *this;
			}

			ConstTreeIterator	operator++(int)
			{
				ConstTreeIterator<value_type> tmp = *this;
				++(*this);
				return tmp;
			}

			ConstTreeIterator	operator--(int)
			{
				ConstTreeIterator<value_type> tmp = *this;
				--(*this);
				return tmp;
			}

			bool operator==(ConstTreeIterator const &cmp) const
			{
				return (_ptr == cmp._ptr);
			}

			bool operator!=(ConstTreeIterator const &cmp) const
			{
				return !(*this == cmp);
			}

			reference	operator*(void) const { return _ptr->data; }
			const T	*operator->(void) const { return &(this->operator*()); }

		private:
			pointer	_ptr;

	};

	template < class T>
		const bool ConstTreeIterator<T>::input_iter = true;

}

#endif
