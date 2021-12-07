/** @file Y_Motor_Task.cpp
 *    This file contains the code for the motor operating in the y direction. It uses the encoder and
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
#include "Y_Motor_Task.h"

void task_y_motor(void *p_params)
{
  Serial << "Initializing Y motor and encoder...";
  MotorDriver Y_motor(PB10, PC7, PB3, PA10); // Creating motor object
  STM32Encoder Y_encoder(TIM1, PA8, PA9); // Creating encoder object
  Serial << "done." << endl;

  Y_motor.enable(); // Turn on motor

  uint16_t user_y = 0; // Local variable created to hold share value

  for (;;)
  {
    share_y_position.get(user_y);

    if(user_y) // if shared variable available
    {
      // Serial << "My Y position is: " << Y_encoder.getCount() << endl;
      Y_motor.setduty(100); // Set duty 
      // Serial << "The shares variable value for y is: " << user_y << endl;;

      if (abs(Y_encoder.getCount() - user_y) <= 50) // If close to desired position
      {
        Y_motor.setduty(0); // set duty to 0 
        share_y_position.put(0); // put 0 into shared variable
        share_y_job_status.put(1); // put 1 into shared job status variable to indicate task done
        queue_y_task.put(1); // put 1 into queue
      }
    }
  }
}