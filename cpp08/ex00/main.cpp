#include "Easyfind.hpp"

int main() {
	try {
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);

		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found value: " << *it << std::endl; 

		std::list<int> lst;
		lst.push_back(100);
		lst.push_back(200);
		lst.push_back(300);
		lst.push_back(400);
		lst.push_back(500);

		std::list<int>::iterator it2 = easyfind(lst, 200);
		std::cout << "Found value: " << *it2 << std::endl;

		easyfind(vec, 60);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
