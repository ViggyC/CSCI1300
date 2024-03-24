// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika!!
// Homework 4 - Problem # extra credit
#include<iostream>
using namespace std;

void shiftElements(int array[], int length, int shifts){
    //counter variable to be implemented in while loop
    int timesShifted = 0;
    
    //shifts less than or equal to 0 print no shift
    if(shifts<=0){
        cout<<"No shift"<<endl;
        return;
    }

    //while counter is less than the inputted amount of shifts, do everything in the loop
    while (timesShifted < shifts) {
        //set a temp var equal to the last element of the array
        int temp = array[length-1];
        
        //in the foor loop, replace the current index with the element in the previous index
        for (int i = length-1; i>0; i--) {

            array[i] = array[i-1];

         }
         //then set the first element to the temp variable
        array[0] = temp;
        //increment counter
        timesShifted++;
    }
}

//helper method that prints the values in the array from the above method
void printArray(int arr[], int len){
    for(int i=0; i<len; i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    //test 1, expected: 30 10 20
    int arr1[3] = {10, 20, 30};
    shiftElements(arr1, 3, 1);
    printArray(arr1, 3);
    cout<<endl;
    
    //test 2, expected: no shift, 10 20 30 40 50
    int arr2[5] = {10, 20, 30, 40, 50};
    shiftElements(arr2, 5, -2);
    printArray(arr2, 5);
    cout<<endl;
    
    //test 3, expected: 40 50 10 20 30
    int arr3[5] = {10, 20, 30, 40, 50};
    shiftElements(arr3, 5, 7);
    printArray(arr3, 5);
    
}