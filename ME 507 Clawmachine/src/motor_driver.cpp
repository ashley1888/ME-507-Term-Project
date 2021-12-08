/** @file motor_driver.cpp
 *    This file contains code for a class that serves as a motor driver with methods to enable, disable, and
 *    set the duty cycle of a motor. It also includes a method for fault detection.
 * 
 *  @author Ashley Humpal and Michael Yiu 
 *  @date   2021-Dec-06 
 */
#include <Arduino.h>
#include <PrintStream.h>
#include "motor_driver.h"


/** @brief   Creates a constructor for the class that initializes variables for zero data.
 *  @details This constructor takes various pins in as parameters.
 *  @param   pin1 Pin representing the motor positive lead
 *  @param   pin2 Pin representing the motor negative lead
 *  @param   nsleep Pin representing the nsleep pin for power
 *  @param   nfault Pin representing the motor nfault pin
 */
MotorDriver::MotorDriver (uint8_t pin1, uint8_t pin2, uint8_t nsleep, uint8_t nfault)
{  _nsleep = nsleep; // Creating local variables
   _pin1 = pin1;
   _pin2 = pin2;
   _nfault = nfault;
   
    pinMode(_pin1, OUTPUT);  // Initializing pins
    pinMode(_pin2, OUTPUT); 
    pinMode(_nsleep, OUTPUT); 
    pinMode(nfault, INPUT_PULLUP); 
}

/** @brief   Method to detect if motor has faulted.
 *  @details Takes no parameters in and turns off motor if fault detected.
 */
void MotorDriver::faulted (void)
{   
    if (digitalRead(_nfault) == LOW) // If nfault pin is logic low 
        { 
         digitalWrite(_nsleep, LOW);  // Disable motor
        }
}

/** @brief   Method to turn on motor.
 *  @details Takes no parameters in and sets pin high.
 */
void MotorDriver::enable (void)
{   
     digitalWrite(_nsleep, HIGH); // Set pin high to turn on motor
}

/** @brief   Method to turn off motor.
 *  @details Takes no parameters in and sets pin low.
 */
void MotorDriver::disable (void)
{   
    digitalWrite(_nsleep, LOW); // Set pin low to turn off motor
}

/** @brief   Method to set motor duty cycle.
 *  @details Accounts for range of duty cycle values.
 *  @param   duty  The duty cycle the motor is operating at
 */
void MotorDriver::setduty (int8_t duty)
{   
    if (duty > 0){
        digitalWrite(_pin1, HIGH); // motor runs counterclockwise
        digitalWrite(_pin2, LOW);
        analogWrite(_pin1, duty);
    }
    if (duty < 0){
        digitalWrite(_pin1, LOW); // motor runs clockwise
        digitalWrite(_pin2, HIGH);
        analogWrite(_pin1, -duty);
    }
    if(duty == 0)
    {
        digitalWrite(_pin1, LOW); // motor stops
        digitalWrite(_pin2, LOW);
        analogWrite(_pin1, duty);
    }
}