#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<random>
using namespace std;
#include"Game.h"

//compile all cpps in bash


int main(){
    srand(time(NULL));
    
    Game game;
    game.driver();

    return 0;
}

