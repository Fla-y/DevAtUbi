#include "stdafx.h"
#include "LevelBuilder.h"
#include "app\app.h"
#include "FileReader.h" 

//
//void LevelBuilder::LoadLevel(const std::string& filePath) {
//    FileReader levelFile(filePath);
//    std::vector<char> fileContents = levelFile.fileReaderMethod();
//    ParseLevelData(fileContents);
//}
//
//void LevelBuilder::ParseLevelData(const std::vector<char>& levelData) {
//    for (char c : levelData) {
//        if (c == '0') {
//        }
//        else if (c == '1') {
//        }
//        else if (c == '2') {
//        }
//        else if (c == '3') {
//        }
//        else if (c == '@') {
//        }
//    }
//}
//
//void LevelBuilder::RenderLevel() {
//}
//
//
//LevelBuilder::LevelBuilder(bool& isInitSuccessful, LogUtility& logger, ObjectPool& pool) : logger(logger), hammerPool(pool)
//{
//    levelFilePaths = { LEVEL1,LEVEL2,LEVEL3 };
//    GetRandomLevel(levelFilePaths);
//}
//
//void LevelBuilder::GetRandomLevel(std::vector<std::filesystem::path> levelFilePaths) {
//    fileName = GetRandomLevelPath();
//    levelData = fileReader.fileReaderMethod(fileName);
//}
//
//std::filesystem::path LevelBuilder::GetRandomLevelPath()
//{
//    // Ensure that the vector is not empty
//    if (levelFilePaths.empty()) {
//        std::cerr << "Error: Failed to initialize level" << std::endl;
//        logger.LogCriticalError("level vector is empty");
//    }
//
//    // Create a random number generator
//    std::random_device rd;  // seed for the random number engine
//    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
//    std::uniform_int_distribution<> distrib(0, levelFilePaths.size() - 1);
//
//    int randomIndex = distrib(gen);
//    return levelFilePaths[randomIndex];
//}
//
//std::vector<char> LevelBuilder::GetLevelData()
//{
//    return levelData;
//}
//
//void LevelBuilder::processLevelData()
//{
//    // Iterate over each character in levelData
//    for (char c : levelData) {
//        switch (c) {
//        case '1':
//            // Process for '1'
//            break;
//        case '0':
//            // Process for '0'
//            break;
//        case '2':
//            // Process for '2'
//            break;
//        case '3':
//            // Process for '3'
//            break;
//        case '@':
//            NewRandomLevel();
//            break;
//        default:
//            // Process for other characters
//            break;
//        }
//        randomSleep();
//    }
//}
//
//void LevelBuilder::randomSleep()
//{
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distrib(1, 3); // For three intervals
//
//    int choice = distrib(gen);
//    std::chrono::milliseconds sleepDuration;
//
//    switch (choice) {
//    case 1: // Short interval
//        sleepDuration = std::chrono::milliseconds(100);
//        break;
//    case 2: // Medium interval
//        sleepDuration = std::chrono::milliseconds(500);
//        break;
//    case 3: // Long interval
//        sleepDuration = std::chrono::milliseconds(1000);
//        break;
//    }
//
//    std::this_thread::sleep_for(sleepDuration);
//}
//
//void LevelBuilder::NewRandomLevel()
//{
//    fileName = GetRandomLevelPath();
//    levelData = fileReader.fileReaderMethod(fileName);
//    processLevelData();
//}
//
//
///// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//LevelBuilder::LevelBuilder(bool& isInitSuccessful, LogUtility& logger, ObjectPool& pool) : logger(logger), hammerPool(pool)
//{
//    levelFilePaths = { LEVEL1,LEVEL2,LEVEL3 };
//    GetRandomLevel(levelFilePaths);
//}
//
//void LevelBuilder::GetRandomLevel(std::vector<std::filesystem::path> levelFilePaths) {
//    fileName = GetRandomLevelPath();
//    levelData = fileReader.fileReaderMethod(fileName);
//}
//
//std::filesystem::path LevelBuilder::GetRandomLevelPath()
//{
//    // Ensure that the vector is not empty
//    if (levelFilePaths.empty()) {
//        std::cerr << "Error: Failed to initialize level" << std::endl;
//        logger.LogCriticalError("level vector is empty");
//    }
//
//    // Create a random number generator
//    std::random_device rd;  // seed for the random number engine
//    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
//    std::uniform_int_distribution<> distrib(0, levelFilePaths.size() - 1);
//
//    int randomIndex = distrib(gen);
//    return levelFilePaths[randomIndex];
//}
//
//std::vector<char> LevelBuilder::GetLevelData()
//{
//    return levelData;
//}
//
//void LevelBuilder::processLevelData()
//{
//    // Iterate over each character in levelData
//    for (char c : levelData) {
//        switch (c) {
//        case '1':
//            // Process for '1'
//            break;
//        case '0':
//            // Process for '0'
//            break;
//        case '2':
//            // Process for '2'
//            break;
//        case '3':
//            // Process for '3'
//            break;
//        case '@':
//            NewRandomLevel();
//            break;
//        default:
//            // Process for other characters
//            break;
//        }
//        randomSleep();
//    }
//}
//
//void LevelBuilder::randomSleep()
//{
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> distrib(1, 3); // For three intervals
//
//    int choice = distrib(gen);
//    std::chrono::milliseconds sleepDuration;
//
//    switch (choice) {
//    case 1: // Short interval
//        sleepDuration = std::chrono::milliseconds(100);
//        break;
//    case 2: // Medium interval
//        sleepDuration = std::chrono::milliseconds(500);
//        break;
//    case 3: // Long interval
//        sleepDuration = std::chrono::milliseconds(1000);
//        break;
//    }
//
//    std::this_thread::sleep_for(sleepDuration);
//}
//
//void LevelBuilder::NewRandomLevel()
//{
//    fileName = GetRandomLevelPath();
//    levelData = fileReader.fileReaderMethod(fileName);
//    processLevelData();
//}
