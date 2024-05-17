# Utiliser une image de base avec CMake et un compilateur C++ préinstallés
FROM ubuntu:20.04

# Définir les variables d'environnement pour ne pas avoir d'interactions lors de l'installation
ENV DEBIAN_FRONTEND=noninteractive

# Installer les dépendances nécessaires
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    xorg \
    openbox \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-ttf-dev \
    libsdl2-mixer-dev \
    make \
    libgl1-mesa-glx \
    libgl1-mesa-dri \
    x11-apps \
    mesa-utils \
    && rm -rf /var/lib/apt/lists/*


