#include <iostream>
#include "menu.h"
#include "optionss.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void menu::save(Player* players,int playersnum){
    ofstream savegame;
    savegame.open("GameFile.csv");
    savegame << "Starting Bal:," << this->get_startbal() << "\n";
    savegame << "Player Num:," << this->get_PlayerNum() << "\n";
    savegame << "Min Bet:," << this->get_minBet() << "\n";
    savegame << "Max bet:," << this->get_maxBet() << "\n";
    savegame << "Spins:," << this->get_spins() << "\n";
    for(int i = 0; i < playersnum; i++){
        savegame << "Player "<< i << " wealth,"<< players[i].get_money()<< "\n";
    }
    for(int i = 0; i < playersnum; i++){
        savegame << "Player "<< i << " Name, "<< players[i].get_name()<< "\n";
    }
    savegame.close();
    

}

void menu::loadgame(string fname, Player* players){
 
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
 
    fstream file (fname, ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
 
            stringstream str(line);
 
            while(getline(str, word, ','))
                row.push_back(word);
                content.push_back(row);
        }
    }
    else cout<<"Could not open the file\n";

    this->startBal = stoi(content[1][0]);
    this->PlayerNum = stoi(content[1][1]);
    this->minBet = stoi(content[1][2]);
    this->maxBet = stoi(content[1][3]);
    this->spins = stoi(content[1][4]);
    for(int i = 0; i < this->PlayerNum; i++){
        players[i].set_money(stoi(content[1][i+5]));
    }
    for(int i = 0; i < this->PlayerNum; i++){
        players[i].set_name(content[1][i+this->get_PlayerNum()]);
    }
}
int menu::get_PlayerNum(){return this->PlayerNum;}
int menu::get_spins(){return this->spins;}
int menu::get_startbal(){return this->startBal;}
int menu::get_minBet(){return this->minBet;}
int menu::get_maxBet(){return this->maxBet;}
