#ifndef servo_h
#define servo_h

#define SERVO_MIN 0
#define SERVO_MAX 1000

class servo
{
public:
    servo();
    void write(int value);             // if value is < 200 its treated as an angle, otherwise as pulse width in microseconds

private:

};


#endif