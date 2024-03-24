// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #7
#include<iostream>
using namespace std; //including standard library

/**
 * This method prints each digit
 * in the collatz sequence
 * based on the starting number.
 * The starting number is inputted
 * by the user
 * */
void printCollatz(int start){
    //no negative numbers allowed
    if(start<=0){
        cout<<"invalid number"<<endl;
    }
    
    /**while the starting number is not 1
     * and greater than 1, compute each
     * term in the sequence based on whether
     * start is currently odd or even
     * */
    while(start != 1 && start>1 ){
         cout<<start << " ";
         if(start%2==1){
             start = 3*start +1;
         }else{
             start /=2;
         }
    }
    
    //if start = 1, just print 1
    if(start==1){
        cout<<start;
    }
}

int main(){
    //test 1, expected: 6 3 10 5 16 8 4 2 1 
    printCollatz(6);
    cout<<endl;
    //test 2, expected: 10 5 16 8 4 2 1
    printCollatz(10);
}