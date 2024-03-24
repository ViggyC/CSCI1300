// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 - Thanika
// Homework 6 - Problem # 1
#include "Planet.h"
#include "Planet.cpp"
#include <iostream>
using namespace std;


int main(){
    //test cases below 
    //creating multiple objects and calling their member functions
    
    Planet p1; //object p1 via default constructor
    Planet p2("Earth", 1.67676); //object p2 via overloaded constructor
    cout<<p1.getRadius()<<endl; //printing radius of p1, expected: 0
    cout << p2.getName() << endl;  //getting name of p2
    cout<<p2.getVolume()<<endl; //getting volume of p2
    p2.setName("Mars");  //changing name of p2 to Mars
    cout<<p2.getName()<<endl; //printing new name of p2
    
    Planet p3("Jupiter", 567876.9876); //object p3
    cout<<p3.getName()<<endl; //printing name of p3
    
}
