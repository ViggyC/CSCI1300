// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #10
#include<iostream>
using namespace std; //including standard library


/**
 * This method prints a grid containing
 * +, -, and |.
 * The number of boxes 
 * in the grid is the 
 * size squared
 * */
void printGrid(int size){
    //size must be positive
    if(size<=0){
        cout<<"The grid can only have a positive number of rows and columns.";
    }else{
        //outerloop prints columns
        for(int i=1 ;i<=size*2+1; i++){
            //inner loop prints rows
           for(int j=1;j<=size; j++){
               //if i is odd, print +--
                if(i%2==1){
                    cout<< "+--";
                }else{
                    //if i is even, print | with 2 spaces
                    cout<<"|  ";
                }
                
            }
            //complete right edge of grid
            if(i%2==1){
               cout<<"+";
            }else{
               cout<<"|";
            }
            //next line to complete next row
            cout<<endl;
        }
        
    }
    
}

int main(){
    //test 1
    printGrid(5);
    cout<<endl;
    //test 2
    printGrid(3);
}