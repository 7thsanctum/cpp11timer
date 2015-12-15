#include <iostream>
#include <chrono>

#include "Timer.h"

Timer<microseconds> cpp11_timer;

int main()
{
	cpp11_timer.Start();	// Get start time
	//#######################################################
	//#			Put code to time after this point			#
	//#######################################################

	for (int i = 0; i < 10000000; i++);

	//#######################################################
	//#			Put code to time before this point			#
	//#######################################################
	cpp11_timer.End();		// Get end time
	std::cout << "Time taken : " << cpp11_timer.Get_Duration() << std::endl;

	return 0;
}