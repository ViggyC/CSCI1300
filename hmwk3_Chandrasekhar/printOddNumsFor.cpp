// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #9
#include<iostream>
using namespace std; //including standard library

/**
 * This method prints all the odd numbers
 * leading up to the max number(includes max)
 * using a for loop
 * */
void printOddNumsFor(int max){
    //add 2 to i to keep it odd
    for(int i = 1; i<=max; i+=2){
        cout<<i<<endl;
    }
}

int main(){
    //test 1, expected: 1 3 5 7 9 11 13
    printOddNumsFor(13);
    cout<<endl;
    //test 2, expected: 1 3 5 7 9 11 13 15 17 19
    printOddNumsFor(20);
}