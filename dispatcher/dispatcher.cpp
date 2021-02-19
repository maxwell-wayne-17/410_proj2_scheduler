/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"

/**
 * Pull process off core
 * update is_valid_job_on_cpu by checking if pulled process is empty
 * return pulled process
 */
PCB Dispatcher::get_from_CPU(){
	PCB currentProcess = cpu->get_process_off_core();
	is_valid_job_on_cpu = currentProcess.isEmpty();
	return currentProcess;
}

/**
 * pull process off core then place new process
 * update is_valid_job_on_cpu to true
 */
void Dispatcher::put_on_CPU(PCB &process){
	cpu->get_process_off_core();
	cpu->put_process_on_core(process);
	is_valid_job_on_cpu = true;
}

/**
 * check is_valid_job_on_cpu to see if core is empty
 */
bool Dispatcher::isValidJobOnCPU(){
	return is_valid_job_on_cpu;
}

