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

extern Share<uint16_t> share_encoder_positionx;
extern Share<uint16_t> share_encoder_positiony;
extern Share<uint16_t> share_user_positionx;
extern Share<uint16_t> share_user_positiony;
extern Share<uint16_t> share_job_status;

/** @brief   Task which tests the reading of encoders using the @c STM32Encoder
 *           class.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_controller(void *p_params)
{
    for (;;)
    {
        delay(5000);
        Serial.print("Input x location: ");
        if (Serial.available() > 0) // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
        {
            uint16_t num_read_x = Serial.read();  // not sure on this variables identifier type
            // share_user_positionx.put(num_read_x); // putting the users input value into the share
        }

        delay(5000);
        Serial.print("Input y location: ");
        if (Serial.available() > 0) // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
        {
            uint16_t num_read_y = Serial.read(); // not sure on this variables identifier type
            // share_user_positiony.put(num_read_y);
            // share_user_positionx.put(num_read_x);  // putting the users input value into the share
            // share_user_positiony.put(user_y);
        }
    }
    // IM NOT SURE IF THIS CODE SHOULD BE HERE OR IN THE VOID SETUP LOOP BELOW OR THE FOR LOOP ??

    // Serial.print (" Input x location ");
    // if (Serial.available() > 0)  // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
    // {
    //  uint16_t num_read_x = Serial.read(); // not sure on this variables identifier type
    //  share_user_positionx.put(num_read_x);  // putting the users input value into the share
    // }

    // delay(10000);
    // Serial.print (" Input y location ");
    // if (Serial.available() > 0)  // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
    // {
    //  uint16_t num_read_y = Serial.read(); // not sure on this variables identifier type
    //  share_user_positiony.put(num_read_y);  // putting the users input value into the share
    // }

    // Pointers to timer/counters used; could be in a task function
    // uint16_t share_data;
    // uint8_t user_x;
    // cout << "Input X position";  // shows this is the common way to prompt user for input on opensource forums so idk why the error
    // cin >> user_x;

    // uint8_t user_y;
    // cout << "Input X position";  // shows this is the common way to prompt user for input on opensource forums so idk why the error
    // cin >> user_y;

    // make shares but in comments
}