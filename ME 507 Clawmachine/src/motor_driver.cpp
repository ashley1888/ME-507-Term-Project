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

MotorDriver::MotorDriver (uint8_t pin1, uint8_t pin2, uint8_t nsleep )
//pin1, pin2, nsleep
{  _nsleep = nsleep;
   _pin1 = pin1;
   _pin2 = pin2;


    pinMode(pin1, OUTPUT); 
    pinMode(pin2, OUTPUT); 
    pinMode(nsleep, OUTPUT); 
    //pinMode(nfault, INPUT_PULLUP) -- MAKE FUNCT FOR WHEN LOGIC LOW IT KNOWS IT FAULT AND SETS MOTOR TO DISABLE

    //uint8_t pin1;
    // sets initial values for class variables
          //The number of data points
}

void MotorDriver::enable (void)
{   
    //_nsleep.high();
     digitalWrite(_nsleep, HIGH);
}

void MotorDriver::disable (void)
{   
    digitalWrite(_nsleep, LOW);
}

void MotorDriver::setduty (uint8_t duty)
{   
    analogWrite(_pin1, duty);
}

   //analogWrite(PB0, 75);  