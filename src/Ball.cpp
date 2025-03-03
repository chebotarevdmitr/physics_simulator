#include "../include/Ball.hpp"

// Конструктор: инициализация полей через список инициализации
Ball::Ball(const Point& center, const Velocity& velocity, double radius, double mass)
    : center(center), velocity(velocity), radius(radius), mass(mass) {}

// Установка новой скорости
void Ball::setVelocity(const Velocity& velocity) {
    this->velocity = velocity;  // this->velocity — поле класса, velocity — параметр
}

// Получение текущей скорости
Velocity Ball::getVelocity() const {
    return velocity;
}

// Установка новой позиции
void Ball::setCenter(const Point& center) {
    this->center = center;
}

// Получение текущей позиции
Point Ball::getCenter() const {
    return center;
}

// Получение радиуса
double Ball::getRadius() const {
    return radius;
}

// Получение массы
double Ball::getMass() const {
    return mass;
}

// Отрисовка шара в окне SFML
void Ball::draw(sf::RenderWindow& window) const {
    sf::CircleShape circle(radius);  // Создаем круг с заданным радиусом
    // Позиция круга: центр шара минус радиус (чтобы круг был отцентрован)
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(sf::Color::Red);  // Цвет шара (красный)
    window.draw(circle);  // Рисуем круг в окне
}
 // Обновление позиции шара
void Ball::update(double deltaTime) {
   center.x += velocity.vx * deltaTime;  // Обновляем координату X
   center.y += velocity.vy * deltaTime;  // Обновляем координату Y
} 