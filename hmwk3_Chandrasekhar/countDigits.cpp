// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #4
#include<iostream>
using namespace std; //including standard library


//function that returns the number of digits in a given number
int countDigits(int number){
    //intitializing digit counter to be 0
    int digitCounter = 0;
    //if the inputted number is 0, return 1
    if(number == 0){
        return 1;
    }
    //if inputted number is less negative, multiply by -1 to make it positive
    if(number<0){
        number *=-1;
    }
    /**
     * This loop continously divides
     * the inputted number by 10
     * until it equals 0.
     * Each time it is divided by 10
     * the digitCounter increments
     * by 1
     * */
    while(number!=0){
        number/=10;
        digitCounter++;
    
    }
   
    //returns digit coutner
    return digitCounter;
}

int main(){
    //test 1, expected: 5
   cout<< countDigits(13456)<<endl;
   //test 2, expected: 3
   cout<< countDigits(-999);
}