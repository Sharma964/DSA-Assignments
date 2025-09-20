#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
};

// Swap function
void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

// QuickSort in descending order
void quickSort(Student student[], int low, int high) {
    if (low >= high)
        return;

    int pivot = student[high].score;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (student[j].score >= pivot) {  // Descending order
            i++;
            swap(student[i], student[j]);
        }
    }
    swap(student[i + 1], student[high]);

    quickSort(student, low, i);
    quickSort(student, i + 2, high);
}

// Display merit list with ranks (ties handled)
void displayMeritList(Student student[], int n) {
    cout << "\nMerit List:\n";
    cout << "---------------------------\n";
    cout << "Rank\tName\tScore\n";

    int rank = 1;
    cout << rank << "\t" << student[0].name << "\t" << student[0].score << endl;

    for (int i = 1; i < n; i++) {
        if (student[i].score == student[i - 1].score) {
            // Same rank for tie
            cout << rank << "\t" << student[i].name << "\t" << student[i].score << endl;
        } else {
            rank = i + 1;
            cout << rank << "\t" << student[i].name << "\t" << student[i].score << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student student[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> student[i].name;
        cout << "Enter score of student " << i + 1 << ": ";
        cin >> student[i].score;
    }

    quickSort(student, 0, n - 1);
    displayMeritList(student, n);

    return 0;
}
