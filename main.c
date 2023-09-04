#include <stdio.h>

#include "stack.h"

void stack_char();
void stack_string();

int main(void){

    printf("Char stack: \n");
    stack_char();

    printf("String stack: \n");
    stack_string();

    return 0;
}

void stack_char(){
    Stack stack;
    Stack* pStack1 = stack_init(&stack, CHAR);

    char ch = 'A';
    stack_push(pStack1, &ch);

    ch = 'B';
    stack_push(pStack1, &ch);

    stack_peak(pStack1);

    stack_pop(pStack1);

    stack_peak(pStack1);

    free(pStack1->pStack);
}

void stack_string(){
    Stack stack;
    Stack* pStack1 = stack_init(&stack, STRING);

    char* str = "ABBA";
    stack_push(pStack1, str);

    str = "BAAB";
    stack_push(pStack1, str);

    stack_peak(pStack1);

    stack_pop(pStack1);

    stack_peak(pStack1);

    free(pStack1->pStack);
}