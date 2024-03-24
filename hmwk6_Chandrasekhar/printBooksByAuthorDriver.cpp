// CS1300 Fall 2019
// Author: Vignesh
// Recitation: 304 - Thanika
// Homework 6 - Problem # 6

#include<iostream>
#include<fstream>
#include<string>
#include "Book.h"
#include "Book.cpp"

using namespace std;

void printBooksByAuthor(Book books[], int numBooks, string name){
    //if numBooks<=0, print that are are no books stored
    if(numBooks<=0){
        cout<<"No books are stored";
        return;
    }
    
    int count = 0; //counter variable iterates thru author array
    for(int i = 0; i<numBooks; i++){
        if(books[i].getAuthor()==name){ //if the index in the array matches the name, increment count
            count++;
        }
    }
    //if we could not find the author above, print that we couldn't
    //and then exit the function
    if(count==0){
        cout<<"There are no books by "<<name<<endl;
        return;
    }
    //if we found the desired author then....
    cout<<"Here is a list of books by "<<name<<endl;
    for(int i = 0; i<numBooks; i++){
        if(books[i].getAuthor()==name){ //go through again and find the author
            cout<<books[i].getTitle()<<endl; //and print the book that he/she wrote
        }
    }
}


int main(){
    //test 1
    Book book1 = Book("Book 1", "Author A");
    Book book2 = Book("Book 2", "Author B");
    Book book3 = Book("Book 3", "Author A");
    Book listOfBooks[3] = {book1, book2, book3};
    int numberOfBooks = 3;
    string author = "Author A";
    printBooksByAuthor(listOfBooks, numberOfBooks, author);
    cout<<endl;
    
    //test 2
    Book listOfBooks1[5] = {};
    int numberOfBooks1 = 0;
    string author1 = "Dan Brown";
    printBooksByAuthor(listOfBooks1, numberOfBooks1, author1);
    
}