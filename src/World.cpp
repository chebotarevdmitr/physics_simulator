#include "../include/World.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

World::World(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filePath);
    }

    double x, y, vx, vy, red, green, blue, radius;
    bool isCollidable;

    // Читаем файл по строкам
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (iss >> x >> y >> vx >> vy >> red >> green >> blue >> radius >> std::boolalpha >> isCollidable) {
            // Создаем объекты Point, Velocity и Ball
            Point center(x, y);
            Velocity velocity(vx, vy);
            Ball ball(center, velocity, radius, /* масса = радиус */ radius, red, green, blue);

            // Добавляем шар в список
            balls.push_back(ball);
        } else {
            std::cerr << "Ошибка чтения строки: " << line << std::endl;
        }
    }
}

const std::vector<Ball>& World::getBalls() const {
    return balls;
}