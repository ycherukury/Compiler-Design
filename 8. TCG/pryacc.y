%{
    
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table_header.h"
#include <string.h>


int yylex();
int yyerror();
int yywrap();

extern FILE *yyin;
extern FILE *yyout;

extern char *id;
extern char *val;
extern char *relop;
extern char *strval;


char *e ;
char inttype[4] = "int";
char strtype[7] = "string";
char vectortype[7] = "vector";
char vector_end_type[11] = "vectorend";


extern int lineno;
int flag1 = -1;
int flag2 = -1;
int igonre_flags = 0;
int success_flag = 1;
int isLoop;

%}

%start ROOT
%token STRING
%token ID
%token NUM
%token VECTOR_START
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
ROOT                    :  Statement END_OF_FILE{isLoop=0;if(success_flag == 1) {printf("\n\n\nSyntax is perfect\n\n");return 0;} else {printf("\n\n\nIncorrect Syntax\n\n");return 0;};}
| error END_OF_FILE{printf("\n\n\nLine number %d :- Incorrect Syntax\n\n",lineno); exit(0);};

Statement               :  SimpleStatement Statement
| CompoundStatement Statement
| ;

SimpleStatement         :  SmallStatement;

SmallStatement          :  Expression
| FlowSt NL
| display NL;

Expression              :  AssignmentExpression NL
| error NL {yyclearin;};

AssignmentExpression    :  ID {push(id);} opassgnleft Expr1main 
| Expr1main opassgnright ID
| error ID {success_flag = 0; printf("\n\nLine number %d :- Incorrect Assignment\n\n",lineno);}
| error NUM {success_flag = 0; printf("\n\nLine number %d :- Incorrect Assignment\n\n",lineno);};


Expr1main               :  Expr1                {codegen_assign(isLoop);insert_to_symbol_table_value((void *)($$), inttype);}
| STRING                                        {push(strval);codegen_assign(isLoop);insert_to_symbol_table_value((void *)(strval), strtype);}
| Vector                                        {vector_assign(isLoop);}
;

Expr1 			        : Expr2 				{$$=$1;printf("expr1= %d\n",$$);}
;

Expr2 			        : Expr3					{$$=$1;printf("expr2= %d\n",$$);}
| Expr2 oppm Expr3		                        {if($2==1) {codegen(isLoop);$$=$1+$3;printf("expr2 in %d plus %d = %d\n",$1,$3,$$);} if($2==2){codegen(isLoop);$$=$1-$3;printf("expr2 in minus= %d\n",$$);}}
;

Expr3 			        : Expr4					{$$=$1;}
| Expr3 opmd Expr4 				                {if($2==3) {codegen(isLoop);$$=$1*$3;} if($2==4){codegen(isLoop);if($3==0){return 0;} else { $$= $1/$3;}}}
;

Expr4                   :  ID                   {push(id); printf("#####\nin expr 4 %s\n#####",id);}
| NUM                                           {push(val); printf("Debug1\n"); char* newval = (char *)malloc(sizeof(char)*100); strcpy(newval,val); $$=atoi(newval);{printf("#####\nin expr4 num %s yayyy newval=%s yayy $$=%d\n#####",val,newval,$$);}}
| '(' Expr1 ')'                                 {$$=$2;}
;                                                


opassgnright            :  RA                   {push("->");}
| RRA                                           {push("->>");};

opassgnleft             :  '='                  {push("=");}
| LA                                            {push("<-");}
| LLA                                           {push("<<-");}
;

oppm                    :  '+'                  {$$=1;push("+");}
| '-'                                           {$$=2;push("-");}
;

opmd                    :  '*'                  {$$=3;push("*");}
| '/'                                           {$$=4;push("/");}
;


FlowSt                  :  BREAK {check_break(isLoop);}
| NEXT 

display                 :  PRINT '(' printitems ')';

printitems              : Expr1
| Vector
| STRING
| ;

CompoundStatement       : {isLoop=1;}       if_loop         {isLoop=0;}NL
| {isLoop=1;}       while_loop      {isLoop=0;} NL
| {isLoop=1;}       for_loop        {isLoop=0;}NL
| {isLoop=1;}       repeat_loop     {isLoop=0;}NL
| error '(' {success_flag = 0; printf("\n\nLine number %d :- Loop keyword misspelt\n\n",lineno); yyclearin;}
| error '{' {success_flag = 0; printf("\n\nLine number %d :- Loop syntax incorrect.....Please check documentation\n\n",lineno);}
| error LOOP_ELSE {printf("\n\nLine number %d :- Loop syntax incorrect.....Bracket Misplaced\n\n",lineno);};


if_loop                 :  LOOP_IF '(' condition ')' {if_lab1(isLoop);}  NL '{' suite '}' {if_lab2(isLoop);} elseif_loop;

elseif_loop             :  LOOP_ELSE LOOP_IF '(' condition ')' {if_lab1(isLoop);} '{' suite '}' {if_lab2(isLoop);} elseif_loop
| else_loop ;

else_loop               :  LOOP_ELSE '{' suite '}' {if_lab3(isLoop);}
|;

while_loop              :  LOOP_WHILE {while_lab1(isLoop);}   '(' condition ')' {while_lab2(isLoop);} NL '{' suite '}'  {while_lab3(isLoop);};

for_loop                :  LOOP_FOR   '('  ID {push(id); push(id);} IN sequence ')' {for_lab2(isLoop); push(id); push("="); push(id); push("+"); push("1"); codegen(isLoop); codegen_assign(isLoop);} NL '{' suite '}'   {for_lab3(isLoop);};

repeat_loop             :  LOOP_REPEAT {repeat_lab1(isLoop);}  '{' suite '}'   {repeat_lab2(isLoop);};

suite                   :  NL Statement;

condition               :  condition '|'    {push("|");}    subcond1   {codegen(isLoop);}
| subcond1;

subcond1                : subcond1 '&'      {push("&");}    subcond2     {codegen(isLoop);}
| subcond2;

subcond2                : RelationalExpression;

RelationalExpression    :  ID               {push(id);}
| NUM                                       {push(val);}
| RelationalExpression      OPREL           {push(relop);}    Expr1        {codegen(isLoop);}
;

sequence                :  SEQ '(' startendind ')'
| ID;

startendind             :  jumpsize
| NUM  ',' NUM                              {push("="); push("1"); codegen_assign(isLoop); for_lab1(isLoop); push("<"); push(val); codegen(isLoop);}
| NUM ':' NUM;

jumpsize                :  NUM ',' NUM ',' FROM '=' NUM;

Vector : VECTOR_START  Vectorsubexpr ')' {push_vector(")");insert_to_symbol_table_vector_value("done", vector_end_type);}

Vectorsubexpr : NUM {push_vector(val);char* newval = (char *)malloc(sizeof(char)*100); strcpy(newval,val); insert_to_symbol_table_vector_value((void *)(newval), inttype);} ','{push_vector(","); }Vectorsubexpr 
| STRING {push_vector(strval);insert_to_symbol_table_vector_value((void *)(strval), strtype);} ','{push_vector(","); } Vectorsubexpr
| NUM    {push_vector(val);char* newval = (char *)malloc(sizeof(char)*100); strcpy(newval,val); insert_to_symbol_table_vector_value((void *)(newval), inttype);}
| STRING {push_vector(strval);insert_to_symbol_table_vector_value((void *)(strval), strtype);};

%%

int main(int argc, char* argv[])
{
    init();
    FILE *pt = NULL;
    if(argc > 1)
    {
        printf("I'm here %s\n",argv[1]);
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

    optimize();

    yyout = fopen("opt_for_tcg.txt", "w");
    dump_optimized(yyout);
    fclose(yyout);
}

int yyerror(char* s)
{
    return 0;
}

