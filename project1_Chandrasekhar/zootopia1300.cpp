// CS1300 Fall 2019
// Author: Vignesh Chandrasekhar
// Recitation: 304 – Thanika
// Project 1 - Problem # 3
#include<iostream>
#include<string>
using namespace std;

//given method for menu option
void printMenu(){
	cout<<"Select a numerical option:"<<endl;
	cout<<"=== menu ==="<<endl;
	cout<<"1. Fox"<<endl;
	cout<<"2. Bunny"<<endl;
	cout<<"3. Sloth"<<endl;
	cout<<"4. Quit"<<endl;
}

//method that prints the result of the user input
//based on the option they choose in the menu
void run(){
    double agility;
    double strength;
    double speed;
    int choice;
    //choice 4 just exits the method
    //everything in the while loop is done continously
    while(choice !=4){
        printMenu();
        cin>>choice;
        //for fox
        if(choice==1){
            cout<<"Enter agility: "<<endl;
            cin>>agility;
            cout<<"Enter strength: "<<endl;
            cin>>strength;
            cout<<"Hire score: "<<(1.8*agility)+(2.16*strength)<<endl;
            //for bunny
        }else if(choice==2){
            cout<<"Enter agility: "<<endl;
            cin>>agility;
            cout<<"Enter speed: "<<endl;
            cin>>speed;
            cout<<"Hire score: "<<(1.8*agility)+(3.24*speed)<<endl;
            //for sloth
        }else if(choice==3){
            cout<<"Enter strength: "<<endl;
            cin>>strength;
            cout<<"Enter speed: "<<endl;
            cin>>speed;
            cout<<"Hire score: "<<(2.16*strength)+(3.24*speed)<<endl;
        }else{
            //this would be choice 4, exit the method.
            return;
        }
    }
}




int main(){
    //running method above
     run();
}