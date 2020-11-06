# Reference Counter
This is an algorithm for automatic garbage collector using reference counter.

The automatic garbage collector is a mechanism which remove areas in the memory that is not being used automatically without the command of a programmer.

How the reference counter method works:
- A reference counter is keeper for each area of allocated memory.
- The reference counter is update after each alteration of the counter for an area.
- Case the reference counter of an area is equal zero that means the area of allocated memory isn't being referenced.So, this area will be releasead automaticaly.
