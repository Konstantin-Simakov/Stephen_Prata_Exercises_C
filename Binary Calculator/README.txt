You must have pre-installed the 'gcc' compiler and the 'make' utility on Linux or macOS,
or only the 'gcc' compiler with set the 'PATH' variable environment for it on Windows.

Detailed technical specifications in Russian are located in the correspoonding .pdf file.
However, the program still displays basic instructions when launched.

To run the program, use the following commands while in the project directory:

On Linux in Terminal:
$ bash bin_calc.sh

On macOS in Terminal:
% make && make run && make clean

On Windows in Command line:
> gcc calculator.c operations.c -o bin_calc.exe
> bin_calc.exe
