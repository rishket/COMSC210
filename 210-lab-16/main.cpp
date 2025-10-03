#include <iostream>
#include <iomanip>

using namespace std;

class Color
{
private:
    int red;
    int green;
    int blue;

public:
   // Default constructor
    Color() : red(0), green(0), blue(0) {}

    // Full parameter constructor (r, g, b)
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    //Partial parameter constructors
    Color(int r, int g = 0, int b = 0) : red(r), green(g), blue(b) {} // red only
    Color(int r = 0, int g = 0, int b) : red(0), green(g), blue(b) {} // blue only
    Color(int r = 0, int g, int b = 0) : red(0), green(g), blue(b) {} // green only
    Color(int r, int g, int b = 0) : red(r), green(g), blue(0) {} // red and green
    Color(int r = 0, int g, int b) : red(r), green(g), blue(b) {} // green and blue
    Color(int r, int g = 0, int b) : red(r), green(g), blue(b) {} // red and blue


    // Getters
    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }

    // Setters
    void setRed(int r)
    {
        red = r;
    }
    void setGreen(int g)
    {
        green = g;
    }
    void setBlue(int b)
    {
        blue = b;
    }

    // Print method
    void print() const
    {
        cout << "Color(R:" << setw(3) << red << " G:" << setw(3) << green << " B:" << setw(3) << blue << ")" << endl;
    }
};

int main()
{
    cout << "testing\n" << endl;
    return 0;
}