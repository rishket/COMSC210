#include <iostream>
using namespace std;

// Constants for random number generation and list size limits
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList
{
private:
    // Node structure for doubly linked list
    struct Node
    {
        int data;   // Stores the value in the node
        Node *prev; // points to the previous node in the list
        Node *next; // Point to the next node in the list
        // Constructor initializes a node with a value and optional prev/next pointers
        Node(int val, Node *p = nullptr, Node *n = nullptr)
        {
            data = val; // Set the nodes data
            prev = p;   // Set the previous pointer
            next = n;   // Set the next pointer
        }
    };

    Node *head; // Points to the first node in the list
    Node *tail; // Points to the last node in the listpublic:
    // Constructor: Initialize an empty list with null head and tail pointers
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // Insert a new node with given value after the specified position
    void insert_after(int value, int position) {
        // Check for valid position
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        // Create new node with the given value
        Node* newNode = new Node(value);
        // If list is empty, make new node both head and tail
        if (!head) {
            head = tail = newNode;
            return;
        }

        // Traverse to the position where we want to insert
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        // If position exceeds list size, clean up and return
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        // Connect new node to its neighbors
        newNode->next = temp->next;
        newNode->prev = temp;
        // If not inserting at end, update next node's prev pointer
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;  // If inserting at end, update tail
        temp->next = newNode;  // Connect current node to new node
    }

    // Delete the first node that contains the specified value
    void delete_val(int value) {
        // Return if list is empty
        if (!head) return;

        // Start search from head
        Node* temp = head;
        
        // Search for node with matching value
        while (temp && temp->data != value)
            temp = temp->next;

        // If value not found, return
        if (!temp) return; 

        // If node has a previous node, update its next pointer
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;  // If deleting head, update head pointer

        // If node has a next node, update its prev pointer
        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;  // If deleting tail, update tail pointer

        // Free the memory of deleted node
        delete temp;
    }

    // Delete node at specified position (1-based indexing)
    void delete_pos(int pos)
    {
        // Check if list is empty
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        // base case: deleting first node
        if (pos == 1)
        {
            pop_front();
            return;
        }

        // Start traversal from head
        Node *temp = head;

        // Move to the specified position
        for (int i = 1; i < pos; i++)
        {
            if (!temp)
            {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        // Verify position exists
        if (!temp)
        {
            cout << "Position doesn't exist." << endl;
            return;
        }

        // Special case: deleting last node
        if (!temp->next)
        {
            pop_back();
            return;
        }

        // Update pointers and delete node
        Node *tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    // Add new node with value v at the end of the list
    void push_back(int v)
    {
        // Create new node with given value
        Node *newNode = new Node(v);
        // If list is empty, set both head and tail to new node
        if (!tail)
            head = tail = newNode;
        else
        {
            // Link new node to current tail
            tail->next = newNode;
            newNode->prev = tail;
            // Update tail to new node
            tail = newNode;
        }
    }

    // Add new node with value v at the beginning of the list
    void push_front(int v)
    {
        // Create new node with given value
        Node *newNode = new Node(v);
        // If list is empty, set both head and tail to new node
        if (!head)
            head = tail = newNode;
        else
        {
            // Link new node to current head
            newNode->next = head;
            head->prev = newNode;
            // Update head to new node
            head = newNode;
        }
    }

    // Remove the first node from the list
    void pop_front()
    {
        // Check if list is empty
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        // Store current head to delete later
        Node *temp = head;

        // If there's more than one node
        if (head->next)
        {
            head = head->next;     // Move head to next node
            head->prev = nullptr;  // Remove link to old head
        }
        else
            head = tail = nullptr; // List becomes empty
        delete temp;              // Free memory of old head
    }

    // Remove the last node from the list
    void pop_back()
    {
        // Check if list is empty
        if (!tail)
        {
            cout << "List is empty." << endl;
            return;
        }
        // Store current tail to delete later
        Node *temp = tail;

        // If there's more than one node
        if (tail->prev)
        {
            tail = tail->prev;     // Move tail to previous node
            tail->next = nullptr;  // Remove link to old tail
        }
        else
            head = tail = nullptr; // List becomes empty
        delete temp;              // Free memory of old tail
    }

    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void every_other_element()
    {
        Node *current = head;
        int count = 1;

        while (current)
        {
            if (count % 2 == 1)
            {
                cout << current->data << " ";
            }
            current = current->next;
            count++;
        }
        cout << endl;
    }

    void print()
    {
        Node *current = head;
        if (!current)
        {
            cout << "List is empty." << endl;
            return;
        }
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse()
    {
        Node *current = tail;
        if (!current)
        {
            cout << "List is empty." << endl;
            return;
        }
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main()
{
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning

    return 0;
}