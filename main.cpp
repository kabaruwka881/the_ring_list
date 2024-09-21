#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next) {
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

bool search_list(Node* head, int key) {
    if (head == nullptr) {
        return false;
    }
    int count = count_list(head);
    Node* temp = head;
    for (int i = 0; i < count; i++) {
        if (temp->data == key) {
            cout << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << endl;
    return false;
}

void delete_by_value(Node*& head, int key) {
    if (head == nullptr) {
        return;
    }
    else if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    int count = count_list(head);
    while (temp->data == key) {
        prev = temp;
        temp = temp->next;
        delete prev;
        count--;
    }
    head = temp;
    for (int i = 1; i < count; i++) {
        if (temp->next->data == key) {
            prev = temp->next;
            temp->next = prev->next;
            delete prev;
        } else {
            temp = temp->next;
        }
    }
    temp->next = head;
}

void delete_after_by_value(Node*& head, int key) {
    if (head == nullptr || head->next == head) {
        return;
    }
    Node* temp = head->next;
    Node* prev = head;
    int count = count_list(head);
    for (int i = 1; i < count; i++) {
        if (prev->data == key) {
            prev->next = temp->next;
            delete temp;
            count--;
        }
        prev = prev->next;
        if (prev->next == head) {
            break;
        }
        temp = prev->next;
    }
}

int main() {
}
