#include <iostream>
#include "core.hpp"
#include "sdl.hpp"

int main(){
    core c;
    sdl s;
    bool running=true;
    while(running){
        bool changed = s.sdlinput(&running);
        SDL_Delay(100);
    }
    s.sdlQuit();
    return 0;
}
