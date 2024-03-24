// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #1
#include<iostream>
using namespace std; //including standard library


/*function which takes in an int and returns 
a value based on whether the number is even or odd*/
int collatzStep(int number){
    if(number<0){
        return 0;
        //if even, return the number divided by two
    }else if(number%2==0){
        return number/2;
    }else{
        //if odd, return 3 times the number plus one
        return 3*number+1;
    }
}

int main(){
    //test 1
    cout<< collatzStep(33) << endl;
    cout<<"expected: 100"<<endl;
    //test 2
    cout<< collatzStep(14)<<endl;
    cout<<"expected: 7";
}