#include <SDL2/SDL.h>
#include <cmath>
#include "../include/Point.hpp"


// Fonction pour dessiner un point paramétrable
void drawPoint(SDL_Renderer* renderer, const Point& point) {
    SDL_Color color = point.getColor();
    Uint8 opacity = point.getOpacity();
    // Définir la couleur avec l'opacité
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, opacity);

    // Dessiner un cercle rempli (point avec rayon)
    int radius = point.getRadius();
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // Calculer la distance en x par rapport au centre
            int dy = radius - h; // Calculer la distance en y par rapport au centre
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, point.getX() + dx, point.getY() + dy);
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
        SDL_RenderDrawLine(renderer, start.getX(), start.getY(), end.getX(), end.getY());
    }
}

// Fonction pour dessiner des points et les lignes les reliant
void drawPointsAndConnections(SDL_Renderer* renderer, const std::vector<Point>& points, const std::vector<Connection>& connections) {

    // Dessiner les connexions entre les points
    drawConnections(renderer, points, connections);

    // Dessiner les points
    for (const Point& point : points) {
        drawPoint(renderer, point);
    }

    // Afficher le rendu
    SDL_RenderPresent(renderer);
}

// Fonction pour appliquer les contraintes de distance fixe
void applyConstraints(std::vector<Point>& points, const std::vector<Connection>& connections) {
    for (const Connection& connection : connections) {
        Point& p1 = points[connection.start];
        Point& p2 = points[connection.end];

        float dx = p2.getX() - p1.getX();
        float dy = p2.getY() - p1.getY();
        float distance = std::sqrt(dx * dx + dy * dy);
        float difference = distance - connection.rest_length;

        if (distance != 0) {
            float correction = difference / distance / 2.0f;
            float correctionX = dx * correction;
            float correctionY = dy * correction;

            p1.setX(p1.getX() + correctionX);
            p1.setY(p1.getY() + correctionY);
            p2.setX(p2.getX() - correctionX);
            p2.setY(p2.getY() - correctionY);
        }
    }
}

// Fonction pour mettre à jour les positions des points en fonction des forces exercées par les connexions et la traînée
void updatePoints(std::vector<Point>& points, std::vector<Connection>& connections, float dt, int window_width, int window_height) {
    // Déplacer les membres de manière aléatoire
    for (size_t i = 1; i < points.size(); ++i) { // Ignorer la tête (point 0)
        points[i].setX(points[i].getX() + (std::rand() % 3 - 1) * 5.0f); // Mouvement aléatoire en x
        points[i].setY(points[i].getY() + (std::rand() % 3 - 1) * 5.0f); // Mouvement aléatoire en y
    }

    // Calculer la force nette de propulsion
    float totalFx = 0;
    float totalFy = 0;
    for (size_t i = 1; i < points.size(); ++i) {
        float dx = points[i].getX() - points[0].getX();
        float dy = points[i].getY() - points[0].getY();
        float distance = std::sqrt(dx * dx + dy * dy);
        if (distance != 0) {
            totalFx += (points[i].getvX() - points[0].getvX()) * dx / distance;
            totalFy += (points[i].getvY() - points[0].getvY()) * dy / distance;
        }
    }

    // Appliquer la force nette de propulsion à tous les points
    for (Point& point : points) {
        point.setvX(point.getvX() + totalFx * dt / point.getMass());
        point.setvY(point.getvY() + totalFy * dt / point.getMass());
    }

    // Mettre à jour les positions des points
    for (Point& point : points) {
        // Appliquer la force de traînée
        float vx = point.getvX();
        float vy = point.getvY();
        point.setvX(vx - vx * point.getDrag() * dt);
        point.setvY(vy - vy * point.getDrag() * dt);

        // Mettre à jour la position
        point.setX(point.getX() + point.getvX() * dt);
        point.setY(point.getY() + point.getvY() * dt);

        // Gérer les collisions avec les bords de la fenêtre
        if (point.getX() - point.getRadius() < 0) {
            point.setX(point.getRadius());
            point.setvX(-point.getvX());
        }
        if (point.getX() + point.getRadius() > window_width) {
            point.setX(window_width - point.getRadius());
            point.setvX(-point.getvX());
        }
        if (point.getY() - point.getRadius() < 0) {
            point.setY(point.getRadius());
            point.setvY(-point.getvY());
        }
        if (point.getY() + point.getRadius() > window_height) {
            point.setY(window_height - point.getRadius());
            point.setvY(-point.getvY());
        }
    }

    // Appliquer les contraintes de distance fixe
    for (int i = 0; i < 10; ++i) { // Répéter plusieurs fois pour assurer la convergence
        applyConstraints(points, connections);
    }
}