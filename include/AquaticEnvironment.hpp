#ifndef AQUATIC_ENVIRONMENT_HPP
#define AQUATIC_ENVIRONMENT_HPP

#include <vector>
#include <SDL2/SDL.h>
#include "AquaticAnimal.hpp"

class AquaticEnvironment {
public:
    int width, height;
    //std::vector<AquaticAnimal> animals;

    AquaticEnvironment(int width, int height, int num_animals);
    //void update();
    //void draw(SDL_Renderer* renderer);
    //void evolve();
    void simulate(int generations, SDL_Window* window, SDL_Renderer* renderer);
};

#endif // AQUATIC_ENVIRONMENT_HPP
