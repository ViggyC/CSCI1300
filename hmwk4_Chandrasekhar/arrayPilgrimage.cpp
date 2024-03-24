// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika!!
// Homework 4 - Problem # 1

#include <iostream>
#include<string>
using namespace std;

int main(){
    //first array
    double temps[10]; //declaring an array of type double with 10 elements
    for(int i =0; i<10; i++){ //for loop fills each index with -459.67
        temps[i]=-459.67;
        cout<<temps[i]<<endl;
    }
    cout<<endl;
    
    //second array
    string colors[5]={"Red","Blue","Green","Cyan", "Magenta"}; //initializing an array of strings with 5 colors
    for(int i=0; i<5;i++){ //for loop prints each index from the array
        cout<<colors[i]<<endl;
    }
    cout<<endl;
    
    //third array
    int sequence[100]; //declaring an array of type int with 100 elements
    for(int i=0;i<100;i++){ //for loop fills the array with the value of i
        sequence[i]=i+1;
        cout<<sequence[i]<<endl; //printing values in array
    }
    cout<<endl;
    
    //fourth array
    char letters[26]; //declaring an array of type char with 26 elements 
    for(int i=0;i<26;i++){ //for loop fills each index with the corresponding ascii value
        letters[i]=char(i+65); //add 65 to i to get lower case letter from ascii
        cout<<letters[i]<<" "<<char(i+97)<<endl; //also print capital letters by adding 97 to i
    }
    
}