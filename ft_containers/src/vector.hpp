#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include "iterator.hpp"
#include "type_traits.hpp"
namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::vector_random_access_iterator<value_type> iterator;
		typedef ft::vector_random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;

		explicit vector(const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _data(NULL), _size(0), _capacity(0) {}

		explicit vector(size_type n, const value_type &val = value_type(),
										const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _size(0), _capacity(0), _data(NULL) { assign(n, val); }

		template <class InputIt>
		vector(InputIt first, InputIt last,
					 const Allocator &alloc = Allocator())
		{
			_alloc = alloc;
			_size = 0;
			_capacity = 0;
			_data = NULL;
			assign(first, last);
		}

		vector(const vector &x)
		{
			_alloc = x._alloc;
			_size = 0;
			_capacity = 0;
			_data = NULL;
			assign(x.begin(), x.end());
		}

		~vector()
		{
			this->clear();
		}

		//////////////////////////// mumber overloads ////////////////////////////
		reference operator[](size_type n) { return (_data[n]); }

		const_reference operator[](size_type n) const { return (_data[n]); }
		vector &operator=(const vector &rhs)
		{
			if (this != &rhs)
				assign(rhs.begin(), rhs.end());
			return (*this);
		}

		////////////////// mumber fuctions in alphabetical order //////////////////
		template <class InputIt>
		void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = 0)
		{
			pointer tmp;
			size_type n = 0;
			for (InputIt it = first; it != last; it++)
				n++;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			if (n > _capacity)
			{
				tmp = _alloc.allocate(n);
				_alloc.deallocate(_data, _capacity);
				_data = tmp;
				_capacity = n;
			}
			_size = 0;
			for (InputIt it = first; it != last; it++)
			{
				_alloc.construct(&_data[_size], *it);
				_size++;
			}
		}

		void assign(size_type n, const value_type &val)
		{
			pointer tmp;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			if (n > _capacity)
			{
				tmp = _alloc.allocate(n);
				_alloc.deallocate(_data, _capacity);
				_data = tmp;
				_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_data[i], val);
			_size = n;
		}

		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return _data[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return _data[n];
		}

		reference back() { return _data[_size - 1]; }
		const_reference back() const { return _data[_size - 1]; }

		iterator begin() { return iterator(_data); }

		const_iterator begin() const { return const_iterator(_data); }

		size_type capacity() const { return _capacity; }

		void clear()
		{
			if (_data == NULL)
				return;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_alloc.deallocate(_data, _capacity);
			_size = 0;
			_capacity = 0;
			_data = NULL;
		}
		bool empty() const { return _size == 0; }

		iterator end() { return iterator(_data + _size); }

		const_iterator end() const { return const_iterator(_data + _size); }

		iterator erase(iterator pos)
		{
			if (pos == this->end() - 1)
			{
				_alloc.destroy(&(*pos));
			}
			else
			{
				iterator it = pos;
				while (it != end() - 1)
				{
					_alloc.destroy(&(*it));
					_alloc.construct(&(*it), *(it + 1));
					it++;
				}
				_alloc.destroy(&(*it));
			}
			_size--;
			return iterator(pos);
		}

		reference front() { return _data[0]; }

		const_reference front() const { return _data[0]; }

		allocator_type get_allocator() const { return _alloc; }

		iterator insert(iterator position, const value_type &val)
		{
			difference_type diff = position - begin();
			if (diff < 0)
				throw std::out_of_range("vector");
			this->reserve(this->_size + 1);
			this->_size += 1;
			difference_type i = size();
			while (--i >= 0)
			{
				if (i == diff)
				{
					this->_alloc.construct(&this->_data[i], val);
					break;
				}
				this->_alloc.construct(&this->_data[i], this->_data[i - 1]);
			}
			return (iterator(this->_data + diff));
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			std::cout << "end - position " << this->end() - position << std::endl;
			if (_size + n > _capacity)
				reserve(_size + n);
			if (position == end())
			{
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(&(*position), val);
					position++;
				}
			}
			else
			{
				std::cout << &(*position) << std::endl;
				std::cout << "end - begin " << &(*this->end()) - &*(this->begin()) << std::endl;
				// while (it > position)
				// {
				// 	// _alloc.construct(&(*(it)), *(it - 1));
				// 	std::cout << "it: " << *it << std::endl;
				// 	it--;
				// }

				// for (size_type i = 0; i < n; i++)
				// {
				// 	_alloc.destroy(&(*position));
				// 	_alloc.construct(&(*position), val);
				// 	std::cout << "position" << *position << std::endl;
				// 	position++;
				// }
			}
			_size += n;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			size_type n = 0;
			for (InputIterator it = first; it != last; it++)
				n++;
			if (_size + n > _capacity)
				reserve(_size + n);
			if (position == end())
			{
				for (InputIterator it = first; it != last; it++)
				{
					_alloc.construct(&(*position), *it);
					position++;
				}
				_size += n;
			}
			else
			{
				iterator it = end();
				for (size_type i = 1; i <= n; i++)
					_alloc.construct(&(*(it + n - i)), *(it - i));
				for (size_type i = 0; i < n; i++)
				{
					_alloc.destroy(&(*position));
					_alloc.construct(&(*position), *first);
					position++;
					first++;
				}
				_size += n;
			}
		}

		void pop_back()
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}

		void push_back(const value_type &val)
		{
			if (_capacity == 0)
				reserve(1);
			else if (_size == _capacity)
				reserve(_capacity * 2);
			_alloc.construct(&_data[_size], val);
			_size++;
		}

		reverse_iterator rbegin() { return reverse_iterator(end()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		void reserve(size_type n)
		{
			if (n <= _capacity)
				return;
			pointer tmp = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&tmp[i], _data[i]);
				_alloc.destroy(&_data[i]);
			}
			if (_capacity > 0)
				_alloc.deallocate(_data, _capacity);
			_data = tmp;
			_capacity = n;
		}

		void resize(size_type count, T value = T())
		{
			if (count > _capacity)
			{
				reserve(count);
				for (size_type i = _size; i < count; i++)
					_alloc.construct(&_data[i], value);
				_capacity = count;
			}
			else if (count > _size)
			{
				for (size_type i = _size; i < count; i++)
					_alloc.construct(&_data[i], value);
			}
			else if (count < _size)
			{
				for (size_type i = count; i < _size; i++)
					_alloc.destroy(&_data[i]);
			}
			_size = count;
		}

		size_type max_size() const { return _alloc.max_size(); }

		size_type size() const { return _size; }

		void swap(vector &x)
		{
			pointer tmp = _data;
			_data = x._data;
			x._data = tmp;
			size_type tmp2 = _size;
			_size = x._size;
			x._size = tmp2;
			tmp2 = _capacity;
			_capacity = x._capacity;
			x._capacity = tmp2;
		}

	private:
		allocator_type _alloc;
		pointer _data;
		size_type _size;
		size_type _capacity;
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return true;
			else
				return false;
		}
		return lhs.size() < rhs.size();
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return true;
			else
				return false;
		}
		return lhs.size() > rhs.size();
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}

#endif