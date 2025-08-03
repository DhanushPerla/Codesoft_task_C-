#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
    time_t dueDate;
};

struct Borrower {
    string name;
    string isbn;
};

vector<Book> books;
vector<Borrower> borrowers;

void addBook() {
    Book book;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter Author: ";
    getline(cin, book.author);
    cout << "Enter ISBN: ";
    getline(cin, book.isbn);
    book.available = true;
    book.dueDate = 0;
    books.push_back(book);
    cout << "Book added successfully!\n";
}

void viewBooks() {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }
    cout << "\n--- Book List ---\n";
    for (size_t i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i].title << " by " << books[i].author
             << " | ISBN: " << books[i].isbn
             << " | " << (books[i].available ? "Available" : "Checked out") << endl;
    }
}

void searchBook() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);
    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(query) != string::npos ||
            book.author.find(query) != string::npos ||
            book.isbn.find(query) != string::npos) {
            cout << "Found: " << book.title << " by " << book.author
                 << " | ISBN: " << book.isbn
                 << " | " << (book.available ? "Available" : "Checked out") << endl;
            found = true;
        }
    }
    if (!found) cout << "No matching book found.\n";
}

void checkoutBook() {
    string isbn, name;
    cout << "Enter ISBN of the book: ";
    cin.ignore();
    getline(cin, isbn);
    for (auto& book : books) {
        if (book.isbn == isbn && book.available) {
            cout << "Enter borrower's name: ";
            getline(cin, name);
            book.available = false;
            book.dueDate = time(0) + (7 * 24 * 60 * 60); // Due in 7 days
            borrowers.push_back({name, isbn});
            cout << "Book checked out successfully! Due in 7 days.\n";
            return;
        }
    }
    cout << "Book not available or not found.\n";
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    cin.ignore();
    getline(cin, isbn);
    for (auto& book : books) {
        if (book.isbn == isbn && !book.available) {
            time_t now = time(0);
            if (now > book.dueDate) {
                double daysOverdue = difftime(now, book.dueDate) / (60 * 60 * 24);
                double fine = daysOverdue * 2.0; // ₹2 per day
                cout << "Book is overdue by " << daysOverdue << " days. Fine: ₹" << fine << endl;
            } else {
                cout << "Book returned on time.\n";
            }
            book.available = true;
            book.dueDate = 0;
            return;
        }
    }
    cout << "Book not found or already available.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- LIBRARY MANAGEMENT MENU ---\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
    return 0;
}
