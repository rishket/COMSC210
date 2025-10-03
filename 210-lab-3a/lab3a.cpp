#include <iostream>
#include <string>

using namespace std;

struct Restaurant {
    int rating;
    string name;
    char cuisine[20];        
    float averagePrice;
    double employeeSalaryAvg;
};


Restaurant addRestaurant();
void displayRestaurant(const Restaurant& r);

int main() {
    const int NUM_RESTAURANTS = 4;
    Restaurant restaurants[NUM_RESTAURANTS];

    cout << "Enter data for " << NUM_RESTAURANTS << " restaurants.\n";

    for (int i = 0; i < NUM_RESTAURANTS; i++) {
        cout << "\nRestaurant #" << (i + 1) << ":\n";
        restaurants[i] = addRestaurant();
    }

    cout << "\nDisplaying all restaurant data:\n";
    for (int i = 0; i < NUM_RESTAURANTS; i++) {
        displayRestaurant(restaurants[i]);
    }

    return 0;
}

Restaurant addRestaurant() {
    Restaurant temp;

    cout << "Enter the restaurant rating (out of 10): ";
    cin >> temp.rating;
    while (cin.fail() || temp.rating < 0 || temp.rating > 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter rating between 0 and 10: ";
        cin >> temp.rating;
    }

    cin.ignore();

    cout << "Enter Restaurant Name: ";
    getline(cin, temp.name);

    cout << "Enter the type of cuisine offered (one word): ";
    cin >> temp.cuisine;

    cout << "Enter the average price of a dinner meal: ";
    cin >> temp.averagePrice;
    while (cin.fail() || temp.averagePrice < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number: ";
        cin >> temp.averagePrice;
    }

    cout << "Enter the average employee salary: ";
    cin >> temp.employeeSalaryAvg;
    while (cin.fail() || temp.employeeSalaryAvg < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number: ";
        cin >> temp.employeeSalaryAvg;
    }

    cin.ignore();

    return temp;
}

void displayRestaurant(const Restaurant& r) {
    cout << "\n--- Restaurant Information ---\n";
    cout << "Name: " << r.name << endl;
    cout << "Cuisine Type: " << r.cuisine << endl;
    cout << "Rating: " << r.rating << " / 10" << endl;
    cout << "Average Meal Price: $" << r.averagePrice << endl;
    cout << "Average Employee Salary: $" << r.employeeSalaryAvg << endl;
    cout << "------------------------------\n";
}
