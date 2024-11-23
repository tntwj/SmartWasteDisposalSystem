#ifndef __DEFINES__
#define __DEFINES__

// Servo pulse width values
#define BACK_DOOR_OPEN_WIDTH 750
#define DOOR_CLOSED_WIDTH 1500
#define FRONT_DOOR_OPEN_WIDTH 2250

#define TEMP_THRESHOLD 40
#define MAX_WASTE_DISTANCE 0.5f     // Max WasteDetector range, half a meter
#define MIN_WASTE_DISTANCE 0.05f    // Min WasteDetector range, 5 cm

// Timings in milliseconds
#define SCHEDULE_PERIOD 100
#define DETECTING_MOTION_PERIOD 200
#define MEASURE_LEVEL_PERIOD 200
#define MEASURE_TEMPERATURE_PERIOD 200
#define WASTE_DISPOSAL_TASK_PERIOD 300
#define RECEIVE_MSG_PERIOD 200
#define SEND_MSG_PERIOD 200

// State specific timings
#define ENTERING_WASTE_WINDOW 5000
#define WASTE_RECEPTION_WINDOW 2000
#define SLEEP_TIMEOUT_WINDOW 5000
#define EMPTYING_PROCESS_WINDOW 2000

#endif
