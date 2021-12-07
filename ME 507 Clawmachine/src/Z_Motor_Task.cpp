/** @file Z_Motor_Task.cpp
 *    This file contains the code for the motor operating in the z direction. It uses the 
 *    motor driver to spin. 
 *
 *  @author Michael Yiu and Ashley Humpal
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
  Serial << "Initializing Z motor...";
  MotorDriver Z_motor(PB9, PB8, PB3, PA10); // Creating motor object
  Serial << "done." << endl;

  Z_motor.enable(); // Turn on motor

  uint32_t time = 5000; // Variable representing duration 

  for (;;)
  {
    queue_x_task.get(); // Gets x task value from queue 
    queue_y_task.get(); // Gets y task value from queue 
    
    Z_motor.setduty(-100); // Motor duty is set 
    delay(time); // waits until time is over
    queue_z_task.put(1); // puts 1 into queue to indicate z task complete
    share_z_job_status.put(1); // puts 1 into share to indicate z task complete
    Z_motor.setduty(0); // sets duty cycle to 0
  }
}