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
    uint16_t task_done = 1;
    for(;;)
    {
        //Serial.print("At the start");
        uint16_t zero = 0;
        uint16_t one = 0;
        //share_user_positionx.put(zero);
        if (task_done == 1); 
        
        {
            if (Serial.available() > 0)  // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
                { 
                //char numreadx = Serial.read();
            //char numreadx = Serial.read();
                uint16_t numbervalx = Serial.parseInt(); 

                uint16_t listx=+ numbervalx;
                task_done= 0;
                Serial.print(listx);
                
                //char x = Serial.read();
                //Serial.print('x');
                queue_userx.put(listx);

                delay(4000);
                uint16_t numbervaly = Serial.parseInt(); 

                uint16_t listy=+ numbervaly;
                //task_done= 0;
                Serial.print(listy);



                 //char enterkey = Serial.read();
                //char enterkey ;


               // uint16_t reading = Serial.read();

                //if (enterkey == 0x0A);
                //if (one == 1);
               // {
                //delay(6000);
                  //Serial.print (1);
                //}
                //Serial.print(list);
                
                
                //delay(6000);

                

                //share_job_status.get(task_done);
                }


            //share_user_positionx.put(numreadx);  // putting the users input value into the share 
            //    delay (5000);
            //    //share_user_positionx.put(0);

            //    char numready = Serial.read();
            //    share_user_positiony.put(numready);

            //    if (Serial.available() > 0)  // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
            //     { 
            //    //char numreadx = Serial.read();
            //    char numready = Serial.read();
            //    share_user_positiony.put(numready);  // putting the users input value into the share 
            //    delay (100);
            //    //share_user_positiony.put(0);
            //     }
            
        }
        
        // delay(10000);
        // Serial.print (" Input y location ");
        // if (Serial.available() > 0)  // source from link Ridgley sent: https://forum.arduino.cc/t/controlling-arduino-by-text-input/112703/3
        // { 
        //  uint16_t numready = Serial.read(); // not sure on this variables identifier type 
        //  share_user_positiony.put(numready); 
        //     //share_user_positionx.put(numreadx);  // putting the users input value into the share 
        //     //share_user_positiony.put(user_y);
    }

}

