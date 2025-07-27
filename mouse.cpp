#include "mouse.h"

void update_walls() {
    if (rightSensor.getDistance() <= lenToSideWall) {
        walls[currentPos[0]][currentPos[1]] |= WALL_RIGHT;
    }
    if (leftSensor.getDistance() <= lenToSideWall) {
        walls[currentPos[0]][currentPos[1]] |= WALL_LEFT;
    }
    if (midSensor.getDistance() <= lenToMidWall) {
        walls[currentPos[0]][currentPos[1]] |= WALL_UP;
    }
}

void one_step() {
    if (midSensor.getDistance() - 180 > lenToMidWall) {
        MotorControl
    }
}

void analyze_maze();

void pass_maze();