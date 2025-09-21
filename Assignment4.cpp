#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LL {
public:
    Node* head;
    LL() {
        head = NULL;
    }

    void create_list(int n) {
        head = NULL; // reset list
        if (n <= 0) {
            cout << "List size must be greater than 0.\n";
            return;
        }
        int val;
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> val;
            insert_end(val);
        }
        cout << "List created successfully.\n";
    }

    void insert_begin(int val) {
        Node* new_Node = new Node(val);
        new_Node->next = head;
        head = new_Node;
    }

    void insert_end(int val) {
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insert_at(int pos, int val) {
        if (pos == 0) {
            insert_begin(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of bounds!\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void delete_begin() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node from beginning.\n";
    }

    void delete_end() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted last node.\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Deleted node from end.\n";
    }

    void delete_at(int pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (pos == 0) {
            delete_begin();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds!\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << "Deleted node at position " << pos << ".\n";
    }

    void search(int val) {
        Node* temp = head;
        int pos = 0;
        bool found = false;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Element " << val << " found at position " << pos << ".\n";
                found = true;
            }
            temp = temp->next;
            pos++;
        }
        if (!found)
            cout << "Element " << val << " not found.\n";
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed successfully.\n";
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int countNode() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LL obj;
    int choice, val, pos, n;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Create List\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete at Beginning\n";
        cout << "6. Delete at End\n";
        cout << "7. Delete at Position\n";
        cout << "8. Search Element\n";
        cout << "9. Reverse List\n";
        cout << "10. Count Nodes\n";
        cout << "11. Print List\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            obj.create_list(n);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            obj.insert_begin(val);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> val;
            obj.insert_end(val);
            break;
        case 4:
            cout << "Enter position and value: ";
            cin >> pos >> val;
            obj.insert_at(pos, val);
            break;
        case 5:
            obj.delete_begin();
            break;
        case 6:
            obj.delete_end();
            break;
        case 7:
            cout << "Enter position to delete: ";
            cin >> pos;
            obj.delete_at(pos);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            obj.search(val);
            break;
        case 9:
            obj.reverse();
            break;
        case 10:
            cout << "Total nodes: " << obj.countNode() << endl;
            break;
        case 11:
            obj.print();
            break;
        case 12:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 12);

    return 0;
}
