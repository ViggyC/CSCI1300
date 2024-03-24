//implementation file for Book class
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;


//creating default constructor
Book::Book(){
    title = "";
    author = "";
}

//creating overloaded constructor
Book::Book(string t, string a){
    title = t;
    author = a;
}

//get method for book title
string Book::getTitle(){
    return title;
}

//setter method for book title
void Book::setTitle(string t){
    title = t;
}

//getter method for author
string Book::getAuthor(){
    return author;
}

//setter method for author
void Book::setAuthor(string a){
    author = a;
}