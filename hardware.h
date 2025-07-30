#ifndef HARDWARE_H
#define HARDWARE_H

#include <stdint.h>
//#include <arduino.h>
#include <"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\Arduino.h"> // понять каким образом вообще здесь импортировать Arduino.h

typedef enum { // для определения типа поворотов
    MOUSE_TURN_RIGHT,
    MOUSE_TURN_LEFT,
    MOUSE_TURN_AROUND,
    MOUSE_TURN_DIAGONAL_RIGHT,
    MOUSE_TURN_DIAGONAL_LEFT
} MouseTurn;

typedef enum { // для опредления типов действий мыши
    MOUSE_MODE_ANALYZE,
    MOUSE_MODE_LINE_FOLLOW
} MouseMode;

typedef enum { // для определения состояния мыши
    MOUSE_STATUS_START,
    MOUSE_STATUS_ACTION,
    MOUSE_STATUS_END
} MouseStatus;

// typedef enum { // текущее положение относительно начальной позиции (направление)
//     MOUSE_DIRECTION_UP,
//     MOUSE_DIRECTION_DOWN,
//     MOUSE_DIRECTION_LEFT,
//     MOUSE_DIRECTION_RIGHT,
//     MOUSE_DIRECTION_LUDIAGONAL,
//     MOUSE_DIRECTION_LDDIAGONAL,
//     MOUSE_DIRECTION_RUDIAGONAL,
//     MOUSE_DIRECTION_RDDIAGONAL
// } MouseDirection;

typedef enum { // для выбора мотора
    MOUSE_MOTOR_LEFT,
    MOUSE_MOTOR_RIGHT
} MouseMotor;

typedef enum { // для выбора действий мотора
    MOUSE_MOTOR_ACTION_FORWARD,
    MOUSE_MOTOR_ACTION_REVERSE,
    MOUSE_MOTOR_ACTION_STOP
} MouseMotorAction;

typedef enum { // для выбора положения сенсора
    MOUSE_SENSOR_RIGHT,
    MOUSE_SENSOR_LEFT,
    MOUSE_SENSOR_MID
} MouseSensor;

class Sensor { // класс для лазеров и датчиков
public:
    MouseSensor ms;
    int sharpPin;

    Sensor(MouseSensor sens, int pin) {
        this->ms = sens;
        this->sharpPin = pin;
    }

    int getDistance() {
        return analogRead(this->sharpPin);
    }
};

class Motor { // класс для моторов
public:
    MouseMotorAction act = MOUSE_MOTOR_ACTION_STOP;
    int first; // pin 1
    int second; // pin 2

    Motor(int f, int s) {
        this->first = f;
        this->second = s;
    }
};

extern MouseMode curMode;

extern Motor rightMotor;
extern Motor leftMotor;

extern Sensor rightSensor;
extern Sensor leftSensor;
extern Sensor midSensor;

#endif