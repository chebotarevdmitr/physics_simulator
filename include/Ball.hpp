#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>  // Для отрисовки
#include "Point.hpp"          // Для координат
#include "Velocity.hpp"       // Для скорости

class Ball {
private:
    Point center;    // Центр шара
    Velocity velocity;  // Скорость шара
    double radius;   // Радиус
    double mass;     // Масса

public:
    // Конструктор: принимает центр, скорость, радиус и массу
    Ball(const Point& center, const Velocity& velocity, double radius, double mass);

    // Геттеры и сеттеры для скорости
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;

    // Геттеры и сеттеры для позиции
    void setCenter(const Point& center);
    Point getCenter() const;

    // Геттеры для радиуса и массы (сеттеры не нужны, так как они не меняются)
    double getRadius() const;
    double getMass() const;

    // Метод отрисовки шара
    void draw(sf::RenderWindow& window) const;

 // Новый метод: обновление позиции шара
 void update(double deltaTime);
};

#endif