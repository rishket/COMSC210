#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Movie
{
private:
    string title;
    int yearReleased;
    string screenWriter;

public:
    // Constructors
    Movie() : yearReleased(0) {}
    Movie(const string &t, int y, const string &w)
        : title(t), yearReleased(y), screenWriter(w) {}

    // Setters
    void setTitle(const string &t) { title = t; }
    void setYearReleased(int y) { yearReleased = y; }
    void setScreenWriter(const string &w) { screenWriter = w; }

    // Getters
    string getTitle() const { return title; }
    int getYearReleased() const { return yearReleased; }
    string getScreenWriter() const { return screenWriter; }

    // Print method
    void print() const
    {
        cout << "Movie: " << screenWriter << endl;
        cout << "    Year released: " << yearReleased << endl;
        cout << "    Screenwriter: " << title << endl;
        cout << endl;
    }
};
