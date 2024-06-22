#include <iostream>

using namespace std;

int* allocateMemory(size_t size) {
    return new int[size];
}

void initializeArray(int* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        array[i] = 0;
    }
}

void printArray(const int* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void deleteArray(int* array) {
    delete[] array;
}

void addElement(int*& array, size_t& size, int element) {
    int* newArray = new int[size + 1];
    for (size_t i = 0; i < size; ++i) {
        newArray[i] = array[i];
    }
    newArray[size] = element;
    delete[] array;
    array = newArray;
    ++size;
}

void insertElement(int*& array, size_t& size, size_t index, int element) {
    if (index > size) {
        cout << "Index out of bounds" << endl;
        return;
    }

    int* newArray = new int[size + 1];
    for (size_t i = 0; i < index; ++i) {
        newArray[i] = array[i];
    }
    newArray[index] = element;
    for (size_t i = index; i < size; ++i) {
        newArray[i + 1] = array[i];
    }
    delete[] array;
    array = newArray;
    ++size;
}

void removeElement(int*& array, size_t& size, size_t index) {
    if (index >= size) {
        cout << "Index out of bounds" << endl;
        return;
    }

    int* newArray = new int[size - 1];
    for (size_t i = 0; i < index; ++i) {
        newArray[i] = array[i];
    }
    for (size_t i = index + 1; i < size; ++i) {
        newArray[i - 1] = array[i];
    }
    delete[] array;
    array = newArray;
    --size;
}

int main() {
    size_t size = 5;
    int* array = allocateMemory(size);
    initializeArray(array, size);

    cout << "Initialized array: ";
    printArray(array, size);

    addElement(array, size, 10);
    cout << "After adding element 10: ";
    printArray(array, size);

    insertElement(array, size, 2, 20);
    cout << "After inserting element 20 at index 2: ";
    printArray(array, size);

    removeElement(array, size, 3);
    cout << "After removing element at index 3: ";
    printArray(array, size);

    deleteArray(array);

    return 0;
}
