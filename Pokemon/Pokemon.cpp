#include<iostream>
#include "Pokemon.h"
#include<fstream>
#include<vector>
#include<iostream>
#include<string>
using namespace std;


Pokemon::Pokemon(){
    //loadPokemon();
    pokemonName="";
    hp = 0;
    defense=0;
    max = 0;
    speed =0;
    attack = 0;
    type1 = "";
    type2 = "";
}

Pokemon::Pokemon(string name, int hp_, int attack_, int defense_, int speed_, int max_, string type1_, string type2_){
    pokemonName=name;
    hp = hp_;
    defense=defense_;
    max = max_;
    attack = attack_;
    speed = speed_;
    type1 = type1_;
    type2 = type2_;
    isAlive=true;
}

string Pokemon:: getPokemonName(){
    return pokemonName;
}

int Pokemon :: getHP(){
    return hp;
}


int Pokemon:: getDefense(){
    return defense;
}


int Pokemon :: getMax(){
    return max;
}

int Pokemon:: getAttack(){
    return attack;
}

int Pokemon:: getSpeed(){
    return speed;
}

string Pokemon::getType1(){
    return type1;
}

string Pokemon::getType2(){
    return type2;
}

void Pokemon :: setPokemonName(string name){
    pokemonName=name;
}


void Pokemon :: setMax(int num){
    max = num;
}


void Pokemon :: setHP(int num){
    hp += num;
    //cout<<"HP: "<<hp<<endl;
}


void  Pokemon ::setDefense(int num){
    defense = num;
}


void Pokemon:: setSpeed(int num){
    speed = num;
}

void Pokemon:: setXCoord(int x){
    xCoord=x;
}

int Pokemon::getXCoord(){
    return xCoord;
}

void Pokemon:: setYCoord(int y){
    yCoord=y;
}

int Pokemon::getYCoord(){
    return yCoord;
}

void Pokemon:: resetHP(int n){
    hp=n;
}


