#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <sstream>

#include "PrintedBook.h"
#include "EBook.h"

using namespace std;

vector<shared_ptr<Book>> library;

void logHistory(const string& message) {
    ofstream historyFile("history.txt", ios::app);
    if (historyFile.is_open()) {
        historyFile << "[LOG]: " << message << endl;
        historyFile.close();
    }
}

void saveToFile() {
    ofstream outFile("library.txt");
    if (!outFile) throw runtime_error("Could not open file for writing!");

    for (const auto& b : library) {
        if (dynamic_pointer_cast<PrintedBook>(b)) outFile << "P|";
        else outFile << "E|";
        outFile<< b->getTitle() << "|" << b->getAuthor() << "|"
                << b->getIsbn() << "|" << b->getExtraValue() << endl;
    }
    outFile.close();
}

void loadFromFile() {
    ifstream inFile("library.txt");
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string type, t, a, i, extra;

        getline(ss, type, '|');
        getline(ss, t, '|');
        getline(ss, a, '|');
        getline(ss, i, '|');
        getline(ss, extra, '|');

        if (type == "P")
            library.push_back(make_shared<PrintedBook>(t, a, i, stoi(extra)));
        else if (type == "E")
            library.push_back(make_shared<EBook>(t, a, i, stod(extra)));
    }
    inFile.close();
    cout << "--- Data successfully restored from file ---" << endl;
}

void adminMenu() {
    string pass;
    cout << "Enter admin password: ";
    cin >> pass;

    if (pass != "admin") {
        logHistory("Failed admin login attempt.");
        throw invalid_argument("Invalid password!");
    }

    logHistory("Admin logged in.");

    int adminChoice;
    while (true) {
        cout << "\n--- Admin Menu ---\n1. Add Printed Book\n2. Add E-Book\n3. Back\nChoice: ";
        if (!(cin >> adminChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (adminChoice == 3) break;

        string t, a, i;
        cout << "Title: "; cin.ignore(); getline(cin, t);
        cout << "Author: "; getline(cin, a);
        cout << "ISBN: "; getline(cin, i);

        if (adminChoice == 1) {
            int pages;
            cout << "Pages: "; cin >> pages;
            library.push_back(make_shared<PrintedBook>(t, a, i, pages));
        } else if (adminChoice == 2) {
            double size;
            cout << "File size (MB): "; cin >> size;
            library.push_back(make_shared<EBook>(t, a, i, size));
        }

        saveToFile();
        logHistory("Added new book: " + t);
        cout << "Book successfully added and saved!\n";
    }
}

void userMenu() {
    logHistory("User viewed the library.");

    int choice;
    while (true) {
        cout << "\n--- User Menu ---\n"
             << "1. View all books\n"
             << "2. Borrow a book\n"
             << "3. Return a book\n"
             << "4. Back\nChoice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 4) break;

        if (choice == 1) {
            cout << "\n--- Available Books ---" << endl;
            if (library.empty()) {
                cout << "Library is empty." << endl;
            } else {
                for (size_t i = 0; i < library.size(); ++i) {
                    cout << i + 1 << ". ";
                    library[i]->displayInfo();
                }
            }
        } else if (choice == 2 || choice == 3) {
            if (library.empty()) { cout << "Library is empty.\n"; continue; }

            cout << "\n--- Books ---\n";
            for (size_t i = 0; i < library.size(); ++i) {
                cout << i + 1 << ". ";
                library[i]->displayInfo();
            }

            cout << "Enter book number: ";
            int idx;
            if (!(cin >> idx) || idx < 1 || idx > (int)library.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number.\n";
                continue;
            }

            auto& book = library[idx - 1];
            if (choice == 2) {
                book->borrowBook();
                logHistory("User borrowed book: " + book->getTitle());
                cout << "Book \"" << book->getTitle() << "\" borrowed.\n";
            } else {
                book->returnBook();
                logHistory("User returned book: " + book->getTitle());
                cout << "Book \"" << book->getTitle() << "\" returned.\n";
            }
            saveToFile();
        }
    }
}

int main() {
    try {
        loadFromFile();

        int mainChoice;
        while (true) {
            cout << "\n=== Main Menu ===\n1. Admin\n2. User\n3. Exit\nChoice: ";
            if (!(cin >> mainChoice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input error. Please try again." << endl;
                continue;
            }

            try {
                if (mainChoice == 1) adminMenu();
                else if (mainChoice == 2) userMenu();
                else if (mainChoice == 3) {
                    logHistory("Program terminated by user.");
                    break;
                }
                else cout << "Invalid menu option!" << endl;
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                logHistory("Error during execution: " + string(e.what()));
            }
        }
    } catch (const exception& e) {
        cerr << "Critical system error: " << e.what() << endl;
    }

    return 0;
}