/** @file controller_task.cpp
 *    This file contains code to test a class for using encoders on STM32's in
 *    the Arduino environment.
 * 
 *    References:
 *    @c https://www.edwinfairchild.com/2019/04/interface-rotary-encoder-right-way.html
 *
 *  @author JR Ridgely
 *  @date   2020-Nov-15 Original file, based on stuff from the Interwebs
 * https://github.com/spluttflob/ME507-Support/blob/master/examples/encoder_test.cpp
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <STM32FreeRTOS.h>


#include "controller_task.h"
#include "shares.h"

//extern Share<uint16_t> share_encoder_positionx;
//extern Share<uint16_t> share_encoder_positiony;


/** @brief   Task which tests the reading of encoders using the @c STM32Encoder
 *           class.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_control (void* p_params)
{
    // Pointers to timer/counters used; could be in a task function
    //uint16_t share_data;
    uint8_t user_x; 
    cout << "Input X position";  // shows this is the common way to prompt user for input on opensource forums so idk why the error
    cin >> user_x;

    uint8_t user_y; 
    cout << "Input X position";  // shows this is the common way to prompt user for input on opensource forums so idk why the error
    cin >> user_y;

// make shares but in comments 
    for (;;)
    {
        delay (100);
        share_user_positionx.put(user_x);  // putting the users input value into the share 
        share_user_positiony.put(user_y);
    }

}


/** @brief   The usual Arduino setup function which runs once as we start up.
 */
void setup (void) 
{
    Serial.begin (115200);
    delay (1000);

    // Create the task that tests the encoder interface class
    xTaskCreate (task_control     // Task function
                 "Control",             // Name in diagnostic printouts
                 1000,                   // Stack size in bytes
                 NULL,                   // Parameters for task function
                 3,                      // Task priority
                 NULL);                  // Handle to task struct

    // STM32duino requires that the FreeRTOS scheduler be manually started
    vTaskStartScheduler ();
}


/** @brief   The Arduino loop function, which is unused in this program.
 */
void loop (void)
{
}