///*----------------------------------------------------------------------------
// *      doorLock_MOTOR.h
// *----------------------------------------------------------------------------
// *      Name:    doorLock_MOTOR.h
// *---------------------------------------------------------------------------*/

#ifndef  _LPC1768_utility_h
#include "LPC1768_utility.h"
#endif // !"LPC1768_utility.h"

#ifndef _LPC1768_motor_h
#include "LPC1768_motor.h"
#endif // !"LPC1768_motor.h"

#ifndef _doorLock_utility_h
#include "doorLock_utility.h"
#endif // !_doorLock_utility_H

#define bool 							int
#define false							0
#define true 							1

#define FORWARD_MOTOR_TIME 150
#define BACKWARD_MOTOR_TIME 150
#define MOTOR_DELAY_TIME 200

typedef enum { move, stop, DOORLOCK_OPEN, DOORLOCK_CLOSE} DOOR_LOCK_MOTOR_STATE;

void init_stepping_motor(void);
void set_motor_output(int a, int na, int b, int nb);
void StepMotor_Cycle(uint8_t cycle);
void stepMotor_move_cw(void);
void stepMotor_move_ccw(void);

void setOpenDoorLock(void);
void setCloseDoorLock(void);
void move_steppingMotor(void);












