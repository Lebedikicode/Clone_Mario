#include "Player.h"
#include "Player.h"
#include <fstream>

Player::Player(float x, float y, float WIDTH, float HEIGHT, std::string file){
    this->x = x;
    this->y = y;
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    this->file = file;

    life = true, onGround = false, isSelected = false, isMove = false;


    Img.loadFromFile(file);
    Texture.loadFromImage(Img);
    Sprite.setTexture(Texture);
    Sprite.setTextureRect(IntRect(0, 0, WIDTH, HEIGHT));
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
    mapCheck();
}

void Player::mapCheck(){
    const int height = 17, width = 225;
    String al[height][width];

    std::ifstream file;
    file.open("/Users/n1kta/CLionProjects/SFMLDemo/map.txt");

    for (int r = 0; r < height; r++)
    {
        for (int t = 0; t < width; t++)
        {
            char a;
            file >> a;
            al[r][t] = a;
        }
    }

    for(int i = y / 35; i < (y + HEIGHT) / 35; i++){
        for(int j = x / 35; j < (x + WIDTH)  / 35; j++){
            if (al[i][j] == 'B'){
                if(dy > 0)
                    y = i * 35 - HEIGHT;
                if(dy < 0)
                    y = i * 35 + 35;
                if(dx > 0)
                    x = j * 35 - HEIGHT;
                if(dx < 0)
                    x = j * 35 + 35;
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
