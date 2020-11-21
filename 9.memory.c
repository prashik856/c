#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int num;
    char *info;
} record;

typedef struct{
    int *elements;
    int size;
    int cap;
} dynamicArray;

int main(){
    printf("53. Memory Management\n");
    // When var is declared, it is stored in stack.
    // int : 4 bytes
    int x;
    printf("%d", sizeof(x)); //4
    // Array size:
    int arr[10];
    printf("%d", sizeof(arr)); //40
    // What if array size is not decided until runtime.
    // Dynamic memory allocation.
    // Allocation and freeing memory as needed.
    // Managed with pointers.
    // Alloctes a block of memory in an area called heap.
    // Statistically managed data in main memory for variables that persist for the lifetime of the program.

    printf("54. Memory Management Functions\n");
    // stdlib.h has these functions
    // malloc(bytes): Returns a pointer to a contiguous block of memory that is of size bytes
    // calloc(num_items, item_size): Same as malloc but the allocated memory is initialized to 0.
    // realloc(ptr, bytes): Resizes the memory pointed to by ptr to size bytes. The newly allocated
    // memory is not initialized.
    // free(ptr) : Releases the block of memory pointed by the ptr.

    printf("55. Malloc Function\n");
    // Contiguous block of memory in bytes
    int *ptr;
    ptr = malloc(10*sizeof(*ptr));
    if (ptr != NULL){
        *(ptr + 2) = 50;
    }
    // Basically creating an array of 10 ints.
    // The sizeof operator was applied to *ptr instead of int, making the code more robust
    // should the *ptr declaration be changed to a different data type later.
    // This memory block can be treated as array.
    // If the allocation is unsuccessful, NULL is returned.
    // We should always check this when using malloc.
    // A simple 2d array requires (rows*columns)*sizeof(datatype) bytes of memory.
    
    printf("56. The free function\n");
    // releases memory
    int *ptr1;
    ptr1 = malloc(10*sizeof(*ptr));
    if(ptr1 != NULL){
        *(ptr1 + 2) = 50;
    }
    printf("%d\n", *(ptr1 + 2));
    free(ptr1);

    printf("57. The calloc Function\n");
    // calloc() function allocates memory based on the size of the specific item, such as a structure.
    record *recs;
    int numRecs = 2;
    int k;
    char str[] = "This is information";
    recs = calloc(numRecs, sizeof(record));
    if(recs != NULL){
        for(k=0; k<numRecs; k++){
            (recs+k)->num = k;
            (recs+k)->info = malloc(sizeof(str));
            strcpy((recs+k)->info, str);
        }
    }
    // Dynamically allocates structures are the basis of linked lists and binary trees as well as other data structures.

    printf("58. The realloc function\n");
    // expands a current block to include additional memory
    int *ptr2;
    ptr2 = malloc(10 * sizeof(*ptr2));
    if(ptr2 != NULL){
        *(ptr + 2) = 50;
    }
    ptr2 = realloc(ptr2,100*sizeof(*ptr2));
    *(ptr2 + 30) = 75;
    // realloc leaves the original content in memory and expands the block to allow for more storage.

    printf("59. Allocation memory for strings\n");
    // We may want to use string length rather than sizeof operator.
    char str20[20];
    char *str1 = NULL;
    strcpy(str20, "123456");
    str1 = malloc(strlen(str20) + 1);
    strcpy(str, str20);
    printf("%s\n", str);
    // When using strlen to determine the number of bytes needed for a string, be sure
    // to include one extra byte for the NULL character \0.

    printf("60. Dynamic Arrays\n");
    // dynamic array usually use a structure to keep track of current array size, current capacity, and a pointer 
    // to the elements
    dynamicArray dyArr;
    dyArr.size = 0;
    dyArr.elements = calloc(1, sizeof(*dyArr.elements));
    dyArr.cap = 1;
    // To exapand more elements
    dyArr.elements = realloc(dyArr.elements, (5+dyArr.cap)*sizeof(*dyArr.elements));
    if (dyArr.elements != NULL){
        dyArr.cap += 5;
    }
    // Adding an element to the array increases it's size.
    if(dyArr.size < dyArr.cap){
        dyArr.elements[dyArr.size] = 50;
        dyArr.size++;
    } else{
        printf("Need to expand the array");
    }
    // We can distibute this task as follows:
    // init_array(), increase_array(), add_element(), and display_array().

    return 0;
}