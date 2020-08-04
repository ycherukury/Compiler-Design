/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
