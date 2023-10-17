# Templater
A tool to easily create (and maybe later on manage) cmake projects tailored to anyone's needs

## Building
Currently only tested on Arch, definetly won't work on Windows.
  - **Step 1:** Create a build directory
  - **Step 2:** From the directory, run `cmake ..`
  - **Step 3:** then `make`
  - **Step 4:** Copy the contents of `build/Plugins` to `${XDG_CONFIG_HOME}/templater/Plugins`
  - **Step 5:** *(Optional)* Copy `debugmalloc.h` from the `Plugins` folder to `${XDG_CONFIG_HOME}/templater/Plugins` if you want the `-d` flag to work
  
## Contributing
For now, only plugin contributions are allowed.

## Usage
```sh
templater <arguments> <project_name>
```

Current built-in arguments:
  - **`-d` or `--debugMalloc`:** Includes a file provided to us by my University, which we are required to include in all of our projects.
  - **`-h` or `--help`:** Prints out basic information about the program.
  - **`-m` or `--math`:** Links the C standard math library.
  - **`-S` or `--SDL2`:** Links SDL2. Currently only works on Arch. (Help required!!)

## Footnote
This project started, because I wanted to be able to create basic cmake projects quickly. Since then it has grown quite a bit, but as such, bugs may very well be present. If you happen to find one, please file it!
Also, all criticism is well recieved, so if you find some bad pracice in the code, please contact me about it.
