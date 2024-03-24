#ifndef GAME
#define GAME
#include "Pokemon.h"
//#include"Pokemon.cpp"
#include "Trainer.h"
//#include"Trainer.cpp"
#include "PokeCenter.h"
#include "Grid.h"
//#include"Grid.cpp"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<random>
using namespace std;


class Game{
    
    public:
    
        void displayMenu();
        void welcomeScreen();
        
        int split(string, char, string arr[], int);
        
        void displayMap(string);
        
        void loadPokemonArray(string, Pokemon arr[]);
        void printGrid(Grid, Trainer);
        void printVisibility(Grid, Trainer);
        void play(Trainer, Grid);
        void driver();
        void shiftPokemon(Grid);
        void combat(Trainer, Grid); //for wild pokemon
        void trainerEncounter(Trainer, Grid);
        
        private:
            //Grid map; //creating Grid object to construct a grid
            //Trainer you(0,0,0,0,0); //creating Trainer object(main player) 
            bool win;
            int numPoints;
            
        
    
    
};
#endif