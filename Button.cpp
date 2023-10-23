#include "Button.hpp"

Button::Button(int cx, int cy,int sx, int sy,sf::Texture *i){
    cord_x = cx;
    cord_y = cy;
    size_x = sx;
    size_y = sy;
    img.setTexture(*i);
    img.setPosition(cx,cy);
}
bool Button::is_pressed(int x, int y){
    return (x>cord_x && x<cord_x+size_x && y>cord_y && y<cord_y+size_y);
}
PressButton::PressButton(int cx, int cy, int sx, int sy,sf::Texture *i,sf::Texture* i2):Button(cx, cy, sx, sy, i){
    img2.setTexture(*i2);
    img2.setPosition(cx, cy);
}
