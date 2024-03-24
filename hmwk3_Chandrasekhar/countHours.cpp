// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #5
#include<iostream>
using namespace std; //include standard library

/**
 * This function returns the number 
 * of hours in the desired month
 * using a switch statement.
 * The constant HOURS_IN_DAY
 * is multiplied by the number
 * of days in the selected month
 * */
int countHours(int month){
    int HOURS_IN_DAY = 24;
    switch (month){
        case 1 :
            return 31*HOURS_IN_DAY;
            break;
        case 2 :
            return 28*HOURS_IN_DAY;
            break;
        case 3 :
            return 31*HOURS_IN_DAY;
            break;
        case 4 :
            return 30*HOURS_IN_DAY;
            break;
        case 5 :
            return 31*HOURS_IN_DAY;
            break;
        case 6 :
            return 30*HOURS_IN_DAY;
            break;
        case 7 :
            return 31*HOURS_IN_DAY;
            break;
        case 8 :
            return 31*HOURS_IN_DAY;
            break;
        case 9 :
            return 30*HOURS_IN_DAY;
            break;
        case 10 :
            return 31*HOURS_IN_DAY;
            break;
        case 11 :
            return 30*HOURS_IN_DAY;
            break;
        case 12 :
            return 31*HOURS_IN_DAY;
            break;
    }
}

int main(){
    //test 1, expected: 744
    cout<<countHours(10)<< " hours"<<endl;
    //test 2, expected: 672
    cout<<countHours(2)<<" hours"<<endl;
}