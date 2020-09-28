#include <iostream>
#include <string>
#include <fstream>
#include "Sort.h"
int main() {
	string s = "Testing this.";
	std::cout << "The string that will be tested is: " << s << "." << std::endl;
	Sort::Insertion(s);
	std::cout << "The string now reads: " << s << "." << std::endl;
}
