/*
 * display_task.c
 *
 *  Created on: Dec 3, 2021
 *      Author: Dell
 */

#include "display_task.h"
#include "scheduler.h"
#include "main.h"
uint8_t segmentNumber[10] = {
		0x40,  // 0
		0x79,  // 1
		0x24,  // 2
		0x30,  // 3
		0x19,  // 4
		0x12,  // 5
		0x02,  // 6
		0x78,  // 7
		0x00,  // 8
		0x10   // 9
};

void display_task(int number) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((segmentNumber[SCH_tasks_G[number].TaskID]>>0)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((segmentNumber[SCH_tasks_G[number].TaskID]>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((segmentNumber[SCH_tasks_G[number].TaskID]>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((segmentNumber[SCH_tasks_G[number].TaskID]>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((segmentNumber[SCH_tasks_G[number].TaskID]>>4)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((segmentNumber[SCH_tasks_G[number].TaskID]>>5)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((segmentNumber[SCH_tasks_G[number].TaskID]>>6)&0x01));
}
