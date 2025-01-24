#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> // For changing text color and background
#include <limits>    // For input validation
using namespace std;

// Structure to store book details
struct Book {
    int id;
    string title;
    string author;
    Book* next;
};

class Library {
private:
    Book* head; // Head of the linked list
    int bookCount;

public:
    Library() : head(nullptr), bookCount(0) {}

    // Function to add a book
    void addBook() {
        Book* newBook = new Book;
        cout << "\nEnter Book ID: ";
        while (!(cin >> newBook->id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid Book ID: ";
        }
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, newBook->title);
        cout << "Enter Book Author: ";
        getline(cin, newBook->author);

        newBook->next = head;
        head = newBook;
        bookCount++;
        cout << "\nBook added successfully!\n";
    }

    // Function to delete a book
    void deleteBook() {
        if (!head) {
            cout << "\nNo books available to delete!\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to delete: ";
        while (!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid Book ID: ";
        }

        Book* temp = head;
        Book* prev = nullptr;

        while (temp && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "\nBook not found!\n";
            return;
        }

        if (!prev) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        bookCount--;
        cout << "\nBook deleted successfully!\n";
    }

    // Function to search for a book
    void searchBook() {
        if (!head) {
            cout << "\nNo books available to search!\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to search: ";
        while (!(cin >> id)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid Book ID: ";
        }

        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "\nBook Found:\n";
                cout << "ID: " << temp->id << "\n";
                cout << "Title: " << temp->title << "\n";
                cout << "Author: " << temp->author << "\n";
                return;
            }
            temp = temp->next;
        }

        cout << "\nBook not found!\n";
    }

    // Function to display all books
    void displayBooks() {
        if (!head) {
            cout << "\nNo books available!\n";
            return;
        }

        cout << "\nBooks in Library:\n";
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(20) << "Author" << endl;
        cout << string(60, '-') << endl;

        Book* temp = head;
        while (temp) {
            cout << left << setw(10) << temp->id << setw(30) << temp->title << setw(20) << temp->author << endl;
            temp = temp->next;
        }
    }

    // Function to change console colors
    void changeColor() {
        int choice;
        cout << "\nChoose Background Color:\n";
        cout << "1. Blue\n2. Green\n3. Red\n4. Default\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice: ";
        }

        switch (choice) {
        case 1:
            system("color 1F"); // Blue background, white text
            break;
        case 2:
            system("color 2F"); // Green background, white text
            break;
        case 3:
            system("color 4F"); // Red background, white text
            break;
        case 4:
            system("color 07"); // Default colors
            break;
        default:
            cout << "\nInvalid choice!\n";
        }
    }

    // Destructor to free memory
    ~Library() {
        while (head) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n========== Library Management System ==========";
        cout << "\n1. Add Book";
        cout << "\n2. Delete Book";
        cout << "\n3. Search Book";
        cout << "\n4. Display All Books";
        cout << "\n5. Change Background Color";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice: ";
        }

        switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2:
            library.deleteBook();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.displayBooks();
            break;
        case 5:
            library.changeColor();
            break;
        case 6:
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
