Hash Tables Project
Description
This project is a custom implementation of a hash table data structure in C, developed as part of the Holberton School curriculum. The goal is to implement a fully functional hash table with collision handling using chaining.

Project Structure
text
hash_tables/
├── hash_tables.h
├── 0-hash_table_create.c
├── 1-djb2.c
├── 2-key_index.c
├── 3-hash_table_set.c
├── 4-hash_table_get.c
├── 5-hash_table_print.c
├── 6-hash_table_delete.c
└── README.md
File	Description
hash_tables.h	Header file containing structures and function prototypes
0-hash_table_create.c	Creates a new hash table with specified size
1-djb2.c	Implements the djb2 hash algorithm
2-key_index.c	Computes the index for a given key
3-hash_table_set.c	Adds or updates a key-value pair in the hash table
4-hash_table_get.c	Retrieves the value associated with a key
5-hash_table_print.c	Prints the entire hash table
6-hash_table_delete.c	Deletes the hash table and frees all memory
General Requirements
Allowed editors: vi, vim, emacs

Code style: Betty style (checked with betty-style.pl and betty-doc.pl)

Global variables: Not allowed

Functions per file: Maximum 5 functions

Header file: hash_tables.h with include guards

File endings: All files must end with a new line

Authorized Functions and Macros
malloc (man 3 malloc)

free (man 3 free)

strdup (man 3 strdup)

printf (man 3 printf)

fprintf (man 3 fprintf)

putchar (man 3 putchar)

strlen (man 3 strlen)

Tasks
Task 0: >>> ht = {}
Function: hash_table_t *hash_table_create(unsigned long int size);
Creates a new hash table with the specified size.

Task 1: djb2
Function: unsigned long int hash_djb2(const unsigned char *str);
Implements the djb2 hash algorithm.

Task 2: key -> index
Function: unsigned long int key_index(const unsigned char *key, unsigned long int size);
Returns the index at which the key/value pair should be stored in the array.

Task 3: >>> ht['betty'] = 'holberton'
Function: int hash_table_set(hash_table_t *ht, const char *key, const char *value);
Adds an element to the hash table.

Task 4: >>> ht['betty']
Function: char *hash_table_get(const hash_table_t *ht, const char *key);
Retrieves a value associated with a key.

Task 5: >>> print(ht)
Function: void hash_table_print(const hash_table_t *ht);
Prints the hash table in the format: {'key': 'value', ...}.

Task 6: >>> del ht
Function: void hash_table_delete(hash_table_t *ht);
Deletes the hash table and frees all allocated memory.

Edge Cases Handled
NULL pointers: Gracefully handle NULL hash tables and keys

Empty tables: Properly handle empty hash tables

Duplicate keys: Update value when key already exists

Collisions: Handle multiple keys hashing to the same index using chaining

Memory allocation failures: Check and handle malloc failures

Future Enhancements
Resize functionality: Automatic resizing when load factor is high

Additional hash functions: Implement alternative hash algorithms

Iterators: Add functions to iterate through all key-value pairs

Thread safety: Add mutex locks for concurrent access

Serialization: Save/load hash table to/from file
