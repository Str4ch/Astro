#ifndef Button_hpp
#define Button_hpp
#include <SFML/Graphics.hpp>

class Button{
public:
    int cord_x;
    int cord_y;
    int size_x;
    int size_y;
    sf::Sprite img;
    bool is_pressed(int x,int y);
    Button(int cx, int cy, int sx, int sy,sf::Texture *i);
    
};

class PressButton: public Button{
public:
    bool flag;
    sf::Sprite img2;
    PressButton(int cx, int cy, int sx, int sy,sf::Texture * i,sf::Texture* i2);
};
#endif
