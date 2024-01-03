#ifndef BACKGROUND_BUILDER_H
#define BACKGROUND_BUILDER_H

#include "stdafx.h"
#include "app/app.h"

class BackgroundBuilder
{
public:
    static const std::string BACKGROUND_FILE_PATH; // Path to the background image
    BackgroundBuilder();
    ~BackgroundBuilder();

    void Draw();

private:
    std::unique_ptr<CSimpleSprite> myBackgroundSprite;
};

#endif

