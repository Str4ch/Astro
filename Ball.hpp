#ifndef Ball_hpp
#define Ball_hpp

#include "main.hpp"

class Ball{
public:
    float mass;
    float cord_X;
    float cord_Y;
    float speed_X;
    float speed_Y;
    float acceleration_X;
    float acceleration_Y;
    void tick(Ball second_ball);
    Ball();
    Ball(float m);
    Ball(float m,float cx,float cy);
    Ball(float m,float cx,float cy,float sx, float sy);
    Ball(float m,float cx,float cy,float sx, float sy,float ax, float ay);
    
};
#endif
