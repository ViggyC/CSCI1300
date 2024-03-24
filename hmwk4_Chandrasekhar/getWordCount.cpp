// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika!!
// Homework 4 - Problem # 5

#include<iostream>
#include<string>
using namespace std;

int getWordCount(string sentence){
    int count=1; //initialize count as 1 if string is not empty
    
    if(sentence==""){//if string is empty, return 0
        return 0;
    }
    //iterate through the string
    for(int i=0; i<sentence.length(); i++){
        //if you find a space, then increment count because that separates the words
        if(sentence[i] == ' '){
            count++;
        }
        
    }
    //return value
    return count;
}

int main(){
    //test 1, expected: 5
    cout<<getWordCount("Hello my name is Vignesh")<<endl;
    //test 2, expected: 0
    cout<<getWordCount("");
}