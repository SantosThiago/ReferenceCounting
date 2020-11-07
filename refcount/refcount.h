#ifndef REFCOUNT_H
#define REFCOUNT_H

typedef struct memory //reference list that contains the dates of all declared pointers
{
    void *adress;
    int counter;
    struct memory *next;

}memory;

void clearAll(); //clear the reference list
void printRefList(); //print the reference list
void updateReferenceList(memory *element,int counter); //update the reference list after every attribution of pointers
void *malloc2(int size_); //pointer to  an allocated a space of memory and create an element in the reference list linked to this pointer
void atrib2(void **receiver,void *transmitter); //transfer date of a pointer to other, receiver=transmitter

#endif // REFCOUNT_H
