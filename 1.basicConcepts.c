// Understanding how computer memory works is an important aspect of the C programming language.
// Used in Oracle database as well
#include<stdio.h>

#define PI1 3.14

int main(){
    printf("1. Introduction\n");
    printf("Hello world!\n");
    // printf() function is included in stdio.h header file.
    // main() is entry
    // \n is the newline character
    // Escape sequences start with '\'

    printf("2. Data Types\n");
    // Data Types:
    // int:
    // float
    // double : double precision floating point value
    // char: single character
    // C has built-in sizeof operator that gives the memory requirements for a particular data type.
    printf("int: %ld \n", sizeof(int));
    printf("float: %ld\n", sizeof(float));
    printf("double: %ld\n", sizeof(double));
    printf("char: %ld\n", sizeof(char));
    printf("long: %ld\n", sizeof(long));
    // Corresponding size in bytes of each datatype.
    // format specifier: %ld (long decimal)
    // C does not have a boolean
    // Format specifiers are also referred to as conversion specifiers

    // Variables: name for an area in memory
    // name of variable: identifier : must begin with letter or an underscore
    // Must be declared as data type first.
    int myVar;
    myVar = 42;
    // Initialize var
    int var=42;
    int a,b;
    float salary=56.55;
    char letter = 'Z';
    a = 8;
    b = 34;
    int c = a + b;
    printf("%d\n", c);
    printf("%f\n", salary);
    printf("%c\n", letter);
    // %d : decimal
    // %f : float
    // %c : char
    // C is case sensitive language.

    // Constants: store value that cannot be changed
    // Common practice is to use UPPERCASE variables
    // use 'const' keyword in variable declaration
    const double PI = 3.14;
    printf("%f\n", PI);
    // Constants must be initialized with a value when defining
    // Another way of defining a constant is with #define preprocessor directive.
    // #define PI 3.14
    // Before compilation, the preprocessor replaces every macro identifier in the code with
    // it's corresponding value from the directive.
    // So every occurance of PI is replaced with 3.14
    // Difference between const and #define is that const uses memory while #define does not.
    // Not to put semicolon at the end of #define statements. 
    // This is a common mistake.

    printf("3. Input & Output\n");
    // getchar(): Returns the value of the next single character input
    char a1 = getchar();
    printf("You entered: %c\n", a1);
    // gets() : Used to read input as an ordered sequence of characters, also called as string
    // A string is stored in a char array.
    char a2[100];
    gets(a2);
    printf("You entered: %s\n", a2);
    // %s : string
    // scanf(): scans input that matches format specifiers
    int a3;
    scanf("%d", &a3);
    printf("You entered: %d\n", a3);
    // & sign: address operator.
    // Gives address of the variable.
    // scanf places an input value at a variable address.
    int a4, a5;
    printf("Enter two numbers: \n");
    scanf("%d %d", &a4, &a5);
    printf("\nSum: %d\n", a4 + a5);
    // scanf() stops reading as soon as it encounters a space, so text such as "Hello world" is
    // two separate inputs for scanf().
    // putchar(): Outputs a single character.
    char a6 = getchar();
    printf("You entered: ");
    putchar(a6);
    printf("\n");
    // puts(): Used to display output as a string.
    char a7[100];
    gets(a7);
    printf("You entered: ");
    puts(a7);
    printf("\n");
    
    // Formatted input
    // scanf() function is used to assign input to variables.
    int x;
    float num;
    char text[20];
    scanf("%d %f %s", &x, &num, text);
    // 10 22.5 abcd: x=10, num=22.5, text=abcd
    // For text[] array, text acts as the pointer.
    // BLANKS, TABS, AND NEWLINES ARE IGNORED.
    // d: decimal
    // c: character
    // f: float
    // s: string
    // x: hexadecimal
    // %[*][max_field]conversion character
    // * will skip the input field: so here %*f will be ignored.
    int x1, y1;
    char text2[20];
    scanf("%2d %d %*f %5s", &x1, &y1, text2);
    /*input: 1234 5.7 elephant*/
    printf("%d %d %s\n", x1, y1, text2);
    /*Output: 12 34 eleph*/

    // Formatting output
    printf("The tree has %d apples. \n", 22);
    printf("\"Hello Wrold!\"");
    // Escape sequences begin with a backslash \:
    // \n : new line
    // \t : horizontal tab
    // \\ : backslash
    // \b : backspace
    // \' : single quote
    // \" : double quote
    // Format specifier can include several options along with a conversion character.
    // %[-][width].[precision]conversion character
    // Optional - specifies left alignment of the data in the string
    // optional width gives the minimum number of characters for the data
    // the period . separates the width from the precision
    // The optional precision fives the number of decimal places for numeric data.
    // If s is used as the conversion character, then precision determines the number of characters to print.
    // %e : scientific notation
    printf("Color: %s, Number: %d, float: %5.2f \n", "red", 42, 3.14159);
    /*Color: red, Number: 42, float: 3.14*/
    printf("Pi = %3.2f\n", 3.14159); // Pi = 3.14
    printf("Pi = %8.5f\n", 3.14159); // Pi = 3.14159
    printf("Pi = %-8.5f\n", 3.14159); // Pi = 3.14159
    printf("There are %d %s in the tree.\n", 22, "apples");

    printf("4. Comments\n");
    // Multiline comments:
    // Starts with /* and ends with */
    // Clarity program's intent to the reader.
    // Single line comments:
    // double slash comment //

    printf("5. Operators\n");
    // + : Addition
    // - : substraction
    // * : multiplication
    // / : division
    // % : modulus
    int length = 10;
    int width = 5;
    int area;
    area = length * width;
    printf("%d \n", area); // 50
    // / performs differently depending on the data types of the operands.
    // When both operands are int data types: integer division: truncated division: removes any remainder to result in an int.
    // When one or both are real numbers (float or double), the result is a real number.
    // % operator returns remainter of integer division.
    // Modulo operator cannot be performed on floats or doubles.
    int i1 = 10;
    int i2 = 3;
    int quotient, remainder;
    float f1 = 4.2;
    float f2 = 2.5;
    float result;
    quotient = i1 / i2; //3
    remainder = i1 % i2; // 1
    result = f1 / f2; // 1.68
    
    // Operator Precedence
    // + and - are in equal precedence, as are *,/, and %.
    // *, /, and % are performed first in order from left to right, then + and -, also from left to right.
    // Use parentheses
    int a8 = 6;
    int b8 = 4;
    int c8 = 2;
    int result8;
    result8 = a8 - b8 + c8; //4
    printf("%d\n", result8);
    result8 = a8 + b8 / c8; //8
    printf("%d\n", result8);
    result = (a8 + b8) / c8; // 5
    printf("%d\n", result8);

    // Type Conversion
    // In operation involving floats and ints, the compiler will convert the int values to float values.
    float price = 6.50;
    int increase = 2;
    float newPrice;
    newPrice = price + increase;
    printf("New price is %4.2f", newPrice);
    // When we want to force the result of an expression to a different type, we can perform
    // explicit type conversion
    float average;
    int total1 = 23;
    int count1 = 4;
    average = (float) total1 / count1; 
    // Without type casting, average will be assigned 5
    // Explicit type conversion is always a good practice


    // Assignment Operators
    // Evaluates the expression on the right side of the equal sign first
    x=3;
    x = x +1;
    x += 1;
    x -= 1;
    x *=3;
    x /=2;
    x %=2;
    x +=3*2; // this will be evaulated as x = x + 3*2. 3*2 will be executed first.


    // Increment and decrement
    int z1=0;
    z1++;
    int y1=0;
    y1--;

    // y-- : postfix
    // --y : prefix
    z1 = 3;
    x = z1--; // assigns value of z1 first and then decrement z to 2
    int y = 3;
    x = ++y; // increment y to 4, then assign 4 to x

    return 0;
    // return 0: program executed successfully. Any other number means program has failed.
}

