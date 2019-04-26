#include <iostream>
#include "type_utilities.hpp"

struct A {

};
class B {

};

namespace example {

class C {

};
}
using namespace type_utilities;
using namespace example;

int main() {
	std::cout << type_name<A>() << "\n";
	std::cout << type_name<B>() << "\n";
  std::cout << type_name<C>() << "\n";
	std::cout << type_name<uint64_t>() << "\n";
	std::cout << type_name<uint32_t>() << "\n";
	std::cout << type_name<const unsigned short>() << "\n";
	std::cout << type_name<std::vector<int>>() << "\n";
	std::cout << type_name<char>() << "\n";
	std::cout << type_name<std::string>() << "\n";
}
