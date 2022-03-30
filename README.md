# Zippy
Basic 2D Rendering Engine (Linux Only)

Todo: -
 - Automated Documentation? - Trying doxygen at the moment.
 - What is the architecture of this game engine?
 - Should I use CMake?

 - Make sure includes are sensible? - Which ones should be hidden? Maybe a pre-compiled header is easier.
 - Does TheCherno have a better way of abstracting glfw?
 - Get rid of line class? Can't I just move it all into Renderer::DrawLine()?
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
 - run "make" in the terminal
 - cd into the build directory
 - call "./Zippy" in the terminal

 - If you wish to change the application, edit Game.cpp as you wish, then rebuild as above.