#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Review {
    double rating;
    string comment;
    Review* next;
};

void addToHead(Review*& head, double rating, const string& comment){
    Review* newNode = new Review{rating, comment, head};
    head = newNode;
}


void addToTail(Review*& head, double rating, const string& comment) {
    Review* newNode = new Review{rating, comment, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Review* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void displayReviews(Review* head) {
    int count = 0;
    double sum = 0.0;
    Review* temp = head;

    cout << "\nOutputting all reviews:\n";
    while (temp) {
        ++count;
        cout << "    > Review #" << count << ": " << temp->rating << ": " << temp->comment << '\n';
        sum += temp->rating;
        temp = temp->next;
    }

    if (count > 0){
        cout << "  > Average rating: " << fixed << setprecision(3) << (sum / count) << '\n';
    } else {
        cout << "  > No reviews to display.\n";
    }
}


void freeList(Review* head) {
    while (head) {
        Review* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    Review* head = nullptr;
    int choice;

    cout << "Which linked list method should we use?: " << endl;
    cout << "[1] New nodes added to the head" << endl;
    cout << "[2] New nodes added to the tail" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore();

    bool addAtHead = (choice == 1);

    while (true){
        double rating;
        string comment;
        char another;

        cout << "Enter rating (0.0 - 5.0): ";
        cin >> rating;
        cin.ignore();

        cout << "Enter comment: ";
        getline(cin, comment);

        if(addToHead){
            addToHead(head, rating, comment);
        }
        else{
            addToTail(head, rating, comment);
        }

        cout << "Enter another review? (y/n): ";
        cin >> another;
        cin.ignore();
        if(another == 'n' || another == 'N'){
            break;
        }
    }

    displayReviews(head);
    freeList(head);
    return 0; 
}
