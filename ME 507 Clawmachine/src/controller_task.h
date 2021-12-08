/** @file controller_task.h
 *    This file contains the header for a file which reads the user's 
 *    input and stores it into shared variables. It only reads once
 *    all other tasks have completed their task.
 * 
 *  @author Ashley Humpal and Michael Yiu
 *  @date   2021-Dec-06 
 */

#ifndef _CONTROLLER_TASK_H_
#define _CONTROLLER_TASK_H_

void task_controller (void* p_params); // Controller task

#endif // _CONTROLLER_TASK_H_