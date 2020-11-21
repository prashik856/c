#include<stdio.h>

int main(){
    printf("6. Conditionals\n");
    // Conditionals
    // if statement : conditional control structure : decision structure
    // if (expression)
    //      statements
    int score = 89;
    if(score > 75){
        printf("You passed.\n");
    }

    //Rational Operators
    // < : less than
    // <= : less than or equal to
    // > : greater than
    // >= : greater than or equal to
    // == : equal to
    // != : not equal to
    int num = 41;
    num += 1;
    if(num == 42){
        printf("You won!\n");
    }
    // An expression that evaluates to non-zero values is considered true
    int inStock = 20;
    if(inStock){
        printf("Order received.\n");
    }

    // if-else statement
    score = 89;
    if(score >= 90){
        printf("Top 10%%.\n");
    }
    else{
        printf("Less than 90.\n");
    }

    // Conditional Expressions
    // Another way of if-else statement
    // ?: operator
    int y;
    int x = 3;
    y = (x >= 5) ? 5 : x;
    // Equivalent to this:
    /*
    if(x>=5)
        y = 5;
    else
        y = x
    */


    printf("7. Nested if Statements\n");
    // Nested ifs
    int profit = 2000;
    int clients = 20;
    int bonus;
    if(profit > 1000){
        if (clients > 15){
            bonus = 100;
        }
        else{
            bonus = 25;
        }
    }
    // Use {} to change the association of else statement with if statement
    if (profit > 1000){
        if(clients > 15){
            bonus = 100;
        }
    }
    else{
        bonus = 15;
    }
    // else if clause
    score = 89;
    if(score >= 90){
        printf("%s", "Top 10%%\n");
    }
    else if (score >= 80){
        printf("%s", "Top 20%%\n");
    }
    else if (score > 75){
        printf("%s", "You passed.\n");
    }
    else{
        printf("%s", "You did not pass.\n");
    }
    // Indents will be helpful in reading the code.


    printf("8. The switch statement\n");
    // The switch statement branches the program control by matching the result of an 
    // expression with a constant case value
    /*
    switch (expression){
        case val1:
            statements
        break;
        case val2;
            statements
        break;
        default:
            statements
    }
    */
   num =3;
   switch (num){
        case 1:
            printf("One\n");
            break;
        case 2:
            printf("Two\n");
            break;
        case 3:
            printf("Three\n");
        default:
            printf("Not 1, 2, or 3.\n");
    }

    // default case is executed when no other matches are made.
    // break statement is needed in each case to branch to the end of the switch statement
    // Without break, other cases will be executed as well, if one case is successful.
    // E.g.
    switch(num) {
        case 1:
        case 2:
        case 3:
            printf("One, Two, or Three.\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("Four, Five, or Siz.\n");
            break;
        default:
            printf("Greater than Six.\n");
    }


    printf("9. Logical Operators.\n");
    // && : and : true if all are true
    // || : or : true if any one is true
    // ! : not : reverse
    // &&
    int n = 10;
    if(n>0 && n<=100){
        printf("Range (1-100");
    }
    // Compound Boolean expression is evaluated from left to right
    // ||
    if (n == 'x' || n == 'X'){
        printf("Roman numeral value of 10.\n");
    }
    // || and &&
    if (n == 999 || (n>0 && n<=100)){
        printf("Input valid.\n");
    }
    // !
    if(!(n=='X' || n=='x')){
        prinf("Roman numeral is not 10.\n");
    }
    // In C, any non zero value is considered true.
    // 0 is false.

    prinf("10. While loop\n");
    /*
     * Loop structure.
     * while(expression){
     *  statements
     * }
     * */
    int count = 1;
    while(count < 8){
        printf("Count = %d\n", count);
        count++;
    }
    // Infinite while loop may cause run time error

    printf("11.The do-while loop\n");
    /*
    do{
        statements
    } while (expression);
    */
    do{
        printf("Count = %d\n", count);
        count++;
    } while (count < 8);
    // Semicolon after while statement
    // do-while loop executes at least once.

    printf("12. break and continue\n");
    // break : used for exiting a loop immediately
    num = 5;
    while(num>0){
        if(num == 3){
            break;
        }
        prinf("%d\n", num);
        num--;
    }
    // continue: remain in loop but skip ahead to next iteration
    num = 5;
    while(num > 0){
        num--;
        if(num == 3){
            continue;
        }
        printf("%d\n", num);
    }

    printf("13. The for loop.\n");
    /**
     * for(initvalue; condition; increment){
     *      statements;
     * }
    */
    // initvalue: initial value counter
    // condition: boolean expression
    // increment: counter set by a value
    int max = 10;
    for(int i=0; i<max; i++){
        printf("%d\n", i);
    }
    // for loop can have multiple expressions
    /**
     * for(x = 0, y=num; x<y; x++, y--){
     *      statements;
     * }
    */
    // We can also skip initvalue, condition and/or increment
    int i=0;
    max = 10;
    for(; i<max; i++){
        printf("%d\n", i);
    }
    // Loops can be nested
    i=0;
    int j;
    int table = 10;
    max = 12;
    for(i=1; i<=table; i++){
        for(j=0; j<=max; j++){
            printf("%d x %d = %d\n", i, j, i*j);
        }
        prinf("\n");
    }
    // break and continue can be used inside these loop for our specific use case.
    

    return 0;
}