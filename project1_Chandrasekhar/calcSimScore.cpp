// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Project 1 - Problem # 4
#include<iostream>
#include<string> //including string library
using namespace std;

/**
 * this method returns the double value
 * of the similarity score between two strings.
 * More explanations within the method
 * */
double calcSimScore(string firstSeq, string secondSeq){
    //length of string made to be adouble
    double length = firstSeq.length()+0.0;
    //initialize hamming_distance as 0.0
    double hamming_distance=0.0;
    //empty string, return 0
    if(firstSeq=="" || secondSeq==""){
        return 0;
    }
    //different lengths, return 0
    if(firstSeq.length()>secondSeq.length()||firstSeq.length()<secondSeq.length()){
        return 0;
    }
    //if indexes at i dont match, increment hamming_distance
    for(int i=0; i<firstSeq.length();i++){
        if(firstSeq[i]!=secondSeq[i]){
            hamming_distance+=1.0;
        }
    }
    //return similarity
    return ((length-hamming_distance)/length);
}

int main(){
    //test 1, expected: 0.5
    cout<<calcSimScore("ATGC","GTGA")<<endl;
    //test 2, expected: 1
    cout<<calcSimScore("GTTA", "GTTA");
}