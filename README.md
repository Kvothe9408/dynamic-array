# First Dynamic Array (C)

## Description
A dynamic array implemented in C.

## Overview
A dynamic array is a memory allocation that can hold values and expand, if the number of values that need to fit into the array exceeds the array capacity. So, it fixes the problems a static array has, which is that once the numbers needing to be inputed into the array exceeds its capacity, then a new array needs to be created with more memory slots and all the data needs to be transferred. None of this happens automatically.

## API / Functions
`dynarray *create(int capacity);` 
- creates an array of size "capacity"
`void push(dynarray *arr, int value);`
- pushes an integer "value" into the next available open slot in the array. To do so, the function bounds checks count and capacity before pushing the value. If no more memory slots are available, then the function doubles the array capacity.
`int get(dynarray *arr, int index);` 
- finds the value at the "index" slot in the array
`void free_array(dynarray *arr);`
- frees up both the memory allocated to the array and to the pointer struct of the array

## Design Decisions
At this stage, I wasn't making any design decisions, since it's so early in the learning process but there were two more involved parts to the code. 
- push(): In order to push data into the array we first need to check both the count and the capacity to make sure the data being pushed has a place to go otherwise triggering realloc to create additional memory slots before pushing the data into this expanded array.
- get(): To get a piece of data from a specific array, we first need to check the count to make sure the get() function isn't trying to look at a negative slot, which isn't possible, or beyond the count. Slots beyond count but within capacity exist in memory but contain garbage values left over from malloc — returning those would be a silent bug with no error signal.

## How to compile and run
```
gcc -o dynarray dynarray.c -Wall -Wextra -fsanitize=address
./dynarray
```
## Next Steps
I am moving on to linked lists now as my next smallest building block on the way to building a mini computer.