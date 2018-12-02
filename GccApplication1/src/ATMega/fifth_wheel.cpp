//
// Created by nate on 11/14/18.
//

#include "fifth_wheel.h"
#include "../semi_truck_data_t.h"

#define LOCKED true
#define UNLOCKED false
#define LOCKED_LEVEL 1      //todo: NEED TO REPLACE VALUES WHEN TESTING WITH SERVOS
#define UNLOCKED_LEVEL 2



fifth_wheel::fifth_wheel(const char *a_name, unsigned char a_priority, size_t a_stack_size, emstream *p_ser_dev,
                         semi_truck_data_t *semi_data_in, volatile uint16_t *oc_reg, uint8_t ddr_pin_in)
		: servo::servo(oc_reg, ddr_pin_in),
		TaskBase::TaskBase(a_name, a_priority, a_stack_size, p_ser_dev)
{
	semi_data = semi_data_in;
    state = LOCKED; // fifth wheel starts out locked
}

void fifth_wheel::run()
{
    lock_servo();
    state = LOCKED; // fifth wheel starts out locked
	volatile int counter = 0;
    for (;;) {
		//write(0);
        if (state == LOCKED) {
            if (semi_data->desired_5th == UNLOCKED) {
                unlock_servo();
                state = UNLOCKED;
            }
        }

        else if (state == UNLOCKED) {
            if (semi_data->desired_5th == LOCKED) {
                lock_servo();
                state = LOCKED;
            }
        }

        else {                      // should not ever be in a state other than 1 or 2
            print_status(*p_serial);
            break;
        }
		//delay_ms(5);
    }
}

void fifth_wheel::lock_servo()
{
    write(LOCKED_LEVEL);
    semi_data->actual_5th = LOCKED;
}

void fifth_wheel::unlock_servo()
{
    write(UNLOCKED_LEVEL);
    semi_data->actual_5th = UNLOCKED;
}
