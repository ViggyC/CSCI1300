// CS1300 Fall 2019
// Author: my name
// Recitation: 304 - Thanika
// Homework 5 - Problem # 7

#include<fstream>
#include<iostream>
using namespace std;


//helper method from hmwk 4
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


int readRatings(string fileName, string users[], int ratings[100][50],int numUsers, int maxRows, int maxCols){
    ifstream myfile; //create file object
    string line = ""; //create pointer string
    myfile.open(fileName); //open fileName
    
    int ratingIndex = 0; //index of the ratings 2D array
    
    int userCount = numUsers; //intilaize counter as the number of current users

    if(numUsers==maxRows){ //if current users equals the max number of rows, return -2
        return -2;
    }else if(myfile.fail()){ //if file does not exist, return -1
        return -1;
    }else{
        //get each line while the userCount is less than the max number of rows
        while(getline(myfile,line)&&userCount<maxRows){
            if(line !=""){
                string temp[51]; //create a temporary string array that can hold 51 values
                //create a variable that equals the number of split pieces of that line
                int ratingRead = split(line,',',temp, maxCols+1);
                //split the line with the user and his/her ratings
                split(line,',',temp, maxCols);
                //the user is the first index of the temp string array
                users[userCount]=temp[0];
                cout<<users[userCount]<<" ";
                
                //poiner for the rating index
                ratingIndex = 0;
                
                //start for loop at 1 because that is where the ratings start
                for(int i=1; i<ratingRead; i++){
                    //fill the ratings array with the int value of the temp array
                    ratings[userCount][ratingIndex]= stoi(temp[i]);
                    
                    cout<<ratings[userCount][ratingIndex];
                    
                    //increment ratingIndex to keep moving along the line
                    ratingIndex++;
                }
                //increment user count to go to the next line of ratings
                userCount++;
                cout<<endl;
            }
        }
    }
    
    
   myfile.close(); //close file
   return userCount; //return value which represents the number of users/number of lines in the file
    
}

int main(){
    //test 1, expected: 20
    string users[20]={};
    int arr[20][50]={{0}};
    cout<<readRatings("ratings.txt", users, arr, 0, 20,50);
    
    cout<<endl;
    
    //test 2, expected: 2
    string users1[2] = {"ritchie"};
    int ratings[][50] = {{0, 1, 2, 0, 0, 3, 0, 0},
                        {0, 0, 0, 0, 0, 5, 0, 0}};
    int numUsers = 1;
    int maxRows = 2;
    int maxColumns = 50;
    cout<<readRatings("ratings.txt", users1, ratings, numUsers, maxRows, maxColumns);
}