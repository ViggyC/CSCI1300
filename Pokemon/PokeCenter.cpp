#include "PokeCenter.h"
//#include"Pokemon.h"
//#include"Trainer.h"
#include<iostream>
using namespace std;


PokeCenter::PokeCenter(int x, int y){
    pcX=x;
    pcY=y;
}


int PokeCenter::getpcX(){
    return pcX;
}

int PokeCenter::getpcY(){
    return pcY;
}