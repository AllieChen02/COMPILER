
README: COMP 506: Project 1. 

With the provided Makefile, you can automatically generate and compile the scanner and parser defined by DEMOgram.l and DEMOgram.y. 
Generated files are stored in directory /compiler, while the executable driver called demo is stored in the current directory.
To run the executable demo on an input Demo program, you should use:  

./demo [demo_file]  

where an input demo_file is a program written in demo syntax.

This directory contains DEMOgram.l and DEMOgram.y. files that can be used as a 
starting point for building those files, they contain declarations that you 
will need, but not much else.

You can run the executable without an input file and in that case, it will check the correctness of some Demo program at standard input.  
To check the correctness of your solution, you can use files from the test directory, that contain the examples of correct and incorrect Demo programs.
