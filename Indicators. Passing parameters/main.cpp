#include <iostream>

using namespace std;

int* removeNegativeNumbers(int* arr, int size, int& newSize) {
    int positiveCount = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            positiveCount++;
        }
    }

    int* positiveArr = new int[positiveCount];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            positiveArr[index++] = arr[i];
        }
    }

    newSize = positiveCount;
    return positiveArr;
}

int main() {
    const int SIZE = 7;
    int arr[SIZE] = { 1, -2, 3, -4, 5, -6, 7 };

    int newSize;
    int* positiveArr = removeNegativeNumbers(arr, SIZE, newSize);

    cout << "New array without negative numbers: ";
    for (int i = 0; i < newSize; ++i) {
        cout << positiveArr[i] << " ";
    }
    cout << endl;

    delete[] positiveArr;

    return 0;
}
