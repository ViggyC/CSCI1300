// CS1300 Fall 2019
// Author: my name
// Recitation: 304 - Thanika
// Homework 5 - Problem # 1

#include<fstream>
#include<string>
#include<iostream>
using namespace std;

int getLinesFromFile(string fileName, int arr[], int length){
    ifstream myfile; //creating file object
    int index = 0; //intitalizing index of array that will store values
    string line = ""; //creating an empty string that will serve as a pointer for the file
    myfile.open(fileName); //openning the file that will be passed through
    
    //if the file does not exist return -1
    if(myfile.fail()){
        return -1;
    }else if(myfile.is_open()){
        
          while(getline(myfile, line)) //keep getting each line of the file until it ends
          {
              if(line!="") //if it's not an empty line, do the operation below
              {
                  if(index==length) //edge case so that index doesn't go out of bounds
                  {
                      return index;
                  }
                  //store the integer value of the line in the array
                  arr[index]=stoi(line);
              }
              else
              {
                  continue; //if the line is empty, go to the next line
              }
              index++; //increment index
            
        }  
    }

    myfile.close(); //close the file at the end
    return index;
    
}

//helper method that will print the contents of the array
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<< " ";
    }
}

int main(){
    //test 1, expected: Function returned 4
    int arr[4];
    int x = getLinesFromFile("numbers.txt", arr, 4);
    cout << "Function returned: " << x << endl;
    printArray(arr, 4);
    
    cout<<endl<<endl;
    
    //test 2, expected: Function returned 7
    int arr1[7];
    int y= getLinesFromFile("numbers2.txt", arr1, 7);
    cout << "Function returned: " << y << endl;
    printArray(arr1, 7);
}