#include "Player.h"
#include <iostream>
Player::Player(int x, int y, int rL, int rT, int rW, int rH, std::string file){
    this->x = x;
    this->y = y;
    this->file = file;

    Img.loadFromFile(file);
    Texture.loadFromImage(Img);
    Sprite.setTexture(Texture);
    Sprite.setTextureRect(IntRect(rL, rT, rW, rH));
    Sprite.setPosition(x, y);
}

void Player::update(float time) {
    switch(dir){
        case Left:
            dx = -speed;
            dy = 0;
            break; // L
        case Right:
            dx = speed;
            dy = 0;
            break; // R
        case Up:
            dx = 0;
            dy = -speed;
            break; // U
        case Down:
            dx = 0;
            dy = speed;
            break; // D
    }

    x += dx * time;
    y += dy * time;

    speed = 0;
    Sprite.setPosition(x, y);
}
