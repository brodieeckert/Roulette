#ifndef SINGLE_H
#define SINGLE_H
#include <string>
#include "Board.h"
using namespace std;

class single : public Board
{
private:
    
    int odds = 36;
public:
    int square;
    single();
    single(int square);
    void set_square(int square);
    void Payout(Player* player, int bet);
    int get_square();
    void placebet(int amount,Player* player);

};

#endif