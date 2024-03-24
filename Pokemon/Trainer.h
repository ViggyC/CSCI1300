//trainer = gym
#ifndef TRAINER
#define TRAINER
#include<iostream>
#include "Pokemon.h"
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Trainer{
    public:
        
        Trainer(int, int, int, int, int);
        void setLocation(int xCoord, int yCoord);
        int getXpos();
        int getYpos();
        int getNumPokemon();
        int getNumBadges();
        void setActivePokemon(int);
        void setActivePokemon(string);
        void setActivePokemonTrainer(int);
        void getActivePokemonStats();
        int getPokemonIndex();
        void setNumPokeBalls(int);
        int getNumPokeBalls();
        int split(string, char, string arr[], int);
        void loadPokemon();
        
        void addPokemon(int i);
        void addPokemon(Pokemon);
        void addPokemon(string);
        
        int getPokemonVectorSize();
        string getTrainerPokemonName(int);
        void setNumPokemonTrainer(int);
        int getNumPokemonTrainer();
        void changeHP(int num);
        void getAllPokemon();
        
        Pokemon activePokemon;
        
        int getTrainerPoints();
        void setTrainerPoints(int);
        
        void setBadges(int);
        
        void changeActivePokemon(int);
        
    
    private:
        int xPos;
        int yPos;
        int trainerPoints =0; //keep updating
        vector<Pokemon> pokemon; //each trainer has a vector of pokemons
        int pokeballs;
        int numPokemon;
        int numBadges;
        //Pokemon activePokemon;
        Pokemon arr[151];
    
};
#endif