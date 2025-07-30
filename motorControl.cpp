#include "motorControl.h"


void MotorControl(Motor motor, MouseMotorAction action) {
    switch (action) {
    case MOUSE_MOTOR_ACTION_FORWARD:
        if (motor.act != MOUSE_MOTOR_ACTION_FORWARD) {
            // КОД ДЛЯ ДВИЖЕНИЯ ПРЯМО С УЧЕТОМ motor.first и motor.second
            digitalWrite(motor.first, HIGH);
            digitalWrite(motor.second, LOW);
        }
        break;
    case MOUSE_MOTOR_ACTION_REVERSE:
        if (motor.act != MOUSE_MOTOR_ACTION_REVERSE) {
            digitalWrite(motor.second, HIGH);
            digitalWrite(motor.first, LOW);
        }
        break;
    case MOUSE_MOTOR_ACTION_STOP:
        if (motor.act != MOUSE_MOTOR_ACTION_STOP) {
            digitalWrite(motor.first, LOW);
            digitalWrite(motor.second, LOW);
        }
        break;
    }
}