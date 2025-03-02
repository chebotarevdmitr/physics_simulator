#include <SFML/Graphics.hpp>
#include "../include/Ball.hpp"

int main() {
    // Создаем окно размером 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Simulator");

    // Создаем шар: центр (400, 300), скорость (0, 0), радиус 20, масса 1
    Ball ball(Point(400, 300), Velocity(0, 0), 20, 1);

    // Основной цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Закрыть окно при нажатии на крестик
            }
        }

        window.clear();        // Очистка окна
        ball.draw(window);     // Отрисовка шара
        window.display();      // Отображение содержимого
    }

    return 0;
}