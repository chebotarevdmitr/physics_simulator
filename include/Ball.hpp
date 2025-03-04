#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
private:
    Point center;    // Текущий центр шара
    Velocity velocity;  // Скорость шара
    double radius;   // Радиус
    double mass;     // Масса
    int red, green, blue; // Цвет шара (RGB)
    Point target;    // Целевая позиция

public:
    // Конструктор: принимает центр, скорость, радиус, массу, цвет и целевую позицию
    Ball(const Point& center, const Velocity& velocity, double radius, double mass, int red, int green, int blue, const Point& target);

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

    // Проверка, достиг ли шар цели
    bool isAtTarget() const;
};

#endif