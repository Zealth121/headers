#include <stdio.h>

#include "stack.h"

void stack_int();
void stack_float();
void stack_double();
void stack_char();
void stack_string();

int main(void){

    printf("Double stack: \n");
    stack_double();

    printf("Char stack: \n");
    stack_char();

    printf("String stack: \n");
    stack_string();

    return 0;
}

void stack_int(){

}

void stack_float(){

}

void stack_double(){
    Stack stack;
    Stack* pStack = stack_init(&stack, DOUBLE);

    double value = 13.01749;
    stack_push(pStack, &value);

    value = 297.0913;
    stack_push(pStack, &value);

    stack_peak(pStack);

    stack_pop(pStack);

    stack_peak(pStack);

    free(pStack->pStack);
}

void stack_char(){
    Stack stack;
    Stack* pStack = stack_init(&stack, CHAR);

    char ch = 'A';
    stack_push(pStack, &ch);

    ch = 'B';
    stack_push(pStack, &ch);

    stack_peak(pStack);

    stack_pop(pStack);

    stack_peak(pStack);

    free(pStack->pStack);
}

void stack_string(){
    Stack stack;
    Stack* pStack = stack_init(&stack, STRING);

    char* str = "ABBA";
    stack_push(pStack, str);

    str = "BAAB";
    stack_push(pStack, str);

    stack_peak(pStack);

    stack_pop(pStack);

    stack_peak(pStack);

    free(pStack->pStack);
}