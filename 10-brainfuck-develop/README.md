# Brainfuck Developer Tool

## Brainfuck

Brainfuck is an esoteric programming language designed to challenge and amuse programmers, and is notable for its extreme minimalism. The language consists of only eight simple commands and an instruction pointer.

## Functionality

> The `generic.bf` program can be converted into an equivalent C language using a brainfuck converter linked in the main description file of the repository.

The program reads a series of star input characters, arranges them in a pyramid scheme, and outputs the modified version of the input into the terminal including line breaks.

## Showcase

![Brainfuck Showcase](/img/brainfuck_showcase.png)

## Code Base

BrainFuck uses a simple machine model consisting of the program and instruction pointer, as well as an array of memory cells and a data pointer. The eight brainFuck commands are as follows:

- `:` Increment the data pointer (move it to the next cell to the right).
- `<:` Decrement the data pointer (move it to the next cell to the left).
- `+:` Increment the value of the current cell.
- `-:` Decrement the value of the current cell.
- `.:` Output the value of the current cell as an ASCII character.
- `,:` Read a single ASCII char of input and store its value in the current cell.
- `[:` If the value of the current cell is zero, jump to the matching `]`, else continue executing the next instruction.
- `]:` If the value of the current cell is non-zero, jump back to the matching `[`, else continue executing the next instruction.
