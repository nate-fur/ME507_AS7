#ifndef servo_h
#define servo_h

#include <stdint.h>

#define SERVO_MIN 0
#define SERVO_MAX 1000
#define DDRB (uint8_t*)0x37

class servo
{
public:
    servo(volatile uint16_t *oc_reg, uint8_t ddr_pin);
	
	/*
     * @brief Writes a value to the output compare register for servo
	 * to change its PWM duty cycle that controls servo position
	 * @param value the value being written into the OCR (0 to 255)
	 */
    void write(int value);             

private:
	volatile uint16_t *out_comp_reg;
	volatile uint8_t *ddr_reg = DDRB; // based on the pinout for the atmega64, all of our servos work thru port b
	uint8_t ddr_pin; 
};


#endif