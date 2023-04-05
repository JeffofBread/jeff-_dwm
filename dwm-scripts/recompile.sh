#!/bin/sh
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
kitty --hold sh -c "cd ${SCRIPT_DIR} && cd .. && cd dwm-src && sudo make clean install"