/** @file Z_Motor_Task.cpp
 *    This file contains the implementation of the z-motor task. 
 *    It turns only runs once the x and y-tasks have indicated that
 *    they have been completed. The z-motors will turn off once the
 *    specific length of time has elapsed.
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

/** @brief   Z-motor task
 *  @details Turns on the z-motor once the x and y-motor tasks
 *           have been completed. The z-motor will turn on for
 *           a specified length of time, send an indication
 *           to the gripper motor that the task was complete, and
 *           then turn off the motor.
 * 
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_z_motor(void *p_params)
{
  // Serial << "Initializing Z motor...";
  MotorDriver Z_motor(PB9, PB8, PB3, PA10); // Creating z-motor object
  // Serial << "done." << endl;

  Z_motor.enable(); // Turn on motor

  uint32_t time = 5000; // Variable representing duration 

  for (;;)
  {
    // Queues allow for blocking of the rest of the code until the x and y-tasks are completed.
    queue_x_task.get(); // Gets x task value from queue 
    queue_y_task.get(); // Gets y task value from queue 
    
    Z_motor.setduty(-100); // Motor duty is set 
    delay(time); // waits until time is over
    queue_z_task.put(1); // puts 1 into queue to indicate z task complete
    share_z_job_status.put(1); // puts 1 into share to indicate z task complete
    Z_motor.setduty(0); // sets duty cycle to 0
  }
}