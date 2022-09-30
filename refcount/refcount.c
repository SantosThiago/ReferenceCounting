#include <stdio.h>
#include <stdlib.h>
#include "refcount.h"

memory *ref_list=NULL; //global var for the initialization of the reference list

void clearAll() //runs all the list removing each element for liberate space before end the program
{
    memory *aux=ref_list;
    while (aux!=NULL)
    {
        free(aux->adress);
        free(aux);
        aux=aux->next;
    }
}

void printRefList() //runs all the list printing your elements
{
    memory *aux=ref_list;
    while (aux!=NULL)
    {
        printf("adress:%d\t",aux->adress);
        printf("ref:%d\n",aux->counter);
        aux=aux->next;
    }
}

void updateReferenceList(memory *element, int counter)  //updates the quantify of references to a pointer
                                                        //checks if a pointer is still being referenced by the list
{ 
    element->counter += counter;
    if (element->counter == 0)
    {
        if (ref_list->next != NULL)
        {
            memory *runner = ref_list;
            if (runner !=element)
            {
                while (runner->next != element)
                {
                    runner = runner->next;
                }
                runner->next = element->next;
            }
            else
            {
                ref_list = element->next;
            }
        }
        free(element->adress);
        free(element);
    }
}

void *malloc2(int size_) //pointer to  an allocated a space of memory and create an element in the reference list linked to this pointer
{
    void *new_allocated_memory = (void *)malloc(size_);
    memory *new_reference_list_element = (memory *)malloc(sizeof(memory));
    new_reference_list_element->adress = new_allocated_memory;
    new_reference_list_element->counter = 1;
    new_reference_list_element->next = NULL;
    if (ref_list == NULL)
    {
        ref_list= new_reference_list_element;
    }
    else
    {
        memory *aux = ref_list;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = new_reference_list_element;
    }
    return new_allocated_memory;
}

void atrib2(void **receiver, void *transmitter) //transfer date of a pointer to other
{                                               //makes the control of the references to pointers
    if ((*receiver) != NULL)
    {
        memory *run_list = ref_list;
        while (run_list->adress != (*receiver))
        {
            run_list = run_list->next;
        }
        updateReferenceList(run_list, -1);
        if (transmitter != NULL)
        {
            (*receiver) = transmitter;
            run_list = ref_list;
            while (run_list->adress !=transmitter)
            {
                run_list = run_list->next;
            }
            updateReferenceList(run_list, 1);
        }
        else
        {
            (*receiver)=NULL;
        }
    }
}
