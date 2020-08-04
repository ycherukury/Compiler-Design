#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table_header.h"

#define INTMAX 5
 
static int line_number = 1;
static int scope = 1;
static store_table **symbol_table;

int check_scope(char *other_symbol){
	if (strcmp(other_symbol,"{")==0)
		scope++;
	if (strcmp(other_symbol,"}")==0)
		scope--;
	//printf("in check_scope %s\n scope value=%d", other_symbol,scope);
	return scope;
}


void init()
{
    symbol_table = malloc(_maxsize * sizeof(store_table*));
    for(int i = 0; i < _maxsize; i++)
    {
        symbol_table[i] = NULL;
    }
    return;
}

store_table *lookup(char *identifier_name, int* insert_at_index, store_table* prev_ptr)
{
    //printf("in lookup -> %s",identifier_name);
    store_table *tokenptr = symbol_table[0];
    store_table *prevdat_ptr = NULL;
    *insert_at_index = 0;
    while ((tokenptr != NULL) && (strcmp(identifier_name,tokenptr->iden_name) != 0))
    {
        prevdat_ptr = tokenptr;
        *insert_at_index = *insert_at_index + 1;
        tokenptr = symbol_table[*insert_at_index];
    }
    return tokenptr;
}
 
void insert_to_symbol_table(char *identifier_name, char* value)
{
    //printf("in insert to symbol table -> %s",identifier_name);
    store_table *tokenptr = symbol_table[0];
    store_table *prev_ptr = NULL;

    int* insert_at_index = (int *)malloc(sizeof(int));

    tokenptr = lookup(identifier_name, insert_at_index, prev_ptr);

    if(tokenptr == NULL)
    {
        tokenptr = (store_table*)malloc(sizeof(store_table));
        strncpy(tokenptr->iden_name, identifier_name, strlen(identifier_name));
        tokenptr->lines = (tok_occ*)malloc(sizeof(tok_occ));
        tokenptr->lines->line_number = line_number;
	    tokenptr->lines->scope_of_id = scope;
        tokenptr->lines->next = NULL;
        tokenptr->values = (tokeninfo*)malloc(sizeof(tokeninfo)*INTMAX);
        tokenptr->next = NULL;
        symbol_table[*insert_at_index] = tokenptr;
    }
    else
    {
        tok_occ *line_no_ptr = tokenptr->lines;

        while (line_no_ptr->next != NULL)
        {
            line_no_ptr = line_no_ptr->next;
        }

        line_no_ptr->next = (tok_occ*)malloc(sizeof(tok_occ));
        line_no_ptr->next->line_number = line_number;
	    line_no_ptr->next->scope_of_id = scope;
        line_no_ptr->next->next = NULL;
    }
    return;
}

void incrline()
{
    line_number++;
}

void dump_to_file(FILE *of)
{  
  fprintf(of,"---------------\t\t\t------------\t\t\t------\t\t\t------\n");
  fprintf(of,"Identifier Name\t\t\tLine Numbers\t\t\t Scope\t\t\t Value\n");
  fprintf(of,"---------------\t\t\t------------\t\t\t------\t\t\t------\n");
  for (int i=0; i < _maxsize; ++i){
    if (symbol_table[i] != NULL)
    {
        store_table *tokenptr = symbol_table[i];
        while (tokenptr != NULL)
        {
            tok_occ *line_no_ptr = tokenptr->lines;
            fprintf(of,"%-20s ",tokenptr->iden_name);
            while (line_no_ptr != NULL)
            {
                fprintf(of,"%4d ",line_no_ptr->line_number);
		        //fprintf(of,"## %4d  ##",line_no_ptr->scope_of_id);
                line_no_ptr = line_no_ptr->next;
            }
	        fprintf(of,"\t\t\t\t");
	        tok_occ *scope_ptr= tokenptr->lines;
            while (scope_ptr != NULL)
            {
                fprintf(of,"%4d ",scope_ptr->scope_of_id);
                scope_ptr = scope_ptr->next;
            }
            fprintf(of,"\n");
            tokenptr = tokenptr->next;
        }
    }
  }
}
