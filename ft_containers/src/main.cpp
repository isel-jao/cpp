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

	return 0;
}