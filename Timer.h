#pragma once
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

template <class T>
class Timer
{
public:
	Timer();
	~Timer();

	void Start();
	void End();

	long long Get_Duration();

private:
	bool stopped;

	time_point<system_clock, system_clock::duration> start;			// start time;
	time_point<system_clock, system_clock::duration> end;			// end time;
	duration<system_clock::rep, system_clock::period> total();		// Function for calculating the time difference between start and end
};

template <class T>
Timer<T>::Timer()
{
	stopped = true;
}

template <class T>
Timer<T>::~Timer(){}

template <class T>
void Timer<T>::Start()
{
	start = system_clock::now();	// Set start time to current time
	stopped = false;
}

template <class T>
void Timer<T>::End()
{
	end = system_clock::now();		// Set end time to current time		
	stopped = true;
}

template <class T>
duration<system_clock::rep, system_clock::period> Timer<T>::total()
{
	if (!stopped)
	{
		//TODO: Workout a good way to do this.
		cout << "Timer wasn't stopped before trying to work out the duration!" << endl;
		return system_clock::now() - start;
	}

	return end - start;
}

template <class T>
long long Timer<T>::Get_Duration()
{
	return duration_cast<T>(total()).count();
}