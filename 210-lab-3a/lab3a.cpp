#include <iostream>
#include <string>

using namespace std;

struct Restaurant{
  int rating;
  string name;
  char cuisine[20];
  float averagePrice;
  double employeeSalaryAvg;
}
Restaurant addRestaurant();
void displayRestaurant(const Restaurant& r);

int main() {
    const int NUM_RESTAURANTS = 4;
    Restaurant restaurants[NUM_RESTAURANTS];

    cout << "Enter data for " << NUM_RESTAURANTS << " restaurants.\n";

    for (int i = 0; i < NUM_RESTAURANTS; i++) {
        cout << "\nRestaurant #" << (i + 1) << ":\n";
        restaurants[i] = createRestaurant();
    }

    cout << "\nDisplaying all restaurant data:\n";
    for (int i = 0; i < NUM_RESTAURANTS; i++) {
        displayRestaurant(restaurants[i]);
    }

    return 0;
}

Restaurant addRestaurant(){

  Restaurant temp;
  cout << "\nEnter the Restauarant rating (out of 10)" << endl;
  getline(cin, temp.rating);
  cout << "\nEnter Restaurant Name: " << endl;
  getline(cin, temp.name);
  cout << "Enter the type of cuisine offered by this restaurant: (one word)" << endl;
  getline(cin, temp.cuisine);
  cout << "Enter the average price of a dinner meal: " << endl;
  getline(cin, temp.averagePrice);
  cout << "Enter the average employee salary: " << endl;
  getline(cin, temp.employeeSalaryAvg);
  cin.ignore();

  return temp;
}

void displayRestaurant(const Restaurant& r) {
    cout << "\n--- Restaurant Information ---\n";
    cout << "Name: " << r.name << endl;
    cout << "Address: " << r.address << endl;
    cout << "Cuisine Type: " << r.cuisineType << endl;
    cout << "Rating: " << r.rating << " stars" << endl;
    cout << "Average Price: $" << r.averagePrice << endl;
    cout << "------------------------------\n";
}
