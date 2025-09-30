# File & Navigation:

    ls # list files
    cd # change directory
    pwd # print working directory
    mkdir libft # make new folder
    touch file.c # create file
    rm file.c # delete file
    rm -rf dir/ # force delete folder

# Compilation Commands:

    cc -Wall -Wextra -Werror file.c # compile C file with flags to treat all warnings as errors

Note: use -g flag to compile with debug info (for gdb), then gdb ./a.out (Hint: Usefull commands bellow)

    ar rcs libft.a file1.o file2.o # create your .a archive (your library)

# Makefile Shourtcuts:

    make: runs the default rule (usually all)
    make bonus: compile your bonus part
    make clean: deletes object files
    make fclean: deletes object files + libft.a
    make re: clean then recompile

# Debugging Memory:

    valgrind ./a.out # check for memory leaks
    flags:
        -s:                     shows the list of detected and supressed errors
        --leak-check=full:      shows the full leak report for each leak
        --show-leak-kinds=all:  shows EVERY kind of leak in your code


# Generating and ssh key and getting it for github

    1-  ssh-keygen -t ed25519 -C "your github email"
    2-  accept the default save location
    3-  add a password (optional)
    4-  git using: cat ~/.ssh/filename.pub
    5-  go to github and add it through the settings
Hint: download the Bash_Scripting/setup_github_ssh.sh file and run it with bash.

# Debugging code errors:

After compiling with the -g flag, you use gdb (GNU Debugger) to debug your program:
Compile with debug info:

    cc -g -Wall -Wextra -Werror main.c all_your_source_files.c -o program_name

Run with gdb:

    gdb ./program_name (the excutable file)

    Common gdb commands:
        1- run                 -         start the program
        2- bt                  -         show backtrace (where it crashed)
        3- list                -         show source code around crash
        4- br                  -         add a breakpoint to go through it while debugging
        5- n                   -         move to the next step / line
        6- print variable_name -         examine / print "variables_name"
        7- step                -         step through code line by line
        8- continue            -         continue execution
        9- quit                -         exit gdb



        A good a proach for debugging is (step by step):
        =====================================================================================
        |                                                                                   |
        |   Note: be careful while debugging, any mistake may require you to start over!!   |
        |                                                                                   |
        =====================================================================================

        1- gdb ./excutable
        2- (run) the program
        3- backtrace using (bt)
        4- (list) the code causing the problem
        5- add breakpoints using (br) for the functions shown in the backtrace
        6- (run) the program again
        7- use (n) to move step by step in the program
        8- (print) the any varible at anytime just to double check that everything is working smoothely
        9- Good luck debugging!!! XD
