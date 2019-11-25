#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;

int main()
{
    Player hero(50, 470, 0, 0, 67, 93, "img/allHeroes/p1_walk.png");;
    const int height = 17, width = 225;
    RenderWindow window(VideoMode(910, 595), "Mario");
    Texture tileSet;
    tileSet.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/grass_photo-resizer.ru.png");
    Texture tileSet2;
    tileSet2.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/box_photo-resizer.ru.png");
    Texture tileSet3;
    tileSet3.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/liquidWater_photo-resizer.ru.png");
    Texture tileSet4;
    tileSet4.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/boxAlt_photo-resizer.ru.png");
    Texture tileSet5;
    tileSet5.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/door_closedMid_photo-resizer.ru.png");
    Texture tileSet6;
    tileSet6.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/door_closedTop_photo-resizer.ru.png");
    Texture tileSet7;
    tileSet7.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/lock_green_photo-resizer.ru.png");
    Sprite tile;
    String al[height][width];
    std::ifstream file;
    file.open("/Users/n1kta/CLionProjects/SFMLDemo/map.txt");

    float CurrentFrame = 0;
    Clock clock;

    if (!file) return 0;
    for (int r = 0; r < height; r++)
    {
        for (int t = 0; t < width; t++)
        {
            char a;
            file >> a;
            al[r][t] = a;
        }
    }
    file.close();
    int a = 0;
    int b = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1000;

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            hero.dir = Left;
//          hero.speed = 0;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            a += CurrentFrame*1.25;
            hero.Sprite.setTextureRect(IntRect(71 * int(CurrentFrame), 93+93, 70, 93));

            //a+= 0.005 * time;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            a-=0.005 * time;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            b += 0.005 * time;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            b -= 0.005 * time;
        }
        window.clear();
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                tile.setTexture(tileSet3);
                tile.setPosition(j * 35, i * 35);
                window.draw(tile);
            }
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (al[i][j] == 'A') tile.setTexture(tileSet);
                else if (al[i][j] == 'B') tile.setTexture(tileSet2);
                else if (al[i][j] == 'C') tile.setTexture(tileSet7);
                else if (al[i][j] == 'D') tile.setTexture(tileSet2);
                else if (al[i][j] == 'E') tile.setTexture(tileSet4);
                else if (al[i][j] == 'P') tile.setTexture(tileSet5);
                else if (al[i][j] == 'L') tile.setTexture(tileSet6);
                else continue;

                tile.setPosition(j*35-a, i*35+b);
                window.draw(tile);
            }
        }



//        if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
//            hero.dir = Left;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 3) CurrentFrame -= 3;
//            hero.Sprite.setTextureRect(IntRect(67 * int(CurrentFrame)+67, 93, -66, 93));
//        }

//        if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
//            hero.dir = Right;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 3) CurrentFrame -= 3;
//            hero.Sprite.setTextureRect(IntRect(71 * int(CurrentFrame), 93+93, 70, 93));
//        }
//
//        if(Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
//            hero.dir = Up;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 2) CurrentFrame -= 2;
//            hero.Sprite.setTextureRect(IntRect(70 * int(CurrentFrame), 93+93+93, 70, 93));
//        }
//
//        if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
//            hero.dir = Down;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 3) CurrentFrame -= 3;
//            hero.Sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 93, 67, 93));
//        }

        //hero.update(time);

        window.draw(hero.Sprite);
        window.display();
    }




//    while (window.isOpen())
//    {
//        float time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time = time / 800;
//
//        Event event;
//
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
//            hero.dir = Left;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 3) CurrentFrame -= 3;
//            hero.Sprite.setTextureRect(IntRect(67 * int(CurrentFrame)+67, 93, -66, 93));
//        }
//
//        if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
//            hero.dir = Right;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 3) CurrentFrame -= 3;
//            hero.Sprite.setTextureRect(IntRect(71 * int(CurrentFrame), 93+93, 70, 93));
//        }
//
//        if(Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
//            hero.dir = Up;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 2) CurrentFrame -= 2;
//            hero.Sprite.setTextureRect(IntRect(70 * int(CurrentFrame), 93+93+93, 70, 93));
//        }
//
//        if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
//            hero.dir = Down;
//            hero.speed = 0.1;
//            CurrentFrame += 0.005 * time;
//            if (CurrentFrame > 3) CurrentFrame -= 3;
//            hero.Sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 93, 67, 93));
//        }
//
//        hero.update(time);
//
//        window.clear();
//        window.draw(hero.Sprite);
//        window.display();
//    }

    return 0;
}