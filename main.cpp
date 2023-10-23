//#include <iostream>

#include "main.hpp"
#include "num_enter.hpp"
#include "Ball.hpp"
#include "Button.hpp"

sf::Font font;
sf::Text txt;

sf::Texture play;
sf::Texture pause;
sf::Texture buttonpng;
sf::Texture refresh;
float g;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Astro");
    //sf::RenderWindow value_input(sf::VideoMode(150,200),"Enter value");
    font.loadFromFile("font/en.lproj/PFAgoraSlabPro Bold.ttf");
    txt.setFont(font);
    txt.setCharacterSize(25);
    txt.setFillColor(sf::Color::White);

    std::string str;
    g = 10;
    sf::CircleShape shape, shape2;
    shape.setFillColor(sf::Color::Blue);
    shape2.setFillColor(sf::Color(255, 165, 0));

    Ball fstball(1000, 500, 50);
    Ball scndball(2000, 100, 1000);

    shape.setRadius(fstball.mass / 100);
    shape2.setRadius(scndball.mass / 100);
    window.setFramerateLimit(60);


    play.loadFromFile("images/play.png");
    pause.loadFromFile("images/pause.png");
    buttonpng.loadFromFile("images/button.png");
    refresh.loadFromFile("images/refresh_data.png");
    PressButton playbutton(1255, 0, 25, 25, &play, &pause);
    playbutton.flag = true;

    Button change_cord_X1(0, 2, 25, 25, &refresh);
    Button change_cord_Y1(0, 32, 25, 25, &refresh);
    Button change_speed_X1(0, 62, 25, 25, &refresh);
    Button change_speed_Y1(0, 92, 25, 25, &refresh);
    Button change_Ac_X1(0, 122, 25, 25, &refresh);
    Button change_Ac_Y1(0, 152, 25, 25, &refresh);

    Button change_cord_X2(0, 182, 25, 25, &refresh);
    Button change_cord_Y2(0, 212, 25, 25, &refresh);
    Button change_speed_X2(0, 242, 25, 25, &refresh);
    Button change_speed_Y2(0, 272, 25, 25, &refresh);
    Button change_Ac_X2(0, 302, 25, 25, &refresh);
    Button change_Ac_Y2(0, 332, 25, 25, &refresh);

    Button change_G(0, 362, 25, 25, &refresh);

    Button change_m1(0, 392, 25, 25, &refresh);
    Button change_m2(0, 422, 25, 25, &refresh);

    sf::Vector2i mousePos;

    while (window.isOpen())
    {
        window.clear();

        mousePos = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.key.code == sf::Mouse::Left) {
                    if (playbutton.is_pressed(mousePos.x, mousePos.y)) playbutton.flag = !playbutton.flag;
                    else if (change_cord_X1.is_pressed(mousePos.x, mousePos.y)) {
                        fstball.cord_X = get_nums(1);
                    }
                    else if (change_cord_Y1.is_pressed(mousePos.x, mousePos.y)) {
                        fstball.cord_Y = get_nums(2);
                    }
                    else if (change_speed_X1.is_pressed(mousePos.x, mousePos.y)) {
                        fstball.speed_X = get_nums(3);
                    }
                    else if (change_speed_Y1.is_pressed(mousePos.x, mousePos.y)) {
                        fstball.speed_Y = get_nums(4);
                    }
                    else if (change_Ac_X1.is_pressed(mousePos.x, mousePos.y)) {
                        fstball.acceleration_X = get_nums(5);
                    }
                    else if (change_Ac_Y1.is_pressed(mousePos.x, mousePos.y)) {
                        fstball.acceleration_Y = get_nums(6);
                    }
                    else if (change_cord_X2.is_pressed(mousePos.x, mousePos.y)) {
                        scndball.cord_X = get_nums(7);
                    }
                    else if (change_cord_Y2.is_pressed(mousePos.x, mousePos.y)) {
                        scndball.cord_Y = get_nums(8);
                    }
                    else if (change_speed_X2.is_pressed(mousePos.x, mousePos.y)) {
                        scndball.speed_X = get_nums(9);
                    }
                    else if (change_speed_Y2.is_pressed(mousePos.x, mousePos.y)) {
                        scndball.speed_Y = get_nums(10);
                    }
                    else if (change_Ac_X2.is_pressed(mousePos.x, mousePos.y)) {
                        scndball.acceleration_X = get_nums(11);
                    }
                    else if (change_Ac_Y2.is_pressed(mousePos.x, mousePos.y)) {
                        scndball.acceleration_Y = get_nums(12);
                    }
                    else if (change_G.is_pressed(mousePos.x, mousePos.y)) {
                        g = get_nums(13);
                    }
                    else if (change_m1.is_pressed(mousePos.x, mousePos.y)) {
                        fstball.mass = get_nums(14);
                    }
                    else if (change_m2.is_pressed(mousePos.x, mousePos.y)) {
                        scndball.mass = get_nums(15);
                    }
                }
                break;
            }

        }

        if (playbutton.flag) window.draw(playbutton.img);
        else window.draw(playbutton.img2);

        if (scndball.mass / 100 + fstball.mass / 100 < pow(pow(scndball.cord_X - fstball.cord_X, 2) + pow(scndball.cord_Y - fstball.cord_Y, 2), 0.5) && playbutton.flag) {

            shape.setPosition(fstball.cord_X - fstball.mass / 100, fstball.cord_Y - fstball.mass / 100);
            shape2.setPosition(scndball.cord_X - scndball.mass / 100, scndball.cord_Y - scndball.mass / 100);

            fstball.tick(scndball);
            scndball.tick(fstball);
        }

        window.draw(shape);
        window.draw(shape2);

        if (!playbutton.flag) {
            str = "";
            str += "x1: " + std::to_string(fstball.cord_X);
            str += '\n';
            str += "y1: " + std::to_string(fstball.cord_Y);
            str += '\n';
            str += "speed_x1: " + std::to_string(fstball.speed_X);
            str += '\n';
            str += "speed_y1: " + std::to_string(fstball.speed_Y);
            str += '\n';
            str += "acceleration_x1: " + std::to_string(fstball.acceleration_X);
            str += '\n';
            str += "acceleration_y1: " + std::to_string(fstball.acceleration_Y);
            str += '\n';

            window.draw(change_cord_X1.img);
            window.draw(change_cord_Y1.img);
            window.draw(change_speed_X1.img);
            window.draw(change_speed_Y1.img);
            window.draw(change_Ac_X1.img);
            window.draw(change_Ac_Y1.img);

            str += "x2: " + std::to_string(scndball.cord_X);
            str += '\n';
            str += "y2: " + std::to_string(scndball.cord_Y);
            str += '\n';
            str += "speed_x2: " + std::to_string(scndball.speed_X);
            str += '\n';
            str += "speed_y2: " + std::to_string(scndball.speed_Y);
            str += '\n';
            str += "acceleration_x2: " + std::to_string(scndball.acceleration_X);
            str += '\n';
            str += "acceleration_y2: " + std::to_string(scndball.acceleration_Y);
            str += '\n';
            str += "G: " + std::to_string(g);
            str += '\n';
            str += "mass1: " + std::to_string(fstball.mass);
            str += '\n';
            str += "mass2: " + std::to_string(scndball.mass);

            window.draw(change_cord_X2.img);
            window.draw(change_cord_Y2.img);
            window.draw(change_speed_X2.img);
            window.draw(change_speed_Y2.img);
            window.draw(change_Ac_X2.img);
            window.draw(change_Ac_Y2.img);

            window.draw(change_G.img);

            window.draw(change_m1.img);
            window.draw(change_m2.img);
            txt.setPosition(28, 0);
            txt.setString(str);
            window.draw(txt);
        }


        window.display();
    }

    return 0;
}
