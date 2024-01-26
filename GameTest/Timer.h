#ifndef TIMER_H
#define TIMER_H

#include "stdafx.h"
#include "app/app.h"
#include "LogUtility.h"
#include "filePath.h"

class Timer
{
public:
    Timer(LogUtility& logger);
    void start(bool& hasStarted);
    void stop();
    void print();

private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;
    bool isRunning;
    LogUtility& logger;

};

#endif 