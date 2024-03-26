#ifndef MAINOBJECT02_H_
#define MAINOBJECT02_H_

#include "Common_function.h"

class MainObject02 {
public:
    MainObject02();
    ~MainObject02();
    void load_p_object(SDL_Surface* _p_object);
    void Show(SDL_Surface* des);
    void HandleMove();
    void HandleInputAction(SDL_Event events);

private:
    SDL_Rect rect_;
    int x_val, y_val;
    SDL_Surface* p_object_;
};

#endif /* MAINOBJECT02_H_ */
