# Zippy
Basic 2D Rendering Engine (Linux Only)

Todo: -
 - Make sure includes are sensible? - Which ones should be hidden?
 - Add more Renderer methods
	 = Set screen size and title
 - Add .o files and executables to a .gitignore
 - Add more Input methods?
 - Shaders
	 = Write Hollow Polygon shader? Or something? idk how to deal with unknown no. of vertices
 	 = Write filled polygon shader? ^^^^^^^^^^^^^
   	 = Write texture shader.
 - Windows compatibility?
 - Convert to dynamic library? (.dll and .so)
 - Time singleton?

Project Aims: -
 - Draw hollow polygons.
 - Draw filled polygons.
 - Apply textures to shapes.

Build instructions for Linux only: - 
 - Clone git repository.
 - cd into it (or open the repository in the terminal)
 - run "make clean" in the terminal
 - cd into the build directory
 - call "./Zippy" in the terminal

 - If you wish to change the application, edit Game.cpp as you wish, then rebuild as above.