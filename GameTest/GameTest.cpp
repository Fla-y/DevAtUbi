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
#include "Physics.h"
#include "LevelBuilder.h"
#include "FileReader.h"
#include "BackgroundBuilder.h"
#include "AnimationManager.h"
#include "LogUtility.h"

//------------------------------------------------------------------------
std::unique_ptr<Player> playerPtr;
std::vector<std::vector<int>> levelData;
std::unique_ptr<BackgroundBuilder> myBackgroundBuilder;

LogUtility logger("game_log.txt", "critical_log.txt");
AnimationManager animManager;


//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	animManager.InitializePlayer();
	myBackgroundBuilder = std::make_unique<BackgroundBuilder>();
	playerPtr = std::make_unique <Player>(logger, animManager);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	playerPtr->Move(deltaTime);
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
	if (myBackgroundBuilder) {
		myBackgroundBuilder->Draw();
	}
	playerPtr->sprite->Draw();
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