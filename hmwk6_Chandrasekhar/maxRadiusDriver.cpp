// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 - Thanika
// Homework 6 - Problem # 2

#include<iostream>
#include "Planet.h"
#include "Planet.cpp"
using namespace std;

int maxRadius(Planet array[], int size){
    int count  = size; //counter variable, set to size
    double maxRad = 0; //current maxRad
    int index = 0; //index that will be returned
    //edge case
    if(size==0){
        return -1;
    }
    //for loop finds the maxRad and sets index = i;
    for(int i = 0; i<size; i++){
        if(array[i].getRadius()>maxRad){
            maxRad = array[i].getRadius();
            index = i;
        }
        
    }
    //checking if multiple elements have the maxRad
    for(int i = 0; i < size; i++){ 
        for(int j = i + 1; j < size; j++) {
            if(array[i].getRadius()==maxRad&& maxRad== array[j].getRadius() &&array[i].getRadius()==array[j].getRadius()){
                return i; //if multiple elements have same maxRad, return index of first occurrence 
            }
        }
    }
    
    //return index
    return index;
    
}




int main(){
    //test 1
    Planet planets[3];
    planets[0] = Planet("Nebraska",13.3);
    planets[1] = Planet("Flarbellon-7",8.6);
    planets[2] = Planet("Parblesnops",6.8);
    int idx = maxRadius(planets, 3);
    cout << planets[idx].getName() << endl; //expected: Nebraska
    cout << planets[idx].getRadius() << endl; //expected: 13.3
    cout << planets[idx].getVolume() << endl<<endl; //expected: 9854.7
    
    //test 2
    Planet newPlanets[3];
    int index = maxRadius(newPlanets, 0);
    cout << index << endl;
}