# Zippy
Basic 2D Rendering Engine (Linux Only)

Engine Architecture:
 - Scene
 	 - GameObjects
	  	- Components

Build instructions for Linux only: - 
 - Clone git repository.
 - cd into it (or open the repository in the terminal)
 - run "make" in the terminal
 - cd into the build directory
 - call "./Zippy" in the terminal

 - If you want to change the application, edit Game.cpp as you wish, then rebuild and run as above.

Project Aims: -
 - Draw hollow polygons.
 - Draw filled polygons.
 - Apply textures to shapes.
 - Create gameobject class
 - Create component class/interface?
 - Create renderer component
 - Create collider component
 - Create rigidbody component

Todo: -
 - Implement a window class as below:
 	- https://www.youtube.com/watch?v=5mlziHwq90k&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=8
 - Convert to dynamic lib (.so)

Questions: -
 - Should I use a pre-compiled header? 

Answered Questions: -
  - Should I use CMake?
 	 - Only if I make this windows-compatible. Otherwise the makefile is fine for linux-only.


