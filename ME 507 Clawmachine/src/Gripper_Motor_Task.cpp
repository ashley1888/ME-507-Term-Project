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

void task_gripper_motor(void *p_params)
{
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing Gripper motor...";
  MotorDriver Gripper_motor(PB6, PA5, PB3, PA10);
  Serial << "done." << endl;

  Gripper_motor.enable();

  uint32_t time = 5000;

  for (;;)
  {
    queue_z_task.get();
    
    Gripper_motor.setduty(100);
    delay(time);
    Gripper_motor.setduty(-100);
    share_gripper_job_status.put(1);
    Gripper_motor.setduty(0);
  }
}