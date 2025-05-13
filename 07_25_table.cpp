#include <iostream>

template <typename item_type>
class Tabelle {
private:
    struct Node {
        item_type data;
        Node* prev;
        Node* next;
        
        Node(const item_type& d, Node* p = nullptr, Node* n = nullptr)
            : data(d), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    Node* current;
    int size;

public:
    Tabelle() : head(nullptr), tail(nullptr), current(nullptr), size(0) {}

    ~Tabelle() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    bool insert(item_type r) {
        if (current == nullptr) {
            // Liste ist leer oder current ist nicht gesetzt
            return append(r);
        }

        Node* newNode = new Node(r, current->prev, current);
        if (current->prev != nullptr) {
            current->prev->next = newNode;
        } else {
            head = newNode;
        }
        current->prev = newNode;
        size++;
        return true;
    }

    bool append(item_type r) {
        Node* newNode = new Node(r, tail, nullptr);
        if (tail == nullptr) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        return true;
    }

    bool first() {
        if (head == nullptr) {
            return false;
        }
        current = head;
        return true;
    }

    bool last() {
        if (tail == nullptr) {
            return false;
        }
        current = tail;
        return true;
    }

    bool next() {
        if (current == nullptr || current->next == nullptr) {
            return false;
        }
        current = current->next;
        return true;
    }

    bool previous() {
        if (current == nullptr || current->prev == nullptr) {
            return false;
        }
        current = current->prev;
        return true;
    }

    bool delete_node() {
        if (current == nullptr) {
            return false;
        }

        Node* toDelete = current;
        Node* prevNode = current->prev;
        Node* nextNode = current->next;

        if (prevNode != nullptr) {
            prevNode->next = nextNode;
        } else {
            head = nextNode;
        }

        if (nextNode != nullptr) {
            nextNode->prev = prevNode;
        } else {
            tail = prevNode;
        }

        current = nextNode; 
        delete toDelete;
        size--;
        return true;
    }

    bool get_node(item_type &r) {
        if (current == nullptr) {
            return false;
        }
        r = current->data;
        return true;
    }

    bool set_node(item_type &r) {
        if (current == nullptr) {
            return false;
        }
        current->data = r;
        return true;
    }
};