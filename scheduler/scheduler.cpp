/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"

/**
 * add a process to the ready queue, either a new one or one that
 * had been running on the CPU and has been preempted
 * *For preemptive scheduler, need to sort processes by cpu time whenever added
 */
void Scheduler::add(PCB p){
	ready_q->push(p);

	if (preemptive){
		sort();
	}
}

/**
 * get next process
 * if queue is empty, return empty PCB
 * else, return front of queue
 */
PCB Scheduler::getNext(){
	PCB null;
	if (this->isEmpty()){
		return null;
	}
	else{
		PCB next = ready_q->front();
		ready_q->pop();
		return next;
	}
}

/**
 * returns true if there are no jobs in the readyQ
 * false otherwise
 */
bool Scheduler::isEmpty(){
	return ready_q->empty();
}

/**
 * if process has completed (used all its remaining_cpu_time) or
 * if we are using a preemptive scheduling algorithm and the
 * timeslice is over then its time to switch processes returns:
 * true - switch processes
 * false - do not switch
 */
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	int timeUsed = tick_count - p.start_time;
	return p.remaining_cpu_time <= 0 || (preemptive && timeUsed >= time_slice);
}
