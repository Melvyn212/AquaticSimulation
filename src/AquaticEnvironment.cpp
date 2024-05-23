#include "../include/AquaticEnvironment.hpp"
#include <algorithm>
#include <cstdlib>

AquaticEnvironment::AquaticEnvironment(int width, int height, int num_animals)
    : width(width), height(height) {
    // for (int i = 0; i < num_animals; ++i) {
    //     animals.emplace_back(static_cast<float>(rand() % 5 + 1));
    // }
}

// void AquaticEnvironment::update() {
//     for (auto& animal : animals) {
//         animal.move();
//     }
// }

// void AquaticEnvironment::draw(SDL_Renderer* renderer) {
//     for (auto& animal : animals) {
//         animal.draw(renderer);
//     }
// }

// void AquaticEnvironment::evolve() {
//     GeneticAlgorithm::evolve(animals);
// }

void AquaticEnvironment::simulate(int generations, SDL_Window* window, SDL_Renderer* renderer) {
    for (int i = 0; i < generations; ++i) {
        //update();
        SDL_SetRenderDrawColor(renderer, 0, 0, 50, 0);
        SDL_RenderClear(renderer);
        //draw(renderer);
        SDL_RenderPresent(renderer);
        //evolve();
        SDL_Delay(500); // Attendre pour visualiser chaque génération
    }
}
