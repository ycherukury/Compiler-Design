%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "symbol_table_header.h"
   
    extern FILE *yyin;
    extern FILE *yyout;
   
    int lineno = 1;
    extern void yyerror();
    
    extern int yylval;
    extern char* yytext;
    char* ident;
    char *val;
    char *relop;
    char* vec;
    char* str;
    char* relop;
%}
LETTERS         [a-zA-Z]+
VALIDOPTIONS    [a-zA-Z|0-9|_|\.]
DIGITS	        [0-9]+
STRING          ['][^']*[']|["][^"]*["]
SPACES          [\t' '\r]
OPREL           <|>|==|<=|>=|!=
LOOP_WHILE      while
LOOP_FOR        for
LOOP_IF         if
LOOP_ELSE       else
LOOP_REPEAT     repeat
IN              in
SEQ             seq
FROM            from
PRINT           print 
BREAK           break
NEXT            next
LLA             <<-
LA              <-
EQUALS          =
RA              ->
RRA             ->>
%%
#.*\n                                                                    {printf("%s -> Comment\n",yytext);}
<<EOF>>                                                                 {return END_OF_FILE;}
{LOOP_WHILE}                                                            {/*printf("%s -> while\n",yytext);*/return LOOP_WHILE;}
{LOOP_FOR}                                                              {/*printf("%s -> for\n",yytext);*/return LOOP_FOR;}
{LOOP_IF}                                                               {/*printf("%s -> if\n",yytext);*/return LOOP_IF;}
{LOOP_ELSE}                                                             {/*printf("%s -> else\n",yytext);*/return LOOP_ELSE;}
{LOOP_REPEAT}                                                           {/*printf("%s -> repeat\n",yytext);*/return LOOP_REPEAT;}
{PRINT}                                                                 {/*printf("%s -> print\n",yytext);*/return PRINT;}        
{IN}                                                                    {/*printf("%s -> IN\n",yytext);*/return IN;}      
{SEQ}                                                                   {/*printf("%s -> SEQ\n",yytext);*/return SEQ;}      
{FROM}                                                                  {/*printf("%s -> FROM\n",yytext);*/return FROM;}        
{BREAK}                                                                 {/*printf("%s -> break\n",yytext);*/return BREAK;}
{NEXT}                                                                  {/*printf("%s -> next\n",yytext);*/return NEXT;}
({LETTERS}({VALIDOPTIONS})*|[\.]{LETTERS}({VALIDOPTIONS})*)	            {/*printf("%s \n",yytext);*/ident=strdup(yytext);return ID;}
c\(({STRING},|{DIGITS},)*({STRING}|{DIGITS})\)                          {/*printf("%s -> vector\n",yytext);*/vec =strdup(yytext);return VECTOR;}
{DIGITS}			    	                                      {/*printf("%s\t",yytext);*/val=strdup(yytext);return NUM;}
{OPREL}                                                                 {/*printf("%s -> RELOP \n",yytext);*/relop=strdup(yytext);return OPREL;}
{LLA}                                                                   {/*printf("%s -> LLA\n",yytext);*/return LLA;}
{LA}                                                                    {/*printf("%s -> LA\n",yytext);*/return LA;}
{RA}                                                                    {/*printf("%s -> RA\n",yytext);*/return RA;}
{RRA}                                                                   {/*printf("%s -> RRA\n",yytext);*/return RRA;}
{STRING}                                                                {/*printf("%s -> STRING\n",yytext);str=strdup(yytext);*/return STRING;}
{SPACES}	                                                            {;}
\n	                                                                    {/*printf("\\n -> Newline\n");*/return NL;}
.                                                                       {/*printf("%s -> Other symbols\n",yytext);*/return yytext[0];}

%%

int yywrap()
{
	return 1;
}

