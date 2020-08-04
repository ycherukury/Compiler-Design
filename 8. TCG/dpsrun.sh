echo $1
rm -f *.yy.c *.output *.txt *.out y.tab.c y.tab.h 
yacc pryacc.y -d -v;
lex prlex.l;
gcc -g -w lex.yy.c y.tab.c symbol_table_source.c -ll -o parser.out;
./parser.out $1
python3 TCG_generation.py