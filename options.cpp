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
    cout << " Starting balence" ;
    cin >> this->startBal;
    if (this->startBal <=0 || this->startBal < minBet || this->startBal > 1000000){
        cout << "Please enter a starting balence larger than the minimum bet (" << this->minBet << ") and inbetween 0 and 1000000" << endl <<  endl;
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
void optionss::set_maxBet(){
    cout << "Max bet: " ;
    cin >> this->maxBet;
    cout << endl;
    if (this->maxBet < minBet || this->maxBet > 100000){
        cout << "Max bet must be larger than the min bet and less than 100000." << endl <<  endl;
        this->set_maxBet();
    }
}
void optionss::set_minBet(){
    cout << "Min bet: ";
    cin >> this->minBet;
    cout << endl;
    if (this->maxBet < this->minBet || this->minBet > startBal){
        cout << "Min bet must be less than the starting balence: " << this->startBal << " and the maximum bet: " << this->maxBet << endl <<  endl;
        this->set_minBet();
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
void optionss::change_startbal(int change){
    this->startBal += change;
}

optionss::~optionss()
{
}
