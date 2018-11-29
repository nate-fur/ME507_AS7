//
// Created by nate on 11/8/18.
//

#include "ME507.h"
//#include <iostream.h>
#include "include/rs232int.h"
#include "include/Adafruit_BNO055.h"
#include "ATMega/communication_data.h"
#include "ATMega/imu_task.h"
#include "ATMega/fifth_wheel.h"
#include "ATMega/gear_shifter.h"
#include "ATMega/motor_driver.h"
#include "ATMega/steer_servo.h"
#include "ATMega/wheel_speed.h"
#include "ATMega/Servo.h"
#include "ATMega/mega_comm_task.h"

using namespace std;
#define nullptr NULL
const uint8_t N_MULTI_TASKS = 8;

int main() {

    /// a bunch of initialization code

    static semi_truck_data_t semi_truck_data = {0};
	TaskShare<semi_truck_data_t> *semi_data = new TaskShare<semi_truck_data_t>();
    
    //rs232 *p_ser_port = new rs232 (9600, 1);
    
	servo serv1 = servo();
    fifth_wheel *fifth = new fifth_wheel("fifth_wheel", 1, 200, nullptr, &semi_truck_data);
    gear_shifter *shifter = new gear_shifter("gear_shifter", 1, 200, nullptr, &semi_truck_data);
    imu_task *imu = new imu_task("imu", 5, 400, nullptr, 0, 0, nullptr);
    mega_comm_task comm = new mega_comm_task("communicator", 5, 500, nullptr, 9600, 1, semi_data);
    motor_driver *motor = new motor_driver("motor", 6, 400, nullptr, &semi_truck_data);
    steer_servo *steering = new steer_servo("steering", 6, 400, nullptr, nullptr);
    wheel_speed *speed = new wheel_speed("speed sensor", 9, 400, nullptr, nullptr);


    /// the actual freeRTOS function that runs the scheduler
}
