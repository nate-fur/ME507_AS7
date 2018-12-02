//
// Created by nate on 11/19/18.
//

#include "motor_driver.h"
#include "../semi_truck_data_t.h"

motor_driver::motor_driver(const char *a_name, 
unsigned char a_priority, 
size_t a_stack_size, 
emstream *p_ser_dev,                      
semi_truck_data_t *semi_data_in, 
volatile uint16_t *oc_reg, 
uint8_t ddr_pin)
        : TaskBase(a_name, a_priority, a_stack_size, p_ser_dev)
{
	out_comp_reg = oc_reg; // set the given output compare register for the servo, which handles pwm duty cycle
	*ddr_reg |= (1 << 4); // sets DDR to configure ddr_pin of port E to be output for PWM
	semi_data = semi_data_in;
}

void motor_driver::run()
{

	for (;;) {
		write(semi_data->motor_output);
		delay_ms(50);
	}
}

void motor_driver::write(uint16_t value)
{
	(*out_comp_reg)++;
	/*
    if( value < SERVO_MIN ) {         // ensure pulse width is valid
		value = SERVO_MIN;
	}
	
    else if( value > SERVO_MAX ) {
		value = SERVO_MAX;
	}
	*out_comp_reg = value; // writes the end value to the servo's output compare register for PWM control
	*/
}