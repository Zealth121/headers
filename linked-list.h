#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    void* data;
    int dataType;
    node* next;
}node;
node* head = NULL;
node* current = NULL;

void list_print(){
    node *p = head;
    printf("\n[");

    while(p != NULL){
        switch(p->dataType){
            case 1:
                printf(" %d ", p->data);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            default:
                printf("Invalid data type\n");
                break;
        }
        p = p->next;
    }
    printf("]\n");
}