/** @file Gripper_Motor_Task.cpp
 *    This file contains the implementation of the gripper-motor task. 
 *    It turns only runs once the z-tasks has indicated that
 *    it has completed. The gripper-motors will turn on for a
 *    specified length of time to grasp an object, then wait a
 *    different specified length of time before releasing it.
 *
 *  @author Michael Yiu and Ashley Humpal
 *  @date   2021-Dec-01
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>

#include "shares.h"
#include "motor_driver.h"
#include "Gripper_Motor_Task.h"

/** @brief   Gripper-motor task
 *  @details Turns on the gripper-motor once the z-motor tasks
 *           has completed. The gripper-motor will turn on for
 *           a specified length of time, wait a different length
 *           of time, then turn off the motor and indicate that
 *           the task has been completed.
 * 
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_gripper_motor(void *p_params)
{
  MotorDriver Gripper_motor(PB6, PA5, PB3, PA10); // Creating motor object
  Gripper_motor.enable(); // Turning on motor
  uint32_t time = 5000; // Variable for the duration the motor will be going in one direction

  for (;;)
  {
    queue_z_task.get(); // Queue used as trigger; code below runs once the Z_Motor_Task is completed 
    Gripper_motor.setduty(100); // Turn the motor on to full power 
    delay(time); // Wait 
    Gripper_motor.setduty(-100); // Reverse direction
    share_gripper_job_status.put(1); // Put value into share indicating task is done
    Gripper_motor.setduty(0); // Set motor to 0 
  }
}