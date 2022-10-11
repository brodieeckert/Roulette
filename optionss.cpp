#include <iostream>
#include "optionss.h"
using namespace std;

optionss::optionss()
{
    this->choice = -1;
    this->edit = -1;
    this->maxBet = 100;
    this-> minBet = 0;
    this->PlayerNum = 3;
    this->startBal = 10000;
    this->spins = 10;
}
void optionss::set_startbal(int startbal){this->startBal = startbal;}
void optionss::set_startbal(){
    cout << " Starting balance" ;
    cin >> this->startBal;
    if (this->startBal <=0 || this->startBal < minBet || this->startBal > 1000000){
        cout << "Please enter a starting balance larger than the minimum bet (" << this->minBet << ") and inbetween 0 and 1000000" << endl <<  endl;
        this->set_startbal();
    }
}
void optionss::set_PlayerNum(int num){this->PlayerNum = num;}
void optionss::set_PlayerNum(){
    cout << " Number of players: ";
    cin >> this->PlayerNum;
    if (this->PlayerNum <0 || this->PlayerNum > 10){
        cout << "Only 1-10 players allowed." << endl <<  endl;
        this->set_PlayerNum();
    }

}
void optionss::set_spins(int spins){this->spins=spins;}
void optionss::set_spins(){
    cout << " Number of spins: " ;
    cin >> this->spins;
    if (this->spins <0 || this->spins > 100){
        cout << "Only 1-100 spins allowed." << endl <<  endl;
        this->set_spins();
    }
}

void optionss::set_edit(int edit){
    this->edit = edit;
}
int optionss::get_edit(){
    return this->edit;

}
void optionss::set_choice(){
    cin >> this->choice;

}
int optionss::get_choice(){
    return this->choice;
}
void optionss::change_startbal(float change){
    this->startBal += change;
}
void optionss::set_maxbet(int max){this->maxBet=max;}
void optionss::set_minbet(int min){this->minBet=min;}

optionss::~optionss()
{
}
