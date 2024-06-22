#include <iostream>

using namespace std;

void separateElements(const int* array, size_t size, int*& positives, size_t& posCount, int*& negatives, size_t& negCount, int*& zeros, size_t& zeroCount) {
    posCount = negCount = zeroCount = 0;

    for (size_t i = 0; i < size; ++i) {
        if (array[i] > 0) {
            ++posCount;
        }
        else if (array[i] < 0) {
            ++negCount;
        }
        else {
            ++zeroCount;
        }
    }

    positives = new int[posCount];
    negatives = new int[negCount];
    zeros = new int[zeroCount];

    size_t posIndex = 0, negIndex = 0, zeroIndex = 0;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] > 0) {
            positives[posIndex++] = array[i];
        }
        else if (array[i] < 0) {
            negatives[negIndex++] = array[i];
        }
        else {
            zeros[zeroIndex++] = array[i];
        }
    }
}

void printArray(const int* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    const size_t size = 10;
    int array[size] = { 1, -2, 0, 4, -5, 6, 0, -8, 9, 0 };

    int* positives = nullptr;
    int* negatives = nullptr;
    int* zeros = nullptr;
    size_t posCount, negCount, zeroCount;

    separateElements(array, size, positives, posCount, negatives, negCount, zeros, zeroCount);

    cout << "Positive elements: ";
    printArray(positives, posCount);

    cout << "Negative elements: ";
    printArray(negatives, negCount);

    cout << "Zero elements: ";
    printArray(zeros, zeroCount);

    delete[] positives;
    delete[] negatives;
    delete[] zeros;

    return 0;
}
