#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    const size_t DAYS = 30;
    vector<double> temperatures(DAYS);

    // Read temperatures from file
    ifstream infile("temperatures.txt");
    if (!infile)
    {
        cout << "Error: Could not open temperatures.txt" << endl;
        return 1;
    }
    for (size_t i = 0; i < DAYS; ++i)
    {
        infile >> temperatures[i];
    }
    infile.close();
