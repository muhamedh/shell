# Shell
Shell mockup written in C for the Operating Systems course

## Group members

Edin Bajrić

Muhamed Hamzić

## The submission contains the following files

shell.c

sleep.c

## Answers

## Description

The shell implements all the project tasks except for piping. Additional commands were implemented such as: `clear` which clears the screen and `exit` which exits the shell. The help page for the entire shell will be listed in the following section.

### Help
`mkdir` 

Create a DIRECTORY, if they do not already exist

Usage mkdir [OPTION]... DIRECTORY...

OPTIONS:

-v print a message for a created directory

-V print the current version

-h show the help page

`ls`

List FILEs in current directory 

Usage ls [OPTION]...

OPTIONS:

-c add color to the output (directories - purple, files - green)

-V print the current version

-h show the help page

`uptime`

Tell how long the system has been running

Usage uptime [OPTION]...

OPTIONS:

-p show uptime in pretty format

-V print the current version

-h show the help page

`sl`
 
Prints a car moving across your screen

`fork`

Shows an example of working with parent and child processes. The parent process creates a child process which uses the execl function to run the sleep.c program. Finally the child process terminates itself.

`vfork`

Demonstrates the major difference between fork and vfork : in vfork the memory is shared between the parent and the child process.

`forkbomb`

Runs a DoS attack by creating an "infinite" amount of child processes.


## Instructions for compiling

`gcc -Wall -o shell shell.c`

`gcc -Wall -o sleep sleep.c`

`./shell`

Shell capabilities
The shell is capable of running the following commands:

clear - clears the shell screen

sl

fork examples

Running instructions

Files-directories

Answers 


Challenges

## Sources-tutorials

https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

https://www.youtube.com/watch?v=OVFEWSP7n8c

https://stackoverflow.com/questions/38796808/how-to-safely-try-out-a-fork-bomb

