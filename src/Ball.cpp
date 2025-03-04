#include "../include/Ball.hpp"
#include <cmath>

// Конструктор с целевой позицией
Ball::Ball(const Point& center, const Velocity& velocity, double radius, double mass, int red, int green, int blue, const Point& target)
    : center(center), velocity(velocity), radius(radius), mass(mass), red(red), green(green), blue(blue), target(target) {}

void Ball::setVelocity(const Velocity& velocity) {
    this->velocity = velocity;
}

Velocity Ball::getVelocity() const {
    return velocity;
}

void Ball::setCenter(const Point& center) {
    this->center = center;
}

Point Ball::getCenter() const {
    return center;
}

double Ball::getRadius() const {
    return radius;
}

double Ball::getMass() const {
    return mass;
}

// Обновление позиции шара на основе скорости и времени
void Ball::update(double deltaTime) {
   if (!isAtTarget()) {
       // Вычисляем направление к цели
       double dx = target.x - center.x;
       double dy = target.y - center.y;
       double distance = std::sqrt(dx * dx + dy * dy);

       // Если близко к цели, останавливаемся
       if (distance < 1.0) {
           velocity.vx = 0;
           velocity.vy = 0;
       } else {
           // Нормализуем направление и умножаем на скорость
           velocity.vx = dx / distance * 3.0; // Увеличиваем скорость (умножаем на 2.0)
           velocity.vy = dy / distance * 3.0;
       }

       // Обновляем позицию
       center.x += velocity.vx * deltaTime;
       center.y += velocity.vy * deltaTime;
   }
}

// Отрисовка шара в окне SFML
void Ball::draw(sf::RenderWindow& window) const {
    sf::CircleShape circle(radius);
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(sf::Color(red, green, blue));
    window.draw(circle);
}

// Проверка, достиг ли шар цели
bool Ball::isAtTarget() const {
    double dx = target.x - center.x;
    double dy = target.y - center.y;
    double distance = std::sqrt(dx * dx + dy * dy);
    return distance < 1.0; // Если расстояние меньше 1 пикселя, считаем, что цель достигнута
}