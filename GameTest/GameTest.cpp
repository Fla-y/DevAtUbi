//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
#include "Player.h"
#include "LevelBuilder.h"
#include "FileReader.h"

//------------------------------------------------------------------------
std::unique_ptr<Player> playerPtr;
std::vector<std::vector<int>> levelData;
//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	// Read the level file and build the level
	std::string filePath = ".\\level1.txt";
	FileReader levelFile (filePath);
	std::vector<char> fileContents = levelFile.fileReaderMethod();

	LevelBuilder levelBuilder(fileContents);
	levelBuilder.BuildLevel(fileContents,levelData);

	// Retrieve the level data
	levelData = levelBuilder.GetLevel();
	playerPtr = std::make_unique <Player>();

}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	playerPtr->Walk(deltaTime);
	//playerPtr->Jump(deltaTime);
	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	{
		App::PlaySound(".\\TestData\\Test.wav");
	}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	playerPtr->testSprite->Draw();
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Example Text.
	//------------------------------------------------------------------------
	//App::Print(100, 100, "Sample Text");

	
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
}