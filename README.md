# Reference Counting
This is an algorithm for automatic garbage collector using reference counting.

The automatic garbage collector is a mechanism which remove areas in the memory that is not being used anymore without the command of a programmer.

## How it works
- There is a reference counter for each area of allocated memory
- The reference counter is updated after every change in the counter of an area
- If the reference counter of an area is equal to zero, which means that the area of the allocated memory isn't being referenced, then this area will be set free automaticaly
