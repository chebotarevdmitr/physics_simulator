cmake_minimum_required(VERSION 3.10)
project(PhysicsSimulator)

set(CMAKE_CXX_STANDARD 17)

# Указываем исходные файлы
set(SOURCE_FILES 
    src/main.cpp 
    src/Ball.cpp 
    src/World.cpp  # Если есть World.cpp
)

# Находим SFML через pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-graphics sfml-window sfml-system)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Добавляем пути к заголовочным файлам
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Подключаем библиотеки SFML
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})