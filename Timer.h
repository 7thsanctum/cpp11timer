#pragma once
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

// TODO: Allow specifying of precision, e.g. milliseconds vs nanoseconds, currently fixed with milliseconds
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

	time_point<system_clock, system_clock::duration> start;				// Get start time;
	time_point<system_clock, system_clock::duration> end;				// Get start time;
	duration<system_clock::rep, system_clock::period> total();
};

Timer::Timer()
{
	stopped = true;
}

Timer::~Timer(){}

void Timer::Start()
{
	start = system_clock::now();		// Get start time
	stopped = false;
}

void Timer::End()
{
	end = system_clock::now();			// Get end time 		
	stopped = true;
}

duration<system_clock::rep, system_clock::period> Timer::total()
{
	if (!stopped)
	{
		//TODO: Workout a good way to do this.
		cout << "Timer wasn't stopped before trying to work out the total!" << endl;
		return system_clock::now() - start;
	}

	return end - start;
}

long long Timer::Get_Duration()
{
	return duration_cast<milliseconds>(total()).count();
}