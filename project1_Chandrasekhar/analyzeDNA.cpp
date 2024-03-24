// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Project 1 - Problem # 7

#include<iostream>
#include<string>
using namespace std; 


// Show menu function
void showMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl;
    cout << "2. Find the best similarity score" << endl;
    cout << "3. Analyze the genome sequences" << endl;
    cout << "4. Quit" << endl;
}

//problem 4 helper method
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

//problem 5 helper method
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

//problem 6 helper method
void findMatchedGenome(string firstGenome, string secondGenome, string thirdGenome, string sequence){
    if(firstGenome==""||secondGenome==""||thirdGenome==""||sequence==""){
        cout<<"Genomes or sequence is empty."<<endl;
        return;
    }
    if(firstGenome.length()>secondGenome.length()||firstGenome.length()<secondGenome.length()||firstGenome.length()>thirdGenome.length()
    ||firstGenome.length()<thirdGenome.length()||secondGenome.length()>thirdGenome.length()
    ||secondGenome.length()<thirdGenome.length()){
        cout<<"Lengths of genomes are different."<<endl;
        return;
    }
    if(findBestSimScore(firstGenome,sequence)>findBestSimScore(secondGenome,sequence)
    &&findBestSimScore(firstGenome,sequence)>findBestSimScore(thirdGenome,sequence)){
        cout<<"Genome 1 is the best match."<<endl;
    }else if(findBestSimScore(secondGenome,sequence)>findBestSimScore(firstGenome,sequence)
    &&findBestSimScore(secondGenome,sequence)>findBestSimScore(thirdGenome,sequence)){
        cout<<"Genome 2 is the best match."<<endl;
    }else if(findBestSimScore(thirdGenome,sequence)>findBestSimScore(secondGenome,sequence)
    &&findBestSimScore(thirdGenome,sequence)>findBestSimScore(firstGenome,sequence)){
        cout<<"Genome 3 is the best match."<<endl;
        
    }else if(findBestSimScore(firstGenome,sequence)==findBestSimScore(secondGenome,sequence)
    &&findBestSimScore(firstGenome,sequence)==findBestSimScore(thirdGenome,sequence)){
        cout<<"Genome 1 is the best match."<<endl;
        cout<<"Genome 2 is the best match."<<endl;
        cout<<"Genome 3 is the best match."<<endl;
    }else if(findBestSimScore(secondGenome,sequence)==findBestSimScore(firstGenome,sequence)){
        cout<<"Genome 1 is the best match."<<endl;
        cout<<"Genome 2 is the best match."<<endl;
    }else if(findBestSimScore(thirdGenome,sequence)==findBestSimScore(secondGenome,sequence)){
        cout<<"Genome 2 is the best match."<<endl;
        cout<<"Genome 3 is the best match."<<endl;
    }else if(findBestSimScore(thirdGenome,sequence)==findBestSimScore(firstGenome,sequence)){
        cout<<"Genome 1 is the best match."<<endl;
        cout<<"Genome 3 is the best match."<<endl;
    }else{
        return;
    }
}

//putting all helper methods together in one for user
void analyzeDNA(){
    int choice;
    while(choice != 4){
        showMenu();
        cin>>choice;
        //edge case, only numbers 1-4 are allowed
        if(choice !=1 && choice!=2 && choice!=3 && choice!=4){
            cout<<"Invalid option."<<endl;
        //choice 2 calls helper method 1
        }else if(choice==1){
            string firstSequence;
            string secondSequence;
            cout<<"Enter sequence 1: "<<endl;
            cin>>firstSequence;
            cout<<"Enter sequence 2: "<<endl;
            cin>>secondSequence;
            cout<<"Similarity score: "<<calcSimScore(firstSequence, secondSequence)<<endl;
        //choice 2 calls helper method 2
        }else if(choice==2){
            string genome;
            string sequence;
            cout<<"Enter genome: "<<endl;
            cin>>genome;
            cout<<"Enter sequence: "<<endl;
            cin>>sequence;
            cout<<"Best similarity score: "<<findBestSimScore(genome, sequence)<<endl;
        //choice 3 calls helper method 3
        }else if(choice==3){
            string g1;
            string g2;
            string g3;
            string seq;
            cout<<"Enter genome 1: "<<endl;
            cin>>g1;
            cout<<"Enter genome 2: "<<endl;
            cin>>g2;
            cout<<"Enter genome 3: "<<endl;
            cin>>g3;
            cout<<"Enter sequence: "<<endl;
            cin>>seq;
            findMatchedGenome(g1,g2,g3,seq);
        }else{
            //choice == 4
            cout<<"Good bye!"<<endl;
            return;
        }
    }
    
}

int main(){
    //main method should be simple; calling mega methods
    analyzeDNA();
}