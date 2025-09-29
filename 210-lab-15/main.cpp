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

int main()
{
    ifstream inFile("input.txt");
    if (!inFile)
    {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    vector<Movie> movies;
    string title, writer;
    int year;

        while (true) {
        // Read title
        if (!getline(inFile, title)) break;

        // Read year
        if (!(inFile >> year)) break;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // consume leftover newline

        // Read screenwriter
        if (!getline(inFile, writer)) break;

        // Build movie object
        Movie temp(title, year, writer);

        // Append to vector
        movies.push_back(temp);
    }
    
    for (const auto& m : movies) {
        m.print();
    }

    return 0;
}
