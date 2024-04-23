#include "Common_function.h"
#include "MainObject.h"
#include "MainObject(02).h"
#include "Ball.h"
#include "khungthanh.h"
#include "khungthanh(02).h"
#include "TextObject.h"

// Định nghĩa biến toàn cục


TextObject scoreText;
TextObject gameTimeText;
int scorePlayer1 = 0;
int scorePlayer2 = 0;
TTF_Font* g_font;
TTF_Font* gameFont;
TTF_Font* menuFont;

// Định nghĩa các hàm
bool init();
void close();

bool init() {

    bool success = true;

    // Khởi tạo SDL và các thành phần khác
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
            if (!SDLCommonFunc::initSDL_Mixer()) {
                printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                success = false;
            }
        }

        // Khởi tạo font và cài đặt cho scoreText
        if(TTF_Init() < 0)
        {
            return false;
        }
        g_font = TTF_OpenFont("tyso.ttf", 48);
        if (g_font == nullptr) {
            printf("Failed to load g_font! SDL_ttf Error: %s\n", TTF_GetError());
            // Xử lý lỗi load font
        }
        gameFont = TTF_OpenFont("Game_Time.ttf", 36); // Thay đổi kích thước font tùy ý
        if (gameFont == nullptr) {
            printf("Failed to load game_font! SDL_ttf Error: %s\n", TTF_GetError());
            // Xử lý lỗi load font
        }
        menuFont = TTF_OpenFont("menu.ttf", 48);
        if(menuFont == nullptr)
        {
            printf("Failed to load menu font! SDL_ttf Error: %s\n", TTF_GetError());
        }
    }

    return success;
}

int main(int argc, char* args[]) {
    if (!init()) {
        printf("Failed to initialize!\n");
        return -1;
    }

    if (!SDLCommonFunc::loadMedia()) {
        printf("Failed to load media!\n");
        return -1;
    }

    bool quit = false;
    SDL_Event e;

    MainObject human_object;
    human_object.load_p_object(nv1_surface);

    MainObject02 human_object02;
    human_object02.load_p_object2(nv2_surface);

    Ball ball;
    ball.load_p_object(ball_surface);

    SDL_SetColorKey(nv2_surface, SDL_TRUE, SDL_MapRGB(nv2_surface->format, 0, 0, 0));
    SDL_SetColorKey(nv1_surface, SDL_TRUE, SDL_MapRGB(nv1_surface->format, 0, 0, 0));

    //Uint32 startTime = SDL_GetTicks(); // Thời điểm bắt đầu game (miliseconds)
    //Uint32 gameDuration = 120000; // Thời gian chơi là 2 phút (120000 miliseconds)

    bool play_game = false;
    bool isGameStarted = false; // Biến để xác định trạng thái game đã bắt đầu hay chưa
    Uint32 startTime = 0; // Thời điểm bắt đầu game (miliseconds)
    Uint32 gameDuration = 120000; // Thời gian chơi là 2 phút (120000 miliseconds)

//    SDL_Event e;

    while (!quit) {
        int ret_menu = SDLCommonFunc::ShowMenu(gScreenSurface, menuFont);
        if (ret_menu == 0) {
            // Thoát chương trình nếu người dùng chọn "Exit"
            quit = true;
            play_game = false;
        } else if (ret_menu == 1) {
            // Bắt đầu chơi game nếu người dùng chọn "Play Game"
            play_game = true;
            isGameStarted = true; // Đã bắt đầu game
            startTime = SDL_GetTicks(); // Lưu thời điểm bắt đầu game
            quit = false;
            Mix_PlayMusic(gBackgroundMusic, -1);
        }

    while (!quit && play_game) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            human_object.HandleInputAction(e);
            human_object02.HandleInputAction(e);
        }

         Uint32 currentTime = SDL_GetTicks(); // Thời điểm hiện tại (miliseconds)
         Uint32 elapsedTime = currentTime - startTime; // Thời gian đã trôi qua từ khi bắt đầu game

         // Tính thời gian còn lại
         Uint32 remainingTime = gameDuration - elapsedTime;

         if (remainingTime <= 0) {
             // Kết thúc game khi hết thời gian
             quit = true;
         }

        // Tính toán số phút và giây còn lại
        int secondsRemaining = remainingTime / 1000;


        SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0, 0, 0));
        scoreText.Show(gScreenSurface);
        SDLCommonFunc::ApplySurface(gPNGSurface, gScreenSurface, 0, 0);

        human_object.HandleMoveWithGoalLimit();
        human_object.HandleMoveWithGoalLimit02();
        human_object.Show(gScreenSurface);

        human_object02.HandleMoveWithGoalLimit();
        human_object02.HandleMoveWithGoalLimit02();
        human_object02.Show(gScreenSurface);

        human_object.HandleBallCollision(ball);
        human_object02.HandleBallCollision(ball);

        human_object.HandleMove();
        human_object.Show(gScreenSurface);

        human_object02.HandleMove();
        human_object02.Show(gScreenSurface);



        if (g_font == NULL) {
            printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        } else {
            scoreText.SetFont(g_font);
            scoreText.SetColor(TextObject::WHITE_TEXT);
            std::string newScore = std::to_string(scorePlayer1) + " : " + std::to_string(scorePlayer2);
            scoreText.SetText(newScore);
            scoreText.SetPosition(SCREEN_WIDTH / 2 - 80, 10);
            // Thực hiện chỉ một lần, không cần trong vòng lặp
            scoreText.CreateGameText(gScreenSurface);
        }

        if (gameFont == NULL) {
            printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        } else{
            gameTimeText.SetFont(gameFont); // Sử dụng font đã load
            gameTimeText.SetColor(TextObject::BLACK_TEXT); // Chọn màu cho chữ (ví dụ: trắng)
            gameTimeText.SetPosition(0, 0); // Vị trí hiển thị của chữ trên màn hình
            std::string timeString = "Time: " + std::to_string(secondsRemaining);
            gameTimeText.SetText(timeString);

            // Hiển thị TextObject của thời gian lên màn hình
            gameTimeText.CreateGameText(gScreenSurface);
            if (secondsRemaining <= 0) {
            quit = true;
            }
        }
        ball.HandleMove();
        ball.Show(gScreenSurface);

        if (KhungThanh::CheckCollision(ball, human_object, human_object02) || KhungThanh02::CheckCollision(ball, human_object, human_object02)) {
            KhungThanh::ResetPosition(ball, human_object, human_object02);
           // Tạo lại văn bản mới với điểm số cập nhật
            scoreText.CreateGameText(gScreenSurface); // Cập nhật văn bản điểm số
        }

        SDL_UpdateWindowSurface(gWindow);
    }

    SDLCommonFunc::close();
    return 0;
    }
}
