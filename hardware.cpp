#include "hardware.h"

MouseMode curMode = MOUSE_MODE_ANALYZE;

Motor rightMotor(5, 6);
Motor leftMotor(9, 10);

Sensor rightSensor(MOUSE_SENSOR_RIGHT);
Sensor leftSensor(MOUSE_SENSOR_LEFT);
Sensor midSensor(MOUSE_SENSOR_MID);