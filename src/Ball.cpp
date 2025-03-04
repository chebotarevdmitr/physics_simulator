#include "../include/Ball.hpp"

// Конструктор
Ball::Ball(const Point& center, const Velocity& velocity, double radius, double mass, int red, int green, int blue)
    : center(center), velocity(velocity), radius(radius), mass(mass), red(red), green(green), blue(blue) {}

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
    center.x += velocity.vx * deltaTime;
    center.y += velocity.vy * deltaTime;

    // Ограничение границ окна (800x600)
    if (center.x - radius < 0 || center.x + radius > 800) {
        velocity.vx = -velocity.vx;
    }
    if (center.y - radius < 0 || center.y + radius > 600) {
        velocity.vy = -velocity.vy;
    }
}

// Отрисовка шара в окне SFML
void Ball::draw(sf::RenderWindow& window) const {
    sf::CircleShape circle(radius);
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(sf::Color(red, green, blue));
    window.draw(circle);
}