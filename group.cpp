#include "group.h"
group::group(){
    this->odds=1;
    this->size=1;
    this->squares=0;
}
group::group(int* squaress,int size,string name)
{   this->_Pname=name;
    this->squares = squaress;
    this->size = size;
    this->odds = 36/size;  
    for(int i = 0; i <10;i++){
        this->current_bet[i] = 0;
    }
}
bool group::isincluded(int square){

    for(int i = 0; i < this->size;i++){
        if(square == this->squares[i]){
            return true;
        }
    }
    return false;
}

void group::Payout(Player* player, int bet){
    player[0].set_money(player[0].get_money() + bet);
}
void group::placebet(int amount, Player* player){
    if(amount <= player[0].get_money()){
        player[0].set_money(player[0].get_money() - amount);
        this->current_bet[player[0].get_index()] = this->current_bet[player[0].get_index()] + amount;
    }
    else cout << "Insufficient funds" << player[0].get_money();
}
float group::get_odds(){return this->odds;}