// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #2
#include<iostream>
using namespace std; //including standard library


/**function that takes in 3 integer values and compares them.
  If all numbers are the same, print "All same". 
  If all numbers are different, print "All different".
  Otherwise, print "neither"*/

void checkEqual(int first, int second, int third){
    //if else statements determine the output
    if(first==second&&first==third&&second==third){
        cout<< "All same";
    }else if(first!=second&&first!=third&&second!=third){
        cout<< "All different";
    }else{
        cout<<"Neither";
    }
}

int main(){
    //test 1, expected: "All different"
    checkEqual(1,4,5);
    cout<<endl;
    //test 2, expected: "All same"
    checkEqual(2,2,2);
     cout<<endl;
    //test 3, expected: "Neither"
    checkEqual(3,3,7);
}