#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <iomanip>
using namespace std;

class List {
public:
    // Constructor
    List() {
        head_ = new Node();
        head_->next = nullptr;
    }

    // Destructor
    ~List() {
        Node* curr = head_;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    // Add an element to the list
    void addElement(float element) {
        Node* newNode = new Node();
        newNode->data = element;
        Node* prev=head_;
        Node* curr = head_;
        while (curr != nullptr)
        {
            prev = curr;
            curr = curr->next;

        }
        prev->next = newNode;
            
    }


    // Print list
    void printlist() const {

        Node* curr = head_->next;
        while (curr != nullptr) {
            if (curr->next != nullptr)
            {
                cout << std::fixed << std::setw(6) << std::setprecision(4) << curr->data << ", ";

            }
            else
                cout << std::fixed << std::setw(6) << std::setprecision(4) << curr->data <<endl;
            
            curr = curr->next;
        }
        
    }

private:
    struct Node {
        float data;
        Node* next;
    };
    Node* head_;
};



#endif
