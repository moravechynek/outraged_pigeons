#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(){
    if(SDL_Init(SDL_INIT_VIDEO)){
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Outraged Pigeons", 100, 100, 1203, 600, SDL_WINDOW_SHOWN);
    if(!window){
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer){
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    IMG_Init(IMG_INIT_PNG);

    SDL_Surface *background = IMG_Load("media/background.png");
    SDL_Texture *background_texture = SDL_CreateTextureFromSurface(renderer, background);
    SDL_FreeSurface(background);

    SDL_Rect texture_destination;
    texture_destination.x = 0;
    texture_destination.y = 0;
    texture_destination.w = 1203;
    texture_destination.h = 600;

    SDL_Surface *sling = IMG_Load("media/sling.png");
    SDL_Texture *sling_texture = SDL_CreateTextureFromSurface(renderer, sling);
    SDL_FreeSurface(sling);

    SDL_Rect sling_pos;
    sling_pos.x = 120;
    sling_pos.y = 394;
    sling_pos.w = 40;
    sling_pos.h = 201;

    SDL_Surface *sling2 = IMG_Load("media/sling2.png");
    SDL_Texture *sling2_texture = SDL_CreateTextureFromSurface(renderer, sling2);
    SDL_FreeSurface(sling2);

    SDL_Rect sling2_pos;
    sling2_pos.x = 91;
    sling2_pos.y = 388;
    sling2_pos.w = 45;
    sling2_pos.h = 125;

    SDL_Event e;
    bool quit = false;

    while(!quit){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, background_texture, NULL, &texture_destination);
        SDL_RenderCopy(renderer, sling_texture, NULL, &sling_pos);
        SDL_RenderCopy(renderer, sling2_texture, NULL, &sling2_pos);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(background_texture);
    SDL_DestroyTexture(sling_texture);
    SDL_DestroyTexture(sling2_texture);
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}