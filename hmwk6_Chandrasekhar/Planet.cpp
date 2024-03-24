//implementation file
#include "Planet.h" //include header file
#include<iostream>
#include <string>
#include <math.h>
using namespace std;

//default constructor
Planet::Planet(){
    planetName = "";
    planetRadius = 0.0;
}

//overloaded constructor
Planet::Planet(string name, double radius){
    planetName = name;
    planetRadius = radius;
}

//getter method for planetName
string Planet::getName(){
    return planetName;
}

//setter method for planetName
void Planet::setName(string name){
    planetName = name;
}

//getter method for planetRadius
double Planet::getRadius(){
    return planetRadius;
}

//setter method for planetRadius
void Planet::setRadius(double radius){
    planetRadius = radius;
}

//getter method for planetVolume
double Planet:: getVolume(){
    return ((4.0/3.0)*M_PI*pow(planetRadius,3));
}





