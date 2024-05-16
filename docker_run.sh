#!/bin/bash

CODE_PATH="/home/hw8172/Bureau/Wrkspc/pomme/AquaticSimulation"
DOCKER_IMAGE="melvyn212/aquatic_simulation:latest"


docker run -it  \
--network host  \
-v "${CODE_PATH}:/AquaticSimulation" \
"${DOCKER_IMAGE}"
