//
// Created by Bedir on 01/07/2024.
//

#ifndef HASHTABLE_C_HASHTABLE_H
#define HASHTABLE_C_HASHTABLE_H

#define MAX_NAME  256
#define TABLE_SIZE  10

typedef struct person{
    char name[MAX_NAME];
    int age;
    //..add more info if required
    struct person *next;
}person;

person *hash_table[TABLE_SIZE];

void init_hash_table();
unsigned int hash(char *name);
void print_table();
bool hash_table_insert(person *p);
person *hash_table_find(char* name);
person *hash_table_delete(char *name);

#endif //HASHTABLE_C_HASHTABLE_H
