#include <SDL2/SDL.h>
#include <cmath>
#include "../include/Point.hpp"

// Fonction pour dessiner un point paramétrable
void drawPoint(SDL_Renderer* renderer, const Point& point) {
    // Définir la couleur avec l'opacité
    SDL_SetRenderDrawColor(renderer, point.color.r, point.color.g, point.color.b, point.opacity);

    // Dessiner un cercle rempli (point avec rayon)
    for (int w = 0; w < point.radius * 2; w++) {
        for (int h = 0; h < point.radius * 2; h++) {
            int dx = point.radius - w; // Calculer la distance en x par rapport au centre
            int dy = point.radius - h; // Calculer la distance en y par rapport au centre
            if ((dx * dx + dy * dy) <= (point.radius * point.radius)) {
                SDL_RenderDrawPoint(renderer, point.x + dx, point.y + dy);
            }
        }
    }
}

// Fonction pour dessiner des lignes entre les points en fonction des connexions
void drawConnections(SDL_Renderer* renderer, const std::vector<Point>& points, const std::vector<Connection>& connections) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Couleur noire pour les lignes
    for (const Connection& connection : connections) {
        const Point& start = points[connection.start];
        const Point& end = points[connection.end];
        SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
    }
}

// Fonction pour dessiner des points et les lignes les reliant
void drawPointsAndConnections(SDL_Renderer* renderer, const std::vector<Point>& points, const std::vector<Connection>& connections) {
    // Effacer l'écran
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Dessiner les connexions entre les points
    drawConnections(renderer, points, connections);

    // Dessiner les points
    for (const Point& point : points) {
        drawPoint(renderer, point);
    }

    // Afficher le rendu
    SDL_RenderPresent(renderer);
}
