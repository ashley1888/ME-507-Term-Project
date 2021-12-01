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

extern Share<uint16_t> share_encoder_positiony;
extern Share<uint16_t> share_user_positiony;

void task_y_motor(void *p_params)
{
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing Y motor and encoder...";
  MotorDriver Y_motor(PB10, PC7, PB3);
  STM32Encoder Y_encoder(TIM1, PA8, PA9);
  Serial << "done." << endl;

  delay(1500);
  Y_motor.enable();

  int8_t power = 100;

  Y_motor.setduty(power); // turn on at max

  for (;;)
  {
    delay(1000);
    Serial << "My Y position is: " << Y_encoder.getCount() << endl;
    //   if (Y_encoder.getCount() >= 5000) // spin til encoder 65,535
    //   {
    //     Y_motor.setduty(-power); // Y_motor.disable();
    //   }
    //   if (Y_encoder.getCount() <= 500) // spin til encoder 65,535
    //   {
    //     Y_motor.setduty(power); // Y_motor.disable();
    //   }
    // }
    if (Y_encoder.getCount() < share_user_positionx.get())
    {
    }
    else if (Y_encoder.getCount() > share_user_positionx.get())
    {
      Y_motor.setduty(-100);
    }
    else
    {
      Y_motor.setduty(0);
    }
  }
}