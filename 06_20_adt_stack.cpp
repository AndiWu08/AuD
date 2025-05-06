#include <iostream>

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
