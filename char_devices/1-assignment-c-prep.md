# Assignment #1: Become more familiar with C pointers and structs

This assignment is meant to introduce you to some fundamental concepts around the semantics of the programming language C.
In this assignment you'll be asked to update source code to print a series of outputs to the terminal. This involves
understanding structs and pointers.

## Background

### Pointer
A pointer is memory address. You can think of it like a mailing address. It is unique
to the piece of data you're pointing at. Much like the number 5 can be stored in two separate
memory addresses and be completely independent, two people named Kim can live at two separate
mailing addresses and be different people. If two letters to Kim go to the same memory address (two
pointers are stored in different variables but have the same value), they still go to the same
Kim, not two different Kims.

Concrete examples:

```
// Two separate Kims

// This is one Kim
int kim1 = 5;
// This is the other
int kim2 = 5;

// This is one Kim's mailing address - the & symbol indicates taking the address of the 5
// in the variable kim1
int *kim1address = &kim1;

// This is the other Kim's mailing address
int *kim2address = &kim2;

// Print out both Kims - "%d" is the string that says print this variable as an integer
// and *kim1address says look up the Kim living at kim1address
printf("%d", *kim1address);
// Should print 5 to the terminal
printf("%d", *kim2address);
// Should also print 5 to the terminal
```

Interestingly, you can alter the value at an address and if another variable points to the same
address, that change will be visible from both pointers. However if the pointers point at two
separate locations, it will only affect one of those values.

Concrete example:

```
// Two separate Kims

// This is one Kim
int kim1 = 5;
// This is the other
int kim2 = 5;

// This is one Kim's mailing address - the & symbol indicates taking the address of the 5
// in the variable kim1
int *kim1address = &kim1;

// This is the other Kim's mailing address
int *kim2address = &kim2;

// Now we alter kim1 using kim1address
*kim1 = 6;

// Print out kim1 and kim2 values
printf("%d", *kim1address);
printf("%d", kim1);
// These two are equilvalent and should both print out 6 now
printf("%d", *kim2address);
printf("%d", kim2);
// These two are equivalent and should both print out 5 still
```

### Struct

A struct is declared as follows:

```
struct this_is_the_struct_name {
    int this_is_an_integer_field;
    int this_is_another_integer_field;
    char *this_is_a_pointer_
}
```
