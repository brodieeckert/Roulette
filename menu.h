#ifndef MENU_H
#define MENU_H
#include <string>
class Player;
using namespace std;

class menu
{
protected:
    float startBal;       // amount of money they players begin the game with.
    int PlayerNum;      //number of players
    int minBet; // minimum bet that can be placed on a square
    int maxBet; //maximum bet per player per spin 
    int spins;  // spins remaining

public:

    int get_startbal();
    int get_PlayerNum();
    int get_minBet();
    int get_maxBet();
    int get_spins();

    void save(Player* players, int playersNUM);
    void loadgame(string filename,Player* players);
};
#endif