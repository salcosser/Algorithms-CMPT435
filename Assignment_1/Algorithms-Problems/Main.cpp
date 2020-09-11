

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>
using namespace std;

void printList(Node *e)
{
    if (e == nullptr)
    {
        std::cout << "If you're seeing this, the list is empty." << std::endl;
        return;
    }
    else
    {
        while (e != nullptr)
        {
            std::cout << e->data << " ";
            e = e->next;
        }
        cout << endl;
        return;
    }
}
void LinkedListDemo()
{
    std::cout << "This is a demonstration of a linked list" << std::endl;
    //Node a, b, c;
    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();
    a->data = "Sam";
    a->next = b;
    b->data = "Bill";
    b->next = c;
    c->data = "Sean";
    c->next = nullptr;
    printList(a);
    return;
}
void StackDemo()
{
    Stack stack = Stack();
    stack.push("Ethan");
    stack.push("Donnavan");
    stack.push("Kayla");
    cout << "This is a demo of a Stack." << endl;
    cout << "I have pushed three elements to the stack, Ethan, Donnavan, and Kayla in that order, and this is what the stack looks like now." << endl;
    printList(stack.top);
    cout << stack.pop().data << endl;
    cout << stack.pop().data << endl;
    cout << stack.pop().data << endl;
    cout << "I just popped off the top of the stack. Here's what it looks like now." << endl;

    printList(stack.top);
    return;
}
void QueueDemo()
{
    Queue q = Queue();
    cout << "And now, here's the queue demo." << endl;
    q.enQueue("Mark");
    cout << "Mark has been added" << endl;
    q.enQueue("Dylan");
    cout << "Dylan has been added" << endl;
    q.enQueue("Rachel");
    cout << "Rachel has been added" << endl;
    q.enQueue("Mike");
    cout << "Mike has been added" << endl;
    cout << "as of right now, the list looks like this:" << endl;
    printList(q.head);
    cout << "And now, I will take off everyone in the line ( Hopefully starting with Mark)." << endl;
    cout << q.deQueue().data << endl;
    cout << q.deQueue().data << endl;
    cout << q.deQueue().data << endl;
    printList(q.head);
}
int main()
{
    /* LinkedListDemo();
    cout << endl;
    StackDemo();
    cout << endl;
    QueueDemo(); */
    
}
