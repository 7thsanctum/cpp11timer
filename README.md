# C++11 Timer Class
A simple C++11 timer class that uses &lt;chrono> for measuring the time between two points. Just now all it requires is including this header.

example.cpp contains an example of how you would use it.

The basic functionality of this timer works as follow.

Instance the timer somewhere:
```
	Timer your_timer_name;
```

Then create a start point for the timer:
```
	your_timer_name.Start();
```

This will take the current time and store it as part of the Timer object. It will also mark a bool "stopped" as FALSE to indicate the timer has been started. Everytime you call .Start() it will make that the new point. After this point do all your processing or whatever it is you are timing.

Create the end point:
```
	your_timer_name.End();
```

By calling .End() this will store the current time as the end point. It will also mark the bool "stopped" as TRUE to indicate you have called the .End() function and that the timer is no longer being called. 

Get the duration of the timer:
```
	your_timer_name.Get_Duration();
```

This will return the value of your timer as a long long in milliseconds. If you call this before calling .End() it will throw a message up to say you haven't called .End() before getting the duration. It will still return the time between when you called the function and start however but won't save it as part of your timer. This is only really important if you needed to measure between two points and forgot to place .End() somewhere so it will just be empty, thus acts as a reminder that you need to call .End().


TODO:
Getters for private variables
Expose total function so you can make your own precision
template so that different precisions can be used e.g. nano instead of milli seconds
Option to disable the start/end warning thing