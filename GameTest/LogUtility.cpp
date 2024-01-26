#include "stdafx.h"
#include "LogUtility.h"

LogUtility::LogUtility(const std::string& normalLog, const std::string& criticalLog) : logFileName(normalLog), criticalLogFileName(criticalLog) {
    CreateLogFile(logFileName, false);         // Overwrite normal log file
    CreateLogFile(criticalLogFileName, true);  // Append to critical log file
}

void LogUtility::LogError(const std::string& errorMessage)
{
    WriteLog(logFileName, errorMessage);
}

void LogUtility::LogCriticalError(const std::string& errorMessage)
{
    WriteLog(criticalLogFileName, errorMessage);
}

void LogUtility::LogGameDuration(long long durationSeconds)
{
    std::string durationLogFileName = "game_duration_log.txt";

    CreateLogFile(durationLogFileName, true); // Create or append to the file
    std::ofstream logFile(durationLogFileName, std::ios::app); // Open in append mode
    if (logFile.is_open()) {
        logFile << "[" << GetCurrentTimeFormatted() << "] Game Duration: " << durationSeconds << " seconds" << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Unable to open duration log file: " << durationLogFileName << std::endl;
    }
}

std::string LogUtility::GetCurrentTimeFormatted()
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::string timeStr = std::ctime(&time);
    timeStr.pop_back(); // Remove the newline character
    return timeStr;
}

void LogUtility::CreateLogFile(const std::string& fileName, bool append)
{
    std::ofstream logFile;
    if (append) {
        logFile.open(fileName, std::ios::app); // Open in append mode
    }
    else {
        logFile.open(fileName); // Open in default mode (overwrite)
    }
    if (!logFile.is_open()) {
        std::cerr << "Failed to create log file: " << fileName << std::endl;
    }
    logFile.close();
}

void LogUtility::WriteLog(const std::string& fileName, const std::string& message)
{
    std::ofstream logFile(fileName, std::ios::app); // Open in append mode
    if (logFile.is_open()) {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::string timeStr = std::ctime(&time);
        timeStr.pop_back(); // Remove the newline character

        logFile << "[" << timeStr << "] " << message << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "Unable to open log file: " << fileName << std::endl;
    }
}
