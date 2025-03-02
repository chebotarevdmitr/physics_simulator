#ifndef POINT_HPP  // Гарантирует, что файл включится только один раз
#define POINT_HPP

struct Point {
    double x;  // Координата X
    double y;  // Координата Y

    // Конструктор с параметрами (по умолчанию x=0, y=0)
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

#endif