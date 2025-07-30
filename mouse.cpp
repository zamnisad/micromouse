#include "mouse.h"

void motors_forward() {
    MotorControl(leftMotor, MOUSE_MOTOR_ACTION_FORWARD);
    MotorControl(rightMotor, MOUSE_MOTOR_ACTION_FORWARD);
    delay(600);
    MotorControl(leftMotor, MOUSE_MOTOR_ACTION_STOP);
    MotorControl(rightMotor, MOUSE_MOTOR_ACTION_STOP);
}

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

void one_step(std::array<2, int> minPos) { // код в коммах может понадобитс€, Ќ≈ ”ƒјЋя“№
    /*int M = midSensor.getDistance();
    int L = leftSensor.getDistance();
    int R = rightSensor.getDistance();

    if (M - 180 > 0) {
        MotorControl(rightMotor, MOUSE_MOTOR_ACTION_FORWARD);
        MotorControl(leftMotor, MOUSE_MOTOR_ACTION_FORWARD);
        delay(600);
        MotorControl(rightMotor, MOUSE_MOTOR_ACTION_STOP);
        MotorControl(leftMotor, MOUSE_MOTOR_ACTION_STOP);
    }
    else if (L.getDistance() - 180 < 0 && R.getDistance() - 180 < 0) {
        MouseControl(MOUSE_TURN_AROUND);
    }
    else if (R - 180 < 0) {
        MouseControl(MOUSE_TURN_LEFT);
    }
    else {
        MouseControl(MOUSE_TURN_RIGHT);
    }*/
    if (minPos[0] < currentPos[0]) {
        motors_forward();
    }
    else if (minPos[1] < currentPos[1]) {
        MouseControl(MOUSE_TURN_LEFT);
        motors_forward();
    }
    else if (minPos[1] > currentPos[1]) {
        MouseControl(MOUSE_TURN_RIGHT);
        motors_forward();
    }
    else {
        MouseControl(MOUSE_TURN_AROUND);
        motors_forward();
    }
}

void analyze_maze() {
    while (curMode == MOUSE_MODE_ANALYZE && currentPos != endPos) {
        update_walls(currentPos[0], currentPos[1]);
        update_maze();

        int minPos[2] = get_min_pos();

        one_step(minPos);

        currentPos[0] = minPos[0];
        currentPos[1] = minPos[1];
    }
}

void pass_maze() {
    /*
        тут просто можно сделать очередь, внутри которой будут ходы дл€ мыши
        при этом пон€ть, как сделать так, что бы она не останавливалась
    */
}