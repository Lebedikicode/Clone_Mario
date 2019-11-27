#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace sf;

#ifndef SFMLDEMO_MAP_H
#define SFMLDEMO_MAP_H

const int height = 17, width = 225;

class Map{
public:

    String al[height][width];
    Texture tileSet;
    Texture tileSet2;
    Texture tileSet3;
    Texture tileSet4;
    Texture tileSet5;
    Texture tileSet6;
    Texture tileSet7;

    void createMap(){
        std::ifstream file;
        file.open("/Users/n1kta/CLionProjects/SFMLDemo/map.txt");

        if (!file) std::cout << "Не правельный путь к файлу!";
        for (int r = 0; r < height; r++)
        {
            for (int t = 0; t < width; t++)
            {
                char a;
                file >> a;
                al[r][t] = a;
            }
        }

        file.close();
    }
};


#endif //SFMLDEMO_MAP_H
