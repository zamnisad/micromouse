#include "turns.h"

void MouseControl (MouseTurn turn) { // просто для повоторов
    switch (turn) {
    case MOUSE_TURN_LEFT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_REVERSE) { // ВОЗМОЖНО ЛУЧШЕ СДЕЛАТЬ РЕВЕРС РАЗВОРОТ ДЛЯ ОДНОГО ИЗ КОЛЕС, 
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_REVERSE); // А НЕ ПРОСТО ОСТАНОВКУ
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
        delay(500);
        break;
    case MOUSE_TURN_RIGHT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_REVERSE) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_REVERSE);
        }
        delay(500);
        break;
    case MOUSE_TURN_AROUND:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_REVERSE) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_REVERSE);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
        delay(1000);
        break;
    case MOUSE_TURN_DIAGONAL_LEFT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_REVERSE) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_REVERSE);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
        delay(250);
        break;
    case MOUSE_TURN_DIAGONAL_RIGHT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_REVERSE) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_REVERSE);
        }
        delay(250);
        break;
    }
    if (curMode == MOUSE_MODE_ANALYZE) {
        MotorControl(leftMotor, MOUSE_MOTOR_ACTION_STOP);
        MotorControl(rightMotor, MOUSE_MOTOR_ACTION_STOP);
    }
}

/*
    1) отслеживать по датчикам когда расстояние меняется
    2) вращение по времени (пока что так)
    3) 
*/