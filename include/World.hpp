#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <fstream>
#include "Ball.hpp"

class World {
private:
    std::vector<Ball> balls;  // Список шаров в мире

public:
    // Конструктор: загружает данные из файла
    World(const std::string& filePath);

    // Метод для доступа к шарам
    const std::vector<Ball>& getBalls() const;
};

#endif