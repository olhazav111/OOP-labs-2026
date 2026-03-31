#include <iostream>
#include <utility>

#include "Book.h"
#include "EBook.h"
#include "LibraryCard.h"
#include "PrintedBook.h"
#include "Reader.h"
#include "StudentReader.h"


using namespace std;

void showBook(Book& book)
{
    book.displayInfo();
}


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

    cout << "\n----- Run-time Polymorphism demo -----\n";

    Book* book;

    PrintedBook pb("Clean Code", "Robert Martin", "123", 450);

    book = &pb;

    book->displayInfo();

    pb.printType();

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

    Book simpleBook("Simple Book", "Author", "555");
    PrintedBook printed2("C++ Guide","Bjarne","666",500);

    Book& ref = printed2;
    ref.displayInfo();


    simpleBook.displayInfo();
    printed2.displayInfo();

    return 0;
}