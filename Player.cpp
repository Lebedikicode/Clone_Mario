#include <iostream>
#include "Player.h"
#include "Map.h"


Player::Player(float x, float y, float WIDTH, float HEIGHT, std::string file){
    this->x = x;
    this->y = y;
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    this->file = file;

    speed = 0, health = 100;
    life = true, onGround = false, isMove = false;


    Img.loadFromFile(file);
    Texture.loadFromImage(Img);
    Sprite.setTexture(Texture);
    Sprite.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));
    Sprite.setOrigin(WIDTH / 2, HEIGHT / 2);
}

void Player::control() {
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        state = Left;
        speed = 0.1;
    }
    if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
        state = Right;
        speed = 0.1;
    }
    if(Keyboard::isKeyPressed(Keyboard::Up) && onGround){
        state = Jump;
        dy = -0.7;
        onGround = false;
    }
    if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
        state = Down;
        speed = 0.1;
    }
}

void Player::update(float time) {
    control();
    switch(state){
        case Left:
            dx = -speed;
            break; // L
        case Right:
            dx = speed;
            break; // R
        case Up:
            break; // U
        case Down:
            break; // D
        case Jump:
            break;
        case Stay:
            break;
    }

    x += dx * time;
    mapCheck(dx, 0);
    y += dy * time;
    mapCheck(0, dy);
    if(!isMove) speed = 0;
    Sprite.setPosition(x + WIDTH / 2, y + HEIGHT / 2);
    if(health <= 0) { life = false; }
    dy += time*0.0015;
}

void Player::mapCheck(float Dx, float Dy){
    Map map;
    map.createMap();

    for(int i = y / 35; i < (y + HEIGHT) / 35; i++){
        for(int j = x / 35; j < (x + WIDTH)  / 35; j++){
            if (map.al[i][j]=='B' || map.al[i][j]=='C' || map.al[i][j]=='E' || map.al[i][j]=='A' || map.al[i][j]=='D'){
                if(Dy > 0) { y = i * 35 - HEIGHT; dy = 0; onGround = true; }
                if(Dy < 0) { y = i * 35 + 35; dy = 0; }
                if(Dx > 0) { x = j * 35 - WIDTH; }
                if(Dx < 0) { x = j * 35 + 35; }
            }
        }
    }
}

float Player::getX() {
    return x;
}

float Player::getY() {
    return y;
}
