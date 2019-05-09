# Assignment #1: Write a "Hello world" kernel module

As mentioned in the notes, kernel modules have two main entry points: one function when kernel
modules are loaded and one when kernel modules are removed. For this assignment, we're going to
keep it simple as this might by your first time writing in C.

## Requirements

* When `sudo insmod ./hello.ko` is run from the command line, "Hello world!" should be printed
in the kernel logs - you can check this by running `dmesg | tail -30` which will output the last
30 lines of the kernel logs and your message should appear somewhere in the 30 lines printed

* When `sudo rmmod ./hello.ko` is run from the command line, "Goodbye world!" should be printed
in the kernel logs

* Please try to stay away from Googling "how to write a kernel module" as this assignment can
be copied and pasted directly from most of the examples that come up from that search and you
won't really learn anything

* Googling general C questions is totally fine as I want you to understand how to work with the
language

## Smaller steps
* The `printk()` function will allow you to print to the kernel logs - read up on how to use
this function.

* Define `init_module()` and `cleanup_module()` in your kernel module. `init_module()` should contain
the code to print "Hello world!" and `cleanup_module()` should contain the code to print "Goodbye
world!".

* To test your kernel module, run `make` in the `c/` directory of this repo to build, and then
run `sudo insmod ./hello.ko` or `sudo rmmod ./hello.ko` to load or remove the module. `dmesg` will
show you whether you've successfully loaded it or not.

## Tips
* To use `printk()`, your file must begin with the following lines:

```
#include <linux/module.h>
#include <linux/kernel.h>
```

This is the C equivalent of importing a library kind of like in JavaScript. In this case,
this will allow you to use general kernel functions and module specific functions.
