/** @file main.cpp
 *    This file contains the controller and motor tasks needed to operate the claw machine. 
 *    The motor tasks are for the X axis, Y axis, Z axis, and for the gripper. 
 *    The controller tasks reads the user input and sends it to the motor tasks.
 *
 *  @author Ashley Humpal and Michael Yiu
 *  @date 2021-01-Dec

 */
#include <Arduino.h>
#include <PrintStream.h>

#if (defined STM32L4xx || defined STM32F4xx)
#include <STM32FreeRTOS.h>
#endif

#include "shares.h"

#include "controller_task.h"
#include "X_Motor_Task.h"
#include "Y_Motor_Task.h"
#include "Z_Motor_Task.h"
#include "Gripper_Motor_Task.h"

// Shared variables and queues initialized 
Queue<uint16_t> queue_x_task(1, "X_Status");
Queue<uint16_t> queue_y_task(1, "Y_Status");
Queue<uint16_t> queue_z_task(1, "Z_Status");

Share<uint16_t> share_x_position;
Share<uint16_t> share_y_position;
Share<uint16_t> share_x_job_status;
Share<uint16_t> share_y_job_status;
Share<uint16_t> share_z_job_status;
Share<uint16_t> share_gripper_job_status;
 
/** @brief   Arduino setup function which runs once at program startup.
 *  @details This function sets up a serial port for communication and creates the
 *           tasks which will be run.
 */
void setup()
{
  Serial.begin(115200);
  delay(1500);

  xTaskCreate(task_controller,    // Task function
              "Control",          // Name in diagnostic printouts
              1000,               // Stack size in bytes
              NULL,               // Parameters for task function
              1,                  // Task priority
              NULL);              // Handle to task struct
  xTaskCreate(task_x_motor,       // Task function
              "X_Motor",          // Name in diagnostic printouts
              1000,               // Stack size in bytes
              NULL,               // Parameters for task function
              1,                  // Task priority
              NULL);              // Handle to task struct
  xTaskCreate(task_y_motor,       // Task function
              "Y_Motor",          // Name in diagnostic printouts
              1000,               // Stack size in bytes
              NULL,               // Parameters for task function
              1,                  // Task priority
              NULL);              // Handle to task struct
  xTaskCreate(task_z_motor,       // Task function
              "Z_Motor",          // Name in diagnostic printouts
              1000,               // Stack size in bytes
              NULL,               // Parameters for task function
              1,                  // Task priority
              NULL);              // Handle to task struct
  xTaskCreate(task_gripper_motor, // Task function
              "Gripper_Motor",    // Name in diagnostic printouts
              1000,               // Stack size in bytes
              NULL,               // Parameters for task function
              1,                  // Task priority
              NULL);              // Handle to task struct

  // STM32duino requires that the FreeRTOS scheduler be manually started
  vTaskStartScheduler();
}
void loop()
{
}