#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include "map.hpp"
#include "utils.hpp"
#include "vector.hpp"

#define LIB ft

#ifndef LIB
#define LIB std
#endif

int main()
{
	LIB::map<int, int> m;

	// m.insert(LIB::pair<int, int>(1, 1));
	// m.insert(LIB::pair<int, int>(2, 2));
	// m.insert(LIB::pair<int, int>(3, 3));
	// m.insert(LIB::pair<int, int>(1337, 3));

	std::cout << m.empty() << std::endl;
	// std::cout << it->first << std::endl;

	return 0;
}