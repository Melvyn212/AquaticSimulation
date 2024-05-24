#!/bin/bash
#CODE_PATH="/home/adehundeag/wrkspace/AquaticSimulation"
CODE_PATH="/home/hw8172/Bureau/Wrkspc/pomme/AquaticSimulation"

export DISPLAY=:0

DOCKER_IMAGE="melvyn212/aquatic_simulation:latest"

docker run -it --rm  \
    --network host  \
    -v "${CODE_PATH}:/AquaticSimulation" \
    "${DOCKER_IMAGE}" \
        /bin/bash -c "\
        cd /AquaticSimulation/build && \
        cmake .. && make"


./build/AquaticSimulation
