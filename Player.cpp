#include "optionss.h"
#include "Player.h"
#include <iostream>
#include "board.h"
#include "single.h"

Player::Player (){
    this->betting = 1;
    this->index = 0;
    this->_Pmoney = 0;
    this->_Pname = "no name";


}

Player::Player(optionss option){
    this->_Pmoney = option.get_startbal();
}

float Player::get_money(){
return this->_Pmoney;   
}

string Player::get_name(){ return this->_Pname;}
void Player::set_name(string name){
    this->_Pname = name;
}
void Player::set_money(float wealth){
    this->_Pmoney = wealth;
}

void Player::add_money(float money){
    this->_Pmoney += money;
}
int Player::get_index(){
    return this->index;
    
}
void Player::set_index(int i){  
    this->index = i;
}
