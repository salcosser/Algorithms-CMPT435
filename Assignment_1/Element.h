#pragma once
#include <string>
class Element {
public:
	std::string name;
	Element* next;
	Element(std::string n);
};