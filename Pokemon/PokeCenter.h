#ifndef POKECENTER
#define POKECENTER
#include"Pokemon.h"
#include"Trainer.h"
#include<iostream>
using namespace std;

class PokeCenter{
    
    public:
        PokeCenter(int, int);
        void printPCMenu();
        int getpcX();
        int getpcY();
    
    
    
    private:
        int pcX;
        int pcY;
    
    
    
    
    
    
    
};
#endif