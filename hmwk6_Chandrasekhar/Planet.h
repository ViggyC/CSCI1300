//header file
#ifndef PLANET //defining Class
#define PLANET

#include <iostream>
#include <string>
using namespace std;

class Planet{
    
     //public member functions
    public:
        Planet();
        Planet(string name, double radius);
        string getName();
        void setName(string name);
        double getRadius();
        void setRadius(double radius);
        double getVolume();
        
        //private data variables
    private:
        string planetName;
        double planetRadius;
    
};

#endif