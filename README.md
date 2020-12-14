# Malloc-Simulation

## Malloc() and Free()

In C language array is a collection of a fixed number of values. Once the size of an array is declared, you cannot change it. sometimes the size of the array you declared may be insufficient. To solve this issue, you can allocate memory manually during run-time. This is known as **dynamic memory allocation** in C programming. To allocate memory dynamically, library functions are malloc(), calloc(), realloc() and free() are used. These functions are defined in the <stdlib.h> header file.

### malloc()

The name “malloc” stands for memory allocation. The malloc() function reserves a block of memory of the specified number of bytes. And, it returns a pointer of void which can be cast into a pointer of any form.

Syntax of malloc()

ptr = (castType*) malloc(size);

Example:-   ptr = (float*) malloc(100 * sizeof(float));

The above statement allocates 400 bytes of memory. It’s because the size of float is 4 bytes. And, the pointer ptr holds the address of the first byte in the allocated memory.

The expression results in a NULL pointer if the memory cannot be allocated.

### free()
Like other languages in C dynamically allocated memory created with malloc() doesn’t get freed on its own. the developer must explicitly use free() to release the space he allocated previously.

Syntax of free()

free(ptr);

### In this “Malloc and Free” Simulation,

25000 Bytes long array considered as memory and all allocation are done using that memory. The simulated version of malloc() is called MyMalloc() and the simulated version of free() is called MyFree().

Like in real malloc(), First MyMalloc() function requires size as a parameter, and then the function will allocate that much of memory from that 25000 bytes pool (it search best-fit memory location for that given size of memory and allocate it ). Finally, the function returns its pointer.

![memory_image](https://diigopost.files.wordpress.com/2015/06/malloc_implementation.png)
<br>
When an allocation is happening, 25000 Bytes of the memory pool divide into the various size of memory blocks. To connect those memory blocks, all memory blocks are put into the linked-list. Every memory block is connected to two other blocks except head and tail blocks. To track the information about those memory blocks, meta-data is used.  Every memory block has its meta-data section. meta-data will track whether that block is allocated or not, the size of the block, and the pointer of the next block.

MyFree() is also requires a pointer of allocated memory as a parameter and working exactly like real free() 
function set the allocated block as free by changing the metadata of that allocated memory block. Then check whether's next or/and previous blocks are free, if those are free, those blocks are merged with newly freed block and create a new block.

### Files 
- mymalloc.c  - implementation of MyMalloc()/MyFree()
- mymalloc.h  - Declarations related to MyMalloc()/MyFree()
- testCases.c - Sample Test Cases
