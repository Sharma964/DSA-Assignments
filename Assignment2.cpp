#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    double salary;
};

void sortBySalary(Employee emp[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (emp[j].salary < emp[j + 1].salary) {
                Employee temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
}

void displayEmployees(Employee emp[], int n) {
    cout << "\n--- Employee Records (Sorted by Salary) ---\n";
    cout << "ID\tName\t\tSalary\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << emp[i].id << "\t" << emp[i].name << "\t\t" << emp[i].salary << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee emp[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Employee " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> emp[i].id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, emp[i].name);
        cout << "Salary: ";
        cin >> emp[i].salary;
    }

    sortBySalary(emp, n);
    displayEmployees(emp, n);

    return 0;
}
