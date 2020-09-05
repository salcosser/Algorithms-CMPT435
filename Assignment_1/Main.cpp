#include <iostream>
#include "Stack.h"



    int main() {
      Stack stack = Stack();
      stack.push("Sam");
      stack.push("David");
      stack.push("Sean");
      std::cout << "I put the names in Sam, David, and Sean in in that order." << std::endl;
      std::cout << "the first name off the stack is " << stack.pop() << "."<<std::endl;
      std::cout << "The second name off the stack is " << stack.pop() << "."<< std::endl;
      std::cout << "The last name off the stack is " << stack.pop() << "."<< std::endl;

    
     
    }

 