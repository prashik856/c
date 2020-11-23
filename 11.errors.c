#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<math.h>

extern int errno;

int main(){
    printf("66. Error Handling\n");
    // Exception: Any situation that causes program to stop normal execution.
    // Error handling.
    // C does not explicitely support error handling.
    // Use errno, perror() and strerror() to identify errors through error codes.

    printf("67. The exit command\n");
    // Using exit to avoid a program crash.
    // Can return any value through exit.
    // 0 for success, -1 for failure.
    // Predefined stdlib.h macros EXIT_SUCCESS and EXIT_FAILURE are also used.
    int x1 = 10;
    int y1 = 1;
    if(y1 != 0){
        printf("x/y = %d\n", x1/y1);
    } else {
        printf("Divisor is 0. Program exiting...\n");
        exit(EXIT_FAILURE);
    }

    printf("68. Using errno\n");
    // Error code is set in a global variable named errno, which is defined in errno.h
    // When using errno, we should set it to 0 before calling a binary function.
    // To output the error code stored in errno, we use fprintf() to print to the stderr file stream, 
    // To use errno, we need to declare it with the statement extern int errno; at the top
    // of our program.
    FILE *fp;
    errno = 0;
    /*
    fp = fopen("c:\nnonexistantfileman", "r");
    if(fp == NULL){
        fprintf(stderr, "Error opening file. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    */
    

    printf("69. The perror and strerror Functions\n");
    // errno is stored in cryptic format.
    // For a more descriptive message about the error, we can use perror().
    // We can also obtain the message using strerror() in the string.h header, which returns a pointer 
    // to the message text.
    // perror() must inlcude a string that will precede the actual error message.
    FILE *fp1;
    /*
    errno = 0;
    fp = fopen("c:\nnonexistantfileman", "r");
    if(fp == NULL){
        perror("Error");
        fprintf(stderr, "Message: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    */
    // List of all errors
    int x;
    for(x = 0; x<135; x++){
        fprintf(stderr, "%d: %s\n", x, strerror(x));
    }
    printf("\n");

    printf("70.EDOM and ERANGE Error Codes\n");
    // Some functions in math.h sets these values.
    // EDOM: when a domain is out of range
    // ERANGE: macro value is used when there is a range error.
    float k = -5;
    float num = 1000;
    float result;
    errno = 0;
    result = sqrt(k);
    if (errno == 0){
        printf("%f \n", result);
    } else if (errno == EDOM){
        fprintf(stderr, "%s\n", strerror(errno));
    }
    errno = 0;
    result = exp(num);
    if(errno == 0){
        printf("%f \n", result);
    } else if (errno == ERANGE) {
        fprintf(stderr, "%s\n", strerror(errno));
    }

    printf("71. The feof and ferror Functions\n");
    FILE *fp2;
    int c;
    errno = 0;
    fp2 = fopen("myFile.txt", "r");
    if(fp2 == NULL){
        fprintf(stderr, "Error opening file, %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } 
    while((c = getc(fp2)) != EOF){
        printf("%c", c);
    }
    if(ferror(fp2)){
        printf("I/O error reading file\n");
    } else if(feof(fp2)) {
        printf("End of file reached.\n");
    }

    return 0;
}