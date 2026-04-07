#include "Book.h"

int Book::bookCount = 0;

Book::Book(std::string t, std::string a, std::string i)
        : title(t), author(a), isbn(i), available(true)
{
    bookCount++;
    std::cout << "Book created: " << title << std::endl;
}

Book::Book(std::string t) : Book(t, "Unknown", "000") {}

Book::Book(const Book& other)
{
    title = other.title;
    author = other.author;
    isbn = other.isbn;
    available = other.available;
    std::cout << "Book copied: " << title << std::endl;
}

Book::Book(Book&& other)
        : title(std::move(other.title)),
          author(std::move(other.author)),
          isbn(std::move(other.isbn)),
          available(other.available)
{
    other.title = "Moved";
    other.author = "";
    other.isbn = "";
    std::cout << "Book moved: " << title << std::endl;
}

Book::~Book()
{
    bookCount--;
    std::cout << "Book deleted: " << title << std::endl;
}

void Book::displayInfo() const
{
    std::cout << "Book: " << title
              << " | Author: " << author
              << " | Available: " << (available ? "Yes" : "No")
              << std::endl;
}

void Book::printDetails() const {
    std::cout << "[IPrintable Interface] ";
    displayInfo();
}

void Book::borrowBook()
{
    this->available = false;
}

void Book::returnBook()
{
    this->available = true;
}

int Book::getBookCount()
{
    return bookCount;
}

bool Book::operator!() const
{
    return !available;
}

bool Book::operator==(const Book& other) const
{
    return isbn == other.isbn;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << book.title << " | " << book.author << " | " << book.isbn;
    return os;
}

std::istream& operator>>(std::istream& is, Book& book)
{
    is >> book.title >> book.author >> book.isbn;
    return is;
}