#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int main()
{
    const size_t DAYS = 30;
    array<double, DAYS> temperatures;

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

// Demonstrate std::array member functions
    cout << "First day's temperature (front): " << temperatures.front() << endl;
    cout << "Last day's temperature (back): " << temperatures.back() << endl;
    cout << "Temperature on day 10 (at): " << temperatures.at(9) << endl;
    cout << "Array size: " << temperatures.size() << endl;
    cout << "Is array empty? " << (temperatures.empty() ? "Yes" : "No") << endl;

    // Find min and max temperature using loops
    double minTemp = temperatures[0];
    double maxTemp = temperatures[0];
    for (size_t i = 1; i < DAYS; ++i)
    {
        if (temperatures[i] < minTemp)
            minTemp = temperatures[i];
        if (temperatures[i] > maxTemp)
            maxTemp = temperatures[i];
    }
    cout << "Lowest temperature: " << minTemp << endl;
    cout << "Highest temperature: " << maxTemp << endl;

    // Calculate average temperature using a loop
    double sum = 0.0;
    for (size_t i = 0; i < DAYS; ++i)
    {
        sum += temperatures[i];
    }
    cout << "Average temperature: " << sum / DAYS << endl;

    // Count days above 75 degrees using a loop
    int hot_days = 0;
    for (size_t i = 0; i < DAYS; ++i)
    {
        if (temperatures[i] > 75.0)
            hot_days++;
    }
    cout << "Days above 75 degrees: " << hot_days << endl;
}
