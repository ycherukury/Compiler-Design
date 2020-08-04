#include <stdio.h>
#define _maxsize 1000
#define _toklen 50
 
typedef struct tokeninfo{
    int value; 
    double floatvalue; 
    char *stringval;
}tokeninfo;

typedef struct tok_occ{
    int line_number;
    struct tok_occ *next;
}tok_occ;
 
typedef struct store_table{
    char iden_name[_toklen];
    tok_occ *lines;
    tokeninfo *values;
    struct store_table *next;
}store_table;

void init();
void insert_to_symbol_table(char *name, void* value);
void dump_to_file(FILE *op);
store_table *lookup(char *name, int* insert_at_index, store_table* prev_ptr);
void incrline();
