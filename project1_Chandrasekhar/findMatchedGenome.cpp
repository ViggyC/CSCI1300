// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Project 1 - Problem # 6

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

//method from problem 5
double findBestSimScore(string genome, string sequence){
    double bestSimScore=0.0;
    for(int i=0; i<genome.length();i++){
        //genome=genome.substr(i,sequence.length());
        if(calcSimScore(genome.substr(i,sequence.length()),sequence) > bestSimScore){
            // bestSimScore=calcSimScore(genome, sequence);
            bestSimScore = calcSimScore(genome.substr(i,sequence.length()),sequence); 
        }
    }
    return bestSimScore;
}

//new method that takes in 3 genomes and one sequence and returns the best match
void findMatchedGenome(string firstGenome, string secondGenome, string thirdGenome, string sequence){
    //empty string case
    if(firstGenome==""||secondGenome==""||thirdGenome==""||sequence==""){
        cout<<"Genomes or sequence is empty."<<endl;
        return;
    }
    //different lengths case
    if(firstGenome.length()>secondGenome.length()||firstGenome.length()<secondGenome.length()||firstGenome.length()>thirdGenome.length()
    ||firstGenome.length()<thirdGenome.length()||secondGenome.length()>thirdGenome.length()
    ||secondGenome.length()<thirdGenome.length()){
        cout<<"Lengths of genomes are different."<<endl;
        return;
    }
    //calling method from problem 5 to check if genome 1 is the best match
    if(findBestSimScore(firstGenome,sequence)>findBestSimScore(secondGenome,sequence)
    &&findBestSimScore(firstGenome,sequence)>findBestSimScore(thirdGenome,sequence)){
        cout<<"Genome 1 is the best match.";
    //calling method from problem 5 to check if genome 2 is the best match
    }else if(findBestSimScore(secondGenome,sequence)>findBestSimScore(firstGenome,sequence)
    &&findBestSimScore(secondGenome,sequence)>findBestSimScore(thirdGenome,sequence)){
        cout<<"Genome 2 is the best match.";
    //calling method from problem 5 to check if genome 3 is the best match
    }else if(findBestSimScore(thirdGenome,sequence)>findBestSimScore(secondGenome,sequence)
    &&findBestSimScore(thirdGenome,sequence)>findBestSimScore(firstGenome,sequence)){
        cout<<"Genome 3 is the best match.";
    
    //if the best sim score is equal for all 3 genomes, out put all 3 genomes
    }else if(findBestSimScore(firstGenome,sequence)==findBestSimScore(secondGenome,sequence)
    &&findBestSimScore(firstGenome,sequence)==findBestSimScore(thirdGenome,sequence)){
        cout<<"Genome 1 is the best match."<<endl;
        cout<<"Genome 2 is the best match."<<endl;
        cout<<"Genome 3 is the best match."<<endl;
    //if the best sim score is equal for 2 genomes, out put the 2 genomes
    }else if(findBestSimScore(secondGenome,sequence)==findBestSimScore(firstGenome,sequence)){
        cout<<"Genome 1 is the best match."<<endl;
        cout<<"Genome 2 is the best match."<<endl;
    //if the best sim score is equal for the other 2 genomes, out put the 2 genomes
    }else if(findBestSimScore(thirdGenome,sequence)==findBestSimScore(secondGenome,sequence)){
        cout<<"Genome 2 is the best match."<<endl;
        cout<<"Genome 3 is the best match."<<endl;
    //if the best sim score is equal 2 genomes, out put the 2 genomes
    }else if(findBestSimScore(thirdGenome,sequence)==findBestSimScore(firstGenome,sequence)){
        cout<<"Genome 1 is the best match."<<endl;
        cout<<"Genome 3 is the best match."<<endl;
    }else{
        return;
    }
    
}

int main(){
    //test 1
    string g1 = "TAAGGCA";
    string g2 = "TACCTAC";
    string g3 = "AGCCAGA";
    string seq = "TCT";
    findMatchedGenome(g1,g2,g3,seq);
    cout<<endl;
    cout<<endl;
    //test 2
    findMatchedGenome("AC","AC","AC","AC");
    
}