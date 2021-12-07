/** @file shares.h
 *  This file contains extern declarations of shares and queues.
 *
 *  @author Ashley Humpal and Michael Yiu
 *  @date   2021-Dec-06
 */

#ifndef _QUEUES_H_
#define _QUEUES_H_

#include "taskshare.h"
#include "taskqueue.h"

// A queue which triggers the Y_Motor_Task to begin
extern Queue<uint16_t> queue_x_task;
// A queue which triggers the Z_Motor_Task to begin
extern Queue<uint16_t> queue_y_task;
// A queue which triggers the Gripper_Motor_Task to begin
extern Queue<uint16_t> queue_z_task;

// A share that contains the desired x location
extern Share<uint16_t> share_x_position;
// A share that contains the desired y location
extern Share<uint16_t> share_y_position;
// A share that contains the status of the X_Motor_Task
extern Share<uint16_t> share_x_job_status;
// A share that contains the status of the Y_Motor_Task
extern Share<uint16_t> share_y_job_status;
// A share that contains the status of the Z_Motor_Task
extern Share<uint16_t> share_z_job_status;
// A share that contains the status of the Gripper_Motor_Task
extern Share<uint16_t> share_gripper_job_status;

#endif // _QUEUES_H_