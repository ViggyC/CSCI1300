// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika!!
// Homework 4 - Problem # 2
#include<iostream>
using namespace std;

//method takes in an array of ints and the length of the array
void printArrReverse(int arr[], int length){
    //start from the last element of the array
    //and move down one index each iteration
    for(int i=length-1; i>=0; i--){
        cout<<arr[i]<<endl; //print the value of the array at i
    }
}
int main(){
    //test 1
    int arr[]={1,2,3,4,5,6,7};
    int len=7;
    printArrReverse(arr,len);
    cout<<endl;
    //test 2
    	
    int arr2[] = {-1, 8, -78};
    int len2 = 3;
    printArrReverse(arr2, len2);
}