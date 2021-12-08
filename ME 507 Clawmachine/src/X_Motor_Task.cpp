/** @file X_Motor_Task.cpp
 *    This file contains the implementation of the x-motor task.
 *    It waits for the user to give it a refernce position value,
 *    which is obtained from the controller task. Once a value has
 *    been obtained, the motor powers on and only turns off once the
 *    encoder is within 50 ticks of the destination.
 *
 *  @author Michael Yiu and Ashley Humpal
 *  @date   2021-Dec-01
 */
#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>

#include "shares.h"
#include "motor_driver.h"
#include "encoder_counter.h"
#include "X_Motor_Task.h"

/** @brief   X-motor task
 *  @details Turns on the x-motor once a value has been given to it
 *           from the controller task. It turns off once the encoder
 *           is withing 50 ticks of the supplied reference position.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_x_motor(void *p_params)
{
  // Serial << "Initializing X motor and encoder...";
  MotorDriver X_motor(PA0, PA1, PB3, PA10); // Creating x-motor object
  STM32Encoder X_encoder(TIM3, PB4, PB5); // Creating encoder object for x-motor
  // Serial << "done." << endl;

  X_motor.enable(); // Turn on motor

  uint16_t user_x = 0; // Local variable created to hold share value

  for (;;)
  {
    share_x_position.get(user_x); // If available get an x-value from the controller task

    if(user_x) // Initially zero so that if the controller has not yet supplied a value, the if statement will not evaluate
    {
      //  Serial << "My X position is: " << X_encoder.getCount() << endl; // Print encoder position
       X_motor.setduty(-100); // Set duty 

      if (abs(X_encoder.getCount() - user_x) <= 50) // If close enough to desired position, turn off motor and indicate that task is complete
      {
        X_motor.setduty(0); // set duty to 0 
        share_x_position.put(0); // put 0 into shared variable
        share_x_job_status.put(1); // put 1 into shared job status variable to indicate task done
        queue_x_task.put(1); // put 1 into queue
      }
    }
  }
}