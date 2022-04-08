# Zippy
Basic 2D Rendering Engine (Linux Only)

This project uses: -
 - glad for OpenGL
 - GLFW3
 - glm
 - doxygen for documentation

Engine Architecture:
 - Scene
 	 - GameObjects
	  	- Components

Build instructions for Linux only: - 
 - Clone git repository.
 - cd into it (or open the repository in the terminal)
 - run "make" in the terminal
 - The library and it's shaders will now be found in the build directory.

If you would like to compile the example too: -
 - cd into sandbox
 - run "make" in the terminal
 - cd into the build directory
 - call "./Sandbox" in the terminal, to run the app.
 - If you want to change the example app, edit Zippy/sandbox/src/Game.cpp as you wish, then rebuild and run as above.

Project Aims: -							Achieved?
 - Draw straight lines. 				/
 - Draw hollow polygons.
 - Draw filled polygons.
 - Apply textures to shapes.
 - Create gameobject class
 - Create component class/interface?
 - Create renderer component
 - Create collider component
 - Create rigidbody component

Todo: -
 - Draw Multiple Joined lines (DrawLines() function?)
 - FPS?
 - See Core.h --> Renderer.h includes should not provide end user access to glad, glfw, Shader.h or Line.h?




Questions: -
 - Should I use a pre-compiled header? 

Answered Questions: -
  - Should I use CMake?
 	 - Only if I make this windows-compatible. Otherwise the makefile is fine for linux-only.
  - Do we need a Window class? 
	 - It seems simpler without one... The renderer holds a pointer to the window, which is accessible with Renderer::GetWindow(). Ideally we hide this from the end user.


