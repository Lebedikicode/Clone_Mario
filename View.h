#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef SFMLDEMO_VIEW_H
#define SFMLDEMO_VIEW_H


View view;

View getCameraFollowHero(float x, float y){
    view.setCenter(x, y);  // 400 218
    return view;
}


#endif //SFMLDEMO_VIEW_H
