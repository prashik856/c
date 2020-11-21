#include<stdio.h>
#include<stdlib.h>

void sayHello(int numTimes);
int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);

void* square(const void* num);

int compare(const void*, const void *);

int main(){
    printf("35. Function Pointers\n");
    // Pointers can also be used to point to the start of executable code.
    // function pointers
    // Function pointers can be stored in an array or passed as arguments to other functions.
    // return_type (*func_name) (parameters)
    // parantheses around (*func_name) is important. Without them, compiler will think that the function is
    // returning a pointer.
    void (*funcPtr) (int); // Function pointer
    funcPtr = sayHello; // Function pointer assignment
    funcPtr(3); // Function call
    // Function name points to the start of the executable code.
    funcPtr = &sayHello;
    (*funcPtr)(3);
    // Both are correct.

    printf("36. Array of Function Pointers\n");
    int x, y, choice, result;
    int (*op[4]) (int, int);
    op[0] = add;
    op[1] = subtract;
    op[2] = multiply;
    op[3] = divide;
    printf("Enter two integers: \n");
    scanf("%d%d", &x, &y);
    printf("Enter 0 to add, 1 to subtract, 2 to multiply, 3 to divide: \n");
    scanf("%d", &choice);
    result = op[choice](x,y);
    printf("%d\n", result);

    printf("37. The void pointer\n");
    // Used to refer to any addres type in memory
    // void *ptr;
    x = 33;
    float z = 34.3;
    char c = 'a';
    void *ptr;
    ptr = &x;
    printf("void ptr points to %d\n", *((int *)ptr));
    ptr = &z;
    printf("void ptr points to %f\n", *((float *)ptr));
    ptr = &c;
    printf("void ptr points to %c\n", *((char *)ptr));
    // When dereferencing a void pointer, we must first type cast the pointer to appropriate data type
    // before dereferencing with *
    // We cannot perform pointer arithmetic with void pointers.

    printf("38. Functions using void Pointers\n");
    // void * square(const void *);
    // Using a void * return type allows for any return type.
    // Similarly, parameters that are void * accepty any argument type.
    // If we want to use the data passed in by the parameter without changing it, we declare it const.
    int sqInt;
    x = 6;
    sqInt = square(&x);
    printf("%d squared is %d\n", x, sqInt);
    // Square is written to multiply only ints. So it is type casted to int.
    // If implementation were to be chagned to allow square() to multiply floats, 
    // then only the definition need to be changed whichout having to make changes to
    // the declaration.

    printf("39. Function Pointers as Arguments\n");
    // Another way to use a function pointer is to pass it as an argument to another function.
    // A function pointer used as an argument is sometimes referred to as a callback function 
    // because the receiving function "calls it back".
    // qsort() function in stdlib.h hader file uses this technique.
    // To implement quicksort, we can include stdlib.h and use qsort() function.
    //void qsort(void *base, size_t num, size_t width, int (*compare) (const void *, const * void));
    // void* base: A void pointer to an array
    // size_t num: number of elements in the array
    // size_t width: the size of an element
    // int(*compare)(const void *, const void *): A function pointer.
    // This function pointer returns 0 when arguments have the same value, <0 when arg1 comes before arg2,
    // and >0 when arg1 comes after arg2.

    return 0;
}

void sayHello(int numTimes){
    int k;
    for(k=0; k<numTimes; k++){
        printf("Hello\n");
    }
}

int add(int x, int y){
    return(x+y);
}

int subtract(int x, int y){
    return(x-y);
}

int multiply(int x, int y){
    return x*y;
}

int divide(int x, int y){
    if(y != 0){
        return(x/y);
    }
    else{
        return 0;
    }
}

void* square(const void *num){
    int result;
    result = (*(int*)num) * (*(int*)num);
    return result;
}

int compare(const void *elem1, const void *elem2){
    if((*(int*)elem1) == (*(int*)elem2)){
        return 0;
    }
    else if((*(int *)elem1) < (*(int *)elem2)){
        return -1;
    }
    else{
        return 1;
    }
}