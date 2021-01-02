#ifndef ACRUSH_STANDARDLIBRARY_H
#define ACRUSH_STANDARDLIBRARY_H

#include <algorithm>
#include <assert.h>

#include <climits>
#include <numeric>
#include <random>

// STL container
#include <vector>
#include <list>

#include <stack>
#include <queue> // priority_queue
#include <deque>

#include <unordered_map>
#include <unordered_set> // hash table with O(1) lookup
#include <set> // avl tree with O(lgn) lookup, also sort items in order

#include <memory>

#include <string>
#include <sstream>

// file IO
#include <iostream>
#include <fstream>

#include <functional>

#include <optional>

// console log in color
std::ostream& cout_red(const std::string &msg);

std::ostream& cout_green(const std::string &msg);

std::ostream& cout_blue(const std::string &msg);

std::ostream& cout_magenta(const std::string &msg);

std::ostream& cout_cyan(const std::string &msg);

// ToDo: helper function to print array, linked list, tree and graph etc.

#endif //ACRUSH_STANDARDLIBRARY_H
