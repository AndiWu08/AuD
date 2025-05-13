#include <iostream>
#include "06_20_21_22_adt_stack.cpp"
#include <string>
#include <sstream>


int main() {
    Stack<int> s;
    int a = 3, b = 2, c = 1;
    // s.pop(); // pop on empty stack ->
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

    std::string test1 = "3+2";          // Erwartet: "3 2 +"
    std::string test2 = "(3+2)*4";      // Erwartet: "3 2 + 4 *"
    std::string test3 = "1+2*3-4/2";    // Erwartet: "1 2 3 * + 4 2 / -"
    std::string test4 = "4/2";

    std::string postfix1 = infix_to_postfix(test1);
    std::string postfix2 = infix_to_postfix(test2);
    std::string postfix3 = infix_to_postfix(test3);

    std::cout << "Test 1 (3+2): " << postfix1 << " = " << evaluate_postfix(postfix1) << std::endl;
    std::cout << "Test 2 ((3+2)*4): " << postfix2 << " = " << evaluate_postfix(postfix2) << std::endl;
    std::cout << "Test 3 1+2*3-4/2: " << postfix3 << " = " << evaluate_postfix(postfix3) << std::endl; 
    std::cout << evaluate_postfix(infix_to_postfix(test4)) << std::endl;  
}

