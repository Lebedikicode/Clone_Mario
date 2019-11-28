#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include "Player.h"
#include "View.h"
#include "Map.h"
#include "Enemy.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(910, 595), "Mario", Style::Titlebar);
    view.reset(FloatRect(0, 0, 910, 595));

    Map map;
    map.createMap();

    map.tileSet.loadFromFile("img/grass_photo-resizer.ru.png");
    map.tileSet2.loadFromFile("img/box_photo-resizer.ru.png");
    map.tileSet3.loadFromFile("img/liquidWater_photo-resizer.ru.png");
    map.tileSet4.loadFromFile("img/boxAlt_photo-resizer.ru.png");
    map.tileSet5.loadFromFile("img/door_closedMid_photo-resizer.ru.png");
    map.tileSet6.loadFromFile("img/door_closedTop_photo-resizer.ru.png");
    map.tileSet7.loadFromFile("img/lock_green_photo-resizer.ru.png");

    Sprite tile;

    Player hero(50, 300, 32, 45, "img/allHeroes/p1_walk_photo-resizer.ru.png");
    Enemy enemy(6580, 492, 32, 45, "img/allHeroes/p3_walk_photo-resizer.ru.png");
    Enemy enemy1(2150, 492, 32, 45, "img/allHeroes/p3_walk_photo-resizer.ru.png");
    Enemy enemy2(3000, 492, 32, 45, "img/allHeroes/p3_walk_photo-resizer.ru.png");

    float CurrentFrame = 0;
    Clock clock;

    bool isGame = true;

    Music music;//создаем объект музыки
    music.openFromFile("Ayy_Macarena_-_Tyga (online-audio-converter.com).wav");//загружаем файл
    music.play();//воспроизводим музыку

    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        float time_en = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        time_en = time_en / 900;

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if(hero.life){
            getCameraFollowHero(hero.getX(), hero.getY());
        }

        if(Keyboard::isKeyPressed(Keyboard::Left)){
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.Sprite.setTextureRect(IntRect(34 * int(CurrentFrame)+34, 46, -35, 46));
            getCameraFollowHero(hero.getX(), hero.getY());
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.Sprite.setTextureRect(IntRect(36 * int(CurrentFrame), 47*2, 35, 46));
            getCameraFollowHero(hero.getX(), hero.getY());
        }
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 2) CurrentFrame -= 2;
            hero.Sprite.setTextureRect(IntRect(35 * int(CurrentFrame), 46*3, 35, 46));
            getCameraFollowHero(hero.getX(), hero.getY());
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 2) CurrentFrame -= 2;
            hero.Sprite.setTextureRect(IntRect(35 * int(CurrentFrame), 140, 35, 46));
            getCameraFollowHero(hero.getX(), hero.getY());
        }

        enemy.update(time_en);
        enemy1.update(time_en);
        enemy2.update(time_en);
        hero.update(time);

        if (hero.y >= 600){
            break;
        }

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

        if((int)hero.x == (int)enemy.x && (int)hero.y == ((int)enemy.y-192)){
            enemy.dx = 0;
            sleep(1);
            isGame = false;
        }
        if((int)hero.x == (int)enemy1.x){
            enemy.dx = 0;
            sleep(1);
            isGame = false;
        }
        if((int)hero.x == (int)enemy2.x){
            enemy.dx = 0;
            sleep(1);
            isGame = false;
        }

        if((int)hero.x == 7770){
            sleep(1);
            isGame = false;
        }

        if(!isGame){
            music.stop();
            return 0;
        }

        window.draw(enemy1.Sprite);
        window.draw(enemy2.Sprite);
        window.draw(enemy.Sprite);
        window.draw(hero.Sprite);
        window.display();
    }

    return 0;
}