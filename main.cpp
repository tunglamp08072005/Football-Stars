#include "Common_function.h"
#include "MainObject.h"
#include "Ball.h"

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

int main(int argc, char* args[]) {
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        if (!SDLCommonFunc::loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            bool quit = false;
            SDL_Event e;

            MainObject human_object;
            human_object.load_p_object(nv1_surface);

            Ball ball;
            ball.load_p_object(ball_surface);

            // Thiết lập màu key cho background và nhân vật
            SDL_SetColorKey(gPNGSurface, SDL_TRUE, SDL_MapRGB(gPNGSurface->format, 0, 0, 0)); // Background màu đen
            SDL_SetColorKey(nv1_surface, SDL_TRUE, SDL_MapRGB(nv1_surface->format, 0, 0, 0)); // Nhân vật màu đen

            while (!quit) {
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                    human_object.HandleInputAction(e);
                    ball.HandleInputAction(e);
                }

                // Hiển thị background
                SDLCommonFunc::ApplySurface(gPNGSurface, gScreenSurface, 0, 0);

                // Hiển thị nhân vật
                human_object.Show(gScreenSurface);
                human_object.HandleMove();

                // Xử lý va chạm giữa nhân vật và quả bóng
                human_object.HandleBallCollision(ball);

                // Xử lý khi nhấn phím để sút bóng
                human_object.KickBall(ball);

                // Di chuyển và hiển thị nhân vật
                human_object.HandleMove();
                human_object.Show(gScreenSurface);

                // Di chuyển và hiển thị quả bóng
                ball.HandleMove();
                ball.Show(gScreenSurface);

                // Cập nhật màn hình
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }

    SDLCommonFunc::close(); // Gọi hàm close() để giải phóng tài nguyên

    return 0;
}
