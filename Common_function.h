#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 1036;

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
extern SDL_Window* gWindow;

extern SDL_Surface* ball_surface ;
//The surface contained by the window
extern SDL_Surface* gScreenSurface;

//Current displayed PNG image
extern SDL_Surface* gPNGSurface;

//Current displayed object image
extern SDL_Surface* nv1_surface;

extern SDL_Surface* nv2_surface;





namespace SDLCommonFunc {
    //Loads media
    bool loadMedia();

    //Frees media and shuts down SDL
    void close();

    //Loads individual image
    SDL_Surface* loadSurface(std::string path);

    // Declaration of ApplySurface
    void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
}

#endif // COMMON_FUNCTION_H_
