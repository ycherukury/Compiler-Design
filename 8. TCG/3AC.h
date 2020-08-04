#include <stdio.h>


typedef struct quadruple {
    char op;
    char arg1;
    char arg2;
    char result;

}quadruple; 

void insert_to_quadruple();
void push(char *s);
void codegen();
void codegen_assign();