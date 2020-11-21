#include<stdio.h>
#include<string.h>

int main(){
    printf("29. Pointers and Strings");
    // String is an array of characters that ends with a NULL character '\0'
    // char str_name[str_len] = "string"
    // When we provide a string literal to initialize the string, the compiler
    // automatically adds NULL character '\0' to the char array.
    // So, we must declare the array atleast one character longer than the actual length.
    // If initial length is not given, the lenght will be calculated based on initialization + 1.
    char str1[6] = "hello";
    char str2[] = "world"; // size: 6
    // String can also be declared as a set of characters
    // With this, the NULL character should be added explicitly.
    char str3[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char str4[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    // Character are enclosed in single quotes
    // name of the string is pointer.
    // A string pointer declaration, such as char * str = "stuff", is considered as a constant, and cannot be changed.
    // To safely and conveniently operate with strings, we use standard library string.h
    /*
    strlen()
    strcat(): merge two strings
    strcpy(): copy one string to another
    strlwr(): convert string to lower case
    strupr(): upper case
    strrev(): reverse string
    strcmp(): compare two strings
    */
    // To retrive a line of text, or other string from the user, we have
    // scanf(), gets(), and fgets() functions
    char firstName[25];
    int age;
    printf("Enter first name: \n");
    scanf("%s %d", firstName, &age);
    // scanf() stops reading when it reaches space
    // To read a string with spaces, we use gets()
    // It reads input until a terminating new line is reached (Enter key is pressed.)
    char fullName[50];
    printf("Enter full name: \n");
    gets(fullName);
    // A safer alternative to gets() is fgets(), which reads up to specified number of charcters.
    // This approach helps prevent a buffer overflow, which happens when the string array isn't 
    // big enough for the typed text.
    char fullName1[100];
    printf("Enter full Name: \n");
    fgets(fullName1, 100, stdin);
    // fgets arguments are: string name, no. of characters to read, and pointer to where we want to read from
    // stdin: standard input
    // Another difference between gets and fgets is that, newline character is stored by fgets.
    // fgets() reads only n-1 characters from stdin because there must be room for '\0'.

    printf("30. String Output");
    // String output is handled with fputs(), puts(), and printf() functions
    // fputs() needs name of string and a pointer to where we want to print the string.
    // To print on screen, we need stdout.
    char city[40];
    printf("Enter favourite city: \n");
    gets(city);
    // fgets(city, 40, stdin)
    fputs(city, stdout);
    printf(" is a fun city.");
    puts(city);
    // puts() function takes only a string argument and can also be used to display output.


    printf("31. The sprintf and sscanf functions");
    // Formatted string can be created using sprintf() function.
    // Used for building a string from other data types.
    char info[100];
    char dept[] = "HR";
    int emp = 75;
    sprintf(info, "The %s department has %d employees.", dept, emp);
    prinft("%s\n", info);
    // sscanf(): for scanning a string for values
    // Function read values from a string and stores them at the corresponding variable addresses.
    char info2[] = "Snoqualmie WA 13190";
    char city[50];
    char state[50];
    int population;
    sscanf(info2, "%s %s %d", city, state, &population);
    printf("%d people live in %s, %s.", population, city, state);

    printf("32. string.h library");
    // strcat(str1, str2) returns concatenation of str1 and str2 and returns the pointer to str1.
    // strcpy(str1, str2) copies str2 to str1.
    char s1[] = "The grey fox";
    char s2[] = " jumped.";
    strcat(s1, s2);
    printf("%s\n", s1);
    printf("Length of s1 is %d\n", strlen(s1));
    strcpy(s1, s2);
    printf("s1 is now %s \n", s1);
    /*
    Additional functions:
    strncat(str1, str2, n): Appends(concatenates) first n characters of str2 at the end of str1.
    strncpy(str1, str2, n)
    strcmp(str1, str2): Returns 0 when str1 is equal to str2, less than 0 when str1 < str2, and greater than 0 when str1 > str2
    strncmp(str1, str2, n): 
    strchr(str1, c): Returns a pointer to the first occurance of char c in str1, or NULL if character not found.
    strrchr(str1, c): Searches str1 in reverse and returns a pointer to the position of char c in str1, or NULL
    strstr(str1, str2): Returns a pointer to the first occurrence of str2 in str1, or NULL if str2 not found.
    */
    
    printf("33. Converting a String to a number\n");
    // stdio contains these functions
    // int atoi(str): ascii to int : 0 is returned if first character is not a number or no numbers are encountered.
    // double atof(str): ascii to float.: 0.0 is returned.
    // long int atol(str): ascii to long
    char input[10];
    int num;
    printf("Enter a number: \n");
    gets(input);
    num = atoi(input);
    // atoi lacks error handling.
    // It is recommended to use strtol() if we want to make sure that proper error handling is done.

    printf("34. Array of Strings\n");
    // 2D char array
    char trip[3][15]= {
        "suitcase",
        "passport",
        "ticket"
    };
    // Declare a size large enough to store everything.

    return 0;
}