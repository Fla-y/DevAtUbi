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
#include "Map.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"
#include "Object.h"

//------------------------------------------------------------------------
std::unique_ptr<Player> playerPtr;
std::vector<std::vector<int>> levelData;
std::unique_ptr<Map> myMap;
std::unique_ptr<Object> hammerPtr;

bool isInitSuccessful = true;
LogUtility logger("game_log.txt", "critical_log.txt");
AnimationManager animManager;
CSimpleSprite* sprite;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	animManager.InitializePlayer();
	animManager.InitializeHammer();
	myMap = std::make_unique <Map>(logger, isInitSuccessful);
	playerPtr = std::make_unique <Player>(logger, animManager,isInitSuccessful);
	hammerPtr = std::make_unique <Object>(logger, animManager,isInitSuccessful); 
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	if (!isInitSuccessful) {
		return;  // Skip updating game logic
	}
	playerPtr->Move(deltaTime);
	hammerPtr->Animate(deltaTime);
	myMap->Update(deltaTime);

	if (playerPtr->CheckCollision(hammerPtr->GetCollisionManager())) {
		playerPtr->TriggerDeath();
	}
	////------------------------------------------------------------------------
	//// Sample Sound.
	////------------------------------------------------------------------------
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
	//{
	//	App::PlaySound(".\\TestData\\Test.wav");
	//}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{
	if (!isInitSuccessful) {
		App::Print(400, 400, "Initialization Failed! Please restart the game.");
		return;  // Skip rendering game logic
	}
	myMap->DrawBackground();
	myMap->DrawFloor();
	playerPtr->Draw();
	hammerPtr->Draw();

}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
	delete sprite;
}

