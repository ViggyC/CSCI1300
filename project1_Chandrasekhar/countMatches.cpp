// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Project 1 - Problem # 2
#include<iostream>
#include<string>
using namespace std;


/**
 * This method returns the integer value
 * of the number of matches of a substring in 
 * a given string
 * */
int countMatches(string word, string sub){
    int matchCount=0;
    //empty strings or substrings return -1
    if(word==""||sub==""){
        return -1;
    }
    //for loop checks the indexes
    //where the substring matches the string
    //in that index
    for(int i=0; i<word.length(); i++){
        if(word.substr(i,(sub.length()))==sub){
            //if there is a match, increment matchCount
            matchCount++;
        }
    }
    
    //return value
    return matchCount;
}

int main(){
    //test 1, expected: 3
    cout<<countMatches("Chandrasekhar","a")<<endl;
    //test 2, expected: 1
    cout<<countMatches("Computer science", "er");
}