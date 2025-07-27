#include "turns.h"

void MouseControl (MouseTurn turn) { // просто для повоторов
    switch (turn) {
    case MOUSE_TURN_LEFT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_STOP) { // ВОЗМОЖНО ЛУЧШЕ СДЕЛАТЬ РЕВЕРС РАЗВОРОТ ДЛЯ ОДНОГО ИЗ КОЛЕС, 
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_STOP); // А НЕ ПРОСТО ОСТАНОВКУ
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
    case MOUSE_TURN_RIGHT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_STOP) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_STOP);
        }
    case MOUSE_TURN_AROUND:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_REVERSE) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_REVERSE);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_FORWARD);
        }
    case MOUSE_TURN_DIAGONAL_LEFT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_DIAGONAL) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_DIAGONAL);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_STOP) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_STOP);
        }
    case MOUSE_TURN_DIAGONAL_RIGHT:
        if (leftMotor.act != MOUSE_MOTOR_ACTION_STOP) {
            MotorControl(leftMotor, MOUSE_MOTOR_ACTION_STOP);
        }
        if (rightMotor.act != MOUSE_MOTOR_ACTION_DIAGONAL) {
            MotorControl(rightMotor, MOUSE_MOTOR_ACTION_DIAGONAL);
        }
    }
}