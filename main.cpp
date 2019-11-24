#include "Player.h"

int main()
{
    RenderWindow window(sf::VideoMode(1280, 720), "Clone_Mario");

    Player hero(250, 250, 0, 0, 67, 93, "img/allHeroes/p1_walk.png");

    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
            hero.dir = Left;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.Sprite.setTextureRect(IntRect(67 * int(CurrentFrame)+67, 93, -66, 93));
        }

        if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
            hero.dir = Right;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.Sprite.setTextureRect(IntRect(71 * int(CurrentFrame), 93+93, 70, 93));
        }

        if(Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
            hero.dir = Up;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 2) CurrentFrame -= 2;
            hero.Sprite.setTextureRect(IntRect(70 * int(CurrentFrame), 93+93+93, 70, 93));
        }

        if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
            hero.dir = Down;
            hero.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            hero.Sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 93, 67, 93));
        }

        hero.update(time);

        window.clear();
        window.draw(hero.Sprite);
        window.display();
    }

    return 0;
}