#include <iostream>
using namespace std;


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void insertionSort(int arr[], int n) {
    cout << "Insertion Sort :"<<endl;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Step " << i << ": ";
        printArray(arr, n);
    }
}


void selectionSort(int arr[], int n) {
    cout << "Selection Sort :"<<endl;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

       
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        cout << "Step " << i + 1 << ": ";
        printArray(arr, n);
    }
}

int main() {
    int arr1[] = {5, 3, 8, 4, 2};
    int arr2[] = {5, 3, 8, 4, 2};
    int n = 5;

    cout << "Original Array:"<<endl;
    printArray(arr1, n);

    insertionSort(arr1, n);

    cout << "Final Sorted Array (Insertion Sort):"<<endl;
    printArray(arr1, n);

    selectionSort(arr2, n);

    cout << "Final Sorted Array (Selection Sort):"<<endl;
    printArray(arr2, n);

    return 0;
}
