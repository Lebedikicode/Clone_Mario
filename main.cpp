#include <SFML/Graphics.hpp>
#include <fstream>
#include "Player.h"
#include "View.h"

using namespace sf;

int main()
{
    const int height = 17, width = 225;

    RenderWindow window(VideoMode(910, 595), "Mario");
    view.reset(FloatRect(0, 0, 910, 595));

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

    Player hero(50, 515, 0, 0, 32, 46, "img/allHeroes/p1_walk_photo-resizer.ru.png");

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

        if(Keyboard::isKeyPressed(Keyboard::Left)){
            hero.dir = Left;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.Sprite.setTextureRect(IntRect(34 * int(CurrentFrame)+34, 46, -34, 46));
            getCameraFollowHero(hero.getX(), hero.getY());
        }
        if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
            hero.dir = Right;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.Sprite.setTextureRect(IntRect(35 * int(CurrentFrame), 46*2, 35, 46));
            getCameraFollowHero(hero.getX(), hero.getY());
        }
        if(Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
            hero.dir = Up;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 2) CurrentFrame -= 2;
            hero.Sprite.setTextureRect(IntRect(35 * int(CurrentFrame), 46*3, 35, 46));
            getCameraFollowHero(hero.getX(), hero.getY());
        }

        hero.update(time);
        window.setView(view);
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

                tile.setPosition(j*35, i*35);
                window.draw(tile);
            }
        }

        window.draw(hero.Sprite);
        window.display();
    }

    file.close();
    return 0;
}