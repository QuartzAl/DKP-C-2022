#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define PI 3.1415926535897932384626433832795

void circle_area(){
    double radius;

    printf("Enter your circle radius: ");
    scanf(" %lf", &radius);
    printf("The circle's area is %lf", PI*(radius*radius));
}

void printToCoordinate(){
    /*
     * Moves the cursor to a specified x and y position
     */
    COORD c;
//    console window by default is 80*25
    c.X = 20;
    c.Y = 15;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void input_output() {
/**
 *  there are 3 ways:
 *  [getchar() / putchar()],
 *  [scanf() / printf()],
 *  [gets() / puts()]
**/

    char *item, *line;
    int itemNo;
    float cost;

/*
 *   # SCANF() & PRINTF()
 *   scanf and printf are the functions for input output which have the most features such as formatting and conversion
 *   hence, scanf and printf are the most commonly used
 *
 *   ## Scanf()
 *   it will read user input from the console until it meets a whitespace unless otherwise specified by the format
 *   Following is the declaration for scanf() function.
 *   `int scanf(const char *format, ...)`
 *   ### Parameters
 *   **format** − This is the C string that contains one or more of the following items:
 *   - Whitespace character,
 *   - Non-whitespace character and
 *   - Format specifiers
 *
 *   A format specifier will be like [=%[*][width][modifiers]type=]
 *
 *   ## Printf()
 *   The C library function int printf(const char *format, ...) sends formatted output to stdout.
 *   Following is the declaration for printf() function
 *   `int printf(const char *format, ...)`
 *   ### Parameters
 *   format − This is the string that contains the text to be written to stdout.
 *   It can optionally contain embedded format tags that are replaced by the values
 *   specified in subsequent additional arguments and formatted as requested.
 *
 *   Format tags prototype is `%[flags][width][.precision][length]specifier` which is explained by the table 1.1
 *
 */
    printf("Input '{itemName} {itemNo} {cost in dollars}: ");
    scanf(" %ms %d %f", &item, &itemNo, &cost);
    printf("%d - %s \n $%f", itemNo, item, cost);

    printf("I only accept inputs of 'ABCDEF': ");

/*
*     this acts like RegEx (Regular Expressions)
*     e.g.
*     %[ ABCDEF] only accepts 'ABCDEF'
*     %[ ^\n] accepts anything except '\n' */
    scanf(" %[ ABCDEF]", &line);
    printf("%s \n", line);
/*
*     difference between %[^\n] and %s
*     %[^\n] reads until a \n or EOF
*     %s reads until a whitespace or EOF
*     (End Of File) -> EOF indicates the end of input
*/

/*
 *     GETS() AND PUTS()
 *     gets() is similar to scanf("%[^\n]") in nature
 *     it reads until a newline is given but gets() will on read character string data only
 *
 *     puts() will print out the string given except,
 *     unlike printf it only has one parameter which is the string, and it appends a \n at the end of the string
 */
    puts("type anything: ");
    gets(line);
    puts(line);

/*
 *    GETCHAR() & PUTCHAR()
 *    int getchar(void) gets a character (an unsigned char) from stdin.
 *    This is equivalent to getc with stdin as its argument.
 *
 *
 */
    free(item);
    free(line);
}

void name(){
    char *firstname, *lastname;
    printf("First name: ");
    scanf(" %ms", &firstname);
    printf("Last name: ");
    scanf(" %ms", &lastname);

    printf("hello, %s %s", firstname, lastname);

    free(firstname);
    free(lastname);
}

int main() {
    input_output();
    return 0;
}

