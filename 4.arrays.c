#include<stdio.h>

int main(){
    printf("18. Arrays\n");
    // Stores collection of data
    int testScores[25];
    float prices[5] = {3.2, 4.5, 10.4, 15.1, 0.99};
    float prices2[5] = {1.3, 0};
    // Missing values are set to 0;
    // Stored in contiguous memory locations and cannot change size after being declated.

    printf("19. Accessing array elements.\n");
    // contents of array are called elements
    int x[5] = {20, 21, 22, 23, 24};
    // index starts from 0
    printf("The second element is %d\n", x[1]);
    x[1] = 260;
    printf("The second element is %d\n", x[1]);
    // index is also referred to as subscript.

    printf("20. Loops with arrays\n");
    // Traversing the array
    float purchases[3] = {10.99, 14.25, 99.90};
    float total = 0;
    int k;
    for(k=0; k<3; k++){
        total += purchases[k];
    }
    printf("Purchases total is %6.2f\n", total);
    // Loops are useful for assignment
    int a[10];
    for(k=0; k<10; k++){
        a[k] = k*10;
    }

    printf("21. 2D Arrays\n");
    // Can be thought as a table
    int b[2][3];
    int c[2][3] = {
        {3,2,6},
        {4,5,6}
    };
    // This offers more clearity than writing it in a single line
    // Arrays can have as many dimensions as needed.

    printf("22. Accessing 2D arrays\n");
    int d[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    printf("Element 3 in row 2 is %d\n", d[1][2]);
    d[1][2] = 25;
    printf("Element 3 in row 2 is %d\n", d[1][2]);
    // Nested for loop for transversion
    int k,j;
    for(k=0; k<2; k++){
        for(j=0; j<3; j++){
            printf(" %d", d[k][j]);
        }
        printf("\n");
    }
    
    return 0;
}