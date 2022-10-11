#ifndef PLAYER_H
#define PLAYER_H
#include "menu.h"
#include "optionss.h"
#include <string>
#include <iostream>
using namespace std;

class Player
{
protected:
    string _Pname;
    float _Pmoney;
    bool betting;
    int index;
public:
    Player();
    Player(optionss option);
    //Player(int startbal, string name);
    float get_money();
    void set_money(float wealth);
    void add_money(float money);
    void set_name(string name);
    void set_index(int i);
    int get_index();
    string get_name();
    bool get_betting(){ return betting;}
    void set_betting(bool bettin){this->betting = bettin;}
    //void placebet(char betSquare, int amount);
};
#endif