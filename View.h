#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

#ifndef SFMLDEMO_VIEW_H
#define SFMLDEMO_VIEW_H


View view;

View getCameraFollowHero(float x, float y){
    float tempX = x, tempY = y;
//    std::cout << "X = " << x << std::endl;
//    std::cout << "Y = " << y << std::endl;
    if (x < 455) tempX = 455;
    if (x > 7840-420) tempX = 7840-420;
    if (y < 300) tempY = 300;
    if (y > 298) tempY = 298;

    view.setCenter(tempX, tempY);  // 400 218
    return view;
}


#endif //SFMLDEMO_VIEW_H
