
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
#include "filePath.h"
#include "Timer.h"
#include "Object.h"


std::unique_ptr<Player> playerPtr;
std::unique_ptr<Map> levelMap;
std::unique_ptr<Obstacle> hammerPtr;
std::unique_ptr<Object> boxPtr;

int boxCollected, totalBox;
bool isInitSuccessful = true;
LogUtility logger("game_log.txt", "critical_log.txt");
AnimationManager animManager;
int loopCounter = 0;
Timer gameTime(logger);
float SCROLL_SPEED = 0.25f;
bool startGame,endScreen;


void Init()
{
	animManager.InitializePlayer();
	animManager.InitializeHammer();
	animManager.InitializeBox();

	levelMap = std::make_unique <Map>(logger, isInitSuccessful,loopCounter,SCROLL_SPEED);
	playerPtr = std::make_unique <Player>(logger, animManager,isInitSuccessful);
	hammerPtr = std::make_unique <Obstacle>(logger, animManager,isInitSuccessful,loopCounter,SCROLL_SPEED);
	boxPtr = std::make_unique<Object>(logger, animManager, isInitSuccessful,SCROLL_SPEED);
	
	startGame = false;
	boxCollected = 0;
	totalBox = 0;
	endScreen = false;

	App::PlaySound(SOUNDTRACK.string().c_str(), true);
}


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
		if (playerPtr->isAlive) {
			playerPtr->Move(deltaTime);
			hammerPtr->Animate(deltaTime);
			levelMap->Update(deltaTime);

			boxPtr->isActive = true;
			boxPtr->FollowHammer(deltaTime);
			if (playerPtr->CheckCollision(boxPtr->GetCollisionManager()) && !boxPtr->isCollected) {
				boxCollected++;
				totalBox++;
				boxPtr->isCollected = true;
			}

			if (boxCollected >= 5) {
				boxCollected = 0;
				playerPtr->TriggerPowerUp();
			}
			if (std::chrono::steady_clock::now() - playerPtr->startTime >= playerPtr->duration) {
				playerPtr->isInvincible = false; // Reset the flag after 5 seconds
			}

			if (playerPtr->CheckCollision(hammerPtr->GetCollisionManager()) && !playerPtr->isInvincible) {
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
		else {
			if (App::IsKeyPressed(VK_RETURN)) {
				exit(0); // Close the game
			}
		}
	}
}


void Render()
{
	if (!isInitSuccessful) {
		App::Print(380, 400, "Initialization Failed! Please restart the game.");
		return; 
	}

	if (!(playerPtr->isAlive)) {
		App::Print(420, 400, "You are dead", 1.0f, 1.0f, 1.0f, GLUT_BITMAP_9_BY_15);
		std::string countStr = "Total Boxes collected: " + std::to_string(totalBox);
		App::Print(380.0f, 380.0f, countStr.c_str(), 1.0f, 1.0f, 1.0f, GLUT_BITMAP_9_BY_15);
		return;
	}
	else {

		levelMap->DrawBackground();
		playerPtr->Draw();
		levelMap->DrawFloor();
		hammerPtr->Draw();
		boxPtr->Draw();
		gameTime.print();

		std::string countStr = "Box collected: " + std::to_string(totalBox);
		App::Print(98.0f, 730.0f, countStr.c_str(), 0.0f, 0.0f, 0.0f, GLUT_BITMAP_9_BY_15);

		if (playerPtr->isInvincible) {
			App::Print(380.0f, 500.0f, "Power-up unlocked, you are Invincible!", 0.0f, 0.0f, 0.0f, GLUT_BITMAP_9_BY_15);
		}

		if (!startGame) {
			App::Print(400.0f, 400.0f, "Press the Space bar to start!", 0.0f, 0.0f, 0.0f, GLUT_BITMAP_9_BY_15);
			App::Print(380.0f, 340.0f, "Press 'W' to jump, 'A' and 'D' to move ", 0.0f, 0.0f, 0.0f, GLUT_BITMAP_8_BY_13);
		}
	}
	
}

void Shutdown()
{
}

