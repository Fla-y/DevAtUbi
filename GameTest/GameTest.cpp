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
#include "Obstacle.h"
#include "GameStateManager.h"
#include "filePath.h"
#include "Timer.h"


//------------------------------------------------------------------------
std::unique_ptr<Player> playerPtr;
std::unique_ptr<Map> levelMap;
std::unique_ptr<Obstacle> hammerPtr;/*
std::unique_ptr<Obstacle> hammerPtr2;
std::unique_ptr<Obstacle> hammerPtr3;*/

bool isInitSuccessful = true;
LogUtility logger("game_log.txt", "critical_log.txt");
AnimationManager animManager;
int loopCounter = 0;
std::unique_ptr<GameStateManager> gameStateManager;
Timer gameTime(logger);
float SCROLL_SPEED = 0.25f;
bool startGame;


//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	animManager.InitializePlayer();
	animManager.InitializeHammer();
	levelMap = std::make_unique <Map>(logger, isInitSuccessful,loopCounter,SCROLL_SPEED);
	playerPtr = std::make_unique <Player>(logger, animManager,isInitSuccessful);
	hammerPtr = std::make_unique <Obstacle>(logger, animManager,isInitSuccessful,loopCounter,SCROLL_SPEED);
	/*hammerPtr2 = std::make_unique <Obstacle>(logger, animManager, isInitSuccessful);
	hammerPtr3 = std::make_unique <Obstacle>(logger, animManager, isInitSuccessful);*/
	//hammerPtr->hammer->SetPosition(1024.0f, 98.0f);
	App::PlaySound(SOUNDTRACK.string().c_str());
	startGame = false;
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
	if (!startGame) {
		playerPtr->ReturnToIdle(deltaTime);
		if (App::IsKeyPressed(VK_SPACE)) {
			startGame = true;
			gameTime.start(startGame);
		}
	}
	else {

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

	if (!startGame) {
		App::Print(400.0f, 400.0f, "Press the Space bar to start!", 0.0f, 0.0f, 0.0f, GLUT_BITMAP_9_BY_15);
		App::Print(380.0f, 340.0f, "Press 'W' to jump, 'A' and 'D' to move ", 0.0f, 0.0f, 0.0f, GLUT_BITMAP_8_BY_13);
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{
}

