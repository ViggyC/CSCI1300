// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika!!
// Homework 4 - Problem # 4

#include<iostream>
using namespace std;

//method takes in an array of ints and the length of the array
void swapFirstLast(int arr[],int length){
    int first=arr[0]; //get value from first index
    int last=arr[length-1]; //get value from last index
    arr[0]=last; //replace first index with the last value
    arr[length-1]=first; //replace last index with the first value
}

int main(){
    //test 1, expected: 51413
    int arr[]={3,1,4,1,5};
    int len = 5;
    swapFirstLast(arr,len);
    for(int i=0; i<len;i++){
        cout<<arr[i];
    }
    
    cout<<endl;
    cout<<endl;
    
    //test 2, expected: 1238
    int arr1[]={8,2,3,1};
    int len1 = 4;
    swapFirstLast(arr1,len1);
    for(int i=0; i<len1;i++){
        cout<<arr1[i];
    }
}