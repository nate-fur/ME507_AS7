//
// Created by nate on 11/8/18.
//

#include "include/taskbase.h"
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

#define nullptr NULL
const uint8_t N_MULTI_TASKS = 8;

int main() {
	//board_init();

    /// a bunch of initialization code
    static semi_truck_data_t semi_truck_data = {0};
	TaskShare<semi_truck_data_t> *semi_data = new TaskShare<semi_truck_data_t>("semi data");
    
    // rs232 *p_ser_port = new rs232 (9600, 1);
	// SERVOS
    fifth_wheel *fifth = new fifth_wheel("fifth_wheel", 1, 200, nullptr, &semi_truck_data, &OCR1A, (uint8_t)5);
	gear_shifter *shifter = new gear_shifter("gear_shifter", 1, 200, nullptr, &semi_truck_data, &OCR1B, (uint8_t)6);
	steer_servo *steering = new steer_servo("steering", 1, 400, nullptr, &semi_truck_data, &OCR1C, (uint8_t)7);
	
	
    //imu_task *imu = new imu_task("imu", 5, 400, nullptr, 0, 0, nullptr);
	//mega_comm_task *comm = new mega_comm_task("communicator", 5, 500, nullptr, 9600, 1, semi_data);
    //motor_driver *motor = new motor_driver("motor", 6, 400, nullptr, &semi_truck_data);
    //wheel_speed *speed = new wheel_speed("speed sensor", 9, 400, nullptr, nullptr);
    
    /// the actual freeRTOS function that runs the scheduler
	vTaskStartScheduler();
}
