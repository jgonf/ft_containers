/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgonfroy <jgonfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:59:21 by jgonfroy          #+#    #+#             */
/*   Updated: 2021/03/22 21:51:24 by jgonfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <iostream>

//template <typename T>

namespace ft
{
	template < class T>
		class vector {

			public:

				//variables

				typedef T			value_type;
				typedef value_type		&reference;
				typedef value_type const	&const_reference;
				typedef value_type		*pointer;
				typedef value_type const	*const_pointer;

				typedef T		*iterator;
				typedef iterator const	const_iterator;
				typedef iterator	reverse_iterator;
				typedef iterator const	const_reverse_iterator;

				std::ptrdiff_t		difference_type;
				size_t			size_type;


				//constructors and destructors

				vector(void): _size(0)
				{
					_cont = new value_type[0];
				};

				vector(size_t n, value_type val);
				vector(iterator first, iterator last);
				vector(vector const & src);
				virtual ~vector(void) {};
				vector	& operator=(vector const & src);


				//fonctions
				iterator	begin(void) {}
				const_iterator 	begin(void) const {}
				iterator	end(void) {}
				const_iterator	end(void) const {}
				reverse_iterator	rbegin(void) {}
				const_reverse_iterator	rbegin(void) const {}
				reverse_iterator	rend(void) {}
				const_reverse_iterator	rend(void) const {}


			private:
				value_type	*_cont;
				size_t		_size;
		};
}
#endif
