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
#include "filePath.h"
#include "Timer.h"


//------------------------------------------------------------------------
std::unique_ptr<Player> playerPtr;
std::unique_ptr<Map> levelMap;
std::unique_ptr<Object> hammerPtr;/*
std::unique_ptr<Object> hammerPtr2;
std::unique_ptr<Object> hammerPtr3;*/

bool isInitSuccessful = true;
LogUtility logger("game_log.txt", "critical_log.txt");
AnimationManager animManager;
int loopCounter = 0;
std::unique_ptr<GameStateManager> gameStateManager;
Timer gameTime(logger);
float SCROLL_SPEED = 0.25f;


//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	animManager.InitializePlayer();
	animManager.InitializeHammer();
	levelMap = std::make_unique <Map>(logger, isInitSuccessful,loopCounter,SCROLL_SPEED);
	playerPtr = std::make_unique <Player>(logger, animManager,isInitSuccessful);
	hammerPtr = std::make_unique <Object>(logger, animManager,isInitSuccessful,loopCounter,SCROLL_SPEED);
	/*hammerPtr2 = std::make_unique <Object>(logger, animManager, isInitSuccessful);
	hammerPtr3 = std::make_unique <Object>(logger, animManager, isInitSuccessful);*/
	hammerPtr->hammer->SetPosition(1024.0f, 98.0f);
	App::PlaySound(SOUNDTRACK.string().c_str());
	gameTime.start();
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
	hammerPtr->Animate(deltaTime);
	levelMap->Update(deltaTime);

	if (playerPtr->CheckCollision(hammerPtr->GetCollisionManager())) {
		playerPtr->TriggerDeath();
		gameTime.stop();
		if (App::IsSoundPlaying(SOUNDTRACK.string().c_str()) || App::IsSoundPlaying(YOU_ARE_DEAD.string().c_str())) {
			App::StopSound(SOUNDTRACK.string().c_str());
			if (!App::IsSoundPlaying(YOU_ARE_DEAD.string().c_str())) {
				App::PlaySound(YOU_ARE_DEAD.string().c_str());
			}
		}
	}
	
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
	hammerPtr->Draw();
	if (!(playerPtr->isAlive)) {
		App::Print(400, 400, "You are dead");
		return;
	}
	gameTime.print();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
}

