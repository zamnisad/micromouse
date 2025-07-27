#include "motorControl.h"


void MotorControl(Motor motor, MouseMotorAction action) {
    switch (action) {
    case MOUSE_MOTOR_ACTION_FORWARD:
        if (motor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            // КОД ДЛЯ ДВИЖЕНИЯ ПРЯМО С УЧЕТОМ motor.first и motor.second
            /*
            DigitalWrite(motor.first, HIGH);
            DigitalWrite(motor.second, LOW);
            */
        }
    case MOUSE_MOTOR_ACTION_DIAGONAL:
        if (motor.act != MOUSE_MOTOR_ACTION_DIAGONAL) {
            // КОД ДЛЯ ДВИЖЕНИЯ ПО ДИАГОНАЛИ С УЧЕТОМ motor.first и motor.second
        }
    case MOUSE_MOTOR_ACTION_REVERSE:
        if (motor.act != MOUSE_MOTOR_ACTION_REVERSE) {
            // КОД ДЛЯ ДВИЖЕНИЯ НАЗАД С УЧЕТОМ motor.first и motor.second
        }
    case MOUSE_MOTOR_ACTION_STOP:
        if (motor.act != MOUSE_MOTOR_ACTION_STOP) {
            // КОД ДЛЯ ОСТАНОВКИ С УЧЕТОМ motor.first и motor.second
        }
    }
}