#include <iostream>

using namespace std;


void sumAndProduct(int* arr, int size, int* sumPtr, int* productPtr) {
 
    *sumPtr = 0;
    *productPtr = 1;

 
    for (int i = 0; i < size; ++i) {
        *sumPtr += arr[i];
        *productPtr *= arr[i];
    }
}

int main() {
    const int SIZE = 5;
    int arr[SIZE] = { 1, 2, 3, 4, 5 };
    int sum, product;

   
    sumAndProduct(arr, SIZE, &sum, &product);
    cout << "Sum of elements: " << sum << endl;
    cout << "Product of elements: " << product << endl;

    return 0;
}
