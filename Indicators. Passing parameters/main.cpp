#include <iostream>

using namespace std;

void countPositiveNegativeZero(int* arr, int size, int* positivePtr, int* negativePtr, int* zeroPtr) {
    *positivePtr = 0;
    *negativePtr = 0;
    *zeroPtr = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            (*positivePtr)++;
        }
        else if (arr[i] < 0) {
            (*negativePtr)++;
        }
        else {
            (*zeroPtr)++;
        }
    }
}

int main() {
    const int SIZE = 8;
    int arr[SIZE] = { 3, -5, 0, 2, -7, 0, 1, 0 };
    int positiveCount, negativeCount, zeroCount;

    countPositiveNegativeZero(arr, SIZE, &positiveCount, &negativeCount, &zeroCount);

    cout << "Number of positive elements: " << positiveCount << endl;
    cout << "Number of negative elements: " << negativeCount << endl;
    cout << "Number of zero elements: " << zeroCount << endl;

    return 0;
}
