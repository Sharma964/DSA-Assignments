#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    double revenue;
};

void merge(Product arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Product* L = new Product[n1];
    Product* R = new Product[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].revenue >= R[j].revenue) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Product arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product products[n];
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of Product " << i + 1 << ": ";
        getline(cin, products[i].name);
        cout << "Enter revenue for " << products[i].name << ": ";
        cin >> products[i].revenue;
        cin.ignore();
    }

    mergeSort(products, 0, n - 1);

    cout << "\n--- Products Sorted by Revenue (Descending) ---\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". " << products[i].name
             << " - Revenue: " << products[i].revenue;
        if (i == 0) cout << "  <-- Best Seller ";
        cout << endl;
    }

    cout << "\nTop Selling Product: " << products[0].name
         << " (Revenue: " << products[0].revenue << ")";
    cout << "\nLowest Selling Product: " << products[n - 1].name
         << " (Revenue: " << products[n - 1].revenue << ")\n";

    return 0;
}
