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


void list_intersection(Node* head1, Node* head2) {
    if (!head1 || !head2) {
        return;
    }
    int count_1 = count_list(head1); int count_2 = count_list(head2);
    Node* temp_1 = head1;
    for (int i = 0; i < count_1; i++) {
        Node* temp_2 = head2;
        for (int j = 0; j < count_2; j++) {
            if (temp_1->data == temp_2->data) {
                cout << temp_1->data << " ";
            }
            temp_2 = temp_2->next;
        }
        temp_1 = temp_1->next;
    }
}


int main() {
    Node* head = nullptr; string stop_word; int word;
    Node* head1 = nullptr; Node* head2 = nullptr;
    cout << "Press '1' add an element to the list in the end\n"
                "Press '2' to print all list\n"
                "Press '3' to delete all list\n"
                "Press '4' to search the necessary element of the list\n"
                "Press '5' to delete all elements which you'll write\n"
                "Press '6' to delete all elements after the specified element\n"
                "Press '7' to make intersection of 2 lists\n";
    while (cout << "What's your choice? Press here: " && cin >> word) {
        switch (word) {
            case 1: {
                cout << "Enter an element of your list: ";
                cin >> word;
                push_back(head, word);
                cout << endl;
                break;
            }
            case 2: {
                cout << "Your total list: ";
                print_list(head);
                cout << endl;
                break;
            }
            case 3: {
                cout << "Your list is deleted successfully." << endl;
                delete_list(head);
                break;
            }
            case 4: {
                cout << "Enter an element which you wanna find: ";
                cin >> word;
                if (search_list(head, word))
                    cout << "Element WAS found in the list.";
                else
                    cout << "Element WAS NOT found in the list.";
                cout << endl;
                break;
            }
            case 5: {
                cout << "Enter an element which you wanna delete the whole: ";
                cin >> word;
                delete_by_value(head, word);
                cout << endl;
                break;
            }
            case 6: {
                cout << "Enter an element which you wanna delete the whole after this element: ";
                cin >> word;
                delete_after_by_value(head, word);
                cout << endl;
                break;
            }
            case 7: {
                cout << "Enter elements for the second list [for stop press -1]: ";
                while (true) {
                    cin >> word;
                    if (word == -1)
                        break;
                    push_back(head2, word);
                }
                cout << "Your result of intersection: ";
                list_intersection(head, head2);
                cout << endl;
                break;
            }
            default: {
                cout << endl;
                cout << "Invalid argument (choice isn't integer)";
                break;
            }
        }
    }
}