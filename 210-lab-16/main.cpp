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
    Color(int r, int g) : red(r), green(g), blue(0) {}
    Color(int r) : red(r), green(0), blue (0) {}
    Color(int b) : red(0), green(0), blue(b) {}
    Color(int g, int b) : red(0), green(g), blue(b) {}


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