#include "single.h"
single::single(){
    this->square = -1;
    for(int i = 0; i <10;i++){
        this->current_bet[i] = 0;
    }

}
single::single(int squaree)
{ 
    this->set_square(squaree);
    for(int i = 0; i <10;i++){
        this->current_bet[i] = 0;
    }
}
void single::set_square(int squaree){
    this->square = squaree;
}
void single::placebet(int amount, Player* player){
    if(amount <= player[0].get_money()){
        player[0].set_money(player[0].get_money() - amount);
        this->current_bet[player[0].get_index()] = this->current_bet[player[0].get_index()] + amount;
    }
    else cout << "Insufficient funds (" << player[0].get_money() << ")\n" ;
}

void single::Payout(Player* player, int bet){

    player[0].set_money(player[0].get_money() + bet);
}

int single::get_square(){return this->square;}