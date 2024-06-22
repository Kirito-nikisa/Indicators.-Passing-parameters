#include <iostream>
#include <vector>

using namespace std;

void removeBlockFromArray(vector<int>& array, size_t startIndex, size_t count) {
    if (startIndex >= array.size()) {
        cout << "Start index is out of array bounds" << endl;
        return;
    }

    size_t endIndex = min(startIndex + count, array.size());
    array.erase(array.begin() + startIndex, array.begin() + endIndex);
}

int main() {
    vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << "Initial array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    removeBlockFromArray(array, 4, 3);

    cout << "Array after removal: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
