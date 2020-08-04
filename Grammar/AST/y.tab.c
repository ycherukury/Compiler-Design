/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

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

#line 101 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    ID = 259,
    NUM = 260,
    VECTOR = 261,
    LOOP_WHILE = 262,
    LOOP_FOR = 263,
    LOOP_IF = 264,
    LOOP_ELSE = 265,
    LOOP_REPEAT = 266,
    IN = 267,
    SEQ = 268,
    FROM = 269,
    BREAK = 270,
    NEXT = 271,
    PRINT = 272,
    LLA = 273,
    LA = 274,
    RA = 275,
    RRA = 276,
    OPREL = 277,
    NL = 278,
    END_OF_FILE = 279
  };
#endif
/* Tokens.  */
#define STRING 258
#define ID 259
#define NUM 260
#define VECTOR 261
#define LOOP_WHILE 262
#define LOOP_FOR 263
#define LOOP_IF 264
#define LOOP_ELSE 265
#define LOOP_REPEAT 266
#define IN 267
#define SEQ 268
#define FROM 269
#define BREAK 270
#define NEXT 271
#define PRINT 272
#define LLA 273
#define LA 274
#define RA 275
#define RRA 276
#define OPREL 277
#define NL 278
#define END_OF_FILE 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,     2,
      29,    30,    27,    25,    36,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,     2,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,    34,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    74,    75,    76,    78,    80,    81,    82,
      84,    86,    87,    89,    91,    93,    94,    95,    97,   100,
     101,   104,   105,   107,   108,   109,   112,   113,   114,   116,
     117,   119,   120,   123,   124,   127,   128,   130,   132,   133,
     134,   135,   137,   138,   139,   140,   142,   143,   145,   146,
     148,   149,   151,   153,   155,   157,   159,   161,   162,   164,
     165,   167,   169,   170,   171,   174,   175,   177,   178,   179,
     181
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "ID", "NUM", "VECTOR",
  "LOOP_WHILE", "LOOP_FOR", "LOOP_IF", "LOOP_ELSE", "LOOP_REPEAT", "IN",
  "SEQ", "FROM", "BREAK", "NEXT", "PRINT", "LLA", "LA", "RA", "RRA",
  "OPREL", "NL", "END_OF_FILE", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'{'", "'}'", "'='", "'|'", "'&'", "','", "':'", "$accept", "ROOT",
  "Statement", "SimpleStatement", "SmallStatement", "Expression",
  "AssignmentExpression", "id", "num", "Expr1main", "Expr1", "Expr2",
  "Expr3", "Expr4", "opassgnleft", "opassgnright", "oppm", "opmd",
  "FlowSt", "display", "printitems", "CompoundStatement", "if_loop",
  "elseif_loop", "else_loop", "while_loop", "for_loop", "cdn",
  "repeat_loop", "suite", "condition", "subcond1", "subcond2",
  "RelationalExpression", "sequence", "startendind", "jumpsize", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    43,    45,    42,    47,    40,
      41,   123,   125,    61,   124,    38,    44,    58
};
# endif

#define YYPACT_NINF -98

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-98)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      38,   -98,   -98,   -98,   -98,   -22,   -16,     9,    34,    -4,
      17,    47,     7,    63,    56,    38,    49,   -98,   -98,    -1,
     -98,    48,   -98,    25,    43,   -98,   -98,   -98,    38,    58,
      60,    61,    64,    70,    85,    70,    67,   -98,   -98,    19,
     -98,    62,   -98,   -98,   -98,   -98,   -98,   -98,   -98,    53,
     -98,   -98,    85,   -98,   -98,     7,   -98,   -98,     7,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,    -3,    59,   -98,    69,
      81,    66,    30,    38,    65,   -98,   -98,   -98,    68,   -98,
     -98,   -98,    43,   -98,    76,    70,    70,     7,     1,    77,
      78,   -98,   -98,   -98,    71,    59,   -98,   -98,    74,   -98,
     -98,    73,    75,    67,   100,    67,    67,    79,    42,    82,
      85,    83,    84,   -98,   100,   100,   -98,   -98,   -98,    97,
      72,   -98,    -5,   -98,   -98,    95,    88,    67,    80,    70,
      86,   100,    32,   -98,   -98,    89,    67,    87,    97,   -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    16,    13,    14,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     7,    10,    23,
      24,     0,    15,    18,    19,    21,     8,     9,     5,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    36,    41,
      23,     0,     1,     2,     3,     6,    28,    27,    26,     0,
      29,    30,     0,    31,    32,     0,    33,    34,     0,     4,
      42,    43,    44,    45,    63,    62,     0,    58,    60,    61,
       0,     0,     0,     5,     0,    40,    39,    38,     0,    25,
      11,    12,    20,    22,     0,     0,     0,     0,     0,     0,
       0,    56,    55,    37,     0,    57,    59,    64,     0,    66,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,    65,    67,    53,    46,
      68,    69,     0,    47,    49,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    70,     0,     0,     0,    51,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -12,   -98,   -98,   -98,   -98,     0,   -94,    90,
     -10,   -98,    91,    92,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -24,   -98,   -98,   -98,   -98,   -98,   -97,
     -34,    36,    37,   -98,   -98,   -98,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    40,    20,    21,
      22,    23,    24,    25,    49,    52,    55,    58,    26,    27,
      78,    28,    29,   123,   124,    30,    31,    71,    32,    74,
      66,    67,    68,    69,   100,   109,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    72,    41,    44,   126,     2,   107,    33,   111,   112,
     108,     2,     3,    34,    98,    19,    59,    46,    47,    37,
     120,   121,    75,     2,     3,    76,   127,    84,    19,    77,
     130,    85,    48,    65,    70,    65,    12,   134,    35,   137,
      38,     1,     2,     3,     4,     5,     6,     7,    12,     8,
      53,    54,    81,     9,    10,    11,     1,     2,     3,     4,
      90,    91,   135,    42,    85,    36,    85,    12,    50,    51,
      56,    57,    45,    19,     2,    64,    39,    97,   114,   115,
      43,    60,    12,    61,    62,    65,    65,    63,    99,     2,
      73,    87,    79,    88,    86,   132,    89,    92,    93,    94,
     101,   102,   103,   104,   105,     3,   106,   122,   125,   128,
     117,   113,   116,   131,   139,   118,   119,   129,   133,   138,
     136,    95,     0,    96,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
      83
};

static const yytype_int16 yycheck[] =
{
       0,    35,    12,    15,     9,     4,   103,    29,   105,   106,
     104,     4,     5,    29,    13,    15,    28,    18,    19,    23,
     114,   115,     3,     4,     5,     6,    31,    30,    28,    39,
     127,    34,    33,    33,    34,    35,    29,   131,    29,   136,
      23,     3,     4,     5,     6,     7,     8,     9,    29,    11,
      25,    26,    52,    15,    16,    17,     3,     4,     5,     6,
      30,    73,    30,     0,    34,    31,    34,    29,    20,    21,
      27,    28,    23,    73,     4,     5,    29,    87,    36,    37,
      24,    23,    29,    23,    23,    85,    86,    23,    88,     4,
      23,    22,    30,    12,    35,   129,    30,    32,    30,    23,
      23,    23,    31,    29,    31,     5,    31,    10,    36,    14,
     110,    32,    30,    33,   138,    32,    32,    29,    32,    32,
      31,    85,    -1,    86,    -1,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    11,    15,
      16,    17,    29,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    56,    57,    59,    60,
      63,    64,    66,    29,    29,    29,    31,    23,    23,    29,
      45,    48,     0,    24,    40,    23,    18,    19,    33,    52,
      20,    21,    53,    25,    26,    54,    27,    28,    55,    40,
      23,    23,    23,    23,     5,    45,    68,    69,    70,    71,
      45,    65,    68,    23,    67,     3,     6,    48,    58,    30,
      47,    45,    50,    51,    30,    34,    35,    22,    12,    30,
      30,    40,    32,    30,    23,    69,    70,    48,    13,    45,
      72,    23,    23,    31,    29,    31,    31,    67,    46,    73,
      74,    67,    67,    32,    36,    37,    30,    45,    32,    32,
      46,    46,    10,    61,    62,    36,     9,    31,    14,    29,
      67,    33,    68,    32,    46,    30,    31,    67,    32,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    40,    41,    42,    42,    42,
      43,    44,    44,    45,    46,    47,    47,    47,    48,    49,
      49,    50,    50,    51,    51,    51,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    58,    58,
      58,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    64,    65,    66,    67,    68,    68,    69,
      69,    70,    71,    71,    71,    72,    72,    73,    73,    73,
      74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     1,     1,
       1,     0,     2,     2,     2,     2,     8,     9,     9,     1,
       4,     0,     8,     8,     3,     4,     2,     3,     1,     3,
       1,     1,     1,     1,     3,     4,     1,     2,     3,     3,
       7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 72 "yacc.y" /* yacc.c:1646  */
    {displayast((yyvsp[-1]));}
#line 1376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 75 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "yacc.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 78 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 84 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "yacc.y" /* yacc.c:1646  */
    {if(y==1){(yyval)=create("=",(yyvsp[-2]),NULL,(yyvsp[0]));}if(y==2){(yyval)=create("<-",(yyvsp[-2]),NULL,(yyvsp[0]));}if(y==3){(yyval)=create("<<-",(yyvsp[-2]),NULL,(yyvsp[0]));}}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 87 "yacc.y" /* yacc.c:1646  */
    {if(z==1){(yyval)=create("->",(yyvsp[-2]),NULL,(yyvsp[0]));}if(z==2){(yyval)=create("->>",(yyvsp[-2]),NULL,(yyvsp[0]));}}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(ident,NULL,NULL,NULL);}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 91 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(val,NULL,NULL,NULL);}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 93 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 95 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 100 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 101 "yacc.y" /* yacc.c:1646  */
    {if(x==1){(yyval)=create("+",(yyvsp[-2]),NULL,(yyvsp[0]));}if(x==2){(yyval)=create("-",(yyvsp[-2]),NULL,(yyvsp[0]));}}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 104 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 105 "yacc.y" /* yacc.c:1646  */
    {if(x==3){(yyval)=create("*",(yyvsp[-2]),NULL,(yyvsp[0]));} else{(yyval)=create("/",(yyvsp[-2]),NULL,(yyvsp[0]));}}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 107 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 108 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 109 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 112 "yacc.y" /* yacc.c:1646  */
    {y=1;}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 113 "yacc.y" /* yacc.c:1646  */
    {y=2;}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 114 "yacc.y" /* yacc.c:1646  */
    {y=3;}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 116 "yacc.y" /* yacc.c:1646  */
    {z=1;}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 117 "yacc.y" /* yacc.c:1646  */
    {z=2;}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 119 "yacc.y" /* yacc.c:1646  */
    {x=1;}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 120 "yacc.y" /* yacc.c:1646  */
    {x=2;}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 123 "yacc.y" /* yacc.c:1646  */
    {x=3;}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 124 "yacc.y" /* yacc.c:1646  */
    {x=4;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 127 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("BREAK",(yyvsp[0]),NULL,NULL);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 128 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("NEXT",(yyvsp[0]),NULL,NULL);}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 130 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("PRINT",(yyvsp[-1]),NULL,NULL);}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 132 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 133 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(vec,NULL,NULL,NULL);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 134 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(str,NULL,NULL,NULL);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 135 "yacc.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 137 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 138 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 139 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 140 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 142 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("if",(yyvsp[-5]),NULL,(yyvsp[-1]));}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 143 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("if-else",(yyvsp[-6]),(yyvsp[-2]),(yyvsp[0]));}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 145 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-5]),(yyvsp[-2]),(yyvsp[0]));}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 146 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 148 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,NULL);}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "yacc.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 151 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("while",(yyvsp[-5]),NULL,(yyvsp[-1]));}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 153 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("for",(yyvsp[-5]),NULL,(yyvsp[-1]));}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 155 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("IN",(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 157 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("repeat",(yyvsp[-1]),NULL,NULL);}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 159 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 161 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("|",(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 162 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 164 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("&",(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 165 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 167 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 169 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 170 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(val,NULL,NULL,NULL);}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 171 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(relop,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 174 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("seq",(yyvsp[-1]),NULL,NULL);}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 175 "yacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 177 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 178 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(",",(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 179 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create(":",(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 181 "yacc.y" /* yacc.c:1646  */
    {(yyval)=create("",(yyvsp[-6]),NULL,(yyvsp[-4]));}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1788 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 182 "yacc.y" /* yacc.c:1906  */


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
	/*if(ast->left || ast->right)
		printf("(");
	printf("%s",ast->type);
	if(ast->left)
		displayast(ast->left);
	if(ast->right)
		displayast(ast->right);
	if(ast->left||ast->right)
		printf(")");*/
	int h=height(ast);
	int i;
	for(i=1;i<=h;i++)
	{
		printlevel(ast,i);
		printf("\n");
	}
}

int yyerror(char* s)
{
    //printf("\n\n\nMy error :- %s\n\n",s);
    exit(0);
}

