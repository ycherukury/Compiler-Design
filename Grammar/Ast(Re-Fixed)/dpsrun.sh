echo $1
rm -f *.yy.c *.output y.tab.c y.tab.h
yacc yacc.y -d -v;
lex lex.l;
gcc lex.yy.c y.tab.c symbol_table_source.c -ll -o parser.out;
./parser.out $1

