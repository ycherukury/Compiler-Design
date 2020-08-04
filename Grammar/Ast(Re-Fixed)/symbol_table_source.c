#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table_header.h"
 
static int line_number = 1;
static store_table **symbol_table;

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
 
void insert_to_symbol_table(char *identifier_name, void* value)
{
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
        tokenptr->lines->next = NULL;
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
  fprintf(of,"---------------\t\t\t------------\n");
  fprintf(of,"Identifier Name\t\t\tLine Numbers\n");
  fprintf(of,"---------------\t\t\t------------\n");
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
                line_no_ptr = line_no_ptr->next;
            }
            fprintf(of,"\n");
            tokenptr = tokenptr->next;
        }
    }
  }
}