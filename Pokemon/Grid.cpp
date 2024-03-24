#include"Grid.h"
#include"PokeCenter.h"
#include "Pokemon.h"
#include"Trainer.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<string>
#include<random>
using namespace std;


//split function
int split1(string split, char delimeter, string arr[], int length){
    int count=0; //split counter which will be returned at the end
    int currentIndex=0; //pointer of the array
    int indexInArray=0; //index that will store the split pieces
    //empty strings return 0
    if(split==""){
        return 0;
    }
    
    //add a delimeter to the end of the string if there already isn't one there
    if(split[split.length()-1]!=delimeter){
        split+=delimeter;
    }
    //remove delimeter from beginning of the string
    if(split[0]==delimeter){
        split=split.substr(split.find(delimeter)+1);
    }
    
    //temportary string variable to be manipulated
    string temp = split; 
    
    //run through the split string
    for(int i=0; i<split.length();i++){
        
        //if the i equals the delimeter: do everything in the if statement
        if(split[i]==delimeter){

            currentIndex = temp.find(delimeter); //set the currentIndex at the location of the delimeter
            arr[indexInArray]=temp.substr(0, currentIndex); //fill the array with the substring starting at 0 to the currentIndex
            indexInArray++; //increment indexInArrat so that next index can be filled
            count++; //increment count because we have made a split
            temp = temp.substr(currentIndex+1); //change the temp string so that it now starts at the index after the index of the found delimeter
                
            
        }
        //check if the first index of the temp string is the delimeter
        if(temp[0]==delimeter){
            //if it is then remove the delimeter by shifting the entire string one index
            temp=temp.substr(temp.find(delimeter)+1);
            //subtract the count var because we did not split anything
            count--;
        }
        
    }
    //edge case: if count>length then return -1
    if(count>length){
        return -1;
    }
    //return the final count var
    return count;
}

//another function for loading pokemon 
void Grid:: loadPokemon(){
    ifstream myfile;
    myfile.open("pokemon.txt");
    string line;
    int pokemonArrayIndex = 0;
    //Pokemon pokemonArray[151]; 
    if(myfile.is_open()){
        while(getline(myfile,line)){
            if(line!=""){
                string temp[9];
                split1(line, ',', temp, 9);
                int pokeHP = stoi(temp[2]);
                int pokeAttack = stoi(temp[3]);
                int pokeDefense = stoi(temp[4]);
                int pokeSpeed = stoi(temp[5]);
                int pokeMax = stoi(temp[6]);
                //filling pokemon array with pokemon objects
                array[pokemonArrayIndex] = Pokemon(temp[1],pokeHP,pokeAttack, pokeDefense ,pokeSpeed, pokeMax, temp[7], temp[8]);
                pokemonArrayIndex++;
            }
        }
        myfile.close();
    }
}


//construct a grid using the file and change character to cooresponding symbols, objects
//load vectors with respective objects
Grid::Grid(){
    loadPokemon(); 
    ifstream myFile;
    myFile.open("mapPoke.txt");
    string line;
    
    int gridIndex=0;
    if(myFile.is_open()){
        while(getline(myFile,line)&&gridIndex<27){
            int count = 0;
            string temp[18];
            split1(line, ',', temp, 18);
            //here maybe check if the char represents and object and push back vector with location
            for(int i=0; i<18;i++){
                if(temp[i]=="w"){
                   temp[i]="~";
                }
                if(temp[i]=="p"){
                    temp[i]="*";
                }
                if(temp[i]=="C"){
                    centers.push_back(PokeCenter(i,gridIndex));
                    //cout<<"PokeCenter: "<<gridIndex<<" "<<i<<endl;
                }
                if(temp[i]=="G"){ //Gyms are trainers
                    
                    //fill the trainers vector with Trainer objects
                    trainers.push_back(Trainer(i, gridIndex,0,10,0));
                    //setting location of trainers
                    trainers[count].setLocation(i,gridIndex);
                    count++;
                    //set the active pokemon for each Trainer
                    
                   
                }
               
                //load grid
                grid[gridIndex][i] = temp[i];
                
            }
            
            //increment gridIndex for grid row index
            gridIndex++;
        
        }
    }
    myFile.close();
    
    //adding pokemon to all trainers pokemon vectors
    //give each trainer 1-6 random pokemon
    for(int i=0; i<trainers.size();i++){
        //cout << "trainer pokemons" << endl; //should print 15 times
        int numPokemon = rand()%6+1;
        trainers[i].setNumPokemonTrainer(numPokemon);
        for(int j=0; j<numPokemon; j++){
            int randIndex = rand()%152;
            trainers[i].addPokemon(randIndex);
            //cout<<array[randIndex].getPokemonName()<<endl; //this is not working!!
        }
    }
    
    //set active pokemon for all other trainers
    //as the first pokemon in each trainers pokedex
    for(int i=0; i<trainers.size();i++){
        //cout<<trainers[i].getPokemonVectorSize()<<endl;
        trainers[i].setActivePokemonTrainer(0);
        //trainers[i].getActivePokemonStats();
        //cout<<endl;
        
    }
    
    //disperse 20 random wild pokemons here**** //figure this out and then we can play the game
    int count = 0;
    while(count<20){
        int randX = rand()%18;
        //cout<<"randX: "<<randX<<endl;
       
        int randY = rand()%27;
        //cout<<"randY: "<<randY<<endl;
        
        int randPoke = rand()%152;
     
        if(grid[randY][randX]=="*"){
            grid[randY][randX]="x"; //for testing
            wildPokemons.push_back(array[randPoke]);
            wildPokemons[count].setXCoord(randX);
            wildPokemons[count].setYCoord(randY);
            
            count++;
        }
    }
    
    
    //testing wildPokemon vector
    // for(int i=0; i<wildPokemons.size();i++){
    //     cout<<wildPokemons[i].getPokemonName()<<" x: "<<wildPokemons[i].getXCoord()<<", y: "<<wildPokemons[i].getYCoord()<<endl;
    // }
    
    //testing
    // for(int i=0;i<trainers.size();i++){
    //     cout<<"Trainer x: "<<trainers[i].getXpos()<<" y: "<<trainers[i].getYpos()<<endl; 
    // }
    
}//end of constructor










