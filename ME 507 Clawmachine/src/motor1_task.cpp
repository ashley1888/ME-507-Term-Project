/** @file motor1_task.cpp
 *    This file contains code to test a class for using encoders on STM32's in
 *    the Arduino environment.
 * 
 *
 *  @author JR Ridgely
 *  @date   2020-Nov-15 Original file, based on stuff from the Interwebs

 */

#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>

#include "shares.h"
#include "motor_driver.h"
#include "encoder_counter.h"


/** @brief   Task which tests the reading of encoders using the @c STM32Encoder
 *           class.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */



void task_move_motor (void* p_params)
{
    if (share_encoder_positionx != queue_data 
    // set up code goes here
// check encoder val, if correct spot stop spinning otherwise continue setduty funct
// set up shares to get encoder values 

    for (;;)
    {
        delay (100);

        
    }
}


/** @brief   The usual Arduino setup function which runs once as we start up.
 */
void setup (void) 
{
    Serial.begin (115200);
    delay (1000);
    

    // Create the task that tests the encoder interface class
    xTaskCreate (task_move_motor,     // Task function
                 "Motor",             // Name in diagnostic printouts
                 1000,                   // Stack size in bytes
                 NULL,                   // Parameters for task function
                 6,                      // Task priority
                 NULL);                  // Handle to task struct

    // STM32duino requires that the FreeRTOS scheduler be manually started
    vTaskStartScheduler ();
}


/** @brief   The Arduino loop function, which is unused in this program.
 */
void loop (void)
{
}