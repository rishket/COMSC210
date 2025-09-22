#include <iostream>
#include <string>

using namespace std;

// Struct to represent a Student
struct Student
{
    string name; // Student's name
    int id;           // Student's ID
    double* grades;   // Dynamic array to store grades
    int numGrades;    // Number of grades

    // Constructor to initialize a student with a name, id, and number of grades
    Student(const string &n, int i, int numG) : name(n), id(i), numGrades(numG)
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
void printStudent(const Student& s)
{
    cout << "Name: " << s.name << ", ID: " << s.id << "\nGrades: ";
    for (int i = 0; i < s.numGrades; ++i)
    {
        cout << s.grades[i];
        if (i < s.numGrades - 1)
        cout << ", ";
    }
    cout << endl;
}

int main()
{
    int numStudents = 3;
    // Create an array of pointers to Student
    Student** students = new Student*[numStudents];

    // Allocate each student individually
    students[0] = new Student("Alice", 1, 3); // Alice has 3 grades
    students[1] = new Student("Bob", 2, 4);   // Bob has 4 grades
    students[2] = new Student("Charlie", 3, 2); // Charlie has 2 grades

    // Assigning grades to each student
    students[0]->grades[0] = 88.5;
    students[0]->grades[1] = 92.0;
    students[0]->grades[2] = 85.0;

    students[1]->grades[0] = 75.0;
    students[1]->grades[1] = 80.5;
    students[1]->grades[2] = 78.0;
    students[1]->grades[3] = 82.0;

    students[2]->grades[0] = 90.0;
    students[2]->grades[1] = 87.5;

    // Print all students and their grades
    for(int i = 0; i < numStudents; ++i){
        printStudent(*students[i]);
    }

    // Free memory for each student
    for(int i = 0; i < numStudents; ++i){
        delete students[i];
    }
    delete[] students; // Free the array of pointers

    return 0;
}