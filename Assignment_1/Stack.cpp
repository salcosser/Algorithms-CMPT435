#include "Stack.h"

Stack::Stack(){
    top = nullptr;
}
bool Stack::isEmpty(){
    if(top == nullptr){
        return true;
    }else{
        return false;
    }
}
void Stack::push(std::string arg){
    Element n = Element(arg);
    Element* oldTop = top;
    n.next = oldTop;
    top = &n;
}
std::string Stack::pop(){
    if(isEmpty()){
        throw "Stack Underflow Exception silly!";
    }else{
        Element retVal = *top;
        return retVal.name;
    }
}