// CS1300 Fall 2019
// Author: my name
// Recitation: 304 - Thanika
// Homework 5 - Problem # 3

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<sstream>
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

//function from previous problem, for test cases
int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size){
    ifstream myfile; 
    int count = numBookStored;
    
    string line = "";
    char delimiter = ','; //between author and title
    
    string tempArr[2]; //array will store split pieces from each line
    
    myfile.open(fileName);
    
    if(myfile.fail()){
        return -1;
    }
    if(numBookStored == size){
        return -2;
    }else if(myfile.is_open()){
        
        while(getline(myfile,line)&&count<size){
           
            if(line!=""){
                    
                if(count==size){
                    return count;
                }
                        
                    
                split(line, delimiter, tempArr, 2);
                string authorNames = tempArr[0];
                string bookTitle = tempArr[1];
                authors[count] = authorNames;
                titles[count] = bookTitle;
                count++;
            }
        }
    }
       
    
    myfile.close(); //closing file
    return count;
}

//function of this problem, just prints the contents of the array
void printAllBooks(string titles[], string authors[], int numBooks){
    if(numBooks<=0){ //if numBooks<=0, print that there are no books
        cout<<"No books are stored";
    }else{
        //otherwise show that there are books
        cout<<"Here is a list of books"<<endl;
        //print titles and books using for loop
        //we get this from the method above
        for(int i = 0; i<numBooks; i++){
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
}

int main(){
    //test 1
    string authors[10] = {};
    string titles[10] = {};
    int nb = readBooks("books.txt",titles,authors, 0, 10);
    printAllBooks(titles, authors, nb);
    
    cout<<endl;
    
    //test 2
    string authors1[10] = {};
    string titles2[10] = {};
    int nb1 = readBooks("myFile.txt",titles,authors, 0, 10);
    printAllBooks(titles, authors, nb1);
}