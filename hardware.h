#ifndef HARDWARE_H
#define HARDWARE_H

#include <stdint.h>


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
    MOUSE_MOTOR_ACTION_STOP,
    MOUSE_MOTOR_ACTION_DIAGONAL
} MouseMotorAction;

typedef enum { // для выбора положения сенсора
    MOUSE_SENSOR_RIGHT,
    MOUSE_SENSOR_LEFT,
    MOUSE_SENSOR_MID
} MouseSensor;

class Sensor { // класс для лазеров и датчиков
public:
    MouseSensor ms;

    Sensor(MouseSensor sens) {
        this->ms = sens;
    }

    int getDistance() {
        // КОД ИЗ АРДУИНО ДЛЯ ПОИСКА РАССТОЯНИЯ

        return 0;
    }
};

class Motor { // класс для моторов
public:
    MouseMotorAction act = MOUSE_MOTOR_ACTION_STOP;
    const int first = 1; // pin 1
    const int second = 2; // pin 2
};

extern Motor rightMotor;
extern Motor leftMotor;

extern Sensor rightSensor;
extern Sensor leftSensor;
extern Sensor midSensor;

#endif