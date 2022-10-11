#ifndef OPTIONS_H
#define OPTIONS_H
#include <string>
#include "menu.h"
using namespace std;

class optionss : public menu
{
private:
    int edit;
    int choice;
public:
    optionss(/* args */);
    void set_startbal();
    void set_startbal(int money);
    void set_PlayerNum();
    void set_PlayerNum(int num);
    void set_spins();
    void set_spins(int spins);
    void set_maxBet();
    void set_maxbet(int max){this->maxBet=max;}
    void set_minBet();
    void set_minBet(int min){this->minBet=min;}
    void set_edit(int edit);
    int get_edit();
    void set_choice();
    int get_choice();
    void change_startbal(int change);
    ~optionss();
};

#endif
