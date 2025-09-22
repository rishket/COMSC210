#include <iostream>
#include <string>

using namespace std;

// Struct to represent a Student
struct Student
{
    std::string name; // Student's name
    int id;           // Student's ID
    double *grades;   // Dynamic array to store grades
    int numGrades;    // Number of grades

    // Constructor to initialize a student with a name, id, and number of grades
    Student(const std::string &n, int i, int numG) : name(n), id(i), numGrades(numG)
    {
        grades = new double[numGrades]; // Allocate dynamic array for grades
    }
    // Destructor to free the dynamic array
    ~Student()
    {
        delete[] grades;
    }
};

// Function to print a student's info and grades
void printStudent(const Student &s)
{
    std::cout << "Name: " << s.name << ", ID: " << s.id << "\nGrades: ";
    for (int i = 0; i < s.numGrades; ++i)
    {
        std::cout << s.grades[i];
        if (i < s.numGrades - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

    int main()
    {

        return 0;
    }