#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbol_table_header.h"

#define INTMAX 5

static int line_number = 1;
static int scope = 1;
static store_table **symbol_table;
static char* iden_name_global = NULL;
static char* vector_value_accumulate = NULL;
static char* temp_vector_pass = NULL;
static char type_int[4] = "int";
static char type_string[7] = "string";
static char type_vector[7] = "vector";
static char type_vector_end[11] = "vectorend";

char vt[100][100];
int vt_top=0;

char st[100][100];
int top=0;
static int i_=0;
char temp[5]="t";

int if_label[20];
int if_lnum=0;
int if_ltop=0;

int while_label[20];
int while_top=0;
static int w =-1;

static int f=-1;
int for_label[20];
int for_top=0;

static int r=-1;
int repeat_label[20];
int repeat_top=0;
int break_=0;
int break_r=0;

quadruple *Head_quad = NULL;
int Index = 0;


int check_scope(char *other_symbol){
	if (strcmp(other_symbol,"{")==0)
		scope++;
	if (strcmp(other_symbol,"}")==0)
		scope--;
	return scope;
}


void init()
{
    iden_name_global = (char*)malloc(sizeof(char)*100);
    vector_value_accumulate = (char*)malloc(sizeof(char)*1000);
    strcpy(vector_value_accumulate, "(");
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

void insert_to_symbol_table(char *identifier_name, void* value, char* type)
{
    // printf("Values recieved - %s - Identifier\t%s - type\n",identifier_name,type);
    // printf("Values recieved - %s - Identifier\t%d - Value\t%s - type\n", identifier_name, (int)value, type);
    
    store_table *tokenptr = symbol_table[0];
    store_table *prev_ptr = NULL;

    int* insert_at_index = (int *)malloc(sizeof(int));

    tokenptr = lookup(identifier_name, insert_at_index, prev_ptr);

    if(tokenptr == NULL)
    {
        tokenptr = (store_table*)malloc(sizeof(store_table));
        strncpy(tokenptr->iden_name, identifier_name, strlen(identifier_name));
        tokenptr->lines = (tok_occ*)malloc(sizeof(tok_occ));
        tokenptr->lines->line_number = line_number - 1;
	    tokenptr->lines->scope_of_id = scope;
        tokenptr->lines->next = NULL;
        // tokenptr->values = (tokeninfo*)malloc(sizeof(tokeninfo)*INTMAX);
        tokenptr->lines->values = (tokeninfo*)malloc(sizeof(tokeninfo));
        
        if (strcmp(type, type_int) == 0)
        {
            strncpy(tokenptr->lines->type, type, strlen(type));
            tokenptr->lines->values->value = (int)value;
        }

        else if (strcmp(type, type_string) == 0)
        {
            strncpy(tokenptr->lines->type, type, strlen(type));
            tokenptr->lines->values->stringval = (char *)malloc(sizeof(char)*100);
            strcpy(tokenptr->lines->values->stringval, (char *)value);
        }
        
        else if (strcmp(type, type_vector) == 0)
        {
            strncpy(tokenptr->lines->type, type, strlen(type));
            tokenptr->lines->values->vectorval = (char *)malloc(sizeof(char)*500);
            strcpy(tokenptr->lines->values->vectorval, (char *)value);
        }

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
        line_no_ptr->next->line_number = line_number - 1;
	    line_no_ptr->next->scope_of_id = scope;
        line_no_ptr->next->next = NULL;
        line_no_ptr->next->values = (tokeninfo*)malloc(sizeof(tokeninfo));

        if (strcmp(type, type_int) == 0)
        {
            strncpy(line_no_ptr->next->type, type, strlen(type));
            line_no_ptr->next->values->value = (int)value;
        }

        else if (strcmp(type, type_string) == 0)
        {
            strncpy(line_no_ptr->next->type, type, strlen(type));
            line_no_ptr->next->values->stringval = (char *)malloc(sizeof(char)*100);
            strcpy(line_no_ptr->next->values->stringval, (char *)value);
        }

        else if (strcmp(type, type_vector) == 0)
        {
            strncpy(line_no_ptr->next->type, type, strlen(type));
            line_no_ptr->next->values->vectorval = (char *)malloc(sizeof(char)*500);
            strcpy(line_no_ptr->next->values->vectorval, (char *)value);
        }
    }
    return;
}

void insert_to_symbol_table_identifier(const char* identifier_name)
{
    strcpy(iden_name_global, identifier_name);
    printf("%s Copied globally\n",iden_name_global);
    return;
}

void insert_to_symbol_table_value(void* value, char* type)
{
    insert_to_symbol_table(iden_name_global, value, type);
    return;
}

void insert_to_symbol_table_vector_value(void* value, char* type)
{
    
    if (strcmp(type, type_vector_end) == 0)
    {
        printf("TRIGGERED INSERTION\n");
        strcat(vector_value_accumulate, ")");
        temp_vector_pass = strdup(vector_value_accumulate);
        strcpy(vector_value_accumulate, "(");
        insert_to_symbol_table(iden_name_global, temp_vector_pass, type_vector);
    }
    
    else
    {
        strcat(vector_value_accumulate, (char *)value);
        strcat(vector_value_accumulate, ", ");
    }
    
    return;
}

void incrline()
{
    line_number++;
    return;
}

void dump_to_file(FILE *of)
{  
  char blank[1] = "";
  fprintf(of,"---------------\t\t\t------------\t\t\t------\t\t\t------\t\t\t------\n");
  fprintf(of,"Identifier Name\t\t\tLine Numbers\t\t\t Scope\t\t\t Type \t\t\t Value\n");
  fprintf(of,"---------------\t\t\t------------\t\t\t------\t\t\t------\t\t\t------\n");
  
  for (int i=0; i < _maxsize; ++i){
    if (symbol_table[i] != NULL)
    {
        store_table *tokenptr = symbol_table[i];
        while (tokenptr != NULL)
        {
            tok_occ *line_no_ptr = tokenptr->lines;
            tok_occ *scope_ptr = tokenptr->lines;
            tok_occ *value_ptr = tokenptr->lines;
            fprintf(of,"%-20s ",tokenptr->iden_name);
            while (line_no_ptr != NULL)
            {
                fprintf(of,"\t%4d ",line_no_ptr->line_number);
                fprintf(of,"\t\t\t\t\t");
                fprintf(of,"%4d ",scope_ptr->scope_of_id);
                fprintf(of,"\t\t\t");
                
                if (strcmp(value_ptr->type, type_int) == 0)
                {
                    fprintf(of,"%s",type_int);
                    fprintf(of,"\t\t\t\t");
                    fprintf(of,"%-10d ",value_ptr->values->value);
                }

                else if (strcmp(value_ptr->type, type_string) == 0 )
                {
                    fprintf(of,"%s",type_string);
                    fprintf(of,"\t\t\t");
                    fprintf(of,"%-10s ",value_ptr->values->stringval);
                }

                else
                {
                    fprintf(of,"%s",type_vector);
                    fprintf(of,"\t\t\t");
                    fprintf(of,"%-10s ",value_ptr->values->vectorval);
                }
                
                line_no_ptr = line_no_ptr->next;
                scope_ptr = scope_ptr->next;
                value_ptr = value_ptr->next;
                fprintf(of,"\n");
                fprintf(of,"%-20s ",blank);
            }
	        
            fprintf(of,"\n");
            tokenptr = tokenptr->next;
        }
    }
  }
}

void dump_optimized(FILE *of)
{  
    quadruple *node = Head_quad;
    int x=1;

    char St_no[6] = "St.no";
    char Operator[9] = "Operator";
    char Arg1[5] = "Arg1";
    char Arg2[5] = "Arg2";
    char Result[7] = "Result";
    char DPS_delimiter[2] = ".";

    // fprintf(ptr,"St.No\t\tOperator\t\tArg1\t\t\t\t\t\t\t\t\t\t\tArg2\t\t\tResult\t\t\tisLoop\t\n");
    // fprintf(ptr,"%s\t\t%-10s\t\t\t\t%-10s\t\t%-8s\t\t%-8s\n", St_no, Operator, Arg1, Arg2, Result);
    while (node != NULL) 
    { 		
        if (strcmp(node->op, "DC") != 0)
        {
            fprintf(of,"%d\t%s\t",node->index+1,node->op);
            if (strcmp(node->arg1, " ") == 0)
            {
                fprintf(of,"%s\t",DPS_delimiter);
            }
            else
            {
                fprintf(of,"%s\t",node->arg1);
            }
            if (strcmp(node->arg2, " ") == 0)
            {
                fprintf(of,"%s\t",DPS_delimiter);
            }
            else
            {
                fprintf(of,"%s\t",node->arg2);
            }
            if (strcmp(node->result, " ") == 0)
            {
                fprintf(of,"%s",DPS_delimiter);
            }
            else
            {
                fprintf(of,"%s",node->result);
            }
            fprintf(of,"\n");
            x++;
        }
        node = node->next;
        
    } 
    return;
}



void concatenate(char p[], char q[]) {
   int c, d;
   
   c = 0;
 
   while (p[c] != '\0') {
      c++;      
   }
 
   d = 0;
 
   while (q[d] != '\0') {
      p[c] = q[d];
      d++;
      c++;    
   }
 
   p[c] = '\0';
}


void push_vector(char *s)
{
    
    //printf("\nin push \n");
    printf("\n %s pushed vector yayy\n",s);
    strcpy(vt[++vt_top],s);
    printf("Push Success\n\n");
}

void vector_assign(int isLoop)
{
	
    int vt_val=1;
    char result[100];
    strcpy(result,"c(");
    // printf("\nin codegen assign \n");
    printf("in vector_assign ");
    while(vt_val!=vt_top+1){
    concatenate(result,vt[vt_val]);
    printf("vt_val=%d value=%s \n",vt_val,vt[vt_val]);
    vt_val++;
    }
    push(result);
    codegen_assign(isLoop);
    printf("\n Result: %s\n",result);
    
}

void push(char *s)
{
    
    //printf("\nin push \n");
    printf("\n %s pushed yayy\n",s);
    strcpy(st[++top],s);
    printf("Push Success\n\n");
}

void codegen(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    
    sprintf(temp,"t%d",i_);


    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr, "%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]); // write to file 
    fclose(fptr);

    strcpy(op,st[top-1]);
    strcpy(arg1,st[top]);
    strcpy(arg2,st[top-2]);
    strcpy(result,temp);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );
    // print_quadruple();

    top-=2;
    strcpy(st[top],temp);
    i_++;
}

void codegen_assign(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];

	printf("isLoop:%d\n",isLoop);
    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"%s %s %s\n",st[top-2],st[top-1],st[top]);
    fclose(fptr);

    strcpy(op,st[top-1]);
    strcpy(arg1,st[top]);
    strcpy(arg2," ");
    strcpy(result,st[top-2]);


    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );
    // print_quadruple();
    top-=2;
}


void if_lab1(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    if_lnum++;
    sprintf(temp,"t%d",i_);
    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 

    fprintf(fptr,"%s = not %s\n",temp,st[top]);
    fprintf(fptr,"if %s goto Loop_%d\n", temp, if_lnum);
    fclose(fptr);

    strcpy(op,"not");
    strcpy(arg1,st[top]);
    strcpy(arg2," ");
    strcpy(result,temp);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result, isLoop);

    sprintf(label,"Loop_%d",if_lnum);
    strcpy(op,"if");
    strcpy(arg1,temp);
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop);

    // print_quadruple();

    i_++;
    if_label[++if_ltop]=if_lnum;
}

void if_lab2(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    // printf("\nin if_lab2 \n");

    int x;
    if_lnum++;
    x=if_label[if_ltop--];

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"goto Loop_%d\n",if_lnum);
    fprintf(fptr,"Loop_%d: \n",x);
    fclose(fptr);

    printf("\nin if_lab2 before goto \n");

    sprintf(label,"Loop_%d",if_lnum);
    strcpy(op,"goto");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    printf("\nin if_lab2 after goto \n");


    sprintf(label,"Loop_%d",x);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    printf("\nin if_lab2 after label \n");

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    
    // print_quadruple();

    // printf("goto Loop_%d\n",if_lnum);
    // printf("Loop_%d: \n",x);
    if_label[++if_ltop]=if_lnum;
}


void if_lab3(int isLoop)
{

    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    // printf("\nin if_lab3 \n");

    int y;
    y=if_label[if_ltop--];

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 

    fprintf(fptr,"Loop_%d: \n",y);
    // printf("Loop_%d: \n",y);
    fclose(fptr);

    sprintf(label,"Loop_%d",if_lnum);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    printf("IF LABEL 3\n");
    // print_quadruple();
    

}

void while_lab1(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];


    // printf("lab1 while_start= %d\n",while_start);
    // printf("lab1 while_lnum = %d\n",while_lnum);
    w++;
    while_label[while_top]=w;
    int a= while_label[while_top];
    while_top++;

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    // fprintf(fptr,"\n lab1 w = %d a = %d while_top=%d\n\n",w,a,while_top);

    fprintf(fptr,"While_%d: \n",a);
    fclose(fptr);

    sprintf(label,"While_%d",a);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result, isLoop);
}

void while_lab2(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    sprintf(temp,"t%d",i_);
    
    w++;
    while_label[while_top]=w;
    int a= while_label[while_top];
    while_top++;

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"%s = not %s\n",temp,st[top]);
    fprintf(fptr,"if %s goto While_%d\n",temp,a);
    fclose(fptr);

    strcpy(op,"not");
    strcpy(arg1,st[top]);
    strcpy(arg2," ");
    strcpy(result,temp);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    sprintf(label,"While_%d",a);
    strcpy(op,"if");
    strcpy(arg1,temp);
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    i_++;
 }

void while_lab3(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    while_top--;
    int a= while_label[while_top];
    while_top--;
    int b= while_label[while_top];

    fprintf(fptr,"goto While_%d \n",b);
    fprintf(fptr,"While_%d: \n",a);
    fclose(fptr);

    sprintf(label,"While_%d",b);
    strcpy(op,"goto");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    sprintf(label,"While_%d",a);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

}

void for_lab1(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    f++;
    for_label[for_top]=f;
    int a= for_label[for_top];
    for_top++;

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"For_%d: \n",a);
    fclose(fptr);

    sprintf(label,"For_%d",a);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

}

void for_lab2(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    sprintf(temp,"t%d",i_);

    f++;
    for_label[for_top]=f;
    int a= for_label[for_top];
    for_top++;

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"%s = not %s\n",temp,st[top]);
    fprintf(fptr,"if %s goto For_%d\n",temp,a);
    fclose(fptr);

    strcpy(op,"not");
    strcpy(arg1,st[top]);
    strcpy(arg2," ");
    strcpy(result,temp);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    sprintf(label,"For_%d",a);
    strcpy(op,"if");
    strcpy(arg1,temp);
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    i_++;
}

void for_lab3(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    for_top--;
    int a= for_label[for_top];
    for_top--;
    int b= for_label[for_top];

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 

    fprintf(fptr,"goto For_%d \n",b);
    fprintf(fptr,"For_%d: \n",a);
    fclose(fptr);

    sprintf(label,"For_%d",b);
    strcpy(op,"goto");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    sprintf(label,"For_%d",a);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

}

void check_break(int isLoop){
    printf("################# break called %d #############\n",break_);
    break_++;
    printf("################# break called after %d #############\n",break_);
    if(repeat_top >0)
        repeat_lab3(isLoop);

}

void repeat_lab1(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    r++;
    repeat_label[repeat_top]=r;
    int a= repeat_label[repeat_top];
    repeat_top++;

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"Repeat_%d: \n",a);
    fclose(fptr);

    sprintf(label,"Repeat_%d",a);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

}

void repeat_lab2(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    repeat_top--;
    int a= repeat_label[repeat_top];

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 

    fprintf(fptr,"goto Repeat_%d\n",a-1);
    fclose(fptr);

    sprintf(label,"Repeat_%d",a-1);
    strcpy(op,"goto");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);

    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop);

    if(break_>0){

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"Repeat_%d: \n",break_r);
    fclose(fptr);

    sprintf(label,"Repeat_%d",break_r);
    strcpy(op,"Label");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );
    break_ --;
    }

}

void repeat_lab3(int isLoop)
{
    char op[10];
    char arg1[100];
    char arg2[100];
    char result[100];
    char label[100];

    r++;
    break_r=r;
    repeat_label[repeat_top]=r;
    int a= repeat_label[repeat_top];
    repeat_top++;

    FILE *fptr = fopen("3AC_output.txt", "a"); // write only 
    fprintf(fptr,"goto Repeat_%d: \n",r);
    fclose(fptr);

    sprintf(label,"Repeat_%d",r );
    strcpy(op,"goto");
    strcpy(arg1," ");
    strcpy(arg2," ");
    strcpy(result,label);
    
    insert_to_quadruple(&Head_quad, op ,arg1 ,arg2 ,result,isLoop );

    return; 

}

void insert_to_quadruple (quadruple **head_ref , char *op, char *arg1, char *arg2, char *result, int isLoop)
{ 
    /* 1. allocate node */
    quadruple* new_node = (quadruple*) malloc(sizeof(quadruple)); 
  
    quadruple *last = *head_ref;  /* used in step 5*/
    
    printf("\nin insert quadruple isLoop:%d\n",isLoop);

    /* 2. put in the data  */
    strcpy(new_node->op,op); 
    strcpy(new_node->arg1,arg1); 
    strcpy(new_node->arg2,arg2); 
    strcpy(new_node->result,result); 
	new_node->isLoop = isLoop;
	new_node->index = Index;

	Index++;
	printf("\nafter insert quadruple Loop:%d\n",new_node->isLoop);
    
    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
    {
        last = last->next; 
    }
  
    /* 6. Change the next of last node */
    last->next = new_node; 
    return; 
} 
  

void print_quadruple()
{ 
	//printf("\nIN print_quad\n\n");
	quadruple *node = Head_quad;
	int x=1;

	FILE *ptr = fopen("optimization.txt", "a"); // write only 
	char St_no[6] = "St.no";
	char Operator[9] = "Operator";
	char Arg1[5] = "Arg1";
	char Arg2[5] = "Arg2";
	char Result[7] = "Result";

	// fprintf(ptr,"St.No\t\tOperator\t\tArg1\t\t\t\t\t\t\t\t\t\t\tArg2\t\t\tResult\t\t\tisLoop\t\n");
	fprintf(ptr,"%s\t\t%-10s\t\t\t\t%-10s\t\t%-8s\t\t%-8s\n", St_no, Operator, Arg1, Arg2, Result);
	while (node != NULL) 
	{ 		
		if (strcmp(node->op, "DC") != 0)
		{
			fprintf(ptr,"%d\t\t\t%-10s\t\t\t",node->index+1,node->op);
			if (strlen(node->arg1) > 9)
			{
				fprintf(ptr,"\t%.7s...\t",node->arg1);
			}
			else
			{
				fprintf(ptr,"\t%-10s\t",node->arg1);
			}
			fprintf(ptr,"\t%-8s\t",node->arg2);
			fprintf(ptr,"\t%-8s\t",node->result);
			fprintf(ptr,"\t%-8d\t",node->isLoop);
			fprintf(ptr,"\n\n");
			x++;
		}
		node = node->next;
		
  } 

// fprintf(ptr,"print done !!!!!!!! \n");
  fprintf(ptr,"length of quadruple: %d\n",x-1);
  fclose(ptr);
  return;
} 

//////////////////OPTIMIZATION///////////////////////////////

int isBinaryOperator(char *op)
{
	switch (op[0])
	{
        case '=':
        case '+':
        case '-':
        case '*':
        case '/':
        case '<':
        case '>':
        case '<-':
            return 1;
        default:
            return 0;
	}
}


int deadCodeElimination()
{
	printf("before deadcode elimination!\n");

	int deadCode = 1, deadLine, optimized = 0;
	while (deadCode)
	{
		quadruple *Quad_i = Head_quad;
		quadruple *Quad_j = Head_quad;

		deadCode = 0;
		for (int i = 0; i < Index; i++)
		{
			if ((isBinaryOperator(Quad_i->op)) && (!Quad_i->isLoop))
			{
				deadLine = 1;
				for (int j = i + 1; j <Index; j++)
				{
					Quad_j = Head_quad;
					while(Quad_j->index!=j)
						Quad_j = Quad_j->next;

					if (strcmp("DC", Quad_j->op) != 0)
					{

						if ((strcmp(Quad_i->result, Quad_j->arg1) == 0) || (strcmp(Quad_i->result, Quad_j->arg2) == 0)  || (strstr(Quad_j->arg2, Quad_i->result) != NULL))
						{
							deadLine = 0;
							break;
						}

						if (!strcmp(Quad_i->result, Quad_j->result))
						{
							break;
						}
					}
				}
				if (deadLine)
				{
					strcpy(Quad_i->op, "DC");
					deadCode = 1;
					optimized = 1;
				}
			}
		Quad_i = Quad_i->next;
		}
	}
	printf("after deadcode elemination!\n");

	return optimized;
}

int isNumber(char *str)
{
	int num = atoi(str);

	if (num == 0 && str[0] != 0)
		return 0;
	else
		return 1;
}

int performOperation(char *op, int num1, int num2)
{
	switch (op[0])
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	default:
		return 0;
	}
}

int constantFolding()
{
	printf("before constant folding!\n");
	int optimized = 0;
	quadruple *Quad_i = Head_quad;
	for (int i = 0; i < Index; i++)
	{

		if ((isBinaryOperator(Quad_i->op)) && (Quad_i->arg1 != NULL && Quad_i->arg1 != " ") && (Quad_i->arg2 != " "))
		{
	
			if (isNumber(Quad_i->arg1) && isNumber(Quad_i->arg2))
			{
	
				int num1 = atoi(Quad_i->arg1), num2 = atoi(Quad_i->arg2);
				int ans = performOperation(Quad_i->op, num1, num2);
				strcpy(Quad_i->arg2, "NULL");
				sprintf(Quad_i->arg1, "%d", ans);
				strcpy(Quad_i->op, "=");
				constantPropagation(ans, i);
				if (Quad_i->result[0] == 't')
				{
					strcpy(Quad_i->op, "DC");
				}
				optimized = 1;
			}
		}
		Quad_i = Quad_i->next;
	}
	printf("after constant folding!\n");
	return optimized;
}

int constantPropagation(int res, int index)
{
	printf("before constant propagating!\n");
	quadruple *Quad = Head_quad;
	quadruple *Quad_i = Head_quad;
	
	while(Quad->index!=index)
		Quad = Quad->next;


	char *op = strdup(Quad->result);
	int propagated = 0;
	for (int i = index + 1; i < Index; i++)
	{
		while(Quad_i->index!=i)
			Quad_i = Quad_i->next;


		if (strcmp("DC", Quad_i->op))
		{

			if (!strcmp(op, Quad_i->arg1))
			{
				sprintf(Quad_i->arg1, "%d", res);
				propagated = 1;
			}
			if (!strcmp(op, Quad_i->arg2))
			{
				sprintf(Quad_i->arg2, "%d", res);
				propagated = 1;
			}
		}
	}
	printf("after constant propagating!\n");
	return propagated;
}


int propagate()
{
	int optimized = 0, propagated = 0;
	quadruple *Quad_i = Head_quad;
	Quad_i = Quad_i->next;

	for (int i = Index-1; i >= 0; i--)
	{
		Quad_i = Head_quad;

		while(Quad_i->index != i)
			Quad_i = Quad_i->next;

		if (!Quad_i->isLoop && !strcmp("=", Quad_i->op) && isNumber(Quad_i->arg1) && !strcmp("NULL", Quad_i->arg2))
		{
			propagated = constantPropagation(atoi(Quad_i->arg1), i);
			optimized |= propagated;
		}

	}
	return optimized;
}

void optimize()
{
    FILE *ptr = fopen("optimization.txt", "a"); // write only 

	fprintf(ptr,"\n\n----------------------------Before optimization!--------------------------------\n\n");
    fclose(ptr);
	int optimize = 1;

    print_quadruple();

	while (optimize)
	{
		optimize = 0;
		optimize = constantFolding();
		optimize |= propagate();
		optimize |= deadCodeElimination();
	}

    ptr = fopen("optimization.txt", "a"); // write only 
	fprintf(ptr,"\n\n-----------------------------After optimization!--------------------------------\n\n");
    fclose(ptr);

	print_quadruple();
}
