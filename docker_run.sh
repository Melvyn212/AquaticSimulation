#!/bin/bash

CODE_PATH="/home/hw8172/Bureau/Wrkspc/pomme/AquaticSimulation"
DOCKER_IMAGE="melvyn212/aquatic_simulation:latest"

export DISPLAY=:0

docker run --rm \
--network host  \
-v "${CODE_PATH}:/AquaticSimulation" \
--env="DISPLAY" \
--env="XDG_RUNTIME_DIR=/tmp" \
--volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
--device=/dev/dri:/dev/dri \
--device=/dev/video0:/dev/video0 \
"${DOCKER_IMAGE}" \
    /bin/bash -c "\
    cd /AquaticSimulation/build && \
    cmake .. && make"

./build/AquaticSimulation

