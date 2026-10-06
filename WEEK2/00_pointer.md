# C Programming – Pointers

## Foundation for Data Structures and Algorithms

> [!info] Course Objective  
> The goal of this lesson is not only to learn pointers as a C language feature, but also to understand **why pointers are essential for Data Structures and Algorithms**.
> 
> A student who understands pointers well will be able to:
> 
> - Understand arrays more deeply.
>     
> - Understand reference-like behavior in functions.
>     
> - Manage dynamic memory.
>     
> - Build Linked Lists.
>     
> - Understand Trees and Graphs.
>     
> - Implement dynamic Stacks and Queues.
>     
> - Write safer and more memory-conscious C programs.
>     

---

# 1. Before Pointers: What Is Memory?

When a C program runs, the variables we create are stored in the computer's **RAM**.

For example:

```
int x = 10;
```

This statement does not simply mean:

> Create a variable named `x` and store `10` inside it.

In reality, the system reserves an area in memory.

For example:

|Memory Address|Content|
|---|---|
|0x1000|?|
|0x1004|10|
|0x1008|?|
|0x100C|?|

Hypothetically:

```
Address of x = 0x1004
Value of x   = 10
```

> [!important]  
> Memory addresses can change between systems and even between different executions of the same program.
> 
> Addresses such as `0x1000` and `0x1004` are used only for educational purposes.

---

# 2. Value and Address

Every variable has two important properties:

1. Its **value**
    
2. Its **memory address**
    

Example:

```
int x = 10;
```

We can think of it like this:

```
Variable name: x
Value:         10
Address:       0x1004
```

Memory representation:

```
flowchart LR
    X["x"] --> M["Memory Address: 0x1004"]
    M --> V["Value: 10"]
```

---

# 3. The Address Operator `&`

In C, we use the:

```
&
```

operator to obtain the address of a variable.

Example:

```
#include <stdio.h>

int main() {
    int x = 10;

    printf("%d\n", x);
    printf("%p\n", (void*)&x);

    return 0;
}
```

Here:

```
x
```

returns the value.

While:

```
&x
```

returns the memory address of `x`.

An example output might be:

```
10
0x7ffd2a311abc
```

---

# 4. What Is a Pointer?

A pointer is:

> **A variable that stores the memory address of another variable.**

A normal variable:

```
int x = 10;
```

stores a value.

A pointer:

```
int *p = &x;
```

stores an address.

For example:

```
x = 10
address(x) = 0x1000

p = 0x1000
```

Memory representation:

```
flowchart LR
    P["p<br/>0x1000"] --> X["x<br/>10"]
```

Another way to visualize it:

```
p -----> x
          10
```

The name itself gives us the idea:

**pointer → pointing → points to something**

A pointer **points to** another location in memory.

---

# 5. Declaring a Pointer

We use `*` when declaring a pointer.

```
int *p;
```

This means:

> `p` is a pointer that can store the address of an `int`.

Example:

```
int x = 10;
int *p;

p = &x;
```

Shorter version:

```
int x = 10;
int *p = &x;
```

---

# 6. Pointer Types

The type of a pointer should match the type of the variable it points to.

```
int x = 10;
int *p = &x;
```

```
float temperature = 23.5;
float *pTemperature = &temperature;
```

```
char letter = 'A';
char *pLetter = &letter;
```

General form:

```
data_type *pointer_name;
```

Examples:

```
int *p;
double *d;
char *c;
float *f;
```

---

# 7. Two Different Uses of `*`

This is one of the most commonly confused topics.

The `*` symbol is used in two different situations.

## 7.1 Pointer Declaration

```
int *p;
```

Here, `*` means:

> `p` is a pointer.

## 7.2 Accessing the Pointed Value

```
*p
```

Here, `*` means:

> Go to the address stored inside `p` and access the value there.

This operation is called:

**dereferencing**

---

# 8. First Pointer Example

```
#include <stdio.h>

int main() {

    int x = 10;
    int *p = &x;

    printf("x = %d\n", x);
    printf("&x = %p\n", (void*)&x);

    printf("p = %p\n", (void*)p);
    printf("*p = %d\n", *p);

    return 0;
}
```

Conceptually:

```
x   = 10
&x  = address of x
p   = address of x
*p  = 10
```

Therefore:

```
p == &x
```

and:

```
*p == x
```

---

# 9. Visualizing a Pointer

Code:

```
int x = 10;
int *p = &x;
```

Memory:

```
flowchart LR
    P["p<br/>Stored Address: 0x1000"]
    X["x<br/>Address: 0x1000<br/>Value: 10"]

    P --> X
```

The pointer itself also has its own memory address.

For example:

```
x:
address = 0x1000
value   = 10

p:
address = 0x2000
value   = 0x1000
```

This distinction is very important.

```
p
```

and:

```
&p
```

are not the same.

---

# 10. Difference Between `p`, `*p`, and `&p`

Example:

```
int x = 10;
int *p = &x;
```

Now:

|Expression|Meaning|
|---|---|
|`x`|Value of x|
|`&x`|Address of x|
|`p`|Address stored inside p|
|`*p`|Value at the address stored in p|
|`&p`|Address of the pointer variable p|

Therefore:

```
p == &x
```

and:

```
*p == x
```

---

# 11. Modifying a Value Through a Pointer

Pointers do not only read values.

They can also modify the variables they point to.

```
#include <stdio.h>

int main() {

    int x = 10;

    int *p = &x;

    *p = 50;

    printf("%d\n", x);

    return 0;
}
```

Output:

```
50
```

Why?

Because:

```
*p = 50;
```

means:

> Go to the address stored in `p` and write `50` there.

Since `p` points to `x`:

```
x = 50
```

---

# 12. Step-by-Step Pointer Example

```
int a = 5;
int *p = &a;
```

Initial state:

```
a = 5
```

```
flowchart LR
    P["p"] --> A["a = 5"]
```

Then:

```
*p = 20;
```

New state:

```
flowchart LR
    P["p"] --> A["a = 20"]
```

Therefore:

```
printf("%d", a);
```

prints:

```
20
```

---

# 13. Why Do We Need Pointers?

At this point, a natural question appears:

> "If I can already access a variable using its name, why do I need a pointer?"

For example, instead of:

```
int x = 10;
int *p = &x;
*p = 20;
```

we could simply write:

```
int x = 10;
x = 20;
```

So why use pointers?

The real power of pointers appears in:

1. Modifying variables through functions
    
2. Arrays
    
3. Strings
    
4. Dynamic memory management
    
5. Structs
    
6. Linked Lists
    
7. Trees
    
8. Graphs
    
9. Dynamic Stacks
    
10. Dynamic Queues
    

---

# 14. Passing a Normal Parameter to a Function

Example:

```
#include <stdio.h>

void change(int x) {
    x = 100;
}

int main() {

    int number = 10;

    change(number);

    printf("%d\n", number);

    return 0;
}
```

Output:

```
10
```

Why is it not `100`?

Because C uses:

> **pass by value**

---

# 15. Pass by Value

Example:

```
int number = 10;

change(number);
```

Function:

```
void change(int x) {
    x = 100;
}
```

Conceptually:

```
flowchart LR
    N["main()<br/>number = 10"]
    X["change()<br/>x = 10"]

    N -. "value copied" .-> X
```

`x` and `number` are different variables.

Therefore:

```
x = 100;
```

does not modify `number`.

---

# 16. Passing a Pointer to a Function

Now let us pass the **address** of the variable.

```
#include <stdio.h>

void change(int *p) {
    *p = 100;
}

int main() {

    int number = 10;

    change(&number);

    printf("%d\n", number);

    return 0;
}
```

Output:

```
100
```

Why?

Because:

```
change(&number);
```

passes the address of `number`.

The parameter:

```
int *p
```

receives that address.

Then:

```
*p = 100;
```

modifies the value stored at that address.

---

# 17. Function Call with Pointer

```
flowchart LR
    M["main()<br/>number = 10"]
    P["change()<br/>p"]

    P -->|"points to"| M
```

The function now has access to the memory location of the original variable.

---

# 18. Very Important Example: Swap

Suppose we have:

```
a = 10
b = 20
```

After swapping:

```
a = 20
b = 10
```

---

# 19. Incorrect Swap Function

```
void swap(int a, int b) {

    int temp = a;

    a = b;
    b = temp;
}
```

Usage:

```
int x = 10;
int y = 20;

swap(x, y);
```

This does not work as expected.

Why?

Because the function receives copies of:

```
10
20
```

---

# 20. Correct Swap with Pointers

```
#include <stdio.h>

void swap(int *a, int *b) {

    int temp = *a;

    *a = *b;
    *b = temp;
}

int main() {

    int x = 10;
    int y = 20;

    swap(&x, &y);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
```

Output:

```
x = 20
y = 10
```

---

# 21. How Swap Works in Memory

Initial state:

```
x = 10
y = 20
```

```
flowchart TD
    A["Pointer a"] --> X["x = 10"]
    B["Pointer b"] --> Y["y = 20"]
```

After:

```
int temp = *a;
```

we have:

```
temp = 10
```

Then:

```
*a = *b;
```

results in:

```
x = 20
```

Finally:

```
*b = temp;
```

results in:

```
y = 10
```

---

# 22. Relationship Between Pointers and Arrays

This is one of the most important parts for Data Structures and Algorithms.

In C, arrays and pointers are closely related.

Example:

```
int numbers[5] = {10, 20, 30, 40, 50};
```

Memory:

```
numbers[0] numbers[1] numbers[2] numbers[3] numbers[4]
    10         20         30         40         50
```

Assume `int` is 4 bytes.

```
Address      Value

0x1000       10
0x1004       20
0x1008       30
0x100C       40
0x1010       50
```

---

# 23. Array Name Represents the Beginning Address

Example:

```
int numbers[5] = {10, 20, 30, 40, 50};
```

In most expressions:

```
numbers
```

decays into the address of the first element.

That means:

```
numbers
```

and:

```
&numbers[0]
```

represent the same starting address.

Example:

```
printf("%p\n", (void*)numbers);
printf("%p\n", (void*)&numbers[0]);
```

Both should print the same address value.

---

# 24. Accessing Array Elements with Pointers

```
int numbers[5] = {10, 20, 30, 40, 50};

int *p = numbers;
```

Now:

```
*p
```

is:

```
10
```

because `p` points to the first array element.

```
flowchart LR
    P["p"] --> A0["numbers[0]<br/>10"]
    A0 --- A1["numbers[1]<br/>20"]
    A1 --- A2["numbers[2]<br/>30"]
    A2 --- A3["numbers[3]<br/>40"]
    A3 --- A4["numbers[4]<br/>50"]
```

---

# 25. Pointer Arithmetic

Arithmetic operations can be performed on pointers.

For example:

```
p + 1
```

moves the pointer to the **next element of the same type**.

Important:

If:

```
int *p;
```

and `int` is 4 bytes, then:

```
p + 1
```

does not move 1 byte.

It moves to the next `int`, typically 4 bytes forward.

---

# 26. Pointer Arithmetic Example

```
int numbers[5] = {10, 20, 30, 40, 50};

int *p = numbers;
```

Now:

```
*p
```

→ `10`

```
*(p + 1)
```

→ `20`

```
*(p + 2)
```

→ `30`

```
*(p + 3)
```

→ `40`

```
*(p + 4)
```

→ `50`

---

# 27. Relationship Between Array Indexing and Pointer Arithmetic

In C:

```
numbers[i]
```

can conceptually be understood as:

```
*(numbers + i)
```

For example:

```
numbers[2]
```

and:

```
*(numbers + 2)
```

produce the same value.

Example:

```
#include <stdio.h>

int main() {

    int numbers[5] = {10, 20, 30, 40, 50};

    printf("%d\n", numbers[2]);
    printf("%d\n", *(numbers + 2));

    return 0;
}
```

Output:

```
30
30
```

---

# 28. Traversing an Array with Pointers

Traditional version:

```
for (int i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
}
```

Pointer arithmetic version:

```
for (int i = 0; i < 5; i++) {
    printf("%d\n", *(numbers + i));
}
```

Using a separate pointer:

```
int *p = numbers;

for (int i = 0; i < 5; i++) {
    printf("%d\n", *(p + i));
}
```

---

# 29. Incrementing a Pointer

We can also write:

```
int *p = numbers;

for (int i = 0; i < 5; i++) {
    printf("%d\n", *p);

    p++;
}
```

First iteration:

```
p -> numbers[0]
```

Second:

```
p -> numbers[1]
```

Third:

```
p -> numbers[2]
```

---

# 30. Why Pointer Type Matters

Suppose:

```
int *p;
```

When `p++` is performed, the pointer moves to the next `int`.

If:

```
char *p;
```

it moves to the next `char`.

Typical sizes:

```
char   = 1 byte
int    = 4 bytes
double = 8 bytes
```

So pointer arithmetic depends on the pointed-to type.

---

# 31. Checking Sizes with `sizeof`

```
#include <stdio.h>

int main() {

    printf("char: %zu byte\n", sizeof(char));
    printf("int: %zu byte\n", sizeof(int));
    printf("double: %zu byte\n", sizeof(double));

    return 0;
}
```

A common result:

```
char:   1
int:    4
double: 8
```

However, the C standard does not guarantee exactly the same sizes on every architecture.

---

# 32. Pointer Size

A pointer stores an **address**.

Therefore, pointer size usually depends on the system architecture.

On many 64-bit systems:

```
8 bytes
```

Example:

```
printf("%zu\n", sizeof(int *));
printf("%zu\n", sizeof(char *));
printf("%zu\n", sizeof(double *));
```

A common 64-bit output is:

```
8
8
8
```

The pointed-to types differ, but each pointer stores an address.

---

# 33. Passing an Array to a Function

Example:

```
void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
```

This can also be written as:

```
void printArray(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
```

In a function parameter:

```
int arr[]
```

and:

```
int *arr
```

represent the same underlying parameter mechanism.

---

# 34. Array Function Example

```
#include <stdio.h>

void printArray(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {

    int numbers[] = {10, 20, 30, 40, 50};

    printArray(numbers, 5);

    return 0;
}
```

---

# 35. Modifying an Array Inside a Function

```
void doubleValues(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}
```

Usage:

```
int numbers[] = {1, 2, 3, 4, 5};

doubleValues(numbers, 5);
```

Result:

```
2 4 6 8 10
```

The original array is modified.

---

# 36. Strings and Pointers

C does not have a separate built-in string type.

A string is:

> an array of `char`.

Example:

```
char name[] = "Kursat";
```

Memory:

```
K u r s a t \0
```

The final character:

```
'\0'
```

is called the null terminator.

---

# 37. Traversing a String with a Pointer

```
#include <stdio.h>

int main() {

    char name[] = "Hello";

    char *p = name;

    while (*p != '\0') {

        printf("%c\n", *p);

        p++;
    }

    return 0;
}
```

The pointer moves like:

```
H -> e -> l -> l -> o -> \0
```

---

# 38. NULL Pointer

A safe initialization is:

```
int *p = NULL;
```

`NULL` means:

> The pointer currently does not point to a valid object.

Example:

```
if (p == NULL) {
    printf("Pointer does not point anywhere.\n");
}
```

---

# 39. Dangerous Pointer Usage

This is dangerous:

```
int *p;

*p = 10;
```

because `p` contains an unknown address.

Such a pointer is often called a:

**wild pointer**

Safer alternatives:

```
int *p = NULL;
```

or:

```
int x = 10;
int *p = &x;
```

---

# 40. NULL Pointer Dereference

This is invalid:

```
int *p = NULL;

printf("%d", *p);
```

because `p` does not point to a valid object.

Possible consequences include:

- segmentation fault
    
- access violation
    
- undefined behavior
    

---

# 41. Pointer to Pointer

A pointer is itself a variable.

Therefore, it also has an address.

Another pointer can store that address.

Example:

```
int x = 10;

int *p = &x;

int **pp = &p;
```

Here:

```
x  = integer
p  = pointer to integer
pp = pointer to pointer to integer
```

---

# 42. Double Pointer Visualization

```
flowchart LR
    PP["pp"] --> P["p"]
    P --> X["x = 10"]
```

Now:

```
x
```

→ `10`

```
*p
```

→ `10`

```
**pp
```

→ `10`

---

# 43. Double Pointer Example

```
#include <stdio.h>

int main() {

    int x = 10;

    int *p = &x;

    int **pp = &p;

    printf("%d\n", x);
    printf("%d\n", *p);
    printf("%d\n", **pp);

    return 0;
}
```

Output:

```
10
10
10
```

---

# 44. Where Are Double Pointers Used?

In Data Structures and Algorithms, they often appear in:

```
Linked Lists
Trees
Dynamic 2D arrays
Functions that need to modify a pointer
```

For example:

```
void insert(Node **head, int value);
```

Here:

```
Node **head
```

is a double pointer.

---

# 45. Basic Memory Regions of a Program

Conceptually, program memory can be represented as:

```
flowchart TB

    CODE["Code / Text<br/>Program instructions"]

    DATA["Data<br/>Global / static variables"]

    HEAP["Heap<br/>Dynamic memory"]

    SPACE["..."]

    STACK["Stack<br/>Local variables / function calls"]

    CODE --> DATA
    DATA --> HEAP
    HEAP --> SPACE
    SPACE --> STACK
```

For pointer programming, two regions are especially important:

- Stack
    
- Heap
    

---

# 46. What Is the Stack?

Normal local variables are usually stored on the stack.

Example:

```
void test() {

    int x = 10;
    int y = 20;
}
```

`x` and `y` exist during the function's execution.

When the function returns, the lifetime of those local variables ends.

---

# 47. What Is the Heap?

The heap is:

> A region of memory where the program can allocate memory dynamically at runtime.

In C, common functions are:

```
malloc()
calloc()
realloc()
free()
```

They are declared in:

```
#include <stdlib.h>
```

---

# 48. Why Dynamic Memory?

Consider:

```
int numbers[100];
```

This array has a fixed size.

But suppose the program asks:

```
How many students are there?
```

The user may enter:

```
12547
```

If we do not know the required size while writing the program, we may want to allocate memory at runtime.

This is called:

**dynamic memory allocation**

---

# 49. `malloc()`

`malloc`:

> Allocates a requested number of bytes.

Example:

```
int *p;

p = malloc(sizeof(int));
```

A common style is:

```
int *p = malloc(sizeof *p);
```

Always check the result:

```
if (p == NULL) {
    return 1;
}
```

---

# 50. `malloc` Example

```
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *p = malloc(sizeof *p);

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *p = 25;

    printf("%d\n", *p);

    free(p);
    p = NULL;

    return 0;
}
```

---

# 51. Memory After `malloc`

Code:

```
int *p = malloc(sizeof(int));
```

Conceptually:

```
flowchart LR

    subgraph STACK[Stack]
        P["p"]
    end

    subgraph HEAP[Heap]
        X["Allocated int"]
    end

    P --> X
```

Then:

```
*p = 50;
```

```
flowchart LR

    subgraph STACK[Stack]
        P["p"]
    end

    subgraph HEAP[Heap]
        X["50"]
    end

    P --> X
```

---

# 52. Dynamic Array

Let us read the array size from the user.

```
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("Number of elements: ");
    scanf("%d", &n);

    int *numbers = malloc(n * sizeof *numbers);

    if (numbers == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        numbers[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }

    free(numbers);
    numbers = NULL;

    return 0;
}
```

---

# 53. Logic of a Dynamic Array

Suppose:

```
n = 5
```

and:

```
sizeof(int) = 4
```

Then:

```
malloc(5 * sizeof(int))
```

requests approximately:

```
20 bytes
```

Conceptual heap:

```
Heap:

+----+----+----+----+----+
|    |    |    |    |    |
+----+----+----+----+----+
  0    1    2    3    4
```

Pointer:

```
numbers
   |
   v
+----+----+----+----+----+
```

---

# 54. `calloc()`

`calloc` also allocates memory.

Example:

```
int *numbers = calloc(5, sizeof *numbers);
```

A major difference:

`calloc` initializes the allocated bytes to zero.

Conceptually:

```
0 0 0 0 0
```

---

# 55. `malloc` vs `calloc`

|Feature|malloc|calloc|
|---|---|---|
|Allocates memory|Yes|Yes|
|Zero-initializes memory|No|Yes|
|Parameters|Total byte count|Element count + element size|

Example:

```
malloc(10 * sizeof(int));
```

```
calloc(10, sizeof(int));
```

---

# 56. `realloc()`

`realloc` changes the size of a previously allocated memory block.

Example:

```
int *numbers = malloc(5 * sizeof *numbers);
```

Later, we need 10 elements:

```
int *temp = realloc(numbers, 10 * sizeof *numbers);

if (temp != NULL) {
    numbers = temp;
}
```

`realloc` may:

- resize the existing block,
    
- or move the data to another location.
    

Therefore, assigning the result directly back to the original pointer can be risky.

---

# 57. `free()`

When dynamically allocated memory is no longer needed:

```
free(pointer);
```

should be used.

Example:

```
int *p = malloc(sizeof *p);

*p = 50;

free(p);
p = NULL;
```

---

# 58. Memory Leak

Allocating memory without releasing it causes a:

**memory leak**

Example:

```
void example() {

    int *p = malloc(1000 * sizeof *p);

}
```

There is no `free()`.

When the function ends, the pointer variable `p` disappears.

However, the allocated heap block was not properly released.

In long-running programs, this can become a serious problem.

---

# 59. Dangling Pointer

Consider:

```
int *p = malloc(sizeof *p);

*p = 10;

free(p);
```

After `free`, `p` may still contain the old address.

But that memory is no longer valid for use.

This is called a:

**dangling pointer**

A useful habit is:

```
free(p);
p = NULL;
```

---

# 60. Pointer Safety Summary

Three important situations:

### Wild Pointer

```
int *p;
```

The pointer was not initialized.

---

### NULL Pointer

```
int *p = NULL;
```

The pointer intentionally points to no valid object.

---

### Dangling Pointer

```
int *p = malloc(sizeof *p);

free(p);
```

The pointer may still contain the address of memory that is no longer valid.

---

# 61. Structs and Pointers

Now we move toward Data Structures.

Let us define a student:

```
struct Student {

    int id;
    float grade;
};
```

Create an object:

```
struct Student student;

student.id = 100;
student.grade = 85.5;
```

---

# 62. Pointer to Struct

We can store the address of a struct in a pointer.

```
struct Student student;

struct Student *p = &student;
```

To access members, we could write:

```
(*p).id
```

Example:

```
(*p).id = 100;
```

However, C provides a more convenient syntax.

---

# 63. Arrow Operator `->`

When accessing members through a struct pointer:

```
p->id
```

can be used.

These are equivalent:

```
(*p).id
```

and:

```
p->id
```

Example:

```
p->id = 100;
p->grade = 85.5;
```

---

# 64. Struct Pointer Example

```
#include <stdio.h>

struct Student {

    int id;
    float grade;
};

int main() {

    struct Student student;

    struct Student *p = &student;

    p->id = 101;
    p->grade = 90.5;

    printf("ID: %d\n", p->id);
    printf("Grade: %.2f\n", p->grade);

    return 0;
}
```

---

# 65. Transition to Data Structures

Now we can see why pointers are fundamental for Data Structures and Algorithms.

Let us define a node:

```
struct Node {

    int data;

};
```

This only stores data.

Now add:

```
struct Node {

    int data;

    struct Node *next;
};
```

Now one Node can store the address of another Node.

This allows us to build a:

**Linked List**

---

# 66. Linked List Idea

Example:

```
10 -> 20 -> 30
```

Conceptually:

```
flowchart LR

    N1["Node<br/>data = 10"] --> N2["Node<br/>data = 20"]
    N2 --> N3["Node<br/>data = 30"]
    N3 --> NULL["NULL"]
```

The connections are pointers.

---

# 67. Linked List Node Definition

```
struct Node {

    int data;

    struct Node *next;
};
```

Each node contains:

```
data
next
```

Conceptually:

```
+------+-------+
| data | next  |
+------+-------+
```

`next` stores:

> the address of the next Node.

---

# 68. Creating the First Node

```
struct Node *head;

head = malloc(sizeof *head);
```

Then:

```
if (head == NULL) {
    return 1;
}

head->data = 10;
head->next = NULL;
```

Now:

```
head
 |
 v
+------+------+
|  10  | NULL |
+------+------+
```

---

# 69. Adding a Second Node

```
struct Node *second;

second = malloc(sizeof *second);

if (second == NULL) {
    free(head);
    return 1;
}

second->data = 20;
second->next = NULL;

head->next = second;
```

Result:

```
flowchart LR

    H["head"] --> N1["10"]
    N1 --> N2["20"]
    N2 --> NULL["NULL"]
```

We have now created a simple Linked List using pointers.

---

# 70. Traversing a Linked List

```
struct Node *current = head;

while (current != NULL) {

    printf("%d\n", current->data);

    current = current->next;
}
```

Conceptually:

```
current = first node

current = second node

current = third node

...

current = NULL
```

Unlike arrays, we do not use:

```
i++
```

to move to the next node.

Instead:

```
current->next
```

takes us there.

---

# 71. Array vs Linked List

Array:

```
[10][20][30][40]
```

Elements are usually stored in contiguous memory.

Linked List:

```
[10|next] ---> [20|next] ---> [30|next]
```

Nodes may be located in different parts of memory.

For example:

```
Node 10 -> Address 0x1000

Node 20 -> Address 0x8F30

Node 30 -> Address 0x45A0
```

Pointers connect these separate memory blocks.

---

# 72. Linked List in Memory

```
flowchart LR

    H["head<br/>0x1000"]

    A["Address 0x1000<br/>data: 10<br/>next: 0x8F30"]

    B["Address 0x8F30<br/>data: 20<br/>next: 0x45A0"]

    C["Address 0x45A0<br/>data: 30<br/>next: NULL"]

    H --> A
    A --> B
    B --> C
```

This structure would not be possible without pointers.

---

# 73. Transition to Trees

Pointers also allow one node to point to multiple nodes.

Binary Tree example:

```
struct TreeNode {

    int data;

    struct TreeNode *left;
    struct TreeNode *right;
};
```

Each node can now store:

```
left child address
right child address
```

---

# 74. Binary Tree Visualization

```
graph TD

    A["10"]
    B["5"]
    C["20"]
    D["3"]
    E["7"]

    A --> B
    A --> C

    B --> D
    B --> E
```

The connections are pointers.

Conceptually, each node contains:

```
+--------+------+-------+
|  left  | data | right |
+--------+------+-------+
```

---

# 75. Graph Structures

Pointers are also frequently used in Graph implementations.

For example, an adjacency-list representation may look like:

```
A -> B -> C

B -> A -> D

C -> A

D -> B
```

Therefore, pointer knowledge leads naturally toward:

```
Pointer
   ↓
Dynamic Memory
   ↓
Linked List
   ↓
Stack / Queue
   ↓
Tree
   ↓
Graph
```

---

# 76. Pointer Roadmap for Data Structures

```
flowchart TD

    P["Pointers"]

    A["Arrays"]
    F["Functions"]
    DM["Dynamic Memory"]
    S["Struct"]

    LL["Linked List"]

    ST["Stack"]
    Q["Queue"]

    T["Tree"]
    G["Graph"]

    P --> A
    P --> F
    P --> DM
    P --> S

    DM --> LL
    S --> LL

    LL --> ST
    LL --> Q

    LL --> T
    LL --> G
```

---

# 77. Using `const` with Pointers

We may also encounter `const`.

Example:

```
const int *p;
```

This means:

> Do not modify the pointed-to integer through `p`.

Example:

```
int x = 10;

const int *p = &x;
```

This is not allowed:

```
*p = 20;
```

---

# 78. Making the Pointer Itself Constant

```
int *const p = &x;
```

Here, the pointer's stored address cannot change.

But the pointed value can.

```
*p = 20;
```

is valid.

But:

```
p = &y;
```

is not.

---

# 79. Both Pointer and Data Constant

```
const int *const p = &x;
```

Now:

- `p` cannot point somewhere else.
    
- The value cannot be modified through `p`.
    

This is not essential for the first pointer lesson, but it appears frequently in real C programs.

---

# 80. `void *` Pointer

C provides the generic pointer type:

```
void *
```

Example:

```
void *p;
```

It can hold addresses of different object types.

`malloc()` also returns:

```
void *
```

Therefore, in C:

```
int *numbers = malloc(10 * sizeof *numbers);
```

works directly.

Casting `malloc` to `(int *)` is not necessary in C and is generally avoided.

---

# 81. Common Mistake: Forgetting `&`

Incorrect:

```
int x = 10;
int *p = x;
```

Here, `x` is:

```
10
```

But the pointer expects an address.

Correct:

```
int *p = &x;
```

---

# 82. Common Mistake: Incorrect Dereferencing

```
int x = 10;
int *p = &x;
```

Remember:

```
p
```

is an address.

```
*p
```

is the value at that address.

A useful question to constantly ask:

> "Do I currently have an address, or do I currently have a value?"

---

# 83. Common Mistake: Uninitialized Pointer

Incorrect:

```
int *p;

*p = 10;
```

Correct:

```
int x;

int *p = &x;

*p = 10;
```

or:

```
int *p = malloc(sizeof *p);

if (p != NULL) {
    *p = 10;
}
```

---

# 84. Common Mistake: NULL Dereference

Incorrect:

```
int *p = NULL;

*p = 10;
```

A pointer can be checked before dereferencing:

```
if (p != NULL) {

    *p = 10;
}
```

---

# 85. Common Mistake: Using Memory After `free()`

Incorrect:

```
int *p = malloc(sizeof *p);

*p = 10;

free(p);

printf("%d", *p);
```

This is called:

**use-after-free**

Once `free()` is called, the program should no longer access that memory through the old pointer.

---

# 86. Common Mistake: Double Free

Incorrect:

```
free(p);
free(p);
```

Freeing the same memory twice can cause undefined behavior.

Preferred pattern:

```
free(p);
p = NULL;
```

Calling:

```
free(p);
```

when `p == NULL` is safe in C.

---

# 87. Common Mistake: Going Out of Array Bounds

```
int numbers[5];
```

Valid indexes are:

```
0
1
2
3
4
```

This is invalid:

```
numbers[5] = 100;
```

Similarly:

```
*(numbers + 5) = 100;
```

accesses memory beyond the array.

This causes **undefined behavior**.

---

# 88. Simple Pointer Question

Code:

```
int x = 5;

int *p = &x;

*p = 20;

printf("%d", x);
```

What is the output?

## Answer

```
20
```

Because `p` points to `x`.

---

# 89. Pointer Question 2

```
int x = 10;

int *p = &x;

int *q = p;

*q = 30;

printf("%d", x);
```

What is the output?

## Answer

```
30
```

Because both `p` and `q` point to the same variable.

```
p ----+
      |
      v
      x

q ----+
```

---

# 90. Pointer Question 3

```
int a = 10;
int b = 20;

int *p = &a;

p = &b;

*p = 50;
```

Final values:

```
a = ?
b = ?
```

## Answer

```
a = 10
b = 50
```

Because after:

```
p = &b;
```

`p` points to `b`.

---

# 91. Pointer Question 4

```
int numbers[] = {5, 10, 15, 20};

int *p = numbers;

printf("%d", *(p + 2));
```

Output:

```
15
```

Because:

```
p + 2
```

points to the third element.

---

# 92. Pointer Question 5

```
int numbers[] = {10, 20, 30};

int *p = numbers;

p++;

printf("%d", *p);
```

Answer:

```
20
```

---

# 93. Pointer Question 6

```
int x = 5;

int *p = &x;

int **pp = &p;

**pp = 50;

printf("%d", x);
```

Answer:

```
50
```

---

# 94. Classroom Example – Finding the Maximum Using a Pointer

```
#include <stdio.h>

int *findMax(int *arr, int size) {

    if (size <= 0) {
        return NULL;
    }

    int *max = arr;

    for (int i = 1; i < size; i++) {

        if (arr[i] > *max) {
            max = &arr[i];
        }
    }

    return max;
}

int main() {

    int numbers[] = {10, 40, 15, 80, 25};

    int *result = findMax(numbers, 5);

    if (result != NULL) {
        printf("Max = %d\n", *result);
    }

    return 0;
}
```

Important point:

The function does not return the maximum value itself.

It returns:

> the address of the maximum element.

---

# 95. Critical Rule for Functions Returning Pointers

This is incorrect:

```
int *createNumber() {

    int x = 10;

    return &x;
}
```

`x` is a local variable.

When the function returns, the lifetime of `x` ends.

Therefore, returning its address creates an invalid pointer.

---

# 96. Correct Approach with Dynamic Memory

```
int *createNumber() {

    int *p = malloc(sizeof *p);

    if (p == NULL) {
        return NULL;
    }

    *p = 10;

    return p;
}
```

Usage:

```
int *number = createNumber();

if (number != NULL) {

    printf("%d\n", *number);

    free(number);
    number = NULL;
}
```

---

# 97. Pointers and Algorithms

Pointers are not only used in data structures.

They also appear in algorithms such as:

- Array traversal
    
- Binary search
    
- Sorting
    
- Two Pointer Technique
    
- Sliding Window
    
- Linked List algorithms
    
- Tree traversal
    
- Graph traversal
    

---

# 98. Two Pointer Technique

Suppose we have a sorted array:

```
1 2 4 6 8 9
```

We want two numbers whose sum is `10`.

One pointer starts from the left:

```
L
↓
1 2 4 6 8 9
          ↑
          R
```

The other starts from the right.

```
1 + 9 = 10
```

A pair is found.

In algorithm terminology, "pointer" may sometimes mean an index rather than an actual C pointer.

However, the idea is similar:

> Maintain references to different positions in a data structure.

---

# 99. Reversing an Array with Pointers

```
#include <stdio.h>

void reverse(int *arr, int size) {

    int *left = arr;

    int *right = arr + size - 1;

    while (left < right) {

        int temp = *left;

        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int main() {

    int numbers[] = {1, 2, 3, 4, 5};

    reverse(numbers, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
```

Result:

```
5 4 3 2 1
```

---

# 100. Array Reverse Visualization

Initial state:

```
 L           R
 ↓           ↓
[1][2][3][4][5]
```

Swap:

```
[5][2][3][4][1]
```

Then:

```
    L     R
    ↓     ↓
[5][2][3][4][1]
```

Swap:

```
[5][4][3][2][1]
```

The algorithm ends when the pointers meet.

---

# 101. How to Read Pointer Declarations

Do not memorize pointer syntax blindly.

Break it into meaning.

Example:

```
int *p;
```

Ask:

> What is `p`?

Answer:

```
A pointer to an integer.
```

---

```
int **p;
```

Ask:

> What is `p`?

Answer:

```
A pointer to a pointer to an integer.
```

---

```
struct Node *next;
```

Ask:

> What is `next`?

Answer:

```
A pointer to a Node.
```

---

# 102. Pointer Thinking Model

When solving pointer problems, ask four questions:

### 1. What address does the pointer currently store?

```
p = ?
```

### 2. What value exists at that address?

```
*p = ?
```

### 3. What is the pointer type?

```
int *
char *
Node *
```

### 4. Is the pointed-to object still valid?

Check:

```
Is it NULL?
Has it been freed?
Has it gone out of scope?
```

---

# 103. Summary Table

|Syntax|Meaning|
|---|---|
|`int x`|Integer variable|
|`&x`|Address of x|
|`int *p`|Pointer to integer|
|`p = &x`|p points to x|
|`*p`|Value pointed to by p|
|`p++`|Move to the next element of the pointed-to type|
|`int **pp`|Pointer to pointer|
|`malloc()`|Allocate dynamic memory|
|`calloc()`|Allocate zero-initialized dynamic memory|
|`realloc()`|Resize dynamic memory|
|`free()`|Release dynamic memory|
|`NULL`|Pointer to no valid object|
|`p->x`|Access a struct member through a pointer|

---

# 104. What Must Be Understood Before Linked Lists?

Before moving to Linked Lists, a student should understand:

- Difference between a variable and its memory address
    
- `&` operator
    
- Pointer declaration
    
- Dereference operator `*`
    
- Modifying a value through a pointer
    
- Passing pointers to functions
    
- Array-pointer relationship
    
- Pointer arithmetic
    
- `NULL`
    
- `malloc`
    
- `free`
    
- Structs
    
- Struct pointers
    
- `->` operator
    

Once these are understood, the student is ready for:

```
Linked List
```

---

# 105. Mini Exercise 1

Create an integer.

Modify its value through a pointer.

```
int number = 10;
```

Expected result:

```
Before: 10
After: 100
```

---

# 106. Mini Exercise 2

Write the following function:

```
void increment(int *number);
```

The function should increment the integer by `1`.

Example:

```
int x = 10;

increment(&x);

printf("%d", x);
```

Expected output:

```
11
```

---

# 107. Mini Exercise 3

Use pointers to swap two integers.

Function:

```
void swap(int *a, int *b);
```

---

# 108. Mini Exercise 4

Print the following array using pointer arithmetic:

```
int numbers[] = {3, 6, 9, 12, 15};
```

Try solving it without:

```
numbers[i]
```

Instead use:

```
*(numbers + i)
```

---

# 109. Mini Exercise 5

Write a function that calculates the sum of an array using pointers.

Function:

```
int sum(int *arr, int size);
```

Input:

```
1 2 3 4 5
```

Expected result:

```
15
```

---

# 110. Mini Exercise 6

Write a function that returns the **address** of the largest element in an array.

```
int *findMax(int *arr, int size);
```

---

# 111. Mini Exercise 7

Read:

```
n
```

from the user.

Use `malloc` to create a dynamic integer array of size `n`.

Read the values from the user.

Calculate the average.

Finally release the memory using:

```
free()
```

---

# 112. Mini Exercise 8 – Preparation for Data Structures

Create this struct:

```
struct Node {

    int data;

    struct Node *next;
};
```

Dynamically create two Nodes.

Their values should be:

```
10
20
```

Create:

```
10 -> 20 -> NULL
```

Then print both values using pointers.

---

# 113. Pointer Debugging Question

Find the problem:

```
int *p;

*p = 50;

printf("%d", *p);
```

## Problem

`p` was not initialized.

## Solution

```
int x;

int *p = &x;

*p = 50;
```

or with dynamic memory:

```
int *p = malloc(sizeof *p);

if (p != NULL) {

    *p = 50;

    free(p);
    p = NULL;
}
```

---

# 114. Pointer Debugging Question 2

```
int *create() {

    int x = 10;

    return &x;
}
```

What is wrong?

## Answer

`x` is a local variable.

Its lifetime ends when the function returns.

Therefore, the returned pointer refers to an object that no longer exists.

---

# 115. Pointer Debugging Question 3

```
int *p = malloc(sizeof *p);

*p = 10;

free(p);

*p = 20;
```

Problem:

```
use-after-free
```

The program must not access the memory after `free()`.

---

# 116. Pointer Debugging Question 4

```
int numbers[5];

numbers[10] = 100;
```

Problem:

```
array bounds violation
```

The array only contains indexes:

```
0-4
```

---

# 117. End-of-Lesson Conceptual Question

Consider:

```
int x = 10;

int *p = &x;

int **q = &p;
```

Explain the meaning of:

```
x
```

```
&x
```

```
p
```

```
*p
```

```
&p
```

```
q
```

```
*q
```

```
**q
```

---

# 118. Answer

```
x
```

→ `10`

---

```
&x
```

→ address of x

---

```
p
```

→ address of x

---

```
*p
```

→ `10`

---

```
&p
```

→ address of p

---

```
q
```

→ address of p

---

```
*q
```

→ value stored in p → address of x

---

```
**q
```

→ value of x → `10`

---

# 119. Complete Pointer Summary

The basic pointer chain is:

```
flowchart LR

    V["Variable"]

    A["Address<br/>&x"]

    P["Pointer<br/>p = &x"]

    D["Dereference<br/>*p"]

    V --> A
    A --> P
    P --> D
    D --> V
```

A variable has:

```
a value
```

and also:

```
a memory address
```

A pointer:

```
stores that address.
```

Dereferencing:

```
accesses the value stored at that address.
```

---

# 120. Big Picture for Data Structures

The main reason we learn pointers is:

```
flowchart TD

    MEMORY["Memory"]

    ADDRESS["Memory Address"]

    POINTER["Pointer"]

    ARRAY["Arrays"]

    DYNAMIC["Dynamic Memory"]

    STRUCT["Struct"]

    NODE["Node"]

    LINKED["Linked List"]

    STACK["Stack"]

    QUEUE["Queue"]

    TREE["Tree"]

    GRAPH["Graph"]

    MEMORY --> ADDRESS

    ADDRESS --> POINTER

    POINTER --> ARRAY
    POINTER --> DYNAMIC

    STRUCT --> NODE
    DYNAMIC --> NODE

    NODE --> LINKED

    LINKED --> STACK
    LINKED --> QUEUE

    NODE --> TREE
    NODE --> GRAPH
```

Pointers are not an isolated C topic.

Pointers are:

> **The basic mechanism that allows dynamic data structures to connect objects in memory.**

---

# 121. Next Lesson: Linked List

The natural next topic after pointers is:

## Singly Linked List

Our first structure will be:

```
typedef struct Node {

    int data;

    struct Node *next;

} Node;
```

And our first goal will be to create:

```
head
 |
 v
+----+-----+     +----+-----+     +----+------+
| 10 |  *------->| 20 |  *------->| 30 | NULL |
+----+-----+     +----+-----+     +----+------+
```

To build this structure, we will combine almost everything learned in this lesson:

```
struct
+
pointer
+
malloc
+
NULL
+
dereference
+
free
```

---

# End-of-Lesson Review Questions

1. What is a pointer?
    
2. What does the `&` operator do?
    
3. What are the two different uses of `*`?
    
4. What is the difference between `p` and `*p`?
    
5. What does `&p` mean?
    
6. Why would we pass a pointer to a function?
    
7. What does pass-by-value mean in C?
    
8. What is the relationship between `arr[i]` and `*(arr + i)`?
    
9. How many bytes does `p++` move?
    
10. What is a NULL pointer?
    
11. What is a wild pointer?
    
12. What is a dangling pointer?
    
13. What does `malloc` do?
    
14. What is the difference between `calloc` and `malloc`?
    
15. What does `realloc` do?
    
16. Why should `free` be used?
    
17. What is a memory leak?
    
18. What does `struct Node *next` mean?
    
19. What is the relationship between `p->data` and `(*p).data`?
    
20. Why are pointers necessary for Linked Lists?
    

---

# Main Message of the Lesson

> [!important]  
> Do not think of pointers as a difficult C topic that is only about using the `*` symbol.
> 
> The core idea is much simpler:
> 
> **One variable knows where another piece of data is located in memory.**
> 
> Many data structures are built on exactly this principle:
> 
> **"One piece of data knows where another piece of data is."**

```
Linked List:

Node knows the next Node
```

```
Tree:

Node knows its left and right children
```

```
Graph:

Vertex knows connected vertices
```

Therefore:

```
Memory
   ↓
Address
   ↓
Pointer
   ↓
Node
   ↓
Data Structures
```

That is the core idea behind pointers.