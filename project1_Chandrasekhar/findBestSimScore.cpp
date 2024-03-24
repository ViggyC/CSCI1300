// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Project 1 - Problem # 5
#include<iostream>
#include<string>
using namespace std;

//method from problem 4
double calcSimScore(string firstSeq, string secondSeq){
    double length = firstSeq.length()+0.0;
    double hamming_distance=0.0;
    if(firstSeq=="" || secondSeq==""){
        return 0;
    }
    if(firstSeq.length()>secondSeq.length()||firstSeq.length()<secondSeq.length()){
        return 0;
    }
    for(int i=0; i<firstSeq.length();i++){
        if(firstSeq[i]!=secondSeq[i]){
            hamming_distance+=1.0;
        }
    }
    return ((length-hamming_distance)/length);
}

//new method that returns the best sim score in a given genome with a desired sequence
double findBestSimScore(string genome, string sequence){
    double bestSimScore=0.0;
    for(int i=0; i<genome.length();i++){
        //if statement retrieves max sim score my making comparisons within the genome
        if(calcSimScore(genome.substr(i,sequence.length()),sequence) > bestSimScore){
            // bestSimScore=calcSimScore(genome, sequence);
            bestSimScore = calcSimScore(genome.substr(i,sequence.length()),sequence); 
        }
    }
    return bestSimScore;
}

int main(){
    //test 1, expected: 0.8
    cout<< findBestSimScore("ATACCAGACCTTAGGAGCG","AGATC")<<endl;
    //test 2, expected: 0.5
    cout<< findBestSimScore("AG","CG")<<endl;
    //test 3, expected: 0
    cout<< findBestSimScore("ABCD", "ABCDE");
}