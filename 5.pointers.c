#include<stdio.h>

void test(int k);
void swap(int *x, int *y);
int addUp(int *a, int no);
int * get_evens();

int main(){
    printf("23. Pointers\n");
    // scanf() uses pointers
    // &var gives address of a variable
    int num;
    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("%d", num);
    // &num is address of num
    // Memory address is given as Hexadecimal (base 16)
    int i=0;
    printf("The address of i is %x\n", &i);
    test(i);
    printf("The address of i is %x\n", &i);
    test(i);
    // the address of variable remains the same.
    // Easily work with memory locations
    // Pointer is a variable that contains the address of another variable
    // Points to the location assigned to a variable and can indirectly access the variable
    // pointer_type *identifier
    // Asterisk * declares the pointer
    int j= 63;
    int *p = NULL;
    p = &j;
    printf("The address of j is %x\n", &j);
    printf("p contains the address %x\n", p);
    printf("The value of j is %d\n", j);
    printf("p is pointing to the value %d\n", *p);
    // Pointers should be initialized to NULL if not assigned.
    // Pointers can be assigned value of address of var using Ampersand (&) sign
    // To see what pointer is pointing to , use *.
    // * is indicating dereference operator. Process is called dereferencing.
    // Some algorithms uses pointer to pointer: **
    int x = 12;
    *p = NULL;
    int **ptr = NULL;
    p = &x;
    ptr = &p;
    
    printf("24. Pointers in Expressions\n");
    x = 5;
    int y;
    *p = NULL;
    p = &x;
    y = *p + 2;
    y += *p;
    *p = y;
    (*p)++; // parentheses () is required here.
    printf("p is pointing to the value %d\n", *p);

    printf("25. Pointers and Arrays\n");
    // + move forward of the memory location, - backward
    int a[5] = {22, 33, 44, 55, 66};
    int *ptr = NULL;
    int i;
    ptr = a;
    for(i=0; i<5; i++){
        printf("%d ", *(ptr + i));
    }
    // array name acts as the pointer to the first element of the array
    // ptr = a can be thought as ptr = &a[0];
    // Address arithmetic can also be thought of as pointer arithmetic because the operations involve pointers
    *ptr = NULL;
    ptr = a;
    printf("%d %x\n", *ptr, ptr); //22
    ptr++;
    printf("%d %x\n", *ptr, ptr); //33
    ptr += 3;
    printf("%d %x\n", *ptr, ptr);   //66
    ptr--;
    printf("%d %x\n", *ptr, ptr);   //55
    ptr -=2;
    printf("%d %x\n", *ptr, ptr);   //33
    // When a pointer is incremented, the memory address increases by the number of bytes 
    // being pointed to.
    // We can also use ==, < and > operators to compare pointer addresses.

    printf("26. Pointers and Functions\n");
    // With pointer parameters, functions can actually alter actual data rather than a copy of data.
    // We can just pass address of variables rather than just reference values.
    x = 5;
    y = 100;
    printf("x is %d, y is %d\n", x, y);
    swap(&x, &y);
    printf("x is %d, y is %d\n", x, y);

    printf("27. Functions with Array Parameters\n");
    int order[5] = {100, 200, 37, 16, 98};
    printf("Total order is %d\n", addUp(order, 5));

    printf("28. Functions that return Array\n");
    // A pointer to an array can also be returned
    int *e;
    int k;
    e = getEvens();
    for(k=0; k<5; k++){
        printf("%d \n", e[k]);
    }
    // We should note that e[k] is same as *(e + k);
    return 0;
}

void test(int k){
    printf("The address of k is %x\n", &k);
}

void swap(int *num1, int* num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int addUp(int *a, int no){
    int total = 0;
    int k;
    for(k=0; k<no; k++){
        total += a[k];
    }

    return total;
}

int * getEvens(){
    // When a local variable is being returned from a function, it should be defined as static
    static int nums[5];
    int k;
    int even = 0;
    for(k=0; k<5; k++){
        nums[k] = (even += 2);
    }
    return nums;
}