#include "servo.h"


servo::servo(volatile uint16_t *oc_reg, uint8_t ddr_pin)
{
	out_comp_reg = oc_reg;
    *ddr_reg |= (1 << ddr_pin);
}


void servo::write(int value)
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

