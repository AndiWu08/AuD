#include <iostream>
#include "06_20_adt_stack.cpp"

int main() {
    Stack<int> s;
    int a = 3, b = 2, c = 1;
    s.push(a);
    std::cout << "Top: " << s.top() << std::endl; 
    std::cout << "Length: " << s.length() << std::endl; 
    s.push(b);
    std::cout << "Top: " << s.top() << std::endl; 
    std::cout << "Length: " << s.length() << std::endl; 
    s.push(c);
    std::cout << "Top: " << s.top() << std::endl; 
    std::cout << "Length: " << s.length() << std::endl; 
    std::cout << "Pop: " << s.pop() << std::endl; 
    std::cout << "Length after pop: " << s.length() << std::endl; 
}