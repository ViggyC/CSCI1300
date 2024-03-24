#ifndef GRID
#define GRID
#include<iostream>
#include "Pokemon.h"
#include "Trainer.h"
#include "PokeCenter.h"


using namespace std;

class Grid{
    
    public:
        Grid();
        //public grid of string characters
        void loadPokemon();
        //2d array of strings
        string grid[27][18]; //map.grid[i][j]=sjfboaebfj
        vector<Trainer> trainers;
        vector<Pokemon> wildPokemons;
        vector<PokeCenter> centers;
        
    
    private:
        const int xSize = 18;
        const int ySize = 27;
        //array for storing grid objects and symbols
        Pokemon array[151];
        
        
        
        
    
};
#endif