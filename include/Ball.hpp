#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
private:
    Point center;
    Velocity velocity;
    double radius;
    double mass;
    int red, green, blue; // Цвет шара (RGB)

public:
    // Конструктор: принимает центр, скорость, радиус, массу и цвет
    Ball(const Point& center, const Velocity& velocity, double radius, double mass, int red, int green, int blue);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;

    void setCenter(const Point& center);
    Point getCenter() const;

    double getRadius() const;
    double getMass() const;

    // Метод для обновления позиции шара
    void update(double deltaTime);

    // Метод для отрисовки шара
    void draw(sf::RenderWindow& window) const;
};

#endif