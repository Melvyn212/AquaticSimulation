#include <SDL2/SDL.h>
#include <iostream>
#include "../include/AquaticEnvironment.hpp"
#include "../include/Point.hpp"


#include<unistd.h>

#define FPS float(60)

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

      // Initialisation des points avec un coefficient de traînée
    std::vector<Point> points = {
        {100, 100, 20, 30, 1, 0.1f, 10, {255, 0, 0, 255}, 128},
        {200, 150, -15, 20, 1, 0.1f, 10, {0, 255, 0, 255}, 128},
        {300, 100, 25, -10, 1, 0.1f, 10, {0, 0, 255, 255}, 128},
    };

    // Initialisation des connexions avec des phases pour l'oscillation
    std::vector<Connection> connections = {
        {0, 1, 100.0f, 5.0f, 0.5f},
        {1, 2, 100.0f, 10.0f, 0.5f},
    };


    // Boucle principale
    bool quit = false;
    SDL_Event e;
    float dt = 1/FPS; // Intervalle de temps (environ 60 FPS)
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


                
        // Mettre à jour les positions des points en fonction des forces exercées par les connexions
        updatePoints(points, connections, dt,w,h);

        // Dessiner les points et les lignes les reliant
        drawPointsAndConnections(renderer, points, connections);


    }

    // Nettoyer et fermer SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
