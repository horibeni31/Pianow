# Pianow
A piano learning app 
## Dependencies
- rtmidi
- qt5
## Installing
### Linux
```
git submoudle update --init --recursive
mkdir build
cd build
cmake ..
cmake --build .

```
### Windows
Open CMakeLists.txt in QTcreator, and build the project.

## Running 

The program only works with a physical midi-capable piano, or a virtual synthesizer for example Synthesia.
## Using with Synthesia:

### Windows
Download loopMidi to create virtual loopback midi ports
In Synthesia set the output, and the Pianow midi device to the created port
### Linux
Usually linux systems already have virtual loopback midi ports, set Synthesia the output, and the Pianow input to the same port
![image](https://user-images.githubusercontent.com/57011394/206924251-e19a90fe-2dd7-4986-9dbf-5694479c0720.png)
