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
#line 1 "pryacc.y" /* yacc.c:339  */

    
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


#line 103 "y.tab.c" /* yacc.c:339  */

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
    VECTOR_START = 261,
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
#define VECTOR_START 261
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

#line 202 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

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
       0,    75,    75,    76,    78,    79,    80,    82,    84,    85,
      86,    88,    89,    91,    91,    92,    93,    94,    97,    98,
      99,   102,   105,   106,   109,   110,   113,   114,   115,   119,
     120,   122,   123,   124,   127,   128,   131,   132,   136,   137,
     139,   141,   142,   143,   144,   146,   146,   146,   147,   147,
     147,   148,   148,   148,   149,   149,   149,   150,   151,   152,
     155,   155,   155,   157,   157,   157,   158,   160,   161,   163,
     163,   163,   165,   165,   165,   167,   167,   169,   171,   171,
     172,   174,   174,   175,   177,   179,   180,   181,   181,   184,
     185,   187,   188,   189,   191,   193,   195,   195,   195,   196,
     196,   196,   197,   198
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "ID", "NUM", "VECTOR_START",
  "LOOP_WHILE", "LOOP_FOR", "LOOP_IF", "LOOP_ELSE", "LOOP_REPEAT", "IN",
  "SEQ", "FROM", "BREAK", "NEXT", "PRINT", "LLA", "LA", "RA", "RRA",
  "OPREL", "NL", "END_OF_FILE", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'{'", "'}'", "'='", "'|'", "'&'", "','", "':'", "$accept", "ROOT",
  "Statement", "SimpleStatement", "SmallStatement", "Expression",
  "AssignmentExpression", "$@1", "Expr1main", "Expr1", "Expr2", "Expr3",
  "Expr4", "opassgnright", "opassgnleft", "oppm", "opmd", "FlowSt",
  "display", "printitems", "CompoundStatement", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "if_loop", "$@10", "$@11", "elseif_loop",
  "$@12", "$@13", "else_loop", "while_loop", "$@14", "$@15", "for_loop",
  "$@16", "$@17", "repeat_loop", "$@18", "suite", "condition", "$@19",
  "subcond1", "$@20", "subcond2", "RelationalExpression", "$@21",
  "sequence", "startendind", "jumpsize", "Vector", "Vectorsubexpr", "$@22",
  "$@23", "$@24", "$@25", YY_NULLPTR
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

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -104

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      72,    80,  -134,    88,  -134,     4,  -134,  -134,   -19,     0,
      40,    -4,    10,  -134,  -134,    -1,    34,  -134,    37,    67,
    -134,     9,    21,    10,    56,    65,    90,    91,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,    94,    78,    85,    96,
      32,  -134,    98,  -134,  -134,    87,  -134,  -134,  -134,  -134,
     113,  -134,  -134,     0,  -134,  -134,     0,  -134,  -134,  -134,
     100,  -134,  -134,  -134,   101,  -134,  -134,  -134,  -134,  -134,
    -134,    64,    89,    97,  -134,  -134,  -134,   102,  -134,  -134,
    -134,    67,  -134,    95,   108,   105,   112,   120,   114,   107,
     116,  -134,  -134,  -134,  -134,  -134,  -134,    22,   106,  -134,
     118,  -134,    95,  -134,  -134,  -134,   119,  -134,     4,     4,
    -134,  -134,  -134,  -134,    30,   124,    42,   111,  -134,  -134,
     121,    95,    95,     0,  -134,    20,  -134,  -134,   115,   106,
    -134,  -134,   122,  -134,   123,   117,   119,   125,   143,  -134,
     126,   119,    83,   127,  -134,   128,  -134,   129,   144,   145,
    -134,   131,   149,  -134,   130,  -134,   119,    -3,  -134,  -134,
     139,   132,   134,   119,   135,  -134,    95,   133,   150,    52,
    -134,  -134,  -134,   136,   119,   137,  -134,   149,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    19,    26,    27,     0,    38,    39,     0,     0,
       0,     0,     0,     7,     8,     0,     0,    18,    21,    22,
      24,     0,     0,     0,     0,     0,     0,     0,    20,    16,
      17,    59,    12,     3,    57,    58,     0,    99,    96,     0,
      44,    26,     0,     1,     2,     0,     4,    11,    29,    30,
       0,    34,    35,     0,    36,    37,     0,     9,    10,     5,
       0,    46,    69,    49,     0,    52,    75,    55,    33,    32,
      31,     0,     0,     0,    95,    43,    41,     0,    42,    28,
      15,    23,    25,     0,     0,     0,     0,     0,     0,     0,
       0,    14,   100,    97,    40,    85,    86,     0,    80,    83,
      84,    47,     0,    50,    72,    53,     0,    56,     0,     0,
      60,    78,    81,    87,     0,     0,     0,     0,   101,    98,
       0,     0,     0,     0,    70,     0,    77,    76,     0,    79,
      82,    88,     0,    90,     0,     0,     0,     0,     0,    73,
       0,     0,     0,     0,    91,     0,    61,     0,     0,     0,
      89,     0,    68,    71,    92,    93,     0,     0,    62,    66,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
      67,    94,    63,     0,     0,     0,    64,    68,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,   -11,  -134,  -134,  -134,  -134,  -134,    99,    -9,
    -134,   138,   104,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,   -23,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -133,  -100,  -134,    50,  -134,    51,
    -134,  -134,  -134,  -134,  -134,   140,    14,  -134,  -134,  -134,
    -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    36,    16,    17,
      18,    19,    20,    50,    71,    53,    56,    21,    22,    77,
      23,    24,    84,    25,    86,    26,    88,    27,    90,    61,
     120,   152,   158,   173,   177,   159,    63,    85,   132,    65,
     115,   145,    67,    89,   117,    97,   121,    98,   122,    99,
     100,   123,   135,   143,   144,    28,    39,    73,   109,    72,
     108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    46,   114,   140,    41,     4,   162,    37,   147,    38,
      40,    45,    59,     2,     3,     4,     5,   -48,   -51,   -45,
      44,   -54,    47,   161,   133,     6,     7,     8,   163,     9,
     167,    76,    57,   134,    -6,    75,    41,     4,     5,     9,
      43,   175,    -6,    45,    58,     2,     3,     4,     5,   -48,
     -51,   -45,   110,   -54,    48,    49,   111,     6,     7,     8,
     124,     9,    51,    52,   111,    60,   169,     2,    41,     4,
       5,     9,    62,     1,    -6,     2,     3,     4,     5,   -48,
     -51,   -45,   172,   -54,    29,    30,   111,     6,     7,     8,
      31,    29,    30,     9,    54,    55,    -6,    31,    64,    95,
      96,     9,    66,    32,    33,   126,   -13,   -13,  -103,    34,
      32,    35,    68,    69,   131,  -102,    34,    80,    35,   148,
     149,   -13,   118,   119,   104,    92,    74,    70,    79,    83,
      87,   101,    94,    93,   102,   103,   125,   105,   106,   107,
     113,   112,   116,   127,   128,   137,   136,   139,   142,   154,
     155,   151,   138,   164,   178,   171,   141,   150,   146,   157,
      82,   153,   156,   166,   165,   170,   160,   174,   168,   176,
      91,   129,     0,   130,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81
};

static const yytype_int16 yycheck[] =
{
       9,    12,   102,   136,     4,     5,     9,     3,   141,     5,
      29,     1,    23,     3,     4,     5,     6,     7,     8,     9,
      24,    11,    23,   156,     4,    15,    16,    17,    31,    29,
     163,    40,    23,    13,    24,     3,     4,     5,     6,    29,
       0,   174,    32,     1,    23,     3,     4,     5,     6,     7,
       8,     9,    30,    11,    20,    21,    34,    15,    16,    17,
      30,    29,    25,    26,    34,     9,   166,     3,     4,     5,
       6,    29,     7,     1,    32,     3,     4,     5,     6,     7,
       8,     9,    30,    11,     4,     5,    34,    15,    16,    17,
      10,     4,     5,    29,    27,    28,    24,    10,     8,     4,
       5,    29,    11,    23,    24,   116,    18,    19,    30,    29,
      23,    31,    18,    19,   123,    30,    29,     4,    31,    36,
      37,    33,   108,   109,     4,    36,    30,    33,    30,    29,
      29,    23,    30,    36,    29,    23,    12,    23,    31,    23,
      22,    35,    23,    32,    23,    23,    31,    30,     5,     5,
       5,    23,    29,    14,   177,     5,    31,    30,    32,    10,
      56,    32,    31,    29,    32,    32,    36,    31,    33,    32,
      71,   121,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    15,    16,    17,    29,
      39,    40,    41,    42,    43,    44,    46,    47,    48,    49,
      50,    55,    56,    58,    59,    61,    63,    65,    93,     4,
       5,    10,    23,    24,    29,    31,    45,     3,     5,    94,
      29,     4,    47,     0,    24,     1,    40,    23,    20,    21,
      51,    25,    26,    53,    27,    28,    54,    23,    23,    40,
       9,    67,     7,    74,     8,    77,    11,    80,    18,    19,
      33,    52,    97,    95,    30,     3,    47,    57,    93,    30,
       4,    49,    50,    29,    60,    75,    62,    29,    64,    81,
      66,    46,    36,    36,    30,     4,     5,    83,    85,    87,
      88,    23,    29,    23,     4,    23,    31,    23,    98,    96,
      30,    34,    35,    22,    83,    78,    23,    82,    94,    94,
      68,    84,    86,    89,    30,    12,    40,    32,    23,    85,
      87,    47,    76,     4,    13,    90,    31,    23,    29,    30,
      82,    31,     5,    91,    92,    79,    32,    82,    36,    37,
      30,    23,    69,    32,     5,     5,    31,    10,    70,    73,
      36,    82,     9,    31,    14,    32,    29,    82,    33,    83,
      32,     5,    30,    71,    31,    82,    32,    72,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    40,    41,    42,    42,
      42,    43,    43,    45,    44,    44,    44,    44,    46,    46,
      46,    47,    48,    48,    49,    49,    50,    50,    50,    51,
      51,    52,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    57,    57,    57,    57,    59,    60,    58,    61,    62,
      58,    63,    64,    58,    65,    66,    58,    58,    58,    58,
      68,    69,    67,    71,    72,    70,    70,    73,    73,    75,
      76,    74,    78,    79,    77,    81,    80,    82,    84,    83,
      83,    86,    85,    85,    87,    88,    88,    89,    88,    90,
      90,    91,    91,    91,    92,    93,    95,    96,    94,    97,
      98,    94,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     0,     1,     1,     2,
       2,     2,     2,     0,     4,     3,     2,     2,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     0,     0,     0,     4,     0,     0,
       4,     0,     0,     4,     0,     0,     4,     2,     2,     2,
       0,     0,    11,     0,     0,    11,     1,     4,     0,     0,
       0,    10,     0,     0,    12,     0,     5,     2,     0,     4,
       1,     0,     4,     1,     1,     1,     1,     0,     4,     4,
       1,     1,     3,     3,     7,     3,     0,     0,     5,     0,
       0,     5,     1,     1
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
#line 75 "pryacc.y" /* yacc.c:1646  */
    {isLoop=0;if(success_flag == 1) {printf("\n\n\nSyntax is perfect\n\n");return 0;} else {printf("\n\n\nIncorrect Syntax\n\n");return 0;};}
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "pryacc.y" /* yacc.c:1646  */
    {printf("\n\n\nLine number %d :- Incorrect Syntax\n\n",lineno); exit(0);}
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "pryacc.y" /* yacc.c:1646  */
    {yyclearin;}
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "pryacc.y" /* yacc.c:1646  */
    {push(id);}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 93 "pryacc.y" /* yacc.c:1646  */
    {success_flag = 0; printf("\n\nLine number %d :- Incorrect Assignment\n\n",lineno);}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 94 "pryacc.y" /* yacc.c:1646  */
    {success_flag = 0; printf("\n\nLine number %d :- Incorrect Assignment\n\n",lineno);}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "pryacc.y" /* yacc.c:1646  */
    {codegen_assign(isLoop);insert_to_symbol_table_value((void *)((yyval)), inttype);}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "pryacc.y" /* yacc.c:1646  */
    {push(strval);codegen_assign(isLoop);insert_to_symbol_table_value((void *)(strval), strtype);}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 99 "pryacc.y" /* yacc.c:1646  */
    {vector_assign(isLoop);}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 102 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);printf("expr1= %d\n",(yyval));}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 105 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);printf("expr2= %d\n",(yyval));}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "pryacc.y" /* yacc.c:1646  */
    {if((yyvsp[-1])==1) {codegen(isLoop);(yyval)=(yyvsp[-2])+(yyvsp[0]);printf("expr2 in %d plus %d = %d\n",(yyvsp[-2]),(yyvsp[0]),(yyval));} if((yyvsp[-1])==2){codegen(isLoop);(yyval)=(yyvsp[-2])-(yyvsp[0]);printf("expr2 in minus= %d\n",(yyval));}}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 109 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "pryacc.y" /* yacc.c:1646  */
    {if((yyvsp[-1])==3) {codegen(isLoop);(yyval)=(yyvsp[-2])*(yyvsp[0]);} if((yyvsp[-1])==4){codegen(isLoop);if((yyvsp[0])==0){return 0;} else { (yyval)= (yyvsp[-2])/(yyvsp[0]);}}}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 113 "pryacc.y" /* yacc.c:1646  */
    {push(id); printf("#####\nin expr 4 %s\n#####",id);}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 114 "pryacc.y" /* yacc.c:1646  */
    {push(val); printf("Debug1\n"); char* newval = (char *)malloc(sizeof(char)*100); strcpy(newval,val); (yyval)=atoi(newval);{printf("#####\nin expr4 num %s yayyy newval=%s yayy $$=%d\n#####",val,newval,(yyval));}}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 115 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "pryacc.y" /* yacc.c:1646  */
    {push("->");}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 120 "pryacc.y" /* yacc.c:1646  */
    {push("->>");}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 122 "pryacc.y" /* yacc.c:1646  */
    {push("=");}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 123 "pryacc.y" /* yacc.c:1646  */
    {push("<-");}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 124 "pryacc.y" /* yacc.c:1646  */
    {push("<<-");}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 127 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=1;push("+");}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 128 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=2;push("-");}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 131 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=3;push("*");}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 132 "pryacc.y" /* yacc.c:1646  */
    {(yyval)=4;push("/");}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 136 "pryacc.y" /* yacc.c:1646  */
    {check_break(isLoop);}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 146 "pryacc.y" /* yacc.c:1646  */
    {isLoop=1;}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 146 "pryacc.y" /* yacc.c:1646  */
    {isLoop=0;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 147 "pryacc.y" /* yacc.c:1646  */
    {isLoop=1;}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 147 "pryacc.y" /* yacc.c:1646  */
    {isLoop=0;}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 148 "pryacc.y" /* yacc.c:1646  */
    {isLoop=1;}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 148 "pryacc.y" /* yacc.c:1646  */
    {isLoop=0;}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 149 "pryacc.y" /* yacc.c:1646  */
    {isLoop=1;}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 149 "pryacc.y" /* yacc.c:1646  */
    {isLoop=0;}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 150 "pryacc.y" /* yacc.c:1646  */
    {success_flag = 0; printf("\n\nLine number %d :- Loop keyword misspelt\n\n",lineno); yyclearin;}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 151 "pryacc.y" /* yacc.c:1646  */
    {success_flag = 0; printf("\n\nLine number %d :- Loop syntax incorrect.....Please check documentation\n\n",lineno);}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 152 "pryacc.y" /* yacc.c:1646  */
    {printf("\n\nLine number %d :- Loop syntax incorrect.....Bracket Misplaced\n\n",lineno);}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 155 "pryacc.y" /* yacc.c:1646  */
    {if_lab1(isLoop);}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 155 "pryacc.y" /* yacc.c:1646  */
    {if_lab2(isLoop);}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 157 "pryacc.y" /* yacc.c:1646  */
    {if_lab1(isLoop);}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 157 "pryacc.y" /* yacc.c:1646  */
    {if_lab2(isLoop);}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 160 "pryacc.y" /* yacc.c:1646  */
    {if_lab3(isLoop);}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 163 "pryacc.y" /* yacc.c:1646  */
    {while_lab1(isLoop);}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 163 "pryacc.y" /* yacc.c:1646  */
    {while_lab2(isLoop);}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 163 "pryacc.y" /* yacc.c:1646  */
    {while_lab3(isLoop);}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 165 "pryacc.y" /* yacc.c:1646  */
    {push(id); push(id);}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 165 "pryacc.y" /* yacc.c:1646  */
    {for_lab2(isLoop); push(id); push("="); push(id); push("+"); push("1"); codegen(isLoop); codegen_assign(isLoop);}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 165 "pryacc.y" /* yacc.c:1646  */
    {for_lab3(isLoop);}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 167 "pryacc.y" /* yacc.c:1646  */
    {repeat_lab1(isLoop);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 167 "pryacc.y" /* yacc.c:1646  */
    {repeat_lab2(isLoop);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 171 "pryacc.y" /* yacc.c:1646  */
    {push("|");}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 171 "pryacc.y" /* yacc.c:1646  */
    {codegen(isLoop);}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 174 "pryacc.y" /* yacc.c:1646  */
    {push("&");}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 174 "pryacc.y" /* yacc.c:1646  */
    {codegen(isLoop);}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 179 "pryacc.y" /* yacc.c:1646  */
    {push(id);}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 180 "pryacc.y" /* yacc.c:1646  */
    {push(val);}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 181 "pryacc.y" /* yacc.c:1646  */
    {push(relop);}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 181 "pryacc.y" /* yacc.c:1646  */
    {codegen(isLoop);}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 188 "pryacc.y" /* yacc.c:1646  */
    {push("="); push("1"); codegen_assign(isLoop); for_lab1(isLoop); push("<"); push(val); codegen(isLoop);}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 193 "pryacc.y" /* yacc.c:1646  */
    {push_vector(")");insert_to_symbol_table_vector_value("done", vector_end_type);}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 195 "pryacc.y" /* yacc.c:1646  */
    {push_vector(val);char* newval = (char *)malloc(sizeof(char)*100); strcpy(newval,val); insert_to_symbol_table_vector_value((void *)(newval), inttype);}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 195 "pryacc.y" /* yacc.c:1646  */
    {push_vector(","); }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 196 "pryacc.y" /* yacc.c:1646  */
    {push_vector(strval);insert_to_symbol_table_vector_value((void *)(strval), strtype);}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 196 "pryacc.y" /* yacc.c:1646  */
    {push_vector(","); }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 197 "pryacc.y" /* yacc.c:1646  */
    {push_vector(val);char* newval = (char *)malloc(sizeof(char)*100); strcpy(newval,val); insert_to_symbol_table_vector_value((void *)(newval), inttype);}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 198 "pryacc.y" /* yacc.c:1646  */
    {push_vector(strval);insert_to_symbol_table_vector_value((void *)(strval), strtype);}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1816 "y.tab.c" /* yacc.c:1646  */
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
#line 200 "pryacc.y" /* yacc.c:1906  */


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

