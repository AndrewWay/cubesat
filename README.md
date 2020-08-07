# Welcome to LORIS!
## Low Orbit Reconaissance Imaging Satellite
### Introduction

LORIS is a 2U CubeSat being developed by Dalhousie University. LORIS's payload features two cameras; one which takes pictures using visible spectrum light and a second which takes pictures using near-infrared light (NIR). This repository contains all source code for the Core Software System (CSS) that will run on the satellite's on-board computer (OBC). It's primarily written in C++, while making use of other languages such as the BASH scripting language. The CSS is responsible for holding all data generated by every external subsystem, storing all generated data, issuing commands to subsystems to change their state, and completing missions received from an external sender in a way that the satellite maintains a nominal state.

### Software Break Down

The entire repository contains code for three distrinct parts: Core, Emulation, and Ground Station.

#### Core
The Core code is what will be used on the OBC of the satellite. It contains all logic necessary for ensuring successful, autonomous operation of the satellite.

<!-- #### Emulation
The Emulation code is used to emulate the hardware subsystems during development of the CSS.

#### Ground Station

The Ground Station code is used to create an interface that operators can use to interact with the CubeSat, whether its being simulated in a nearby computer or in orbit. From here, operators can request data, issue commands, test/debug, and start simulations. -->


### Code Conventions

Using Google C++ conventions. Reference here:

https://google.github.io/styleguide/cppguide.html

### Committing Code

Using the following Git model for development, testing, hot-fixes, and merging:
https://nvie.com/posts/a-successful-git-branching-model/?


### Project Directories

build – Output executables (“targets”). The suffix `_d` indicates debug version.
<!-- data – Files used by the main executable. -->
<!-- doc – Project’s documentation, possibly auto-generated. -->
<!-- deps – Subdirectories with external dependencies like libraries. -->
<!-- obj – Binary objects created during compilation. -->
src – Source files of the project with subdirectories if needed.
include - Project header file.
<!-- test – Source files of tests. -->
.gitignore – Prevents adding binary and temporary files to the git repository.
LICENSE – Describes how this project can be used and distributed.
README.md – General information about the project in Markdown format.

## Building the Project

In a terminal, run:
```
$ cd CubeSat-Core
$ cmake .
$ make
```
And watch the magic happen :) You'll find the compiled binaries in the `build/` directory.

## Code Documentation 

### Inter-Process Communication (IPC) system
#### Client API
`int ipc_connect(char name[3])`:
* Purpose
  * Initialize the client side IPC interface and connect to the IPC daemon
  * Necessary to run before using any other IPC related functions
* Arguments
  * `name`: 3 character name used to register you on the IPC network
* Returns
  * On success, 0 is returned
  * On error, -1 is returned

`int ipc_send(char dest[3], char * msg, size_t msg_len)`:
* Purpose
  * Send message to another process registered on the IPC network
* Arguments
  * `dest`: 3 character name of message recipient
  * `msg`: character array pointing to message desired to be sent 
  * `msg_len`: length of message pointed by `msg`
* Returns
  * On success, 0 is returned
  * On error, -1 is returned

`int ipc_recv(char src[3], char * buffer, size_t buffer_len)`:
* Purpose
  * Receive an incoming message from the IPC network
* Arguments
  * `src`: filter incoming message from IPC network. 
         use '*' to receive message from any sender.
  * `buffer`: points to array where incoming message will be stored upon receit.
  * `buffer_len`: maximum length of data which can be received and copied into `buffer`
* Returns
  * On success, the number of bytes copied into buffer is returned
  * On error, -1 is returned

`int ipc_disconnect()`:
* Purpose
  * Disconnect from the IPC network
* Returns
  * On success, 0 is returned
  * On error, -1 is returned
