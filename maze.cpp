#include "maze.h"


const int mazeSize = 16;

const int startPos[2] = {0, 0};
int currentPos[2] = {0, 0};
const int endPos[2] = {8, 8};

int maze[mazeSize][mazeSize];

uint8_t walls[mazeSize][mazeSize];

const uint8_t WALL_UP = 0b0001;
const uint8_t WALL_DOWN  = 0b0010;
const uint8_t WALL_RIGHT = 0b0100;
const uint8_t WALL_LEFT  = 0b1000;

const int lenToMidWall = 120;
const int lenToSideWall = 80;

void init_maze() { // заполняет начальный лабиринт
    const int center_x = mazeSize / 2;
    const int center_y = mazeSize / 2;

    for (int y = 0; y < mazeSize; y++) {
        for (int x = 0; x < mazeSize; x++) {
            maze[y][x] = 999;
            walls[y][x] = 0b0000;
        }
    }
}

void init_walls() {
    // Внешние стены
    for (int i = 0; i < mazeSize; i++) {
        walls[0][i] |= WALL_UP;
        walls[mazeSize - 1][i] |= WALL_DOWN;
        walls[i][0] |= WALL_LEFT;
        walls[i][mazeSize - 1] |= WALL_RIGHT;
    }

    // Сложные внутренние стены (сгенерировано gpt просто для первого теста)
    // Горизонтальные стены (по 4 строкам)
    /* for (int x = 2; x <= 13; x++) {
        walls[3][x] |= WALL_DOWN;
        walls[4][x] |= WALL_UP;
    }
    for (int x = 1; x <= 10; x++) {
        walls[7][x] |= WALL_DOWN;
        walls[8][x] |= WALL_UP;
    }
    for (int x = 5; x <= 14; x++) {
        walls[11][x] |= WALL_DOWN;
        walls[12][x] |= WALL_UP;
    }

    // Вертикальные стены
    for (int y = 2; y <= 6; y++) {
        walls[y][5] |= WALL_RIGHT;
        walls[y][6] |= WALL_LEFT;
    }
    for (int y = 9; y <= 13; y++) {
        walls[y][10] |= WALL_RIGHT;
        walls[y][11] |= WALL_LEFT;
    }

    // Дополнительные перегородки
    for (int x = 7; x <= 9; x++) {
        walls[5][x] |= WALL_DOWN;
        walls[6][x] |= WALL_UP;
    }
    for (int y = 0; y <= 2; y++) {
        walls[y][12] |= WALL_RIGHT;
        walls[y][13] |= WALL_LEFT;
    }*/  
}

bool in_bounds(int x, int y) {
    return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize;
}

void update_maze(int posx, int posy) {
    std::queue<std::pair<int, int>> q;
    q.push({posx, posy});
    maze[posx][posy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        int current_dist = maze[y][x];

        // вверх
        if (!(walls[y][x] & WALL_UP) && in_bounds(x, y - 1)) {
            if (maze[y - 1][x] > current_dist + 1) {
                maze[y - 1][x] = current_dist + 1;
                q.push({x, y - 1});
            }
        }

        // вниз
        if (!(walls[y][x] & WALL_DOWN) && in_bounds(x, y + 1)) {
            if (maze[y + 1][x] > current_dist + 1) {
                maze[y + 1][x] = current_dist + 1;
                q.push({x, y + 1});
            }
        }

        // вправо
        if (!(walls[y][x] & WALL_RIGHT) && in_bounds(x + 1, y)) {
            if (maze[y][x + 1] > current_dist + 1) {
                maze[y][x + 1] = current_dist + 1;
                q.push({x + 1, y});
            }
        }

        // влево
        if (!(walls[y][x] & WALL_LEFT) && in_bounds(x - 1, y)) {
            if (maze[y][x - 1] > current_dist + 1) {
                maze[y][x - 1] = current_dist + 1;
                q.push({x - 1, y});
            }
        }
    }
}

void print_maze_distances() {
    std::cout << "Maze distances:\n";
    for (int y = 0; y < mazeSize; y++) {
        for (int x = 0; x < mazeSize; x++) {
            if (maze[y][x] == 999)
                std::cout << "## ";
            else
                std::cout << (maze[y][x] < 10 ? "0" : "") << maze[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

void print_maze_human_readable() { // СГЕНЕРИРОВАНО CHAT GPT ДЛЯ КРАСИВОЙ ОТРИСОВКИ (РЯЛЬНО)
    // Верхняя граница
    for (int x = 0; x < mazeSize; x++) {
        std::cout << "+---";
    }
    std::cout << "+\n";

    for (int y = 0; y < mazeSize; y++) {
        // Левая вертикальная стена и ячейки
        for (int x = 0; x < mazeSize; x++) {
            if (x == 0)
                std::cout << (walls[y][x] & WALL_LEFT ? "|" : " ");
            
            // Вывод расстояния или пробела (по желанию можно заменить на другой символ)
            if (maze[y][x] == 999)
                std::cout << "   ";  // закрытая клетка
            else if (maze[y][x] < 10)
                std::cout << " " << maze[y][x] << " ";
            else
                std::cout << maze[y][x] << " ";

            // Правая стена клетки
            if (walls[y][x] & WALL_RIGHT)
                std::cout << "|";
            else
                std::cout << " ";
        }
        std::cout << "\n";

        // Нижняя стена ячеек
        for (int x = 0; x < mazeSize; x++) {
            std::cout << "+";
            if (walls[y][x] & WALL_DOWN)
                std::cout << "---";
            else
                std::cout << "   ";
        }
        std::cout << "+\n";
    }
}