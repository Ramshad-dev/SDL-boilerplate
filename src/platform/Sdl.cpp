#include "Sdl.hpp"

Sdl::Sdl(){
    sdlInit();
}

Sdl::~Sdl(){
    sdlQuit();
}

bool Sdl::sdlinput(bool* running){
    bool changed = false;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                *running = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        *running = false;
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    return changed;
}



void Sdl::sdlInit(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL init failed: " << SDL_GetError() << '\n';
        std::exit(1);
    }

    window = SDL_CreateWindow(TITLE, screenPosX, screenPosY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, ResolutionWidth, ResolutionHeight);
}

void Sdl::sdlUpdate(const std::vector<uint32_t> &pixels){
    SDL_UpdateTexture(texture, NULL, pixels.data(), ResolutionWidth * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Sdl::sdlQuit(){
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer=NULL;
    texture=NULL;
    SDL_Quit();
}