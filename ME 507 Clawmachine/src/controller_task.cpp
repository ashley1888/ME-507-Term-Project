/** @file controller_task.cpp
 *    This file contains code for a file which reads the user's position input and stores it into shared variables, 
 *    as well as reading shared variables from other files. 
 * 
 *  @author Ashley Humpal and Michael Yiu 
 *  @date   2021-Dec-06 
 */

#include <Arduino.h> 
#include <PrintStream.h>
#include <STM32FreeRTOS.h>
#include "controller_task.h"
#include "shares.h"

/** @brief   Task which reads the user's input and appropriately stores it into a position
 *           shared variable.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_controller(void *p_params)
{
    uint16_t x_task_done = 1;  // Variable representing status of the completion of the X_Motor_Task
    uint16_t y_task_done = 1;  // Variable representing status of the completion of the Y_Motor_Task
    uint16_t z_task_done = 1;  // Variable representing status of the completion of the Z_Motor_Task
    uint16_t gripper_task_done = 1; // Variable representing status of the completion of the Gripper_Motor_Task
    uint16_t task_done = 1; // Variable representing status of the completion of all motor tasks
    uint8_t one_pos = (pow(2, 16) - 1) / 8; // Variable representing the rotation value needed to move one square on the chess board
    for (;;)
    {
        if (x_task_done && y_task_done && z_task_done && gripper_task_done) // Checks if all motor tasks are completed 
        {
            //if (1) 
            if Serial.available() > 0) // Checks whether user has input anything to the serial monitor 
            {
                uint16_t numberval = Serial.parseInt(); // Reads user input integer values
                uint16_t list = +numberval; //Puts the read numbers together in case there's more than one
                delay(5000); //Waits a little to let user finish entering numbers

                // Beginning of if else conditionals to set shared position variables based on what the user input

                    if (list == 1) // If user entered 1
                    {
                        share_x_position.put(one_pos); // Set the shared user x position as the following
                        share_y_position.put(one_pos); // Set the shared user y position as the following
                    }
                    else if (list == 2)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos);
                    }
                    else if (list == 3)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos);
                    }
                    else if (list == 4)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos);
                    }
                    else if (list == 5)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos);
                    }
                    else if (list == 6)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos);
                    }
                    else if (list == 7)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos);
                    }
                    else if (list == 8)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos);
                    }
                
                    // row 2
                    else if (list == 9)
                    {
                        share_x_position.put(one_pos);
                        share_y_position.put(one_pos * 2);
                    }
                    else if (list == 10)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos * 2);
                    }
                    else if (list == 11)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos * 2);
                    }
                    else if (list == 12)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos * 2);
                    }
                    else if (list == 13)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos * 2);
                    }
                    else if (list == 14)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos * 2);
                    }
                    else if (list == 15)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos * 2);
                    }
                    else if (list == 16)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos * 2);
                    }

                    // row 3
                    else if (list == 17)
                    {
                        share_x_position.put(one_pos);
                        share_y_position.put(one_pos * 3);
                    }
                    else if (list == 18)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos * 3);
                    }
                    else if (list == 19)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos * 3);
                    }
                    else if (list == 20)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos * 3);
                    }
                    else if (list == 21)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos * 3);
                    }
                    else if (list == 22)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos * 3);
                    }
                    else if (list == 23)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos * 3);
                    }
                    else if (list == 24)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos * 3);
                    }

                    // row 4
                    else if (list == 25)
                    {
                        share_x_position.put(one_pos);
                        share_y_position.put(one_pos * 4);
                    }
                    else if (list == 26)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos * 4);
                    }
                    else if (list == 27)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos * 4);
                    }
                    else if (list == 28)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos * 4);
                    }
                    else if (list == 29)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos * 4);
                    }
                    else if (list == 30)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos * 4);
                    }
                    else if (list == 31)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos * 4);
                    }
                    else if (list == 32)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos * 4);
                    }

                    // row 5
                    else if (list == 33)
                    {
                        share_x_position.put(one_pos);
                        share_y_position.put(one_pos * 5);
                    }
                    else if (list == 34)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos * 5);
                    }
                    else if (list == 35)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos * 5);
                    }
                    else if (list == 36)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos * 5);
                    }
                    else if (list == 37)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos * 5);
                    }
                    else if (list == 38)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos * 5);
                    }
                    else if (list == 39)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos * 5);
                    }
                    else if (list == 40)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos * 5);
                    }

                    // row 6
                    else if (list == 41)
                    {
                        share_x_position.put(one_pos);
                        share_y_position.put(one_pos * 6);
                    }
                    else if (list == 42)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos * 6);
                    }
                    else if (list == 43)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos * 6);
                    }
                    else if (list == 44)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos * 6);
                    }
                    else if (list == 45)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos * 6);
                    }
                    else if (list == 46)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos * 6);
                    }
                    else if (list == 47)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos * 6);
                    }
                    else if (list == 48)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos * 6);
                    }

                    // row 7
                    else if (list == 49)
                    {
                        share_x_position.put(one_pos);
                        share_y_position.put(one_pos * 7);
                    }
                    else if (list == 50)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos * 7);
                    }
                    else if (list == 51)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos * 7);
                    }
                    else if (list == 52)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos * 7);
                    }
                    else if (list == 53)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos * 7);
                    }
                    else if (list == 54)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos * 7);
                    }
                    else if (list == 55)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos * 7);
                    }
                    else if (list == 56)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos * 7);
                    }

                    // row 8
                    else if (list == 57)
                    {
                        share_x_position.put(one_pos);
                        share_y_position.put(one_pos * 8);
                    }
                    else if (list == 58)
                    {
                        share_x_position.put(one_pos * 2);
                        share_y_position.put(one_pos * 8);
                    }
                    else if (list == 59)
                    {
                        share_x_position.put(one_pos * 3);
                        share_y_position.put(one_pos * 8);
                    }
                    else if (list == 60)
                    {
                        share_x_position.put(one_pos * 4);
                        share_y_position.put(one_pos * 8);
                    }
                    else if (list == 61)
                    {
                        share_x_position.put(one_pos * 5);
                        share_y_position.put(one_pos * 8);
                    }
                    else if (list == 62)
                    {
                        share_x_position.put(one_pos * 6);
                        share_y_position.put(one_pos * 8);
                    }
                    else if (list == 63)
                    {
                        share_x_position.put(one_pos * 7);
                        share_y_position.put(one_pos * 8);
                    }
                    else if (list == 64)
                    {
                        share_x_position.put(one_pos * 8);
                        share_y_position.put(one_pos * 8);
                    }
                    else 
                    {
                        Serial.print( "Invalid entry. Please try again.");
                    }

                    Serial << list << endl;
                }
                // Clear initial variables that indicate the task is done in preparation for next run
                x_task_done = 0; 
                y_task_done = 0;
                z_task_done = 0;
                gripper_task_done = 0;

                // Testing code 
                //share_x_position.put(5000); 
                //share_y_position.put(5000);
            }
            share_x_job_status.get(x_task_done); // Get shared variable representing status of X_Motor_Task
            share_y_job_status.get(y_task_done); // Get shared variable representing status of Y_Motor_Task
            share_z_job_status.get(z_task_done); // Get shared variable representing status of Z_Motor_Task
            share_gripper_job_status.get(gripper_task_done); // Get shared variable representing status of Gripper_Motor_Task
        }
    }
}