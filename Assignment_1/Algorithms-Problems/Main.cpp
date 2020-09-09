

#include <iostream>
#include "LinkedLists.h"
#include <string>
using namespace std;

void printList(Node* e)
{
    while (e != nullptr) {
        std::cout << e->data << " ";
        e = e->next;
    }
    cout << endl;
    return;
}
void LinkedListDemo() {
    std::cout << "This is a demonstration of a linked list" << std::endl;
    Node a, b, c;
    a.data = "Sam";
    b.data = "Bill";
    c.data = "Sean";
    a.next = &b;
    b.next = &c;
    printList(&a);
    return;
}
void StackDemo() {
    Stack stack = Stack();
    stack.push("Ethan");
    stack.push("Donnavan");
    stack.push("Kayla");
    cout << "This is a demo of a Stack." << endl;
    cout << "I have pushed three elements to the stack, and this is what the stack looks like now." << endl;
    printList(stack.top);
    //cout << stack.pop().data << endl;             These are commented out as they are not functioning yet.
    //cout << stack.pop().data << endl;             They throw either a bad_alloc or some error about a long string
    //cout << (*stack.top).data << endl;
    cout << "I just popped off the top of the stack. Here's what it looks like now." << endl;
    // cout << stack.top->data << endl;
     //printList(stack.top);
    return;
}
int main() {
    LinkedListDemo();
   // StackDemo();
}

