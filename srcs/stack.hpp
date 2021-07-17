/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:59:21 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/04/04 14:03:16 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

//# include "reverse_iterator.hpp"
//# include "RandomIterator.hpp"
//# include "tools.hpp"
# include "vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
		class stack {

			public:

				//variables

				typedef T			value_type;
				typedef Container	container_type;
				typedef	size_t		size_type;


				//constructors
				explicit stack (const container_type& ctnr = container_type())
				{
					_cont = ctnr;
				}

				bool empty() const	{ return _cont.empty(); }

				size_type size() const { return _cont.size(); }

				value_type& top() { return _cont.back(); }
				const value_type& top() const { return _cont.back(); }

				void push (const value_type& val) { return _cont.push_back(val); }

				void pop() { return _cont.pop_back(); }

			protected:
				container_type	_cont;

			friend bool operator==(const stack &lhs, const stack &rhs)
			{
				return (lhs._cont == rhs._cont);
			}

			friend bool operator<(const stack &lhs, const stack &rhs)
			{
				return (lhs._cont < rhs._cont);
			}
		};

	template <class T, class Container >
		bool operator!=(const stack<T, Container>& lhs, const stack<T,Container>& rhs)
		{
			return !(lhs == rhs);
		}

	template <class T, class Container >
		bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return !(rhs < lhs);
		}

	template <class T, class Container >
		bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return rhs < lhs;
		}

	template <class T, class Container >
		bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
		{
			return !(lhs < rhs);
		}
}
#endif
