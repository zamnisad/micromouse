#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <queue>
#include <cmath>
#include <cstdint>

#include "turns.cpp"

extern const int mazeSize = 16;

extern const int startPos[2] = {0, 0};
extern int currentPos[2] = {0, 0};
extern const int endPos[2] = {8, 8};

extern int maze[mazeSize][mazeSize];

extern uint8_t walls[mazeSize][mazeSize];

// при желании заменить на север-юг-запад-восток
extern const uint8_t WALL_UP;
extern const uint8_t WALL_DOWN;
extern const uint8_t WALL_RIGHT;
extern const uint8_t WALL_LEFT;

extern const int lenToMidWall;
extern const int lenToSideWall;

void init_maze();

void init_walls();

bool in_bounds(int x, int y);

void update_maze(int posx, int posy);

void print_maze_distances();

void print_maze_human_readable();

#endif