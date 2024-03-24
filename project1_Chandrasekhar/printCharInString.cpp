// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Project 1 - Problem # 1
#include<iostream>
#include<string> //including string library
using namespace std;

//method that takes in a string a prints each letter on a new line
void printCharInString(string word){
    //empty string case
    if(word==""){
        cout<<"Given string is empty!";
    }
    //for loop retrieves each index in the string
    for(int i =0; i<word.length();i++){
        cout<<word[i]<<endl; //moving next iteration to next line
    }
}

int main(){
    //test 1
    printCharInString("Computer");
    cout<<endl;
    //test 2
    printCharInString("Vignesh");
}