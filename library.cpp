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
    }

    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        isAvailable = true;
    }

    string getISBN() {
        return ISBN;
    }
};

int main() {
    Book b;
    b.setBookDetails("Sample Book", "Author Name", "123", true);
    b.displayBookDetails();

    return 0;
}