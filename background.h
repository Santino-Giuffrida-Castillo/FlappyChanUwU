#pragma once

#include <raylib.h>

struct ParallaxBackground
{
    Texture2D back;
    Texture2D mid;
    Texture2D front;

    float scrollingBack;
    float scrollingMid;
    float scrollingFore;
};