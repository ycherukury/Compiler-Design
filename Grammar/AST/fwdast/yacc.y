%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table_header.h"
#include<string.h>
#include<stddef.h>
int x;
int yylex();
int yyerror();
int yywrap();
extern FILE *yyin;
extern FILE *yyout;
extern char* __identifier_name;
extern char *id;
extern char *val;
int flag1=-1;
int flag2=-1;
typedef struct node
{
	char* type;
	struct node* left;
	//struct node* mid;
	struct node* right;
}node;
node *create(char* type, node* left, node* right);
void displayast(node *ast);

#define YYSTYPE struct node *
%}

%start ROOT
%token STRING
%token ID
%token NUM
%token VECTOR
%token LOOP_WHILE
%token LOOP_FOR
%token LOOP_IF
%token LOOP_ELSE
%token LOOP_REPEAT
%token IN
%token SEQ
%token FROM
%token BREAK
%token NEXT
%token PRINT
%token LLA
%token LA
%token RA
%token RRA
%token OPREL
%token NL
%token END_OF_FILE

%left '+' '-'
%left '*' '/'
%left '(' ')'
%left '{' '}'
%left '='
%left '|' '&'
%left ',' ':'
// %left '->'
// %right '<-' '<<-'


%%
ROOT                    :  Statement END_OF_FILE {printf("\n\n\nSyntax is perfect\n\n"); $$=$1; displayast($1);};

Statement               :  SimpleStatement Statement {$$=create("body", $1, $2);}
| {$$=create("", NULL, NULL);};

SimpleStatement         :  SmallStatement NL {$$=$1;};

SmallStatement          :  Expression {$$=$1;};

Expression              :  AssignmentExpression {$$=$1;};

AssignmentExpression    :  ID_pass  opassgnleft Expr1main {$$ = create("=", $1, $3);};

Expr1main               :  Expr1 {$$=$1;};
ID_pass                 :  ID {/*printf("%s encountered\n", id);*/ $$ = create(id, NULL, NULL);};

Expr1 			        : Expr2 				{$$=$1;}
;

Expr2 			        : Expr3					{$$=$1;}
| Expr2 '+' Expr3 		{$$ = create("+", $1, $3);} 
| Expr2 '-' Expr3       {$$ = create("-", $1, $3);}
;

Expr3 			        : Expr4					{$$=$1;}
| Expr3 '*' Expr4 		{$$ = create("*", $1, $3);} 
| Expr3 '/' Expr4       {$$ = create("/", $1, $3);}
;
 
Expr4                   :  ID			        {printf("%s encountered\n", id); $$=create(id, NULL, NULL);}
| NUM                                           {char* newval = (char *)malloc(sizeof(char)*100); strcpy(newval,val); /*printf("%d encountered\n",atoi(newval));*/ $$=create(newval, NULL, NULL);}
| '(' Expr1 ')'                                 {$$=$2;}
;                                                

opassgnleft             :  '='
| LA
| LLA;

%%

int main(int argc, char* argv[])
{
    
    init();
    FILE *pt = NULL;
    if(argc > 1)
    {
        printf("Filename -> %s\n",argv[1]);
        pt = fopen(argv[1],"r");
    }
    if(!pt)
    {
        printf("Please enter correct file name\n");
        return -1;
    }
    yyin = pt;
    do
    {
        yyparse();
    }while(!feof(yyin));

    yyout = fopen("symbol_table.txt", "w");
    dump_to_file(yyout);
    fclose(yyout);

}

node *create(char* type, node* left, node* right)
{
	node* new = (node*)malloc(sizeof(node));
	char* str= (char*)malloc(strlen(type)+1);
	strcpy(str,type);
	new->left=left;
	new->right=right;
	new->type=str;
	return(new);
}

void displayast(node* ast)
{
	if (ast == NULL) 
          return;
    
    printf("%p\n%s\nLeft->%p\tRight->%p\n\n\n", ast, ast->type, ast->left, ast->right);

     displayast(ast->left); 
  
     displayast(ast->right); 

}


int yyerror(char* s)
{
    //printf("\n\n\nMy error :- %s\n\n",s);
    exit(0);
}

