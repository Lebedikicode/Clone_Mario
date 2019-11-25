#include <SFML/Graphics.hpp>
#include <string.h>

using namespace sf;

#ifndef SFMLDEMO_PLAYER_H
#define SFMLDEMO_PLAYER_H

enum Direction {
    Left = 0, Right, Up, Down
};

class Player {
private:
    float x, y;
public:
    float dx, dy; // координаты
    int dir = 0; // направление
    float speed = 0; // скорость с которой двигается персонаж
    std::string file; // путь к изображению
    Image Img;
    Texture Texture;
    Sprite Sprite;
    Player(float x, float y, int rL, int rT, int rW, int rH, std::string file);
    void update(float time);
    float getX(); // координаты персонажа по х
    float getY(); // координаты персонажа по у
};


#endif //SFMLDEMO_PLAYER_H
