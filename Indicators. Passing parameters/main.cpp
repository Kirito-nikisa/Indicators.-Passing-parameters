#include <iostream>

using namespace std;

int* findSubset(int* A, int sizeA, int* B, int sizeB) {
    for (int i = 0; i <= sizeA - sizeB; ++i) {
        bool found = true;
        for (int j = 0; j < sizeB; ++j) {
            if (A[i + j] != B[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return &A[i];
        }
    }
    return nullptr;
}

int main() {
    const int SIZE_A = 7;
    const int SIZE_B = 3;
    int A[SIZE_A] = { 1, 2, 3, 4, 5, 6, 7 };
    int B[SIZE_B] = { 3, 4, 5 };

    int* result = findSubset(A, SIZE_A, B, SIZE_B);

    if (result != nullptr) {
        cout << "Subset found at index: " << result - A << endl;
    }
    else {
        cout << "Subset not found" << endl;
    }

    return 0;
}
