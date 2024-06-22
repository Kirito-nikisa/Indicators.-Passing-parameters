#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

int* removePrimes(const int* array, size_t size, size_t& newSize) {
    newSize = 0;
    for (size_t i = 0; i < size; ++i) {
        if (!isPrime(array[i])) {
            ++newSize;
        }
    }

    int* newArray = new int[newSize];
    size_t index = 0;
    for (size_t i = 0; i < size; ++i) {
        if (!isPrime(array[i])) {
            newArray[index++] = array[i];
        }
    }

    return newArray;
}

void printArray(const int* array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    size_t size = 10;
    int* array = new int[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original array: ";
    printArray(array, size);

    size_t newSize;
    int* newArray = removePrimes(array, size, newSize);

    cout << "Array after removing primes: ";
    printArray(newArray, newSize);

    delete[] array;
    delete[] newArray;

    return 0;
}
