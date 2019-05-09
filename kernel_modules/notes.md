# Linux kernel modules

## What is a kernel?

You can think of a kernel as the translator between hardware and software. All internet traffic and keyboard presses and disk reads and writes pass through the kernel. They are sent from the hardware,
processed by the kernel, and made available to the software sitting on top of the operating system.

## Why do we need a kernel?

Without one, Firefox, Chrome and Safari would be responsible for talking directly to hardware.
This means code that could be reused and put in the kernel would have to be rewritten per application.
Furthermore, kernels handle usage of the hardware so we need some way to synchronize between different
applications that want to use the hardware. Even from a security perspective, the idea
of every application being allowed to access hardware is not consistent with the security perspective
of granting fewest permissions needed. If you're still not convinced, every application
being responsible for their own network stack also introduces surface area for bugs which is bad both
from a security and functionality perspective.

## Okay, so I'm on board with having a kernel - how do they work?

Kernels are stored in binary files on a Linux filesystem like any other file. When the computer turns
on, the bootloader goes through a number of steps that reads this into memory and begins executing
the code in the kernel.

### Or in more detail...

#### Binary file

This is the result of running a compiler on a text file. For languages like C, Golang and Rust,
you're not meant to run code directly from a text file. As a result, we use a compiler to parse the
text file, do some optimizations on the code, and generate assembly language which are instructions
that can be directly executed on your CPU. These instructions are stored in a binary file
and on Linux, this is in a format called ELF. Try running `objdump -d /usr/bin/yes` to see what the
`yes` command on Linux looks like in assembly.

#### Bootloader

We're not going to get into this in too much detail but it lives in a designated part of your disk.
Your hardware knows to load it and the bootloader is responsible for bringing to the operating
system up.

#### Reading into memory

Just like you might read a text file in a programming language like Python, you can also read a
binary file into memory. The catch here is that what we're doing with the binary data is
executing it, not processing text. This means mapping it into an _address space_. An address space
means a section of RAM and in the case of operating systems, there is a chunk of a RAM
that is reserved for the kernel code and data. (On the assignment, you should be aware of this as
compiling code requires special memory address flags to put the code in the proper address space.)

#### Executing code

CPUs execute instructions and every chip architecture (`x86_64`, `arm`, `mips`, etc.) has a
different set of instructions that it permits. The compiler targets a chip, generates instructions
for that chip, and when a program is run, those instructions are passed to the CPU for execution.

## But what are kernel modules?

Kernel modules essentially allow you to dynamically load and unload parts of the operating system
at run time. As opposed to _everything_ available in the kernel having to be chosen when it's
compiled, this allows modules to be loaded and removed as needed. This can have stability
and performance benefits.

### Mechanics

#### First, `dlopen()`

`dlopen()` is a function call that is responsible for loading dynamic libraries on Linux. It opens
a compiled binary library file and reads in the assembly instructions and incorporates that code
into the running program.

#### How does that relate to kernel modules?

You can think of kernel module loading as a more complicated `dlopen()`. It takes kernel code and
maps it into kernel space and activates it. Each kernel module has two main function entry points:
one when the kernel is loaded for initialization and one when the kernel is removed for cleanup.
