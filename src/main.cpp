#include <SDL2/SDL.h>
#include <iostream>
#include "../include/AquaticEnvironment.hpp"
#include "../include/Point.hpp"


#include<unistd.h>

#define FPS 60

int main(int argc, char* argv[]) {
    // Initialiser SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Créer la fenêtre
    SDL_Window* window = SDL_CreateWindow("Aquatic Animal Simulation",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Créer le renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
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

    // Initialisation des points
    std::vector<Point> points = {
        {100, 100, 10, {255, 0, 0, 255}, 128},
        {200, 150, 10, {0, 255, 0, 255}, 128},
        {300, 100, 10, {0, 0, 255, 255}, 128},
        {400, 150, 10, {255, 255, 0, 255}, 128}
    };

        std::vector<Connection> connections = {
        {0, 1},
        {1, 3},
        {1, 2},

    };


    // Boucle principale
    bool quit = false;
    SDL_Event e;

    int w;
    int h;
    while (!quit) {
        // Gérer les événements
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }


        SDL_GetWindowSize(window,&w,&h);


                
        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255,255 ,255);
        SDL_RenderClear(renderer);
        // Dessiner les points et les lignes les reliant
        drawPointsAndConnections(renderer, points, connections);

        // Afficher le rendu
        SDL_RenderPresent(renderer);

        // Attendre un peu pour contrôler la vitesse du point
        SDL_Delay(1000/FPS); // Environ 60 FPS;
    }

    // Nettoyer et fermer SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
