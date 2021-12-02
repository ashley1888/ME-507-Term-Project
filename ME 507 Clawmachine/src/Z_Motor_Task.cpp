/** @file Z_Motor_Task.cpp
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
#include "Z_Motor_Task.h"

// extern Share<uint16_t> share_user_positionz;

void task_z_motor(void *p_params)
{
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing Z motor...";
  MotorDriver Z_motor(PB9, PB8, PB3, PA10);
  Serial << "done." << endl;

  delay(1500);
  Z_motor.enable();

  int8_t power = 100;

  Z_motor.setduty(power); // turn on at max

  for (;;)
  {
    delay(1000);
    // if (Z_encoder.getCount() < share_user_positionx.get()) // calculate how long to leave motor on to reach location
    // {
    // }
    // else if (Z_encoder.getCount() > share_user_positionx.get())
    // {
    //   Z_motor.setduty(-100);
    // }
    // else
    // {
    //   Z_motor.setduty(0);
    // }
  }
}