/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:59:25 by isel-jao          #+#    #+#             */
/*   Updated: 2023/01/14 09:41:21 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <typename T>
	class vector_random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
		typedef T *pointer;
		typedef T &reference;

		vector_random_access_iterator() : _ptr(NULL) {}

		vector_random_access_iterator(pointer ptr) : _ptr(ptr) {}

		vector_random_access_iterator(const vector_random_access_iterator &other) : _ptr(other._ptr) {}

		vector_random_access_iterator &operator=(const vector_random_access_iterator &other)
		{
			_ptr = other._ptr;
			return *this;
		}
		virtual ~vector_random_access_iterator() {}

		pointer base() const { return (this->_ptr); }

		reference operator*(void) const { return (*_ptr); }

		pointer operator->(void) { return &(this->operator*()); }

		vector_random_access_iterator &operator++(void)
		{
			_ptr++;
			return (*this);
		}

		vector_random_access_iterator operator++(int)
		{
			vector_random_access_iterator tmp(*this);
			operator++();
			return (tmp);
		}

		vector_random_access_iterator &operator--(void)
		{
			_ptr--;
			return (*this);
		}

		vector_random_access_iterator operator--(int)
		{
			vector_random_access_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		vector_random_access_iterator operator+(difference_type n) const
		{
			return (vector_random_access_iterator(_ptr + n));
		}

		vector_random_access_iterator operator-(difference_type n) const
		{
			return (vector_random_access_iterator(_ptr - n));
		}

		vector_random_access_iterator &operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		}

		vector_random_access_iterator &operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}

		reference operator[](difference_type n) const { return (_ptr[n]); }

	friend bool operator==(const vector_random_access_iterator &lhs, const vector_random_access_iterator &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	private:
		pointer _ptr;
	};


	template <class Iterator>
	bool operator!=(const vector_random_access_iterator<Iterator> &lhs, const vector_random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	vector_random_access_iterator<Iterator> operator+(typename vector_random_access_iterator<Iterator>::difference_type n, const vector_random_access_iterator<Iterator> &it)
	{
		return (it + n);
	}

	template <class Iterator>
	typename vector_random_access_iterator<Iterator>::difference_type operator-(const vector_random_access_iterator<Iterator> &lhs, const vector_random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <class Iterator>
	bool operator<(const vector_random_access_iterator<Iterator> &lhs, const vector_random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator>(const vector_random_access_iterator<Iterator> &lhs, const vector_random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator<=(const vector_random_access_iterator<Iterator> &lhs, const vector_random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	bool operator>=(const vector_random_access_iterator<Iterator> &lhs, const vector_random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

}

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

		reverse_iterator() : _ptr() {}

		explicit reverse_iterator(iterator_type it) : _ptr(it) {}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _ptr(rev_it.base()) {}

		virtual ~reverse_iterator() {}

		iterator_type base() const { return (_ptr); }

		reference operator*() const
		{
			iterator_type tmp = _ptr;
			return (*(--tmp));
		}

		reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_ptr - n)); }

		reverse_iterator &operator++()
		{
			--_ptr;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const { return (reverse_iterator(_ptr + n)); }

		reverse_iterator &operator--()
		{
			++_ptr;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			_ptr += n;
			return (*this);
		}

		pointer operator->() const { return &(operator*()); }

		reference operator[](difference_type n) const { return (this->base()[-n - 1]); }

		friend bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs._ptr == rhs._ptr); }

		friend bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs._ptr != rhs._ptr); }

		friend bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs._ptr > rhs._ptr); }

		friend bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs._ptr >= rhs._ptr); }

		friend bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs._ptr < rhs._ptr); }

		friend bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs._ptr <= rhs._ptr); }

	private:
		iterator_type _ptr;
	};
}

namespace ft
{
	template <typename D, typename T>
	class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;
		typedef D data_type;

		BST_iterator() : _ptr() {}

		BST_iterator(T *p) : _ptr(p) {}

		BST_iterator(const BST_iterator &it) : _ptr(it._ptr) {}

		virtual ~BST_iterator() {}

		BST_iterator &operator=(const BST_iterator &it)
		{
			if (*this == it)
				return (*this);
			this->_ptr = it._ptr;
			return (*this);
		}

		bool operator==(const BST_iterator &it)
		{
			return (this->_ptr == it._ptr);
		}

		bool operator!=(const BST_iterator &it)
		{
			return (this->_ptr != it._ptr);
		}

		data_type &operator*() const
		{
			return (this->_ptr->_data);
		}

		data_type *operator->() const
		{
			return (&(this->_ptr->_data));
		}

		BST_iterator &operator++(void)
		{
			if (_ptr == NULL)
				return (*this);
			if (_ptr->_right != NULL)
			{
				_ptr = _ptr->_right;
				while (_ptr->_left != NULL)
					_ptr = _ptr->_left;
			}
			else
			{
				while (_ptr->_parent != NULL && _ptr == _ptr->_parent->_right)
					_ptr = _ptr->_parent;
				_ptr = _ptr->_parent;
			}
			return (*this);
		}

		BST_iterator operator++(int)
		{
			BST_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		BST_iterator &operator--(void)
		{
			if (_ptr == NULL)
				return (*this);
			if (_ptr->_left != NULL)
			{
				_ptr = _ptr->_left;
				while (_ptr->_right != NULL)
					_ptr = _ptr->_right;
			}
			else
			{
				while (_ptr->_parent != NULL && _ptr == _ptr->_parent->_left)
					_ptr = _ptr->_parent;
				_ptr = _ptr->_parent;
			}
			return (*this);
		}

		BST_iterator operator--(int)
		{
			BST_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

	friend bool operator==(const BST_iterator &lhs, const BST_iterator &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}

	friend bool operator!=(const BST_iterator &lhs, const BST_iterator &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}
	private:
		pointer _ptr;
	};

}

namespace ft
{
	template <typename D, typename T>
	class BST_reverse_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;
		typedef D data_type;

		BST_reverse_iterator() : _ptr() {}

		BST_reverse_iterator(T *p) : _ptr(p) {}

		BST_reverse_iterator(const BST_reverse_iterator &it) : _ptr(it._ptr) {}

		virtual ~BST_reverse_iterator() {}

		BST_reverse_iterator &operator=(const BST_reverse_iterator &it)
		{
			if (*this == it)
				return (*this);
			this->_ptr = it._ptr;
			return (*this);
		}

		bool operator==(const BST_reverse_iterator &it)
		{
			return (this->_ptr == it._ptr);
		}

		bool operator!=(const BST_reverse_iterator &it)
		{
			return (this->_ptr != it._ptr);
		}

		data_type &operator*() const
		{
			return (this->_ptr->_data);
		}

		data_type *operator->() const
		{
			return (&(this->_ptr->_data));
		}

		BST_reverse_iterator &operator++(void)
		{
			if (_ptr == NULL)
				return (*this);
			if (_ptr->_left != NULL)
			{
				_ptr = _ptr->_left;
				while (_ptr->_right != NULL)
					_ptr = _ptr->_right;
			}
			else
			{
				while (_ptr->_parent != NULL && _ptr == _ptr->_parent->_left)
					_ptr = _ptr->_parent;
				_ptr = _ptr->_parent;
			}
			return (*this);
		}

		BST_reverse_iterator operator++(int)
		{
			BST_reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		BST_reverse_iterator &operator--(void)
		{
			if (_ptr == NULL)
				return (*this);
			if (_ptr->_right != NULL)
			{
				_ptr = _ptr->_right;
				while (_ptr->_left != NULL)
					_ptr = _ptr->_left;
			}
			else
			{
				while (_ptr->_parent != NULL && _ptr == _ptr->_parent->_right)
					_ptr = _ptr->_parent;
				_ptr = _ptr->_parent;
			}
			return (*this);
		}

		BST_reverse_iterator operator--(int)
		{
			BST_reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

	
	friend bool operator==(const BST_reverse_iterator &lhs, const BST_reverse_iterator &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}
	friend bool operator!=(const BST_reverse_iterator &lhs, const BST_reverse_iterator &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}
	private:
		pointer _ptr;
	};


}

namespace ft
{
	template <typename D, typename T>
	class BST_const_reverse_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;
		typedef D data_type;

		BST_const_reverse_iterator() : _ptr() {}

		BST_const_reverse_iterator(T *p) : _ptr(p) {}

		BST_const_reverse_iterator(const BST_const_reverse_iterator &it) : _ptr(it._ptr) {}

		virtual ~BST_const_reverse_iterator() {}

		BST_const_reverse_iterator &operator=(const BST_const_reverse_iterator &it)
		{
			if (*this == it)
				return (*this);
			this->_ptr = it._ptr;
			return (*this);
		}

		bool operator==(const BST_const_reverse_iterator &it)
		{
			return (this->_ptr == it._ptr);
		}

		bool operator!=(const BST_const_reverse_iterator &it)
		{
			return (this->_ptr != it._ptr);
		}

		const data_type &operator*() const
		{
			if (this->_offset != 0 || this->_ptr == NULL)
			{
				return (this->_first_node->_data);
			}
			return (this->_ptr->_data);
		}

		const data_type *operator->() const
		{
			return (&(this->_ptr->_data));
		}

		BST_const_reverse_iterator &operator++(void)
		{
			return (*this);
		}

		BST_const_reverse_iterator operator++(int)
		{
			BST_const_reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		BST_const_reverse_iterator &operator--(void)
		{
			return (*this);
		}

		BST_const_reverse_iterator operator--(int)
		{
			BST_const_reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

	private:
		pointer _ptr;
	};
}

#endif
// void ft::vector<T, Allocator>::insert(ft::vector<T, Allocator>::iterator, InputIterator, InputIterator)
// InputIterator = int;
// T = int;
// Allocator = std::allocator<int>
//  ft::vector<T, Allocator>::iterator = ft::vector_random_access_iterator<int>