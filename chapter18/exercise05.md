# Chapter 18, Exercise 5

## (a)

False. A `static` variable declared inside a block has static storage duration
and block scope.

## (b)

False. Every `extern` variable declared inside a function has either internal or
external linkage.

## (c)

True. Every variable with internal linkage is either 1) a `static` variable
declared outside any block or 2) an `extern` variable.

## (d)

False. Function parameters appearing within the list of parameter declarations
in a function prototype (not part of a function definition) have function
prototype scope, which terminates at the end of the function declarator.
