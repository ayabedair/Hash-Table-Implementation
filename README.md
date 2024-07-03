# Hash Table Implementation

This project demonstrates a simple hash table implementation in C.

![1_pyMMcK8HAAbfg5iPUB_xcA](https://github.com/ayabedair/Hash-Table-Implementation/assets/111665968/b4357860-ed55-4aa0-b447-c071242f3067)

## Features

- **Initialization (`init_hash_table`)**:
  Initializes the hash table with `TABLE_SIZE` slots.

- **Hash Function (`hash`)**:
  Generates a unique index for each name based on the sum of ASCII values, ensuring efficient distribution of keys.

- **Insertion (`hash_table_insert`)**:
  Inserts a person into the hash table based on their name. Handles collisions using chaining (linked list).

- **Search (`hash_table_find`)**:
  Searches for a person by name in the hash table. Returns a pointer to the person if found, otherwise returns `NULL`.

- **Deletion (`hash_table_delete`)**:
  Deletes a person from the hash table based on their name. Adjusts pointers to maintain data structure integrity.

- **Printing (`print_table`)**:
  Prints the entire hash table, showing index slots and chained elements.
