#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
            
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int salaries[10] = {45000, 32000, 60000, 28000, 50000,
                        39000, 70000, 41000, 36000, 55000};

    int n = 10;

    cout << "Original Salaries:\n";
    display(salaries, n);

    bubbleSort(salaries, n);

    cout << "\n\nSorted Salaries (Ascending Order):\n";
    display(salaries, n);

    return 0;
}
