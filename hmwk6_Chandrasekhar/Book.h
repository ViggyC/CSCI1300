//header file for Book class
#ifndef BOOK
#define BOOK

#include <iostream>
#include <string>
using namespace std;

//creating a class called Book
class Book{
    
    //declaring public member functions
    public:
        Book();
        Book(string title, string author);
        string getTitle();
        void setTitle(string title);
        string getAuthor();
        void setAuthor(string author);
        
    //declaring private variables
    private:
        string title;
        string author;
};

#endif