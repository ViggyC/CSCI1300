// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #6
#include<iostream>
using namespace std; //including standard library

/**
 * This method return true(1)
 * or false(0) if the inputted
 * year is a leapYear.
 * This is done by "checking"
 * if a year meets the condition of a 
 * leap year through boolean expressions.
 * */
bool checkLeapYear(int year){
    bool isLeapYear = false;
    if ( year%400==0 || (year%100!=0 && year%4==0) || (year<=1582 && year%4==0)){
        
        isLeapYear = true;
    }
        
    return isLeapYear;
}

int main(){
    //test 1, expected: 0(true)
    cout<<checkLeapYear(2000)<<endl;
    //test 2, expected: 1(false)
    cout<<checkLeapYear(2011);
}