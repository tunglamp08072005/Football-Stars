#include "Common_function.h"
#include "MainObject.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "TextObject.h"
#include "TextObject.h"

// Global variable definition
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gPNGSurface = NULL;
SDL_Surface* nv1_surface = NULL;
SDL_Surface* ball_surface = NULL;
SDL_Surface* nv2_surface = NULL;
SDL_Surface* goal_surface = NULL;
SDL_Surface* goal02_surface = NULL;
Mix_Music* gBackgroundMusic = NULL;
Mix_Chunk* gSoccerKickSound = NULL;
Mix_Chunk* gGoalCheeringSound = NULL;
SDL_Surface* g_img_menu = NULL;

bool SDLCommonFunc::CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect)
{
    if(x >= rect.x && x <= rect.x + rect.w &&
       y >= rect.y && y <= rect.y + rect.h)
    {
        return true;
    }
    return false;
}

int SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font* font) {
    g_img_menu = loadSurface("start_menu_game.png");
    if (g_img_menu == NULL) {
        return 1;
    }

    int value;

    const int kMenuItemNum = 2;
    SDL_Rect pos_arr[kMenuItemNum];
    pos_arr[0].x = 200;
    pos_arr[0].y = 200;
    pos_arr[1].x = 200;
    pos_arr[1].y = 300;

    TextObject text_menu[kMenuItemNum];

    text_menu[0].SetText("Play Game");
    text_menu[0].SetColor(TextObject::BLACK_TEXT);
    text_menu[0].SetFont(font);
    text_menu[0].SetPosition(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("Exit");
    text_menu[1].SetColor(TextObject::BLACK_TEXT);
    text_menu[1].SetFont(font);
    text_menu[1].SetPosition(pos_arr[1].x, pos_arr[1].y);

    bool selected[kMenuItemNum] = {false, false};
    int xm = 0;
    int ym = 0;

    SDL_Event m_event;
    bool quit_menu = false;

    while (!quit_menu) {
        SDLCommonFunc::ApplySurface(g_img_menu, des, 0, 0);

        for (int i = 0; i < kMenuItemNum; ++i) {
            text_menu[i].CreateGameText(des);
        }

        while (SDL_PollEvent(&m_event)) {
            switch (m_event.type) {
                case SDL_QUIT:
                    quit_menu = true;
                    value = 2;
                    break;
                case SDL_MOUSEMOTION:
                    xm = m_event.motion.x;
                    ym = m_event.motion.y;

                    for (int i = 0; i < kMenuItemNum; i++) {
                        if (SDLCommonFunc::CheckFocusWithRect(xm, ym, text_menu[i].GetRect())) {
                            if (!selected[i]) {
                                selected[i] = true;
                                text_menu[i].SetColor(TextObject::RED_TEXT);
                            }
                        }
                        else {
                            if (selected[i]) {
                                selected[i] = false;
                                text_menu[i].SetColor(TextObject::BLACK_TEXT);
                            }
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    xm = m_event.button.x;
                    ym = m_event.button.y;
                    for (int i = 0; i < kMenuItemNum; i++) {
                        if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect())) {
                            if (i == 0) {
                                quit_menu = true;
                                value = 1;
                            } else if (i == 1) {
                                quit_menu = true;
                                value = 0;
                            }
                        }
                    }
                    break;

                default:
                    break;
            }
        }
        SDL_UpdateWindowSurface(gWindow);
    }
    return value;
}



bool SDLCommonFunc::initSDL_Mixer() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }
    gSoccerKickSound = Mix_LoadWAV("soccer-kick.mp3");
    if (gSoccerKickSound == NULL) {
        printf("Failed to load soccer-kick sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }
    return true;
}

void SDLCommonFunc::closeSDL_Mixer() {
    Mix_CloseAudio();
}

bool SDLCommonFunc::loadMedia()
{
    bool success = true;

    // Load goal cheering sound effect
    gGoalCheeringSound = Mix_LoadWAV("free-crowd-cheering.mp3");
    if (gGoalCheeringSound == NULL) {
        printf("Failed to load goal cheering sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    gBackgroundMusic = Mix_LoadMUS("background.mp3");
    if (gBackgroundMusic == NULL) {
        printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    // Load background image
    gPNGSurface = loadSurface("field02.png");
    if (gPNGSurface == NULL)
    {
        printf("Failed to load PNG image field02.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // Load character image (nv1.png)
    nv1_surface = loadSurface("nv1.png");
    if (nv1_surface == NULL)
    {
        printf("Failed to load character image nv1.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }
    // Load character image (nv2.png)
    nv2_surface = loadSurface("nv2.png");
    if (nv2_surface == NULL)
    {
        printf("Failed to load character image nv2.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // Load ball image
    ball_surface = loadSurface("ball.png");
    if (ball_surface == NULL)
    {
        printf("Failed to load ball image ball.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // Set the color key for ball_surface to remove the background color
    SDL_SetColorKey(ball_surface, SDL_TRUE, SDL_MapRGB(ball_surface->format, 0, 0, 0));

    // Set the coordinates for ball.png
    int ball_x = SCREEN_WIDTH / 2 - 25;
    int ball_y = SCREEN_HEIGHT / 2 - 25;

    // Load goal frame image (khungthanh.png)
    goal_surface = loadSurface("khungthanh.png");
    if (goal_surface == NULL)
    {
        printf("Failed to load goal frame image khungthanh.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }
    else
    {
    // Set color key to remove background color (if needed)
    SDL_SetColorKey(goal_surface, SDL_TRUE, SDL_MapRGB(goal_surface->format, 0, 0, 0));
    }

    // Load goal frame image (khungthanh(02).png)
    goal02_surface = loadSurface("khungthanh(02).png");
    if (goal02_surface == NULL)
    {
        printf("Failed to load goal frame image khungthanh(02).png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }
    else
    {
        // Set color key if needed to remove background
         SDL_SetColorKey(goal02_surface, SDL_TRUE, SDL_MapRGB(goal02_surface->format, 0, 0, 0));
    }

    // Set the coordinates for khungthanh(02).png
    int goal02_x = GOAL_2_X;
    int goal02_y = GOAL_2_Y;

    SDLCommonFunc::ApplySurface(goal02_surface, gPNGSurface, goal02_x, goal02_y);

// Set the coordinates for khungthanh.png
    int goal_x = GOAL_1_X;
    int goal_y = GOAL_1_Y;

    // Apply khungthanh.png onto the background at the specified coordinates
    SDLCommonFunc::ApplySurface(goal_surface, gPNGSurface, goal_x, goal_y);

    return success;
}





void SDLCommonFunc::close()
{
    // Free loaded image
    SDL_FreeSurface(gPNGSurface);
    gPNGSurface = NULL;

    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    Mix_FreeChunk(gGoalCheeringSound);
    gGoalCheeringSound = NULL;

    TTF_CloseFont(g_font);
    TTF_CloseFont(gameFont);
    TTF_CloseFont(menuFont);


    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Surface* SDLCommonFunc::loadSurface(std::string path)
{
    // The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == NULL)
        {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

namespace SDLCommonFunc {
    void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
        SDL_Rect offset;
        offset.x = x;
        offset.y = y;
        SDL_BlitSurface(src, NULL, des, &offset);
    }
}
