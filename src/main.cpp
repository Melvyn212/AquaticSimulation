#include <SDL2/SDL.h>
#include <iostream>
#include "../include/AquaticEnvironment.hpp"

int main(int argc, char* argv[]) {
    // Initialiser SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Créer la fenêtre
    SDL_Window* window = SDL_CreateWindow("Aquatic Animal Simulation",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Créer le renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialiser l'environnement aquatique
    int width = 800;
    int height = 600;
    int num_animals = 10;

    AquaticEnvironment env(width, height, num_animals);

    // Boucle principale
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Gérer les événements
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dessiner l'environnement
        //env.draw(renderer);

        // Mettre à jour l'écran
        SDL_RenderPresent(renderer);
    }

    // Nettoyer et fermer SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
