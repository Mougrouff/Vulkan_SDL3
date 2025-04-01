# Vulkan SDL3 example in Plain C

This project is a plain c implementation of the first half of this Vulkan tutorial: https://vulkan-tutorial.com/

This includes everything before the texturing part.  I've included cglm for the matrix maths stuff.

I make no claims that this is well organised or setup perfectly.  It was just the bare minimum to get it working without
C++ and using SDL3 instead of GLFW.  If I've done anything stupid let me know - it will be a good learning experience for
me!

## Linux Instructions

You will need the following dependencies:

- gcc
- make
- cmake
- vulkan
- sdl3
- cglm

To get everything working you should just need to do (from the root of the project):

```bash
./compile_shaders.sh
./build_and_run.sh
```

If it works you should see a rotating coloured square.

## Windows Instructions

You will need the following dependencies:

- The Vulkan SDK (installed in the default location on your C drive)
- Microsoft Visual Studio community edition

To get it working, first double click on `win_compile_shaders.bat` to compile the shaders.  Then load the folder in Visual Studio.

If you forget to compile the shaders first, CMake won't copy them into the right location.  Either shut down Visual Studio,
delete the .vs and out directories and load the folder again, or make some trivial change to the CMakeLists.txt file (i.e.
add a space) to get it to reload.  There probably is a better way to do this but I don't really develop on Windows and I'm a
Visual Studio noob!
