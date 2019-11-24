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

public:
    float x, y, dx, dy; // координаты
    float speed = 0; // скорость с которой двигается персонаж
    int dir = 0; // направление
    std::string file; // путь к изображению
    Image Img;
    Texture Texture;
    Sprite Sprite;
    Player(int x, int y, int rL, int rT, int rW, int rH, std::string file);
    void update(float time);

};


#endif //SFMLDEMO_PLAYER_H
