#ifndef LOG_UTILITY_H
#define LOG_UTILITY_H

#include "stdafx.h"
#include <chrono>
#include <ctime>



class LogUtility
{
public:
	LogUtility(const std::string& normalLog, const std::string& criticalLog);
	void LogError(const std::string& errorMessage);
	void LogCriticalError(const std::string& errorMessage);
	void LogGameDuration(long long durationSeconds);

private:
	std::string logFileName;
	std::string criticalLogFileName;

	std::string GetCurrentTimeFormatted();
	void CreateLogFile(const std::string& fileName, bool append );
	void WriteLog(const std::string& fileName, const std::string& message);
};

#endif
