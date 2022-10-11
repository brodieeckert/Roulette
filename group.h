#ifndef GROUP_H
#define GROUP_H
#include <string>
#include "Board.h"

using namespace std;

class group: public Board
{
protected:
    string name;
    int size;
    int* squares;
    float odds;
    

public:
    group();
    group(int* squaress,int size,string name);
    void Payout(Player* player,int bet);
    void placebet(int amount,Player* player);
    bool isincluded(int square);
    float get_odds();

};
#endif

