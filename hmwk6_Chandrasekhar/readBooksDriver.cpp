// CS1300 Fall 2019
// Author: Vignesh
// Recitation: 304 - Thanika
// Homework 6 - Problem # 4

#include<iostream>
#include<fstream>
#include<string>
#include "Book.h"
#include "Book.cpp"

using namespace std;

//split function from hmwk 4
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



int main(){
   //test 1
   Book books[10] = {};
   cout<<readBooks("readBooksFile.txt",books, 0, 10)<<endl;//expected: 2
   cout<<books[0].getAuthor()<<endl;//expected: Author A
   cout<<books[1].getAuthor()<<endl;//expected: Author B
   cout<<books[0].getTitle()<<endl;//expected: Book 1
   cout<<books[1].getTitle()<<endl;//expected: Book 2
   
   cout<<endl;
   //test 2
   Book books1[10];
   books1[0].setAuthor("Author Z");
   books1[0].setTitle("Book N");
   readBooks("readBooksFile.txt",books, 1, 10);
   cout<<books1[0].getTitle()<<endl; //expected: Book N
   cout<<books1[0].getAuthor()<<endl; //expected: Author Z
    
}