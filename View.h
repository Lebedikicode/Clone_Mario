#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef SFMLDEMO_VIEW_H
#define SFMLDEMO_VIEW_H


View view;

View getCameraFollowHero(float x, float y){
    view.setCenter(x + 100, y);
    return view;
}


#endif //SFMLDEMO_VIEW_H
