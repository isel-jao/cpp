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
		vector &operator=(const vector &rhs)
		{
			if (this != &rhs)
				assign(rhs.begin(), rhs.end());
			return (*this);
		}
		~vector()
		{
			this->clear();
		}

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

		void push_back(const value_type &val)
		{
			if (_capacity == 0)
				reserve(1);
			else if (_size == _capacity)
				reserve(_capacity * 2);
			_alloc.construct(&_data[_size], val);
			_size++;
		}

		void pop_back()
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}

		iterator begin() { return iterator(_data); }
		const_iterator begin() const { return const_iterator(_data); }
		iterator end() { return iterator(_data + _size); }
		const_iterator end() const { return const_iterator(_data + _size); }

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_alloc.deallocate(_data, _capacity);
			_size = 0;
			_capacity = 0;
			_data = NULL;
		}

		size_type size() const { return _size; }
		size_type capacity() const { return _capacity; }
		bool empty() const { return _size == 0; }
		size_type max_size() const { return _alloc.max_size(); }

		allocator_type get_allocator() const { return _alloc; }

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

		reference operator[](size_type n) { return (_data[n]); }

		const_reference operator[](size_type n) const { return (_data[n]); }

		void resize(size_type count, T value = T())
		{
			if (count > _size)
			{
				reserve(count);
				for (size_type i = _size; i < count; i++)
					_alloc.construct(&_data[i], value);
				_capacity = count;
			}
			else
			{
				for (size_type i = count; i < _size; i++)
					_alloc.destroy(&_data[i]);
			}
			_size = count;
		}
		reference front()
		{
			return _data[0];
		}
		const_reference front() const
		{
			return _data[0];
		}
		reference back()
		{
			return _data[_size - 1];
		}
		const_reference back() const
		{
			return _data[_size - 1];
		}

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

	private:
		allocator_type _alloc;
		pointer _data;
		size_type _size;
		size_type _capacity;
	};
}

#endif