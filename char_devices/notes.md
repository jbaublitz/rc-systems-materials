# Char devices

## What is a char device?

Last time, we discussed kernel modules. Char devices are a class of Linux kernel modules that expose a
"pretend" file to use as an interface for passing data to and from the kernel.

### What does this mean?

Run `ls /dev` on your Linux box. Many of the files listed in that directory, including `/dev/tty*`, are
char devices. This means when you read from or write to those files, the data is passed to the kernel.

### What is the interface for files then?

File objects in the kernel run kernel code on each `read`/`write` call to the file. What this practically
translates to is that if you run `read(your_file_descriptor, ...)`, the driver responsible for those
types of reads and writes will run that code to handle the syscall invocation.

You can think of it like this:

```
read(file_descriptor, ...) -> file descriptor points to a file object in the kernel -> file_object.read()
```

In the case of char devices, the char device driver we'll write in the next assignment will define what happens
when you write to your char device file.

### Example of a Rust char device

[This](https://github.com/jbaublitz/knock-out/blob/master/src/lib.rs) is the bulk of the code for a Rust char device.
