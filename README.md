# Mesh (Musa & Edo shell)
Shell mockup written in C for the Operating Systems course

## Group members

Edin Bajrić

Muhamed Hamzić

## The submission contains the following files

shell.c

sleep.c

## Answers

### Q1: The following actions, do they require the OS to use kernel mode or is user mode sufficient?

- Starting a new process.

The fork() function in the C programming language is the underlying system call to the fork implementation in Linux. This action requires the OS to be in kernel mode, because this function is extremely dangerous - creates a new PCB for the child process.

- Multiplying two floating numbers stored in an application’s memory.

Since the multiplication is done in the application’s memory there is no need for the mode to switch to kernel mode and it is sufficient for the program to stay in user mode in order to multiply two numbers.

- Writing the results of the multiplication to a temporary log file on disk.

Even though the log file is only temporary, the program has to access the hardware to write it. And all access to hardware must go through the kernel, therefore it requires the kernel mode.

### Q2: Explain the purpose of a system call. Describe how control passes to the kernel when executing a system call.

The system call is the interface between an application and the Linux kernel.
It allows application programs to communicate with the system's core.
When a process in user mode requires access to a resource, the process makes a system call to the kernel, which subsequently provides the resource.

The modern operating system concept of user mode and kernel mode requires the usage of system calls. In user mode, application programs are started, and when they request to execute, a process and virtual address space are established for them. User-mode applications have less privileges and must rely on system calls to gain access to system resources. Kernel mode, on the other hand, is the primary control system since it runs all of the system's services and activities, as well as system-critical actions by application programs that are banned in user mode. System calls are necessary whenever an application requires additional computational power or storage space, or if an application-external file (open, read, edit, etc.) is required. Simply put, system calls are required anytime a user-mode process desires to perform a function that can only be performed in kernel mode.

System calls are necessary in the operating system in a variety of situations:

-when a file is created or deleted

-to transmit and receive data packets, network connections require system calls

-system calls are required when a user wants to read or write to a file

-if the user wishes to utilize a printer, scanner, or other piece of hardware

-processes are created and managed via system calls.

In order to execute a system call a program needs to execute a special trap instruction. This instruction accesses the kernel and switches the mode to kernel mode. The code which the trap runs is stored inside a trap table which the kernel sets up at boot time. In the kernel, the system (if allowed) can perform any privileged operations which are needed and do the required work for the calling process. On completion, the operating system calls a return-from-trap instruction which returns into the program, switches to user mode and begins running the process.

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

https://code.woboq.org/linux/linux/kernel/fork.c.html#fork_idle

https://www.linuxtechi.com/learn-use-fork-vfork-wait-exec-system-calls-linux/

https://www.programiz.com/c-programming/c-file-input-output



