//
// Created by nate on 11/18/18.
//

#include "steer_servo.h"
#include "../semi_truck_data_t.h"

#define FORWARDS 0

steer_servo::steer_servo(const char *a_name, unsigned char a_priority, size_t a_stack_size, emstream *p_ser_dev,
						 semi_truck_data_t *semi_data_in, volatile uint16_t *oc_reg, uint8_t ddr_pin_in)
		: servo::servo(oc_reg, ddr_pin_in),			 
		TaskBase::TaskBase(a_name, a_priority, a_stack_size, p_ser_dev)
{
	DDRB |= 0b10000000; // sets DDR to configure pin 7 of port B to be output for PWM

    semi_data = semi_data_in;
    write(FORWARDS); // want the semi-truck to start facing forwards
}

void steer_servo::run()
{
	for (;;) {
	    write(semi_data->steer_output);
		delay_ms(5);
	}
}

void steer_servo::set_steering_level(int16_t level)
{
	semi_data->steer_output= level;
}

int16_t steer_servo::get_steering_level()
{
	return semi_data->steer_output;
}

