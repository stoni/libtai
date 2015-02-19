#/bin/sh

DIRECTORY=build

if [ ! -d "$DIRECTORY" ]; then
    mkdir build
fi

cd build
cmake -G"Unix Makefiles" ..
cd ..



