// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Homework 3 - Problem: extra credit
#include<iostream>
using namespace std;
#include<string>

//story 1
void storyOne(){
    string noun;
    cout<<"Enter a noun: "<<endl;
    cin>>noun;
    cout<< "Be careful not to vacuum the "<<noun<< " when you clean under your bed."<<endl;
}

//story 2
void storyTwo(){
    cout<<"Enter a name: "<<endl;
    string name;
    cin>>name;
    cout<<"Enter an occupation: "<<endl;
    string occupation;
    cin>>occupation;
    cout<<"Enter a place: "<<endl;
    string place;
    cin>>place;
    cout<<name << " is a "<<occupation<< " who lives in "<<place<<"."<<endl;
    
}

//story 3
void storyThree(){
    cout<<"Enter a plural noun: "<<endl;
    string plural;
    cin>>plural;
    cout<<"Enter an occupation: "<<endl;
    string occupation;
    cin>>occupation;
    cout<<"Enter an animal: "<<endl;
    string animal;
    cin>>animal;
    cout<< "Enter a place: "<<endl;
    string place;
    cin>>place;
    cout<<"In the book War of the "<< plural<<", the main character is an anonymous " << occupation<<" who records the arrival of the " <<  animal<< "s in " <<place<<"."<<endl;
}

//story 4
void storyFour(){
    cout<<"Good bye!";
}

int main(){
    //continuously ask the questions until 4 is selected
    while(true){
        cout<<"Which story would you like to play? Enter the number of the story (1, 2, or 3) or type 4 to quit"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            storyOne();
            cout<<endl;
        }else if(choice==2){
            storyTwo();
            cout<<endl;
        }else if(choice ==3){
            storyThree();
            cout<<endl;
        }else if(choice==4){
            storyFour();
            break;
        }else{
            continue;
        }
    }
}