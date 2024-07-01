//Created by Aya Bedair
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"

void init_hash_table(){
    unsigned int i;
    for(i = 0 ; i < TABLE_SIZE ; ++i){
        hash_table[i] = NULL;
    }
}

/*This function sets unique index for every name based on the sum of ascii code of each char*/
unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    int i;
    unsigned int hash_value = 0;
    for(i = 0 ; i < length; ++i){
        hash_value = (hash_value + name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void print_table(){
    unsigned int i;
    for(i = 0 ; i < TABLE_SIZE; ++i){
        if(hash_table[i] == NULL)
            printf("\t%d\t\n", i);
        else{
            printf("\t%d\t", i);
            person *temp = hash_table[i];
            while(temp){
                printf("%s->", temp->name);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

bool hash_table_insert(person *p){
    if(p == NULL) return false;

    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

/*returns a ptr to the person if it is in the table
if not it returns NULL*/
person *hash_table_find(char* name){
    int index = hash(name);
    person *temp = hash_table[index];

    while (temp && strncmp(temp->name, name, MAX_NAME) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\tNot Found\n");
    }

    return temp;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    person *temp = hash_table[index];
    person *prev = NULL;
    while(temp && strncmp(temp->name, name, MAX_NAME) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return NULL;
    if(prev == NULL){
        hash_table[index] = temp->next;
    }else{
        prev->next = temp->next;
    }
    return temp;
}
