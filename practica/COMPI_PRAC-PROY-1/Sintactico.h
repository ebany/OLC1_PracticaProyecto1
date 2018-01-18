/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_YY_SINTACTICO_H_INCLUDED
# define YY_YY_SINTACTICO_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tknPublic = 258,
     tknPrivate = 259,
     tknProtected = 260,
     tknClass = 261,
     tknInt = 262,
     tknString = 263,
     tknBoolean = 264,
     tknDouble = 265,
     tknChar = 266,
     tknNew = 267,
     tknIgual = 268,
     tknParA = 269,
     tknParC = 270,
     tknLlaveA = 271,
     tknLlaveC = 272,
     tknComa = 273,
     tknPtoComa = 274,
     tknVoid = 275,
     tknOverride = 276,
     tknThis = 277,
     tknIf = 278,
     tknElse = 279,
     tknSwitch = 280,
     tknCase = 281,
     tknDosPts = 282,
     tknBreak = 283,
     tknDefault = 284,
     tknWhile = 285,
     tknDo = 286,
     tknFor = 287,
     tknContinue = 288,
     tknNull = 289,
     tknPto = 290,
     tknMeMe = 291,
     tknMaMa = 292,
     tknAnd = 293,
     tknOr = 294,
     tknNot = 295,
     tknMenor = 296,
     tknMayor = 297,
     tknMenorQ = 298,
     tknMayorQ = 299,
     tknIgualIgual = 300,
     tknDiferente = 301,
     tknMas = 302,
     tknMenos = 303,
     tknPor = 304,
     tknDiv = 305,
     tknReturn = 306,
     tknExtends = 307,
     tknNumero = 308,
     tknId = 309,
     tknCadena = 310,
     tknCaracter = 311
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 86 "Sintactico.y"
	
	char cadena[256];
	struct Nodo* NODO;


/* Line 2058 of yacc.c  */
#line 119 "Sintactico.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SINTACTICO_H_INCLUDED  */
