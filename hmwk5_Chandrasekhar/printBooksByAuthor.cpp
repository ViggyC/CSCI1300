// CS1300 Fall 2019
// Author: my name
// Recitation: 304 - Thanika
// Homework 5 - Problem # 4

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void printBooksByAuthor(string titles[], string authors[], int numBooks, string name){
    //if numBooks<=0, print that are are no books stored
    if(numBooks<=0){
        cout<<"No books are stored";
        return;
    }
    
    int count = 0; //counter variable iterates thru author array
    for(int i = 0; i<numBooks; i++){
        if(authors[i]==name){ //if the index in the array matches the name, increment count
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
        if(authors[i]==name){ //go through again and find the author
            cout<<titles[i]<<endl; //and print the book that he/she wrote
        }
    }
    
        
    
}

int main(){
    //test 1
    string titles[3] = {"Book 1", "Book 2", "Book 3"};
    string authors[3] = {"Author A", "Author B", "Author A"};
    int numBooks = 3;
    string author = "Author A";
    printBooksByAuthor(titles, authors, numBooks, author);
    
    cout<<endl;
    
    //test 2, expected: there are no books by Author A
    string titles1[3] = {"Book 1", "Book 2", "Book 3"};
    string authors1[3] = {"Author B", "Author C", "Author D"};
    int numBooks1 = 3;
    string author1 = "Author A";
    printBooksByAuthor(titles1, authors1, numBooks1, author1);
}