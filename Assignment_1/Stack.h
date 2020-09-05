 #include "Element.h"
 class Stack{
     public:
        Stack();
        bool isEmpty();
        void push(std::string arg);
        std::string pop();
        Element* top;
    
};