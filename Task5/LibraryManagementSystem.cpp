#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
};

struct BorrowRecord {
    string isbn;
    string borrowerName;
    int daysBorrowed;
};

void addBook(vector<Book> &books) {
    Book b;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, b.title);
    cout << "Enter author: ";
    getline(cin, b.author);
    cout << "Enter ISBN: ";
    getline(cin, b.isbn);
    b.available = true;
    books.push_back(b);
    cout << "Book added successfully.\n";
}

void searchBook(const vector<Book> &books) {
    int option;
    cout << "Search by: 1.Title  2.Author  3.ISBN\nEnter option: ";
    cin >> option;
    cin.ignore();
    string query;
    cout << "Enter search term: ";
    getline(cin, query);

    bool found = false;
    for (auto &b : books) {
        if ((option == 1 && b.title == query) ||
            (option == 2 && b.author == query) ||
            (option == 3 && b.isbn == query)) {
            cout << "Title: " << b.title << ", Author: " << b.author
                 << ", ISBN: " << b.isbn
                 << ", Status: " << (b.available ? "Available" : "Checked out") << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching book found.\n";
}

void checkoutBook(vector<Book> &books, vector<BorrowRecord> &records) {
    string isbn, borrower;
    cout << "Enter ISBN of book to checkout: ";
    cin.ignore();
    getline(cin, isbn);
    bool found = false;
    for (auto &b : books) {
        if (b.isbn == isbn && b.available) {
            cout << "Enter borrower's name: ";
            getline(cin, borrower);
            int days;
            cout << "Enter number of days borrowed: ";
            cin >> days;
            BorrowRecord r = {isbn, borrower, days};
            records.push_back(r);
            b.available = false;
            cout << "Book checked out successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Book not available or ISBN incorrect.\n";
}

void returnBook(vector<Book> &books, vector<BorrowRecord> &records) {
    string isbn;
    cout << "Enter ISBN of book to return: ";
    cin.ignore();
    getline(cin, isbn);
    bool found = false;

    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->isbn == isbn) {
            int lateDays;
            cout << "Enter late days (0 if none): ";
            cin >> lateDays;
            if (lateDays > 0) {
                int fine = lateDays * 2; // ₹2 per day fine
                cout << "Fine amount: ₹" << fine << "\n";
            }
            for (auto &b : books) {
                if (b.isbn == isbn) {
                    b.available = true;
                    break;
                }
            }
            records.erase(it);
            cout << "Book returned successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Record not found.\n";
}

int main() {
    vector<Book> books;
    vector<BorrowRecord> records;
    int choice;

    while (true) {
        cout << "\n--- LIBRARY MENU ---\n";
        cout << "1. Add Book\n2. Search Book\n3. Checkout Book\n4. Return Book\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addBook(books);
        else if (choice == 2) searchBook(books);
        else if (choice == 3) checkoutBook(books, records);
        else if (choice == 4) returnBook(books, records);
        else if (choice == 5) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}
