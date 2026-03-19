#include <utility>
#include <iostream>

#include "Book.h"
#include "Reader.h"
#include "LibraryCard.h"
#include "PrintedBook.h"
#include "EBook.h"
#include "StudentReader.h"

using namespace std;

int main() {

    Book book1("Programming in C++", "Ivan Petrenko", "111-222");
    Book book2("Basics of Algorithms", "Unknown", "000");

    Reader reader1("Olha Zavialets", 1, 18);
    Reader reader2("Maria Koval", 2, 19);

    LibraryCard card1(1, "08.03.2026", reader1);
    LibraryCard card2(2, "10.03.2026", reader2);

    book1.displayInfo();
    reader1.displayProfile();
    card1.displayInfo();

    Book book3 = book1;

    Book book4 = std::move(book2);

    const Book book5("Const Book", "Author", "999");
    book5.displayInfo();

    cout << book1 << endl;

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

    return 0;
}