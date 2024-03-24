// CS1300 Fall 2019
// Author: Vignesh
// Recitation: 304 - Thanika
// Homework 5 - Problem # 2

#include<iostream>
#include<fstream>
#include<string>

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


int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size){
    ifstream myfile; //create file object
    int count = numBookStored; //counter variable starts at the number of books already stored
    
    string line = ""; //create pointer string
    char delimiter = ','; //between author and title
    
    string tempArr[2]; //array will store split pieces from each line
    
    myfile.open(fileName); //open fileName
    
    if(myfile.fail()){ //if the file does not exist, return -1
        return -1;
    }
    if(numBookStored == size){ //if numBookStored equals the size return -2
        return -2;
    }else if(myfile.is_open()){
        
        //get each line of the file while the count is less than the size
        //so there is no segmentation fault
        while(getline(myfile,line)&&count<size){
           
            if(line!=""){
                
                if(count==size){//if the count equals the size return the count
                    return count;
                }
                        
                
                split(line, delimiter, tempArr, 2);//split the line
                string authorNames = tempArr[0]; //author goes in first index 
                string bookTitle = tempArr[1]; //title goes in second index
                authors[count] = authorNames; //store that value in the author array
                titles[count] = bookTitle; //store that value in the title array
                count++; //increment count to keep filling
            }
        }
    }
       
    
    myfile.close(); //closing file
    return count;
}

//helper method prints content of the arrays
void printArray(string authors[], string titles[], int size){
    for(int i=0; i<size; i++){
        cout<<titles[i]<< " by "<<authors[i]<<endl;
    }
}

int main(){
    //test 1, expected: 10
    int numbooks = 0;
    string std_titles[10]; 
    string std_authors[10];
    numbooks = readBooks("books.txt", std_titles, std_authors, numbooks, 10);
    cout << "Function returned value: "<< numbooks << endl;
    printArray(std_authors,std_titles,10);
    
    cout<<endl;
    //test 2, expected: -1
    cout<<readBooks("DNEfile.txt", std_titles, std_authors, numbooks,10);
}