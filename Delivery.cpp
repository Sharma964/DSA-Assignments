#include <iostream>
using namespace std;

class Route {
public:
    string name;
    Route* next;

    Route(string n) {
        name = n;
        next = nullptr;
    }
};


class NavigationSystem {
private:
    Route* head;

public:
    NavigationSystem() {
        head = nullptr;
    }

   
    void addRoute(string routeName) {
        Route* newRoute = new Route(routeName);
        if (head == nullptr) {
            head = newRoute;
            newRoute->next = head; 
        } else {
            Route* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newRoute;
            newRoute->next = head;
        }
    }

    
    void removeRoute(string routeName) {
        if (head == nullptr) {
            cout << "No routes available to remove.\n";
            return;
        }

        Route* curr = head;
        Route* prev = nullptr;

        
        do {
            if (curr->name == routeName) {
                if (curr == head && curr->next == head) { 
                    
                    head = nullptr;
                } else {
                    if (curr == head) {
                        
                        Route* last = head;
                        while (last->next != head) {
                            last = last->next;
                        }
                        head = head->next;
                        last->next = head;
                    } else {
                        prev->next = curr->next;
                    }
                }
                delete curr;
                cout << "Route \"" << routeName << "\" removed.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Route \"" << routeName << "\" not found.\n";
    }

    
    void displayRoutes() {
        if (head == nullptr) {
            cout << "No routes available.\n";
            return;
        }
        Route* temp = head;
        cout << "Routes: ";
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to " << head->name << ")\n";
    }
};


int main() {
    NavigationSystem nav;
    int n;
    string routeName;

    cout << "Enter number of initial routes: ";
    cin >> n;

    cout << "Enter route names:\n";
    for (int i = 0; i < n; i++) {
        cin >> routeName;
        nav.addRoute(routeName);
    }

    int choice;
    do {
        cout << "\n--- Delivery Navigation System ---\n";
        cout << "1. Add Route\n";
        cout << "2. Remove Route\n";
        cout << "3. Display Routes\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter route name: ";
            cin >> routeName;
            nav.addRoute(routeName);
            break;
        case 2:
            cout << "Enter route name to remove: ";
            cin >> routeName;
            nav.removeRoute(routeName);
            break;
        case 3:
            nav.displayRoutes();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
