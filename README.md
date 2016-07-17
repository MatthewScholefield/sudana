# Sudana
Sudana is a light weight simple sound engine written in C++ for PortAudio. It can currently generate sine, triangular, and saw tooth waveforms.

# Getting Started

### Setup
Sudana depends on PortAudio and by default is compiled using clang. In Ubuntu you can install these with `sudo apt-get install libportaudio-dev clang-3.5`.

### Compiling
Simply run `make` and it will compile everything. 

### Running
The executable should be created in a subdirectory in the `dist` folder. To run it type `./dist/` followed by the full path of the binary. For me the command would be `dist/Debug/CLang-Linux/sunada`. It is important to run the executable from the root project directory since that is where the demo `song.dat` file resides.

# Development
This project uses Netbeans IDE although any editor of your choice will work. In `source/SongPlayer.cpp` you can get an idea of how the engine currently works. At the moment it is set up to read a text file with lines consisting of three integers on it representing a note in a major scale. Anything below 1 is counted as a rest.

# Contact
Contact me either at `matthew3311999@gmail.com` or by filing an issue on GitHub.

