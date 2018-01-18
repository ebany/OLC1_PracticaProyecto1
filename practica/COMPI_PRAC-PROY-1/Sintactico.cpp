/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Sintactico.y"

#include <iostream>
#include <QMessageBox>
#include <QList>
#include "Lexico.h"
#include "_Nodo.h"
#include "NodoLex.h"

using namespace std;

extern int yylineno;
extern char *yytext;
extern int yyfila;
extern int yycolumna;

QList<ErrLex *> erroresS;

//general
QList<InfoCls*> clases;

//temporal
QList<Gnrc*> metodos;
QList<Gnrc*> funciones;
QList<Gnrc*> atributos;
QList<Gnrc*> constructores;
QList<Gnrc*> overrides;

//global
Gnrc* varGlobal;

QList<InfoCls*> getClases(){
	return clases;
}

void limpiarClss(){
	metodos.clear();
	funciones.clear();
	atributos.clear();
	constructores.clear();
	overrides.clear();
}

void limpiarGeneral(){
	limpiarClss();
	clases.clear();
}

Nodo *raiz = NULL;

void reiniciar(){
	yyfila=1;
	yycolumna=0;
}

Nodo *GetRaiz(){
	return raiz;
}

void NullRaiz(){
	raiz = NULL;
}

QList<ErrLex *> lstErrores(){
	return erroresS;
}

void limpiarErrores(){
	erroresS.clear();
}

int yyerror(const char *error){	 	
	/*yycolumna =0;
	cout<<"\n\nError Sintactico:\n"<<error<<"\n\n"<<yyfila<<"--"<<yycolumna<<endl;*/
	raiz = NULL;

	ErrLex* nuevo = new ErrLex(error,yycolumna,yyfila);
	erroresS.append(nuevo);

	return 0;
}


/* Line 371 of yacc.c  */
#line 151 "Sintactico.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Sintactico.h".  */
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
/* Line 387 of yacc.c  */
#line 86 "Sintactico.y"
	
	char cadena[256];
	struct Nodo* NODO;


/* Line 387 of yacc.c  */
#line 256 "Sintactico.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 284 "Sintactico.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  295
/* YYNRULES -- Number of states.  */
#define YYNSTATES  729

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    18,    25,    32,    40,
      42,    44,    46,    49,    51,    52,    55,    57,    59,    61,
      63,    68,    72,    74,    76,    78,    80,    82,    84,    88,
      90,    94,    96,   100,   104,   106,   108,   114,   116,   118,
     122,   124,   126,   128,   133,   136,   139,   141,   143,   145,
     147,   155,   163,   171,   180,   189,   198,   207,   216,   225,
     229,   232,   234,   236,   240,   244,   248,   250,   253,   257,
     259,   262,   265,   268,   271,   274,   276,   278,   282,   286,
     290,   294,   298,   302,   306,   309,   313,   316,   318,   321,
     323,   325,   327,   329,   331,   333,   337,   341,   345,   349,
     353,   355,   357,   359,   361,   363,   368,   370,   379,   388,
     397,   400,   402,   405,   407,   416,   425,   434,   439,   441,
     446,   454,   462,   470,   477,   484,   491,   494,   496,   502,
     508,   514,   517,   525,   533,   541,   551,   561,   571,   581,
     583,   585,   589,   591,   602,   613,   624,   627,   629,   631,
     633,   635,   637,   639,   642,   644,   646,   648,   652,   656,
     660,   663,   666,   668,   670,   672,   674,   676,   679,   681,
     683,   685,   687,   691,   694,   697,   700,   703,   707,   710,
     719,   728,   737,   740,   742,   745,   747,   756,   765,   774,
     779,   784,   786,   794,   802,   810,   817,   824,   831,   834,
     836,   842,   848,   854,   857,   866,   875,   884,   887,   889,
     892,   894,   903,   912,   921,   926,   931,   933,   941,   949,
     957,   964,   971,   978,   981,   983,   989,   995,  1001,  1004,
    1012,  1020,  1028,  1038,  1048,  1058,  1068,  1079,  1090,  1101,
    1104,  1106,  1108,  1110,  1112,  1114,  1116,  1119,  1121,  1123,
    1125,  1128,  1131,  1134,  1137,  1139,  1141,  1143,  1145,  1147,
    1149,  1151,  1154,  1156,  1158,  1161,  1164,  1167,  1170,  1173,
    1176,  1179,  1188,  1197,  1206,  1209,  1211,  1214,  1216,  1225,
    1234,  1243,  1248,  1253,  1255,  1263,  1271,  1279,  1286,  1293,
    1300,  1303,  1305,  1311,  1317,  1323
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    59,    60,    -1,    60,    -1,
      61,     6,    54,    62,    16,    64,    17,    -1,     6,    54,
      62,    16,    64,    17,    -1,     1,    54,    62,    16,    64,
      17,    -1,    61,     1,    54,    62,    16,    64,    17,    -1,
       3,    -1,     4,    -1,     5,    -1,    52,    54,    -1,    63,
      -1,    -1,    64,    65,    -1,    65,    -1,    75,    -1,    66,
      -1,    80,    -1,    61,    67,    68,    69,    -1,    67,    68,
      69,    -1,    54,    -1,     8,    -1,     9,    -1,    10,    -1,
      11,    -1,     7,    -1,    68,    18,    54,    -1,    54,    -1,
      13,    70,    19,    -1,    19,    -1,    13,     1,    19,    -1,
      13,    70,     1,    -1,     1,    -1,    91,    -1,    12,    54,
      14,    71,    15,    -1,    72,    -1,    63,    -1,    72,    18,
      91,    -1,    91,    -1,    74,    -1,    63,    -1,    74,    18,
      67,    54,    -1,    67,    54,    -1,    61,    76,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    54,    14,    73,
      15,    16,   136,    17,    -1,    54,    14,    73,    15,    16,
       1,    17,    -1,    54,    14,     1,    15,    16,   136,    17,
      -1,    67,    54,    14,    73,    15,    16,   109,    17,    -1,
      67,    54,    14,     1,    15,    16,   109,    17,    -1,    67,
      54,    14,    73,    15,    16,     1,    17,    -1,    20,    54,
      14,    73,    15,    16,   136,    17,    -1,    20,    54,    14,
       1,    15,    16,   136,    17,    -1,    20,    54,    14,    73,
      15,    16,     1,    17,    -1,    21,    61,    81,    -1,    21,
      81,    -1,    78,    -1,    79,    -1,    22,    35,    83,    -1,
      54,    35,    83,    -1,    83,    35,    54,    -1,    54,    -1,
      82,    85,    -1,    14,    71,    15,    -1,    63,    -1,    54,
      69,    -1,    82,    69,    -1,     1,    69,    -1,    54,    88,
      -1,    82,    88,    -1,    37,    -1,    36,    -1,    14,    71,
      15,    -1,    54,    89,    19,    -1,    82,    89,    19,    -1,
      82,    89,     1,    -1,    54,    89,     1,    -1,    91,    38,
      91,    -1,    91,    39,    91,    -1,    40,    91,    -1,    93,
      92,    93,    -1,    48,    93,    -1,    93,    -1,    93,    91,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    46,    -1,    93,    47,    93,    -1,    93,    48,    93,
      -1,    93,    49,    93,    -1,    93,    50,    93,    -1,    14,
      91,    15,    -1,    53,    -1,    55,    -1,    56,    -1,    54,
      -1,    84,    -1,    54,    14,    71,    15,    -1,    34,    -1,
      23,    14,    91,    15,    16,   109,    17,    95,    -1,    23,
      14,    91,    15,    16,     1,    17,    95,    -1,    23,    14,
       1,    15,    16,   109,    17,    95,    -1,    96,    98,    -1,
      98,    -1,    96,    97,    -1,    97,    -1,    24,    23,    14,
      91,    15,    16,   109,    17,    -1,    24,    23,    14,     1,
      15,    16,   109,    17,    -1,    24,    23,    14,    91,    15,
      16,     1,    17,    -1,    24,    16,   109,    17,    -1,    63,
      -1,    24,    16,     1,    17,    -1,    25,    14,    91,    15,
      16,   103,    17,    -1,    25,    14,    91,    15,    16,     1,
      17,    -1,    25,    14,     1,    15,    16,   103,    17,    -1,
      26,    93,    27,   109,    28,    19,    -1,    26,    93,    27,
       1,    28,    19,    -1,    26,    93,    27,   109,    28,     1,
      -1,   101,   100,    -1,   100,    -1,    29,    27,   109,    28,
      19,    -1,    29,    27,     1,    28,    19,    -1,    29,    27,
     109,    28,     1,    -1,   101,   102,    -1,    30,    14,    91,
      15,    16,   111,    17,    -1,    30,    14,    91,    15,    16,
       1,    17,    -1,    30,    14,     1,    15,    16,   111,    17,
      -1,    31,    16,   111,    17,    30,    14,    91,    15,    19,
      -1,    31,    16,   111,    17,    30,    14,     1,    15,    19,
      -1,    31,    16,     1,    17,    30,    14,    91,    15,    19,
      -1,    31,    16,   111,    17,    30,    14,    91,    15,     1,
      -1,    66,    -1,    86,    -1,    54,    13,    70,    -1,    87,
      -1,    32,    14,   106,    91,    19,   107,    15,    16,   111,
      17,    -1,    32,    14,   106,    91,    19,   107,    15,    16,
       1,    17,    -1,    32,    14,   106,    91,     1,   107,    15,
      16,   109,    17,    -1,   109,   110,    -1,   110,    -1,    66,
      -1,    90,    -1,    94,    -1,    99,    -1,   104,    -1,    87,
      19,    -1,   105,    -1,   108,    -1,    86,    -1,    51,    91,
      19,    -1,    51,     1,    19,    -1,    51,    91,     1,    -1,
      87,     1,    -1,   111,   112,    -1,   112,    -1,    66,    -1,
      90,    -1,   113,    -1,   118,    -1,    87,    19,    -1,   104,
      -1,   105,    -1,   108,    -1,    86,    -1,    51,    91,    19,
      -1,    28,    19,    -1,    33,    19,    -1,    33,     1,    -1,
      28,     1,    -1,    51,    91,     1,    -1,    87,     1,    -1,
      23,    14,    91,    15,    16,   111,    17,   114,    -1,    23,
      14,    91,    15,    16,     1,    17,   114,    -1,    23,    14,
       1,    15,    16,   111,    17,   114,    -1,   115,   117,    -1,
     117,    -1,   115,   116,    -1,   116,    -1,    24,    23,    14,
      91,    15,    16,   111,    17,    -1,    24,    23,    14,    91,
      15,    16,     1,    17,    -1,    24,    23,    14,     1,    15,
      16,   111,    17,    -1,    24,    16,   111,    17,    -1,    24,
      16,     1,    17,    -1,    63,    -1,    25,    14,    91,    15,
      16,   122,    17,    -1,    25,    14,    91,    15,    16,     1,
      17,    -1,    25,    14,     1,    15,    16,   122,    17,    -1,
      26,    93,    27,   111,    28,    19,    -1,    26,    93,    27,
       1,    28,    19,    -1,    26,    93,    27,   111,    28,     1,
      -1,   120,   119,    -1,   119,    -1,    29,    27,   111,    28,
      19,    -1,    29,    27,     1,    28,    19,    -1,    29,    27,
     111,    28,     1,    -1,   120,   121,    -1,    23,    14,    91,
      15,    16,   136,    17,   124,    -1,    23,    14,    91,    15,
      16,     1,    17,   124,    -1,    23,    14,     1,    15,    16,
     136,    17,   124,    -1,   125,   127,    -1,   127,    -1,   125,
     126,    -1,   126,    -1,    24,    23,    14,    91,    15,    16,
     136,    17,    -1,    24,    23,    14,    91,    15,    16,     1,
      17,    -1,    24,    23,    14,     1,    15,    16,   136,    17,
      -1,    24,    16,   136,    17,    -1,    24,    16,     1,    17,
      -1,    63,    -1,    25,    14,    91,    15,    16,   132,    17,
      -1,    25,    14,    91,    15,    16,     1,    17,    -1,    25,
      14,     1,    15,    16,   132,    17,    -1,    26,    93,    27,
     136,    28,    19,    -1,    26,    93,    27,     1,    28,    19,
      -1,    26,    93,    27,   136,    28,     1,    -1,   130,   129,
      -1,   129,    -1,    29,    27,   136,    28,    19,    -1,    29,
      27,     1,    28,    19,    -1,    29,    27,   136,    28,     1,
      -1,   130,   131,    -1,    30,    14,    91,    15,    16,   138,
      17,    -1,    30,    14,    91,    15,    16,     1,    17,    -1,
      30,    14,     1,    15,    16,   138,    17,    -1,    31,    16,
     138,    17,    30,    14,    91,    15,    19,    -1,    31,    16,
     138,    17,    30,    14,     1,    15,    19,    -1,    31,    16,
       1,    17,    30,    14,    91,    15,    19,    -1,    31,    16,
     138,    17,    30,    14,    91,    15,     1,    -1,    32,    14,
     106,    91,    19,   107,    15,    16,   138,    17,    -1,    32,
      14,   106,    91,    19,   107,    15,    16,     1,    17,    -1,
      32,    14,   106,    91,     1,   107,    15,    16,   138,    17,
      -1,   136,   137,    -1,   137,    -1,    66,    -1,    90,    -1,
     123,    -1,   128,    -1,   133,    -1,    87,    19,    -1,   134,
      -1,   135,    -1,    86,    -1,    51,    19,    -1,    87,     1,
      -1,    51,     1,    -1,   138,   139,    -1,   139,    -1,    66,
      -1,    90,    -1,   140,    -1,   145,    -1,   133,    -1,   134,
      -1,    87,    19,    -1,   135,    -1,    86,    -1,    51,    19,
      -1,    28,    19,    -1,    33,    19,    -1,    87,     1,    -1,
      51,     1,    -1,    28,     1,    -1,    33,     1,    -1,    23,
      14,    91,    15,    16,   138,    17,   141,    -1,    23,    14,
      91,    15,    16,     1,    17,   141,    -1,    23,    14,     1,
      15,    16,   138,    17,   141,    -1,   142,   144,    -1,   144,
      -1,   142,   143,    -1,   143,    -1,    24,    23,    14,    91,
      15,    16,   138,    17,    -1,    24,    23,    14,    91,    15,
      16,     1,    17,    -1,    24,    23,    14,     1,    15,    16,
     138,    17,    -1,    24,    16,   138,    17,    -1,    24,    16,
       1,    17,    -1,    63,    -1,    25,    14,    91,    15,    16,
     149,    17,    -1,    25,    14,    91,    15,    16,     1,    17,
      -1,    25,    14,     1,    15,    16,   149,    17,    -1,    26,
      93,    27,   138,    28,    19,    -1,    26,    93,    27,     1,
      28,    19,    -1,    26,    93,    27,   138,    28,     1,    -1,
     147,   146,    -1,   146,    -1,    29,    27,   138,    28,    19,
      -1,    29,    27,     1,    28,    19,    -1,    29,    27,   138,
      28,     1,    -1,   147,   148,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   252,   252,   259,   264,   271,   291,   311,   316,   323,
     328,   333,   340,   349,   356,   360,   365,   372,   385,   433,
     442,   451,   461,   466,   472,   478,   484,   490,   497,   507,
     516,   521,   526,   531,   536,   543,   548,   555,   560,   567,
     572,   579,   583,   590,   599,   609,   677,   741,   745,   749,
     755,   772,   777,   784,   802,   807,   814,   833,   838,   845,
     882,   915,   920,   927,   932,   939,   944,   951,   958,   963,
     970,   975,   980,   987,   992,   999,  1004,  1011,  1018,  1023,
    1028,  1033,  1041,  1046,  1051,  1056,  1061,  1066,  1071,  1078,
    1083,  1088,  1093,  1098,  1103,  1110,  1115,  1120,  1125,  1130,
    1135,  1140,  1145,  1150,  1155,  1160,  1165,  1177,  1182,  1187,
    1194,  1199,  1206,  1211,  1218,  1223,  1228,  1235,  1240,  1245,
    1252,  1257,  1262,  1269,  1274,  1279,  1286,  1291,  1298,  1303,
    1308,  1315,  1322,  1327,  1332,  1339,  1344,  1349,  1354,  1361,
    1366,  1373,  1378,  1385,  1390,  1395,  1402,  1407,  1414,  1419,
    1424,  1429,  1434,  1439,  1444,  1449,  1454,  1459,  1464,  1469,
    1474,  1482,  1487,  1494,  1499,  1504,  1509,  1514,  1519,  1524,
    1529,  1534,  1539,  1544,  1549,  1554,  1559,  1564,  1569,  1576,
    1581,  1586,  1593,  1598,  1605,  1610,  1617,  1622,  1627,  1634,
    1639,  1644,  1651,  1656,  1661,  1668,  1673,  1678,  1685,  1690,
    1697,  1702,  1707,  1714,  1725,  1730,  1735,  1742,  1747,  1754,
    1759,  1766,  1771,  1776,  1783,  1788,  1793,  1800,  1805,  1810,
    1817,  1822,  1827,  1834,  1839,  1846,  1851,  1856,  1863,  1870,
    1875,  1880,  1887,  1892,  1897,  1902,  1909,  1914,  1919,  1926,
    1931,  1938,  1943,  1948,  1953,  1958,  1963,  1968,  1973,  1978,
    1983,  1988,  1993,  2001,  2006,  2013,  2018,  2023,  2028,  2033,
    2038,  2043,  2048,  2053,  2058,  2063,  2068,  2073,  2078,  2083,
    2088,  2098,  2103,  2108,  2115,  2120,  2127,  2132,  2139,  2144,
    2149,  2156,  2161,  2166,  2173,  2178,  2183,  2190,  2195,  2200,
    2207,  2212,  2219,  2224,  2229,  2236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tknPublic", "tknPrivate",
  "tknProtected", "tknClass", "tknInt", "tknString", "tknBoolean",
  "tknDouble", "tknChar", "tknNew", "tknIgual", "tknParA", "tknParC",
  "tknLlaveA", "tknLlaveC", "tknComa", "tknPtoComa", "tknVoid",
  "tknOverride", "tknThis", "tknIf", "tknElse", "tknSwitch", "tknCase",
  "tknDosPts", "tknBreak", "tknDefault", "tknWhile", "tknDo", "tknFor",
  "tknContinue", "tknNull", "tknPto", "tknMeMe", "tknMaMa", "tknAnd",
  "tknOr", "tknNot", "tknMenor", "tknMayor", "tknMenorQ", "tknMayorQ",
  "tknIgualIgual", "tknDiferente", "tknMas", "tknMenos", "tknPor",
  "tknDiv", "tknReturn", "tknExtends", "tknNumero", "tknId", "tknCadena",
  "tknCaracter", "$accept", "S", "CLS", "CL", "AUX_A", "EXT", "EPS",
  "LST_CUERPO_CL", "CUERPO_CL", "DECL", "TIPO", "LST_ID", "DEC_ASIGN",
  "OPC_EXP", "PARAMETROS_1", "LST_PARAM", "PARAMETROS_2", "LST_PARAM_2",
  "CAJAS", "OPC_CAJAS", "CONSTRUCTOR", "FUNC", "MET", "SOBRESC",
  "OPC_SOBRESC", "PRE_OBJ", "LST_ACC", "ACC_OBJ", "OPC_ACC", "ASIGN",
  "INC_DEC", "OPC_INCDEC", "PRE_LLAMADA", "LLAMADA", "EXPRESION", "REL",
  "ART", "IFF", "OPC_IFF", "LST_IFF", "IF_ELSEF", "FIN_IFF", "SWITCHF",
  "CASEF", "LST_CASEF", "DEFAULTF", "CUERPO_SWITCHF", "WHILEF",
  "DO_WHILEF", "OPC_FOR1", "OPC_FOR2", "FORF", "PRE_CUERPOF", "CUERPO_F",
  "PRE_CUERPOFC", "CUERPO_CICLOF", "IFFC", "OPC_IFFC", "LST_IFFC",
  "IF_ELSEFC", "FIN_IFFC", "SWITCHFC", "CASEFC", "LST_CASEFC", "DEFAULTFC",
  "CUERPO_SWITCHFC", "IFM", "OPC_IFM", "LST_IFM", "IF_ELSEM", "FIN_IFM",
  "SWITCHM", "CASEM", "LST_CASEM", "DEFAULTM", "CUERPO_SWITCHM", "WHILEM",
  "DO_WHILEM", "FORM", "PRE_CUERPOM", "CUERPO_M", "PRE_CUERPOMC",
  "CUERPO_CICLOM", "IFMC", "OPC_IFMC", "LST_IFMC", "IF_ELSEMC", "FIN_IFMC",
  "SWITCHMC", "CASEMC", "LST_CASEMC", "DEFAULTMC", "CUERPO_SWITCHMC", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    61,
      61,    61,    62,    62,    63,    64,    64,    65,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    77,    78,    78,    78,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    85,    85,
      86,    86,    86,    87,    87,    88,    88,    89,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    98,    98,    98,
      99,    99,    99,   100,   100,   100,   101,   101,   102,   102,
     102,   103,   104,   104,   104,   105,   105,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   117,
     117,   117,   118,   118,   118,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   127,   127,   127,   128,   128,   128,
     129,   129,   129,   130,   130,   131,   131,   131,   132,   133,
     133,   133,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   138,   138,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   140,   140,   140,   141,   141,   142,   142,   143,   143,
     143,   144,   144,   144,   145,   145,   145,   146,   146,   146,
     147,   147,   148,   148,   148,   149
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     7,     6,     6,     7,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     3,     1,     1,     5,     1,     1,     3,
       1,     1,     1,     4,     2,     2,     1,     1,     1,     1,
       7,     7,     7,     8,     8,     8,     8,     8,     8,     3,
       2,     1,     1,     3,     3,     3,     1,     2,     3,     1,
       2,     2,     2,     2,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     4,     1,     8,     8,     8,
       2,     1,     2,     1,     8,     8,     8,     4,     1,     4,
       7,     7,     7,     6,     6,     6,     2,     1,     5,     5,
       5,     2,     7,     7,     7,     9,     9,     9,     9,     1,
       1,     3,     1,    10,    10,    10,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     2,     2,     2,     2,     3,     2,     8,
       8,     8,     2,     1,     2,     1,     8,     8,     8,     4,
       4,     1,     7,     7,     7,     6,     6,     6,     2,     1,
       5,     5,     5,     2,     8,     8,     8,     2,     1,     2,
       1,     8,     8,     8,     4,     4,     1,     7,     7,     7,
       6,     6,     6,     2,     1,     5,     5,     5,     2,     7,
       7,     7,     9,     9,     9,     9,    10,    10,    10,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     8,     8,     8,     2,     1,     2,     1,     8,     8,
       8,     4,     4,     1,     7,     7,     7,     6,     6,     6,
       2,     1,     5,     5,     5,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     9,    10,    11,     0,     0,     0,     4,     0,
      14,    14,     1,     3,     0,     0,     0,     0,    13,     0,
      14,    14,    12,     0,     0,     0,     0,    27,    23,    24,
      25,    26,     0,     0,    22,     0,     0,    16,    18,     0,
      17,    46,    47,    48,    49,    19,     0,     0,     0,     0,
      22,     0,     0,    61,    62,    60,     0,     0,    45,     7,
      15,    29,     0,     6,     0,     0,     0,    59,     0,     0,
      42,     0,     0,    41,     0,     0,    34,     0,     0,    31,
      21,     8,     5,     0,     0,     0,    44,     0,     0,    20,
       0,     0,     0,     0,     0,     0,   106,     0,     0,   100,
     103,   101,   102,     0,    14,   104,    35,    87,    28,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
      84,    86,    14,     0,    33,    30,    14,    69,    67,     0,
       0,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,     0,     0,   249,     0,   242,
     243,   244,   245,   247,   248,     0,   240,     0,     0,    43,
       0,     0,    14,    99,    66,    63,     0,    38,     0,    37,
      40,    64,     0,    82,    83,    95,    96,    97,    98,    85,
       0,     0,     0,    72,     0,     0,     0,     0,     0,   252,
     250,    14,    76,    75,    70,    73,     0,     0,    29,    71,
      74,     0,   251,   246,    52,   239,    51,    50,     0,     0,
       0,     0,     0,     0,   148,   156,     0,   149,   150,   151,
     152,   154,   155,     0,   147,     0,     0,     0,     0,    96,
     105,     0,    68,    57,    58,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   263,
       0,   256,   259,   260,   262,     0,   254,   257,   258,     0,
     139,     0,   140,     0,     0,    81,    78,    80,    79,     0,
       0,     0,     0,     0,     0,     0,   160,   153,    54,   146,
      55,    53,    36,    65,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,   265,   270,   266,   268,   264,
     267,   261,     0,   253,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   163,   171,
       0,   164,   168,   169,   170,     0,   162,   165,   166,     0,
     158,   159,   157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,   173,   175,   174,
       0,   178,   167,     0,   161,     0,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   172,     0,     0,     0,    14,    14,    14,     0,     0,
     223,   228,   219,   218,   217,   231,   230,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   216,
     206,    14,   210,   208,   205,   204,     0,     0,     0,     0,
       0,     0,     0,   291,     0,     0,     0,     0,     0,     0,
     141,     0,     0,    14,    14,    14,     0,     0,   126,   131,
     122,   121,   120,   134,   133,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   207,     0,
       0,     0,     0,   234,    14,    14,    14,     0,     0,   290,
     295,   286,   285,   284,   233,   235,   232,     0,     0,     0,
       0,   118,   109,    14,   113,   111,   108,   107,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,   273,    14,   277,   275,   272,   271,     0,
       0,   238,   237,   236,     0,     0,   112,   110,     0,     0,
       0,     0,   137,    14,    14,    14,     0,     0,   198,   203,
     194,   193,   192,   136,   138,   135,     0,     0,     0,   215,
     214,     0,     0,   221,   222,   220,   226,   227,   225,     0,
       0,   276,   274,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   181,    14,   185,   183,
     180,   179,     0,     0,   145,   144,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,   117,     0,     0,
     124,   125,   123,   129,   130,   128,     0,     0,   184,   182,
       0,     0,     0,     0,     0,     0,   282,   281,     0,     0,
     288,   269,   265,   293,   269,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   189,     0,     0,   196,   176,   173,   201,
     176,   173,   213,   212,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   114,     0,     0,
     280,   279,   278,     0,     0,     0,   188,   187,   186
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,   153,    17,    18,    36,    37,   258,
     155,    62,   193,   103,   178,   179,    72,    73,    40,    41,
      42,    43,    44,    45,    55,   156,   175,   105,   128,   259,
     260,   205,   206,   261,   180,   142,   107,   228,   532,   533,
     534,   535,   229,   442,   443,   489,   444,   332,   333,   273,
     397,   334,   233,   234,   335,   336,   337,   626,   627,   628,
     629,   338,   545,   546,   589,   547,   160,   460,   461,   462,
     463,   161,   380,   381,   421,   382,   262,   263,   264,   165,
     166,   265,   266,   267,   563,   564,   565,   566,   268,   473,
     474,   520,   475
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -317
static const yytype_int16 yypact[] =
{
     814,   -42,  -317,  -317,  -317,   -27,    31,  1536,  -317,   257,
       3,     3,  -317,  -317,    -7,    30,    49,   110,  -317,   114,
       3,     3,  -317,  4322,  4322,   124,   136,  -317,  -317,  -317,
    -317,  -317,   119,  1000,   183,   672,   844,  -317,  -317,   168,
    -317,  -317,  -317,  -317,  -317,  -317,  1464,  4322,  4322,   200,
    -317,   961,   208,  -317,  -317,  -317,   155,   168,  -317,  -317,
    -317,   217,   738,  -317,  1718,  4302,   242,  -317,   217,   249,
    -317,   231,   290,   273,   738,   707,  -317,   137,   246,  -317,
    -317,  -317,  -317,   304,   313,   295,  -317,   319,   218,  -317,
     326,   339,   350,   321,  4358,   323,  -317,  4358,   442,  -317,
      -5,  -317,  -317,     9,   368,  -317,   251,  4341,  -317,   370,
     376,  3808,  3841,   371,   385,   404,  -317,   421,    97,   386,
     251,   821,  4358,   386,  -317,  -317,  4358,  -317,  -317,  4358,
    4358,  -317,  -317,  -317,  -317,  -317,  -317,   442,   442,   442,
     442,   251,   442,  3808,  3874,   182,   434,   448,   455,   470,
     479,    50,   922,   218,  -317,   446,   607,  -317,    99,  -317,
    -317,  -317,  -317,  -317,  -317,  3115,  -317,   389,  3148,  -317,
    3907,  3940,  4358,  -317,  -317,   498,   442,  -317,   508,   524,
     251,   498,   538,  -317,   510,   459,   791,  -317,  -317,   821,
    3181,   749,  3214,  -317,   253,   296,   605,  2389,   106,  -317,
    -317,  4358,  -317,  -317,  -317,  -317,   122,   446,  -317,  -317,
    -317,   175,  -317,  -317,  -317,  -317,  -317,  -317,   573,   577,
     586,   597,   616,   651,  -317,  -317,   201,  -317,  -317,  -317,
    -317,  -317,  -317,  3247,  -317,   887,  3280,   574,   603,   459,
    -317,  4358,  -317,  -317,  -317,  -317,   656,   142,   661,   197,
     686,   299,   890,   652,   689,   236,   260,   269,  -317,  -317,
     324,  -317,  -317,  -317,  -317,  1752,  -317,  -317,  -317,   118,
    -317,   182,  -317,  4358,   694,  -317,  -317,  -317,  -317,   731,
     768,   978,  2422,   106,   702,   105,  -317,  -317,  -317,  -317,
    -317,  -317,  -317,  -317,   251,   695,   697,   709,   714,   725,
     730,   706,  1059,  1097,  -317,  -317,  -317,  -317,  -317,  -317,
    -317,  -317,   719,  -317,   149,  -317,   737,   307,   745,   333,
     752,   374,  1029,   756,   761,   417,   420,  4358,  -317,  -317,
     436,  -317,  -317,  -317,  -317,  1785,  -317,  -317,  -317,  4358,
    -317,  -317,  -317,  3808,  3973,   751,    17,  2455,  2488,   766,
     778,   384,   779,   413,   784,   -17,   -17,   783,   789,   809,
     817,   818,   822,   777,  1166,  1202,  -317,  -317,  -317,  -317,
     177,  -317,  -317,   807,  -317,   285,  3313,  1071,  3346,   442,
    -317,   160,   825,   826,   833,  1820,  1125,  1855,  4358,   840,
     843,   858,   867,  1258,   211,   613,  -317,   870,   877,  3907,
    4006,   868,    65,  2521,  2554,   879,   884,   452,   886,   523,
    -317,  -317,   888,   -17,   -17,   892,   892,   892,   764,   893,
    -317,  -317,  -317,  -317,  -317,  -317,  -317,  -317,   525,  2455,
    2587,   885,    70,   899,   566,  4306,   903,   908,  3379,  1153,
    3412,   442,  -317,   179,   909,   910,   912,  1888,  1160,  1923,
    4358,   921,   924,   926,   927,  1332,   923,   932,   123,  -317,
    -317,   892,  -317,  -317,  -317,  -317,  4039,  4072,   929,  1956,
    1182,  1989,   442,  -317,   488,   933,   934,   936,   937,   440,
    -317,  2455,  2620,   941,   941,   941,   831,   950,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,   596,  2521,  2653,   935,
     173,   945,   608,   962,   966,  4105,   970,  -317,  -317,    73,
    3445,   255,  3478,  -317,   963,   963,   963,  1028,   958,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,  -317,  2024,  1192,  2059,
     276,  -317,  -317,   941,  -317,  -317,  -317,  -317,  4138,  4171,
     969,  2092,  1248,  2125,   442,  -317,   521,   972,   974,   976,
     975,   453,  3907,  2686,  1262,  3511,  1380,   977,   460,   982,
     464,   316,  -317,  -317,   963,  -317,  -317,  -317,  -317,  2719,
    2752,  -317,  -317,  -317,  4204,   988,  -317,  -317,   346,  3544,
     366,  3577,  -317,   990,   990,   990,  1073,   979,  -317,  -317,
    -317,  -317,  -317,  -317,  -317,  -317,  3610,  1276,  2158,  -317,
    -317,  1001,   655,  -317,  -317,  -317,  -317,  -317,  -317,  2785,
    1003,  -317,  -317,   509,  2818,   565,  2851,  1283,  3643,  1498,
    1004,   487,  1009,   500,   347,  -317,  -317,   990,  -317,  -317,
    -317,  -317,  2884,  2917,  -317,  -317,  -317,  1006,  1013,  1303,
    2191,  1563,  1018,   502,  1019,   530,  -317,  -317,  1030,   659,
    -317,  -317,  -317,  -317,  -317,  -317,  2950,  1033,  -317,  -317,
     575,  2983,   635,  3016,  3808,  4237,  -317,  -317,  1034,   716,
    -317,   548,   557,  -317,  1027,  1039,  1042,  1045,  1328,  2224,
    1606,  1031,   533,  1043,   598,  3676,  1350,  3709,  1047,  1050,
    3907,  4270,  -317,  -317,  1052,   720,  -317,   599,   646,  -317,
    1054,  1057,  -317,  -317,  -317,  2455,  3049,  3742,  1399,  3775,
    1053,  1063,  2257,  1412,  2290,  -317,  -317,  -317,  2521,  3082,
    -317,  -317,  -317,  2323,  1444,  2356,  -317,  -317,  -317
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -317,  -317,  -317,  1075,    29,     0,   312,   433,    18,   -23,
     898,   -49,   -48,   645,  -122,  -317,    24,  -317,  -317,  1048,
    -317,   564,   604,  -317,  1035,  1385,   971,  -317,  -317,   692,
     334,  -153,   952,   992,   -62,  -317,   -81,  -317,   203,  -317,
     556,   568,  -317,   654,  -317,  -317,   704,    33,   747,   827,
    -316,   869,  -155,  -111,   -87,  -265,  -317,   135,  -317,   482,
     489,  -317,   571,  -317,  -317,   618,  -317,   372,  -317,   663,
     664,  -317,   746,  -317,  -317,   782,  -105,   -63,   400,  -110,
    -146,  -275,  -187,  -317,   248,  -317,   569,   570,  -317,   666,
    -317,  -317,   711
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -295
static const yytype_int16 yytable[] =
{
      38,    38,   168,   210,   182,    95,   162,   162,    74,   122,
     124,    19,    10,    38,    80,   106,   236,   121,   383,   215,
      25,    26,   215,    38,    38,    38,    89,    11,   125,     9,
     123,    12,   118,   190,   192,   120,     9,   394,   162,   162,
     398,    38,    38,   379,   215,   141,   215,    20,   163,   163,
     237,   199,    35,    35,    60,    16,   185,   186,   187,   188,
     162,   189,    51,   162,    60,    35,   445,   183,   184,   200,
     374,   476,   385,   387,    76,    35,    35,    35,   313,   274,
     163,   163,    60,    60,    21,   162,    77,   162,   154,   154,
      84,   441,    79,    35,    35,   239,   472,   456,   457,    91,
     212,   557,   163,    22,   204,   163,   341,   145,   209,     2,
       3,     4,   173,    27,    28,    29,    30,    31,   213,    76,
     154,   154,   289,   275,   342,   289,    23,   163,    95,   163,
      24,    77,   247,   249,   251,   129,   130,    79,    92,   505,
      47,   276,   154,   129,   130,   154,   506,   224,   224,    93,
     355,    94,    48,   123,   469,   471,    69,   296,    74,    95,
     269,   285,    27,    28,    29,    30,    31,   154,   356,   154,
     -14,    96,   -22,    49,   548,   270,   277,    97,   410,   294,
     129,   130,   374,    76,   374,    98,   379,   129,   130,   419,
      99,   100,   101,   102,   278,    77,   411,    56,   313,   544,
     313,    79,   286,   230,   230,   441,   527,   529,   487,    50,
     224,   314,   298,   224,    66,   129,   130,   317,   319,   321,
     287,   204,    61,   209,   435,    27,    28,    29,    30,    31,
     215,    75,   215,   376,   378,   129,   130,   304,   162,   162,
     351,   353,   210,    83,   438,   440,   123,   202,   203,    27,
      28,    29,    30,    31,   246,   305,    76,   -14,    14,   328,
     270,   306,    68,    15,    85,   370,   230,    94,    77,   230,
     308,   162,    50,   162,    79,    95,   374,   375,   374,   307,
     163,   163,   313,   559,   313,    86,   413,    96,   309,   129,
     130,    88,   574,    97,   614,   616,    50,   248,   418,   575,
     108,    98,   407,   409,   414,    87,    99,   100,   101,   102,
      94,   111,   328,   163,   300,   163,   447,   449,    95,   109,
     154,   154,   358,   129,   130,   310,   428,   289,   110,   289,
      96,   434,   609,   374,   640,   112,    97,   129,   130,   610,
     313,   114,   313,   311,    98,   129,   130,    76,   360,    99,
     100,   101,   102,   154,   115,   154,   510,   512,   119,    77,
     486,   162,   162,   656,   215,    79,   215,    76,    70,   116,
     657,   129,   130,   106,   620,   117,   224,   224,    70,    77,
     328,   328,   126,   579,   581,    79,   143,    70,   496,   362,
      76,   517,   144,   502,   622,   555,   374,   596,   374,   390,
     162,   170,    77,   163,   163,   162,   216,   162,    79,   215,
     541,   543,   129,   130,   374,   224,   127,   224,   366,   618,
     171,   368,   129,   130,   328,   169,   328,   313,   392,   313,
     712,   714,   230,   230,   177,   172,   367,   371,   177,   369,
     174,   525,   163,   154,   154,   158,   158,   163,   194,   163,
     162,   129,   130,   313,   594,   372,    94,    46,   374,   526,
     374,   604,   195,   586,    95,   607,   598,   452,   289,   196,
     289,   230,   595,   230,   328,   328,    96,   158,   158,   605,
      64,    65,   154,   608,   177,   289,   197,   154,   651,   154,
     129,   130,   163,   198,   602,    99,   100,   101,   102,   158,
     208,   654,   158,   671,   226,   226,   652,   289,   139,   140,
      76,   164,   164,   177,   472,   224,   224,   518,   328,   655,
     328,   672,    77,   240,   158,   313,   158,   313,    79,   224,
     328,   674,   154,   238,   697,   707,   709,   642,   454,   215,
     468,   215,   241,   164,   164,   661,   663,   544,   129,   675,
     587,   224,   698,   242,   685,   687,   224,   649,   224,   162,
     162,   129,   130,   129,   130,   164,    76,   226,   164,   679,
     226,   230,   230,   224,  -289,   328,    76,  -289,    77,   669,
     162,   479,   162,  -287,    79,   230,  -287,   279,    77,   292,
     164,   280,   164,   644,    79,   224,   289,    53,   289,   700,
     281,   163,   163,   681,   129,   130,   250,   230,    76,   328,
     328,   540,   230,   282,   230,    53,   330,   701,   695,    94,
      77,   201,   163,   551,   163,  -197,    79,    95,  -197,   230,
     283,   723,   725,   328,   129,   130,    76,    54,   328,    96,
     328,   154,   154,   202,   203,    97,   129,   130,    77,   202,
     203,   230,   284,    98,    79,    54,   328,   293,    99,   100,
     101,   102,   154,   683,   154,    94,   302,   224,   224,   330,
     638,   295,  -195,    95,   677,  -195,   297,   158,   158,    27,
      28,    29,    30,    31,   224,    96,   224,   536,   537,   396,
     396,    97,    32,   129,   130,   328,   328,   129,   130,    98,
     328,   299,   328,   303,    99,   100,   101,   102,    90,   315,
     158,   343,   158,   344,    27,    28,    29,    30,    31,   630,
     631,   340,   -14,   230,   230,   345,    34,   459,   459,   459,
     346,   689,   316,   226,   226,   711,   349,   330,   330,    76,
     230,   347,   230,   164,   164,    94,   348,   396,   396,   354,
      76,    77,   357,    95,   129,   130,    78,    79,   129,   130,
     359,    50,    77,   567,   568,    96,   244,   361,    79,   318,
     364,    97,   226,   459,   226,   365,   164,   379,   164,    98,
     388,   330,    94,   330,    99,   100,   101,   102,   464,   465,
      95,   466,   -86,   389,   391,   531,   531,   531,   393,   399,
     158,   158,    96,   157,   157,   400,   -86,   405,    97,   -86,
     -86,   137,   176,   139,   140,     1,    98,     2,     3,     4,
       5,    99,   100,   101,   102,   401,   562,   562,   562,   -86,
     -86,   330,   330,   402,   403,   157,   157,   412,   404,   158,
     139,   140,   422,   423,   158,   531,   158,     2,     3,     4,
     424,    27,    28,    29,    30,    31,   429,   157,   538,   430,
     157,    59,   225,   225,    32,    33,   164,   164,   137,   176,
     139,   140,   226,   226,   431,   330,   562,   330,   137,   176,
     139,   140,   157,   432,   157,   436,   226,   330,    76,   158,
     272,    76,   437,   450,   441,   625,   625,   625,    34,   451,
      77,   453,   455,    77,   290,   164,    79,   301,   226,    79,
     164,   472,   164,   226,   478,   226,   458,   231,   231,   481,
     467,    39,    39,    76,   482,   225,   490,   491,   225,   492,
     226,    52,   330,    57,    39,    77,   201,   497,   503,   625,
     498,    79,   499,   500,    39,    39,    39,   504,   513,    52,
     521,   522,   226,   523,    71,   164,   524,   123,   202,   203,
     550,   544,    39,    39,    71,   530,   330,   330,    27,    28,
      29,    30,    31,    71,   329,   272,   -22,   539,   552,   320,
     231,    32,   553,   231,   556,   570,   113,   561,   582,   590,
     330,   591,    94,   592,   593,   330,   603,   330,   158,   158,
      95,   606,   619,     2,     3,     4,   633,    27,    28,    29,
      30,    31,    96,   330,   624,    50,   637,   641,    97,   158,
      32,   158,   664,   650,   226,   226,    98,   329,   653,   665,
      76,    99,   100,   101,   102,   157,   157,   670,   673,   232,
     232,   226,    77,   226,  -294,   676,   363,   680,    79,   688,
     696,   207,   330,   330,    50,   569,  -292,   330,   690,   330,
     350,   691,   699,   705,   164,   164,   706,   710,   157,   718,
     157,  -202,    76,    94,  -200,   137,   176,   139,   140,   719,
     480,    95,    13,    58,    77,   164,    67,   164,   416,   576,
      79,   225,   225,    96,   181,   329,   329,   488,   352,    97,
     632,   577,   232,   159,   159,   232,   446,    98,   211,   658,
     339,    94,    99,   100,   101,   102,   659,   588,   549,    95,
     137,   176,   139,   140,   507,   508,    76,   420,   384,     0,
     225,    96,   225,   611,   612,   159,   159,    97,    77,   329,
     519,   329,   426,   477,    79,    98,   231,   231,     0,     0,
      99,   100,   101,   102,    76,     0,     0,   159,   157,   157,
     159,    76,   227,   227,     0,     0,    77,   406,     0,     0,
     484,     0,    79,    77,     0,     0,     0,   494,     0,    79,
      94,     0,   159,    76,   159,   231,     0,   231,    95,   329,
     329,     0,     0,    76,     0,    77,     0,   157,     0,   515,
      96,    79,   157,   408,   157,    77,    97,     0,     0,   572,
       0,    79,     0,     0,    98,     0,    94,     0,     0,    99,
     100,   101,   102,     0,    95,   227,     0,     0,   227,     0,
     225,   225,     0,   329,     0,   329,    96,     0,     0,     0,
       0,     0,    97,     0,   225,   329,     0,   157,     0,    76,
      98,     0,     0,     0,     0,    99,   100,   101,   102,   433,
       0,    77,     0,    76,     0,   584,   225,    79,   232,   232,
       0,   225,    94,   225,   331,    77,     0,    76,     0,   599,
      95,    79,     0,     0,    76,   231,   231,     0,   225,    77,
     329,     0,    96,   635,     0,    79,    77,     0,    97,   231,
     646,     0,    79,     0,    76,     0,    98,   232,     0,   232,
     225,    99,   100,   101,   102,     0,    77,     0,     0,     0,
     666,   231,    79,     0,   329,   329,   231,   331,   231,    76,
       0,     0,     0,   501,     0,   159,   159,     0,     0,     0,
       0,    77,     0,   231,     0,   692,    94,    79,   329,     0,
       0,    76,     0,   329,    95,   329,   157,   157,     0,     0,
       0,     0,     0,    77,     0,   231,    96,   703,   159,    79,
     159,   329,    97,     0,     0,     0,     0,   157,     0,   157,
      98,   601,   225,   225,     0,    99,   100,   101,   102,     0,
       0,   227,   227,     0,    94,   331,   331,     0,     0,   225,
      76,   225,    95,     0,     0,     0,     0,   232,   232,     0,
     329,   329,    77,    76,    96,   329,   716,   329,    79,     0,
      97,   232,     0,     0,     0,    77,     0,     0,    98,   721,
     227,    79,   227,    99,   100,   101,   102,   231,   231,   331,
       0,   331,     0,   232,     0,    76,     0,     0,   232,     0,
     232,     0,     0,     0,   231,     0,   231,    77,   159,   159,
       0,   727,   104,    79,     0,   232,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,   104,
       0,    63,   104,   104,    32,    33,     0,   232,     0,   331,
     331,     0,   104,     0,     0,     0,     0,   159,     0,   648,
       0,     0,   159,     0,   159,     0,     0,   104,     0,     0,
       0,   104,    94,     0,   104,   104,     0,     0,    34,     0,
      95,     0,   104,   104,   104,   104,     0,   104,     0,     0,
     227,   227,    96,   331,     0,   331,    -2,     1,    97,     2,
       3,     4,     5,     0,   227,   331,    98,   159,     0,     0,
       0,    99,   100,   101,   102,     0,     0,   104,     0,   232,
     232,   104,     0,     0,   668,     0,   227,     0,     0,     0,
       0,   227,     0,   227,     0,     0,   232,    94,   232,   104,
     104,   104,     0,   271,     0,    95,   104,     0,   227,     0,
     331,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,    97,     0,     0,     0,   694,   104,     0,
     227,    98,     0,     0,     0,     0,    99,   100,   101,   102,
      94,     0,     0,     0,   331,   331,   104,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,    97,     0,   331,     0,
       0,     0,     0,   331,    98,   331,   159,   159,   104,    99,
     100,   101,   102,     0,   104,   104,   104,     0,   271,     0,
       0,   331,     0,     0,     0,     0,     0,   159,     0,   159,
       0,     0,   227,   227,     0,     0,     0,   104,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   227,     0,     0,     0,     0,     0,     0,     0,     0,
     331,   331,   104,     0,     0,   331,     0,   331,     0,     0,
       0,     2,     3,     4,   104,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,    81,     0,     0,    32,    33,
     395,   395,     0,     0,     0,     0,     0,     0,     0,   104,
     104,     0,     0,   145,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,   104,     0,     0,     0,     0,   312,
       0,     0,    34,   104,    95,   253,     0,   254,   104,     0,
     255,     0,   148,   149,   150,   256,   145,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,   395,   395,
       0,     0,   373,   257,     0,     0,   152,    95,   323,     0,
     324,     0,     0,   325,     0,   220,   221,   222,   326,     0,
     104,   145,     0,     2,     3,     4,   104,    27,    28,    29,
      30,    31,     0,     0,     0,   104,   327,   425,     0,   152,
     104,     0,    95,   253,     0,   254,     0,     0,   255,     0,
     148,   149,   150,   256,     0,     0,   145,   104,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,   257,   427,     0,   152,     0,     0,    95,   253,     0,
     254,     0,     0,   255,     0,   148,   149,   150,   256,   145,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,   493,   257,     0,     0,   152,
      95,   323,     0,   324,     0,     0,   325,     0,   220,   221,
     222,   326,     0,     0,   145,     0,     2,     3,     4,   104,
      27,    28,    29,    30,    31,     0,     0,     0,     0,   327,
     495,   104,   152,     0,     0,    95,   323,     0,   324,     0,
       0,   325,     0,   220,   221,   222,   326,   145,     0,     2,
       3,     4,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,   514,   327,     0,     0,   152,    95,   253,
       0,   254,     0,     0,   255,     0,   148,   149,   150,   256,
     145,     0,     2,     3,     4,     0,    27,    28,    29,    30,
      31,     0,     0,     0,   104,     0,   516,   257,     0,     0,
     152,    95,   253,     0,   254,     0,     0,   255,     0,   148,
     149,   150,   256,     0,     0,   145,   104,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
     257,   571,     0,   152,     0,     0,    95,   253,     0,   254,
       0,     0,   255,     0,   148,   149,   150,   256,     0,     0,
     145,     0,     2,     3,     4,   104,    27,    28,    29,    30,
      31,     0,     0,     0,     0,   257,   573,     0,   152,     0,
       0,    95,   253,     0,   254,     0,     0,   255,     0,   148,
     149,   150,   256,   145,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,   583,
     257,     0,     0,   152,    95,   323,     0,   324,     0,     0,
     325,     0,   220,   221,   222,   326,   145,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,   585,   327,     0,     0,   152,    95,   323,     0,
     324,     0,     0,   325,     0,   220,   221,   222,   326,   145,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,   636,   327,     0,     0,   152,
      95,   323,     0,   324,     0,     0,   325,     0,   220,   221,
     222,   326,   145,     0,     2,     3,     4,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,   667,   327,
       0,     0,   152,    95,   253,     0,   254,     0,     0,   255,
       0,   148,   149,   150,   256,   145,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,   693,   257,     0,     0,   152,    95,   323,     0,   324,
       0,     0,   325,     0,   220,   221,   222,   326,   145,     0,
       2,     3,     4,     0,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,   720,   327,     0,     0,   152,    95,
     253,     0,   254,     0,     0,   255,     0,   148,   149,   150,
     256,   145,     0,     2,     3,     4,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,   722,   257,     0,
       0,   152,    95,   253,     0,   254,     0,     0,   255,     0,
     148,   149,   150,   256,   145,     0,     2,     3,     4,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
     726,   257,     0,     0,   152,    95,   323,     0,   324,     0,
       0,   325,     0,   220,   221,   222,   326,   145,     0,     2,
       3,     4,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,   728,   327,     0,     0,   152,    95,   323,
       0,   324,     0,     0,   325,     0,   220,   221,   222,   326,
     252,     0,     2,     3,     4,     0,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,   327,     0,     0,
     152,    95,   253,     0,   254,     0,     0,   255,     0,   148,
     149,   150,   256,   322,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
     257,     0,     0,   152,    95,   323,     0,   324,     0,     0,
     325,     0,   220,   221,   222,   326,   145,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,   327,     0,     0,   152,    95,   253,     0,
     254,     0,     0,   255,     0,   148,   149,   150,   256,   386,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,   257,     0,     0,   152,
      95,   253,     0,   254,     0,     0,   255,     0,   148,   149,
     150,   256,   145,     0,     2,     3,     4,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,   257,
       0,     0,   152,    95,   323,     0,   324,     0,     0,   325,
       0,   220,   221,   222,   326,   448,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,   327,     0,     0,   152,    95,   323,     0,   324,
       0,     0,   325,     0,   220,   221,   222,   326,   470,     0,
       2,     3,     4,     0,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,   327,     0,     0,   152,    95,
     253,     0,   254,     0,     0,   255,     0,   148,   149,   150,
     256,   528,     0,     2,     3,     4,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,   257,     0,
       0,   152,    95,   253,     0,   254,     0,     0,   255,     0,
     148,   149,   150,   256,   542,     0,     2,     3,     4,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,   257,     0,     0,   152,    95,   323,     0,   324,     0,
       0,   325,     0,   220,   221,   222,   326,   597,     0,     2,
       3,     4,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,   327,     0,     0,   152,    95,   323,
       0,   324,     0,     0,   325,     0,   220,   221,   222,   326,
     613,     0,     2,     3,     4,     0,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,   327,     0,     0,
     152,    95,   253,     0,   254,     0,     0,   255,     0,   148,
     149,   150,   256,   615,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
     257,     0,     0,   152,    95,   253,     0,   254,     0,     0,
     255,     0,   148,   149,   150,   256,   639,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,   257,     0,     0,   152,    95,   253,     0,
     254,     0,     0,   255,     0,   148,   149,   150,   256,   145,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,   257,     0,     0,   152,
      95,   253,     0,   254,     0,     0,   643,     0,   148,   149,
     150,   256,   145,     0,     2,     3,     4,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,   257,
       0,     0,   152,    95,   253,     0,   254,     0,     0,   645,
       0,   148,   149,   150,   256,   660,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,   257,     0,     0,   152,    95,   323,     0,   324,
       0,     0,   325,     0,   220,   221,   222,   326,   662,     0,
       2,     3,     4,     0,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,   327,     0,     0,   152,    95,
     323,     0,   324,     0,     0,   325,     0,   220,   221,   222,
     326,   678,     0,     2,     3,     4,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,   327,     0,
       0,   152,    95,   323,     0,   324,     0,     0,   325,     0,
     220,   221,   222,   326,   145,     0,     2,     3,     4,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,   327,     0,     0,   152,    95,   323,     0,   324,     0,
       0,   682,     0,   220,   221,   222,   326,   145,     0,     2,
       3,     4,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,   327,     0,     0,   152,    95,   323,
       0,   324,     0,     0,   684,     0,   220,   221,   222,   326,
     713,     0,     2,     3,     4,     0,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,   327,     0,     0,
     152,    95,   253,     0,   254,     0,     0,   255,     0,   148,
     149,   150,   256,   724,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
     257,     0,     0,   152,    95,   323,     0,   324,     0,     0,
     325,     0,   220,   221,   222,   326,   145,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,   214,   327,     0,     0,   152,    95,   146,     0,
     147,     0,     0,     0,     0,   148,   149,   150,     0,   145,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,   217,   151,     0,     0,   152,
      95,   146,     0,   147,     0,     0,     0,     0,   148,   149,
     150,     0,   145,     0,     2,     3,     4,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,   243,   151,
       0,     0,   152,    95,   146,     0,   147,     0,     0,     0,
       0,   148,   149,   150,     0,   145,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,   245,   151,     0,     0,   152,    95,   146,     0,   147,
       0,     0,     0,     0,   148,   149,   150,     0,   145,     0,
       2,     3,     4,     0,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,   288,   151,     0,     0,   152,    95,
     218,     0,   219,     0,     0,     0,     0,   220,   221,   222,
       0,   145,     0,     2,     3,     4,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,   291,   223,     0,
       0,   152,    95,   218,     0,   219,     0,     0,     0,     0,
     220,   221,   222,     0,   145,     0,     2,     3,     4,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
     415,   223,     0,     0,   152,    95,   146,     0,   147,     0,
       0,     0,     0,   148,   149,   150,     0,   145,     0,     2,
       3,     4,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,   417,   151,     0,     0,   152,    95,   146,
       0,   147,     0,     0,     0,     0,   148,   149,   150,     0,
     145,     0,     2,     3,     4,     0,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,   483,   151,     0,     0,
     152,    95,   218,     0,   219,     0,     0,     0,     0,   220,
     221,   222,     0,   145,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,   485,
     223,     0,     0,   152,    95,   218,     0,   219,     0,     0,
       0,     0,   220,   221,   222,     0,   145,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,   223,     0,     0,   152,    95,   146,     0,
     147,     0,     0,   558,     0,   148,   149,   150,     0,   145,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,   151,     0,     0,   152,
      95,   146,     0,   147,     0,     0,   560,     0,   148,   149,
     150,     0,   145,     0,     2,     3,     4,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,   600,   151,
       0,     0,   152,    95,   146,     0,   147,     0,     0,     0,
       0,   148,   149,   150,     0,   145,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,   151,     0,     0,   152,    95,   218,     0,   219,
       0,     0,   621,     0,   220,   221,   222,     0,   145,     0,
       2,     3,     4,     0,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,   223,     0,     0,   152,    95,
     218,     0,   219,     0,     0,   623,     0,   220,   221,   222,
       0,   145,     0,     2,     3,     4,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,   634,   223,     0,
       0,   152,    95,   218,     0,   219,     0,     0,     0,     0,
     220,   221,   222,     0,   145,     0,     2,     3,     4,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
     647,   223,     0,     0,   152,    95,   218,     0,   219,     0,
       0,     0,     0,   220,   221,   222,     0,   145,     0,     2,
       3,     4,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,   702,   223,     0,     0,   152,    95,   146,
       0,   147,     0,     0,     0,     0,   148,   149,   150,     0,
     145,     0,     2,     3,     4,     0,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,   704,   151,     0,     0,
     152,    95,   146,     0,   147,     0,     0,     0,     0,   148,
     149,   150,     0,   145,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,   715,
     151,     0,     0,   152,    95,   218,     0,   219,     0,     0,
       0,     0,   220,   221,   222,     0,   145,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,   717,   223,     0,     0,   152,    95,   218,     0,
     219,     0,     0,     0,     0,   220,   221,   222,     0,   145,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,   223,     0,     0,   152,
      95,   146,     0,   147,     0,     0,     0,     0,   148,   149,
     150,     0,   167,     0,     2,     3,     4,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,   151,
       0,     0,   152,    95,   146,     0,   147,     0,     0,     0,
       0,   148,   149,   150,     0,   191,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,   151,     0,     0,   152,    95,   146,     0,   147,
       0,     0,     0,     0,   148,   149,   150,     0,   145,     0,
       2,     3,     4,     0,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,   151,     0,     0,   152,    95,
     218,     0,   219,     0,     0,     0,     0,   220,   221,   222,
       0,   235,     0,     2,     3,     4,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,   223,     0,
       0,   152,    95,   218,     0,   219,     0,     0,     0,     0,
     220,   221,   222,     0,   377,     0,     2,     3,     4,     0,
      27,    28,    29,    30,    31,     0,     0,     0,     0,     0,
       0,   223,     0,     0,   152,    95,   146,     0,   147,     0,
       0,     0,     0,   148,   149,   150,     0,   439,     0,     2,
       3,     4,     0,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,   151,     0,     0,   152,    95,   218,
       0,   219,     0,     0,     0,     0,   220,   221,   222,     0,
     509,     0,     2,     3,     4,     0,    27,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,   223,     0,     0,
     152,    95,   146,     0,   147,     0,     0,     0,     0,   148,
     149,   150,     0,   511,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
     151,     0,     0,   152,    95,   146,     0,   147,     0,     0,
       0,     0,   148,   149,   150,     0,   554,     0,     2,     3,
       4,     0,    27,    28,    29,    30,    31,     0,     0,     0,
       0,     0,     0,   151,     0,     0,   152,    95,   146,     0,
     147,     0,     0,     0,     0,   148,   149,   150,     0,   578,
       0,     2,     3,     4,     0,    27,    28,    29,    30,    31,
       0,     0,     0,     0,     0,     0,   151,     0,     0,   152,
      95,   218,     0,   219,     0,     0,     0,     0,   220,   221,
     222,     0,   580,     0,     2,     3,     4,     0,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,   223,
       0,     0,   152,    95,   218,     0,   219,     0,     0,     0,
       0,   220,   221,   222,     0,   617,     0,     2,     3,     4,
       0,    27,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,   223,     0,     0,   152,    95,   218,     0,   219,
       0,     0,     0,     0,   220,   221,   222,     0,   686,     0,
       2,     3,     4,     0,    27,    28,    29,    30,    31,     0,
       0,     0,     0,     0,     0,   223,     0,     0,   152,    95,
     146,     0,   147,     0,     0,     0,     0,   148,   149,   150,
       0,   708,     0,     2,     3,     4,     0,    27,    28,    29,
      30,    31,     0,     0,     0,     0,     0,     0,   151,     0,
       0,   152,    95,   218,     0,   219,     0,     0,     0,     0,
     220,   221,   222,     0,     0,     2,     3,     4,     0,    27,
      28,    29,    30,    31,     0,     0,     0,     0,    93,    82,
      94,   223,    32,    33,   152,     2,     3,     4,    95,    27,
      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
      96,     0,    32,    33,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,    98,    94,    34,     0,     0,    99,
     100,   101,   102,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    96,    34,     0,     0,     0,
      95,    97,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    96,     0,    99,   100,   101,   102,    97,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,    99,   100,   101,   102
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-317)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      23,    24,   112,   156,   126,    22,   111,   112,    57,    14,
       1,    11,    54,    36,    62,    77,   171,    98,     1,   165,
      20,    21,   168,    46,    47,    48,    74,    54,    19,     0,
      35,     0,    94,   143,   144,    97,     7,    54,   143,   144,
     356,    64,    65,    26,   190,   107,   192,    54,   111,   112,
     172,     1,    23,    24,    36,    52,   137,   138,   139,   140,
     165,   142,    33,   168,    46,    36,     1,   129,   130,    19,
     335,     1,   347,   348,     1,    46,    47,    48,   265,   201,
     143,   144,    64,    65,    54,   190,    13,   192,   111,   112,
      66,    26,    19,    64,    65,   176,    26,   413,   414,    75,
       1,    28,   165,    54,   152,   168,     1,     1,   156,     3,
       4,     5,    15,     7,     8,     9,    10,    11,    19,     1,
     143,   144,   233,     1,    19,   236,    16,   190,    22,   192,
      16,    13,   194,   195,   196,    38,    39,    19,     1,    16,
      16,    19,   165,    38,    39,   168,    23,   170,   171,    12,
       1,    14,    16,    35,   429,   430,     1,    15,   207,    22,
      54,   223,     7,     8,     9,    10,    11,   190,    19,   192,
      15,    34,    54,    54,     1,   198,     1,    40,     1,   241,
      38,    39,   447,     1,   449,    48,    26,    38,    39,    29,
      53,    54,    55,    56,    19,    13,    19,    14,   385,    26,
     387,    19,     1,   170,   171,    26,   481,   482,    29,    54,
     233,   273,    15,   236,    14,    38,    39,   279,   280,   281,
      19,   269,    54,   271,    13,     7,     8,     9,    10,    11,
     376,    14,   378,   343,   344,    38,    39,     1,   343,   344,
     302,   303,   395,     1,   399,   400,    35,    36,    37,     7,
       8,     9,    10,    11,     1,    19,     1,    15,     1,   282,
     283,     1,    54,     6,    15,   327,   233,    14,    13,   236,
       1,   376,    54,   378,    19,    22,   541,   339,   543,    19,
     343,   344,   469,    28,   471,    54,     1,    34,    19,    38,
      39,    18,    16,    40,   569,   570,    54,     1,   379,    23,
      54,    48,   364,   365,    19,    15,    53,    54,    55,    56,
      14,    16,   335,   376,    15,   378,   403,   404,    22,    15,
     343,   344,    15,    38,    39,     1,   388,   438,    15,   440,
      34,   393,    16,   598,   609,    16,    40,    38,    39,    23,
     527,    15,   529,    19,    48,    38,    39,     1,    15,    53,
      54,    55,    56,   376,    15,   378,   466,   467,    35,    13,
     441,   466,   467,    16,   510,    19,   512,     1,    56,    19,
      23,    38,    39,   435,    28,    54,   399,   400,    66,    13,
     403,   404,    14,   538,   539,    19,    16,    75,   450,    15,
       1,   472,    16,   455,    28,   505,   661,   552,   663,    15,
     505,    16,    13,   466,   467,   510,    17,   512,    19,   555,
     497,   498,    38,    39,   679,   438,   104,   440,     1,   574,
      16,     1,    38,    39,   447,    54,   449,   614,    15,   616,
     705,   706,   399,   400,   122,    14,    19,     1,   126,    19,
      54,     1,   505,   466,   467,   111,   112,   510,    14,   512,
     555,    38,    39,   640,     1,    19,    14,    24,   723,    19,
     725,     1,    14,   544,    22,     1,   553,    15,   579,    14,
     581,   438,    19,   440,   497,   498,    34,   143,   144,    19,
      47,    48,   505,    19,   172,   596,    16,   510,     1,   512,
      38,    39,   555,    14,   556,    53,    54,    55,    56,   165,
      54,     1,   168,     1,   170,   171,    19,   618,    49,    50,
       1,   111,   112,   201,    26,   538,   539,    29,   541,    19,
     543,    19,    13,    15,   190,   712,   192,   714,    19,   552,
     553,     1,   555,    35,     1,   690,   691,    28,    15,   685,
      15,   687,    18,   143,   144,   632,   633,    26,    38,    19,
      29,   574,    19,    15,   664,   665,   579,   619,   581,   664,
     665,    38,    39,    38,    39,   165,     1,   233,   168,   656,
     236,   538,   539,   596,    26,   598,     1,    29,    13,   641,
     685,    15,   687,    26,    19,   552,    29,    14,    13,    15,
     190,    14,   192,    28,    19,   618,   707,    33,   709,     1,
      14,   664,   665,    28,    38,    39,     1,   574,     1,   632,
     633,    15,   579,    16,   581,    51,   282,    19,   680,    14,
      13,    14,   685,    15,   687,    26,    19,    22,    29,   596,
      14,   718,   719,   656,    38,    39,     1,    33,   661,    34,
     663,   664,   665,    36,    37,    40,    38,    39,    13,    36,
      37,   618,     1,    48,    19,    51,   679,    54,    53,    54,
      55,    56,   685,    28,   687,    14,    14,   690,   691,   335,
      15,    15,    26,    22,    15,    29,    15,   343,   344,     7,
       8,     9,    10,    11,   707,    34,   709,   484,   485,   355,
     356,    40,    20,    38,    39,   718,   719,    38,    39,    48,
     723,    15,   725,    14,    53,    54,    55,    56,     1,    15,
     376,    16,   378,    16,     7,     8,     9,    10,    11,   584,
     585,    19,    15,   690,   691,    16,    54,   415,   416,   417,
      16,    15,     1,   399,   400,    15,    30,   403,   404,     1,
     707,    16,   709,   343,   344,    14,    16,   413,   414,    30,
       1,    13,    15,    22,    38,    39,    18,    19,    38,    39,
      15,    54,    13,   515,   516,    34,    17,    15,    19,     1,
      14,    40,   438,   461,   440,    14,   376,    26,   378,    48,
      14,   447,    14,   449,    53,    54,    55,    56,   416,   417,
      22,    27,     1,    15,    15,   483,   484,   485,    14,    16,
     466,   467,    34,   111,   112,    16,    15,    30,    40,    18,
      19,    47,    48,    49,    50,     1,    48,     3,     4,     5,
       6,    53,    54,    55,    56,    16,   514,   515,   516,    38,
      39,   497,   498,    16,    16,   143,   144,    30,    16,   505,
      49,    50,    17,    17,   510,   533,   512,     3,     4,     5,
      17,     7,     8,     9,    10,    11,    16,   165,    27,    16,
     168,    17,   170,   171,    20,    21,   466,   467,    47,    48,
      49,    50,   538,   539,    16,   541,   564,   543,    47,    48,
      49,    50,   190,    16,   192,    15,   552,   553,     1,   555,
     198,     1,    15,    14,    26,   583,   584,   585,    54,    15,
      13,    15,    14,    13,    17,   505,    19,    17,   574,    19,
     510,    26,   512,   579,    15,   581,    24,   170,   171,    16,
      27,    23,    24,     1,    16,   233,    17,    17,   236,    17,
     596,    33,   598,    35,    36,    13,    14,    16,    15,   627,
      16,    19,    16,    16,    46,    47,    48,    15,    19,    51,
      17,    17,   618,    17,    56,   555,    19,    35,    36,    37,
      15,    26,    64,    65,    66,    24,   632,   633,     7,     8,
       9,    10,    11,    75,   282,   283,    54,    27,    16,     1,
     233,    20,    16,   236,    14,    27,    88,    24,    19,    17,
     656,    17,    14,    17,    19,   661,    19,   663,   664,   665,
      22,    19,    14,     3,     4,     5,    27,     7,     8,     9,
      10,    11,    34,   679,    24,    54,    15,    14,    40,   685,
      20,   687,    16,    19,   690,   691,    48,   335,    19,    16,
       1,    53,    54,    55,    56,   343,   344,    19,    19,   170,
     171,   707,    13,   709,    17,    15,    17,    14,    19,    15,
      19,   153,   718,   719,    54,    27,    17,   723,    16,   725,
       1,    16,    19,    16,   664,   665,    16,    15,   376,    16,
     378,    17,     1,    14,    17,    47,    48,    49,    50,    16,
     435,    22,     7,    35,    13,   685,    51,   687,    17,   533,
      19,   399,   400,    34,   123,   403,   404,   443,     1,    40,
      27,   533,   233,   111,   112,   236,   402,    48,   156,   627,
     283,    14,    53,    54,    55,    56,   627,   546,   500,    22,
      47,    48,    49,    50,   461,   461,     1,   381,   346,    -1,
     438,    34,   440,   564,   564,   143,   144,    40,    13,   447,
     474,   449,    17,   432,    19,    48,   399,   400,    -1,    -1,
      53,    54,    55,    56,     1,    -1,    -1,   165,   466,   467,
     168,     1,   170,   171,    -1,    -1,    13,     1,    -1,    -1,
      17,    -1,    19,    13,    -1,    -1,    -1,    17,    -1,    19,
      14,    -1,   190,     1,   192,   438,    -1,   440,    22,   497,
     498,    -1,    -1,     1,    -1,    13,    -1,   505,    -1,    17,
      34,    19,   510,     1,   512,    13,    40,    -1,    -1,    17,
      -1,    19,    -1,    -1,    48,    -1,    14,    -1,    -1,    53,
      54,    55,    56,    -1,    22,   233,    -1,    -1,   236,    -1,
     538,   539,    -1,   541,    -1,   543,    34,    -1,    -1,    -1,
      -1,    -1,    40,    -1,   552,   553,    -1,   555,    -1,     1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,     1,
      -1,    13,    -1,     1,    -1,    17,   574,    19,   399,   400,
      -1,   579,    14,   581,   282,    13,    -1,     1,    -1,    17,
      22,    19,    -1,    -1,     1,   538,   539,    -1,   596,    13,
     598,    -1,    34,    17,    -1,    19,    13,    -1,    40,   552,
      17,    -1,    19,    -1,     1,    -1,    48,   438,    -1,   440,
     618,    53,    54,    55,    56,    -1,    13,    -1,    -1,    -1,
      17,   574,    19,    -1,   632,   633,   579,   335,   581,     1,
      -1,    -1,    -1,     1,    -1,   343,   344,    -1,    -1,    -1,
      -1,    13,    -1,   596,    -1,    17,    14,    19,   656,    -1,
      -1,     1,    -1,   661,    22,   663,   664,   665,    -1,    -1,
      -1,    -1,    -1,    13,    -1,   618,    34,    17,   376,    19,
     378,   679,    40,    -1,    -1,    -1,    -1,   685,    -1,   687,
      48,     1,   690,   691,    -1,    53,    54,    55,    56,    -1,
      -1,   399,   400,    -1,    14,   403,   404,    -1,    -1,   707,
       1,   709,    22,    -1,    -1,    -1,    -1,   538,   539,    -1,
     718,   719,    13,     1,    34,   723,    17,   725,    19,    -1,
      40,   552,    -1,    -1,    -1,    13,    -1,    -1,    48,    17,
     438,    19,   440,    53,    54,    55,    56,   690,   691,   447,
      -1,   449,    -1,   574,    -1,     1,    -1,    -1,   579,    -1,
     581,    -1,    -1,    -1,   707,    -1,   709,    13,   466,   467,
      -1,    17,    77,    19,    -1,   596,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    94,
      -1,    17,    97,    98,    20,    21,    -1,   618,    -1,   497,
     498,    -1,   107,    -1,    -1,    -1,    -1,   505,    -1,     1,
      -1,    -1,   510,    -1,   512,    -1,    -1,   122,    -1,    -1,
      -1,   126,    14,    -1,   129,   130,    -1,    -1,    54,    -1,
      22,    -1,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     538,   539,    34,   541,    -1,   543,     0,     1,    40,     3,
       4,     5,     6,    -1,   552,   553,    48,   555,    -1,    -1,
      -1,    53,    54,    55,    56,    -1,    -1,   172,    -1,   690,
     691,   176,    -1,    -1,     1,    -1,   574,    -1,    -1,    -1,
      -1,   579,    -1,   581,    -1,    -1,   707,    14,   709,   194,
     195,   196,    -1,   198,    -1,    22,   201,    -1,   596,    -1,
     598,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,     1,   223,    -1,
     618,    48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      14,    -1,    -1,    -1,   632,   633,   241,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    40,    -1,   656,    -1,
      -1,    -1,    -1,   661,    48,   663,   664,   665,   273,    53,
      54,    55,    56,    -1,   279,   280,   281,    -1,   283,    -1,
      -1,   679,    -1,    -1,    -1,    -1,    -1,   685,    -1,   687,
      -1,    -1,   690,   691,    -1,    -1,    -1,   302,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,
      -1,   709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     718,   719,   327,    -1,    -1,   723,    -1,   725,    -1,    -1,
      -1,     3,     4,     5,   339,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,
     355,   356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,
     365,    -1,    -1,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,   379,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    54,   388,    22,    23,    -1,    25,   393,    -1,
      28,    -1,    30,    31,    32,    33,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,   413,   414,
      -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    31,    32,    33,    -1,
     435,     1,    -1,     3,     4,     5,   441,     7,     8,     9,
      10,    11,    -1,    -1,    -1,   450,    51,    17,    -1,    54,
     455,    -1,    22,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    32,    33,    -1,    -1,     1,   472,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    51,    17,    -1,    54,    -1,    -1,    22,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    31,    32,    33,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,
      32,    33,    -1,    -1,     1,    -1,     3,     4,     5,   544,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    51,
      17,   556,    54,    -1,    -1,    22,    23,    -1,    25,    -1,
      -1,    28,    -1,    30,    31,    32,    33,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,    33,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,   619,    -1,    17,    51,    -1,    -1,
      54,    22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      31,    32,    33,    -1,    -1,     1,   641,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      51,    17,    -1,    54,    -1,    -1,    22,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    31,    32,    33,    -1,    -1,
       1,    -1,     3,     4,     5,   680,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    51,    17,    -1,    54,    -1,
      -1,    22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      31,    32,    33,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,
      51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,    32,    33,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    31,    32,    33,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,
      32,    33,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    51,
      -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,    28,
      -1,    30,    31,    32,    33,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    51,    -1,    -1,    54,    22,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    31,    32,    33,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    17,    51,    -1,    -1,    54,    22,
      23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,
      33,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    17,    51,    -1,
      -1,    54,    22,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    32,    33,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,
      -1,    28,    -1,    30,    31,    32,    33,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,    33,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      31,    32,    33,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,    32,    33,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    31,    32,    33,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,
      32,    33,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,    28,
      -1,    30,    31,    32,    33,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    31,    32,    33,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,
      23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,
      33,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    54,    22,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    32,    33,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,
      -1,    28,    -1,    30,    31,    32,    33,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,    33,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      31,    32,    33,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,    32,    33,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    31,    32,    33,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,
      32,    33,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,    28,
      -1,    30,    31,    32,    33,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    31,    32,    33,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,
      23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,
      33,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    54,    22,    23,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    32,    33,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,
      -1,    28,    -1,    30,    31,    32,    33,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,    23,
      -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,    33,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,
      31,    32,    33,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,    32,    33,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    17,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    51,
      -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    17,    51,    -1,    -1,    54,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    17,    51,    -1,    -1,    54,    22,
      23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    17,    51,    -1,
      -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    51,    -1,    -1,
      54,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,
      51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    28,    -1,    30,    31,    32,    -1,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,
      32,    -1,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    51,
      -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,
      -1,    -1,    28,    -1,    30,    31,    32,    -1,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,
      23,    -1,    25,    -1,    -1,    28,    -1,    30,    31,    32,
      -1,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    17,    51,    -1,
      -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    51,    -1,    -1,
      54,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,
      51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    17,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,
      23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,    23,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,
      31,    32,    -1,     1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    -1,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,     1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      22,    23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,     1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    22,    23,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    -1,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    22,
      23,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,     1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    54,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    12,    17,
      14,    51,    20,    21,    54,     3,     4,     5,    22,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    20,    21,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    14,    54,    -1,    -1,    53,
      54,    55,    56,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    34,    54,    -1,    -1,    -1,
      22,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    34,    -1,    53,    54,    55,    56,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    53,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    58,    59,    60,    61,
      54,    54,     0,    60,     1,     6,    52,    62,    63,    62,
      54,    54,    54,    16,    16,    62,    62,     7,     8,     9,
      10,    11,    20,    21,    54,    61,    64,    65,    66,    67,
      75,    76,    77,    78,    79,    80,    64,    16,    16,    54,
      54,    61,    67,    78,    79,    81,    14,    67,    76,    17,
      65,    54,    68,    17,    64,    64,    14,    81,    54,     1,
      63,    67,    73,    74,    68,    14,     1,    13,    18,    19,
      69,    17,    17,     1,    73,    15,    54,    15,    18,    69,
       1,    73,     1,    12,    14,    22,    34,    40,    48,    53,
      54,    55,    56,    70,    82,    84,    91,    93,    54,    15,
      15,    16,    16,    67,    15,    15,    19,    54,    91,    35,
      91,    93,    14,    35,     1,    19,    14,    63,    85,    38,
      39,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    91,    92,    16,    16,     1,    23,    25,    30,    31,
      32,    51,    54,    61,    66,    67,    82,    86,    87,    90,
     123,   128,   133,   134,   135,   136,   137,     1,   136,    54,
      16,    16,    14,    15,    54,    83,    48,    63,    71,    72,
      91,    83,    71,    91,    91,    93,    93,    93,    93,    93,
     136,     1,   136,    69,    14,    14,    14,    16,    14,     1,
      19,    14,    36,    37,    69,    88,    89,    67,    54,    69,
      88,    89,     1,    19,    17,   137,    17,    17,    23,    25,
      30,    31,    32,    51,    66,    86,    87,    90,    94,    99,
     104,   105,   108,   109,   110,     1,   109,    71,    35,    93,
      15,    18,    15,    17,    17,    17,     1,    91,     1,    91,
       1,    91,     1,    23,    25,    28,    33,    51,    66,    86,
      87,    90,   133,   134,   135,   138,   139,   140,   145,    54,
      66,    82,    86,   106,    71,     1,    19,     1,    19,    14,
      14,    14,    16,    14,     1,    91,     1,    19,    17,   110,
      17,    17,    15,    54,    91,    15,    15,    15,    15,    15,
      15,    17,    14,    14,     1,    19,     1,    19,     1,    19,
       1,    19,    17,   139,    91,    15,     1,    91,     1,    91,
       1,    91,     1,    23,    25,    28,    33,    51,    66,    86,
      87,    90,   104,   105,   108,   111,   112,   113,   118,   106,
      19,     1,    19,    16,    16,    16,    16,    16,    16,    30,
       1,    91,     1,    91,    30,     1,    19,    15,    15,    15,
      15,    15,    15,    17,    14,    14,     1,    19,     1,    19,
      91,     1,    19,    17,   112,    91,   136,     1,   136,    26,
     129,   130,   132,     1,   132,   138,     1,   138,    14,    15,
      15,    15,    15,    14,    54,    82,    87,   107,   107,    16,
      16,    16,    16,    16,    16,    30,     1,    91,     1,    91,
       1,    19,    30,     1,    19,    17,    17,    17,    93,    29,
     129,   131,    17,    17,    17,    17,    17,    17,    91,    16,
      16,    16,    16,     1,    91,    13,    15,    15,   109,     1,
     109,    26,   100,   101,   103,     1,   103,   111,     1,   111,
      14,    15,    15,    15,    15,    14,   107,   107,    24,    63,
     124,   125,   126,   127,   124,   124,    27,    27,    15,   138,
       1,   138,    26,   146,   147,   149,     1,   149,    15,    15,
      70,    16,    16,    17,    17,    17,    93,    29,   100,   102,
      17,    17,    17,    17,    17,    17,    91,    16,    16,    16,
      16,     1,    91,    15,    15,    16,    23,   126,   127,     1,
     136,     1,   136,    19,    17,    17,    17,    93,    29,   146,
     148,    17,    17,    17,    19,     1,    19,   138,     1,   138,
      24,    63,    95,    96,    97,    98,    95,    95,    27,    27,
      15,   111,     1,   111,    26,   119,   120,   122,     1,   122,
      15,    15,    16,    16,     1,   136,    14,    28,    28,    28,
      28,    24,    63,   141,   142,   143,   144,   141,   141,    27,
      27,    17,    17,    17,    16,    23,    97,    98,     1,   109,
       1,   109,    19,    17,    17,    17,    93,    29,   119,   121,
      17,    17,    17,    19,     1,    19,   109,     1,   111,    17,
      17,     1,    91,    19,     1,    19,    19,     1,    19,    16,
      23,   143,   144,     1,   138,     1,   138,     1,   109,    14,
      28,    28,    28,    28,    24,    63,   114,   115,   116,   117,
     114,   114,    27,    27,    17,    17,    17,    15,    15,     1,
     138,    14,    28,    28,    28,    28,    17,    17,     1,    91,
      19,     1,    19,    19,     1,    19,    16,    23,   116,   117,
       1,   111,     1,   111,    16,    16,    17,    17,     1,    91,
      19,     1,    19,    19,     1,    19,    15,    15,     1,   111,
      14,    28,    28,    28,    28,   136,     1,   136,    15,    15,
      16,    16,    17,    17,     1,    91,    19,     1,    19,    19,
       1,    19,    17,    17,    17,    16,    16,   109,     1,   109,
      15,    15,   138,     1,   138,    17,    17,    17,    16,    16,
      17,    17,    17,   111,     1,   111,    17,    17,    17
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 253 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("S","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 260 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CLS","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 265 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CLS","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 272 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
					
					//cout<<"cls: "<<$4->fila<<endl;

					InfoCls* nClase = new InfoCls();
					nClase->metodos = metodos;
					nClase->funciones = funciones;
					nClase->atributos = atributos;
					nClase->constructores = constructores;
					nClase->overrides = overrides;
					nClase->id = (yyvsp[(3) - (7)].cadena);
					if((yyvsp[(4) - (7)].NODO)->token=="EXT")
						nClase->extendss = (yyvsp[(4) - (7)].NODO)->hijos.at(1)->lexema;
					nClase->fila = (yyvsp[(4) - (7)].NODO)->fila;
					clases.append(nClase);
					limpiarClss();
				}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 292 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
					
					//cout<<"cls: "<<$3->fila<<endl;

					InfoCls* nClase = new InfoCls();
					nClase->metodos = metodos;
					nClase->funciones = funciones;
					nClase->atributos = atributos;
					nClase->constructores = constructores;
					nClase->overrides = overrides;
					nClase->id = (yyvsp[(2) - (6)].cadena);
					if((yyvsp[(3) - (6)].NODO)->token=="EXT")
						nClase->extendss = (yyvsp[(3) - (6)].NODO)->hijos.at(1)->lexema;
					nClase->fila = (yyvsp[(3) - (6)].NODO)->fila;
					clases.append(nClase);
					limpiarClss();
				}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 312 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;					
				}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 317 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;					
				}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 324 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("tknPublic","+",yyfila,yycolumna);					
					(yyval.NODO) = nPadre;
				}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 329 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("tknPrivate","-",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 334 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("tknProtected","#",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 341 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXT","",yyfila,yycolumna);
					Nodo* tknExtends = new Nodo("tknExtends",(yyvsp[(1) - (2)].cadena),yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",(yyvsp[(2) - (2)].cadena),yyfila,yycolumna);
					nPadre->addHijo(tknExtends);
					nPadre->addHijo(tknId);
					(yyval.NODO) = nPadre;
				}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 350 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EPS","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 356 "Sintactico.y"
    {}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 361 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CUERPO_CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 366 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CUERPO_CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 373 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;

					if(varGlobal->tipo.empty()){//constructor						
						constructores.append(varGlobal);
					}else if(varGlobal->tipo=="void"){//metodo						
						metodos.append(varGlobal);
					}else{//funcion						
						funciones.append(varGlobal);
					}
				}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 386 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CL","",yyfila,yycolumna);					
					(yyval.NODO) = nPadre;

					string acceso = "+";
					string tipo = "int";
					if((yyvsp[(1) - (1)].NODO)->hijos.size()>3){//trae su acceso
						acceso = (yyvsp[(1) - (1)].NODO)->hijos.at(0)->lexema;
						tipo = (yyvsp[(1) - (1)].NODO)->hijos.at(1)->lexema;
						bool bandera = true;
						Nodo* temp = (yyvsp[(1) - (1)].NODO)->hijos.at(2);
						while(bandera){
							Gnrc* atributo = new Gnrc();
							atributo->tipo = tipo;
							atributo->visibilidad = acceso;							
							if(temp->hijos.size()==1){
								atributo->id = temp->hijos.at(0)->lexema;	
								atributo->fila = temp->hijos.at(0)->fila;								
								bandera = false;
							}else{
								atributo->id = temp->hijos.at(2)->lexema;							
								atributo->fila = temp->hijos.at(2)->fila;
							}							
							atributos.append(atributo);							
							temp = temp->hijos.at(0);
						}
					}else{//es publico
						tipo = (yyvsp[(1) - (1)].NODO)->hijos.at(0)->lexema;
						bool bandera = true;
						Nodo* temp = (yyvsp[(1) - (1)].NODO)->hijos.at(1);
						while(bandera){
							Gnrc* atributo = new Gnrc();
							atributo->tipo = tipo;
							atributo->visibilidad = acceso;							
							if(temp->hijos.size()==1){
								atributo->id = temp->hijos.at(0)->lexema;
								atributo->fila = temp->hijos.at(0)->fila;								
								bandera = false;
							}else{
								atributo->id = temp->hijos.at(2)->lexema;							
								atributo->fila = temp->hijos.at(2)->fila;
							}
							atributos.append(atributo);							
							temp = temp->hijos.at(0);
						}
					}
				}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 434 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
					overrides.append(varGlobal);
					//cout<<"override "<<varGlobal->visibilidad<<" "<<varGlobal->tipo<<" "<<varGlobal->id<<endl;
				}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 443 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DECL","",yyfila,yycolumna);
					nPadre->addHijo((yyvsp[(1) - (4)].NODO));
					nPadre->addHijo((yyvsp[(2) - (4)].NODO));
					nPadre->addHijo((yyvsp[(3) - (4)].NODO));
					nPadre->addHijo((yyvsp[(4) - (4)].NODO));
					(yyval.NODO) = nPadre;
				}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 452 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DECL","",yyfila,yycolumna);
					nPadre->addHijo((yyvsp[(1) - (3)].NODO));
					nPadre->addHijo((yyvsp[(2) - (3)].NODO));
					nPadre->addHijo((yyvsp[(3) - (3)].NODO));
					(yyval.NODO) = nPadre;
				}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 462 "Sintactico.y"
    {					
					Nodo* tknTipo = new Nodo("tknTipo",(yyvsp[(1) - (1)].cadena),yyfila,yycolumna);
					(yyval.NODO) = tknTipo;					
				}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 467 "Sintactico.y"
    {					
					Nodo* tknTipo = new Nodo("tknTipo",(yyvsp[(1) - (1)].cadena),yyfila,yycolumna);
					(yyval.NODO) = tknTipo;
				}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 473 "Sintactico.y"
    {					
					Nodo* tknTipo = new Nodo("tknTipo",(yyvsp[(1) - (1)].cadena),yyfila,yycolumna);
					(yyval.NODO) = tknTipo;
				}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 479 "Sintactico.y"
    {					
					Nodo* tknTipo = new Nodo("tknTipo",(yyvsp[(1) - (1)].cadena),yyfila,yycolumna);
					(yyval.NODO) = tknTipo;
				}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 485 "Sintactico.y"
    {					
					Nodo* tknTipo = new Nodo("tknTipo",(yyvsp[(1) - (1)].cadena),yyfila,yycolumna);
					(yyval.NODO) = tknTipo;
				}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 491 "Sintactico.y"
    {					
					Nodo* tknTipo = new Nodo("tknTipo",(yyvsp[(1) - (1)].cadena),yyfila,yycolumna);
					(yyval.NODO) = tknTipo;										
				}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 498 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_ID","",yyfila,yycolumna);
					Nodo* tknComa = new Nodo("tknComa",(yyvsp[(2) - (3)].cadena),yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",(yyvsp[(3) - (3)].cadena),yyfila,yycolumna);
					nPadre->addHijo((yyvsp[(1) - (3)].NODO));
					nPadre->addHijo(tknComa);
					nPadre->addHijo(tknId);
					(yyval.NODO) = nPadre;
				}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 508 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_ID","",yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",(yyvsp[(1) - (1)].cadena),yyfila,yycolumna);
					nPadre->addHijo(tknId);
					(yyval.NODO) = nPadre;
				}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 517 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 522 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 527 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 532 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 537 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 544 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_EXP","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 549 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_EXP","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 556 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PARAMETROS_1","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 561 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PARAMETROS_1","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 568 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_PARAM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 573 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_PARAM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 580 "Sintactico.y"
    {					
					(yyval.NODO) = (yyvsp[(1) - (1)].NODO);
				}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 584 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EPS","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 591 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_PARAM_2","",yyfila,yycolumna);
					nPadre->addHijo((yyvsp[(1) - (4)].NODO));//mas id's
					nPadre->addHijo((yyvsp[(3) - (4)].NODO));//tipo nuevo id
					Nodo* id = new Nodo("tknId",(yyvsp[(4) - (4)].cadena),yyfila,yycolumna);
					nPadre->addHijo(id);
					(yyval.NODO) = nPadre;
				}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 600 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_PARAM_2","",yyfila,yycolumna);
					nPadre->addHijo((yyvsp[(1) - (2)].NODO));//tipo
					Nodo* id = new Nodo("tknId",(yyvsp[(2) - (2)].cadena),yyfila,yycolumna);
					nPadre->addHijo(id);
					(yyval.NODO) = nPadre;
				}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 610 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CAJAS","",yyfila,yycolumna);
					nPadre->addHijo((yyvsp[(1) - (2)].NODO));
					nPadre->addHijo((yyvsp[(2) - (2)].NODO));
					(yyval.NODO) = nPadre;

					Gnrc* nuevo = new Gnrc();
					nuevo->visibilidad = (yyvsp[(1) - (2)].NODO)->lexema;
					if((yyvsp[(2) - (2)].NODO)->token=="CONSTRUCTOR"){//es  CONSTRUCTOR
						nuevo->id = (yyvsp[(2) - (2)].NODO)->hijos.at(0)->lexema;
						if((yyvsp[(2) - (2)].NODO)->hijos.at(2)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = (yyvsp[(2) - (2)].NODO)->hijos.at(2);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}						
						//constructores.append(nuevo);
						nuevo->fila = (yyvsp[(2) - (2)].NODO)->hijos.at(0)->fila;
						varGlobal = nuevo;
						/*cout<<nuevo->id<<endl;					
						for(int a=0;a<nuevo->parametros.size();a++){
							cout<<nuevo->parametros.at(a)->tipo<<" "<<nuevo->parametros.at(a)->id<<endl;
						}*/
					}else{//es FUNCION o METODO
						nuevo->tipo = (yyvsp[(2) - (2)].NODO)->hijos.at(0)->lexema;
						nuevo->id = (yyvsp[(2) - (2)].NODO)->hijos.at(1)->lexema;
						if((yyvsp[(2) - (2)].NODO)->hijos.at(3)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = (yyvsp[(2) - (2)].NODO)->hijos.at(3);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}
						/*if($2->token=="FUNC"){//es FUNCION
							funciones.append(nuevo);
						}else{
							metodos.append(nuevo);
						}*/		
						nuevo->fila = (yyvsp[(2) - (2)].NODO)->hijos.at(1)->fila;
						varGlobal = nuevo;										
					}
				}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 678 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CAJAS","",yyfila,yycolumna);					
					nPadre->addHijo((yyvsp[(1) - (1)].NODO));
					(yyval.NODO) = nPadre;

					Gnrc* nuevo = new Gnrc();
					if((yyvsp[(1) - (1)].NODO)->token=="CONSTRUCTOR"){
						nuevo->id = (yyvsp[(1) - (1)].NODO)->hijos.at(0)->lexema;
						if((yyvsp[(1) - (1)].NODO)->hijos.at(2)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = (yyvsp[(1) - (1)].NODO)->hijos.at(2);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}						
						//constructores.append(nuevo);
						nuevo->fila = (yyvsp[(1) - (1)].NODO)->hijos.at(0)->fila;
						varGlobal = nuevo;
					}else{
						nuevo->tipo = (yyvsp[(1) - (1)].NODO)->hijos.at(0)->lexema;
						nuevo->id = (yyvsp[(1) - (1)].NODO)->hijos.at(1)->lexema;
						if((yyvsp[(1) - (1)].NODO)->hijos.at(3)->token!="EPS"){//si hay parametros
							bool bandera = true;
							Nodo* temp = (yyvsp[(1) - (1)].NODO)->hijos.at(3);
							while(bandera){
								if(temp->hijos.size()>2){
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(1)->lexema;
									parametro->id = temp->hijos.at(2)->lexema;
									nuevo->parametros.push_front(parametro);
								}else{
									Gnrc* parametro = new Gnrc();
									parametro->tipo = temp->hijos.at(0)->lexema;
									parametro->id = temp->hijos.at(1)->lexema;
									nuevo->parametros.push_front(parametro);
									bandera = false;
								}		
								temp = temp->hijos.at(0);						
							}
						}
						/*if($1->token=="FUNC"){//es FUNCION
							funciones.append(nuevo);
						}else{
							metodos.append(nuevo);
						}*/
						nuevo->fila = (yyvsp[(1) - (1)].NODO)->hijos.at(1)->fila;
						varGlobal = nuevo;
					}
				}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 742 "Sintactico.y"
    {
					(yyval.NODO) = (yyvsp[(1) - (1)].NODO);
				}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 746 "Sintactico.y"
    {					
					(yyval.NODO) = (yyvsp[(1) - (1)].NODO);
				}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 750 "Sintactico.y"
    {
					(yyval.NODO) = (yyvsp[(1) - (1)].NODO);
				}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 756 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CONSTRUCTOR","",yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",(yyvsp[(1) - (7)].cadena),yyfila,yycolumna);					
					Nodo* tknParA = new Nodo("tknParA",(yyvsp[(2) - (7)].cadena),yyfila,yycolumna);										
					Nodo* tknParC = new Nodo("tknParC",(yyvsp[(4) - (7)].cadena),yyfila,yycolumna);					
					Nodo* tknLlaveA = new Nodo("tknLlaveA",(yyvsp[(5) - (7)].cadena),yyfila,yycolumna);										
					Nodo* tknLlaveC = new Nodo("tknLlaveC",(yyvsp[(7) - (7)].cadena),yyfila,yycolumna);					
					nPadre->addHijo(tknId);
					nPadre->addHijo(tknParA);	
					nPadre->addHijo((yyvsp[(3) - (7)].NODO));
					nPadre->addHijo(tknParC);
					nPadre->addHijo(tknLlaveA);
					nPadre->addHijo((yyvsp[(6) - (7)].NODO));
					nPadre->addHijo(tknLlaveC);
					(yyval.NODO) = nPadre;
				}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 773 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CONSTRUCTOR","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 778 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CONSTRUCTOR","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 785 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FUNC","",yyfila,yycolumna);					
					Nodo* tknId = new Nodo("tknId",(yyvsp[(2) - (8)].cadena),yyfila,yycolumna);					
					Nodo* tknParA = new Nodo("tknParA",(yyvsp[(3) - (8)].cadena),yyfila,yycolumna);										
					Nodo* tknParC = new Nodo("tknParC",(yyvsp[(5) - (8)].cadena),yyfila,yycolumna);					
					Nodo* tknLlaveA = new Nodo("tknLlaveA",(yyvsp[(6) - (8)].cadena),yyfila,yycolumna);										
					Nodo* tknLlaveC = new Nodo("tknLlaveC",(yyvsp[(8) - (8)].cadena),yyfila,yycolumna);
					nPadre->addHijo((yyvsp[(1) - (8)].NODO));
					nPadre->addHijo(tknId);
					nPadre->addHijo(tknParA);	
					nPadre->addHijo((yyvsp[(4) - (8)].NODO));
					nPadre->addHijo(tknParC);
					nPadre->addHijo(tknLlaveA);
					nPadre->addHijo((yyvsp[(7) - (8)].NODO));
					nPadre->addHijo(tknLlaveC);
					(yyval.NODO) = nPadre;					
				}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 803 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FUNC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 808 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FUNC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 815 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("MET","",yyfila,yycolumna);
					Nodo* tknVoid = new Nodo("tknVoid",(yyvsp[(1) - (8)].cadena),yyfila,yycolumna);
					Nodo* tknId = new Nodo("tknId",(yyvsp[(2) - (8)].cadena),yyfila,yycolumna);					
					Nodo* tknParA = new Nodo("tknParA",(yyvsp[(3) - (8)].cadena),yyfila,yycolumna);										
					Nodo* tknParC = new Nodo("tknParC",(yyvsp[(5) - (8)].cadena),yyfila,yycolumna);					
					Nodo* tknLlaveA = new Nodo("tknLlaveA",(yyvsp[(6) - (8)].cadena),yyfila,yycolumna);										
					Nodo* tknLlaveC = new Nodo("tknLlaveC",(yyvsp[(8) - (8)].cadena),yyfila,yycolumna);
					nPadre->addHijo(tknVoid);
					nPadre->addHijo(tknId);
					nPadre->addHijo(tknParA);	
					nPadre->addHijo((yyvsp[(4) - (8)].NODO));
					nPadre->addHijo(tknParC);
					nPadre->addHijo(tknLlaveA);
					nPadre->addHijo((yyvsp[(7) - (8)].NODO));
					nPadre->addHijo(tknLlaveC);
					(yyval.NODO) = nPadre;					
				}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 834 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("MET","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 839 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("MET","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 846 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SOBRESC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
					
					//cout<<$2->fila<<endl;
					Gnrc* nuevo = new Gnrc();
					nuevo->visibilidad = (yyvsp[(2) - (3)].NODO)->lexema;
					nuevo->tipo = (yyvsp[(3) - (3)].NODO)->hijos.at(0)->lexema;
					nuevo->id = (yyvsp[(3) - (3)].NODO)->hijos.at(1)->lexema;
					if((yyvsp[(3) - (3)].NODO)->hijos.at(3)->token!="EPS"){//si hay parametros
						bool bandera = true;
						Nodo* temp = (yyvsp[(3) - (3)].NODO)->hijos.at(3);
						while(bandera){
							if(temp->hijos.size()>2){
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(1)->lexema;
								parametro->id = temp->hijos.at(2)->lexema;
								nuevo->parametros.push_front(parametro);
							}else{
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(0)->lexema;
								parametro->id = temp->hijos.at(1)->lexema;
								nuevo->parametros.push_front(parametro);
								bandera = false;
							}		
							temp = temp->hijos.at(0);						
						}
					}
					/*if($1->token=="FUNC"){//es FUNCION
						funciones.append(nuevo);
					}else{
						metodos.append(nuevo);
					}*/
					nuevo->fila = (yyvsp[(2) - (3)].NODO)->fila;
					varGlobal = nuevo;					
				}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 883 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SOBRESC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;

					Gnrc* nuevo = new Gnrc();
					nuevo->visibilidad = "+";
					nuevo->tipo = (yyvsp[(2) - (2)].NODO)->hijos.at(0)->lexema;
					nuevo->id = (yyvsp[(2) - (2)].NODO)->hijos.at(1)->lexema;
					if((yyvsp[(2) - (2)].NODO)->hijos.at(3)->token!="EPS"){//si hay parametros
						bool bandera = true;
						Nodo* temp = (yyvsp[(2) - (2)].NODO)->hijos.at(3);
						while(bandera){
							if(temp->hijos.size()>2){
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(1)->lexema;
								parametro->id = temp->hijos.at(2)->lexema;
								nuevo->parametros.push_front(parametro);
							}else{
								Gnrc* parametro = new Gnrc();
								parametro->tipo = temp->hijos.at(0)->lexema;
								parametro->id = temp->hijos.at(1)->lexema;
								nuevo->parametros.push_front(parametro);
								bandera = false;
							}		
							temp = temp->hijos.at(0);						
						}
					}
					nuevo->fila = (yyvsp[(2) - (2)].NODO)->hijos.at(0)->fila;
					varGlobal = nuevo;					
				}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 916 "Sintactico.y"
    {
					//Nodo* nPadre = new Nodo("OPC_SOBRESC","",yyfila,yycolumna);
					(yyval.NODO) = (yyvsp[(1) - (1)].NODO);
				}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 921 "Sintactico.y"
    {
					//Nodo* nPadre = new Nodo("OPC_SOBRESC","",yyfila,yycolumna);
					(yyval.NODO) = (yyvsp[(1) - (1)].NODO);
				}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 928 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_OBJ","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 933 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_OBJ","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 940 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_ACC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 945 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_ACC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 952 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ACC_OBJ","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 959 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_ACC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 964 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_ACC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 971 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;					
				}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 976 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;					
				}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 981 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;					
				}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 988 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("INC_DEC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 993 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("INC_DEC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 1000 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_INCDEC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 1005 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_INCDEC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 1012 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_LLAMADA","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 1019 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LLAMADA","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 1024 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LLAMADA","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 1029 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 1034 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEC_ASIGN","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 1042 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 1047 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 1052 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 1057 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 1062 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 1067 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 1072 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("EXPRESION","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 1079 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 1084 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 1089 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 1094 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1099 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1104 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("REL","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1111 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1116 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 1121 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1126 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1131 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1136 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1141 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1146 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1151 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1156 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1161 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1166 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("ART","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 1178 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 1183 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 1188 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 1195 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 1200 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 1207 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 1212 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 1219 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 1224 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1229 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1236 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1241 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1246 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1253 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1258 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1263 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1270 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1275 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1280 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1287 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 1292 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 1299 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 1304 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1309 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 1316 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_SWITCHF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 1323 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("WHILEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1328 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("WHILEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1333 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("WHILEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1340 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1345 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1350 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1355 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1362 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_FOR1","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1367 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_FOR1","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1374 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_FOR2","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 1379 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_FOR2","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1386 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FORF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1391 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FORF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1396 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FORF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1403 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1408 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1415 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1420 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1425 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1430 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1435 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1440 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1445 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1450 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1455 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1460 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1465 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1470 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1475 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_F","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1483 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1488 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1495 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1500 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1505 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1510 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1515 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1520 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1525 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1530 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1535 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1540 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1545 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1550 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1555 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1560 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1565 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1570 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOF","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1577 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1582 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1587 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1594 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1599 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1606 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1611 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1618 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1623 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1628 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1635 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1640 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1645 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1652 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1657 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1662 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1669 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1674 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1679 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1686 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1691 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1698 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 1703 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 1708 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 1715 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_SWITCHFC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 1726 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 1731 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 1736 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 1743 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 1748 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 1755 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 1760 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 1767 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 1772 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 1777 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 1784 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 1789 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 1794 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 1801 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 1806 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1811 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1818 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1823 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1828 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1835 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1840 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1847 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1852 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1857 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1864 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_SWITCHM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1871 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("WHILEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1876 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("WHILEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1881 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("WHILEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1888 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1893 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1898 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 1903 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DO_WHILEM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1910 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FORM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 1915 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FORM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1920 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FORM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1927 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 1932 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 241:
/* Line 1792 of yacc.c  */
#line 1939 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 1944 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 1949 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 1954 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 1959 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 1964 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 1969 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 248:
/* Line 1792 of yacc.c  */
#line 1974 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 1979 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 1984 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 1989 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 1994 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_M","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 2002 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 2007 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("PRE_CUERPOMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 2014 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 256:
/* Line 1792 of yacc.c  */
#line 2019 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 257:
/* Line 1792 of yacc.c  */
#line 2024 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 258:
/* Line 1792 of yacc.c  */
#line 2029 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 259:
/* Line 1792 of yacc.c  */
#line 2034 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 260:
/* Line 1792 of yacc.c  */
#line 2039 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 2044 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 262:
/* Line 1792 of yacc.c  */
#line 2049 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 263:
/* Line 1792 of yacc.c  */
#line 2054 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 264:
/* Line 1792 of yacc.c  */
#line 2059 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 265:
/* Line 1792 of yacc.c  */
#line 2064 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 266:
/* Line 1792 of yacc.c  */
#line 2069 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 2074 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 268:
/* Line 1792 of yacc.c  */
#line 2079 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 269:
/* Line 1792 of yacc.c  */
#line 2084 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 270:
/* Line 1792 of yacc.c  */
#line 2089 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_CICLOM","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 271:
/* Line 1792 of yacc.c  */
#line 2099 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 2104 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 273:
/* Line 1792 of yacc.c  */
#line 2109 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 274:
/* Line 1792 of yacc.c  */
#line 2116 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 2121 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("OPC_IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 276:
/* Line 1792 of yacc.c  */
#line 2128 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 2133 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 2140 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 279:
/* Line 1792 of yacc.c  */
#line 2145 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 2150 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("IF_ELSEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 2157 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 282:
/* Line 1792 of yacc.c  */
#line 2162 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 2167 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("FIN_IFMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 2174 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 2179 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 286:
/* Line 1792 of yacc.c  */
#line 2184 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("SWITCHMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 287:
/* Line 1792 of yacc.c  */
#line 2191 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 288:
/* Line 1792 of yacc.c  */
#line 2196 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 289:
/* Line 1792 of yacc.c  */
#line 2201 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CASEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 290:
/* Line 1792 of yacc.c  */
#line 2208 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 291:
/* Line 1792 of yacc.c  */
#line 2213 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("LST_CASEMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 2220 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 2225 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 2230 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("DEFAULTMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 2237 "Sintactico.y"
    {
					Nodo* nPadre = new Nodo("CUERPO_SWITCHMC","",yyfila,yycolumna);
					(yyval.NODO) = nPadre;
				}
    break;


/* Line 1792 of yacc.c  */
#line 5822 "Sintactico.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 2243 "Sintactico.y"


