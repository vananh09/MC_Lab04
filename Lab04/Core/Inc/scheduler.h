/*
 * scheduler.h
 *
 *  Created on: Dec 2, 2021
 *      Author: Dell
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "main.h"

typedef struct {
    // Pointer to the task (must be a 'void (void)' function)
	void ( * pTask)(void);
	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;
	// Interval (ticks) between subsequent runs.
	uint32_t Period;
	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;
	//TaskID use to show the task is running
	uint32_t TaskID;
} sTask;

typedef struct{
	// Pointer to task
	void (*pTask)(void);
	// Id task
	uint8_t TaskID;
} qTask;

enum Error{
	FREE_OF_ERROR,
	ERROR_SCH_TOO_MANY_TASKS,
	ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK,
	ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER,
	ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START,
	ERROR_SCH_LOST_SLAVE,
	ERROR_SCH_CAN_BUS_ERROR,
	ERROR_I2C_WRITE_BYTE_AT24C64,
	ERROR_SCH_CANNOT_DELETE_TASK
};

#define SCH_MAX_TASKS 	5
#define QUEUE_MAX_TASKS 		10
#define NO_TASK_ID 		0
#define _SUCCESS_ 		1
#define _ERROR_ 		0
#define TIMER_CYCLE 	10

sTask SCH_tasks_G[SCH_MAX_TASKS];
qTask QUEUE_Tasks_G[QUEUE_MAX_TASKS];

uint32_t Error_code_G;

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pfunction)(void), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);
void SCH_Shift_Right(uint32_t Index, int typeArr);
void SCH_Shift_Left(uint32_t Index, int typeArr);
uint32_t qpush(sTask task);
uint8_t qpop();

void Timer_Init();
void Watchdog_Init();
void SCH_Report_Status();
void SCH_Go_To_Sleep();
#endif /* INC_SCHEDULER_H_ */
