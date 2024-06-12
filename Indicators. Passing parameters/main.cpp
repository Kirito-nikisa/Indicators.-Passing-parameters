#include <iostream>

using namespace std;

void insertElements(int*& arr, int& size, int index, int* elementsToInsert, int elementsCount) {
    int newSize = size + elementsCount;
    int* tempArray = new int[newSize];

    for (int i = 0; i < index; ++i) {
        tempArray[i] = arr[i];
    }

    for (int i = 0; i < elementsCount; ++i) {
        tempArray[index + i] = elementsToInsert[i];
    }

    for (int i = index; i < size; ++i) {
        tempArray[i + elementsCount] = arr[i];
    }

    delete[] arr;
    arr = tempArray;
    size = newSize;
}

int main() {
    const int INITIAL_SIZE = 5;
    int* arr = new int[INITIAL_SIZE] {1, 2, 3, 4, 5};
    int size = INITIAL_SIZE;

    int elementsToInsert[] = { 6, 7, 8 };
    int elementsCount = sizeof(elementsToInsert) / sizeof(elementsToInsert[0]);
    int insertIndex = 2;

    insertElements(arr, size, insertIndex, elementsToInsert, elementsCount);

    cout << "New array after inserting elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
