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
#include "CollisionManager.h"
#include "Object.h"

//------------------------------------------------------------------------
std::unique_ptr<Player> playerPtr;
std::vector<std::vector<int>> levelData;
std::unique_ptr<BackgroundBuilder> myBackgroundBuilder;
std::unique_ptr<Object> hammerPtr;

LogUtility logger("game_log.txt", "critical_log.txt");
AnimationManager animManager;
CollisionManager collManager();


//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	animManager.InitializePlayer();
	animManager.InitializeHammer();
	myBackgroundBuilder = std::make_unique <BackgroundBuilder>();
	playerPtr = std::make_unique <Player>(logger, animManager);
	hammerPtr = std::make_unique <Object>(logger, animManager); 
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	playerPtr->Move(deltaTime);
	//hammerPtr->Animate();
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
	//hammerPtr->Animate();
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