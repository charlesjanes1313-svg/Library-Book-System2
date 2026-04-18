#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    void setBookDetails(string t, string a, string i, bool available) {
        title = t;
        author = a;
        ISBN = i;
        isAvailable = available;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        if (isAvailable)
            cout << "Status: Available" << endl;
        else
            cout << "Status: Borrowed" << endl;
        cout << "---------------------------" << endl;
    }

    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    bool returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            return true;
        }
        return false;
    }

    string getISBN() {
        return ISBN;
    }

    string getTitle() {
        return title;
    }
};

int main() {
    Book library[5];
    int choice;
    string input;
    bool found;

    library[0].setBookDetails("1984", "George Orwell", "111", true);
    library[1].setBookDetails("Harry Potter", "J.K. Rowling", "222", true);
    library[2].setBookDetails("The Hobbit", "J.R.R. Tolkien", "333", true);
    library[3].setBookDetails("Clean Code", "Robert Martin", "444", true);
    library[4].setBookDetails("Rich Dad Poor Dad", "Robert Kiyosaki", "555", true);

    do {
        cout << "\n===== LIBRARY MENU =====" << endl;
        cout << "1. Display all books" << endl;
        cout << "2. Borrow book" << endl;
        cout << "3. Return book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\nLibrary Books:\n" << endl;
            for (int i = 0; i < 5; i++) {
                library[i].displayBookDetails();
            }
        }
        else if (choice == 2) {
            cout << "\nEnter the ISBN of the book you want to borrow: ";
            getline(cin, input);

            found = false;
            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == input) {
                    found = true;
                    if (library[i].borrowBook()) {
                        cout << "Book borrowed successfully." << endl;
                    } else {
                        cout << "This book is already borrowed." << endl;
                    }
                    break;
                }
            }

            if (!found) {
                cout << "Book not found." << endl;
            }
        }
        else if (choice == 3) {
            cout << "\nEnter the ISBN of the book you want to return: ";
            getline(cin, input);

            found = false;
            for (int i = 0; i < 5; i++) {
                if (library[i].getISBN() == input) {
                    found = true;
                    if (library[i].returnBook()) {
                        cout << "Book returned successfully." << endl;
                    } else {
                        cout << "This book is already available in the library." << endl;
                    }
                    break;
                }
            }

            if (!found) {
                cout << "Book not found." << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}