#include<stdio.h>
#include<string.h>
#define PI 3.14
#define AREA(r) (PI*(r)*(r))
#define VERY_LONG_CONSTANT \
23.678901
#define MAX 100
#define MIN 0
# define SQUARE(x) \
    x*x
#define RATE 0.08
#ifndef TERM
  #define TERM 24
#endif
#define LEVEL 4

int main(){
    printf("72. Preprocessor Directives\n");
    // Uses # directives to make substitutions in program source code before compilation
    // E.g. #include<stdio.h> is replaced by the contents of the stdio.h header file before a program is compiled.
    // #include : including header files.
    // #define, #undef : Defining and undifing macros
    // #ifdef, #ifndef, #if, #else, #elif, #endif: Conditional compilation
    // #pragma: Implementation and compiler specific
    // #error, #warning: Output an error or warning message
    // Do not put semicolon character at the end of a # directive

    printf("73. The #include Directive\n");
    // For including header files: 
    // A header file has collection of functions and macros for a library.
    // Some common c libraries are:
    // stdio, stdlib, string, errno, math, time.
    // A user defined file can also be included buth with quotation
    // #include "myutil.h"
    // Some headers use .hpp extension for header files.

    printf("74. #define Directive\n");
    // Used to create object-like macros for constants.
    // Can also be used to create Function like macros.
    float radius = 2;
    printf("Area is %5.2f\n", AREA(radius));
    printf("Area with radius + 1: %5.2f\n", AREA(radius + 1));
    // Before compilation, the preprocessor expands every macro identifier.
    // So PI is replaced by 3.14, AREA(arg) is replaced with PI*arg*arg.
    // So for radius + 1, this becomes: 3.14*2+1*2+1 which will give very different results.
    // Be cautious.
    // Better to enclose each parameter in parenthesis.

    printf("75. Formatting Preprocessor Directives\n");
    // If a # directive is lenghty, we can use \ continuation character
    // There can be any amount of white space before # and between the # and the directive

    printf("76. Predefined Macro Definitions\n");
    // __DATE__ : current date as string in format Mmddyyy
    // __TIME__ : current time as string in hh:mm::ss
    // __FILE__ : current filename as string
    // __LINE__ : current line number as an int value
    // __STDC__ 1
    char curr_time[10];
    char curr_date[12];
    int std_c;
    strcpy(curr_time, __TIME__);
    strcpy(curr_date, __DATE__);
    printf("%s %s\n", curr_time, curr_date);
    printf("This is line %d\n", __LINE__);
    std_c = __STDC__;
    printf("STDC is %d\n", std_c);

    printf("77. Conditional Directives.\n");
    // #ifdef, #ifndef, #undef : operate on macros created with #define.
    // Compilation problem if same macros is defined twice. 
    // To check that, we can use #ifdef
    #ifdef RATE
        #undef RATE
        printf("Redefining Rate\n");
        #define RATE 0.068
    #else
        #define RATE 0.068
    #endif
    printf("%f %d\n", RATE, TERM);
    // Since RATE is defined at the top, only #ifdef clause will be compiled.
    // The optional #else branch compiles when #ifdef RATE is false during preprocessing
    // An #endif is required to cose the block of code.
    // An #elif directive is like an else if and can be used to provide additional alternatives after #else
    // Conditional compilation of segments of code is controlled by a set of directives:
    // #if, #else, #elif, and #endif.
    #if LEVEL > 6
        // Blah blah : do something here
    #elif LEVEL > 5
        // do something
    #elif LEVEL > 4
        // do something
    #else
        // last option here
    #endif
    // There are instances when this type of code can be used.
    // The defined() preprocessor operator can be used with #if, as in:
    #if !defined(LEVEL)
        // blah blah : do something
    #endif
    // The #if and if statements are not interchangeable.
    // The #if is evaluated using data available to the preprocessor, which
    // then sends only the true branch for compilation.
    // An if statement uses data provided at runtime with the possibility of branching to any else clause.

    printf("78. Preprocessor Operators\n");
    // The # Operator
    // The # macro operator is called the stringification or stringizing operator 
    // and tells the preprocessor to convert a parameter to a string constant.
    // White space is ignored.
    #define TO_STR(x) #x
    printf("%s\n", TO_STR(123\\12));

    printf("79. The ## Operator\n");
    // The ## Operator is also called the token pasting operator because it appends, or "pasters" tokens together
    #define VAR(name, num) name##num
    int x1 = 125;
    int x2 = 230;
    int x3 = 500;
    printf("%d \n", VAR(x, 3));

    return 0;
}