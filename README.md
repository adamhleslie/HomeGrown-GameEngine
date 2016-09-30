## Design Overview
Core is the basic functionality of the engine. It runs the game loop, which calls update on Modules and Entities, then renders.  
Modules are the overarching engine extensions - large additions to total functionality  
Entities are the things existing within the game at any point in time  
Components are the things that bring behavior and functionality to an entity, and are related to a specific module, or simply provide game logic tying other components together

There are 3 main ideas you should be familiar with:

1. Load/Unload - If loaded, a module or entity is known to the engine, and a component is known to its entity
2. Enable/Disable - If enabled (and loaded), a module, entity, or component has its update function called every tick
3. Create/Destroy - By using create/destroy, a module, entity, or component will have its memory managed by the engine, and will be automatically loaded

## Folder Structure
Modules should be in their own folder under the Source directory  
Components should be under the directory for their parent module  
Resources should be in the Media directory, which will be copied to the Build/Binaries directory  

## Adding folders (modules) to the build
1. Open CMakeLists.txt
2. Add a new line to the section denoted by "# Module List", as follows
3. add_project_module(Module ModuleDirectory)

## Branching Structure
Create a branch for each feature you are working on, with a descriptive name!  
Only merge it to master when your feature is verified finished and working  
If you want a branch to be a sub-branch use a forward slash, eg "parent-branch/child-branch"  
When the project is due, we will turn in whatever the master branch builds  

## Naming Comventions
Classes should be UpperCamelCase  
Methods and Functions should be lowerCamelCase  
Variables should by lowerCamelCase  

### Prefixes
m : Member Variable, mInputDevice  
s : Static Variable, sNumBugs  
k : Constant Variable, kMaxInputDevices  

## Compiling

### Linux

First time:

	$ mkdir Build && cd Build
	$ cmake ..
	$ make

After:

    $ cd Build
    $ make

To Run: (you must run it within the Binaries folder for it to find the Media folder)

	$ cd Build/Binaries
	$ ./ProjectName

### (Outdated) Windows (Visual Studio 2013)

1. Open CMake-Gui and set the source path, and the build path to the source path + Build
2. Add Entry OGRE_HOME and set it to your OGRE SDK path.
3. Configure for Visual Studio 2013
4. Generate
5. Open Build/ProjectName.sln
6. Build & Debug

On Windows, the DLLs needed to run the application are copied automatically to the binary folder.

## (Outdated) Tips

* If you are using version control, do not commit the Build folder. The generated build scripts are for your local working copy, not anyone else.
* To add Ogre plugins, simply add them to the `find_package` line in the `CMakeLists.txt` and add to linking/includes. You will also have to add the `loadPlugin` line in `Source/Core/Application.cpp` to load the library before you can use it.
* To add code modules, use the `add_project_module` macro.

## Notes

Created by Ron Kinard. Don't make this repository public

Visual Studio 2015 Preview is probably not supported because OGRE won't compile in it. It's a bummer. :disappointed:

You need a recent version of g++ to compile under Linux.
