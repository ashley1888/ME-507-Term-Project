/** @file Y_Motor_Task.cpp
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
#include "Y_Motor_Task.h"

void task_y_motor(void *p_params)
{
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing Y motor and encoder...";
  MotorDriver Y_motor(PB10, PC7, PB3, PA10);
  STM32Encoder Y_encoder(TIM1, PA8, PA9);
  Serial << "done." << endl;

  Y_motor.enable();

  uint16_t user_y = 0;

  for (;;)
  {
    share_y_position.get(user_y);

    if(user_y)
    {
      Serial << "My Y position is: " << Y_encoder.getCount() << endl;
      Y_motor.setduty(100);
      Serial << "The shares variable value for y is: " << user_y << endl;;

      if (abs(Y_encoder.getCount() - user_y) <= 50)
      {
        Y_motor.setduty(0);
        share_y_position.put(0);
      }
    }
  }
}