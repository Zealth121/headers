#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person* next;
}person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char* name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

void print_table(){
    printf("Start\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        }else{
            printf("\t%i\t", i);
            person* tmp = hash_table[i];
            while(tmp != NULL){
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

bool hash_table_insert(person* p){
    if(p == NULL){
        return false;
    }
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person* hash_table_lookup(char* name){
    int index = hash(name);
    person* tmp = hash_table[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        tmp = tmp->next;
    }
    return tmp;
}

person* hash_table_delete(char* name){
    int index = hash(name);
    person* tmp = hash_table[index];
    person* prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL){
        return NULL;
    }
    if(prev == NULL){
        hash_table[index] = tmp->next;
    }else{
        prev->next = tmp->next;
    }
    return tmp;
}

int main(){

    init_hash_table();
    print_table();
    
    person jacob = {.name="Jacob", .age=37};
    person jack = {.name="Jack", .age=19};
    person bob = {.name="Bob", .age=44};
    person charlie = {.name="Charlie", .age=19};
    person ned = {.name="Ned", .age=23};
    person nicky = {.name="Nicky", .age=22};
    person joey = {.name="Joey", .age=99};
    hash_table_insert(&jacob);
    hash_table_insert(&jack);
    hash_table_insert(&bob);
    hash_table_insert(&charlie);
    hash_table_insert(&ned);
    hash_table_insert(&nicky);
    hash_table_insert(&joey);

    print_table();
    person* tmp = hash_table_lookup("Jack");
    if(tmp != NULL){
        printf("Name: %s, age: %i\n", tmp->name, tmp->age);
    }else{
        printf("Did not find person\n");
    }
    hash_table_delete("Jack");
    print_table();

    return 0;
}