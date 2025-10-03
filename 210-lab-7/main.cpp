#include <iostream>
#include <string>
using namespace std;

string* reverseArray(string* ptr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        string temp = *(ptr + i);
        *(ptr + i) = *(ptr + size - 1 - i);
        *(ptr + size - 1 - i) = temp;
    }
    return ptr; // Return the same pointer (now reversed)
}

void displayArray(string* ptr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 5;

    string* names = new string[SIZE];
    *(names + 0) = "Janet";
    *(names + 1) = "Jeffe";
    *(names + 2) = "Jin";
    *(names + 3) = "Joe";
    *(names + 4) = "Junio";

    cout << "Original array: ";
    displayArray(names, SIZE);

    reverseArray(names, SIZE);

    cout << "Reversed array: ";
    displayArray(names, SIZE);

    delete[] names;

    return 0;
}
