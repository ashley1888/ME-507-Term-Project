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

void task_z_motor(void *p_params)
{
  // Pointers to timer/counters used; could be in a task function
  Serial << "Initializing Z motor...";
  MotorDriver Z_motor(PB9, PB8, PB3, PA10);
  Serial << "done." << endl;

  Z_motor.enable();

  uint32_t time = 5000;

  for (;;)
  {
    queue_x_task.get();
    queue_y_task.get();
    
    Z_motor.setduty(-100);
    delay(time);
    queue_z_task.put(1);
    share_z_job_status.put(1);
    Z_motor.setduty(0);
  }
}