#include "stdafx.h"
#include "filePath.h"
#include "BackgroundBuilder.h"


BackgroundBuilder::BackgroundBuilder() {
    // Create the sprite with 1 column and 1 row since it's a single image
    std::string backgroundPathString = BACKGROUND.string();
    myBackgroundSprite = std::make_unique<CSimpleSprite>(backgroundPathString.c_str(), 1, 1);

    // In virtual coordinates, this should place it at the middle of the screen
    myBackgroundSprite->SetPosition(APP_VIRTUAL_WIDTH * 0.5f, APP_VIRTUAL_HEIGHT * 0.5f);

    // Scale the sprite to cover the entire screen
    // Since the virtual resolution matches the sprite's size, we use a scale of 1.0f
    myBackgroundSprite->SetScale(1.0f);

    //--------------
    /*
    // Assuming uniform scaling is acceptable
    //float scale = std::max(APP_VIRTUAL_WIDTH / 1024.0f, APP_VIRTUAL_HEIGHT / 768.0f);
    float scaleX = APP_VIRTUAL_WIDTH / 1024.0f;
    float scaleY = APP_VIRTUAL_HEIGHT / 768.0f;
    float scale = std::max(scaleX, scaleY);
    myBackgroundSprite->SetScale(scale);
    */
    //-----------
}

BackgroundBuilder::~BackgroundBuilder() {
    // Destructor - Sprite is automatically cleaned up by unique_ptr
}

void BackgroundBuilder::Draw() {
    if (myBackgroundSprite) {
        myBackgroundSprite->Draw();
    }
}
