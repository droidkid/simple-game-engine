# simple-game-engine
Simple Game Engine using SDL2.

## Build instructions for Linux.

Make sure SDL2, SDL2_image, and SDL2_TTF libraries are installed.

```
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./game
```

## Build instructions for Windows.

Download [dependencies](https://drive.google.com/open?id=1SWtxt1CuLF3d8bRoZ09E5R6730bMoTJG), unzip and place it under the top directory.

Then run Cmake, generate the project using Visual Studio 15. Use Visual Studio to build the generated sln.
