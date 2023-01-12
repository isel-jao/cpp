#include <iostream>
#include <vector>
#include <map>
// #include <string>
// #include <set>
// #include "map.hpp"
// #include "utils.hpp"
#include "vector.hpp"

#define LIB ft

#ifndef LIB
#define LIB std
#endif

int main()
{
	std::vector<int> myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8, 100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	return 0;

	return 0;
}