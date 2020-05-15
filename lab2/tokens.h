/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BY = 258,
     CHAR = 259,
     CHARCONST = 260,
     COLON = 261,
     COMMA = 262,
     DIVIDE = 263,
     ELSE = 264,
     ENDOFFILE = 265,
     EQUALS = 266,
     FOR = 267,
     IF = 268,
     INT = 269,
     LBRACKET = 270,
     LPAREN = 271,
     LSQUARE = 272,
     MINUS = 273,
     NAME = 274,
     ELE = 275,
     NOT = 276,
     NUMBER = 277,
     PLUS = 278,
     PROCEDURE = 279,
     RBRACKET = 280,
     READ = 281,
     RPAREN = 282,
     RSQUARE = 283,
     SEMICOLON = 284,
     THEN = 285,
     TIMES = 286,
     TO = 287,
     WHILE = 288,
     WRITE = 289,
     UNKNOWN = 290,
     LT = 291,
     LE = 292,
     EQ = 293,
     NE = 294,
     GE = 295,
     GT = 296,
     AND = 297,
     OR = 298
   };
#endif
/* Tokens.  */
#define BY 258
#define CHAR 259
#define CHARCONST 260
#define COLON 261
#define COMMA 262
#define DIVIDE 263
#define ELSE 264
#define ENDOFFILE 265
#define EQUALS 266
#define FOR 267
#define IF 268
#define INT 269
#define LBRACKET 270
#define LPAREN 271
#define LSQUARE 272
#define MINUS 273
#define NAME 274
#define ELE 275
#define NOT 276
#define NUMBER 277
#define PLUS 278
#define PROCEDURE 279
#define RBRACKET 280
#define READ 281
#define RPAREN 282
#define RSQUARE 283
#define SEMICOLON 284
#define THEN 285
#define TIMES 286
#define TO 287
#define WHILE 288
#define WRITE 289
#define UNKNOWN 290
#define LT 291
#define LE 292
#define EQ 293
#define NE 294
#define GE 295
#define GT 296
#define AND 297
#define OR 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "DEMOgram.y"
{
  unsigned long int val;
  char             *cptr;
  struct NODE     *nodeptr;
  struct BP        *bp;
  struct LOOP      *loop;
  struct LOOPEXPR  *loopex;
  struct ITEHEAD   *ite;
}
/* Line 1529 of yacc.c.  */
#line 145 "DEMOgram.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

