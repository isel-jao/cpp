/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:59:34 by isel-jao          #+#    #+#             */
/*   Updated: 2023/01/13 14:09:21 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = std::vector<T>>
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
		explicit stack(const container_type &c = container_type()) : _c(c) {}

		~stack() {}

		bool empty() const { return (this->_c.empty()); }

		size_type size() const { return (this->_c.size()); }

		value_type &top() { return (this->_c.back()); }

		const value_type &top() const { return (this->_c.back()); }

		void push(const value_type &val) { this->_c.push_back(val); }

		void pop() { this->_c.pop_back(); }

		template <class Tn, class ContainerN>
		friend bool operator==(const ft::stack<Tn, ContainerN> &lhs, const ft::stack<Tn, ContainerN> &rhs);

		template <class Tn, class ContainerN>
		friend bool operator!=(const ft::stack<Tn, ContainerN> &lhs, const ft::stack<Tn, ContainerN> &rhs);

		template <class Tn, class ContainerN>
		friend bool operator<(const ft::stack<Tn, ContainerN> &lhs, const ft::stack<Tn, ContainerN> &rhs);

		template <class Tn, class ContainerN>
		friend bool operator<=(const ft::stack<Tn, ContainerN> &lhs, const ft::stack<Tn, ContainerN> &rhs);

		template <class Tn, class ContainerN>
		friend bool operator>(const ft::stack<Tn, ContainerN> &lhs, const ft::stack<Tn, ContainerN> &rhs);

		template <class Tn, class ContainerN>
		friend bool operator>=(const ft::stack<Tn, ContainerN> &lhs, const ft::stack<Tn, ContainerN> &rhs);

	protected:
		container_type _c;
	};

	template <class T, class Container>
	bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._c == rhs._c);
	}

	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._c != rhs._c);
	}

	template <class T, class Container>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._c < rhs._c);
	}

	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._c <= rhs._c);
	}

	template <class T, class Container>
	bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._c > rhs._c);
	}

	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs._c >= rhs._c);
	}
}

#endif
