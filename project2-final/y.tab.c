/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

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
#line 1 "parser.y"

#include<stdio.h>

/* Line 371 of yacc.c  */
#line 72 "y.tab.c"

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
     NUMBER = 258,
     ID = 259,
     QUOTE = 260,
     OPENCARROT = 261,
     CLOSECARROT = 262,
     OPENING = 263,
     CLOSING = 264,
     VAR = 265,
     EQUAL = 266,
     PLUS = 267,
     MINUS = 268,
     MULTIPLY = 269,
     DIVIDE = 270,
     OPENPAR = 271,
     CLOSEPAR = 272,
     WRITE = 273,
     NEWLINE = 274,
     SEMICOLON = 275,
     COMMA = 276,
     DOCUMENT = 277,
     OPENCURLY = 278,
     CLOSECURLY = 279,
     COLON = 280,
     DOT = 281,
     PRINTNEWLINE = 282
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define QUOTE 260
#define OPENCARROT 261
#define CLOSECARROT 262
#define OPENING 263
#define CLOSING 264
#define VAR 265
#define EQUAL 266
#define PLUS 267
#define MINUS 268
#define MULTIPLY 269
#define DIVIDE 270
#define OPENPAR 271
#define CLOSEPAR 272
#define WRITE 273
#define NEWLINE 274
#define SEMICOLON 275
#define COMMA 276
#define DOCUMENT 277
#define OPENCURLY 278
#define CLOSECURLY 279
#define COLON 280
#define DOT 281
#define PRINTNEWLINE 282



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "parser.y"

	char *string_val;
	int number_val;
	struct var_node *node_val;


/* Line 387 of yacc.c  */
#line 176 "y.tab.c"
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
/* Line 390 of yacc.c  */
#line 24 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yydebug = 1;
int lineno = 1;

enum NODE_TYPE
{
	NUMBER_NODE,
	OP_NODE,
	EMPTY_NODE,
	EMPTY_FIELD_NODE,
	FIELD_NODE,
	OBJECT_NODE,
	QUOTE_NODE,
	NEWLINE_NODE
};

struct var_node
{
	int declared;
	int initialized;

	enum NODE_TYPE type;
	char *id;

	int number;
	char *quote;
	char op;

	struct var_node * next;
};

struct var_node* find_variable(char *id);
struct var_node* find_variable_declare(char *id);
struct var_node* find_field(struct var_node* node, char *id);
void replace_variable(struct var_node *originalNode, struct var_node *newNode);
void make_variable(struct var_node * newNode);
void print_error();
void print_debug(char *s);

struct var_node *variables[50][100];
int numInst = 0;
int numVars[50];



/* Line 390 of yacc.c  */
#line 254 "y.tab.c"

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   87

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    10,    15,    17,    18,    22,    24,
      25,    27,    30,    33,    36,    37,    40,    41,    44,    45,
      48,    51,    52,    57,    59,    65,    68,    70,    74,    75,
      78,    81,    82,    84,    90,    93,    97,    98,   102,   105,
     106,   110,   114,   118,   120,   122,   125,   129,   133,   134,
     137,   141,   145,   146,   148,   152,   154,   156,   160,   162,
     164,   165,   169
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    -1,    31,    30,    32,    53,    63,    -1,
       6,     8,     5,     7,    -1,    37,    -1,    -1,    19,    33,
      34,    -1,    35,    -1,    -1,    36,    -1,    36,    35,    -1,
      37,    19,    -1,    40,    38,    -1,    -1,    20,    39,    -1,
      -1,    40,    38,    -1,    -1,    22,    42,    -1,    10,    46,
      -1,    -1,    23,    41,    32,    24,    -1,    54,    -1,    26,
      18,    16,    43,    17,    -1,    44,    45,    -1,    56,    -1,
      21,    44,    45,    -1,    -1,     4,    47,    -1,    11,    48,
      -1,    -1,    56,    -1,    23,    19,    49,    19,    24,    -1,
      51,    50,    -1,    21,    51,    50,    -1,    -1,    63,     4,
      52,    -1,    25,    56,    -1,    -1,     6,     9,     7,    -1,
      55,    11,    56,    -1,     4,    26,     4,    -1,     4,    -1,
      57,    -1,    59,    58,    -1,    12,    59,    58,    -1,    13,
      59,    58,    -1,    -1,    61,    60,    -1,    14,    61,    60,
      -1,    15,    61,    60,    -1,    -1,    62,    -1,    16,    56,
      17,    -1,     3,    -1,     5,    -1,     4,    26,     4,    -1,
       4,    -1,    27,    -1,    -1,    19,    64,    63,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    77,    83,    87,    89,    89,    95,    96,
     101,   103,   107,   113,   114,   119,   120,   125,   126,   131,
     133,   135,   135,   141,   145,   149,   153,   171,   172,   177,
     198,   202,   210,   214,   221,   241,   254,   262,   270,   279,
     287,   291,   343,   353,   359,   365,   401,   449,   487,   495,
     529,   573,   614,   622,   626,   632,   639,   647,   677,   701,
     709,   709,   712
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "QUOTE", "OPENCARROT",
  "CLOSECARROT", "OPENING", "CLOSING", "VAR", "EQUAL", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "OPENPAR", "CLOSEPAR", "WRITE", "NEWLINE",
  "SEMICOLON", "COMMA", "DOCUMENT", "OPENCURLY", "CLOSECURLY", "COLON",
  "DOT", "PRINTNEWLINE", "$accept", "program", "$@1", "opening", "middle",
  "$@2", "middle_tail", "lines", "line", "statements", "statement_tail",
  "statement_tail_tail", "statement", "$@3", "write", "param_list",
  "param", "param_tail", "declare", "declare_tail", "declare_tail_tail",
  "fields", "fields_tail", "field", "field_tail", "closing", "assign",
  "id_list", "expression", "pm_expr", "pm_expr_tail", "dm_expr",
  "dm_expr_tail", "sub_dm", "base_value", "ending", "$@4", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    30,    29,    31,    32,    33,    32,    34,    34,
      35,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      40,    41,    40,    40,    42,    43,    44,    45,    45,    46,
      47,    47,    48,    48,    49,    50,    50,    51,    52,    52,
      53,    54,    55,    55,    56,    57,    58,    58,    58,    59,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      64,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     4,     1,     0,     3,     1,     0,
       1,     2,     2,     2,     0,     2,     0,     2,     0,     2,
       2,     0,     4,     1,     5,     2,     1,     3,     0,     2,
       2,     0,     1,     5,     2,     3,     0,     3,     2,     0,
       3,     3,     3,     1,     1,     2,     3,     3,     0,     2,
       3,     3,     0,     1,     3,     1,     1,     3,     1,     1,
       0,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,    14,     0,    43,     0,
       6,     0,    21,     0,     5,    16,    23,     0,     4,     0,
      31,    20,     9,     0,    19,    14,     0,    62,    18,    13,
       0,    42,     0,    29,     7,     8,    10,     0,     0,     0,
       0,    60,     3,    15,    16,    55,    58,    56,     0,    59,
      41,    44,    48,    52,    53,     0,    30,    32,    11,    12,
       0,    22,    40,    62,    17,     0,     0,     0,     0,    45,
       0,     0,    49,    62,     0,    28,    26,    61,    57,    54,
      48,    48,    52,    52,     0,    36,     0,    24,     0,    25,
      46,    47,    50,    51,     0,    62,    34,    39,    28,    33,
      36,     0,    37,    27,    35,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     3,    13,    22,    34,    35,    36,    14,
      29,    43,    15,    25,    24,    74,    75,    89,    21,    33,
      56,    84,    96,    85,   102,    27,    16,    17,    76,    51,
      69,    52,    72,    53,    54,    86,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -46
static const yytype_int8 yypact[] =
{
       9,     1,    13,   -46,    12,   -46,    10,    19,    25,    41,
     -46,    26,   -46,    44,   -46,    33,   -46,    43,   -46,    51,
      45,   -46,    21,    39,   -46,    10,    49,    40,    24,   -46,
       3,   -46,     0,   -46,   -46,   -46,    21,    42,    46,    36,
      56,   -46,   -46,   -46,    33,   -46,    38,   -46,     3,   -46,
     -46,   -46,    -1,     7,   -46,    47,   -46,   -46,   -46,   -46,
       3,   -46,   -46,    40,   -46,    61,    50,     3,     3,   -46,
       3,     3,   -46,    40,    52,    53,   -46,   -46,   -46,   -46,
      -1,    -1,     7,     7,    54,    55,    64,   -46,     3,   -46,
     -46,   -46,   -46,   -46,    48,    40,   -46,    57,    53,   -46,
      55,     3,   -46,   -46,   -46,   -46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -46,    58,   -46,   -46,    34,   -46,   -12,
      31,   -46,    59,   -46,   -46,   -46,   -11,   -20,   -46,   -46,
     -46,   -46,   -21,   -15,   -46,   -46,   -46,   -46,   -30,   -46,
     -45,   -29,   -41,   -22,   -46,   -26,   -46
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int8 yytable[] =
{
      50,    42,    57,    45,    46,    47,    45,    46,    47,     4,
      37,    67,    68,     5,     8,     1,    48,     7,    66,    48,
       9,    70,    71,    55,    37,     8,    18,    49,     8,    10,
      49,     9,    11,    12,     9,    90,    91,    77,    80,    81,
     -14,    92,    93,    11,    12,    20,    11,    12,    82,    83,
      26,    19,    23,    28,    30,    31,    32,    38,    40,    41,
      61,    59,    60,    62,    65,    78,    73,    79,    97,    87,
      58,   105,    99,    94,    88,    64,    95,    98,   103,   104,
     100,     0,   101,    39,     0,     0,     0,    44
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      30,    27,    32,     3,     4,     5,     3,     4,     5,     8,
      22,    12,    13,     0,     4,     6,    16,     5,    48,    16,
      10,    14,    15,    23,    36,     4,     7,    27,     4,    19,
      27,    10,    22,    23,    10,    80,    81,    63,    67,    68,
      19,    82,    83,    22,    23,     4,    22,    23,    70,    71,
       6,    26,    26,    20,    11,     4,    11,    18,     9,    19,
      24,    19,    16,     7,    26,     4,    19,    17,     4,    17,
      36,   101,    24,    19,    21,    44,    21,    88,    98,   100,
      95,    -1,    25,    25,    -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    29,    31,     8,     0,    30,     5,     4,    10,
      19,    22,    23,    32,    37,    40,    54,    55,     7,    26,
       4,    46,    33,    26,    42,    41,     6,    53,    20,    38,
      11,     4,    11,    47,    34,    35,    36,    37,    18,    32,
       9,    19,    63,    39,    40,     3,     4,     5,    16,    27,
      56,    57,    59,    61,    62,    23,    48,    56,    35,    19,
      16,    24,     7,    64,    38,    26,    56,    12,    13,    58,
      14,    15,    60,    19,    43,    44,    56,    63,     4,    17,
      59,    59,    61,    61,    49,    51,    63,    17,    21,    45,
      58,    58,    60,    60,    19,    21,    50,     4,    44,    24,
      51,    25,    52,    45,    50,    56
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
  YYUSE (yytype);
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

  YYUSE (yytype);
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
/* Line 1787 of yacc.c  */
#line 77 "parser.y"
    {
		numVars[0] = 0;
	}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 89 "parser.y"
    {
		++lineno;
	}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 107 "parser.y"
    {
		++lineno;
	}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 135 "parser.y"
    {
		numVars[++numInst] = 0;
	}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 137 "parser.y"
    {
		--numInst;
	}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 153 "parser.y"
    {
		struct var_node *node = (yyvsp[(1) - (1)].node_val);
		if (node->type == NUMBER_NODE) {
			printf("%d", node->number);
			//free(node);
		} else if (node->type == QUOTE_NODE) {
			print_debug("is a quote node");
			printf("%s", node->quote);
		} else if (node->type == NEWLINE_NODE) {
			printf("\n");
		} else {
			print_debug("params error");
			print_error();
		}
	}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 177 "parser.y"
    {
		struct var_node *idNode = find_variable_declare((yyvsp[(1) - (2)].string_val));
		struct var_node *assignment = (yyvsp[(2) - (2)].node_val);

			print_debug((yyvsp[(1) - (2)].string_val));

		if (idNode == NULL) {
			print_debug("declare new var");
			assignment->id = strdup((yyvsp[(1) - (2)].string_val));
			make_variable(assignment);
		} else if (idNode->type == assignment->type) {
			print_debug("declare error");
			print_error();
		} else {
			print_debug("replacing with new declare");
			replace_variable(idNode, assignment);
		}
	}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 198 "parser.y"
    {
		(yyval.node_val) = (yyvsp[(2) - (2)].node_val);
	}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 202 "parser.y"
    {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		(yyval.node_val) = node;
	}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 210 "parser.y"
    {
		(yyval.node_val) = (yyvsp[(1) - (1)].node_val);
	}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 214 "parser.y"
    {
		lineno = lineno + 2;
		(yyval.node_val) = (yyvsp[(3) - (5)].node_val);
	}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 221 "parser.y"
    {
		print_debug("found fields");
		struct var_node *object = (struct var_node*)malloc(sizeof(struct var_node));
		object->type = OBJECT_NODE;
		
		struct var_node *left = (yyvsp[(1) - (2)].node_val);
		struct var_node *right = (yyvsp[(2) - (2)].node_val);

		if (right->type == EMPTY_NODE) {
			//free(right);
		} else {
			left->next = right;
		}

		object->next = left;
		(yyval.node_val) = object;
	}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 241 "parser.y"
    {
		struct var_node *left = (yyvsp[(2) - (3)].node_val);
		struct var_node *right = (yyvsp[(3) - (3)].node_val);

		if (right->type == EMPTY_NODE) {
			//free(right);
		} else {
			left->next = right;
		}

		(yyval.node_val) = left;
	}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 254 "parser.y"
    {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		(yyval.node_val) = node;
	}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 262 "parser.y"
    {
		struct var_node *node = (yyvsp[(3) - (3)].node_val);
		node->id = (yyvsp[(2) - (3)].string_val);
		(yyval.node_val) = node;
	}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 270 "parser.y"
    {
		print_debug("found field tail");
		struct var_node *node = (yyvsp[(2) - (2)].node_val);
		if (node->type == NUMBER_NODE) {
			print_debug("number node");
		}
		(yyval.node_val) = (yyvsp[(2) - (2)].node_val);
	}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 279 "parser.y"
    {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_FIELD_NODE;
		(yyval.node_val) = node;
	}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 291 "parser.y"
    {
		struct var_node *idNode = (yyvsp[(1) - (3)].node_val);
		struct var_node *assignment = (yyvsp[(3) - (3)].node_val);

		if (idNode == NULL) {
			print_error();
		}

		if ((idNode->type == EMPTY_NODE) | (idNode->type == EMPTY_FIELD_NODE)) {
			idNode->type = assignment->type;
			if (assignment->type == NUMBER_NODE) {
				idNode->number = assignment->number;
				//free(assignment);
			} else if (assignment->type == QUOTE_NODE) {
				idNode->quote = strdup(assignment->quote);
				//free(assignment);
			} else if (assignment->type == NEWLINE_NODE) {
				//nothing
			} else {
				print_debug("assign error");
				print_error();
			}
		} else if(idNode->type != assignment->type) {
			if ((idNode->type == NEWLINE_NODE) && (assignment->type == QUOTE_NODE)) {
				idNode->type = QUOTE_NODE;
				idNode->quote = strdup(assignment->quote);
				//free(assignment);
			} else if ((idNode->type == QUOTE_NODE) && (assignment->type == NEWLINE_NODE)) {
				idNode->type = NEWLINE_NODE;
				//free(assignment);
			} else {
				print_debug("assign error");
				print_error();
			}
		} else {
			if (assignment->type == NUMBER_NODE) {
				idNode->number = assignment->number;
				//free(assignment);
			} else if (assignment->type == QUOTE_NODE) {
				idNode->quote = strdup(assignment->quote);
				//free(assignment);
			} else if (assignment->type == NEWLINE_NODE) {
				//nothing
			} else {
				print_debug("assign error");
				print_error();
			}
		}
	}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 343 "parser.y"
    {
		struct var_node *node = find_variable((yyvsp[(1) - (3)].string_val));
		if (node == NULL) {
			print_debug("idlist error");
			print_error();
		}

		(yyval.node_val) = find_field(node, (yyvsp[(3) - (3)].string_val));
	}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 353 "parser.y"
    {
		(yyval.node_val) = find_variable((yyvsp[(1) - (1)].string_val));
	}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 359 "parser.y"
    {
		(yyval.node_val) = (yyvsp[(1) - (1)].node_val);
	}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 365 "parser.y"
    {
		struct var_node *left = (yyvsp[(1) - (2)].node_val);
		struct var_node *right = (yyvsp[(2) - (2)].node_val);

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("pmexpr error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if(right->op == '+') {
					left->number += right->number;
				} else if (right->op == '-') {
					left->number -= right->number;
				} else {
					print_debug("pmexpr error");
					print_error();
				}
			} else if (left->type == QUOTE_NODE) {
				if(right->op == '+') {
					strcat(left->quote, right->quote);
				} else {
					print_debug("pm expr error");
					print_error();
				}
			} else {
				print_debug("pmexpr error");
				print_error();
			}
		}
		//free(right);
		(yyval.node_val) = left;
	}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 401 "parser.y"
    {
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '+';
		struct var_node *left = (yyvsp[(2) - (3)].node_val);
		struct var_node *right = (yyvsp[(3) - (3)].node_val);
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("pmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '+') {
					left->number += right->number;
				} else if (right->op == '-') {
					left->number -= right->number;
				} else {
					print_debug("pmexprtail error");
					print_error();
				}
			} else if (left->type == QUOTE_NODE) {
				if (right->op == '+') {
					strcat(left->quote, right->quote);
				} else {
					print_debug("pmexprtail error");
					print_error();
				}
				
			} else {
				print_debug("pmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else if (nextOp->type == QUOTE_NODE) {
			nextOp->quote = strdup(left->quote);
		} else {
			print_debug("pmexprtail error");
			print_error();
		}
		//free(left);
		(yyval.node_val) = nextOp;
	}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 449 "parser.y"
    {
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '-';
		struct var_node *left = (yyvsp[(2) - (3)].node_val);
		struct var_node *right = (yyvsp[(3) - (3)].node_val);
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("pmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '+') {
					left->number -= right->number;
				} else if (right->op == '-') {
					left->number += right->number;
				} else {
					print_debug("pmexprtail error");
					print_error();
				}
			} else {
				print_debug("pmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else {
			print_debug("pmexprtail error");
			print_error();
		}
		//free(left);
		(yyval.node_val) = nextOp;
	}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 487 "parser.y"
    {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		(yyval.node_val) = node;
	}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 495 "parser.y"
    {
		struct var_node *left = (yyvsp[(1) - (2)].node_val);
		struct var_node *right = (yyvsp[(2) - (2)].node_val);

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("dmexpr error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if(right->op == '*') {
					left->number = left->number * right->number;
				} else if (right->op == '/') {
					if (right->number == 0) {
						print_debug("dmexpr error");
						print_error();
					} else {
						left->number = left->number / right->number;
					}
				} else {
					print_debug("dmexpr error");
					print_error();
				}
			} else {
				print_debug("dmexpr error");
				print_error();
			}
		}
		//free(right);
		(yyval.node_val) = left;
	}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 529 "parser.y"
    {
		print_debug("found * symbol");
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '*';
		struct var_node *left = (yyvsp[(2) - (3)].node_val);
		struct var_node *right = (yyvsp[(3) - (3)].node_val);
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("dmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '*') {
					left->number = left->number * right->number;
				} else if (right->op == '/') {
					if (right->number == 0) {
						print_debug("dmexprtail error");
						print_error();
					} else {
						left->number = left->number / right->number;
					}
				} else {
					print_debug("dmexprtail error");
					print_error();
				}
			} else {
				print_debug("dmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else {
			print_debug("dmexprtail error");
			print_error();
		}
		//free(left);
		(yyval.node_val) = nextOp;
	}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 573 "parser.y"
    {
		struct var_node *nextOp = (struct var_node*)malloc(sizeof(struct var_node));
		nextOp->op = '/';
		struct var_node *left = (yyvsp[(2) - (3)].node_val);
		struct var_node *right = (yyvsp[(3) - (3)].node_val);
		nextOp->type = left->type;

		if (right->type != EMPTY_NODE) {
			if (left->type != right->type) {
				print_debug("dmexprtail error");
				print_error();
			}
			if (left->type == NUMBER_NODE) {
				if (right->op == '/') {
					if (right->number == 0) {
						print_error();
					}
					left->number = left->number / right->number;
				} else if (right->op == '*') {
					left->number = right->number * left->number;
				} else {
					print_debug("dmexprtail error");
					print_error();
				}
			} else {
				print_debug("dmexprtail error");
				print_error();
			}
		}
		//free(right);
		nextOp->type = left->type;
		if (nextOp->type == NUMBER_NODE) {
			nextOp->number = left->number;
		} else {
			print_debug("dmexprtail error");
			print_error();
		}
		//free(left);
		(yyval.node_val) = nextOp;
	}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 614 "parser.y"
    {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = EMPTY_NODE;
		(yyval.node_val) = node;
	}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 622 "parser.y"
    {
		(yyval.node_val) = (yyvsp[(1) - (1)].node_val);
	}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 626 "parser.y"
    {
		(yyval.node_val) = (yyvsp[(2) - (3)].node_val);
	}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 632 "parser.y"
    {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = NUMBER_NODE;
		node->number = (yyvsp[(1) - (1)].number_val);
		(yyval.node_val) = node;
	}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 639 "parser.y"
    {
		print_debug("found quote");
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = QUOTE_NODE;
		node->quote = strdup((yyvsp[(1) - (1)].string_val));
		(yyval.node_val) = node;
	}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 647 "parser.y"
    {
		struct var_node *node = find_variable((yyvsp[(1) - (3)].string_val));
		print_debug("looking for object");
		print_debug((yyvsp[(1) - (3)].string_val));
		if (node == NULL) {
			print_error();
			print_debug("basevalue error");
		}

		node = find_field(node, (yyvsp[(3) - (3)].string_val));
		if (node == NULL) {
			print_debug("basevalue error");
			print_error();
		}
		
		struct var_node *copy = (struct var_node*)malloc(sizeof(struct var_node));
		copy->type = node->type;
		if (node->type == NUMBER_NODE) {
			copy->number = node->number;
		} else if (node->type == QUOTE_NODE) {
			copy->quote = strdup(node->quote);
		} else if (node->type == NEWLINE_NODE) {
			//nothing
		} else {
			print_debug("basevalue error");
			print_error();
		}
		(yyval.node_val) = copy;
	}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 677 "parser.y"
    {
		print_debug("looking for variable");
		print_debug((yyvsp[(1) - (1)].string_val));
		struct var_node *node = find_variable((yyvsp[(1) - (1)].string_val));
		if (node == NULL) {
			print_debug("basevalue error");
			print_error();
		}

		struct var_node *copy = (struct var_node*)malloc(sizeof(struct var_node));
		copy->type = node->type;
		if (node->type == NUMBER_NODE) {
			copy->number = node->number;
		} else if (node->type == QUOTE_NODE) {
			copy->quote = strdup(node->quote);
		} else if (node->type == NEWLINE_NODE) {
			//nothing
		} else {
			print_debug("basevalue error");
			print_error();
		}
		(yyval.node_val) = copy;
	}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 701 "parser.y"
    {
		struct var_node *node = (struct var_node*)malloc(sizeof(struct var_node));
		node->type = NEWLINE_NODE;
		(yyval.node_val) = node;
	}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 709 "parser.y"
    {
		++lineno;
	}
    break;


/* Line 1787 of yacc.c  */
#line 2219 "y.tab.c"
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


/* Line 2050 of yacc.c  */
#line 716 "parser.y"


struct var_node* find_variable(char *name)
{
	//printf("numInst=%d\n", numInst);
    int i;
    int j;
	for (j = numInst; j>=0; j--) {
		for (i=0; i<numVars[j]; i++) {
			if (! strcmp(variables[j][i]->id, name)) {
				//printf("instance %d\tvar %d\n", j, i);
				return variables[j][i];
			}
		}
	}
	return NULL;
} 

struct var_node* find_variable_declare(char *name)
{
	//printf("numInst=%d\n", numInst);
	int i;
	int j = numInst;
	for (i=0; i<numVars[j]; i++) {
		if (! strcmp(variables[j][i]->id, name)) {
			//printf("instance %d\tvar %d\n", j, i);
			return variables[j][i];
		}
	}
	return NULL;
} 

void replace_variable(struct var_node *originalNode, struct var_node *newNode) 
{
	int i;
   	int j = numInst;
	for (i=0; i<numVars[j]; i++) {
		if (! strcmp(variables[j][i]->id, originalNode->id)) {
			variables[j][i] = newNode;
			//free(originalNode);
		}
	}
}

struct var_node* find_field(struct var_node *node, char *name)
{
    	struct var_node *ptr = node;
	while ((ptr=ptr->next) != NULL) {
		if (! strcmp(ptr->id, name)) {
			//printf("found field: %s\n", name);
			return ptr;
		}
	}
	return NULL;
} 

void make_variable(struct var_node *newVar) {
	variables[numInst][numVars[numInst]++] = newVar;
}

FILE *yyin;
int yylineno;
yyerror(char *s)
{
    printf("%s\n", s);
}

void print_debug(char *s) {
	//printf("%s\n", s);
}

void print_error() {
	printf("Line %d, type violation\n", lineno);
	exit(0);
}

main(int argc, char *argv[])
{
    //yydebug = 1;
    if (argc == 2) {
        FILE *file;

        file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "could not open %s\n", argv[1]);
        } else{
            yyin = file;
            //yyparse() will call yylex()
            yyparse();
        }
    } else{
        fprintf(stderr, "format: ./yacc_example [filename]");
    }
}
