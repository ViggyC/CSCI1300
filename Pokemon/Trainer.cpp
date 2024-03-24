#include "Pokemon.h"
#include "Trainer.h"
#include<fstream>
#include<vector>
#include<string>

int Trainer::split(string split, char delimeter, string arr[], int length){
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

void Trainer:: loadPokemon(){
    ifstream myfile;
    myfile.open("pokemon.txt");
    string line;
    int pokemonArrayIndex = 0;
    //Pokemon pokemonArray[151]; 
    if(myfile.is_open()){
        while(getline(myfile,line)){
            if(line!=""){
                string temp[9];
                split(line, ',', temp, 9);
                int pokeHP = stoi(temp[2]);
                int pokeAttack = stoi(temp[3]);
                int pokeDefense = stoi(temp[4]);
                int pokeSpeed = stoi(temp[5]);
                int pokeMax = stoi(temp[6]);
                //filling pokemon array with pokemon objects
                arr[pokemonArrayIndex] = Pokemon(temp[1],pokeHP,pokeAttack, pokeDefense ,pokeSpeed, pokeMax, temp[7], temp[8]);
                pokemonArrayIndex++;
            }
        }
        myfile.close();
    }
}


//Trianer constructor
Trainer::Trainer(int x, int y, int points, int numPoke, int badges){
    loadPokemon();
    xPos = x;
    yPos = y;
    trainerPoints = 0;
    pokeballs = 10;
    numBadges=0;
    numPokemon = numPoke;
}

//sets active pokemon for you
void Trainer :: setActivePokemon(int index){
    activePokemon = arr[index];
}

void Trainer:: setActivePokemon(string name){
    for(int i=0; i<151;i++){
        if(arr[i].getPokemonName()==name){
            activePokemon=arr[i];
        }
    }
}

void Trainer:: setActivePokemonTrainer(int index){
    activePokemon = pokemon[0];
}

//prints your active pokemon stats
void Trainer::getActivePokemonStats(){
    cout<<"Name: "<<activePokemon.getPokemonName()<<" (ACTIVE), "<<"HP: "<<activePokemon.getHP()<<", A: "<<activePokemon.getAttack()<<", D: "<<activePokemon.getDefense()<<", S: "<<activePokemon.getSpeed()<<", M: "<<activePokemon.getMax()<<endl;
}

//sets location of trainer
void Trainer :: setLocation(int x, int y){
    xPos = x;
    yPos = y;
}


//adds pokemon to trainers vector of pokemon
void Trainer:: addPokemon(int i){
    pokemon.push_back(arr[i]);
    numPokemon++;
}

void Trainer:: addPokemon(Pokemon add){
    pokemon.push_back(add);
    numPokemon++;
}

void Trainer:: addPokemon(string name){
    for(int i=0;i<151;i++){
        if(arr[i].getPokemonName()==name){
            activePokemon=arr[i];
        }
        
    }
        
}

string Trainer::getTrainerPokemonName(int i){
    return pokemon[i].getPokemonName();
}


int Trainer ::getXpos(){
    return xPos;
}

int Trainer:: getYpos(){
    return yPos;
}

int Trainer::getNumPokeBalls(){
    return pokeballs;
}

void Trainer::setNumPokeBalls(int num){
    pokeballs+=num;
}



int Trainer:: getPokemonVectorSize(){
    return pokemon.size();
}

void Trainer:: setNumPokemonTrainer(int num){
    numPokemon=num;
}
    
int Trainer:: getNumPokemonTrainer(){
    return numPokemon;
}

void Trainer:: changeHP(int num){
    activePokemon.setHP(num);
    for(int i=0; i<numPokemon;i++){
        pokemon[i].setHP(num);
       // cout<<"HP: "<<pokemon[i].getHP()<<endl; //this works
    }
}

void Trainer:: getAllPokemon(){
     cout<<"Here is a list of all your pokemon: "<<endl; 
    for(int i=0; i<numPokemon;i++){
        cout<<i+1<< ". "<<pokemon[i].getPokemonName()<<endl;
    }
}


void Trainer::setTrainerPoints(int num){
    trainerPoints+=num;
}

int Trainer:: getTrainerPoints(){
    return trainerPoints;
}


void Trainer::setBadges(int n){
    numBadges+=n;
}

int Trainer::getNumBadges(){
    return numBadges;
}


void Trainer::changeActivePokemon(int i){
    activePokemon=pokemon[i];
}