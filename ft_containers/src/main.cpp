#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "map.hpp"
#include "utils.hpp"
#include "vector.hpp"

// #define LIB ft

#ifndef LIB
#define LIB std
#endif

int main()
{

	AVL<int> avl;

	LIB::pair<AVL<int>::iterator, bool> p = avl.insert(1);

	print_container(avl);

	// std::cout << std::boolalpha << (p1 == p2) << std::endl;

	return 0;
}