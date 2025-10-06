#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Review {
    double rating;
    string comment;
    Review* next;
};

class Movie{private:
    string title;
    Review* head;

public:
    Movie() {
        head = nullptr;
    }

    Movie(string t) {
        title = t;
        head = nullptr;
    }

    void addReview(string comment) {
        double rating = (rand() % 41 + 10) / 10.0; // random 1.0 to 5.0
        Review* newNode = new Review;
        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;
        head = newNode;
    }

    void showReviews() {
        cout << "\nMovie: " << title << endl;
        if (head == nullptr) {
            cout << "  No reviews found.\n";
            return;
        }

        Review* temp = head;
        int count = 0;
        double total = 0.0;

int main()
{   
    srand(time(0));
    string comments[20];
    int commentCount = 0;
    
    ifstream file("reviews.txt");
    if(!file){
        cout << "Could not open the file!" << endl;
        return 1;
    }

    string line;
    while(getline(file, line)){
        if(!line.empty()){
            comments[commentCount++] = line;
        }
    }
    file.close();

    if (commentCount < 12) {
        cout << "Need at least 12 comments in reviews.txt\n";
        return 1;
    }

    Movie movies[4] = {
        Movie("The Lost Horizon"),
        Movie("Dreams of Steel"),
        Movie("Echoes of Tomorrow"),
        Movie("Quantum Breakpoint")
    };
    return 0;
}