#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>
#include <vector>


// Structure pour stocker les paramètres du point
struct Point {
    float x, y;
    float vx, vy;
    float mass;
    int radius;
    SDL_Color color;
    Uint8 opacity;
};

// Structure pour stocker les connexions entre les points
struct Connection {
    int start; // Index du point de départ
    int end;   // Index du point de fin
    float rest_length; // Longueur de repos du ressort
    float stiffness;   // Raideur du ressort
};

// Fonction pour dessiner un point paramétrable
void drawPoint(SDL_Renderer* renderer, const Point& point);

// Fonction pour dessiner des lignes entre les points en fonction des connexions
void drawConnections(SDL_Renderer* renderer, const std::vector<Point>& points, const std::vector<Connection>& connections);

// Fonction pour dessiner des points et les lignes les reliant
void drawPointsAndConnections(SDL_Renderer* renderer, const std::vector<Point>& points, const std::vector<Connection>& connections);

// Fonction pour mettre à jour les positions des points en fonction des forces exercées par les connexions
void updatePoints(std::vector<Point>& points, const std::vector<Connection>& connections, float dt, int window_width, int window_height);


#endif // POINT_H
