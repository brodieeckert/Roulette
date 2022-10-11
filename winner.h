#include <string>
#include <random>
#include <iostream>
using namespace std;

class winnerr{
    private:
        int number;
        int total;
        string wintxt;
        int rotation;
        

    public:
        winnerr():number(rand()%37),total(number),wintxt(""){}

        void reset(){
            number = rand()%37;
        }
        int getNumber(){return number;}
        
        int wheel_converter(int rand){
        switch (rand)
    {
    case 9:
        return 0;
        break;
    case 31:
        return 1;
        break;
    case 14:
        return 2;
        break;
    case 20:
        return 3;
        break;
    case 1:
        return 4;
        break;
    case 33:
        return 5;
        break;
    case 16:
        return 6;
        break;
    case 24:
        return 7;
        break;
    case 5:
        return 8;
        break;
    case 10:
        return 9;
        break;
    case 23:
        return 10;
        break;
    case 8:
        return 11;
        break;
    case 30:
        return 12;
        break;
    case 11:
        return 13;
        break;
    case 36:
        return 14;
        break;
    case 13:
        return 15;
        break;
    case 27:
        return 16;
        break;
    case 6:
        return 17;
        break;
    case 34:
        return 18;
        break;
    case 17:
        return 19;
        break;
    case 25:
        return 20;
        break;
    case 2:
        return 21;
        break;
    case 21:
        return 22;
        break;
    case 4:
        return 23;
        break;
    case 19:
        return 24;
        break;
    case 15:
        return 25;
        break;
    case 32:
        return 26;
        break;
    case 0:
        return 27;
        break;
    case 26:
        return 28;
        break;
    case 3:
        return 29;
        break;
    case 35:
        return 30;
        break;
    case 12:
        return 31;
        break;
    case 28:
        return 32;
        break;
    case 7:
        return 33;
        break;
    case 29:
        return 34;
        break;
    case 18:
        return 35;
        break;
    case 22:
        return 36;
    default:
    cout << " SOMETHING IS BROKEN" << endl;
    return -1;
        break;
    }  
        }
};