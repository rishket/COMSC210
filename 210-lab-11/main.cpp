#include <iostream>
#include <string>

using namespace std;

// Struct to represent a Student
struct Student
{
    string name; // Student's name
    int id;           // Student's ID
    double *grades;   // Dynamic array to store grades
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
void printStudent(const Student &s)
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
    Student* students = new Student[numStudents]{
        Student("Alice", 1, 3),
        Student("Bob", 2, 4),
        Student("Charlie", 3, 2)
        };

        //Assigning grades to each student
        students[0].grades[0] = 88.5;
        students[0].grades[1] = 92.0;
        students[1].grades[0] = 75.0;
        students[1].grades[1] = 80.5;
        students[1].grades[2] = 78.0;

        students[2].grades[0] = 90.0;

        for(int i = 0; i < numStudents; i++){
            printStudent(students[i]);
        }

        delete[] students; // Free the dynamic array of students

        return 0;
    }