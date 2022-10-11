#ifndef OPTIONSS_H
#define OPTIONSS_H
#include "menu.h"
#include <string>
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
    void change_startbal(float change);
    void set_PlayerNum(int num);
    void set_spins();
    void set_spins(int spins);
    void set_maxbet(int max);
    void set_minbet(int min);
    void set_edit(int edit);
    int get_edit();
    void set_choice();
    int get_choice();
    ~optionss();
};

#endif
