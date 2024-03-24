#include "Pokemon.h"
#include "Trainer.h"
#include "PokeCenter.h"
#include "Grid.h"
#include"Game.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<random>

using namespace std;

string player;


//ask trainer what to do
void Game:: displayMenu(){
    cout << "Please choose from the following options:" << endl<<endl;
    cout << "1. Travel" << endl;
    cout << "2. Rest" << endl;
    cout << "3. Try your luck" << endl;
    cout << "4. Quit the game" << endl;
}

//beginning of game shit
void Game:: welcomeScreen(){
    //ofstream myfile;
    //myfile.open("results.txt");
    cout<<"Welcome to Pokemon!"<<endl<<endl;
    cout<<"Please state your name: "<<endl<<endl;
    string name;
    //cin.ignore();
    getline(cin,name);
    player=name;
    //myfile<<name<<endl;
    cout<<"Welcome, "<<name<< " Before you can begin your "<<endl;
    cout<<"Pokémon adventure, you must choose a starting "<<endl;
    cout<<"Pokémon, courtesy of the Professor. Please "<<endl;
    cout<<"choose from the following Pokémon:"<<endl<<endl;
    cout<<"1. Bulbasaur"<<endl;
    cout<<"2. Charmander"<<endl;
    cout<<"3. Squirtle"<<endl;
    cout<<"4. Pikachu"<<endl;

}

//split
int Game:: split(string split, char delimeter, string arr[], int length){
    int count=0; //split counter which will be returned at the end
    int currentIndex=0; //pointer of the array
    int indexInArray=0; //index that will store the split pieces
    //empty strings return 0
    if(split==""){
        return 0;
    }
    
    //add a delimeter to the end of the string if there already isn't one there
    if(split[split.length()-1]!=delimeter){
        split+=delimeter;
    }
    //remove delimeter from beginning of the string
    if(split[0]==delimeter){
        split=split.substr(split.find(delimeter)+1);
    }
    
    //temportary string variable to be manipulated
    string temp = split; 
    
    //run through the split string
    for(int i=0; i<split.length();i++){
        
        //if the i equals the delimeter: do everything in the if statement
        if(split[i]==delimeter){

            currentIndex = temp.find(delimeter); //set the currentIndex at the location of the delimeter
            arr[indexInArray]=temp.substr(0, currentIndex); //fill the array with the substring starting at 0 to the currentIndex
            indexInArray++; //increment indexInArrat so that next index can be filled
            count++; //increment count because we have made a split
            temp = temp.substr(currentIndex+1); //change the temp string so that it now starts at the index after the index of the found delimeter
                
            
        }
        //check if the first index of the temp string is the delimeter
        if(temp[0]==delimeter){
            //if it is then remove the delimeter by shifting the entire string one index
            temp=temp.substr(temp.find(delimeter)+1);
            //subtract the count var because we did not split anything
            count--;
        }
        
    }
    //edge case: if count>length then return -1
    if(count>length){
        return -1;
    }
    //return the final count var
    return count;
}



//displays map from mapPoke.txt
void Game :: displayMap(string fileName){
    ifstream myfile;
    myfile.open(fileName); //"mapPoke.txt"
    string line;
    int index = 0;
    string mapArray[27][18];
    if(myfile.is_open()){
        while(getline(myfile, line) && index<27){
            string temp[18];
            split(line , ',', temp, 18);
            
            for(int j=0; j<18; j++){
                
                mapArray[index][j]=(temp[j]);
                cout<<" "<<mapArray[index][j];
                
            }  
                index++;
                cout<<endl;
            
        }
    }
    myfile.close();
    cout<<endl;
}

//reads pokemon file and fills an array with pokemon objects
void Game:: loadPokemonArray(string fileName, Pokemon array[151] ){
    ifstream myfile;
    myfile.open(fileName);
    string line;
    int pokemonArrayIndex = 0;
    //Pokemon pokemonArray[151]; 
    if(myfile.is_open()){
        while(getline(myfile,line)){
            if(line!=""){
                string temp[9];
                split(line, ',', temp, 9);
                int pokeHP = stoi(temp[2]);
                int pokeAttack = stoi(temp[3]);
                int pokeDefense = stoi(temp[4]);
                int pokeSpeed = stoi(temp[5]);
                int pokeMax = stoi(temp[6]);
                //filling pokemon array with pokemon objects
                array[pokemonArrayIndex] = Pokemon(temp[1],pokeHP,pokeAttack, pokeDefense ,pokeSpeed, pokeMax, temp[7], temp[8]);
                pokemonArrayIndex++;
            }
        }
        myfile.close();
    }
}

//new grid
void Game:: printGrid(Grid map,Trainer object){
    //problem below
    for(int i=0;i<27;i++){
        for(int j=0; j<18; j++){
            if(i==object.getYpos()&&j==object.getXpos()){
                map.grid[i][j]="@";
            }
            cout<<" " <<map.grid[i][j];
            // cout << " ";
            
        }
        cout<<endl;
    }
}

//7x7 map
void Game:: printVisibility(Grid grid, Trainer object){ //passing in Trainer object(you) so we can get coordinates
    for(int i=object.getYpos()-3;i<object.getYpos()+4;i++){
        for(int j=object.getXpos()-3; j<object.getXpos()+4; j++){
            if(i==object.getYpos()&&j==object.getXpos()){
                grid.grid[i][j]="@";
            }
            //printing contents of the objects 2D grid
            cout<<" " <<grid.grid[i][j];
            
        }
        cout<<endl;
    }
}


void Game::shiftPokemon(Grid map){
    int count = 0;
    while(count<20){
        int randX = rand()%18;
        //cout<<"randX: "<<randX<<endl;
       
        int randY = rand()%27;
        //cout<<"randY: "<<randY<<endl;
        
        //int randPoke = rand()%152;
     
        if(map.grid[randY][randX]=="x"){
            map.grid[randY][randX]="*"; //for testing
            //wildPokemons.push_back(array[randPoke]);
            map.wildPokemons[count].setXCoord(randX);
            map.wildPokemons[count].setYCoord(randY);
            map.grid[randY][randX]="x";
            
            count++;
        }
    }
}

//function for fightting other pokemons***
void Game::combat(Trainer t, Grid m){
    //note: when traversing the grid we will add the last pokemon that is found if necessary
    int combatChoice;
    int escape;
    int wildPokeChance;
    int randX;
    int randY;
    int x;
    int y;
    int randEscape;
    int fleeAttemps = 1;
    string changePoke;
    string opponent;
    int index;
    int attackChance;
    bool combat = true;
    bool found = false;
    
    int randAttack;
    int randDefense;
    //go through grid
    for(int i=t.getYpos()-2;i<t.getYpos()+3;i++){
        //y=i;
        for(int j=t.getXpos()-2; j<t.getXpos()+3; j++){
            //x=j;
            //cout<<map.grid[i][j]<<endl;
            if(m.grid[i][j]=="x" ){
                found = true;
                //go through wildPokemon vector 
                for(int k=0;k<m.wildPokemons.size();k++){
                    if(m.wildPokemons[k].getXCoord()==j&&m.wildPokemons[k].getYCoord()==i){
                        opponent = m.wildPokemons[k].getPokemonName();
                        //cout<<"Oppenent: "<<opponent<<endl;
                        index = k;
                        x=j;
                        y=i;
                        //cout<<"Index: "<<index<<endl;
                        if(t.getNumPokemonTrainer()<2){
                            t.addPokemon(m.wildPokemons[k]);
                            cout<<"You added "<<m.wildPokemons[k].getPokemonName()<<" to your collection"<<endl;
                            cout<<"Name: "<<m.wildPokemons[k].getPokemonName()<<", HP: "<<m.wildPokemons[k].getHP()<<", A: "<<m.wildPokemons[k].getAttack()<<", D: "<<m.wildPokemons[k].getDefense()<<", S: "<<m.wildPokemons[k].getSpeed()<<", M: "<<m.wildPokemons[k].getMax()<<endl;
                            m.grid[y][x]="*";
                            t.getAllPokemon(); //*
                            printVisibility(m,t);
                            
                            return;
                        }
                        
                    }
                }
            }
        }
    }
    if(found==false){
        cout<<"No wild pokemon were found."<<endl;
        return;
    }
    
    // cout<<"x: "<<x<<endl;
    // cout<<"y: "<<y<<endl;
    
    cout<<"You ran into a wild pokemon: "<<endl;
    cout<<"Oppenent: "<<opponent<<endl;
    cout<<"Name: "<<m.wildPokemons[index].getPokemonName()<<", HP: "<<m.wildPokemons[index].getHP()<<", A: "<<m.wildPokemons[index].getAttack()<<", D: "<<m.wildPokemons[index].getDefense()<<", S: "<<m.wildPokemons[index].getSpeed()<<", M: "<<m.wildPokemons[index].getMax()<<endl;
    cout<<"Your active pokemon is: "<<endl;
    t.getActivePokemonStats();
    cout<<endl;
    while(combat){
        cout<<"Please choose from the following options: (1,2,3, or 4)"<<endl;
        cout<<"1. Fight"<<endl;
        cout<<"2. Switch Active pokemon"<<endl;
        cout<<"3. Run"<<endl;
        cout<<"4. Quit"<<endl;
        cin>>combatChoice;
        switch(combatChoice){
            // cout<<"x: "<<x<<endl;
            // cout<<"y: "<<y<<endl;
            //fight
            case 1:
                wildPokeChance=rand()%10;
                //if wild pokemon tries to flee
                if(wildPokeChance<4){
                    escape = (((m.wildPokemons[index].getSpeed()*32)/((t.activePokemon.getSpeed())/4)%256)+30)*fleeAttemps;
                    if(escape>255){
                        cout<<m.wildPokemons[index].getPokemonName()<<" escaped!"<<endl;
                        
                        //change location of wildpokemon
                        randX=rand()%18;
                        randY=rand()%27;
                        m.wildPokemons[index].setXCoord(randX);
                        m.wildPokemons[index].setYCoord(randY);
                        m.grid[y][x]="*";
                        m.grid[randY][randX]="x";
                        printVisibility(m,t);
                        return;
                    }else{
                        randEscape= rand()%256;
                        if(randEscape<escape){
                            cout<<m.wildPokemons[index].getPokemonName()<<" escaped!"<<endl;
                           
                            //change location of wildpokemon
                            randX=rand()%18;
                            randY=rand()%27;
                            m.wildPokemons[index].setXCoord(randX);
                            m.wildPokemons[index].setYCoord(randY);
                            m.grid[y][x]="*";
                            m.grid[randY][randX]="x";
                            printVisibility(m,t);
                            return;
                        }else{
                            cout<<m.wildPokemons[index].getPokemonName()<<" wanted to flee but was too slow!"<<endl;
                            cout<<"You caught "<<m.wildPokemons[index].getPokemonName()<<endl;
                            m.grid[y][x]="*";
                            t.addPokemon(m.wildPokemons[index]);
                            t.getAllPokemon();
                            printVisibility(m,t);
                            return;
                        }
                    }
                //if wild pokemon tries to attack
                }else{
                   cout<<m.wildPokemons[index].getPokemonName()<<" wants to attack you!"<<endl; 
                   //im currently here
                   //if opponents speed is greater than yours
                   if(m.wildPokemons[index].getSpeed()>t.activePokemon.getSpeed()){
                       while(t.activePokemon.getHP()>0){
                           randAttack = rand()%m.wildPokemons[index].getAttack();
                           randDefense = rand()%t.activePokemon.getDefense();
                           if(randAttack>randDefense){
                               cout<<"You lost "<<randAttack-randDefense<<" hp!"<<endl;
                               t.activePokemon.setHP(randDefense-randAttack);
                               t.getActivePokemonStats();
                           }else{
                               cout<<"You did not get any damage"<<endl;
                           }
                       }
                       t.setTrainerPoints(-10);
                       cout<<"Your active pokemon fainted:("<<endl;
                       //setting hp to 0
                       t.activePokemon.resetHP(0);
                       t.getActivePokemonStats();
                       t.changeActivePokemon(1);
                       cout<<"Here is your new active pokemon:"<<endl;
                       t.getActivePokemonStats();
                       //transport to poke center
                       
                       if(m.wildPokemons[index].getSpeed()<t.activePokemon.getSpeed()){
                            cout<<"You escaped!"<<endl;
                            for(int i=t.getYpos()-3;i<t.getYpos()+4;i++){
                                for(int j=t.getXpos()-3; j<t.getXpos()+4; j++){
                                    if(m.grid[i][j]=="C"){
                                        t.setLocation(j,i);
                                        break;
                                    }
                                }
                                break;
                            }
                            printVisibility(m, t);
                            return;
                        }
                       return;
                   }else{
                       while(m.wildPokemons[index].getHP()>0){
                           randDefense =rand()%m.wildPokemons[index].getDefense();
                           randAttack = rand()%t.activePokemon.getAttack();
                           if(randAttack>randDefense){
                               cout<<m.wildPokemons[index].getPokemonName()<<" lost "<<randAttack-randDefense<<" hp!"<<endl;
                               m.wildPokemons[index].setHP(randDefense-randAttack);
                               cout<<"Name: "<<m.wildPokemons[index].getPokemonName()<<", HP: "<<m.wildPokemons[index].getHP()<<", A: "<<m.wildPokemons[index].getAttack()<<", D: "<<m.wildPokemons[index].getDefense()<<", S: "<<m.wildPokemons[index].getSpeed()<<", M: "<<m.wildPokemons[index].getMax()<<endl;
                           }else{
                               cout<<"Your opponent did not get any damage"<<endl;
                           }
                       }
                       cout<<"You defeated "<<m.wildPokemons[index].getPokemonName()<<"!"<<endl;
                       t.setTrainerPoints(20);
                       m.wildPokemons[index].setHP(m.wildPokemons[index].getMax());
                       t.addPokemon(m.wildPokemons[index]);
                       m.grid[y][x]="*";
                       t.getAllPokemon();
                       numPoints+=10;
                       printVisibility(m,t);
                       return;
                   }
                }
            
            
                break;
            //switch active pokemon
            case 2:
                t.getAllPokemon();
                cout<<"Enter the name of your new active pokemon: "<<endl;
                cin>>changePoke;
                t.setActivePokemon(changePoke);
                cout<<endl;
                t.getActivePokemonStats();
                
                break;
            //run
            case 3:
                if(m.wildPokemons[index].getSpeed()<t.activePokemon.getSpeed()){
                    cout<<"You escaped!"<<endl;
                    for(int i=t.getYpos()-3;i<t.getYpos()+4;i++){
                        for(int j=t.getXpos()-3; j<t.getXpos()+4; j++){
                            if(m.grid[i][j]=="C"){
                                t.setLocation(j,i);
                                break;
                            }
                        }
                        break;
                    }
                    printVisibility(m, t);
                    return;
                }else{
                    escape = (((t.activePokemon.getSpeed()*32)/((m.wildPokemons[index].getSpeed())/4)%256)+30)*fleeAttemps;
                    fleeAttemps++;
                }
                if(escape>255){
                    cout<<"You escaped!"<<endl;
                    for(int i=t.getYpos()-3;i<t.getYpos()+4;i++){
                        for(int j=t.getXpos()-3; j<t.getXpos()+4; j++){
                            if(m.grid[i][j]=="C"){
                                t.setLocation(j,i);
                                break;
                            }
                        }
                        break;
                    }
                    printVisibility(m, t);
                    return;
                }else{
                    randEscape=rand()%256;
                    if(randEscape<escape){
                        cout<<"You escaped!"<<endl;
                        for(int i=t.getYpos()-3;i<t.getYpos()+4;i++){
                            for(int j=t.getXpos()-3; j<t.getXpos()+4; j++){
                                if(m.grid[i][j]=="C"){
                                    t.setLocation(j,i);
                                    break;
                                }
                            }
                            break;
                        }
                        printVisibility(m, t);
                        return;
                    }else{
                        cout<<"You did not escape "<<m.wildPokemons[index].getPokemonName()<<endl;
                    }
                }
                break;
            
            case 4: 
                combat=false;
                break;
                
            default:
                cout<<"Please choose a valid option."<<endl;
        }
    }
}

void Game:: trainerEncounter(Trainer y, Grid chart){
    ofstream myfile;
    myfile.open("results.txt");
    string change; //for changing active pokemon
    int trainerChoice;
    int randAttack;
    int randDefense;
    bool encounter = true;
    int index;
    //bool win = false;
    cout<<"You have entered a Gym!"<<endl;
    for(int i=0;i<chart.trainers.size();i++){
        if(chart.trainers[i].getXpos()==y.getXpos()&&chart.trainers[i].getYpos()==y.getYpos()){
            cout<<"Here is your opponent's active pokemon:"<<endl;
            chart.trainers[i].getActivePokemonStats();
            index = i;
        }
    }
    cout<<"Here are you active pokemon stats:"<<endl;
    y.getActivePokemonStats();
    cout<<endl;
    while(encounter){
        if(y.getNumBadges()>1){
            cout<<"You won the game!"<<endl;
            return;
        }
        cout<<"Choose from the following options: "<<endl;
        cout<<"1. Fight"<<endl;
        cout<<"2. Change active pokemon"<<endl;
        cout<<"3. Leave gym"<<endl;
        cin>>trainerChoice;
        switch(trainerChoice){
            case 1:
                if(chart.trainers[index].activePokemon.getSpeed()>y.activePokemon.getSpeed()){
                    while(y.activePokemon.getHP()>0){
                       randAttack = rand()%chart.trainers[index].activePokemon.getAttack();
                       randDefense = rand()%y.activePokemon.getDefense();
                           if(randAttack>randDefense){
                               cout<<"You lost "<<randAttack-randDefense<<" hp!"<<endl;
                               y.activePokemon.setHP(randDefense-randAttack);
                               y.getActivePokemonStats();
                           }else{
                               cout<<"You did not get any damage"<<endl;
                           }
                       }
                       y.setTrainerPoints(-10);
                       cout<<"Your active pokemon fainted:("<<endl;
                       //setting hp to 0
                       y.activePokemon.resetHP(0);
                       cout<<"Here is your new active pokemon"<<endl;
                       y.changeActivePokemon(1);
                       y.getActivePokemonStats();
                       break;
                    }else{
                        while(chart.trainers[index].activePokemon.getHP()>0){
                        randDefense = rand()%chart.trainers[index].activePokemon.getDefense();
                        randAttack = rand()%y.activePokemon.getAttack();
                            if(randAttack>randDefense){
                               cout<<chart.trainers[index].activePokemon.getPokemonName()<<" lost "<<randAttack-randDefense<<" hp!"<<endl;
                               chart.trainers[index].activePokemon.setHP(randDefense-randAttack);
                               cout<<"Name: "<<chart.trainers[index].activePokemon.getPokemonName()<<", HP: "<<chart.trainers[index].activePokemon.getHP()<<", A: "<<chart.trainers[index].activePokemon.getAttack()<<", D: "<<chart.trainers[index].activePokemon.getDefense()<<", S: "<<chart.trainers[index].activePokemon.getSpeed()<<", M: "<<chart.trainers[index].activePokemon.getMax()<<endl;
                            }else{
                               cout<<"Your opponent's active pokemon did not get any damage"<<endl;
                            }
                        }
                        y.setTrainerPoints(10);
                        cout<<"You defeated your opponent!"<<endl;
                        //setting hp to 0
                        y.addPokemon(chart.trainers[index].activePokemon);
                        y.getAllPokemon();
                        numPoints+=30;
                        win=true;
                        
                        if(win==true){
                            y.setBadges(1);
                        }else{
                            y.setBadges(0);
                        }
                        cout<<"You have "<<y.getNumBadges()<<" badges!"<<endl;
                        break;
                    
                    }
                break;
            case 2:
                y.getAllPokemon();
                cout<<"Enter the name of your new active pokemon: "<<endl;
                cin>>change;
                y.setActivePokemon(change);
                y.getActivePokemonStats();
                break;
            case 3:
                encounter=false;
                break;
            default:
                cout<<"Select a valid option please"<<endl;
                break;
        }
    }
}


//Travel, rest, try your luck, or quit
void Game::play(Trainer you, Grid map){
    int gameChoice;
    
    string change;
    string newPoke;
    
    int chance; 
    int count = 0;//for wild pokemons
    bool gamePlay = true;
    string direction;
    while(gamePlay){
        //cout<<"Num badges: "<<you.getNumBadges();
        displayMenu();
        cin>>gameChoice;
        switch(gameChoice){
            //travel
            case 1: 
                cout<<"What direction would you like to travel? (N,S,E,or W)"<<endl;
                //travel one space in any direction, make sure not to go out of bounds or in water
                cin>>direction;
                if(direction=="N"){
                    
                    if(map.grid[you.getYpos()-1][you.getXpos()]=="-"){
                        cout<<"You cannot go out of bounds, choose again"<<endl;
                        break;
                    }
                    
                    
                    if(map.grid[you.getYpos()-1][you.getXpos()]=="~"){
                        cout<<"You cannot go in water, choose again"<<endl;
                        break;
                    }
                    
                    you.setLocation(you.getXpos(), you.getYpos()-1);
                    cout<<"Your location is @ x: "<<you.getXpos()<<", y: "<<you.getYpos()<<endl;
                    printVisibility(map, you);
                }else if(direction=="S"){
                    
                    if(map.grid[you.getYpos()+1][you.getXpos()]=="-"){
                        cout<<"You cannot go out of bounds, choose again"<<endl;
                        break;
                    }
                    
                    
                    
                    if(map.grid[you.getYpos()+1][you.getXpos()]=="~"){
                        cout<<"You cannot go in water, choose again"<<endl;
                        break;
                    }
                    
                    you.setLocation(you.getXpos(), you.getYpos()+1);
                    cout<<"Your location is @ x: "<<you.getXpos()<<", y: "<<you.getYpos()<<endl;
                    printVisibility(map, you);
                }else if(direction=="E"){
                    
                    if(map.grid[you.getYpos()][you.getXpos()+1]=="|"){
                        cout<<"You cannot go out of bounds, choose again"<<endl;
                        break;
                    }
                    
                    
                    if(map.grid[you.getYpos()][you.getXpos()+1]=="~"){
                        cout<<"You cannot go in water, choose again"<<endl;
                        break;
                    }
                    
                    you.setLocation(you.getXpos()+1, you.getYpos());
                    cout<<"Your location is @ x: "<<you.getXpos()<<", y: "<<you.getYpos()<<endl;
                    printVisibility(map, you);
                }else if(direction=="W"){
                    
                    if(map.grid[you.getYpos()][you.getXpos()-1]=="|"){
                        cout<<"You cannot go out of bounds, choose again"<<endl;
                        break;
                    }
                    
                    if(map.grid[you.getYpos()][you.getXpos()-1]=="~"){
                        cout<<"You cannot go in water, choose again"<<endl;
                        break;
                    }
                    
                    you.setLocation(you.getXpos()-1, you.getYpos());
                    cout<<"Your location is @ x: "<<you.getXpos()<<", y: "<<you.getYpos()<<endl;
                    printVisibility(map, you);
                }else{
                    cout<<"Please state a valid direction"<<endl;
                    break;
                }
                
                if(map.grid[you.getYpos()][you.getXpos()]=="C"){ //problem here
                    cout<<"You have entered a Pokemon Center"<<endl;
                    cout<<"You have "<<you.getNumPokeBalls()<<" pokeballs."<<endl;
                    you.getAllPokemon();
                    cout<<"Would you like to change your active pokemon? (Yes/No)"<<endl;
                    cin>>change;
                    if(change=="Yes"||change=="yes"||change=="Y"){
                        cout<<"Enter the name of your new active pokemon: "<<endl;
                        cin>>newPoke;
                        you.setActivePokemon(newPoke);
                        cout<<endl;
                        you.getActivePokemonStats();
                    }else{
                        cout<<"Active pokemon is the same"<<endl;
                    }
                }
                
                //trainer encounter
                if(map.grid[you.getYpos()][you.getXpos()]=="G"){
                    trainerEncounter(you,map);
                }
            
                break;
            //rest    
            case 2: 
                you.setNumPokeBalls(-1);
                cout<<"You have "<<you.getNumPokeBalls()<<" pokeballs."<<endl;
                you.changeHP(1);
                cout<<"All your pokemon have increased their hp by 1. Your location did not change."<<endl;
                //cout<<you.activePokemon.getHP()<<endl;
                you.getAllPokemon();
                you.getActivePokemonStats();
                break;
            //try your luck    
            case 3: 
                //cout<<"Number of pokemon: "<<you.getNumPokemonTrainer()<<endl;
                if(you.getNumPokemonTrainer()>6){
                    cout<<"You have the maximum number of pokemon"<<endl;
                    break;
                }
                //0=true, 1=false
                cout<<"There is a 50% chance that you catch a wild pokemon for free"<<endl;
                chance =rand()%2; 
                //if 0, catch pokemon, else fight pokemon
                if(chance==0){
                        for(int i=you.getYpos()-3;i<you.getYpos()+4;i++){
                            for(int j=you.getXpos()-3; j<you.getXpos()+4; j++){
                                if(map.grid[i][j]=="x" ){
                                    //cout<<"We are in"<<endl;
                                    for(int k=0;k<map.wildPokemons.size();k++){
                                        if(map.wildPokemons[k].getXCoord()==j&&map.wildPokemons[k].getYCoord()==i){
                                            if(you.getNumPokemonTrainer()>2){
                                                break;
                                            }
                                            
                                            // cout<<"Congrats, you have collected some wild pokemon!"<<endl;
                                            you.addPokemon(map.wildPokemons[k]); //yeet that pokemon
                                            you.setTrainerPoints(5);
                                            numPoints+=5;
                                            map.grid[i][j]="*"; //changing tile back
                                        }
                                    }
                                    //break;
                                }
                                
                            }
                            //break;
                        }
                    cout<<"Congrats, you have collected some wild pokemon!"<<endl;
                    you.getAllPokemon();
                    printVisibility(map, you);
                    cout<<"Keep trying your luck to battle wild pokemon."<<endl;
                    shiftPokemon(map);
                    //printGrid(map,you); //shift wild pokemon
                }else{
                    //not lucky means you have to fight a wildpokemon ^^
                    cout<<"You did not catch a wildpokemon for free. Let's see if we must fight one"<<endl;
                    combat(you,map);
                }
                break;
            //quit    
            case 4:
                cout<<"Thanks for playing!"<<endl;
                gamePlay=false;
                break;
            default:
                cout<<"Please select a valid option"<<endl;
                break;
        }
    }
}


//"main" method
void Game:: driver(){
    
    win=false;
    numPoints =0;
    ofstream myfile;
    myfile.open("results.txt");
    
    Grid map; //creating Grid object to construct a grid
    Trainer you(0,0,0,0,0); //creating Trainer object(main player) 
    
    Pokemon pokemonArray[151]; //array of pokemon objects
    loadPokemonArray("pokemon.txt", pokemonArray); //filling pokemon array
    
    cout<<"This is the game map: "<<endl;
    
    displayMap("mapPoke.txt");
    
    welcomeScreen();
    
    //user choice for starting pokemon
    int choice; 
    cin>>choice;
    
    if(choice==1){
        for(int i=0; i<151; i++){
            if(pokemonArray[i].getPokemonName()=="Bulbasaur"){
                //updating active pokemon and trainer stuff
                you.setLocation(7,13);
                you.addPokemon(i);
                you.setActivePokemon(i);
                cout<<"You chose "<<pokemonArray[i].getPokemonName()<<endl;
                break;
            }
        }
    }else if(choice==2){
        for(int i=0; i<151; i++){
            if(pokemonArray[i].getPokemonName()=="Charmander"){
                //updating active pokemon and trainer stuff
                you.setLocation(8,13);
                you.addPokemon(i);
                you.setActivePokemon(i);
                cout<<"You chose "<<pokemonArray[i].getPokemonName()<<endl;
                break;
            }
        }
    }else if(choice==3){
        for(int i=0; i<151; i++){
            if(pokemonArray[i].getPokemonName()=="Squirtle"){
                //updating active pokemon and trainer stuff
                you.setLocation(9,13);
                you.addPokemon(i);
                you.setActivePokemon(i);
                cout<<"You chose "<<pokemonArray[i].getPokemonName()<<endl;
                break;
            }
        }
    }else if(choice==4){
        for(int i=0; i<151; i++){
            if(pokemonArray[i].getPokemonName()=="Pikachu"){
                //updating active pokemon and trainer stuff
                you.setLocation(10,13);
                you.addPokemon(i);
                you.setActivePokemon(i);
                cout<<"You chose "<<pokemonArray[i].getPokemonName()<<endl; 
                break;
            }
        }
    }
    
        
    you.getActivePokemonStats();//printing active pokemon stats
    cout<<"Your location is @ x: "<<you.getXpos()<<", y: "<<you.getYpos()<<endl;
    cout<<"Here is your location on the map: "<<endl<<endl;
    
    //full size grid 
    printGrid(map,you);
    
    //7x7 grid
    printVisibility(map,you);
    cout<<endl;

    
    //now ask what the player wants to do
    //switch/while
    play(you,map);
   
    myfile<<"Name  |  Points"<<endl;
    myfile<<player<<"       "<<numPoints<<endl;
    if(win==true){
        myfile<<"You won!"<<endl;
    }else{
        myfile<<"You lost:("<<endl;
    }
}


