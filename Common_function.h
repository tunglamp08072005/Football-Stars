#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <stdio.h>
#include <SDL_ttf.h>
#include "TextObject.h"

#define GOAL_1_Y    SCREEN_HEIGHT / 2 - 150
#define GOAL_1_X    0

#define GOAL_2_X    SCREEN_WIDTH - 100
#define GOAL_2_Y    SCREEN_HEIGHT / 2 - 150

#define SCREEN_WIDTH  1200
#define SCREEN_HEIGHT 600
#define MAX_SPEED 1

// Loads individual image
SDL_Surface* loadSurface(std::string path);

// The window we'll be rendering to
extern SDL_Window* gWindow;

// The surface contained by the window
extern SDL_Surface* gScreenSurface;

// Current displayed PNG image
extern SDL_Surface* gPNGSurface;

// Current displayed object image
extern SDL_Surface* nv1_surface;
extern SDL_Surface* nv2_surface;
extern SDL_Surface* ball_surface;
extern SDL_Surface* goal_surface;
extern SDL_Surface* goal02_surface;

// Background music
extern Mix_Music* gBackgroundMusic;
extern Mix_Chunk* gSoccerKickSound;
extern Mix_Chunk* gGoalCheeringSound;
extern TTF_Font* g_font;
extern TextObject scoreText;
extern TextObject gameTimeText;
extern TTF_Font* gameFont;
extern TTF_Font* menuFont;

namespace SDLCommonFunc {
    void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
    SDL_Surface* loadSurface(std::string path);
    bool initSDL_Mixer();
    void closeSDL_Mixer();
    bool loadMedia();
    bool CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect);
    int ShowMenu(SDL_Surface* des, TTF_Font* font);
    void close();
}


#endif // COMMON_FUNCTION_H_
