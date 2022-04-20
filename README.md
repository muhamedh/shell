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

Redirect the output to a text file in the following way:

`uptime > your_file_name.txt`

*.txt must be the extension of your file*

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


## Challenges

Researching additional materials needed for coding

Researching built-in C functions we haven't used

Working on github, tracking changes and resolving merge conflicts

## Sources-tutorials

https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

https://www.youtube.com/watch?v=OVFEWSP7n8c

https://stackoverflow.com/questions/38796808/how-to-safely-try-out-a-fork-bomb

https://tuxthink.blogspot.com/2012/12/c-program-in-linux-to-find-username-of.html

https://www.systutorials.com/how-to-get-the-hostname-of-the-node-in-c/

https://www.theurbanpenguin.com/4184-2/

https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-basename-return-last-component-path-name#rbasen

https://iq.opengenus.org/chdir-fchdir-getcwd-in-c/

https://www.youtube.com/watch?v=j9yL30R6npk

https://stackoverflow.com/questions/1540627/what-api-do-i-call-to-get-the-system-uptime

