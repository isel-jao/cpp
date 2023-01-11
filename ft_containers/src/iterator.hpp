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

		friend bool operator==(const vector_random_access_iterator<T> &lhs, const vector_random_access_iterator<T> &rhs)
		{
			return (lhs._ptr == rhs._ptr);
		}

		friend bool operator!=(const vector_random_access_iterator<T> &lhs, const vector_random_access_iterator<T> &rhs)
		{
			return (lhs._ptr != rhs._ptr);
		}

		friend bool operator<(const vector_random_access_iterator<T> &lhs, const vector_random_access_iterator<T> &rhs)
		{
			return (lhs._ptr < rhs._ptr);
		}

		friend bool operator<=(const vector_random_access_iterator<T> &lhs, const vector_random_access_iterator<T> &rhs)
		{
			return (lhs._ptr <= rhs._ptr);
		}

		friend bool operator>(const vector_random_access_iterator<T> &lhs, const vector_random_access_iterator<T> &rhs)
		{
			return (lhs._ptr > rhs._ptr);
		}

		friend bool operator>=(const vector_random_access_iterator<T> &lhs, const vector_random_access_iterator<T> &rhs)
		{
			return (lhs._ptr >= rhs._ptr);
		}

	private:
		pointer _ptr;
	};

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

		BST_iterator() : _ptr(), _last_node() {}

		BST_iterator(T *p, T *first_node, T *last_node, int offset = 0) : _ptr(p), _first_node(first_node), _last_node(last_node), _offset(offset) {}

		BST_iterator(const BST_iterator &it) : _ptr(it._ptr), _first_node(it._first_node), _last_node(it._last_node), _offset(it._offset) {}

		virtual ~BST_iterator() {}

		BST_iterator &operator=(const BST_iterator &it)
		{
			if (*this == it)
				return (*this);
			this->_ptr = it._ptr;
			this->_last_node = it._last_node;
			this->_first_node = it._first_node;
			this->_offset = it._offset;
			return (*this);
		}

		bool operator==(const BST_iterator &it)
		{
			return (this->_ptr == it._ptr && this->_offset == it._offset);
		}

		bool operator!=(const BST_iterator &it)
		{
			return (this->_ptr != it._ptr || this->_offset != it._offset);
		}

		data_type &operator*() const
		{
			if (this->_offset != 0 || this->_ptr == NULL)
			{
				return (this->_last_node->_data);
			}
			return (this->_ptr->_data);
		}

		data_type *operator->() const
		{
			return (&(this->_ptr->_data));
		}

		BST_iterator &operator++(void)
		{
			if (this->_offset < 0 || this->_offset > 1 || this->_ptr == this->_last_node)
				this->_offset++;
			else if (this->_ptr->_right)
			{
				this->_ptr = this->_ptr->_right;
				while (this->_ptr->_left)
					this->_ptr = this->_ptr->_left;
			}
			else
			{
				while (this->_ptr->_parent && this->_ptr->_parent->_right == this->_ptr)
					this->_ptr = this->_ptr->_parent;
				this->_ptr = this->_ptr->_parent;
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
			if (this->_offset > 0 || this->_offset < -1 || this->_ptr == this->_first_node)
				this->_offset--;
			else if (this->_ptr->_left)
			{
				this->_ptr = this->_ptr->_left;
				while (this->_ptr->_right)
					this->_ptr = this->_ptr->_right;
			}
			else
			{
				while (this->_ptr->_parent && this->_ptr->_parent->_left == this->_ptr)
					this->_ptr = this->_ptr->_parent;
				this->_ptr = this->_ptr->_parent;
			}
			return (*this);
		}

		BST_iterator operator--(int)
		{
			BST_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

	private:
		pointer _ptr;
		pointer _last_node;
		pointer _first_node;
		int _offset;
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

		BST_reverse_iterator() : _ptr(), _last_node() {}

		BST_reverse_iterator(T *p, T *first_node, T *last_node, int offset = 0) : _ptr(p), _first_node(first_node), _last_node(last_node), _offset(offset) {}

		BST_reverse_iterator(const BST_reverse_iterator &it) : _ptr(it._ptr), _first_node(it._first_node), _last_node(it._last_node), _offset(it._offset) {}

		virtual ~BST_reverse_iterator() {}

		BST_reverse_iterator &operator=(const BST_reverse_iterator &it)
		{
			if (*this == it)
				return (*this);
			this->_ptr = it._ptr;
			this->_last_node = it._last_node;
			this->_first_node = it._first_node;
			this->_offset = it._offset;
			return (*this);
		}

		bool operator==(const BST_reverse_iterator &it)
		{
			return (this->_ptr == it._ptr && this->_offset == it._offset);
		}

		bool operator!=(const BST_reverse_iterator &it)
		{
			return (this->_ptr != it._ptr || this->_offset != it._offset);
		}

		data_type &operator*() const
		{
			if (this->_offset != 0 || this->_ptr == NULL)
			{
				return (this->_first_node->_data);
			}
			return (this->_ptr->_data);
		}

		data_type *operator->() const
		{
			return (&(this->_ptr->_data));
		}

		BST_reverse_iterator &operator++(void)
		{
			if (this->_offset < 0 || this->_offset > 1 || this->_ptr == this->_first_node)
				this->_offset++;
			else if (this->_ptr->_left)
			{
				this->_ptr = this->_ptr->_left;
				while (this->_ptr->_right)
					this->_ptr = this->_ptr->_right;
			}
			else
			{
				while (this->_ptr->_parent && this->_ptr->_parent->_left == this->_ptr)
					this->_ptr = this->_ptr->_parent;
				this->_ptr = this->_ptr->_parent;
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
			if (this->_offset > 0 || this->_offset < -1 || this->_ptr == this->_last_node)
				this->_offset--;
			else if (this->_ptr->_right)
			{
				this->_ptr = this->_ptr->_right;
				while (this->_ptr->_left)
					this->_ptr = this->_ptr->_left;
			}
			else
			{
				while (this->_ptr->_parent && this->_ptr->_parent->_right == this->_ptr)
					this->_ptr = this->_ptr->_parent;
				this->_ptr = this->_ptr->_parent;
			}
			return (*this);
		}

		BST_reverse_iterator operator--(int)
		{
			BST_reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

	private:
		pointer _ptr;
		pointer _last_node;
		pointer _first_node;
		int _offset;
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

		BST_const_reverse_iterator() : _ptr(), _last_node() {}

		BST_const_reverse_iterator(T *p, T *first_node, T *last_node, int offset = 0) : _ptr(p), _first_node(first_node), _last_node(last_node), _offset(offset) {}

		BST_const_reverse_iterator(const BST_const_reverse_iterator &it) : _ptr(it._ptr), _first_node(it._first_node), _last_node(it._last_node), _offset(it._offset) {}

		virtual ~BST_const_reverse_iterator() {}

		BST_const_reverse_iterator &operator=(const BST_const_reverse_iterator &it)
		{
			if (*this == it)
				return (*this);
			this->_ptr = it._ptr;
			this->_last_node = it._last_node;
			this->_first_node = it._first_node;
			this->_offset = it._offset;
			return (*this);
		}

		bool operator==(const BST_const_reverse_iterator &it)
		{
			return (this->_ptr == it._ptr && this->_offset == it._offset);
		}

		bool operator!=(const BST_const_reverse_iterator &it)
		{
			return (this->_ptr != it._ptr || this->_offset != it._offset);
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
			if (this->_offset < 0 || this->_offset > 1 || this->_ptr == this->_first_node)
				this->_offset++;
			else if (this->_ptr->_left)
			{
				this->_ptr = this->_ptr->_left;
				while (this->_ptr->_right)
					this->_ptr = this->_ptr->_right;
			}
			else
			{
				while (this->_ptr->_parent && this->_ptr->_parent->_left == this->_ptr)
					this->_ptr = this->_ptr->_parent;
				this->_ptr = this->_ptr->_parent;
			}
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
			if (this->_offset > 0 || this->_offset < -1 || this->_ptr == this->_last_node)
				this->_offset--;
			else if (this->_ptr->_right)
			{
				this->_ptr = this->_ptr->_right;
				while (this->_ptr->_left)
					this->_ptr = this->_ptr->_left;
			}
			else
			{
				while (this->_ptr->_parent && this->_ptr->_parent->_right == this->_ptr)
					this->_ptr = this->_ptr->_parent;
				this->_ptr = this->_ptr->_parent;
			}
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
		pointer _last_node;
		pointer _first_node;
		int _offset;
	};
}

#endif
