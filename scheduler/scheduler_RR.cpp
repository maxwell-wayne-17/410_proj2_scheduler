/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include"../includes/scheduler_RR.h"

/**
 * Switch if process has been on for time-slice length,
 * or if process is done
 * return true if process is finished, or if process has been on for a time slice
 * return false otherwise
 */
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p){

	int timeTracker = p.required_cpu_time - p.remaining_cpu_time;
	if (timeTracker % time_slice == 0 || p.remaining_cpu_time == 0){
		return true;
	}
	else{
		return false;
	}
}

/**
 * RR - not preemptive, not necessary
 */
void Scheduler_RR::sort(){

}
