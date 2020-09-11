
#include "Stack.h"
#include <iostream>
#include <string>



bool Stack::isEmpty() {
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
void Stack::push(std::string arg) {
    Node* n = new Node();
    n->data = arg;
    Node* oldTop = top;
    n->next = oldTop;
    top = n;
    //std::cout << top.data << std::endl;    // not needed
    return;
}
Node Stack::pop() {
    if (isEmpty()) {
        throw "Memory underflow Error";
    }
    else {
        Node retVal = Node(*top);
        Node* newTop = top->next;
        top = newTop;
        return retVal;
    }
}

