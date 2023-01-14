#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "utils.hpp"
#include "avl.hpp"
#include <map>
#include <stack>
#include <vector>
#include <algorithm> // std::lexicographical_compare
#include <cctype>

#ifndef LIB
#define LIB ft
#endif

void print_test_header(std::string test_name)
{
	std::cout << "\033[0;36m testing:  < " << test_name << "> \033[0m" << std::endl;
}

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
	bool operator()(const char &lhs, const char &rhs) const { return lhs < rhs; }
};

bool mypredicate(int i, int j) { return (i == j); }

bool mycomp(char c1, char c2) { return std::tolower(c1) < std::tolower(c2); }

int main()
{
	// equal
	print_test_header("equal");
	try
	{
		int myints[] = {20, 40, 60, 80, 100};					//   myints: 20 40 60 80 100
		ft::vector<int> myvector(myints, myints + 5); // myvector: 20 40 60 80 100

		// using default comparison:
		if (ft::equal(myvector.begin(), myvector.end(), myints))
			std::cout << "The contents of both sequences are equal.\n";
		else
			std::cout << "The contents of both sequences differ.\n";

		myvector[3] = 81; // myvector: 20 40 60 81 100

		// using predicate comparison:
		if (ft::equal(myvector.begin(), myvector.end(), myints, mypredicate))
			std::cout << "The contents of both sequences are equal.\n";
		else
			std::cout << "The contents of both sequences differ.\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// lexicographical_compare
	print_test_header("lexicographical_compare");
	try
	{
		char foo[] = "Apple";
		char bar[] = "apartment";

		std::cout << std::boolalpha;

		std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

		std::cout << "Using default comparison (operator<): ";
		std::cout << LIB::lexicographical_compare(foo, foo + 5, bar, bar + 9);
		std::cout << '\n';

		std::cout << "Using mycomp as comparison object: ";
		std::cout << LIB::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp);
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	//  vector::vector
	print_test_header("vector::vector");
	try
	{
		LIB::vector<int> first;																// empty vector of ints
		LIB::vector<int> second(4, 100);											// four ints with value 100
		LIB::vector<int> third(second.begin(), second.end()); // iterating through second
		LIB::vector<int> fourth(third);												// a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16, 2, 77, 29};
		LIB::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

		std::cout << "The contents of fifth are:";
		for (LIB::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::assign
	print_test_header("vector::assign");
	try
	{
		LIB::vector<int> first;
		LIB::vector<int> second;
		LIB::vector<int> third;

		first.assign(7, 100); // 7 ints with a value of 100

		LIB::vector<int>::iterator it;
		it = first.begin() + 1;

		second.assign(it, first.end() - 1); // the 5 central values of first

		int myints[] = {1776, 7, 4};
		third.assign(myints, myints + 3); // assigning from array.

		std::cout << "Size of first: " << int(first.size()) << '\n';
		std::cout << "Size of second: " << int(second.size()) << '\n';
		std::cout << "Size of third: " << int(third.size()) << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::back
	print_test_header("vector::back");
	try
	{
		LIB::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back(myvector.back() - 1);
		}

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::begin
	print_test_header("vector::begin");
	try
	{
		LIB::vector<int> myvector;

		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);

		std::cout << "myvector contains:";
		for (LIB::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::capacity
	print_test_header("vector::capacity");
	try
	{
		LIB::vector<int> myvector;

		for (int i = 0; i < 100; i++)
			myvector.push_back(i);

		std::cout << "size: " << myvector.size() << '\n';
		std::cout << "capacity: " << myvector.capacity() << '\n';
		std::cout << "max_size: " << myvector.max_size() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::clear
	print_test_header("vector::clear");
	try
	{
		LIB::vector<int> myvector;
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);

		std::cout << "myvector contains:";
		for (LIB::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		myvector.clear();
		myvector.push_back(1101);
		myvector.push_back(2202);

		std::cout << "myvector contains:";
		for (LIB::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::empty
	print_test_header("vector::empty");
	try
	{
		LIB::vector<int> myvector;
		int sum(0);

		for (int i = 1; i <= 10; i++)
			myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "total: " << sum << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::end
	print_test_header("vector::end");
	try
	{
		LIB::vector<int> myvector;

		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);

		std::cout << "myvector contains:";
		for (LIB::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::erase
	print_test_header("vector::erase");
	try
	{
		LIB::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++)
			myvector.push_back(i);

		// erase the 6th element
		myvector.erase(myvector.begin() + 5);

		// erase the first 3 elements:
		myvector.erase(myvector.begin(), myvector.begin() + 3);

		std::cout << "myvector contains:";
		for (LIB::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::front
	print_test_header("vector::front");
	try
	{
		LIB::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::insert
	print_test_header("vector::insert");
	try
	{
		LIB::vector<int> myvector(3, 100);
		LIB::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert(it, 200);

		myvector.insert(it, 2, 300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		LIB::vector<int> anothervector(2, 400);
		myvector.insert(it + 2, anothervector.begin(), anothervector.end());

		int myarray[] = {501, 502, 503};
		myvector.insert(myvector.begin(), myarray, myarray + 3);

		std::cout << "myvector contains:";
		for (it = myvector.begin(); it < myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::max_size
	print_test_header("vector::max_size");
	try
	{
		LIB::vector<int> myvector;

		// set some content in the vector:
		for (int i = 0; i < 100; i++)
			myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::operator[]
	print_test_header("vector::operator[]");
	try
	{
		LIB::vector<int> myvector(10); // 10 zero-initialized elements

		LIB::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i = 0; i < sz; i++)
			myvector[i] = i;

		// reverse vector using operator[]:
		for (unsigned i = 0; i < sz / 2; i++)
		{
			int temp;
			temp = myvector[sz - 1 - i];
			myvector[sz - 1 - i] = myvector[i];
			myvector[i] = temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::operator=
	print_test_header("vector::operator=");
	try
	{
		LIB::vector<int> foo(3, 0);
		LIB::vector<int> bar(5, 0);

		bar = foo;
		foo = LIB::vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::pop_back
	print_test_header("vector::pop_back");
	try
	{
		LIB::vector<int> myvector;
		int sum(0);
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "The elements of myvector add up to " << sum << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::push_back
	print_test_header("vector::push_back");
	try
	{
		LIB::vector<int> myvector;

		myvector.push_back(0);
		myvector.push_back(1);
		myvector.push_back(2);
		myvector.push_back(4);
		myvector.push_back(9);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::rbegin
	print_test_header("vector::rbegin");
	try
	{
		LIB::vector<int> myvector(5); // 5 default-constructed ints

		int i = 0;

		LIB::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit != myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (LIB::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::rend
	print_test_header("vector::rend");
	try
	{
		LIB::vector<int> myvector;

		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);

		std::cout << "myvector contains:";
		for (LIB::vector<int>::reverse_iterator rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::reserve
	print_test_header("vector::reserve");
	try
	{
		LIB::vector<int>::size_type sz;

		LIB::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			foo.push_back(i);
			if (sz != foo.capacity())
			{
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}

		LIB::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100); // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			bar.push_back(i);
			if (sz != bar.capacity())
			{
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::resize
	print_test_header("vector::resize");
	try
	{
		LIB::vector<int> myvector;

		// set some initial content:
		for (int i = 1; i < 10; i++)
			myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8, 100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::size
	print_test_header("vector::size");
	try
	{
		LIB::vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i = 0; i < 10; i++)
			myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert(myints.end(), 10, 100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// vector::swap
	print_test_header("vector::swap");
	try
	{
		LIB::vector<int> foo(3, 100); // three ints with a value of 100
		LIB::vector<int> bar(5, 200); // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (LIB::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (LIB::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// relational operators (vector)
	print_test_header("relational operators (vector)");
	try
	{
		LIB::vector<int> foo(3, 100); // three ints with a value of 100
		LIB::vector<int> bar(2, 200); // two ints with a value of 200

		if (foo == bar)
			std::cout << "foo and bar are equal\n";
		if (foo != bar)
			std::cout << "foo and bar are not equal\n";
		if (foo < bar)
			std::cout << "foo is less than bar\n";
		if (foo > bar)
			std::cout << "foo is greater than bar\n";
		if (foo <= bar)
			std::cout << "foo is less than or equal to bar\n";
		if (foo >= bar)
			std::cout << "foo is greater than or equal to bar\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// swap (vector)
	print_test_header("swap (vector)");
	{
		LIB::vector<int> foo(3, 100); // three ints with a value of 100
		LIB::vector<int> bar(5, 200); // five ints with a value of 200

		swap(foo, bar);

		std::cout << "foo contains:";
		for (LIB::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (LIB::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	// map::map
	print_test_header("map::map");
	try
	{
		LIB::map<char, int> first;

		first['a'] = 10;
		first['b'] = 30;
		first['c'] = 50;
		first['d'] = 70;

		LIB::map<char, int> second(first.begin(), first.end());

		LIB::map<char, int> third(second);

		LIB::map<char, int, classcomp> fourth; // class as Compare

		bool (*fn_pt)(char, char) = fncomp;
		LIB::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare
		print_container(first, "first");
		print_container(second, "second");
		print_container(third, "third");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::begin
	print_test_header("map::begin");
	try
	{
		LIB::map<char, int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (LIB::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::clear
	print_test_header("map::clear");
	try
	{
		LIB::map<char, int> mymap;
		LIB::map<char, int>::iterator it;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		mymap.clear();
		mymap['a'] = 1101;
		mymap['b'] = 2202;

		std::cout << "mymap contains:\n";
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::count
	print_test_header("map::count");
	try
	{
		LIB::map<char, int> mymap;
		char c;

		mymap['a'] = 101;
		mymap['c'] = 202;
		mymap['f'] = 303;

		for (c = 'a'; c < 'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c) > 0)
				std::cout << " is an element of mymap.\n";
			else
				std::cout << " is not an element of mymap.\n";
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::empty
	print_test_header("map::empty");
	try
	{
		LIB::map<char, int> mymap;

		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;

		while (!mymap.empty())
		{
			std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
			mymap.erase(mymap.begin());
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::end
	print_test_header("map::end");
	try
	{
		LIB::map<char, int> mymap;

		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;

		std::cout << "mymap contains:\n";

		LIB::map<char, int>::iterator it = mymap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mymap.end() != ++it);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::equal_range
	print_test_header("map::equal_range");
	try
	{
		LIB::map<char, int> mymap;

		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;

		LIB::pair<LIB::map<char, int>::iterator, LIB::map<char, int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::erase
	print_test_header("map::erase");
	try
	{
		LIB::map<char, int> mymap;
		LIB::map<char, int>::iterator it;

		// insert some values:
		mymap['a'] = 10;
		mymap['b'] = 20;
		mymap['c'] = 30;
		mymap['d'] = 40;
		mymap['e'] = 50;
		mymap['f'] = 60;

		it = mymap.find('b');
		mymap.erase(it); // erasing by iterator

		mymap.erase('c'); // erasing by key

		it = mymap.find('e');
		mymap.erase(it, mymap.end()); // erasing by range

		// show content:
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::find
	print_test_header("map::find");
	try
	{
		LIB::map<char, int> mymap;
		LIB::map<char, int>::iterator it;

		mymap['a'] = 50;
		mymap['b'] = 100;
		mymap['c'] = 150;
		mymap['d'] = 200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase(it);

		// print content:
		std::cout << "elements in mymap:" << '\n';
		std::cout << "a => " << mymap.find('a')->second << '\n';
		std::cout << "c => " << mymap.find('c')->second << '\n';
		std::cout << "d => " << mymap.find('d')->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::get_allocator
	print_test_header("map::get_allocator");
	try
	{
		int psize;
		LIB::map<char, int> mymap;
		LIB::pair<const char, int> *p;

		// allocate an array of 5 elements using mymap's allocator:
		p = mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(LIB::map<char, int>::value_type) * 5;

		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p, 5);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::insert
	print_test_header("map::insert");
	try
	{
		LIB::map<char, int> mymap;

		// first insert function version (single parameter):
		mymap.insert(LIB::pair<char, int>('a', 100));
		mymap.insert(LIB::pair<char, int>('z', 200));

		LIB::pair<LIB::map<char, int>::iterator, bool> ret;
		ret = mymap.insert(LIB::pair<char, int>('z', 500));
		if (ret.second == false)
		{
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		LIB::map<char, int>::iterator it = mymap.begin();
		mymap.insert(it, LIB::pair<char, int>('b', 300)); // max efficiency inserting
		mymap.insert(it, LIB::pair<char, int>('c', 400)); // no max efficiency inserting

		// third insert function version (range insertion):
		LIB::map<char, int> anothermap;
		anothermap.insert(mymap.begin(), mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "anothermap contains:\n";
		for (it = anothermap.begin(); it != anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::key_comp
	print_test_header("map::key_comp");
	try
	{
		LIB::map<char, int> mymap;

		LIB::map<char, int>::key_compare mycomp = mymap.key_comp();

		mymap['a'] = 100;
		mymap['b'] = 200;
		mymap['c'] = 300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first; // key value of last element

		LIB::map<char, int>::iterator it = mymap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mycomp((*it++).first, highest));

		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::lower_bound
	print_test_header("map::lower_bound");
	try
	{
		LIB::map<char, int> mymap;
		LIB::map<char, int>::iterator itlow, itup;

		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;

		itlow = mymap.lower_bound('b'); // itlow points to b
		itup = mymap.upper_bound('d');	// itup points to e (not d!)

		mymap.erase(itlow, itup); // erases [itlow,itup)

		// // print content:
		for (LIB::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::max_size
	print_test_header("map::max_size");
	try
	{
		LIB::map<char, int> mymap;

		if (mymap.max_size() > 1000)
		{
			for (int i = 0; i < 1000; i++)
				mymap['a' + i] = i;
			std::cout << "The map contains 1000 elements.\n";
		}
		else
			std::cout << "The map could not hold 1000 elements.\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::operator[]
	print_test_header("map::operator[]");
	try
	{
		LIB::map<char, std::string> mymap;

		mymap['a'] = "an element";
		mymap['b'] = "another element";
		mymap['c'] = mymap['b'];

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';
		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::operator=
	print_test_header("map::operator=");
	try
	{
		LIB::map<char, int> first;
		LIB::map<char, int> second;

		first['x'] = 8;
		first['y'] = 16;
		first['z'] = 32;

		second = first;								 // second now contains 3 ints
		first = LIB::map<char, int>(); // and first is now empty

		std::cout << "Size of first: " << int(first.size()) << '\n';
		std::cout << "Size of second: " << int(second.size()) << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::rbegin
	print_test_header("map::rbegin");
	try
	{
		LIB::map<char, int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		std::cout << "mymap contains:\n";

		LIB::map<char, int>::reverse_iterator rit = mymap.rbegin();
		for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::rend
	print_test_header("map::rend");
	try
	{
		LIB::map<char, int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		std::cout << "mymap contains:\n";

		LIB::map<char, int>::reverse_iterator rit = mymap.rbegin();
		for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::size
	print_test_header("map::size");
	try
	{
		LIB::map<char, std::string> mymap;

		mymap['a'] = "an element";
		mymap['b'] = "another element";
		mymap['c'] = mymap['b'];

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::swap
	print_test_header("map::swap");
	try
	{
		LIB::map<char, int> foo, bar;

		foo['x'] = 100;
		foo['y'] = 200;

		bar['a'] = 11;
		bar['b'] = 22;
		bar['c'] = 33;

		foo.swap(bar);

		std::cout << "foo contains:\n";
		for (LIB::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (LIB::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::upper_bound
	print_test_header("map::upper_bound");
	try
	{
		LIB::map<char, int> mymap;
		LIB::map<char, int>::iterator itlow, itup;

		mymap['a'] = 20;
		mymap['b'] = 40;
		mymap['c'] = 60;
		mymap['d'] = 80;
		mymap['e'] = 100;

		itlow = mymap.lower_bound('b'); // itlow points to b
		itup = mymap.upper_bound('d');	// itup points to e (not d!)

		mymap.erase(itlow, itup); // erases [itlow,itup)

		// print content:
		for (LIB::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// map::value_comp
	print_test_header("map::value_comp");
	try
	{
		LIB::map<char, int> mymap;

		mymap['x'] = 1001;
		mymap['y'] = 2002;
		mymap['z'] = 3003;

		std::cout << "mymap contains:\n";

		LIB::pair<char, int> highest = *mymap.rbegin(); // last element

		LIB::map<char, int>::iterator it = mymap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mymap.value_comp()(*it++, highest));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// relational operators (map)
	print_test_header("relational operators (map)");
	try
	{
		LIB::map<char, int> foo, bar;
		foo['a'] = 100;
		foo['b'] = 200;
		bar['a'] = 10;
		bar['z'] = 1000;

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo == bar)
			std::cout << "foo and bar are equal\n";
		if (foo != bar)
			std::cout << "foo and bar are not equal\n";
		if (foo < bar)
			std::cout << "foo is less than bar\n";
		if (foo > bar)
			std::cout << "foo is greater than bar\n";
		if (foo <= bar)
			std::cout << "foo is less than or equal to bar\n";
		if (foo >= bar)
			std::cout << "foo is greater than or equal to bar\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// swap (map)
	print_test_header("swap (map)");
	try
	{
		LIB::map<char, int> foo, bar;

		foo['x'] = 100;
		foo['y'] = 200;

		bar['a'] = 11;
		bar['b'] = 22;
		bar['c'] = 33;

		swap(foo, bar);

		std::cout << "foo contains:\n";
		for (LIB::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (LIB::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::stack
	print_test_header("stack::stack");
	try
	{
		std::deque<int> mydeque(3, 100);	 // deque with 3 elements
		LIB::vector<int> myvector(2, 200); // vector with 2 elements

		LIB::stack<int> first;					 // empty stack
		LIB::stack<int, std::deque<int> > second(mydeque); // stack initialized to copy of deque

		std::stack<int, LIB::vector<int> > third; // empty stack using vector
		LIB::stack<int, LIB::vector<int> > fourth(myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::empty
	print_test_header("stack::empty");
	try
	{
		LIB::stack<int> mystack;
		int sum(0);

		for (int i = 1; i <= 10; i++)
			mystack.push(i);

		while (!mystack.empty())
		{
	print_test_header("stack::stack");
	try
	{
		std::deque<int> mydeque(3, 100);	 // deque with 3 elements
		LIB::vector<int> myvector(2, 200); // vector with 2 elements

		LIB::stack<int> first;					 // empty stack
		LIB::stack<int, std::deque<int> > second(mydeque); // stack initialized to copy of deque

		std::stack<int, LIB::vector<int> > third; // empty stack using vector
		LIB::stack<int, LIB::vector<int> > fourth(myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::empty
	print_test_header("stack::empty");
	try
	{
		LIB::stack<int> mystack;
		int sum(0);

		for (int i = 1; i <= 10; i++)
			mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::pop
	print_test_header("stack::pop");
	try
	{
		LIB::stack<int> mystack;

		for (int i = 0; i < 5; ++i)
			mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::push
	print_test_header("stack::push");
	try
	{
		LIB::stack<int> mystack;

		for (int i = 0; i < 5; ++i)
			mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::size
	print_test_header("stack::size");
	try
	{
		LIB::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i = 0; i < 5; i++)
			myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::top
	print_test_header("stack::top");
	try
	{
		LIB::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::pop
	print_test_header("stack::pop");
	try
	{
		LIB::stack<int> mystack;

		for (int i = 0; i < 5; ++i)
			mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::push
	print_test_header("stack::push");
	try
	{
		LIB::stack<int> mystack;

		for (int i = 0; i < 5; ++i)
			mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::size
	print_test_header("stack::size");
	try
	{
		LIB::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i = 0; i < 5; i++)
			myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// stack::top
	print_test_header("stack::top");
	try
	{
		LIB::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}