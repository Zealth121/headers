#include <stdio.h>
#include <stdlib.h>

#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define CHAR 4
#define STRING 5

typedef struct Stack{
    void* pStack;
    int size;
    int dataType;
}Stack;

Stack* stack_init(Stack* stack, int dataType){
    stack->size = 0;
    stack->dataType = dataType;
    switch(dataType){
        case INT:
            stack->pStack = (int*) calloc(stack->size, sizeof(int));
            break;
        case FLOAT:
            stack->pStack = (float*) calloc(stack->size, sizeof(float));
            break;
        case DOUBLE:
            stack->pStack = (double*) calloc(stack->size, sizeof(double));
            break;
        case CHAR:
            stack->pStack = (char*) calloc(stack->size, sizeof(char));
            break;
        case STRING:
            stack->pStack = (char*) calloc(stack->size, sizeof(char[15]));
            break;
        default:
            perror("Invalid data type\n");
            exit(EXIT_FAILURE);
    }
    printf("Stack initalized\n");
    return stack;
}

Stack* stack_pop(Stack* stack){
    if(stack->size <= 0){
        printf("Can not be negative\n");
        return stack;
    }
    stack->size--;
    switch(stack->dataType){
        case INT:
            stack->pStack = (int*) realloc(stack->pStack, sizeof(int)*stack->size);
            break;
        case FLOAT:
            stack->pStack = (float*) realloc(stack->pStack, sizeof(float)*stack->size);
            break;
        case DOUBLE:
            stack->pStack = (double*) realloc(stack->pStack, sizeof(double)*stack->size);
            break;
        case CHAR:
            stack->pStack = (char*) realloc(stack->pStack, sizeof(char)*stack->size);
            break;
        case STRING:
            stack->pStack = (char*) realloc(stack->pStack, sizeof(char[15])*stack->size);
            break;
        default:
            perror("Invalid data type\n");
            exit(EXIT_FAILURE);
    }
    return stack;
}

Stack* stack_push(Stack* stack, void* item){
    stack->size++;
    void* ptr;
    switch(stack->dataType){
        case INT:
            stack->pStack = (int*) realloc(stack->pStack, sizeof(int)*stack->size);
            ptr = (int*) stack->pStack+(stack->size-1);
            *(int*) ptr = *(int*) item;
            break;
        case FLOAT:
            stack->pStack = (float*) realloc(stack->pStack, sizeof(float)*stack->size);
            ptr = (float*) stack->pStack+(stack->size-1);
            *(float*) ptr = *(float*) item;
            break;
        case DOUBLE:
            stack->pStack = (double*) realloc(stack->pStack, sizeof(double)*stack->size);
            ptr = (double*) stack->pStack+(stack->size-1);
            *(double*) ptr = *(double*) item;
            break;
        case CHAR:
            stack->pStack = (char*) realloc(stack->pStack, sizeof(char)*stack->size);
            ptr = (char*) stack->pStack+(stack->size-1);
            *(char*) ptr = *(char*) item;
            break;
        case STRING:
            stack->pStack = (char*) realloc(stack->pStack, sizeof(char[15])*stack->size);
            ptr = (char*) stack->pStack+((stack->size-1)*15);
            while(*(char*)item != '\0'){
                *(char*) ptr = *(char*) item;
                ptr = (char*) ptr+1;
                item = (char*) item+1;
            }
            *(char*) ptr = '\0';
            break;
        default:
            perror("Invalid data type\n");
            exit(EXIT_FAILURE);
    }
    return stack;
}

void stack_peak(Stack* stack){
    printf("--------------------\n");
    void* location = stack->pStack;
    for(int i = 0; i < stack->size; i++){
        switch(stack->dataType){
            case INT:
                printf("Peak value: %d\n", *(int*)location);
                location = (int*)location+1;
                break;
            case FLOAT:
                printf("Peak value: %g\n", *(float*)location);
                location = (float*)location+1;
                break;
            case DOUBLE:
                printf("Peak value: %g\n", *(double*)location);
                location = (double*)location+1;
                break;
            case CHAR:
                printf("Peak value: %c\n", *(char*)location);
                location = (char*)location+1;
                break;
            case STRING:
                printf("Peak value: %s\n", (char*) location);
                location = (char*) location+15;
                break;
            default:
                perror("Invalid data type\n");
                exit(EXIT_FAILURE);
        }
    }
    printf("--------------------\n");
    printf("\n");
}