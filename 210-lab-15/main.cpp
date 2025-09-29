#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Movie {
private:
    string title;
    int yearReleased;
    string screenWriter;

public:
  // Constructors
  Movie() : yearReleased(0) {}
Movie(const string& t, int y, const string& w)
  : title(t), yearReleased(y), screenWriter(w) {}


