#ifndef MAP_HPP
#define MAP_HPP

#include "avl.hpp"
#include "utils.hpp"

namespace ft
{

	template <
			class Key,
			class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<Key, T>>>
	class map
	{

	public:
		struct value_compare
		{
			Compare _comp;
			value_compare(Compare comp = Compare()) : _comp(comp) {}
			bool operator()(const ft::pair<Key, T> &lhs, const ft::pair<Key, T> &rhs) const
			{
				return (_comp(lhs.first, rhs.first));
			}
		};

		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;

		typedef typename AVL<ft::pair<key_type, mapped_type>, value_compare>::iterator iterator;
		typedef typename AVL<ft::pair<key_type, mapped_type>, value_compare>::const_iterator const_iterator;
		typedef typename AVL<ft::pair<key_type, mapped_type>, value_compare>::reverse_iterator reverse_iterator;
		typedef typename AVL<ft::pair<key_type, mapped_type>, value_compare>::const_reverse_iterator const_reverse_iterator;

		explicit map() : _tree() {}

		explicit map(const Compare &comp, const Allocator &alloc = Allocator()) : _tree(value_compare(comp), alloc), _comp(comp) {}

		template <class InputIt>

		map(const map &other)
		{
			*this = other;
		}

		~map()
		{
			_tree.clear();
		}
		/////////////////////////// operators overload ///////////////////////////
		mapped_type &operator[](const key_type &key)
		{
			iterator it = _tree.find(key);
			if (it == _tree.end())
			{
				_tree.insert(ft::make_pair(key, mapped_type()));
				it = _tree.find(key);
			}
			return (it->second);
		}

		////////////////// mumber fuctions in alphabetical order //////////////////
		iterator begin() { return (_tree.begin()); }

		const_iterator begin() const { return (_tree.begin()); }

		void clear() { _tree.clear(); }

		size_type count(const Key &key) const { return (this->find(key) == this->end() ? 0 : 1); }

		bool empty() const { return (_tree.size() == 1); }

		iterator end() { return (_tree.end()); }

		const_iterator end() const { return (_tree.end()); }

		ft::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		void erase(iterator position) { _tree.erase(*position); }

		size_type erase(const key_type &k) { return (_tree.erase(ft::make_pair(k, mapped_type()))); }

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp = first;
				++first;
				_tree.erase(*tmp);
			}
		}
		iterator find(const key_type &key)
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		const_iterator find(const key_type &key) const
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}
		allocator_type get_allocator() const { return (_tree.get_allocator()); }

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return (_tree.insert(value));
		}

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return (_tree.insert(val).first);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_tree.insert(*first);
				++first;
			}
		}

		key_compare key_comp() const { return (_comp); }

		iterator lower_bound(const key_type &k)
		{
			return (_tree.lower_bound(ft::make_pair(k, mapped_type())));
		}

		const_iterator lower_bound(const key_type &k) const
		{
			return (_tree.lower_bound(ft::make_pair(k, mapped_type())));
		}

		size_type max_size() const { return (_tree.max_size()); }

		reverse_iterator rbegin() { return (_tree.rbegin()); }
		const_reverse_iterator rbegin() const { return (_tree.rbegin()); }

		reverse_iterator rend() { return (_tree.rend()); }

		const_reverse_iterator rend() const { return (_tree.rend()); }

		size_type size() const { return _tree.size(); }

		void swap(map &x) { _tree.swap(x._tree); }

		iterator upper_bound(const key_type &k)
		{
			return (_tree.upper_bound(ft::make_pair(k, mapped_type())));
		}

		const_iterator upper_bound(const key_type &k) const
		{
			return (_tree.upper_bound(ft::make_pair(k, mapped_type())));
		}

		value_compare value_comp() const
		{
			return value_compare(_comp);
		}

	protected:
		typedef AVL<ft::pair<Key, T>, value_compare> bst_tree;
		bst_tree _tree;
		key_compare _comp;
	};
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	// {
	// 	return (lhs._tree == rhs._tree);
	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	// {
	// 	return (lhs._tree != rhs._tree);
	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	// {
	// 	return (lhs._tree < rhs._tree);
	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	// {
	// 	return (lhs._tree <= rhs._tree);
	// }

	// template <class Key, class T, class Compare, class Alloc>
	// bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	// {
	// 	return (lhs._tree > rhs._tree);
	// }
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)

	// {
	// 	return (lhs._tree >= rhs._tree);
	// }
}

#endif
