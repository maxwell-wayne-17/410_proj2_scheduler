/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU(){

	PCB currentProcess = cpu->get_process_off_core();
	is_valid_job_on_cpu = currentProcess.isEmpty();
	return currentProcess;
}

void Dispatcher::put_on_CPU(PCB &process){
	cpu->get_process_off_core();
	cpu->put_process_on_core(process);
	is_valid_job_on_cpu = true;
}

bool Dispatcher::isValidJobOnCPU(){
	return is_valid_job_on_cpu;
}

