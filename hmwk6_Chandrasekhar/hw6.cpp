// CS1300 Fall 2019
// Author: Vignesh
// Recitation: 304 - Thanika
// Homework 6 - Problem # 7

#include<iostream>
#include<fstream>
#include<string>
#include "Book.h"
#include "Book.cpp"

using namespace std;

//given menu function
void printMenu(){
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Print all books" << endl;
    cout << "3. Print books by author" << endl;
    cout << "4. Quit" << endl;
}

//split function
int split(string split, char delimeter, string arr[], int length){
    int count=0; //split counter which will be returned at the end
    int currentIndex=0; //pointer of the array
    int indexInArray=0; //index that will store the split pieces
    //empty strings return 0
    if(split==""){
        return 0;
    }
    
    //add a delimeter to the end of the string if there already isn't one there
    if(split[split.length()-1]!=delimeter){
        split+=delimeter;
    }
    //remove delimeter from beginning of the string
    if(split[0]==delimeter){
        split=split.substr(split.find(delimeter)+1);
    }
    
    //temportary string variable to be manipulated
    string temp = split; 
    
    //run through the split string
    for(int i=0; i<split.length();i++){
        
        //if the i equals the delimeter: do everything in the if statement
        if(split[i]==delimeter){

            currentIndex = temp.find(delimeter); //set the currentIndex at the location of the delimeter
            arr[indexInArray]=temp.substr(0, currentIndex); //fill the array with the substring starting at 0 to the currentIndex
            indexInArray++; //increment indexInArrat so that next index can be filled
            count++; //increment count because we have made a split
            temp = temp.substr(currentIndex+1); //change the temp string so that it now starts at the index after the index of the found delimeter
                
            
        }
        //check if the first index of the temp string is the delimeter
        if(temp[0]==delimeter){
            //if it is then remove the delimeter by shifting the entire string one index
            temp=temp.substr(temp.find(delimeter)+1);
            //subtract the count var because we did not split anything
            count--;
        }
        
    }
    //edge case: if count>length then return -1
    if(count>length){
        return -1;
    }
    //return the final count var
    return count;
}

////////////////////////////////////////////////////////////////////////////


//problem 4 function
int readBooks(string fileName, Book books[], int numBookStored, int booksArrSize){
    ifstream myfile; //create file object
    int count = numBookStored; //counter variable starts at the number of books already stored
    
    string line = ""; //create pointer string
    char delimiter = ','; //between author and title
    
    string tempArr[2]; //array will store split pieces from each line
    
    myfile.open(fileName); //open fileName
    
    if(myfile.fail()){ //if the file does not exist, return -1
        return -1;
    }
    if(numBookStored == booksArrSize){ //if numBookStored equals the size return -2
        return -2;
    }else if(myfile.is_open()){
        
        //get each line of the file while the count is less than the size
        //so there is no segmentation fault
        while(getline(myfile,line)&&count<booksArrSize){
           
            if(line!=""){
                
                if(count==booksArrSize){//if the count equals the size return the count
                    return count;
                }
                        
                split(line, delimiter, tempArr, 2);//split the line
                books[count]=Book(tempArr[1],tempArr[0]); //store contents in book object
                count++; //increment count to keep filling
            }
        }
    }
    myfile.close(); //closing file
    return count;
}

//problem 5 function
void printAllBooks(Book books[], int numBooks){
    if(numBooks<=0){ //if numBooks<=0, print that there are no books
        cout<<"No books are stored";
    }else{
        //otherwise show that there are books
        cout<<"Here is a list of books"<<endl;
        for(int i = 0; i<numBooks; i++){
            //print the books title and author using getter methods from implementation file
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;
        }
    }
}

//problem 6 function
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

//driver function for this problem
void driver(){
    Book books[50]; //create array of books with size 50
    int choice; //choice for user
    int nb =0; //initialize number of books 
    string fileName; //declare file name
    while(choice!=4){
        printMenu();//continuously print menu
        cin>>choice; //read user's choice
        if(choice!=1 && choice!=2 &&choice!=3 && choice!=4){ //invalid options test
            cout<<"Invalid input."<<endl;
        }else if(choice==1){
            cout<<"Enter a book file name: "<<endl;
            cin>>fileName; //read filename
            nb=readBooks(fileName, books, nb, 50); //get nb from readBooks function
            if(nb==-1){
                cout<<"No books saved to the database."<<endl;
            }else if(nb==-2){
                cout<<"Database is already full. No books were added."<<endl;
            }else if(nb==50){
                cout<<"Database is full. Some books may have not been added."<<endl;
            }else{
                cout<<"Total books in the database: "<<nb<<endl; //print nb
            }
        }else if(choice==2){
            printAllBooks(books, nb); //calling problem 4 function with nb found above
        }else if(choice==3){
            string name; 
            cout<<"Enter name of author: "<<endl;
            cin.ignore(); //ignore delimiters till eof
            getline(cin, name); //get the name from getline()
            printBooksByAuthor(books, nb, name); //calling problem 5 function with nb found above
        }else{
            cout<<"Good bye!"<<endl; //option 4
            return;
        }
    }
}

int main(){
    //calling driver
    driver();
}

