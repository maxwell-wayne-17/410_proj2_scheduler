/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"
#include <vector>
#include <algorithm>

/**
 * Helper method to compare PCBs by reamining_cpu_time
 */
bool sortRemeainingCpuTime(PCB &one, PCB &two){
	return one.remaining_cpu_time < two.remaining_cpu_time;
}

/**
 * call sort method to ensure ready_q is prioritized properly
 * call superclass function
 */
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

/**
 * creates a temporary vector to store values
 * empty queue into temporary vector
 * call std::sort on vector with helper method
 * push PCB back into queue in least remaining cpu time order
 */
void Scheduler_SRTF::sort(){

	std::vector<PCB> temp;
	while (!isEmpty()){
		temp.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(temp.begin(), temp.end(), sortRemeainingCpuTime);

	for (PCB p : temp){
		ready_q->push(p);
	}


}
