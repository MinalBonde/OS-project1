# OS-project1
Count the frequency of alphabetical characters using fork
##Project1 README
===============

This is the README  file for the instructions of running project1.If you are reading this,you have probably have access to source files with main.c and input files file1 file2 file3 file4 file5 file6 file7 file8 file9 file10.
Function of this program is to use fork system call to create n processes.Each process will open a file and count the frequency of alphabetical characters inside it.Once the characters are counted, the result will be written in result.txt file.

##What to do next?
================

Instructions to compile and run the main.c 
1.Compile main.c using cc main.c command
2.make sure you have input files kept at the same location as main.c
3.Please provide command line parameters with executable filename along with the number of files to be read.
  for eg : ./a.out 2 file1.txt file2.txt result.txt
4.last parameter of command line will be the output file where the frequency of the characters will be written.
5.Input files : main.c file1.txt file2.txt file3.txt file4.c file5.yml file6.yml file7.txt file8.c file9.txt file10.yml
6.Output file : result.txt

##Error cases:
============

1.if number of file is less than 0 then missing filenames will be displayed.
2.if number of files given does not match with command line parameters filenames then error message of number of files mismatch will be displayed.


