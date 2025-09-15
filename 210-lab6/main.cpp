#include <iostream>
using namespace std;

const int ARRAY_SIZE = 5;

void enterArrayData(double* ptr, int size) {
    cout << "Data entry for the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "    > Element #" << i << ": ";
        cin >> *(ptr + i);
    }
    cout << "Data entry complete.\n";
}

void outputArrayData(double* ptr, int size) {
    cout << "Outputting array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

double sumArray(double* ptr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += *(ptr + i);
    }
    return sum;
}

int main() {
    double* myArray = new double[ARRAY_SIZE];

    enterArrayData(myArray, ARRAY_SIZE);
    outputArrayData(myArray, ARRAY_SIZE);
    double total = sumArray(myArray, ARRAY_SIZE);

    cout << "Sum of values: " << total << endl;

    delete[] myArray;

    return 0;
}
