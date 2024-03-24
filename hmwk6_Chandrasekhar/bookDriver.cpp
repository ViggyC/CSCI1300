// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 - Thanika
// Homework 6 - Problem # 3
#include "Book.h"
#include "Book.cpp"
#include <iostream>
using namespace std;

int main(){
    //test cases below, creating multiple objects and calling their member functions
    Book b1; //b1 object of Book Class
    Book b2("Harry Potter", "J.K Rowling"); //b2 object of Book class
    cout<<b2.getAuthor()<<endl; //getting b2 author
    cout<<b2.getTitle()<<endl; //getting b2 title
    b2.setAuthor("Voldemort"); //changing b2 author name to Voldemort
    cout<<b2.getAuthor()<<endl; //getting new b2 name
}