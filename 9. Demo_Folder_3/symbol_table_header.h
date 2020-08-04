#include <stdio.h>
#define _maxsize 1000
#define _toklen 50
 
char* __identifier_name;

typedef struct tokeninfo{
    int value; 
    double floatvalue; 
    char *stringval;
    char *vectorval;
}tokeninfo;

typedef struct tok_occ{
    int line_number;
    int scope_of_id;
    char type[_toklen];
    tokeninfo *values;
    struct tok_occ *next;
}tok_occ;
 
typedef struct store_table{
    char iden_name[_toklen];
    tok_occ *lines;
    tokeninfo *values;
    struct store_table *next;
}store_table;

void init();
void insert_to_symbol_table(char *name, void* value, char* type);
void insert_to_symbol_table_identifier(const char* identifier_name);
void insert_to_symbol_table_value(void* value, char* type);
void dump_to_file(FILE *op);
void dump_optimized(FILE *op);
store_table *lookup(char *name, int* insert_at_index, store_table* prev_ptr);
void incrline();
int check_scope(char *name);


typedef struct quadruple {
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    int isLoop;
    int index;
    struct quadruple *next;
    

}quadruple; 

int isLoop;


int deadCodeElimination();
int isBinaryOperator(char *op);
int constantFolding();
int isNumber(char *str);
int performOperation(char *op, int num1, int num2);
void printICG();
int constantPropagation(int res, int index);
int propagate();
void optimize();


void insert_to_quadruple(quadruple **head_ref , char *op, char *arg1, char *arg2, char *result, int isLoop);
void print_quadruple();
void push(char *s);
void codegen(int isLoop);
void codegen_assign(int isLoop);
void concatenate(char p[], char q[]);
void if_lab1(int isLoop);
void if_lab2(int isLoop);
void if_lab3(int isLoop);
void while_lab1(int isLoop);
void while_lab2(int isLoop);
void while_lab3(int isLoop);
void for_lab1(int isLoop);
void for_lab2(int isLoop);
void for_lab3(int isLoop);
void repeat_lab1(int isLoop);
void repeat_lab2(int isLoop);
void repeat_lab3(int isLoop);
void check_break(int isLoop);
void push_vector(char *s);
void vecor_assign(int isLoop);