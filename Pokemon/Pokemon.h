#ifndef POKEMON
#define POKEMON
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Pokemon{
    public:
        Pokemon();
        Pokemon(string, int, int, int, int, int, string, string);
        string getPokemonName();
        int getHP();
        int getDefense();
        int getSpeed();
        int getMax();
        int getAttack();
        string getType1();
        string getType2();
        void setPokemonName(string name);
        void setHP(int num);
        void setDefense(int num);
        void setSpeed(int num);
        void setMax(int num);
        void setXCoord(int);
        void setYCoord(int);
        int getXCoord();
        int getYCoord();
        void getStats(string);
        
        void resetHP(int);
        
        
       
        
        
        
    
    private:
        string pokemonName;
        int hp;
        int attack;
        int defense;
        int speed;
        int max;
        string type1;
        string type2;
        //pokemon location
        int xCoord;
        int yCoord;
        bool isAlive;
        
        int arr[151];
    
    
};
#endif