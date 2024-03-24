#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<random>
using namespace std;
#include"Game.h"
#include"Pokemon.cpp"
#include"Trainer.cpp"
#include"PokeCenter.cpp"
#include"Grid.cpp"
#include"Game.cpp"

//compile all cpps in bash


int main(){
    srand(time(NULL));
    
    Game game;
    game.driver();
}

/**
Finish Trainer encounters
Write to text file
Done

*/