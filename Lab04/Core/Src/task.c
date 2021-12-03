/*
 * task.c
 *
 *  Created on: Dec 2, 2021
 *      Author: Dell
 */

#include "main.h"

void task1() {
	HAL_GPIO_TogglePin(GPIOA, task1_Pin);
}
void task2() {
	HAL_GPIO_TogglePin(GPIOA, task2_Pin);
}
void task3() {
	HAL_GPIO_TogglePin(GPIOA, task3_Pin);
}
void task4() {
	HAL_GPIO_TogglePin(GPIOA, task4_Pin);
}
void task5() {
	HAL_GPIO_TogglePin(GPIOA, task5_Pin);
}
