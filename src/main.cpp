#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/World.hpp"  // Подключаем класс World

int main() {
    // Создаем окно SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Simulator");

    try {
        // Создаем мир, загружая данные из файла
        World world("data/smile.txt");  // Путь к файлу с шарами
        const std::vector<Ball>& balls = world.getBalls();  // Получаем список шаров

        // Основной цикл
        while (window.isOpen()) {
            // Обработка событий (например, закрытие окна)
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // Отрисовка
            window.clear();  // Очистка окна

            // Рисуем все шары из мира
            for (const Ball& ball : balls) {
                ball.draw(window);
            }

            window.display();  // Отображение кадра
        }
    } catch (const std::exception& e) {
        // Выводим ошибку, если файл не загрузился
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}