#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef SFMLDEMO_ENEMY_H
#define SFMLDEMO_ENEMY_H

class Enemy{
public:
    float x, y;
    float WIDTH, HEIGHT, dx, dy, speed = 0;//  // координаты // скорость с которой двигается персонаж
    int health;
    float moveTimer;
    bool life;
    std::string file; // путь к изображению
    Image Img;
    Texture Texture;
    Sprite Sprite;

    Enemy(float x, float y, float WIDTH, float HEIGHT, std::string file){
        this->x = x;
        this->y = y;
        this->WIDTH = WIDTH;
        this->HEIGHT = HEIGHT;
        this->file = file;

        dx = 0.1;
        moveTimer = 0;

        Img.loadFromFile(file);
        Texture.loadFromImage(Img);
        Sprite.setTexture(Texture);
        Sprite.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));
        Sprite.setPosition(x, y);
    }

    void update(float time){
        x += dx * time;
        moveTimer += time;
        if (moveTimer > 1000) { dx*= -1; moveTimer = 0; }
        Sprite.setPosition(x+WIDTH/2, y+HEIGHT/2);
        mapCheck();
    }

    void mapCheck(){
        Map map;
        map.createMap();

        for(int i = y / 35; i < (y + HEIGHT) / 35; i++){
            for(int j = x / 35; j < (x + WIDTH)  / 35; j++){
                if (map.al[i][j]=='B' || map.al[i][j]=='C' || map.al[i][j]=='E' || map.al[i][j]=='A' || map.al[i][j]=='D'){
                    if(dy > 0) { y = i * 35 - HEIGHT; }
                    if(dy < 0) { y = i * 35 + 35; }
                    if(dx > 0) { x = j * 35 - WIDTH; }
                    if(dx < 0) { x = j * 35 + 35; }
                }
            }
        }
    }

};

#endif //SFMLDEMO_ENEMY_H
