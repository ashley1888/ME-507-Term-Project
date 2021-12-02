/** @file motor_driver.cpp
 *    This file 
 * 
 * 
 */
#include <Arduino.h>
#include <PrintStream.h>
#include "motor_driver.h"

/** @brief   Cr
 * 
 *  @details This
 */

MotorDriver::MotorDriver (uint8_t pin1, uint8_t pin2, uint8_t nsleep, uint8_t nfault)
//pin1, pin2, nsleep
{  _nsleep = nsleep;
   _pin1 = pin1;
   _pin2 = pin2;
   _nfault = nfault;
   

    pinMode(_pin1, OUTPUT); 
    pinMode(_pin2, OUTPUT); 
    pinMode(_nsleep, OUTPUT); 
    pinMode(nfault, INPUT_PULLUP); 
    //pinMode(nfault, INPUT_PULLUP) -- MAKE FUNCT FOR WHEN LOGIC LOW IT KNOWS IT FAULT AND SETS MOTOR TO DISABLE
}

void MotorDriver::faulted (void)
{   
    if (digitalRead(_nfault) == LOW) // if nfault pin is logic low 
        { 
         digitalWrite(_nsleep, LOW);  // disable motor
        }
    //attachInterrupt(digitalPinToInterrupt(nfault), blink, CHANGE); 
}
void MotorDriver::enable (void){   
     digitalWrite(_nsleep, HIGH);
}
void MotorDriver::disable (void){   
    digitalWrite(_nsleep, LOW);
}
void MotorDriver::setduty (int8_t duty){   
    if (duty >= 0){
        digitalWrite(_pin1, HIGH);
        digitalWrite(_pin2, LOW);
        analogWrite(_pin1, duty);
    }
    if (duty <= 0){
        digitalWrite(_pin1, LOW);
        digitalWrite(_pin2, HIGH);
        analogWrite(_pin1, -duty);
    }    
}