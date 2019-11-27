#include <SFML/Graphics.hpp>
#include <string.h>

using namespace sf;

#ifndef SFMLDEMO_PLAYER_H
#define SFMLDEMO_PLAYER_H

enum Direction {
    Left = 0, Right, Up, Down, Jump, Stay
};

class Player {
private:
    float x, y;
public:
    float WIDTH, HEIGHT, dx, dy, speed = 0;//  // координаты // скорость с которой двигается персонаж
    int state = 0, health; // направление
    bool life, isMove, onGround;
    std::string file; // путь к изображению
    Image Img;
    Texture Texture;
    Sprite Sprite;


    Player(float x, float y, float WIDTH, float HEIGHT, std::string file);
    void control();
    void update(float time);
    void mapCheck(float Dx, float Dy);
    float getX(); // координаты персонажа по х
    float getY(); // координаты персонажа по у
};


#endif //SFMLDEMO_PLAYER_H
