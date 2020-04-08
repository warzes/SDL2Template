#ifndef APP_H
#define APP_H

#include <SDL.h>

class App
{
public:
    App();
    virtual ~App();

    bool Start();

protected:

    SDL_Window*   _window;
    SDL_Renderer* _renderer;
};

#endif // APP_H