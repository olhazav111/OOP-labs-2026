cmake_minimum_required(VERSION 4.0)
project(untitled8)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled8
        main.cpp
        Book.cpp
        Book.h
        Reader.cpp
        Reader.h
        LibraryCard.cpp
        LibraryCard.h
        PrintedBook.cpp
        PrintedBook.h
        EBook.cpp
        EBook.h
        StudentReader.cpp
        StudentReader.h
)
