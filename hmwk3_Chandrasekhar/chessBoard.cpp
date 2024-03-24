// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem #3
#include<iostream>
using namespace std; //including standard library

/**
 * This function takes in a char and int value and outputs the matching color on
 * a chess board. According to whether the number is odd and which letter is inputted
 * the color may be different. Chess boards alternate in color so an even number and the 
 * letter 'a' would output white. The way the program determines the output is through
 * if else statements which decide what color corresponds to the two inputs.
 * Letter must be a-h and number must be 1-8.
 * */

void chessBoard(char letter, int number){
    if(number>8||(letter!='a'&&letter!='b'&&letter!='c'&&letter!='d'&&letter!='e'&&letter!='f'&&letter!='g'&&letter!='h')){
        cout<< "Chessboard squares can only have letters between a-h and numbers between 1-8.";
    }else if(number%2==0 && (letter=='a'||letter=='c'||letter=='e'||letter=='g')){
        cout<<"white";
    }else if(number%2==1 && (letter=='b'||letter=='d'||letter=='f'||letter=='h')){
        cout<<"white";
    }else if(number%2==0 && (letter=='b'||letter=='d'||letter=='f'||letter=='h')){
        cout<<"black";
    }else if(number%2==1 && (letter=='a'||letter=='c'||letter=='e'||letter=='g')){
        cout<<"black";
    }else{
        cout<<"Chessboard squares can only have letters between a-h and numbers between 1-8.";
    }
}

int main(){
    //test 1, expected: white
    chessBoard('c',6);
    cout<<endl;
    //test 2, expected: black
    chessBoard('e', 5);
    cout<<endl;
    //test 3, expected: Chessboard squares can only have letters between a-h and numbers between 1-8.
    chessBoard('k',2);
}