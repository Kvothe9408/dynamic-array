// includes are the standard functions I will be using in this program
#include <stdio.h>  // gives me printf
#include <stdlib.h> // gives me the main functions like malloc, realloc, free, exit, NULL

//My defititions
typedef struct{ // typedef is the defintion of XYZ in this case a struct, so a bundle of variables
    int count; // tells me how much data is in the array
    int capacity; // tells me how much memory total has been allocated
    int *data; // is the pointer pointing to the address with the data in memory
} dynarray; // name of the struct

//My functions
dynarray *create(int capacity) {
    dynarray *arr = (dynarray *)malloc(sizeof(dynarray)); // creates memory space for the array struct, which we already previously defined
    if (arr == NULL) { // checks if the memory allocation suceeded, if not it will return NULL?
        printf("allocation failed\n");
        return NULL;
    }
    arr->data = (int *)malloc(sizeof(int) * capacity); // create the memory allocation for the data in the array, size 10 slots
    if (arr->data == NULL) {
        printf("allocation failed\n");
        return NULL;
    }
    arr->count = 0; // sets the starting positions of the array to count 0
    arr->capacity = capacity; // how much memory is currently allocated
    return arr;
}
void push(dynarray *arr, int value) { // push function to append new interger (int value) to the end
    if (arr->count >= arr->capacity) { // you need the -> to point the machine at the right type of thing to look at within the data. this line checks if the count of the array is equal to or larger than the capacity of the array
        arr->capacity = arr->capacity * 2; // stores capacity as double of the old capacity
        arr->data = (int *)realloc(arr->data,sizeof(int) * arr->capacity); // points to the actual data in the array and resizes it to the new capacity from above
        if (arr->data == NULL) { // checks if the reallocation happened
            printf("allocation failed\n");
            return; // no NULL needed because void was used at the beginning of the function just terminates after successful completion without returning anything
        }
    }
    arr->data[arr->count] = value; // adds the value in the function to the end of the expanded memory
    arr->count = arr->count + 1; // I have to add this to make sure the computer recognizes that something was added to the count within the struct ("count + 1" can also be written as "count++""
}

int get(dynarray *arr, int index) { //index is used here by convention to indicate that i am looking at a slot in the array
    if (index < 0) { // need to check if the program is trying to look for a negative memory slot, which isn't possible but i need to be explict about it
        printf("negative value\n"); 
        return -1; // -1 by convention is what should be returned by the program is the get function is searching beyond the count
    }
    if (index >= arr->count) { //checking if the index is searching for data beyond the count, so data that is living in the memory allocation for this array
        printf("value exceeds count\n");
        return -1; // -1 by convention is what should be returned by the program is the get function is searching beyond the count
    }
   return arr->data[index]; // this returns the value at the searched index by going to the data in the array at that specific memory slot
}

void free_array(dynarray *arr) { //freeing the memory in the dynarray pointing toward arr
    free(arr->data); // frees the actual data in the array
    free(arr); // frees the memory allocted to the pointer of the array
}

int main() { // this is the main function we perform once all the functions and defintiions have been defined previously. By convention main functions are integer return functions in C, In this instance main is empty, which i don't 100% understand why but will leave for now
    dynarray *arr= create(10); // since something new is being created, i need to give the new thing, in this case an array a name for the remainder of the program to run. this is different from the subsequent calls, which don't need that.
    push(arr, 7); // calling push function
    printf("%d\n", get(arr, 0)); // calls get and prints resutls
    free_array(arr); // freeing the memory
    return 0; // a return of 0 mean success. any other number means failure, by convention in C
} // At the end of this program, it will have created a 10 memory slot array, placed the number 7 in it, then checked the first slot (0), returned that index numebr in this case 7 and then freed the memory used to run this program 
