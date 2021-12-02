/** @file shares.h
 *  This file contains extern declarations of shares and queues which are used
 *  in more than one file of a demonstration project.
 *
 *  @author JR Ridgely
 *  @date   2021-Oct-23 Original file
 *  @copyright (c) 2021 by JR Ridgely, released under the LGPL 3.0.
 */

#ifndef _QUEUES_H_
#define _QUEUES_H_

#include "taskshare.h"
#include "taskqueue.h"
// Example of shares in depth at https://spluttflob.github.io/ME507-Support/classShare.html

// A queue which triggers a task to print the count at certain times
extern Queue<uint16_t> queue_x_position;

extern Queue<uint16_t> queue_y_position;

extern Share<uint16_t> share_x_position;
extern Share<uint16_t> share_y_position;

extern Share<uint16_t> share_x_job_status;

extern Share<uint16_t> share_y_job_status;

extern Share<uint16_t> share_z_job_status;

extern Share<uint16_t> share_gripper_job_status;

#endif // _QUEUES_H_