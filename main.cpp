#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* nexct) {
        this->data = data;
        this->next = next;
    }
};

Node* create_list(int data) {
    Node* newNode = new Node(data, nullptr);
    newNode->next = newNode;
    return newNode;
}

void push_back(Node*& head, int data) {
    if (head == nullptr) {
        head = create_list(data);
    } else {
        Node* newNode = new Node(data, head);
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

int count_list(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    int count = 1;
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
        count++;
    }
    return count;
}

void print_list(Node* head) {
    if (head == nullptr) {
        return;
    }
    int count = count_list(head);
    Node* temp = head;
    for (int i = 0; i < count; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void delete_list(Node*& head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* curr = head;
    Node* temp = nullptr;
    while (curr->next != head) {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    delete curr;
    head = nullptr;
    cout << endl;
}

int main() {
}
