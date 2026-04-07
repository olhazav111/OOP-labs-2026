#include <iostream>
#include <utility>

#include "Book.h"
#include "EBook.h"
#include "LibraryCard.h"
#include "PrintedBook.h"
#include "Reader.h"
#include "StudentReader.h"
#include "IPrintable.h"

using namespace std;

void showBook(Book& book)
{
    book.displayInfo();
}

int main() {

    PrintedBook book1("Programming in C++", "Ivan Petrenko", "111-222", 300);
    PrintedBook book2("Basics of Algorithms", "Unknown", "000", 150);

    Reader reader1("Olha Zavialets", 1, 18);
    Reader reader2("Maria Koval", 2, 19);

    LibraryCard card1(1, "08.03.2026", reader1);
    LibraryCard card2(2, "10.03.2026", reader2);

    book1.displayInfo();
    reader1.displayProfile();
    card1.displayInfo();

    PrintedBook book3 = book1;

    PrintedBook book4 = std::move(book2);

    const PrintedBook book5("Const Book", "Author", "999", 100);
    book5.displayInfo();

    cout << book1 << endl;

    cout << "\n----- Run-time Polymorphism demo -----\n";

    Book* bookPtr;

    PrintedBook pb("Clean Code", "Robert Martin", "123", 450);

    bookPtr = &pb;
    bookPtr->displayInfo();
    bookPtr->printType();

    cout << "Total books: " << Book::getBookCount() << endl;

    if(!book1)
        cout << "Book is not available" << endl;

    if(book1 == book3)
        cout << "Books have same ISBN" << endl;

    cout << "\n----- Inheritance demo -----\n";

    PrintedBook printed("Clean Code","Robert Martin","333",450);
    EBook ebook("Design Patterns","Gamma","444",6.2);

    StudentReader student("Olha Zavialets",3,18,"LNU");

    printed.displayInfo();
    ebook.displayInfo();
    student.displayProfile();

    cout << "\n----- Static Binding demo -----\n";

    PrintedBook simpleBook("Simple Book", "Author", "555", 120);
    PrintedBook printed2("C++ Guide","Bjarne","666",500);

    Book& ref = printed2;
    ref.displayInfo();

    simpleBook.displayInfo();
    printed2.displayInfo();

    cout << "\n----- Task 8: Interface & Pure Virtual Functions -----\n";

    IPrintable* elements[2];
    elements[0] = new PrintedBook("C++ Primer", "Lippman", "555", 1000);
    elements[1] = new StudentReader("Oleh", 123, 20, "LPNU");

    for(int i = 0; i < 2; i++) {
        elements[i]->printDetails();
    }

    for(int i = 0; i < 2; i++) {
        delete elements[i];
    }

    return 0;
}