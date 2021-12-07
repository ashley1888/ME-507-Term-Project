/** @file X_Motor_Task.cpp
 *    This file contains the code for the motor operating in the x direction. It uses the encoder and
 *    and motor drivers to verify it's at the desired locaton.
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

void task_x_motor(void *p_params)
{
  Serial << "Initializing X motor and encoder...";
  MotorDriver X_motor(PA0, PA1, PB3, PA10); // Creating motor object
  STM32Encoder X_encoder(TIM3, PB4, PB5); // Creating encoder object
  Serial << "done." << endl;

  X_motor.enable(); // Turn on motor

  uint16_t user_x = 0; // Local variable created to hold share value

  for (;;)
  {
    share_x_position.get(user_x);

    if(user_x) // if shared variable available
    {
       Serial << "My X position is: " << X_encoder.getCount() << endl; // Print encoder position
      X_motor.setduty(-100); // Set duty 

      if (abs(X_encoder.getCount() - user_x) <= 50) // If close to desired position
      {
        X_motor.setduty(0); // set duty to 0 
        share_x_position.put(0); // put 0 into shared variable
        share_x_job_status.put(1); // put 1 into shared job status variable to indicate task done
        queue_x_task.put(1); // put 1 into queue
      }
    }
  }
}