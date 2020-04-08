#include "App.h"

#include <cstdio>
#include <cassert>

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

App::App()
    : _window(nullptr)
    , _renderer(nullptr)
{

}

App::~App()
{
    if (_renderer)
    {
        SDL_DestroyRenderer(_renderer);
    }

    if (_window)
    {
        SDL_DestroyWindow(_window);
    }

    SDL_Quit();
}

bool App::Start()
{
    assert(_window == nullptr && _renderer == nullptr);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    else
    {
        _window = SDL_CreateWindow("SDL Template", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (_window == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            return false;
        }
        else
        {
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            if (_renderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                return false;
            }
            else
            {
                SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
            }
        }
    }

    bool quit = false;

    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_RenderClear(_renderer);
        SDL_RenderPresent(_renderer);
    }

    return true;
}