#ifndef AVL_HPP
#define AVL_HPP

#include <functional>
#include "iterator.hpp"
#include "utils.hpp"

template <typename T>
struct Node
{
	T _data;
	typedef T data_type;
	typedef Node<T> node_type;
	typedef Node<T> *node_pointer;
	node_pointer _parent;
	node_pointer _left;
	node_pointer _right;
	unsigned long _height;

	Node(T data = T(), Node<T> *parent = NULL, Node<T> *left = NULL, Node<T> *right = NULL)
			: _data(data), _parent(parent), _left(left), _right(right), _height(0) {}

	~Node() {}
};

template <typename T>
void print2D(Node<T> *root, int space)
{
	if (root == NULL)
		return;
	space += 7;
	print2D(root->_right, space);
	std::cout << std::endl;
	for (int i = 7; i < space; i++)
		std::cout << " ";
	std::cout << root->_data << "/" << root->_height;
	if (root->_parent)
		std::cout << "/" << root->_parent->_data;
	else
		std::cout << "/NULL";
	std::cout << std::endl;
	std::cout << std::endl;
	print2D(root->_left, space);
}

template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<Node<T> > >
class AVL
{
public:
	typedef T value_type;
	typedef Node<T> node_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;							// Node<T>&
	typedef typename allocator_type::const_reference const_reference; // const Node<T>&
	typedef typename allocator_type::pointer pointer;									// Node<T>*
	typedef typename allocator_type::const_pointer const_pointer;			// const Node<T>*
	typedef typename allocator_type::size_type size_type;

	typedef ft::BST_iterator<value_type, node_type> iterator;
	typedef ft::BST_iterator<value_type, node_type> const_iterator;
	typedef ft::BST_reverse_iterator<value_type, node_type> reverse_iterator;
	typedef ft::BST_reverse_iterator<value_type, node_type> const_reverse_iterator;

private:
	allocator_type _alloc;
	pointer _root;
	key_compare _comp;
	size_type _size;

public:
	AVL(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _root(), _comp(comp), _size(0)
	{
	}
	AVL(const AVL &x) : _alloc(x._alloc), _root(), _comp(x._comp), _size(x._size)
	{
		*this = x;
	}

	AVL &operator=(const AVL &x)
	{
		if (this != &x)
		{
			this->clear();
			_comp = x._comp;
			_alloc = x._alloc;
			_size = x._size;
			_root = this->clone(x._root);
		}
		return *this;
	}

	~AVL()
	{
		this->clear();
	}

	iterator find(const value_type &data)
	{
		pointer node = _root;
		while (node)
		{
			if (_comp(data, node->_data))
				node = node->_left;
			else if (_comp(node->_data, data))
				node = node->_right;
			else
				return iterator(node);
		}
		return end();
	}

	const_iterator find(const value_type &data) const
	{
		pointer node = _root;
		while (node)
		{
			if (_comp(data, node->_data))
				node = node->_left;
			else if (_comp(node->_data, data))
				node = node->_right;
			else
				return const_iterator(node);
		}
		return end();
	}

	allocator_type get_allocator() const { return _alloc; }

	iterator begin()
	{
		pointer min = minValue(_root);
		return iterator(min);
	}

	iterator end()
	{
		return iterator(NULL);
	}

	const_iterator begin() const
	{
		pointer min = minValue(_root);
		return const_iterator(min);
	}

	const_iterator end() const
	{
		return const_iterator(NULL);
	}

	reverse_iterator rbegin()
	{
		pointer max = maxValue(_root);
		return reverse_iterator(max);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(NULL);
	}

	const_reverse_iterator rbegin() const
	{
		pointer max = maxValue(_root);
		return const_reverse_iterator(max);
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(NULL);
	}

	void
	print()
	{
		print2D(_root, 0);
	}
	ft::pair<iterator, bool> insert(const value_type &data)
	{
		bool inserted = false;
		iterator it = end();
		_root = insert(_root, data, NULL, inserted, it);

		return ft::pair<iterator, bool>(it, inserted);
	}
	size_type erase(const value_type &data)
	{
		size_type erased = 0;
		_root = erase(_root, data, erased);
		return erased;
	}

	void clear()
	{
		clear(_root);
		this->_root = NULL;
		this->_size = 0;
	}

	size_type size() const { return this->_size; }
	iterator lower_bound(const value_type &data)
	{
		pointer node = _root;
		pointer min = NULL;
		while (node)
		{
			if (_comp(data, node->_data))
			{
				min = node;
				node = node->_left;
			}
			else if (_comp(node->_data, data))
				node = node->_right;
			else
				return iterator(node);
		}
		return iterator(min);
	}

	const_iterator lower_bound(const value_type &data) const
	{
		pointer node = _root;
		pointer min = NULL;
		while (node)
		{
			if (_comp(data, node->_data))
			{
				min = node;
				node = node->_left;
			}
			else if (_comp(node->_data, data))
				node = node->_right;
			else
				return const_iterator(node);
		}
		return const_iterator(min);
	}

	iterator upper_bound(const value_type &data)
	{
		pointer node = _root;
		pointer max = NULL;
		while (node)
		{
			if (_comp(data, node->_data))
				node = node->_left;
			else if (_comp(node->_data, data))
			{
				max = node;
				node = node->_right;
			}
			else
				return ++iterator(node);
		}
		return ++iterator(max);
	}

	const_iterator upper_bound(const value_type &data) const
	{
		pointer node = _root;
		pointer max = NULL;
		while (node)
		{
			if (_comp(data, node->_data))
				node = node->_left;
			else if (_comp(node->_data, data))
			{
				max = node;
				node = node->_right;
			}
			else
				return ++const_iterator(node);
		}
		return ++const_iterator(max);
	}
	size_type max_size() const { return _alloc.max_size(); }

	void swap(AVL &x)
	{
		pointer tmp = x._root;
		x._root = this->_root;
		this->_root = tmp;

		size_type tmp2 = x._size;
		x._size = this->_size;
		this->_size = tmp2;
	}

	friend bool operator==(const AVL &lhs, const AVL &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	friend bool operator!=(const AVL &lhs, const AVL &rhs)
	{
		return !(lhs == rhs);
	}

	friend bool operator<(const AVL &lhs, const AVL &rhs)
	{

		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	friend bool operator<=(const AVL &lhs, const AVL &rhs)
	{
		return !(rhs < lhs);
	}

	friend bool operator>(const AVL &lhs, const AVL &rhs)
	{
		return rhs < lhs;
	}

	friend bool operator>=(const AVL &lhs, const AVL &rhs)
	{
		return !(lhs < rhs);
	}
private:
	void
	clear(pointer node)
	{
		if (node)
		{
			clear(node->_left);
			clear(node->_right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
	}

	pointer clone(pointer node, pointer p = NULL)
	{
		if (node)
		{
			pointer n = _alloc.allocate(1);
			_alloc.construct(n, node->_data);
			n->_parent = p;
			n->_left = clone(node->_left, n);
			n->_right = clone(node->_right, n);
			n->_height = node->_height;
			return n;
		}
		return NULL;
	}

	int calheight(pointer p)
	{
		if (!p)
			return -1;
		if (p->_left && p->_right)
		{
			if (p->_left->_height < p->_right->_height)
				return p->_right->_height + 1;
			else
				return p->_left->_height + 1;
		}
		else if (p->_left && p->_right == NULL)
		{
			return p->_left->_height + 1;
		}
		else if (p->_left == NULL && p->_right)
		{
			return p->_right->_height + 1;
		}
		return 0;
	}

	int balanceFactor(pointer n)
	{
		if (n == NULL)
			return -1;
		if (n->_left && n->_right)
		{
			return n->_left->_height - n->_right->_height;
		}
		else if (n->_left && n->_right == NULL)
		{
			return n->_left->_height + 1;
		}
		else if (n->_left == NULL && n->_right)
		{
			return -n->_right->_height - 1;
		}
		return 0;
	}

	pointer ll_rotate(pointer x)
	{
		pointer p = x->_parent;
		pointer y = x->_left;
		pointer b = y->_right;
		if (p)
		{
			if (p->_left == x)
				p->_left = y;
			else
				p->_right = y;
		}
		y->_parent = p;
		y->_right = x;
		x->_parent = y;
		x->_left = b;
		if (b)
			b->_parent = x;
		x->_height = calheight(x);
		y->_height = calheight(y);
		return y;
	}

	pointer rr_rotate(pointer x)
	{
		pointer p = x->_parent;
		pointer y = x->_right;
		pointer b = y->_left;
		if (p)
		{
			if (p->_left == x)
				p->_left = y;
			else
				p->_right = y;
		}
		y->_parent = p;
		y->_left = x;
		x->_parent = y;
		x->_right = b;
		if (b)
			b->_parent = x;
		x->_height = calheight(x);
		y->_height = calheight(y);
		return y;
	}

	pointer lr_rotate(pointer x)
	{
		x->_left = rr_rotate(x->_left);
		return ll_rotate(x);
	}

	pointer rl_rotate(pointer x)
	{
		x->_right = ll_rotate(x->_right);
		return rr_rotate(x);
	}

	pointer balance(node_type *r)
	{
		if (r == NULL)
			return r;
		if (balanceFactor(r) == 2)
		{
			if (balanceFactor(r->_left) == 1)
				return ll_rotate(r);
			else
				return lr_rotate(r);
		}
		if (balanceFactor(r) == -2)
		{
			if (balanceFactor(r->_right) == -1)
				return rr_rotate(r);
			else
				return rl_rotate(r);
		}
		return r;
	}

	pointer insert(pointer root, const value_type &data, pointer parent, bool &inserted, iterator &it)
	{
		if (root == NULL)
		{
			root = _alloc.allocate(1);
			_alloc.construct(root, data);
			root->_parent = parent;
			_size++;
			inserted = true;
			it = iterator(root);
		}
		else if (_comp(data, root->_data))
			root->_left = insert(root->_left, data, root, inserted, it);
		else if (_comp(root->_data, data))
			root->_right = insert(root->_right, data, root, inserted, it);
		else
		{
			it = iterator(root);
			return root;
		}
		root->_height = calheight(root);
		root = balance(root);
		return root;
	}

	pointer minValue(pointer node) const
	{
		pointer current = node;
		while (current && current->_left != NULL)
			current = current->_left;
		return current;
	}
	pointer maxValue(pointer node) const
	{
		pointer current = node;
		while (current && current->_right != NULL)
			current = current->_right;
		return current;
	}

	pointer erase(pointer root, const value_type &data, size_type &count)
	{
		if (root == NULL)
			return root;
		if (_comp(data, root->_data))
			root->_left = erase(root->_left, data, count);
		else if (_comp(root->_data, data))
			root->_right = erase(root->_right, data, count);
		else
		{
			if (root->_left == NULL && root->_right == NULL)
			{
				_alloc.destroy(root);
				_alloc.deallocate(root, 1);
				root = NULL;
				_size--;
			}
			else if (root->_left == NULL)
			{
				pointer temp = root;
				root = root->_right;
				root->_parent = temp->_parent;
				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
				_size--;
			}
			else if (root->_right == NULL)
			{
				pointer temp = root;
				root = root->_left;
				root->_parent = temp->_parent;
				_alloc.destroy(temp);
				_alloc.deallocate(temp, 1);
				_size--;
			}
			else
			{
				pointer temp = minValue(root->_right);
				root->_data = temp->_data;
				root->_right = erase(root->_right, temp->_data, count);
			}
			count = 1;
		}
		if (root == NULL)
			return root;
		root->_height = calheight(root);
		return balance(root);
	}
};

#endif