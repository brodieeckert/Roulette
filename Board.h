#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Player.h"
using namespace std;

class Board : public Player
{
protected:
    
public:
    int current_bet[10];
    virtual void Payout(Player* player, int bet) = 0; 
    virtual void placebet(int amount, Player* player) = 0;
};



#endif