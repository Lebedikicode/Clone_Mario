#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "View.h"
#include "Map.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(910, 595), "Mario");
    view.reset(FloatRect(0, 0, 910, 595));

    Map map;
    map.createMap();

    map.tileSet.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/grass_photo-resizer.ru.png");
    map.tileSet2.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/box_photo-resizer.ru.png");
    map.tileSet3.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/liquidWater_photo-resizer.ru.png");
    map.tileSet4.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/boxAlt_photo-resizer.ru.png");
    map.tileSet5.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/door_closedMid_photo-resizer.ru.png");
    map.tileSet6.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/door_closedTop_photo-resizer.ru.png");
    map.tileSet7.loadFromFile("/Users/n1kta/CLionProjects/SFMLDemo/img/lock_green_photo-resizer.ru.png");

    Sprite tile;

    Player hero(50, 300, 32, 45, "img/allHeroes/p1_walk_photo-resizer.ru.png");

    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 700;

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if(hero.life){
            getCameraFollowHero(hero.getX(), hero.getY());
        }

        hero.update(time);
        window.setView(view);
        window.clear();

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                tile.setTexture(map.tileSet3);
                tile.setPosition(j * 35, i * 35);
                window.draw(tile);
            }
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (map.al[i][j] == 'A') tile.setTexture(map.tileSet);
                else if (map.al[i][j] == 'B') tile.setTexture(map.tileSet2);
                else if (map.al[i][j] == 'C') tile.setTexture(map.tileSet7);
                else if (map.al[i][j] == 'D') tile.setTexture(map.tileSet2);
                else if (map.al[i][j] == 'E') tile.setTexture(map.tileSet4);
                else if (map.al[i][j] == 'P') tile.setTexture(map.tileSet5);
                else if (map.al[i][j] == 'L') tile.setTexture(map.tileSet6);
                else continue;

                tile.setPosition(j*35, i*35);
                window.draw(tile);
            }
        }

        window.draw(hero.Sprite);
        window.display();
    }

    return 0;
}