/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"

/**
 * Constructor that sets *vec to &finished_vector
 * and all other fields to 0
 */
Stats::Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;
	av_wait_time = 0;
	av_turnaround_time = 0;
	av_response_time = 0;
}

void Stats::showAllProcessInfo(){

}

/**
 * create variables to calculate total time then divide by vector.size()
 * wait time = finish time - arrival time - required CPU time
 * turnaround time = finish time - arrival time
 * response time = start time - arrival time
 * store all averages in Stats field variables
 */
void Stats::calcStats(){
	float totalWaitTime = 0.0;
	float totalTurnaroundTime = 0.0;
	float totalResponseTime = 0.0;

	for (int i = 0; i < (signed)vec->size(); i++){
		totalWaitTime += vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time;
		totalTurnaroundTime += vec->at(i).finish_time - vec->at(i).arrival_time;
		totalResponseTime += vec->at(i).start_time - vec->at(i).arrival_time;
	}

	av_wait_time       = totalWaitTime / vec->size();
	av_turnaround_time = totalTurnaroundTime / vec->size();
	av_response_time   = totalResponseTime / vec-> size();

}

/**
 * response time = (start time - arrival time)
 */
float Stats::get_av_response_time(){
	calcStats();
	return av_response_time;
}

/**
 * turnaround time = (finish time - arrival time)
 */
float Stats::get_av_turnaround_time(){
	calcStats();
	return av_turnaround_time;
}
float Stats::get_av_wait_time(){
	calcStats();
	return av_wait_time;
}

