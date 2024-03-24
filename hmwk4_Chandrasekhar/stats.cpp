// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika!!
// Homework 4 - Problem # 3

#include<iostream>
#include <iomanip>
using namespace std;

void stats(double arr[], int length){
    float min=arr[0]; //initialize min value as first element
    float max=arr[0]; //initialize max value as first element
    float average = 0; //initialize average as 0
    float sum=0; //initialize sum as 0
    //go through the array using for loop
    for(int i=0 ;i<length; i++){
        //if the current element in the array is less than the current min value,
        //make the current element the min value
        if(arr[i]<min){
            min=arr[i];
        }
    }
    for(int i=0; i<length; i++){
        //if the current element in the array is greater than the current max value,
        //make the current element the max value
        if(arr[i]>max){
            max=arr[i];
        }
    }
    //go through array and sum all the elements
    for(int i =0; i<length; i++){
        sum+=arr[i];
    }
    average=sum/length; //average is sum of all elements divided by the number of elements
    cout<<setprecision(2)<<fixed<<"Min: "<< min<<endl; //print min with 2 decimal places
    cout<<setprecision(2)<<fixed<<"Max: "<<max<<endl; //print max with 2 decimal places
    cout<<setprecision(2)<<fixed<<"Avg: "<<average; //print average with 2 decimal places
}

int main(){
    //test 1
    double arr[] = {0,1,2,3,4,5,6,7,8,9};
    int len = 10;
    stats(arr, len);
    cout<<endl;
    cout<<endl;
    //test 2
    double arr2[] = {1,1,1,1};
    int len2 = 4;
    stats(arr2, len2);
    cout<<endl;
}