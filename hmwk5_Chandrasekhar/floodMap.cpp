// CS1300 Fall 2019
// Author: my name
// Recitation: 304 - Thanika
// Homework 5 - Problem # 5

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void floodMap(double arr[][4], int rows, double level){
    //create nested for loop that will print a chart
    for(int i =0;i<rows; i++){ //outer loop goes thru the number of rows
        for(int j=0; j<4; j++){ //inner loop goes through columns which is always 4
            //if the value in the 2D array is less than the level
            //print a *
            if(arr[i][j]<=level){ 
                cout<<"*";
            }else{
                cout<<"_"; //otherwise print a _
            }
        }
        //go to next line after we print each row
        cout<<endl;
    }
}

int main(){
    //test 1
    cout<<"test 1: "<<endl;
    double map[4][4] = {{1.0, 5.0, 1.0, 1.0},
                        {1.0, 5.0, 5.0, 1.0},
                        {5.0, 1.0, 5.0, 5.0},
                        {1.0, 1.0, 1.0, 1.0}};
    floodMap(map, 4, 3.14);
    
    cout<<endl;
    
    //test 2
    cout<<"test 2: "<<endl;
    double map1[2][4] = {{0.2, 0.8, 0.8, 0.2},
                        {0.2, 0.2, 0.8, 0.5}};
    floodMap(map1, 2, 0.5);
    
    cout<<endl;
    
    //test 3
    cout<<"test 3: "<<endl;
    double map2[2][4] = {{0.2, 0.8, 0.8, 0.2},
                        {0.2, 0.2, 0.8, 0.5}};
    floodMap(map2, 2, 0.0);
}