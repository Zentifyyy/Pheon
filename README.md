<img src="https://raw.githubusercontent.com/Zentifyyy/Pheon/refs/heads/main/PheonProject/img/icon.bmp" width=48>

# 
Pheon is a simple GUI application framework written in C++ using SDL3, SDL3_ttf for font usage and SDL3_image for images. Pheon doesnt come with any bells or whistles and is designed for single page applications which dont need fancy looking graphics.

## Getting started
#### These instructions will be for windows only, support for other platforms will come in the future.

- Firstly, make sure you have SDL3, SDL3_ttf and SDL3_image installed into your home directory.
- This repository has an example project which you can modify and edit for your own application, to get started, clone the repository ``` git clone --recursive https://github.com/Zentifyyy/Pheon.git```.
- Then run ```scripts/Setup-ExampleProject.bat``` which will generate all of the project files for you.
- Open the Visual Studio solution and add a Reference to SDL3 under SDL3_ttf and SDL3_image.
- Compile + run the project.

If you get a 'cannot open file SDL3.lib' error, go to SDL3_ttf and SDL3_image, go to properties, link and then to input and change SDL3.lib; to /x64/Debug/SDL3.lib;


### External Dependencies:
- [SDL3](https://github.com/libsdl-org/SDL)
- [SDL3_ttf](https://github.com/libsdl-org/SDL_ttf) (and included dependencies).
- [SDL3_image](https://github.com/libsdl-org/SDL_image) (and included dependencies).

### Additional
Pheon uses the [Roboto Font](https://fonts.google.com/specimen/Roboto) [(Apache License, Version 2.0)](https://www.apache.org/licenses/LICENSE-2.0).
