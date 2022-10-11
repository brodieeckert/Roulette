
#include "main.h"
#include "classes.h"
using namespace sf;

int main()
{
    float sx = 10000;
    float sy = 100;
    RenderWindow window(VideoMode(1000,1000), "GIMME YOUR MONEY!");
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
        wheelbg.setTexture(wheel);
        wheelbg.setOrigin(528/2.f, 528/2.f);
        wheelbg.setPosition(528/2+10,528/2+30);

        winner win;
        int winner = rand()%37;
        int ttlWin = winner;
        float rotation = 0;


        // font shiz
        Font casfont;
        casfont.loadFromFile("Le Casino Royale.otf");
        Text winnertxt;
        winnertxt.setFont(casfont);
        winnertxt.setCharacterSize(140); // in pixels, not points!
        winnertxt.setFillColor(Color::Red);
        winnertxt.setStyle(Text::Bold);
        winnertxt.setOrigin(70,70);
        winnertxt.setPosition(528/2+30,528/2);

        //font shiz ^^
    while (window.isOpen())
    {

        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            window.close();
        }



        //spinning 

        if(Keyboard::isKeyPressed(Keyboard::Space) ){
            while(rotation <= win.getNumber()*360/37){
                float speed = 2;  // this value needs to be this for some reason otherwise it misaligns.
                rotation = rotation + speed;
                wheelbg.rotate(speed);

                //draw
                window.clear(Color(255, 255, 255, 255));
                window.draw(wheelbg);
                window.draw(wpointer);
                window.draw(winnertxt);
                window.display();
            }
            
        }
        if(!(Keyboard::isKeyPressed(Keyboard::Space)) && rotation > win.getNumber()*360/37){
            rotation = 0;
            winnertxt.setString(to_string(wheel_converter(ttlWin%37)));
            
            win.reset();

            ttlWin = ttlWin+win.getNumber();
            
        }


            window.clear(Color(255, 255, 255, 255));
            window.draw(wheelbg);
            window.draw(wpointer);
            window.draw(winnertxt);
            window.display();
    }
    
    
    return 0;
}