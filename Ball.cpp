#include "Ball.hpp"

#include <cmath>

float get_angle(float cord_x1,float cord_y1,float cord_x2,float cord_y2){
    float X = (cord_x2-cord_x1);
    float Y = (cord_y2-cord_y1);
    float lena = sqrt(pow(X,2)+pow(Y,2));
    if(Y>0){
        return acos(X/lena);
    }
    return -acos(X/lena);
}

float get_force(float cord_X1,float cord_Y1,float mass1,float cord_X2,float cord_Y2, float mass2){;
    float r_sq = pow((cord_X1-cord_X2),2)+pow((cord_Y1-cord_Y2),2);
    float fforce = (g*mass1*mass2)/r_sq;
    return fforce;
}


Ball::Ball(){
    mass = 100;
    cord_X = 0;
    cord_Y = 0;
    speed_X = 0;
    speed_Y = 0;
    acceleration_X = 0;
    acceleration_Y = 0;
}

Ball::Ball(float m){
    mass = m;
    cord_X = 0;
    cord_Y = 0;
    speed_X = 0;
    speed_Y = 0;
    acceleration_X = 0;
    acceleration_Y = 0;
}

Ball::Ball(float m,float cx,float cy){
    mass = m;
    cord_X = cx;
    cord_Y = cy;
    speed_X = 0;
    speed_Y = 0;
    acceleration_X = 0;
    acceleration_Y = 0;
}

Ball::Ball(float m,float cx,float cy,float sx, float sy){
    mass = m;
    cord_X = cx;
    cord_Y = cy;
    speed_X = sx;
    speed_Y = sy;
    acceleration_X = 0;
    acceleration_Y = 0;
}

Ball::Ball(float m,float cx,float cy,float sx, float sy,float ax, float ay){
    mass = m;
    cord_X = cx;
    cord_Y = cy;
    speed_X = sx;
    speed_Y = sy;
    acceleration_X = ax;
    acceleration_Y = ay;
}

void Ball::tick(Ball secondball){
    float angle = get_angle(cord_X, cord_Y, secondball.cord_X, secondball.cord_Y);
    float force = get_force(cord_X,cord_Y,mass,secondball.cord_X,secondball.cord_Y,secondball.mass);
    
    acceleration_X = (force/mass)*cos(angle);
    acceleration_Y = (force/mass)*sin(angle);
    
    cord_X +=(speed_X/60);
    cord_Y +=(speed_Y/60);
    speed_X += (acceleration_X/60);
    speed_Y += (acceleration_Y/60);
}
