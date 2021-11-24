/** @file shares.h
 *  This file contains extern declarations of shares and queues which are used
 *  in more than one file of a demonstration project.
 * 
 *  @author JR Ridgely
 *  @date   2021-Oct-23 Original file
 *  @copyright (c) 2021 by JR Ridgely, released under the LGPL 3.0. 
 */

#ifndef _SHARES_H_
#define _SHARES_H_

//#include "encoder_counter.h"
//#include "motor_driver.h"
#include "taskshare.h"// im not sure about this but in ridgley simple shares canvas ex he had this so i emailed him and am waiting

// A share which holds a counter of how many times a simulated event occurred
extern Share<uint16_t> share_encoder_positionx;

extern Share<uint16_t> share_encoder_positiony;

extern Share<uint16_t> share_user_positionx; // will be from controller.cpp frontend 

extern Share<uint16_t> share_user_positiony;

// A queue which triggers a task to print the count at certain times
//extern Queue<uint16_t> data_queue;


#endif // _SHARES_H_