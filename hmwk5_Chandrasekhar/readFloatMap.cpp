// CS1300 Fall 2019
// Author: my name
// Recitation: 304 - Thanika
// Homework 5 - Problem # 6

#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
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


int readFloatMap(string fileName, double arr[][4],int rows){
    
    string line = "";
    int i=0;
    string temp[4];
    
    ifstream myfile;
    myfile.open(fileName);
    
    if(myfile.fail())
    {
        return -1;
    }
    else if(myfile.is_open())
    {
        while(getline(myfile, line))
        {
            if(line != "")
            {
                split(line, ',', temp, 4);
                arr[i][0]= stod(temp[0]);
                arr[i][1]= stod(temp[1]);
                arr[i][2]= stod(temp[2]);
                arr[i][3]= stod(temp[3]);
                i++;
                
            }
        } 
    }
    
    myfile.close();
    return i;
}

//helper method that prints contents in the array
void printArray(double arr[][4], int len){
    for(int i = 0; i<len; i++){
        for(int j=0; j<4; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int main(){
    //test 1, expected: There are 4 lines
    double floatMap[4][4];
    cout<<"There are "<<readFloatMap("floodMap.txt", floatMap, 4)<<" lines."<<endl;
    printArray(floatMap,4); //print floatMap.txt
    
    cout<<endl;
    
    //test 2, expected: -1
    double floatMap1[2][4];
    cout<<readFloatMap("notThisFile.txt", floatMap1, 2);
    
}