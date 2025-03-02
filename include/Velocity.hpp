#ifndef VELOCITY_HPP
#define VELOCITY_HPP

struct Velocity {
    double vx;  // Скорость по оси X
    double vy;  // Скорость по оси Y

    // Конструктор с параметрами (по умолчанию vx=0, vy=0)
    Velocity(double vx = 0, double vy = 0) : vx(vx), vy(vy) {}
};

#endif