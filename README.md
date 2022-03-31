# Zippy
Basic 2D Rendering Engine (Linux Only)

Todo: -
 - What is the architecture of this game engine?
	 - Scene
	 	 - GameObjects
		  	- Components

 - Automated Documentation? - Trying doxygen at the moment.
	- Describe exposed methods, members, functions and classes. (Using .h files for this)
		 - Todo: -
		 	 - Renderer.h
			 - Line.h?
			 - Shader.h
			 
 - Should I use CMake? - Only if I make this windows-compatible. Otherwise the makefile is fine for linux-only.

 - Should I use a pre-compiled header?
 - Does TheCherno have a better way of abstracting glfw?
 - Get rid of line class? Can't I just move it all into Renderer::DrawLine()?
 - Convert to dynamic lib (.so)?
 - Time singleton?

Project Aims: -
 - Draw hollow polygons.
 - Draw filled polygons.
 - Apply textures to shapes.

Build instructions for Linux only: - 
 - Clone git repository.
 - cd into it (or open the repository in the terminal)
 - run "make" in the terminal
 - cd into the build directory
 - call "./Zippy" in the terminal

 - If you wish to change the application, edit Game.cpp as you wish, then rebuild as above.