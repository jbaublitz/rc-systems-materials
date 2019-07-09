# Notes

This should give you enough of an understanding of C to begin the assignment on coding in C.

## Background

### Comments
A single line comment is done like so in C:
```
// This is a comment - the compiler will ignore it

// The next line is not a comment - it's C code that defines an integer!
int not_a_comment;
```

A multiline comment looks like this:
```
/*
 * By convention, the first line is usually left without text
 * and every new line just begins with a * directly below the * on the previous line
 *
 * This convention is just for readability
 *
 * It can technically be formatted however you want other than the first two and last two
 * characters of the comment but don't do that! You want people to be able to easily read
 * your documentation, right?
 */

/* basically everything between "forward slash asterisk" and "asterisk forward slash" is ignored */

// so the comment above ^ is still using multiline syntax
```

I will use comments in code snippets to explain code so it doesn't look quite as arbitrary
as it usually does when learning a language.

### Declarations

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

/* 
 * This is one Kim's mailing address - the & symbol indicates taking the address of the 5
 * in the variable kim1
 */
int *kim1address = &kim1;

// This is the other Kim's mailing address
int *kim2address = &kim2;

/* 
 * Print out both Kims - "%d" is the string that says print this variable as an integer
 * and *kim1address says look up the Kim living at kim1address
 */
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

/* 
 * This is one Kim's mailing address - the & symbol indicates taking the address of the 5
 * in the variable kim1
 */
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
    // This is how strings are represented in C, as an array of characters - yes, it's not pretty
    char *this_is_a_string_field;
};
```

Structs have two different types of syntax.

One is for accessing fields of structs when the
variable is not a pointer to a struct (usually this means it is stack allocated).

```
struct a_struct {
    /* 
     * int is 32 bits which means it can hold a number up to pow(2, 32) - 1 where pow() here means
     * "two to the power of thirty-two"
     */
    int this_is_an_integer;
    // short is typically only 16 bits and can hold pow(2, 16) - 1
    short this_is_a_smaller_int;
};

/* Declare that the struct is typed as "struct a_struct"-type - this will allocate memory on the
 * stack for it to be used later and initializes the values stored there from the beginning
 *
 */ NOTE: It is good practice to
struct a_struct example_struct = {
    // This initializes the first field with 100
    .this_is_an_integer = 100,
    // This initializes the second field with 10
    .this_is_a_smaller_integer = 10,
};

// Access variable this_is_an_integer
example_struct.this_is_an_integer;

// Print variable this_is_an_integer
printf("%d", example_struct.this_is_an_integer);
```

The other type of syntax is for accessing a field of a struct where the variable is a pointer
to a struct.

```
struct a_struct {
    int this_is_an_integer;
    short this_is_a_smaller_int;
};

struct a_struct a = {
    .this_is_an_integer = 1000,
    .this_is_a_smaller_integer = 1,
};

// Pointer to variable a
struct a_struct *a_ptr = &a;

// Access this_is_an_integer
a_ptr->this_is_an_integer;

// Print this_is_an_integer
printf("%d", a_ptr->this_is_an_integer);
```
