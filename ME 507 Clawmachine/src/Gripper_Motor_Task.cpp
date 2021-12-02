/** @file Gripper_Motor_Task.cpp
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
#include "Gripper_Motor_Task.h"

// extern Share<uint16_t> share_user_positionz;

void task_gripper_motor(void *p_params)
{
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing Gripper motor...";
  MotorDriver Gripper_motor(PB6, PA5, PB3, PA10);
  Serial << "done." << endl;

  delay(1500);
  Gripper_motor.enable();

  int8_t power = 100;

  Gripper_motor.setduty(power); // turn on at max

  for (;;)
  {
    delay(1000);
    // if (Gripper_encoder.getCount() < share_user_positionx.get()) // calculate how long to leave motor on to reach location
    // {
    // }
    // else if (Gripper_encoder.getCount() > share_user_positionx.get())
    // {
    //   Gripper_motor.setduty(-100);
    // }
    // else
    // {
    //   Gripper_motor.setduty(0);
    // }
  }
}