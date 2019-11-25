# 3D OpenGL ENGINE

## About
This project is intended to put into practice the knowledge acquired
around 3D programming with OpenGL.

This 3D engine is designed to provide an implementation and demonstration of concepts and functionalities
that we find in the big ones like Unity, Unreal.
It is not intended to compete with known engines.

This project can be used as support for anyone who would like to embark on the adventure
3D engine development with C ++ / OpenGL.
My final goal for this project is that it be cross platform (Linux, Windows, MacOS).
The project is recent, it is currently developed and runnable under Windows.


# Building & Dependancies

## Dependancies
As this project is mainly developed in C++, I use [GLFW](https://github.com/glfw/glfw) for window creation and user input management,
[GLM](https://glm.g-truc.net/0.9.9/index.html) for functions and mathematical calculations,
GLEW for openGL functions and [STB_Image](https://github.com/nothings/stb) for loading and manipulating image files for textures.

## Building
This project has been configured to use the Vcpkg package manager, which provides a flexibility to update them.
All packages can be installed from [Vcpkg](https://docs.microsoft.com/en-us/cpp/build/vcpkg?view=vs-2019).
This link show how to build and setup [Vcpkg](https://docs.microsoft.com/en-us/cpp/build/vcpkg?view=vs-2019#installation) on Windows.

As I use static-linking for all above dependencies, you can install packages for x86 or x64 or both 
if you would like to have both.
Here is  commands for these  architectures
## x86
`vcpkg install glfw:x86-windows-static`
`vcpkg install glew:x86-windows-static`
`vcpkg install stb:x86-windows-static`
`vcpkg install glm:x86-windows-static`


## x64
`vcpkg install glfw:x64-windows-static`
`vcpkg install glew:x64-windows-static`
`vcpkg install stb:x64-windows-static`
`vcpkg install glm:x64-windows-static`
