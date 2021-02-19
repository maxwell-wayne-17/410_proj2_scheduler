/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "../includes/scheduler_FIFO.h"

/**
 * switch process only if process is done
 * return true if process's remaining cpu time is <= 0
 * return false otherwise
 */
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	return p.remaining_cpu_time <= 0;
}

/**
 * FIFO - not preemptive - no sorting needed
 */
void Scheduler_FIFO::sort(){

}
