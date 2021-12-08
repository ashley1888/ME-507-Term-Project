/** @file Y_Motor_Task.cpp
 *    This file contains the implementation of the y-motor task.
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
#include "Y_Motor_Task.h"

/** @brief   Y-motor task
 *  @details Turns on the y-motor once a value has been given to it
 *           from the controller task. It turns off once the encoder
 *           is withing 50 ticks of the supplied reference position.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_y_motor(void *p_params)
{
  // Serial << "Initializing Y motor and encoder...";
  MotorDriver Y_motor(PB10, PC7, PB3, PA10); // Creating y-motor object
  STM32Encoder Y_encoder(TIM1, PA8, PA9); // Creating encoder object for y-motor
  // Serial << "done." << endl;

  Y_motor.enable(); // Turn on motor

  uint16_t user_y = 0; // Local variable created to hold share value

  for (;;)
  {
    share_y_position.get(user_y); // If available get a y-value from the controller task

    if(user_y) // Initially zero so that if the controller has not yet supplied a value, the if statement will not evaluate
    {
      // Serial << "My Y position is: " << Y_encoder.getCount() << endl;
      Y_motor.setduty(100); // Set duty 
      // Serial << "The shares variable value for y is: " << user_y << endl;;

      if (abs(Y_encoder.getCount() - user_y) <= 50) // If close enough to desired position, turn off motor and indicate that task is complete
      {
        Y_motor.setduty(0); // set duty to 0 
        share_y_position.put(0); // put 0 into shared variable
        share_y_job_status.put(1); // put 1 into shared job status variable to indicate task done
        queue_y_task.put(1); // put 1 into queue
      }
    }
  }
}