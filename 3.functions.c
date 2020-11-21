#include<stdio.h>

int global1 = 0;
int square(int num);
int sum_up(int x, int y);
void sayHello();
int factorial(int x);

int main(){
    printf("14. Functions")
    // Declare the function above the main() function
    // return_type function_name(parameters);
    // If no return_type, use void
    // void display_message()
    // Function prototype: parameter type and name is declared.
    int x, result;
    x = 5;
    result = square(x);
    printf("%d is the squared value of %d\n", x, result);
    // Function definition after main function
    // Multiple parameters can be separated by commas
    // return is used to send value.

    printf("15. Function Parameters");
    // Values to these parameters are arguments through the function call
    int y;
    x = 3;
    y = 12;
    result = sum_up(x, y);
    printf("%d + %d = %d", x, y, result);
    // Arguments are actual parameters

    printf("16. Variable Scope");
    // Visibility of variable within the program
    // Var inside function are local
    // Var declared outside function are global to entire program.
    // #define is visible to entire program
    int local1, local2;
    local1 = 15;
    local2 = 5;
    global1 = local1 + local2;
    printf("%d\n", global1);

    printf("17. Static Variables");
    // Static variables have local scope but are not destroyed when function is exited.
    // It retain its value
    // They can be reaccessed every time the function is re-entered.
    // Is always initialized
    int i;
    for(i=0; i<5; i++){
        sayHello();
    }

    prinf("17. Recursive Functions");
    // Factorial: recursion
    // Recursive Function: one that calls itself
    x = 5;
    printf("The factorial of %d is %d\n", x, factorial(x));
    // Recursion works by stacking
    // Calls are completed from newest to oldest
    // Every recursion needs a base condition

    return 0;
}

int square(int num){
    int y;
    y = num * num;
    return y;
}

int sum_up(int x, int y){
    x += y;
    return x;
}

void sayHello(){
    static int num_calls = 1;
    printf("Hello number %d\n", num_calls);
    num_calls++;
}

int factorial(int x){
    if(num == 1){
        return(1);
    }
    else{
        return num*factorial(num-1);
    }
}