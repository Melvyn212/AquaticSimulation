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

/// Fonction pour mettre à jour les positions des points en fonction des forces exercées par les connexions
void updatePoints(std::vector<Point>& points, const std::vector<Connection>& connections, float dt, int window_width, int window_height) {
    // Calcul des forces exercées par les connexions
    for (const Connection& connection : connections) {
        Point& p1 = points[connection.start];
        Point& p2 = points[connection.end];

        float dx = p2.x - p1.x;
        float dy = p2.y - p1.y;
        float distance = std::sqrt(dx * dx + dy * dy);
        float forceMagnitude = connection.stiffness * (distance - connection.rest_length);

        float fx = forceMagnitude * dx / distance;
        float fy = forceMagnitude * dy / distance;

        // Appliquer les forces (troisième loi de Newton)
        p1.vx += fx / p1.mass * dt;
        p1.vy += fy / p1.mass * dt;
        p2.vx -= fx / p2.mass * dt;
        p2.vy -= fy / p2.mass * dt;
    }

    // Mettre à jour les positions des points
    for (Point& point : points) {
        point.x += point.vx * dt;
        point.y += point.vy * dt;

        // Gérer les collisions avec les bords de la fenêtre
        if (point.x - point.radius < 0) {
            point.x = point.radius;
            point.vx = -point.vx;
        }
        if (point.x + point.radius > window_width) {
            point.x = window_width - point.radius;
            point.vx = -point.vx;
        }
        if (point.y - point.radius < 0) {
            point.y = point.radius;
            point.vy = -point.vy;
        }
        if (point.y + point.radius > window_height) {
            point.y = window_height - point.radius;
            point.vy = -point.vy;
        }
    }
}