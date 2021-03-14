# Nelson

This is a repository for code and explanation, for my final "Something Awesome"
project for SIT111 - Computer Systems, as Deakin University.

The idea of the project is to create a small high-level language, and tooling
to produce valid X86_64 Assembly, that can then be compiled to a final 
executable with an existing compiler (eg. gcc, g++, mingw, clang).

## Why Nelson?

According to myth, Lord Nelson on had one eye, one arm and one leg. In cricket,
that legend applies to any individual or team score of 111 or multiples of.

It's a superstition that even umpires embrace, with David Shepherd raising a leg
"on a Nelson".

Since cricket is the national past time in Australia, and Computer Systems is
SIT111, it seems appropriate to call the language Nelson.

## High-Level Architecture

Through the development, the aim is to produce a compiler capable of translating
a Nelson (.nlsn) file into X86_64 Assembly (.s) file.

Each step in figure 1 will be implemented, and depending on total time, the
language will progress from simple arithmetic, to loops and conditionals.

Ideally, it will be a Turing complete language, though that depends on how much
can be developed over the trimester.

![High-Level Design](/docs/hld.png)
