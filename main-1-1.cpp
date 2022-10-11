#include "menu.h"
#include "optionss.h"
#include "Player.h"
#include "single.h"
#include "Board.h"
#include "group.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "winner.h"
//using namespace std;
using namespace sf;

int main(){
    
    int wH=1000;
    int wW=2400;
    RenderWindow window(VideoMode(wW,wH), "GIMME YOUR MONEY!");
    Event event;
    CircleShape wpointer(15.f);
    wpointer.setRotation(180.f);
    wpointer.setPointCount(3);
    wpointer.setPosition(280,15);
    wpointer.setFillColor(Color::Blue);
    wpointer.setOrigin(Vector2f(5,5));
    Sprite wheelbg;
       
    Texture wheel;
    wheel.loadFromFile("wheel.png");

    Texture refboardpic;
    refboardpic.loadFromFile("refboard.png");

    Sprite refboard;

    refboard.setTexture(refboardpic);
    refboard.setPosition(wW/2-200,wH/2);
    wheelbg.setPosition(-528/2+2400,-528/2+1000);

    wheelbg.setTexture(wheel);
    int wheeldim = 528;
    wheelbg.setOrigin(wheeldim/2.f, wheeldim/2.f);
    wheelbg.setPosition(-528/2+2400,-528/2+1000);
    // font shiz
    Font casfont;
    casfont.loadFromFile("coolvetica rg.otf");
    Text menutext;
    menutext.setFont(casfont);
    menutext.setCharacterSize(100); // in pixels, not points!
    menutext.setFillColor(Color::Red);
    menutext.setStyle(Text::Bold);
    menutext.setPosition(10,10);
    while (window.isOpen()){
        //font shiz ^^
        while(window.pollEvent(event)){if(event.type == Event::Closed){window.close();}}
        srand (time(NULL));
        // Menu screen
        int gametype = 0;
        menutext.setString("Welcome to Casino Roulette!\nPlease Enter your option: \n1. New Game \n2. Load game");
        window.clear(Color(255, 255, 255, 255));
        window.draw(menutext);
        window.display();
        while(gametype != 1 && gametype != 2){
            while(window.pollEvent(event)){if(event.type == Event::Closed){window.close();}}

            if (Keyboard::isKeyPressed(Keyboard::Num1)){
            gametype = 1;
            }
            if (Keyboard::isKeyPressed(Keyboard::Num2)){
            gametype = 2;
            }
        }

        /* check for valid input option
        while (gametype != 1 && gametype != 2){
        cout << "Please enter a value number, 1 or 2:" << endl;
        cin >> gametype;
        } */ // might not be needed with sfml

        optionss *option = new optionss;
        Player* players{ new Player[10]};       //create array of the players
        int optedit = -1;
        if (gametype == 1){
            
            while(!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::B)){
                while(window.pollEvent(event)){if(event.type == Event::Closed){window.close();}}

                menutext.setString("Please Enter your option: \nA. Start Game \nB. Change Options");
                window.clear(Color(255, 255, 255, 255));
                window.draw(menutext);
                window.display();
            };

            while(optedit != 1 && optedit != 2){
                while(window.pollEvent(event)){if(event.type == Event::Closed){window.close();}}

                if (Keyboard::isKeyPressed(Keyboard::A)){
                    optedit = 1;
                }
                else if (Keyboard::isKeyPressed(Keyboard::B)){
                    optedit = 2;
                }
            }
            option[0].set_edit(optedit); 
            string optionstext = "";
            while(option[0].get_edit() == 2){
                while(window.pollEvent(event)){if(event.type == Event::Closed){window.close();}}

                optionstext = "";
    
                optionstext.append( "Which option would you like to change? \n");
                optionstext.append("0. (Done)\n");
                optionstext.append("1. Starting amount (" + to_string(option[0].get_startbal()));
                optionstext.append(") \n2. Number of players (" + to_string(option[0].get_PlayerNum()));
                optionstext.append(") \n3. Min/Max bet (" + to_string(option[0].get_minBet())+ "/" + to_string(option[0].get_maxBet()));
                optionstext.append(") \n4. Number of Spins (" + to_string(option[0].get_spins()) + ")");

                menutext.setString(optionstext);
                window.clear(Color(255, 255, 255, 255));
                window.draw(menutext);
                window.display();
            
                char optionschoice = ' ';
                optedit = -1;
                if (event.type == sf::Event::TextEntered){
                    
                    optionschoice = event.text.unicode;
                    optedit = optionschoice-48;
                }
                window.clear(Color(255, 255, 255, 255));
                window.draw(menutext);
                window.display(); 
                bool brk = 0;
                switch (optedit){
                    case 0:
                        option[0].set_edit(1);
                        break;
            
                    case 1:
                        optionstext = "";
                        menutext.setString("New Starting balance:" + optionstext);
                        window.clear(Color(255, 255, 255, 255));
                        window.draw(menutext);
                        window.display();
                        while (!Keyboard::isKeyPressed(Keyboard::Enter))
                        {   
                            while(window.pollEvent(event)){
                                
                               if(event.type == Event::Closed){window.close();}

                                if (event.type == sf::Event::TextEntered){
                                    optionstext += event.text.unicode;
                                    menutext.setString("New Starting balance:" + optionstext);
                                    }
                                if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                                {
                                    optionstext ="";
                                    menutext.setString(("New Starting balance:" + optionstext));
                                }
                                window.clear(Color(255, 255, 255, 255));
                                window.draw(menutext);
                                window.display();
                                
                            }
                        }
                        option->set_startbal(stoi(string("0"+optionstext)));
                        if(option->get_startbal() == 0){option->set_startbal(1000);}
                        break;
                        
                    case 2:
                        optionstext = "";
                        menutext.setString("Set Player Number:" + optionstext);
                        window.clear(Color(255, 255, 255, 255));
                        window.draw(menutext);
                        window.display();
                        while (!Keyboard::isKeyPressed(Keyboard::Enter) || brk == 0)
                        {   
                            while(window.pollEvent(event)){
                                
                               if(event.type == Event::Closed){window.close();}

                                if (event.type == sf::Event::TextEntered){
                                    optionstext = event.text.unicode;
                                    menutext.setString("Set Player Number:" + optionstext);
                                    }
                                for(int pnum = 1; pnum <11 ; pnum++){
                                    if (optionstext == to_string(pnum)){
                                    brk = 1;
                                    }
                                }
                                window.clear(Color(255, 255, 255, 255));
                                window.draw(menutext);
                                window.display();
                                
                                
                            }
                        }
                        option->set_PlayerNum(stoi(string("0"+optionstext)));
                        break;
                    case 3:
                        optionstext = "";
                        menutext.setString("Max bet:" + optionstext);
                        window.clear(Color(255, 255, 255, 255));
                        window.draw(menutext);
                        window.display();
                        while (!Keyboard::isKeyPressed(Keyboard::Enter))
                        {   
                            while(window.pollEvent(event)){
                                
                               if(event.type == Event::Closed){window.close();}

                                if (event.type == sf::Event::TextEntered){
                                    optionstext += event.text.unicode;
                                    menutext.setString("Max bet:" + optionstext);
                                    }
                                if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                                {
                                    optionstext ="";
                                    menutext.setString(("Max bet:" + optionstext));
                                }
                                window.clear(Color(255, 255, 255, 255));
                                window.draw(menutext);
                                window.display();
                                
                            }
                        }
                        option->set_maxbet(stoi(string("0"+optionstext)));

                        optionstext = "";
                        menutext.setString("Min bet:" + optionstext);
                        window.clear(Color(255, 255, 255, 255));
                        window.draw(menutext);
                        window.display();
                        while(Keyboard::isKeyPressed(Keyboard::Enter)){

                        }
                        while (!Keyboard::isKeyPressed(Keyboard::Enter))
                        {   
                            while(window.pollEvent(event)){
                                
                               if(event.type == Event::Closed){window.close();}

                                if (event.type == sf::Event::TextEntered){
                                    optionstext += event.text.unicode;
                                    menutext.setString("Min bet:" + optionstext);
                                    }
                                if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                                {
                                    optionstext ="";
                                    menutext.setString(("Min bet:" + optionstext));
                                }
                                window.clear(Color(255, 255, 255, 255));
                                window.draw(menutext);
                                window.display();

                            }
                        }
                        option->set_minbet(stoi(string(optionstext))); 

                        if(option->get_minBet() < option->get_maxBet()){break;}
                        else{
                            option->set_minbet(option->get_maxBet());
                            option->set_maxbet(stoi(string(optionstext)));
                            }
                        
                    case 4:
                        optionstext = "";
                        menutext.setString("Spins:" + optionstext);
                        window.clear(Color(255, 255, 255, 255));
                        window.draw(menutext);
                        window.display();
                        while (!Keyboard::isKeyPressed(Keyboard::Enter))
                        {   
                            while(window.pollEvent(event)){
                                
                               if(event.type == Event::Closed){window.close();}

                                if (event.type == sf::Event::TextEntered){
                                    optionstext += event.text.unicode;
                                    menutext.setString("Spins:" + optionstext);
                                    }
                                if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                                {
                                    optionstext ="";
                                    menutext.setString(("Spins:" + optionstext));
                                }
                                window.clear(Color(255, 255, 255, 255));
                                window.draw(menutext);
                                window.display();
                                
                            }
                        }
                        option->set_spins(stoi(string(optionstext)));
                        break;
                    default:
                        break;
                }
            }

            Player Playerdefault(option[0]);
            for(int i = 0; i < option[0].get_PlayerNum();i++){
                players[i] = Playerdefault;
                players[i].set_money(option->get_startbal());
                players[i].set_index(i);

                string optionstext = "";
                menutext.setString(string("Please Enter Player " + to_string(i+1)) + "'s name: " );
                window.clear(Color(255, 255, 255, 255));
                window.draw(menutext);
                window.display();
                while (Keyboard::isKeyPressed(Keyboard::Space)){
                }
                while (!Keyboard::isKeyPressed(Keyboard::Space))
                {   
                    while(window.pollEvent(event)){
                        
                        if(event.type == Event::Closed){window.close();}

                        if (event.type == sf::Event::TextEntered){
                            optionstext += event.text.unicode;
                            menutext.setString(string("Please Enter Player " + to_string(i+1)) + string("'s name: " + optionstext));
                            }
                        if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                        {
                            optionstext ="";
                            menutext.setString(string("Please Enter Player " + to_string(i+1)) + "'s name: " );
                        }
                        window.clear(Color(255, 255, 255, 255));
                        window.draw(menutext);
                        window.display();
                        
                    }
                }

                players[i].set_name(optionstext);
                players[i].set_betting(1);
            }

            option[0].save(players,option->get_PlayerNum());        //save the game to file with current settings
        }

    
    if (gametype == 1 || gametype == 2){ //Loading game from file for new game and loaded game
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
    
        fstream file ("GameFile.csv", ios::in);
        if(file.is_open()){

            while(getline(file, line)){
                row.clear();
    
                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                    content.push_back(row);
            }
            

        option[0].set_startbal(stoi("0"+content[0][1]));
        option[0].set_PlayerNum(stoi("0"+content[1][1]));
        option[0].set_minbet(stoi("0"+content[2][1]));
        option[0].set_maxbet(stoi("0"+content[3][1]));
        option[0].set_spins(stoi("0"+content[4][1]));
        for(int i = 0; i < option[0].get_PlayerNum(); i++){
            players[i].set_money(stoi("0"+content[i+5][1]));
        }
        for(int i = 0; i < option[0].get_PlayerNum(); i++){
            players[i].set_name(content[i+5+option[0].get_PlayerNum()][1]);
        }
        for(int i = 0; i < option[0].get_PlayerNum(); i++){
            players[i].set_index(i);
        }
// turn the above into a function in options and also make options utility calss 

        single _0(0);
        single _1(1);
        single _2(2);
        single _3(3);
        single _4(4);
        single _5(5);
        single _6(6);
        single _7(7);
        single _8(8);
        single _9(9);        
        single q(10);
        single w(11);
        single e(12);
        single r(13);
        single t(14);
        single y(15);
        single u(16);
        single letteri(17);
        single o(18);
        single a(19);
        single s(20);
        single d(21);
        single f(22);
        single g(23);
        single h(24);
        single letterj(25);
        single k(26);
        single l(27);
        single z(28);
        single x(29);
        single c(30);
        single v(31);
        single b(32);
        single n(33);
        single m(34);
        single comma(35);
        single fullstop(36);

        single* singles[37];
        singles[0] = &_0;
        singles[1] = &_1;
        singles[2] = &_2;
        singles[3] = &_3;
        singles[4] = &_4;
        singles[5] = &_5;
        singles[6] = &_6;
        singles[7] = &_7;
        singles[8] = &_8;
        singles[9] = &_9;
        singles[10] = &q;
        singles[11] = &w;
        singles[12] = &e;
        singles[13] = &r;
        singles[14] = &t;
        singles[15] = &y;
        singles[16] = &u;
        singles[17] = &letteri;
        singles[18] = &o;
        singles[19] = &a;
        singles[20] = &s;
        singles[21] = &d;
        singles[22] = &f;
        singles[23] = &g;
        singles[24] = &h;
        singles[25] = &letterj;
        singles[26] = &k;
        singles[27] = &l;
        singles[28] = &z;
        singles[29] = &x;
        singles[30] = &c;
        singles[31] = &v;
        singles[32] = &b;
        singles[33] = &n;
        singles[34] = &m;
        singles[35] = &comma;
        singles[36] = &fullstop;

        group* groups[13];
        //row1 
        int* tildaNums{ new int[9]{1,2,3,4,5,6,7,8,9}};
        group tilda(tildaNums,9,"tilda");
        groups[0]=&tilda;
        
        //row2
        int* Pnums{ new int[9]{10,11,12,13,14,15,16,17,18}};
        group P(Pnums,9,"P");
        groups[1]=&P;
        //row3
        int* semicolnums{ new int[9]{19,20,21,22,23,24,25,26,27}};
        group semicol(semicolnums,9,"semicol");
        groups[2]=&semicol;
        //row4
        
        int* slashNums{ new int[9]{28,29,30,31,32,33,34,35,36}};
        group slash(slashNums,9,"slash");
        groups[3]=&slash;
        //left third
        int* backticknums{ new int[12]{1,2,3,q.get_square(),w.get_square(),e.get_square(),a.get_square(),s.get_square(),d.get_square(),z.get_square(),x.get_square(),c.get_square()}};
        group backtick(backticknums,12,"backtick");
        groups[4]=&backtick;
        //middle third
        int* underlinenums{ new int[12]{4,5,6,r.get_square(),f.get_square(),v.get_square(),t.get_square(),g.get_square(),b.get_square(),y.get_square(),h.get_square(),n.get_square()}};
        group underline(underlinenums,12,"underline");
        groups[5]=&underline;
        //right third
        int* plusnums{ new int[12]{7,8,9,u.get_square(),letterj.get_square(),m.get_square(),letteri.get_square(),k.get_square(),comma.get_square(),o.get_square(),l.get_square(),fullstop.get_square()}};
        group plus(plusnums,12,"plus");
        groups[6]=&plus;
        // red numbers
        int* backslashnums{ new int[18]{9,18,7,12,3,32,19,21,25,34,27,36,30,23,5,16,1,14}};
        group backslash(backslashnums,18,"backsla");
        groups[7]=&backslash;
        // black numbers
        int* vertlinenums{ new int[18]{22,29,28,35,26,15,4,2,17,6,13,11,8,10,24,33,20,31}};
        group vertline(vertlinenums,18,"vertline");
        groups[8]=&vertline;
        //first 18
        int* LsqrBracketnums{ new int [18]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18}};
        group LsqrBracket(LsqrBracketnums,18,"lsqrt");
        groups[9]=&LsqrBracket;
        //second 18
        int* RsqrBracketnums{ new int [18]{19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}};
        group RsqrBracket(RsqrBracketnums,18,"rsqer");
        groups[10]=&RsqrBracket;
        //odd
        int* minusnums{ new int [18]{1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35}};
        group minus(minusnums,18,"minus");
        groups[11]=&minus;
        //even
        int* equalnums{ new int [18]{2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36}};
        group equal(equalnums,18,"equal");
        groups[12]=&equal;

        for (int i = 0; i < 37;i++){
                for(int i = 0; i <10;i++){
                    singles[i]->current_bet[i] = 0;
                }
            }
            for (int i = 0; i < 13;i++){
                for(int i = 0; i <10;i++){
                    groups[i]->current_bet[i] = 0;
                }
            }

        for (int S = option[0].get_spins();option[0].get_spins()>=0;S--){
            for (int I = 0; I < option[0].get_PlayerNum();I++){
                while(players[I].get_betting() == true){

                    string optionstext = "";
                    menutext.setString(string(players[I].get_name() + ", Place your bet. \n (Enter ! once you have placed all your bets)\n") + string("Current balance: " + to_string((int)players[I].get_money())) +"\nSquare / group: " );
                    window.clear(Color(255, 255, 255, 255));
                    window.draw(refboard);
                    window.draw(menutext);
                    window.display();
                    while (Keyboard::isKeyPressed(Keyboard::Enter)){
                    }
                    while (!Keyboard::isKeyPressed(Keyboard::Enter))
                    {   
                        while(window.pollEvent(event)){
                            
                            if(event.type == Event::Closed){window.close();}

                            if (event.type == sf::Event::TextEntered){
                                optionstext = event.text.unicode;
                                menutext.setString(string(players[I].get_name() + ", Place your bet. \n (Enter ! once you have placed all your bets)\n") + string("Current balance: " + to_string((int)players[I].get_money())) +"\nSquare / group: " + optionstext);
                                }
                            window.clear(Color(255, 255, 255, 255));
                            window.draw(refboard);
                            window.draw(menutext);
                            window.display();
                        }
                    }

                    string squarechoice = optionstext;
                    char choice = squarechoice[0];
                    if (optionstext[0] == '!')
                    {
                        players[I].set_betting(false);
                        break;
                    }

                    optionstext = "";
                    menutext.setString("How much would you like to bet ? \n");
                    window.clear(Color(255, 255, 255, 255));
                    window.draw(refboard);
                    window.draw(menutext);
                    window.display();
                    while (Keyboard::isKeyPressed(Keyboard::Enter)){
                    }
                    while (!Keyboard::isKeyPressed(Keyboard::Enter))
                    {   
                        while(window.pollEvent(event)){
                            
                            if(event.type == Event::Closed){window.close();}

                            if (event.type == sf::Event::TextEntered){
                                optionstext += event.text.unicode;
                                menutext.setString("How much would you like to bet ? " + optionstext );
                            }
                            if (Keyboard::isKeyPressed(Keyboard::BackSpace)){
                            optionstext ="";
                            menutext.setString(string("How much would you like to bet ?"));
                            }
                            window.clear(Color(255, 255, 255, 255));
                            window.draw(refboard);
                            window.draw(menutext);
                            window.display();
                        }
                    }
                    
                    int amount = stoi(string(optionstext));
                    if(amount < option->get_minBet() || amount > option->get_maxBet()){
                        choice = ' ';
                    }
                    switch (choice)
                    {
                    case '1':
                        _1.placebet(amount,&players[I]);
                        break;
                    case '2':
                        _2.placebet(amount,&players[I]);
                        break;
                    case '3':
                        _3.placebet(amount,&players[I]);
                        break;
                    case '4':
                        _4.placebet(amount,&players[I]);
                        break;
                    case '5':
                        _5.placebet(amount,&players[I]);
                        break;
                    case '6':
                        _6.placebet(amount,&players[I]);
                        break;
                    case '7':
                        _7.placebet(amount,&players[I]);
                        break;
                    case '8':
                        _8.placebet(amount,&players[I]);
                        break;
                    case '9':
                        _9.placebet(amount,&players[I]);
                        break;
                    case '0':
                        _0.placebet(amount,&players[I]);
                        break;
                    case 'q':
                        q.placebet(amount,&players[I]);
                        break;
                    case 'w':
                        w.placebet(amount,&players[I]);
                        break;
                    case 'e':
                        e.placebet(amount,&players[I]);
                        break;
                    case 'r':
                        r.placebet(amount,&players[I]);
                        break;
                    case 't':
                        t.placebet(amount,&players[I]);
                        break;
                    case 'y':
                        y.placebet(amount,&players[I]);
                        break;
                    case 'u':
                        u.placebet(amount,&players[I]);
                        break;
                    case 'i':
                        letteri.placebet(amount,&players[I]);
                        break;
                    case 'o':
                        o.placebet(amount,&players[I]);
                        break;
                    case 'a':
                        a.placebet(amount,&players[I]);
                        break;
                    case 's':
                        s.placebet(amount,&players[I]);
                        break;
                    case 'd':
                        d.placebet(amount,&players[I]);
                        break;
                    case 'f':
                        f.placebet(amount,&players[I]);
                        break;
                    case 'g':
                        g.placebet(amount,&players[I]);
                        break;
                    case 'h':
                        h.placebet(amount,&players[I]);
                        break;
                    case 'j':
                        letterj.placebet(amount,&players[I]);
                        break;
                    case 'k':
                        k.placebet(amount,&players[I]);
                        break;
                    case 'l':
                        l.placebet(amount,&players[I]);
                        break;
                    case 'z':
                        z.placebet(amount,&players[I]);
                        break;
                    case 'x':
                        x.placebet(amount,&players[I]);
                        break;
                    case 'c':
                        c.placebet(amount,&players[I]);
                        break;
                    case 'v':
                        v.placebet(amount,&players[I]);
                        break;
                    case 'b':
                        b.placebet(amount,&players[I]);
                        break;
                    case 'n':
                        n.placebet(amount,&players[I]);
                        break;
                    case 'm':
                        m.placebet(amount,&players[I]);
                        break;
                    case ',':
                        comma.placebet(amount,&players[I]);
                        break;
                    case '.':
                        fullstop.placebet(amount,&players[I]);
                        break;
                    case '~':
                        tilda.placebet(amount,&players[I]);
                        break;
                    case 'p':
                        P.placebet(amount,&players[I]);
                        break;
                    case ';':
                        semicol.placebet(amount,&players[I]);
                        break;
                    case '/':
                        slash.placebet(amount,&players[I]);
                        break;
                    case '-':
                        minus.placebet(amount,&players[I]);
                        break;
                    case '+':
                        plus.placebet(amount,&players[I]);
                        break;
                    case '=':
                        cout << equal.current_bet[I] << endl;
                        equal.placebet(amount,&players[I]);
                        cout << equal.current_bet[I]<< " "<< I<< endl;
                        break;
                    case '_':
                        underline.placebet(amount,&players[I]);
                        break;
                    case '"':
                        backslash.placebet(amount,&players[I]);
                        break;
                    case '\'':
                        vertline.placebet(amount,&players[I]);
                        break;
                    case '[':
                        LsqrBracket.placebet(amount,&players[I]);
                        break;
                    case ']':
                        RsqrBracket.placebet(amount,&players[I]);
                        break;
                    case '`':
                        backtick.placebet(amount,&players[I]);
                        break;
                    
                    default:
                    cout << "Please select a valid square or group" << endl;
                        break;
                    }
                    
                }
            }
            int winner = rand()%37;
            cout << "The winning number was " << winner << endl;

            CircleShape wpointer(15.f);
            wpointer.setRotation(180.f);
            wpointer.setPointCount(3);
            wpointer.setPosition(wW-270,wH-20-wheeldim);
            wpointer.setFillColor(Color::Blue);
            wpointer.setOrigin(Vector2f(5,5));
            Sprite wheelbg;
            Texture wheel;


            wheel.loadFromFile("wheel.png");
            wheelbg.setTexture(wheel);
            wheelbg.setOrigin(wheeldim/2.f, wheeldim/2.f);
            wheelbg.setPosition(-wheeldim/2+wW-20,-wheeldim/2+wH-20);
            winnerr dub;
            //get this wheel spining
            while (window.isOpen()){
                while(window.pollEvent(event)){if(event.type == Event::Closed)window.close();}
                //spinning 

                while(!Keyboard::isKeyPressed(Keyboard::Space)){
                    while(window.pollEvent(event)){if(event.type == Event::Closed)window.close();}
                    //draw
                    wheelbg.rotate(1);
                    window.clear(Color(255, 255, 255, 255));
                    menutext.setString("Press space to stop wheel!");
                    window.draw(menutext);
                    window.draw(wheelbg);
                    window.draw(wpointer);
                    window.display();
                }
                wheelbg.setRotation(((dub.wheel_converter(winner)*360))/37); //23 is the offset for the slowing action.
                wheelbg.rotate(23*360/37);

                float speed = 0;
                while(!Keyboard::isKeyPressed(Keyboard::Enter)){
                    while(window.pollEvent(event)){if(event.type == Event::Closed)window.close();}
                    if (speed >= 1){
                        speed = speed - 0.001;;
                    }
                    
                    wheelbg.rotate(1-speed);
                    speed = speed + 0.001;
                    
                    window.clear(Color(255, 255, 255, 255));
                    menutext.setString("Press Enter to skip");
                    window.draw(menutext);
                    window.draw(wheelbg);
                    window.draw(wpointer);
                    window.display();
                    

                    
                    }
                if(Keyboard::isKeyPressed(Keyboard::Enter)){
                    break;
                }
            }

            
            for(int j = 0; j < option[0].get_PlayerNum();j++){
                for (int i = 0; i < 37;i++){
                    if (singles[i][0].get_square() == winner){
                        singles[i][0].Payout(&players[j],36 * singles[i][0].current_bet[j]);
                    }
                }
                for ( int i = 0; i < 13;i++){                   
                    if (groups[i][0].isincluded(winner)){
                        groups[i][0].Payout(&players[j],groups[i][0].get_odds() * groups[i][0].current_bet[j]);
                    }
                }

                for (int i = 0;i<option[0].get_PlayerNum();i++){players[i].set_betting(1);}
                
            }
            string leaderboard = "";
            //Maybe something to sort
            while (window.isOpen()){
                while(window.pollEvent(event)){if(event.type == Event::Closed)window.close();}
                //spinning 

                while(!Keyboard::isKeyPressed(Keyboard::Space)){
                    while(window.pollEvent(event)){if(event.type == Event::Closed)window.close();}
                    //draw
                    window.clear(Color(255, 255, 255, 255));

                    leaderboard = "Congratulations to the winners, here are the standings...\n";

                    int countr = 0;
                    int doubls = 0;
                    int order[option->get_PlayerNum()] = {-1};

                    for(int i = 0; i< option->get_PlayerNum();i++){
                        for(int j = 0; j<i;j++){
                            if(players[i].get_money() == players[j].get_money()){
                                players[i].add_money(0.001*i);
                            }
                        }
                    }
                    for(int i = 0; i < option->get_PlayerNum() ;i++){
                        countr = 0;
                        for(int j = 0; j < option->get_PlayerNum();j++){
                            if (i == j){continue;}
                            if (players[i].get_money() < players[j].get_money()){
                                countr ++;
                            }
                        }
                        order[countr] = players[i].get_index(); 
                    }
                    
                    for(int j = 0; j < option[0].get_PlayerNum();j++){  
                        leaderboard.append(to_string(j+1));
                        leaderboard.append(" " + players[order[j]].get_name() + " $" + to_string((int)players[order[j]].get_money()) + "\n");
                    }
                    leaderboard.append("\n\n\n" + to_string(option->get_spins()-1) + " Spins Left!");
        
                    menutext.setString(leaderboard);
                    window.draw(wheelbg);
                    window.draw(wpointer);
                    window.draw(menutext);
                    window.display();
                }
                break;
                }
                
            for (int i = 0; i < 37;i++){
                for(int i = 0; i <10;i++){
                    singles[i]->current_bet[i] = 0;
                }
            }
            for (int i = 0; i < 13;i++){
                for(int i = 0; i <10;i++){
                    groups[i]->current_bet[i] = 0;
                }
            }
            option[0].set_spins(option[0].get_spins()-1);
            winner = rand()%37;
            option[0].save(players,option->get_PlayerNum());
        }
        
    }
}
}
}
