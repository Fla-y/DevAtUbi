#include "stdafx.h"
#include "Timer.h"
#include "App/app.h"

Timer::Timer(LogUtility& logger): isRunning(false),logger(logger)
{
}

void Timer::start(bool& hasStarted)
{
    if (!isRunning && hasStarted) {
        startTime = std::chrono::high_resolution_clock::now();
        isRunning = true;
    }
}

void Timer::stop()
{
    if (isRunning) {
        endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
        logger.LogGameDuration(duration);
        isRunning = false;
    }
}

void Timer::print()
{   
    float x = 790.0f, y = 730.0f;

    if (isRunning) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
        std::string timeString = "Time: " + std::to_string(elapsedTime) + " seconds";
        App::Print(x, y, timeString.c_str(), 0.0f, 0.0f, 0.0f, GLUT_BITMAP_9_BY_15); // 0.0f->black
    }
    else {
        auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
        std::string timeString = "Time: " + std::to_string(elapsedTime) + " seconds";
        App::Print(x, y, timeString.c_str(), 0.0f, 0.0f, 0.0f, GLUT_BITMAP_9_BY_15);
    }
}
