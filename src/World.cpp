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

    std::string line;
    while (std::getline(file, line)) {
        // Удаляем пробелы в начале и конце строки
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        // Игнорируем пустые строки и комментарии
        if (line.empty() || line[0] == '#') {
            continue;
        }

        std::istringstream iss(line);
        if (iss >> x >> y >> vx >> vy >> red >> green >> blue >> radius >> std::boolalpha >> isCollidable) {
            Point center(x, y);
            Velocity velocity(vx, vy);
            Ball ball(center, velocity, radius, /* масса = радиус */ radius, red, green, blue);
            balls.push_back(ball);
        } else {
            std::cerr << "Ошибка чтения строки: " << line << std::endl;
        }
    }
}

const std::vector<Ball>& World::getBalls() const {
    return balls;
}