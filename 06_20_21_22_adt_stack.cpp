#include <iostream>
#include <string>
#include <cctype> 
#include <sstream>

// 20: Stack Implementierung
template <class item_type>
class Stack {
    struct node {
        item_type item;
        node *next;
    };
private:
    node *tail;
    int anz_items;
public:
    Stack() : tail(nullptr), anz_items(0) {}

    ~Stack() {
        while (tail != nullptr) {
            node* temp = tail;
            tail = tail->next;
            delete temp;
        }
    }

    void push(item_type &r) {
        node* new_node = new node;
        new_node->item = r;
        new_node->next = tail;
        tail = new_node;
        anz_items++;
    }

    item_type pop() {
        node* temp = tail;
        item_type result = temp->item;
        tail = tail->next;
        delete temp;
        anz_items--;
        return result;
    }

    item_type top() {
        return tail->item;
    }

    int length() {
        return anz_items;
    }

    bool empty() {
        return anz_items == 0;
    }
};


// Hilfsfunktion zur Bestimmung der Operatorpriorität
int get_precedence(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 0; // Für '('
}

// 21: Infix to postfix
std::string infix_to_postfix(const std::string& infix) {
    Stack<char> stack;
    std::string postfix;
    std::string current_number; // Sammelt mehrstellige Zahlen

    for (char c : infix) {
        if (isdigit(c)) {
            current_number += c;
        } else {
            // Zahl ausgeben, falls vorhanden
            if (!current_number.empty()) {
                postfix += current_number + " ";
                current_number.clear();
            }
            
            if (isspace(c)) continue; // Leerzeichen ignorieren
            
            if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                // Alle Operatoren bis zur öffnenden Klammer ausgeben
                while (!stack.empty() && stack.top() != '(') {
                    postfix += stack.pop();
                    postfix += " ";
                }
                stack.pop(); // '(' entfernen
            } else {
                // Operatoren verarbeiten
                while (!stack.empty() && stack.top() != '(' && 
                       get_precedence(stack.top()) >= get_precedence(c)) {
                    postfix += stack.pop();
                    postfix += " ";
                }
                stack.push(c);
            }
        }
    }
    
    // Restliche Zahl ausgeben
    if (!current_number.empty()) {
        postfix += current_number + " ";
    }
    
    // Verbleibende Operatoren ausgeben
    while (!stack.empty()) {
        postfix += stack.pop();
        postfix += " ";
    }
    
    // Letztes Leerzeichen entfernen
    if (!postfix.empty() && postfix.back() == ' ') {
        postfix.pop_back();
    }
    
    return postfix;
}

// 22
double evaluate_postfix(const std::string& postfix) {
    Stack<double> stack;
    std::string token;
    std::stringstream ss(postfix);

    // stringstream kann strings zerlegen, solange string zerlegen, bis string leer ist
    while (ss >> token) {
        if (isdigit(token[0]))
        {
            double num = stod(token); // stod: string -> double
            stack.push(num);
        }
        else // token ist operand
        {
            // die oberen beiden zahlen aus stack lesen
            // zweiter operand liegt oben, erster operand darunter
            double b = stack.pop();
            double a = stack.pop();

            // a und b ausrechnen
            double result;
            switch (token[0]) {
                case '+': result = a+b; break;
                case '-': result = a-b; break;
                case '*': result = a*b; break;
                case '/': result = a/b; break;
            }
            stack.push(result);
        }
    }
    // ergebnis zurückgeben
    double final_result = stack.pop();
    return final_result;
}