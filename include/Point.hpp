#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>
#include <vector>


class Point {
public:
    float x, y;
    float vx, vy;

    Point(float x, float y, float vx = 0, float vy = 0)
        : x(x), y(y), vx(vx), vy(vy) {}

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    float getX() const { return x; }
    float getY() const { return y; }

    void setvX(float vx) { this->vx = vx; }
    void setvY(float vy) { this->vy = vy; }
    float getvX() const { return vx; }
    float getvY() const { return vy; }

    float getMass() const { return mass; }
    float getDrag() const { return drag; }
    int getRadius() const { return radius; }
    SDL_Color getColor() const { return color; }
    Uint8 getOpacity() const { return opacity; }

private:
    float mass = 10;
    float drag = 0.1f;
    int radius = 10;
    SDL_Color color = {255, 255, 255, 255};
    Uint8 opacity = 255;
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

// Fonction pour mettre à jour les positions des points en fonction des forces exercées par les connexions et la traînée
void updatePoints(std::vector<Point>& points, std::vector<Connection>& connections, float dt, int window_width, int window_height);

#endif // POINT_DRAWING_H
