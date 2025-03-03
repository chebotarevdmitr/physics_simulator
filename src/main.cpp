#include <SFML/Graphics.hpp>  // Для работы с графикой SFML
#include "../include/World.hpp"          // Подключаем класс World
#include <iostream>           // Для вывода ошибок в консоль

int main() {
    // Создаем окно SFML размером 800x600 с заголовком "Physics Simulator"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Simulator");

    try {
        // Создаем мир, загружая данные из файла "data/smile.txt"
        World world("data/smile.txt");
        
        // Получаем список шаров из мира (константная ссылка для безопасности)
        const std::vector<Ball>& balls = world.getBalls();

        // Создаем таймер для измерения времени между кадрами
        sf::Clock clock;

        // Основной цикл программы
        while (window.isOpen()) {
            // Обработка событий (например, закрытие окна)
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();  // Закрываем окно
                }
            }

            // Вычисляем время, прошедшее с предыдущего кадра (в секундах)
            float deltaTime = clock.restart().asSeconds();

            // Обновляем позиции всех шаров
            // Используем const_cast, чтобы снять константность с balls
            for (Ball& ball : const_cast<std::vector<Ball>&>(balls)) {
                ball.update(deltaTime);  // Обновляем позицию шара
            }

            // Отрисовка
            window.clear();  // Очищаем окно

            // Рисуем все шары
            for (const Ball& ball : balls) {
                ball.draw(window);
            }

            window.display();  // Отображаем кадр
        }
    } catch (const std::exception& e) {
        // Выводим ошибку, если что-то пошло не так
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;  // Возвращаем код ошибки
    }

    return 0;  // Успешное завершение
}