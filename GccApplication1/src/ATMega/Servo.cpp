#include "servo.h"

servo::servo()
{

}


void servo::write(int value)
{
      if( value < SERVO_MIN )          // ensure pulse width is valid
      value = SERVO_MIN;
      else if( value > SERVO_MAX )
      value = SERVO_MAX;
}

