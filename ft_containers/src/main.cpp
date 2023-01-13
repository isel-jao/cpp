#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "utils.hpp"
#include <map>
#include <stack>
#include <vector>

#ifndef LIB
#define LIB ft
#endif

void print_test_header(std::string test_name)
{
	std::cout << "\033[0;36m testing:  < " << test_name << "> \033[0m" << std::endl;
}

int main()
{
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

	return 0;
}