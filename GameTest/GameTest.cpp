//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
#include <windows.h>
#include <crtdbg.h>
#include "app\app.h"
#include "Player.h"
#include "Map.h"
#include "AnimationManager.h"
#include "LogUtility.h"
#include "CollisionManager.h"
#include "Object.h"
#include "GameStateManager.h"
#include "ObjectPool.h"

//------------------------------------------------------------------------
std::unique_ptr<Player> playerPtr;
std::unique_ptr<Map> levelMap;
std::unique_ptr<Object> hammerPtr;

bool isInitSuccessful = true;
LogUtility logger("game_log.txt", "critical_log.txt");
AnimationManager animManager;

std::unique_ptr<GameStateManager> gameStateManager;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	animManager.InitializePlayer();
	animManager.InitializeHammer();
	levelMap = std::make_unique <Map>(logger, animManager, isInitSuccessful);
	playerPtr = std::make_unique <Player>(logger, animManager,isInitSuccessful);
	//hammerPtr = std::make_unique <Object>(logger, animManager,isInitSuccessful); 


}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	if (!isInitSuccessful) {
		return; 
	}
	playerPtr->Move(deltaTime);
	//hammerPtr->Animate(deltaTime);
	levelMap->Update(deltaTime);

	auto& hammerPool = levelMap->GetHammerPool(); // Get the hammer pool
	auto activeHammers = hammerPool.GetActiveObjects(); // Get active hammers
	for (const auto& hammer : activeHammers) {
		if (playerPtr->CheckCollision(hammer->GetCollisionManager())) {
			playerPtr->TriggerDeath();
			break; // Exit the loop as the player is dead
		}
	}

	/*if (playerPtr->CheckCollision(hammerPtr->GetCollisionManager())) {
		playerPtr->TriggerDeath();
	}*/
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
		return; 
	}
	levelMap->DrawBackground();
	playerPtr->Draw();
	levelMap->DrawFloor();
	levelMap->DrawObject();
	//hammerPtr->Draw();

	if (!(playerPtr->isAlive)) {
		App::Print(400, 400, "You are dead");
		return;
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
}

