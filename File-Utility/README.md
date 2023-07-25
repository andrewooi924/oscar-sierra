# User Manual for File Utility (fileutil.c)
Author: Ooi Yu Zhang

# Introduction
This beginner-friendly instruction manual will show you how to compile the program 'fileutil.c' and how to run all of the features that come with it.

# Functionalities
1. Viewing up to the first 10 words or a user-specified number of words of a user-specified source file.
2. Appending the first 10 words or a user-specified number or words from a user-specified source file to another user-specified  destination file.
Note: If the user does not specify a source file, sample.txt which comes with the program will be used instead.

# Compiling the program 'fileutil.c'
Run the command 'gcc -o fileutil fileutil.c' in your terminal. (Without the single quotes!)
This outputs a single file that you will be using to run the functions of the program.

# How to use the program

## Notes
1. All the commands stated below should be ran in the terminal.
2. All arguments inside the brackets <> are considered optional.
3. If a user-specified source file is included, it has to be the first argument after ./fileutil
4. The arguments -a and destfile depend on each other and will not work if one is excluded from the command. The argument destfile must come after the argument -a as well.
5. The arguments -n and numwords depend on each other and will not work if one is excluded from the command. The argument numwords must come after the argument -n as well.

## Viewing
Command: ./fileutil <sourcefile> <-n numwords>

(a). Running the command without any of the optional arguments will output up to the first 10 words of sample.txt.
(b). If the sourcefile argument is included, up to the first 10 words of the sourcefile will be outputted instead.
(c). The numwords argument takes in an integer that specifies how many words the user wants to view from the file.
     
## Appending from sample.txt to a user-specified destination file
Command: ./fileutil -a destfile <-n numwords>

(a). Running the command without the optional argument will append up to the first 10 words of sample.txt to the destination    file.
(b). The arguments -n and numwords can be included if the user wants to append number of words greater than 10. This argument can be inserted before or after -a destfile.

## Appending from a user-specified source file to a user-specified destination file
Command: ./fileutil sourcefile -a destfile <-n numwords>

(a). Running the command without the optional argument will append up to the first 10 words of the source file to the destination file.
(b). The position of the arguments -a destfile and -n numwords can be anywhere in the command as long as they come after the argument sourcefile.
