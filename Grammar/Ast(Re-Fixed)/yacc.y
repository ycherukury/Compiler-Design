%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table_header.h"
#include<string.h>
#include<stddef.h>
int x;
int y;
int z;
int yylex();
int yyerror();
int yywrap();
extern FILE *yyin;
extern FILE *yyout;
extern char* ident;
extern char* yytext;
extern char* val;
extern char* vec;
extern char* str;
extern char* relop;
int flag1=-1;
int flag2=-1;
typedef struct node
{
	char* type;
	struct node* left;
	struct node* mid;
	struct node* right;
}node;
node *create(char* type, node* left,node* mid, node* right);
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
ROOT                    :  Statement END_OF_FILE{displayast($1);};

Statement               :  SimpleStatement Statement{$$=create("",$1,NULL,$2);}
| CompoundStatement Statement{$$=create("",$1,NULL,$2);}
| {$$=NULL;};

SimpleStatement         :  SmallStatement NL{$$=create("",$1,NULL,$2);};

SmallStatement          :  Expression{$$=$1;}
| FlowSt{$$=$1;}
| display{$$=$1;};

Expression              :  AssignmentExpression{$$=$1;};

AssignmentExpression    :  id opassgnleft Expr1main {if(y==1){$$=create("=",$1,NULL,$3);}if(y==2){$$=create("<-",$1,NULL,$3);}if(y==3){$$=create("<<-",$1,NULL,$3);}}
| Expr1main opassgnright id	{if(z==1){$$=create("->",$1,NULL,$3);}if(z==2){$$=create("->>",$1,NULL,$3);}};

id: ID {$$=create(ident,NULL,NULL,NULL);};

num: NUM {$$=create(val,NULL,NULL,NULL);};

Expr1main               :  Expr1{$$=$1;}
| STRING {$$=create(str,NULL,NULL,NULL);}
| VECTOR {$$=create(vec,NULL,NULL,NULL);};


Expr1 			        : Expr2 {$$=$1;}				
;

Expr2 			        : Expr2 '+' Expr3 {{$$=create("+",$1,NULL,$3);}}
|Expr2 '-' Expr3 {$$=create("-",$1,NULL,$3);}			
| Expr3	{$$=$1;}
;

Expr3 			        : Expr3 '*' Expr4 {$$=create("*",$1,NULL,$3);} 
|Expr3 '/' Expr4 {$$=create("/",$1,NULL,$3);}
| Expr4	{$$=$1;}	
;								        
 
Expr4                   :  ID {$$=create(ident,NULL,NULL,NULL);} 
| NUM {$$=create(val,NULL,NULL,NULL);};      
| '(' Expr1 ')' {$$=$2;}
;                                                

opassgnleft             :  '=' {y=1;}
| LA	{y=2;}
| LLA	{y=3;};

opassgnright            :  RA		{z=1;}
| RRA	{z=2;};

FlowSt                  :  BREAK NL {$$=create("BREAK",$2,NULL,NULL);}
| NEXT NL {$$=create("NEXT",$2,NULL,NULL);};

display                 :  PRINT '(' printitems ')'	{$$=create("PRINT",$3,NULL,NULL);};

printitems              : Expr1 {$$=$1;}
| VECTOR {$$=create(vec,NULL,NULL,NULL);}
| STRING {$$=create(str,NULL,NULL,NULL);}
|{$$=NULL;} ;

CompoundStatement       :  if_loop NL {$$=create("",$1,NULL,$2);}
| while_loop NL {$$=create("",$1,NULL,$2);}
| for_loop NL {$$=create("",$1,NULL,$2);}
| repeat_loop NL {$$=create("",$1,NULL,$2);};

if_loop                 :  LOOP_IF '(' condition ')' NL '{' suite '}'{$$=create("if",$3,NULL,$7);}
|LOOP_IF '(' condition ')' NL '{' suite '}' elseif_loop {$$=create("if-else",$3,$7,$9);};

elseif_loop             :  LOOP_ELSE LOOP_IF '(' condition ')' '{' suite '}' elseif_loop {$$=create("",$4,$7,$9);}
| else_loop {$$=$1;};

else_loop               :  LOOP_ELSE '{' suite '}' {$$=create("",$3,NULL,NULL);}
|{$$=NULL;};

while_loop              :  LOOP_WHILE '(' condition ')' NL '{' suite '}'{$$=create("while",$3,NULL,$7);};

for_loop                :  LOOP_FOR '(' cdn ')' NL '{' suite '}'{$$=create("for",$3,NULL,$7);};

cdn:id IN sequence {$$=create("IN",$1,NULL,$3);};

repeat_loop             :  LOOP_REPEAT '{' suite '}'{$$=create("repeat",$3,NULL,NULL);};

suite                   :  NL Statement {$$=create("",$1,NULL,$2);};

condition               :  condition '|' subcond1 {$$=create("|",$1,NULL,$3);}
| subcond1{$$=$1;};

subcond1                : subcond1 '&' subcond2 {$$=create("&",$1,NULL,$3);}
| subcond2{$$=$1;};

subcond2                : RelationalExpression {$$=$1;};

RelationalExpression    :  id {$$=$1;}
| NUM	{$$=create(val,NULL,NULL,NULL);}
| RelationalExpression OPREL Expr1 {$$=create(relop,$1,NULL,$3);}
;

sequence                :  SEQ '(' startendind ')'  {$$=create("seq",$3,NULL,NULL);}
| id{$$=$1;};

startendind             :  jumpsize id{$$=create("",$1,NULL,$2);}
| num ',' num {$$=create(",",$1,NULL,$3);}
| num ':' num	{$$=create(":",$1,NULL,$3);};

jumpsize                :  num ',' num ',' FROM '=' num {$$=create("",$1,NULL,$3);};
%%

int main(int argc, char* argv[])
{
    
    init();
    FILE *pt = NULL;
    if(argc > 1)
    {
        printf("\n\n\n\n\nI'm here %s\n\n\n",argv[1]);
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

node *create(char* type, node* left, node* mid, node* right)
{
	node* new = (node*)malloc(sizeof(node));
	char* str= (char*)malloc(strlen(type)+1);
	strcpy(str,type);
	new->left=left;
	new->mid=mid;
	new->right=right;
	new->type=str;
	return(new);
}

int height(node* ast)
{
	if(ast==NULL)
		return 0;
	else
	{
		int lh=height(ast->left);
		int rh=height(ast->right);
		int mh=height(ast->mid);
		if(lh>rh && lh>mh)
			return(lh+1);
		else if(rh>lh && rh>mh)
			return(rh+1);
		else
			return(mh+1);
	}
}

void printlevel(node* ast, int level)
{
	if(ast==NULL)
		return;
	if(level==1)
		if(ast->type=="STATEMENT")
			printf(" ");
		else
			printf("%s ", ast->type);
	else if (level>1)
	{
		printlevel(ast->left, level-1);
		printlevel(ast->mid,level-1);
		printlevel(ast->right, level-1);
	}
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

