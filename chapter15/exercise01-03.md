# Chapter 15, Exercises 1-3

## Exercise 1

### (a)

* You can inspect and test each source file individually.
* It becomes easier to improve only some parts of the program without altering
  its behavior.

### (b)

* You need to ensure that there are no errors during the linking process.
* It may be hard to maintain the makefile or equivalent for the program.

## Exercise 2

\(b\). Function definitions should be in source files.


## Exercise 3

If there’s a file named `file` in the current directory, the preprocessor will
insert it into the current file rather than include the system header named
`file`.
