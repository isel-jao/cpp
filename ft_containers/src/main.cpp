#include <iostream>
#include <vector>
#include <map>
// #include <string>
// #include <set>
// #include "map.hpp"
#include "utils.hpp"
#include "vector.hpp"

// #define LIB ft

#ifndef LIB
#define LIB std
#endif

int main()
{
	LIB::vector<int> w;
	LIB::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for (int i = 0; i < 10; i++)
		w.push_back(i * 10);

	print_container(v, "v");
	print_container(w, "w");

	std::cout << "----------------------------------------" << std::endl;
	v.insert(v.begin() + 2, w.begin() + 2, w.begin() + 6);
	std::cout << "v.insert(v.end(), w.begin() + 2, w.end() + 6);" << std::endl;
	print_container(v, "v");
	return 0;
}