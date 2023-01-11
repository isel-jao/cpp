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
	private:
		struct compare
		{
			Compare _comp;
			compare(Compare comp = Compare()) : _comp(comp) {}
			bool operator()(const ft::pair<Key, T> &lhs, const ft::pair<Key, T> &rhs) const
			{
				return (_comp(lhs.first, rhs.first));
			}
		};
		typedef AVL<ft::pair<Key, T>, compare> node_type;

	public:
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

		typedef typename AVL<ft::pair<key_type, mapped_type>, compare>::iterator iterator;
		typedef typename AVL<ft::pair<key_type, mapped_type>, compare>::const_iterator const_iterator;
		// typedef implementation - defined const_iterator;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		// typedef INSERT_RETURN_TYPE<iterator, node_type> insert_return_type;

		explicit map() : _tree() {}

		explicit map(const Compare &comp, const Allocator &alloc = Allocator()) : _tree(compare(comp), alloc) {}

		template <class InputIt>

		map(const map &other) : _tree(other._tree)
		{
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return (_tree.insert(value));
		}

		iterator find(const Key &key)
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		const_iterator find(const Key &key) const
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		size_type count(const Key &key) const
		{
			if (this->find(key) == this->end())
				return 0;
			return 1;
		}

		void clear() { _tree.clear(); }

		iterator begin() { return (_tree.begin()); }

		const_iterator begin() const { return (_tree.begin()); }

		iterator end() { return (_tree.end()); }

		const_iterator end() const { return (_tree.end()); }

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

		size_type size() const { return _tree.size(); }

		bool empty() const { return (_tree.size() == 1); }

	private:
		node_type _tree;
	};
}

#endif