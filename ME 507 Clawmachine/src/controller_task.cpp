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

// extern Share<uint16_t> share_encoder_positionx;
// extern Share<uint16_t> share_encoder_positiony;
// extern Share<uint16_t> share_user_positionx;
// extern Share<uint16_t> share_user_positiony;
// extern Share<uint16_t> share_job_status;

/** @brief   Task which tests the reading of encoders using the @c STM32Encoder
 *           class.
 *  @param   p_params A pointer, which is ignored, to no parameters
 */
void task_controller(void *p_params)
{
    uint16_t task_done = 1;
    uint8_t one_pos = (pow(2,16)-1 )/8;
    for (;;)
    {
        if (task_done == 1)
        {
            if (Serial.available() > 0) // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
            {
                uint16_t numberval = Serial.parseInt();
                uint16_t list = +numberval;

                // Serial.print(listx);

                // delay(5000);
                // Serial.print("Input x location: ");
                // if (Serial.available() > 0) // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
                // {
                //     uint16_t num_read_x = Serial.read();  // not sure on this variables identifier type
                //     // share_user_positionx.put(num_read_x); // putting the users input value into the share
                // }

                // delay(5000);
                // Serial.print("Input y location: ");
                // if (Serial.available() > 0) // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
                // {
                //     uint16_t num_read_y = Serial.read(); // not sure on this variables identifier type
                //     // share_user_positiony.put(num_read_y);
                //     // share_user_positionx.put(num_read_x);  // putting the users input value into the share
                //     // share_user_positiony.put(user_y);
                // }

                // queue_x_position.put(listx);

                if list == 1
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos);
                }
                else if (list==2 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos);
                }
                else if (list==3 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos);
                }
                else if (list==4 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos);
                }
                else if (list==5 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos);
                }
                else if (list==6 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos);
                }
                else if (list==7 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos);
                }
                else if (list==8 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos);
                }

                // row 2 
                else if (list==9 )
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos*2);
                }
                else if (list==10 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos*2);
                }
                else if (list==11 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos*2);
                }
                else if (list==12 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos*2);
                }
                else if (list==13 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos*2);
                }
                else if (list==14 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos*2);
                }
                else if (list==15 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos*2);
                }
                else if (list==16 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos*2);
                }

                // row 3 
                else if (list==17 )
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos*3);
                }
                else if (list==18 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos*3);
                }
                else if (list==19 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos*3);
                }
                else if (list==20 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos*3);
                }
                else if (list==21 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos*3);
                }
                else if (list==22 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos*3);
                }
                else if (list==23 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos*3);
                }
                else if (list==24 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos*3);
                }

                //row 4 

                else if (list==25 )
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos*4);
                }
                else if (list==26 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos*4);
                }
                else if (list==27 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos*4);
                }
                else if (list==28 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos*4);
                }
                else if (list==29 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos*4);
                }
                else if (list==30 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos*4);
                }
                else if (list==31 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos*4);
                }
                else if (list==32 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos*4);
                }
                
                // row 5
                //
                //
                else if list == 33
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos*5);
                }
                else if (list==34 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos*5);
                }
                else if (list==35 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos*5);
                }
                else if (list==36 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos*5);
                }
                else if (list==37 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos*5);
                }
                else if (list==38 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos*5);
                }
                else if (list==39 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos*5);
                }
                else if (list==40 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos*5);
                }

                // row 6 
                else if (list==41 )
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos*6);
                }
                else if (list==42 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos*6);
                }
                else if (list==43 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos*6);
                }
                else if (list==44 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos*6);
                }
                else if (list==45 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos*6);
                }
                else if (list==46 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos*6);
                }
                else if (list==47 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos*6);
                }
                else if (list==48 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos*6);
                }

                // row 7 
                else if (list==49 )
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos*7);
                }
                else if (list==50 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos*7);
                }
                else if (list==51 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos*7);
                }
                else if (list==52 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos*7);
                }
                else if (list==53 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos*7);
                }
                else if (list==54 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos*7);
                }
                else if (list==55 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos*7);
                }
                else if (list==56 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos*7);
                }

                //row 8

                else if (list==57 )
                {
                    share_x_position.put(one_pos);
                    share_y_position.put(one_pos*8);
                }
                else if (list==58 )
                {
                    share_x_position.put(one_pos*2);
                    share_y_position.put(one_pos*8);
                }
                else if (list==59 )
                {
                    share_x_position.put(one_pos*3);
                    share_y_position.put(one_pos*8);
                }
                else if (list==60 )
                {
                    share_x_position.put(one_pos*4);
                    share_y_position.put(one_pos*8);
                }
                else if (list==61 )
                {
                    share_x_position.put(one_pos*5);
                    share_y_position.put(one_pos*8);
                }
                else if (list==62 )
                {
                    share_x_position.put(one_pos*6);
                    share_y_position.put(one_pos*8);
                }
                else if (list==63 )
                {
                    share_x_position.put(one_pos*7);
                    share_y_position.put(one_pos*8);
                }
                else if (list==64 )
                {
                    share_x_position.put(one_pos*8);
                    share_y_position.put(one_pos*8);
                }
                
                
                //share_x_position.put(listx);
                Serial << list << endl;

                // delay(5000);
                // uint16_t numbervaly = Serial.parseInt();
                // uint16_t lisyx = +numbervaly;
                // share_y_position.put(listy);
                // Serial << listy << endl;


                task_done = 0;
                // share_gripper_job_status.get();
            }
        }
    }
}