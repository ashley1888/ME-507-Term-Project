/** @file X_Motor_Task.cpp
 *    This file contains code to test a class for using encoders on STM32's in
 *    the Arduino environment.
 *
 *  @author Michael Yiu
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
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing X motor and encoder...";
  MotorDriver X_motor(PA0, PA1, PB3, PA10);
  STM32Encoder X_encoder(TIM3, PB4, PB5);
  Serial << "done." << endl;

  X_motor.enable();

  uint16_t user_x = 0;

  for (;;)
  {
    share_x_position.get(user_x);

    if(user_x)
    {
       Serial << "My X position is: " << X_encoder.getCount() << endl;
      X_motor.setduty(-100);
      // Serial << "The shares variable value for x is: " << user_x << endl;;

      if (abs(X_encoder.getCount() - user_x) <= 50)
      {
        X_motor.setduty(0);
        share_x_position.put(0);
        share_x_job_status.put(1);
        queue_x_task.put(1);
      }
    }
  }
}