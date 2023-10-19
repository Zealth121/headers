#ifndef HASH
#define HASH
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* TO USE THIS HEADER FILE
    Create hash table using ------ person* (table_name)[TABLE_SIZE]
*/

// once again variables that could be changed
// MAX_NAME is for the max characters of the key (a persons name) for the table
// table size is a predefined size for the hash_table
#define MAX_NAME 256
#define TABLE_SIZE 100

// This could be changed to any sort of object. I just chose people so that it is easy to test and read
// it holds a persons name and age... The person* next variable is for when a slot in the table is already occupied.
// It acts as a linked list. This deals with conflicts
typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person* next;
}person;

// returns the index of the name in the hash table
unsigned int hash(char* name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

// initializes a table using size TABLE_SIZE
bool init_hash_table(person** hash_table){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    return true;
}

// prints out the hash table
void print_table(person** hash_table){
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

// inserts person* into hash table. Pushes the value of current head of linked list back and it gets put at the front.
// Returns true on success and false on failure
bool hash_table_insert(person** hash_table, person* p){
    if(p == NULL){
        return false;
    }
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

// returns the person* to whatever name is searched in the table
// RETURNS NULL if person not found
person* hash_table_lookup(person** hash_table, char* name){
    // gets index of name and creates person* temp equal to the first spot of the index
    int index = hash(name);
    person* tmp = hash_table[index];
    // while not at the end of the linked list and person not found... get next person in linked list
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        tmp = tmp->next;
    }
    return tmp;
}

// RETURNS NULL IF PERSON NOT FOUND OTHERWISE RETURNS PERSON DELETED
person* hash_table_delete(person** hash_table, char* name){
    // get index of name and create tmp and prev person* variable
    int index = hash(name);
    person* tmp = hash_table[index];
    person* prev = NULL;
    // while the person is not found and the end of the linked list has not been reached... get next person
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL){
        return NULL;
    }
    // the linked list change is dependent on if the person found was in the front or not
    if(prev == NULL){
        hash_table[index] = tmp->next;
    }else{
        prev->next = tmp->next;
    }
    return tmp;
}
#endif