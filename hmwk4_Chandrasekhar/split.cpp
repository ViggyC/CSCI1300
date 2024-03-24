// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika!!
// Homework 4 - Problem # 6

#include<iostream>
#include<string>
using namespace std;


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


//helper method that prints each index in the new filled array
void printArray(string arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<endl;
        
    }
}

int main(){
    
    //test 1, expected: 3
    string words[4];
    cout << split("one small step",' ', words,6) << endl<<endl;
    printArray(words,4);
    
    //test 2, expected: 5
    string arr[6];
    cout << split("unintentionally",'n',arr,6) << endl<<endl;
    printArray(arr,6);
    
    //test 3, expected: 3
    string animals[6];
    cout << split("cow/big pig//fish",'/',animals,6) <<endl<< endl;
    printArray(animals,6);
}