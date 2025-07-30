#ifndef MOUSE_H
#define MOUSE_H

#include "maze.h"

void motors_forward();

void update_walls();

void one_step(std::array<2, int> minPos);

void analyze_maze();

void pass_maze();

#endif