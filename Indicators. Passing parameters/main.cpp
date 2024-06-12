#include <iostream>

using namespace std;

void addElementsToEnd(int*& arr, int& size, int* elementsToAdd, int elementsCount) {
    int newSize = size + elementsCount;
    int* tempArray = new int[newSize];

    for (int i = 0; i < size; ++i) {
        tempArray[i] = arr[i];
    }

    for (int i = 0; i < elementsCount; ++i) {
        tempArray[size + i] = elementsToAdd[i];
    }

    delete[] arr;
    arr = tempArray;
    size = newSize;
}

int main() {
    const int INITIAL_SIZE = 5;
    int* arr = new int[INITIAL_SIZE] {1, 2, 3, 4, 5};
    int size = INITIAL_SIZE;

    int elementsToAdd[] = { 6, 7, 8 };
    int elementsCount = sizeof(elementsToAdd) / sizeof(elementsToAdd[0]);

    addElementsToEnd(arr, size, elementsToAdd, elementsCount);

    cout << "New array after adding elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
