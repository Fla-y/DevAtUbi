#ifndef FILE_PATH_H
#define FILE_PATH_H

#include "stdafx.h"

namespace fs = std::filesystem;

//player sprite
const fs::path PLAYER = ".\\TestData\\Robot.png";

const fs::path PLAYER_SIZE_SAMPLE = ".\\TestData\\framesPerCollision\\robot0.png";

//Hammer sprite
const fs::path HAMMER = ".\\TestData\\Hammer.png";

const fs::path HAMMER_SIZE_0 = ".\\TestData\\framesPerCollision\\hammerFrames\\Hammer0.png";
const fs::path HAMMER_SIZE_1_5 = ".\\TestData\\framesPerCollision\\hammerFrames\\Hammer1_5.png";
const fs::path HAMMER_SIZE_2_3_4 = ".\\TestData\\framesPerCollision\\hammerFrames\\Hammer2_3_4.png";
const fs::path HAMMER_SIZE_6 = ".\\TestData\\framesPerCollision\\hammerFrames\\Hammer6.png";
const fs::path HAMMER_SIZE_7 = ".\\TestData\\framesPerCollision\\hammerFrames\\Hammer7.png";


//background sprite
const fs::path BACKGROUND = ".\\TestData\\LabBackground.png";

//floor tiles
const fs::path FLOOR_TILE = ".\\TestData\\tiles\\IndustrialTile_73.png";

//objects
const fs::path BOX = ".\\TestData\\Box3.png";

//music and sounds
const fs::path YOU_ARE_DEAD = ".\\TestData\\sound\\death.wav";
const fs::path SOUNDTRACK = ".\\TestData\\sound\\LineNoise.wav";

#endif

