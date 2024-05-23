#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>
#include <vector>

// Structure pour stocker les paramètres du point
struct Point {
    int x, y;
    int radius;
    SDL_Color color;
    Uint8 opacity;
};

// Structure pour stocker les connexions entre les points
struct Connection {
    int start; // Index du point de départ
    int end;   // Index du point de fin
};

// Fonction pour dessiner un point paramétrable
void drawPoint(SDL_Renderer* renderer, const Point& point);

// Fonction pour dessiner des lignes entre les points en fonction des connexions
void drawConnections(SDL_Renderer* renderer, const std::vector<Point>& points, const std::vector<Connection>& connections);

// Fonction pour dessiner des points et les lignes les reliant
void drawPointsAndConnections(SDL_Renderer* renderer, const std::vector<Point>& points, const std::vector<Connection>& connections);

#endif // POINT_H
