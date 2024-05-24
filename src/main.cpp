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

 // Initialisation des points avec un coefficient de traînée
    std::vector<Point> points;
    points.push_back(Point(400, 300)); // Tête
    points.push_back(Point(350,250)); // Membre 1
    points.push_back(Point(450, 250)); // Membre 2
   

    // Initialisation des connexions fixes
    std::vector<Connection> connections = {
        {0, 1, 50.0f, 1.0f},
        {0, 2, 50.0f, 1.0f},

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

            // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 100);
        SDL_RenderClear(renderer);


        SDL_GetWindowSize(window,&w,&h);


                
        // Mettre à jour les positions des points en fonction des forces exercées par les connexions
        updatePoints(points, connections, dt,w,h);

        // Dessiner les points et les lignes les reliant
        drawPointsAndConnections(renderer, points, connections);

        SDL_Delay(1000/FPS); // Environ 60 FPS


    }

    // Nettoyer et fermer SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
