# Zippy
Basic 2D Rendering Engine

Todo: -
 - More seg faults!!! Happens in GetApp()? <-- Cause of Line Constructor being called before GLFW and GLAD are initialised.

  - Maybe app shouldn't contain a renderer pointer? Have a Renderer singleton?

Project Aims: -
 - Draw hollow polygons.
 - Draw filled polygons.
 - Apply textures to shapes.

Build instructions for Linux only: - 
 - Clone git repository.
 - cd into it
 - run "make" in the terminal
 - cd into build
 - call "./Zippy" in the terminal

 - If you wish to change the application, edit Game.cpp as you wish, then rebuild.