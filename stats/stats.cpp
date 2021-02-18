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

float Stats::get_av_response_time(){
	return 0.0;
}

float Stats::get_av_turnaround_time(){
	return 0.0;
}
float Stats::get_av_wait_time(){
	return 0.0;
}

