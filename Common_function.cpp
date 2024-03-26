#include "Common_function.h"
#include "MainObject.h" // Include header file that contains nv1_surface declaration

// Global variable definition
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gPNGSurface = NULL;
SDL_Surface* nv1_surface = NULL; // Declare nv1_surface here
SDL_Surface* ball_surface = NULL; // Add this line for ball_surface
SDL_Surface* nv2_surface = NULL;




bool SDLCommonFunc::loadMedia()
{
    // Loading success flag
    bool success = true;

    // Load background image
    gPNGSurface = loadSurface("field03(02).png");
    if (gPNGSurface == NULL)
    {
        printf("Failed to load PNG image field03(02).png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // Load character image (nv1.png)
    nv1_surface = loadSurface("nv1.png");
    if (nv1_surface == NULL)
    {
        printf("Failed to load character image nv1.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // Trong hàm loadMedia của Common_function.cpp

    // Load character image (nv2.png)
    nv2_surface = loadSurface("nv2.png");
    if (nv2_surface == NULL)
    {
        printf("Failed to load character image nv2.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // Set the color key for nv2_surface to remove the background color
    SDL_SetColorKey(nv2_surface, SDL_TRUE, SDL_MapRGB(nv2_surface->format, 0, 0, 0)); // Nhân vật màu đen

    // Trong hàm loadMedia của Common_function.cpp

    // Set the coordinates for nv2.png
    int nv2_x = SCREEN_WIDTH / 2 + 300; // Set the x coordinate
    int nv2_y = SCREEN_HEIGHT / 2 - 100; // Set the y coordinate

    // Apply nv2.png onto the background at the specified coordinates
    SDLCommonFunc::ApplySurface(nv2_surface, gPNGSurface, nv2_x, nv2_y);


    // Load ball image
    ball_surface = loadSurface("ball.png");
    if (ball_surface == NULL)
    {
        printf("Failed to load ball image ball.png! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // Set the color key for ball_surface to remove the background color
    SDL_SetColorKey(ball_surface, SDL_TRUE, SDL_MapRGB(ball_surface->format, 0, 0, 0)); // Background màu đen

    // Set the coordinates for ball.png
    int ball_x = SCREEN_WIDTH / 2 - 25; // Set the x coordinate
    int ball_y = SCREEN_HEIGHT / 2 - 25; // Set the y coordinate

    // Apply ball.png onto the background at the specified coordinates
    SDLCommonFunc::ApplySurface(ball_surface, gPNGSurface, ball_x, ball_y);

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
        // Định nghĩa của hàm ApplySurface
        SDL_Rect offset;
        offset.x = x;
        offset.y = y;
        SDL_BlitSurface(src, NULL, des, &offset);
    }
}
