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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         ndt_yyparse
#define yylex           ndt_yylex
#define yyerror         ndt_yyerror
#define yydebug         ndt_yydebug
#define yynerrs         ndt_yynerrs


/* Copy the first part of user declarations.  */
#line 1 "grammar.y" /* yacc.c:339  */

/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2017-2018, plures
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "grammar.h"


void
yyerror(YYLTYPE *loc, yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta,
        ndt_context_t *ctx, const char *msg)
{
    (void)scanner;
    (void)ast;
    (void)meta;

    ndt_err_format(ctx, NDT_ParseError, "%d:%d: %s\n", loc->first_line,
                   loc->first_column, msg);
}

int
yylex(YYSTYPE *val, YYLTYPE *loc, yyscan_t scanner, ndt_context_t *ctx)
{
    return ndt_yylexfunc(val, loc, scanner, ctx);
}

#line 128 "grammar.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.h".  */
#ifndef YY_NDT_YY_GRAMMAR_H_INCLUDED
# define YY_NDT_YY_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int ndt_yydebug;
#endif
/* "%code requires" blocks.  */
#line 57 "grammar.y" /* yacc.c:355  */

  #include "ndtypes.h"
  #include "seq.h"
  #include "attr.h"
  #include "parsefuncs.h"
  #define YY_TYPEDEF_YY_SCANNER_T
  typedef void * yyscan_t;

#line 167 "grammar.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENDMARKER = 0,
    ANY_KIND = 258,
    SCALAR_KIND = 259,
    VOID = 260,
    BOOL = 261,
    SIGNED_KIND = 262,
    INT8 = 263,
    INT16 = 264,
    INT32 = 265,
    INT64 = 266,
    UNSIGNED_KIND = 267,
    UINT8 = 268,
    UINT16 = 269,
    UINT32 = 270,
    UINT64 = 271,
    FLOAT_KIND = 272,
    FLOAT16 = 273,
    FLOAT32 = 274,
    FLOAT64 = 275,
    COMPLEX_KIND = 276,
    COMPLEX32 = 277,
    COMPLEX64 = 278,
    COMPLEX128 = 279,
    CATEGORICAL = 280,
    NA = 281,
    INTPTR = 282,
    UINTPTR = 283,
    SIZE = 284,
    CHAR = 285,
    STRING = 286,
    FIXED_STRING_KIND = 287,
    FIXED_STRING = 288,
    BYTES = 289,
    FIXED_BYTES_KIND = 290,
    FIXED_BYTES = 291,
    REF = 292,
    FIXED = 293,
    VAR = 294,
    COMMA = 295,
    COLON = 296,
    LPAREN = 297,
    RPAREN = 298,
    LBRACE = 299,
    RBRACE = 300,
    LBRACK = 301,
    RBRACK = 302,
    STAR = 303,
    ELLIPSIS = 304,
    RARROW = 305,
    EQUAL = 306,
    LESS = 307,
    GREATER = 308,
    QUESTIONMARK = 309,
    BANG = 310,
    AMPERSAND = 311,
    BAR = 312,
    ERRTOKEN = 313,
    INTEGER = 314,
    FLOATNUMBER = 315,
    STRINGLIT = 316,
    NAME_LOWER = 317,
    NAME_UPPER = 318,
    NAME_OTHER = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 86 "grammar.y" /* yacc.c:355  */

    ndt_t *ndt;
    ndt_field_t *field;
    ndt_field_seq_t *field_seq;
    ndt_value_t *typed_value;
    ndt_value_seq_t *typed_value_seq;
    ndt_attr_t *attribute;
    ndt_attr_seq_t *attribute_seq;
    enum ndt_variadic variadic_flag;
    enum ndt_encoding encoding;
    uint32_t uint32;
    char *string;
    ndt_string_seq_t *string_seq;
    ndt_type_seq_t *type_seq;

#line 261 "grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int ndt_yyparse (yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta, ndt_context_t *ctx);
/* "%code provides" blocks.  */
#line 66 "grammar.y" /* yacc.c:355  */

  #define YY_DECL extern int ndt_yylexfunc(YYSTYPE *yylval_param, YYLTYPE *yylloc_param, yyscan_t yyscanner, ndt_context_t *ctx)
  extern int ndt_yylexfunc(YYSTYPE *, YYLTYPE *, yyscan_t, ndt_context_t *);
  void yyerror(YYLTYPE *loc, yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta, ndt_context_t *ctx, const char *msg);

#line 293 "grammar.c" /* yacc.c:355  */

#endif /* !YY_NDT_YY_GRAMMAR_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 299 "grammar.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  93
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   570

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   201,   202,   203,   207,   208,   209,   210,
     213,   214,   217,   218,   221,   222,   223,   224,   225,   228,
     229,   230,   233,   234,   235,   236,   237,   238,   239,   240,
     243,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     267,   268,   269,   270,   273,   274,   275,   276,   279,   280,
     281,   284,   285,   286,   290,   291,   292,   295,   296,   299,
     302,   303,   306,   307,   308,   309,   310,   313,   316,   319,
     322,   323,   326,   329,   330,   333,   334,   335,   336,   339,
     340,   343,   344,   345,   348,   349,   350,   353,   354,   357,
     358,   361,   362,   363,   366,   367,   370,   371,   374,   375,
     376,   379,   380,   383,   384,   387,   388,   391,   392,   395,
     396,   397,   398,   401,   404,   405,   408,   409
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "ANY_KIND", "SCALAR_KIND",
  "VOID", "BOOL", "SIGNED_KIND", "INT8", "INT16", "INT32", "INT64",
  "UNSIGNED_KIND", "UINT8", "UINT16", "UINT32", "UINT64", "FLOAT_KIND",
  "FLOAT16", "FLOAT32", "FLOAT64", "COMPLEX_KIND", "COMPLEX32",
  "COMPLEX64", "COMPLEX128", "CATEGORICAL", "NA", "INTPTR", "UINTPTR",
  "SIZE", "CHAR", "STRING", "FIXED_STRING_KIND", "FIXED_STRING", "BYTES",
  "FIXED_BYTES_KIND", "FIXED_BYTES", "REF", "FIXED", "VAR", "COMMA",
  "COLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK",
  "STAR", "ELLIPSIS", "RARROW", "EQUAL", "LESS", "GREATER", "QUESTIONMARK",
  "BANG", "AMPERSAND", "BAR", "ERRTOKEN", "INTEGER", "FLOATNUMBER",
  "STRINGLIT", "NAME_LOWER", "NAME_UPPER", "NAME_OTHER", "$accept",
  "input", "datashape_or_module", "datashape", "dimensions_with_broadcast",
  "dimensions", "dimensions_nooption", "dimensions_tail", "dtype",
  "scalar", "signed", "unsigned", "ieee_float", "ieee_complex", "alias",
  "character", "string", "fixed_string", "endian_opt", "encoding", "bytes",
  "fixed_bytes", "ref", "categorical", "typed_value_seq", "typed_value",
  "variadic_flag", "comma_variadic_flag", "tuple_type", "tuple_field_seq",
  "tuple_field", "record_type", "record_field_seq", "record_field",
  "record_field_name", "arguments_opt", "attribute_seq", "attribute",
  "untyped_value_seq", "untyped_value", "function_type",
  "type_seq_or_void", "type_seq", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -170

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-170)))

#define YYTABLE_NINF -93

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,  -170,  -170,  -170,  -170,  -170,  -170,  -170,   -29,     2,
    -170,  -170,    15,    23,  -170,    27,    37,    42,    23,   175,
     -16,   -33,  -170,  -170,  -170,   507,   -27,   350,  -170,   -30,
    -170,    13,    26,    97,    98,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,    72,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,    56,    67,   -21,    47,
      60,    58,  -170,    58,   350,    58,    79,   -33,   -14,    75,
      93,   100,  -170,  -170,  -170,  -170,  -170,    99,   106,  -170,
     117,   464,  -170,  -170,   -18,    -6,  -170,  -170,   464,   122,
     407,   464,    90,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,   236,   350,  -170,  -170,  -170,  -170,    31,
    -170,  -170,   116,    33,   115,    86,  -170,    88,   125,    94,
     464,    58,  -170,   293,   133,  -170,    40,   138,   350,   507,
    -170,  -170,  -170,  -170,   350,   115,   141,   102,  -170,   464,
    -170,  -170,  -170,   -21,  -170,  -170,    47,  -170,    -9,    58,
    -170,  -170,  -170,   137,  -170,   -34,   -33,  -170,   121,  -170,
    -170,   115,  -170,    19,  -170,   129,  -170,  -170,  -170,  -170,
    -170,  -170,   145,    51,  -170,  -170,  -170,  -170,  -170,  -170,
     464,  -170,  -170,  -170,    58,  -170,   -23,  -170,  -170,   -32,
      51,  -170,  -170,  -170
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      72,    22,    23,   125,    32,    34,    36,    38,     0,    67,
      69,    43,     0,   111,    46,     0,     0,     0,   111,    72,
      89,     0,    73,    74,    75,    72,     0,    72,    76,     0,
      27,    30,     0,     0,   126,     6,    10,    12,     8,    24,
      33,    35,    37,    39,    40,    41,    42,    44,     0,    45,
      47,    49,    48,    25,    26,     4,     0,   124,     0,     0,
       0,     0,    78,     0,    72,     0,     0,    90,    30,    99,
       0,    91,    97,    90,   108,   109,   110,     0,    91,   104,
       0,    72,    13,     9,     0,     0,     7,    81,    72,     0,
      72,    72,     0,     1,     2,    31,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    72,    72,    88,    85,    86,    87,     0,
      83,    77,     0,     0,     0,     0,   113,     0,     0,     0,
      72,     0,    94,    72,     0,   101,    92,     0,    72,    72,
      21,    11,    19,    14,    72,    27,     0,     0,    16,    72,
     126,   123,   127,     0,    82,    68,     0,    70,     0,     0,
     112,    79,    80,     0,    17,     0,    93,    98,     0,    95,
      93,   108,   105,     0,   102,   106,    20,     5,    28,    29,
      18,    84,     0,     0,   120,   121,   122,   119,   115,   114,
      72,   100,    96,   103,     0,    71,     0,   117,    15,     0,
       0,   116,   107,   118
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,  -170,     3,   163,   -72,   -24,   -81,   -25,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,    34,
    -170,  -170,  -170,  -170,  -170,    38,   173,   119,  -170,  -170,
      61,  -170,  -170,    59,  -170,   180,   -61,    43,  -170,  -169,
    -170,    91,  -170
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    69,    35,    36,    37,   141,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   122,
      49,    50,    51,    52,   119,   120,    70,   134,    53,    71,
      72,    54,    78,    79,    80,    62,   125,   126,   196,   188,
      55,    56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    82,   127,    34,   129,   115,   159,   143,   159,   140,
     148,    17,    18,    58,   197,    81,   140,   200,    88,   140,
      17,    18,    21,   191,   201,   202,    93,    84,    90,   147,
      87,   203,    29,    73,    91,    92,    85,   183,   116,   117,
     118,    29,    91,    92,    59,    85,    74,    75,    76,   164,
     184,   185,   186,   187,    89,    90,   142,    60,   140,   159,
      82,    91,    92,   142,   193,    61,   142,   128,   180,    63,
     165,   153,   168,   156,   154,   173,   157,   140,    95,    64,
      96,    97,    98,    99,    65,   100,   101,   102,   103,   170,
     104,   105,   106,   146,   107,   108,   109,    94,    -3,   110,
     111,   112,   171,    75,    76,   142,   113,   114,   121,   198,
     184,   185,   186,   187,   176,    82,   150,   152,   140,   123,
     124,     1,     2,     3,   142,     4,   159,   130,   159,   160,
       5,   161,   131,   199,   159,     6,   132,   163,   149,     7,
     133,   175,   159,     8,   135,   179,   136,   177,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   138,   155,
      19,   159,    20,   144,   192,   142,   158,    21,   162,    22,
      23,    24,    25,    26,    27,    28,   169,    29,     1,     2,
      30,    31,     4,   174,   178,   190,   194,     5,   195,    86,
     182,   181,     6,    77,   167,   172,     7,   137,    66,     0,
       8,     0,   189,     0,   151,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,    19,   -89,    20,
       0,     0,     0,     0,    67,     0,    22,    23,    24,    25,
      26,    27,    28,     0,    29,     0,     0,    30,    68,     1,
       2,     3,     0,     4,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     6,     0,     0,     0,     7,     0,     0,
       0,     8,     0,     0,     0,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    19,     0,
      20,     0,     0,     0,     0,    21,     0,    22,    23,    24,
      25,    26,    27,    28,     0,    29,     1,     2,    30,    68,
       4,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       6,     0,     0,     0,     7,     0,     0,     0,     8,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,    19,   -92,    20,     0,     0,
       0,     0,   166,     0,    22,    23,    24,    25,    26,    27,
      28,     0,    29,     1,     2,   145,    68,     4,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     6,     0,     0,
       0,     7,     0,     0,     0,     8,     0,     0,     0,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,    19,     0,    20,     0,     0,     0,     0,    21,
       0,    22,    23,    24,    25,    26,    27,    28,     0,    29,
       1,     2,    30,    68,     4,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     6,     0,     0,     0,     7,     0,
       0,     0,     8,     0,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,    19,
       0,    20,     0,     0,     0,     0,    21,     0,    22,    23,
      24,    25,    26,    27,    28,     0,    29,     1,     2,   145,
      68,     4,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     6,     0,     0,     0,     7,     0,     0,     0,     8,
       0,     0,     0,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,    19,     0,    20,     0,
       1,     2,     0,     0,     4,    22,    23,    24,   139,     5,
      27,    28,     0,    29,     6,     0,    30,    68,     7,     0,
       0,     0,     8,     0,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,    19,
       0,    20,     0,     0,     0,     0,     0,     0,    22,    23,
      24,     0,     0,    27,    28,     0,    29,     0,     0,    30,
      68
};

static const yytype_int16 yycheck[] =
{
      25,    25,    63,     0,    65,    26,    40,    88,    40,    81,
      91,    38,    39,    42,   183,    48,    88,    40,    48,    91,
      38,    39,    49,    57,    47,    57,     0,    54,    42,    90,
      27,   200,    59,    49,    48,    49,    63,    46,    59,    60,
      61,    59,    48,    49,    42,    63,    62,    63,    64,   130,
      59,    60,    61,    62,    41,    42,    81,    42,   130,    40,
      84,    48,    49,    88,    45,    42,    91,    64,   149,    42,
     131,    40,   133,    40,    43,   136,    43,   149,     6,    42,
       8,     9,    10,    11,    42,    13,    14,    15,    16,    49,
      18,    19,    20,    90,    22,    23,    24,     0,     0,    27,
      28,    29,    62,    63,    64,   130,    50,    40,    61,   190,
      59,    60,    61,    62,   139,   139,   113,   114,   190,    59,
      62,     3,     4,     5,   149,     7,    40,    48,    40,    43,
      12,    43,    57,   194,    40,    17,    43,    43,    48,    21,
      40,   138,    40,    25,    45,    43,    40,   144,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    43,
      42,    40,    44,    41,    43,   190,    51,    49,    43,    51,
      52,    53,    54,    55,    56,    57,    43,    59,     3,     4,
      62,    63,     7,    45,    43,    48,    57,    12,    43,    26,
     156,   153,    17,    20,   133,   136,    21,    78,    18,    -1,
      25,    -1,   159,    -1,   113,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    62,    63,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,     3,     4,    62,    63,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,     3,     4,    62,    63,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
       3,     4,    62,    63,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,     3,     4,    62,
      63,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    44,    -1,
       3,     4,    -1,    -1,     7,    51,    52,    53,    54,    12,
      56,    57,    -1,    59,    17,    -1,    62,    63,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    56,    57,    -1,    59,    -1,    -1,    62,
      63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,    12,    17,    21,    25,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    42,
      44,    49,    51,    52,    53,    54,    55,    56,    57,    59,
      62,    63,    66,    67,    68,    69,    70,    71,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    85,
      86,    87,    88,    93,    96,   105,   106,   107,    42,    42,
      42,    42,   100,    42,    42,    42,   100,    49,    63,    68,
      91,    94,    95,    49,    62,    63,    64,    91,    97,    98,
      99,    48,    71,    73,    54,    63,    69,    68,    48,    41,
      42,    48,    49,     0,     0,     6,     8,     9,    10,    11,
      13,    14,    15,    16,    18,    19,    20,    22,    23,    24,
      27,    28,    29,    50,    40,    26,    59,    60,    61,    89,
      90,    61,    84,    59,    62,   101,   102,   101,    68,   101,
      48,    57,    43,    40,    92,    45,    40,    92,    41,    54,
      70,    72,    73,    72,    41,    62,    68,   101,    72,    48,
      68,   106,    68,    40,    43,    43,    40,    43,    51,    40,
      43,    43,    43,    43,    72,   101,    49,    95,   101,    43,
      49,    62,    98,   101,    45,    68,    73,    68,    43,    43,
      72,    90,    84,    46,    59,    60,    61,    62,   104,   102,
      48,    57,    43,    45,    57,    43,   103,   104,    72,   101,
      40,    47,    57,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    76,    77,    77,
      77,    78,    78,    78,    79,    79,    79,    80,    80,    81,
      82,    82,    83,    83,    83,    83,    83,    84,    85,    86,
      87,    87,    88,    89,    89,    90,    90,    90,    90,    91,
      91,    92,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    98,    98,    99,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   104,   104,   105,   106,   106,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     4,     1,     2,     1,     2,
       1,     3,     1,     2,     3,     6,     3,     4,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     4,     1,
       4,     6,     0,     1,     1,     1,     1,     1,     2,     4,
       4,     2,     4,     1,     3,     1,     1,     1,     1,     0,
       1,     0,     1,     2,     3,     4,     5,     1,     3,     1,
       4,     3,     4,     5,     1,     3,     3,     6,     1,     1,
       1,     0,     3,     1,     3,     3,     5,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     3
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
      yyerror (&yylloc, scanner, ast, meta, ctx, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, scanner, ast, meta, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta, ndt_context_t *ctx)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (meta);
  YYUSE (ctx);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta, ndt_context_t *ctx)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, ast, meta, ctx);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta, ndt_context_t *ctx)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, ast, meta, ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, ast, meta, ctx); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta, ndt_context_t *ctx)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (ast);
  YYUSE (meta);
  YYUSE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 59: /* INTEGER  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1439 "grammar.c" /* yacc.c:1257  */
        break;

    case 60: /* FLOATNUMBER  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1445 "grammar.c" /* yacc.c:1257  */
        break;

    case 61: /* STRINGLIT  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1451 "grammar.c" /* yacc.c:1257  */
        break;

    case 62: /* NAME_LOWER  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1457 "grammar.c" /* yacc.c:1257  */
        break;

    case 63: /* NAME_UPPER  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1463 "grammar.c" /* yacc.c:1257  */
        break;

    case 64: /* NAME_OTHER  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1469 "grammar.c" /* yacc.c:1257  */
        break;

    case 66: /* input  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1475 "grammar.c" /* yacc.c:1257  */
        break;

    case 67: /* datashape_or_module  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1481 "grammar.c" /* yacc.c:1257  */
        break;

    case 68: /* datashape  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1487 "grammar.c" /* yacc.c:1257  */
        break;

    case 69: /* dimensions_with_broadcast  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1493 "grammar.c" /* yacc.c:1257  */
        break;

    case 70: /* dimensions  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1499 "grammar.c" /* yacc.c:1257  */
        break;

    case 71: /* dimensions_nooption  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1505 "grammar.c" /* yacc.c:1257  */
        break;

    case 72: /* dimensions_tail  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1511 "grammar.c" /* yacc.c:1257  */
        break;

    case 73: /* dtype  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1517 "grammar.c" /* yacc.c:1257  */
        break;

    case 74: /* scalar  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1523 "grammar.c" /* yacc.c:1257  */
        break;

    case 75: /* signed  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1529 "grammar.c" /* yacc.c:1257  */
        break;

    case 76: /* unsigned  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1535 "grammar.c" /* yacc.c:1257  */
        break;

    case 77: /* ieee_float  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1541 "grammar.c" /* yacc.c:1257  */
        break;

    case 78: /* ieee_complex  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1547 "grammar.c" /* yacc.c:1257  */
        break;

    case 79: /* alias  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1553 "grammar.c" /* yacc.c:1257  */
        break;

    case 80: /* character  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1559 "grammar.c" /* yacc.c:1257  */
        break;

    case 81: /* string  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1565 "grammar.c" /* yacc.c:1257  */
        break;

    case 82: /* fixed_string  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1571 "grammar.c" /* yacc.c:1257  */
        break;

    case 85: /* bytes  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1577 "grammar.c" /* yacc.c:1257  */
        break;

    case 86: /* fixed_bytes  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1583 "grammar.c" /* yacc.c:1257  */
        break;

    case 87: /* ref  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1589 "grammar.c" /* yacc.c:1257  */
        break;

    case 88: /* categorical  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1595 "grammar.c" /* yacc.c:1257  */
        break;

    case 89: /* typed_value_seq  */
#line 187 "grammar.y" /* yacc.c:1257  */
      { ndt_value_seq_del(((*yyvaluep).typed_value_seq)); }
#line 1601 "grammar.c" /* yacc.c:1257  */
        break;

    case 90: /* typed_value  */
#line 186 "grammar.y" /* yacc.c:1257  */
      { ndt_value_del(((*yyvaluep).typed_value)); }
#line 1607 "grammar.c" /* yacc.c:1257  */
        break;

    case 93: /* tuple_type  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1613 "grammar.c" /* yacc.c:1257  */
        break;

    case 94: /* tuple_field_seq  */
#line 185 "grammar.y" /* yacc.c:1257  */
      { ndt_field_seq_del(((*yyvaluep).field_seq)); }
#line 1619 "grammar.c" /* yacc.c:1257  */
        break;

    case 95: /* tuple_field  */
#line 184 "grammar.y" /* yacc.c:1257  */
      { ndt_field_del(((*yyvaluep).field)); }
#line 1625 "grammar.c" /* yacc.c:1257  */
        break;

    case 96: /* record_type  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1631 "grammar.c" /* yacc.c:1257  */
        break;

    case 97: /* record_field_seq  */
#line 185 "grammar.y" /* yacc.c:1257  */
      { ndt_field_seq_del(((*yyvaluep).field_seq)); }
#line 1637 "grammar.c" /* yacc.c:1257  */
        break;

    case 98: /* record_field  */
#line 184 "grammar.y" /* yacc.c:1257  */
      { ndt_field_del(((*yyvaluep).field)); }
#line 1643 "grammar.c" /* yacc.c:1257  */
        break;

    case 99: /* record_field_name  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1649 "grammar.c" /* yacc.c:1257  */
        break;

    case 100: /* arguments_opt  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_attr_seq_del(((*yyvaluep).attribute_seq)); }
#line 1655 "grammar.c" /* yacc.c:1257  */
        break;

    case 101: /* attribute_seq  */
#line 189 "grammar.y" /* yacc.c:1257  */
      { ndt_attr_seq_del(((*yyvaluep).attribute_seq)); }
#line 1661 "grammar.c" /* yacc.c:1257  */
        break;

    case 102: /* attribute  */
#line 188 "grammar.y" /* yacc.c:1257  */
      { ndt_attr_del(((*yyvaluep).attribute)); }
#line 1667 "grammar.c" /* yacc.c:1257  */
        break;

    case 103: /* untyped_value_seq  */
#line 191 "grammar.y" /* yacc.c:1257  */
      { ndt_string_seq_del(((*yyvaluep).string_seq)); }
#line 1673 "grammar.c" /* yacc.c:1257  */
        break;

    case 104: /* untyped_value  */
#line 190 "grammar.y" /* yacc.c:1257  */
      { ndt_free(((*yyvaluep).string)); }
#line 1679 "grammar.c" /* yacc.c:1257  */
        break;

    case 105: /* function_type  */
#line 183 "grammar.y" /* yacc.c:1257  */
      { ndt_del(((*yyvaluep).ndt)); }
#line 1685 "grammar.c" /* yacc.c:1257  */
        break;

    case 106: /* type_seq_or_void  */
#line 192 "grammar.y" /* yacc.c:1257  */
      { ndt_type_seq_del(((*yyvaluep).type_seq)); }
#line 1691 "grammar.c" /* yacc.c:1257  */
        break;

    case 107: /* type_seq  */
#line 192 "grammar.y" /* yacc.c:1257  */
      { ndt_type_seq_del(((*yyvaluep).type_seq)); }
#line 1697 "grammar.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, ndt_t **ast, ndt_meta_t *meta, ndt_context_t *ctx)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 76 "grammar.y" /* yacc.c:1429  */
{
   yylloc.first_line = 1;
   yylloc.first_column = 1;
   yylloc.last_line = 1;
   yylloc.last_column = 1;
}

#line 1813 "grammar.c" /* yacc.c:1429  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner, ctx);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 197 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[-1].ndt);  *ast = (yyval.ndt); YYACCEPT; }
#line 2002 "grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 201 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2008 "grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 202 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2014 "grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 203 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_module((yyvsp[-3].string), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2020 "grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 207 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2026 "grammar.c" /* yacc.c:1646  */
    break;

  case 7:
#line 208 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fortran((yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2032 "grammar.c" /* yacc.c:1646  */
    break;

  case 8:
#line 209 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2038 "grammar.c" /* yacc.c:1646  */
    break;

  case 9:
#line 210 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_option((yyvsp[0].ndt)); if ((yyval.ndt) == NULL) YYABORT; }
#line 2044 "grammar.c" /* yacc.c:1646  */
    break;

  case 10:
#line 213 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2050 "grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 214 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_ellipsis_dim(NULL, (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2056 "grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2062 "grammar.c" /* yacc.c:1646  */
    break;

  case 13:
#line 218 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_option((yyvsp[0].ndt)); if ((yyval.ndt) == NULL) YYABORT; }
#line 2068 "grammar.c" /* yacc.c:1646  */
    break;

  case 14:
#line 221 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_dim_from_shape((yyvsp[-2].string), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2074 "grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 222 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_dim_from_attrs((yyvsp[-3].attribute_seq), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2080 "grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 223 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_symbolic_dim((yyvsp[-2].string), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2086 "grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 224 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_var_dim(meta, (yyvsp[-2].attribute_seq), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2092 "grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 225 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_ellipsis_dim((yyvsp[-3].string), (yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2098 "grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 228 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2104 "grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 229 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_option((yyvsp[0].ndt)); if ((yyval.ndt) == NULL) YYABORT; }
#line 2110 "grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 230 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2116 "grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 233 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_any_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2122 "grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 234 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_scalar_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2128 "grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2134 "grammar.c" /* yacc.c:1646  */
    break;

  case 25:
#line 236 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2140 "grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 237 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2146 "grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 238 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_nominal((yyvsp[0].string), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2152 "grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 239 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_constr((yyvsp[-3].string), (yyvsp[-1].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2158 "grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 240 "grammar.y" /* yacc.c:1646  */
    { (void)(yyvsp[-3].string); (void)(yyvsp[-1].attribute_seq); ndt_free((yyvsp[-3].string)); ndt_attr_seq_del((yyvsp[-1].attribute_seq)); (yyval.ndt) = NULL;
                                            ndt_err_format(ctx, NDT_NotImplementedError, "general attributes are not implemented");
                                            YYABORT; }
#line 2166 "grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 243 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_typevar((yyvsp[0].string), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2172 "grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 246 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Bool, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2178 "grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 247 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_signed_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2184 "grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 248 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2190 "grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 249 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_unsigned_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2196 "grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2202 "grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 251 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_float_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2208 "grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 252 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2214 "grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 253 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_complex_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2220 "grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 254 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2226 "grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2232 "grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 256 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2238 "grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 257 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2244 "grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 258 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_fixed_string_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2250 "grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 259 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2256 "grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 260 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2262 "grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 261 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_fixed_bytes_kind(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2268 "grammar.c" /* yacc.c:1646  */
    break;

  case 47:
#line 262 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2274 "grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 263 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2280 "grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 264 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = (yyvsp[0].ndt); }
#line 2286 "grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 267 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Int8, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2292 "grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 268 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Int16, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2298 "grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 269 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Int32, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2304 "grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 270 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Int64, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2310 "grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 273 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Uint8, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2316 "grammar.c" /* yacc.c:1646  */
    break;

  case 55:
#line 274 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Uint16, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2322 "grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 275 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Uint32, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2328 "grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 276 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Uint64, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2334 "grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 279 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Float16, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2340 "grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 280 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Float32, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2346 "grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 281 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Float64, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2352 "grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 284 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Complex32, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2358 "grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 285 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Complex64, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2364 "grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 286 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_primitive(Complex128, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2370 "grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 290 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_from_alias(Intptr, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2376 "grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 291 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_from_alias(Uintptr, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2382 "grammar.c" /* yacc.c:1646  */
    break;

  case 66:
#line 292 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_from_alias(Size, (yyvsp[-1].uint32), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2388 "grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 295 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_char(Utf32, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2394 "grammar.c" /* yacc.c:1646  */
    break;

  case 68:
#line 296 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_char((yyvsp[-1].encoding), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2400 "grammar.c" /* yacc.c:1646  */
    break;

  case 69:
#line 299 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_string(ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2406 "grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 302 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_string((yyvsp[-1].string), Utf8, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2412 "grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 303 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_string((yyvsp[-3].string), (yyvsp[-1].encoding), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2418 "grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 306 "grammar.y" /* yacc.c:1646  */
    { (yyval.uint32) = 0; }
#line 2424 "grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 307 "grammar.y" /* yacc.c:1646  */
    { (yyval.uint32) = NDT_SYS_BIG_ENDIAN ? NDT_BIG_ENDIAN : NDT_LITTLE_ENDIAN; }
#line 2430 "grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 308 "grammar.y" /* yacc.c:1646  */
    { (yyval.uint32) = NDT_LITTLE_ENDIAN; }
#line 2436 "grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 309 "grammar.y" /* yacc.c:1646  */
    { (yyval.uint32) = NDT_BIG_ENDIAN; }
#line 2442 "grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 310 "grammar.y" /* yacc.c:1646  */
    { (yyval.uint32) = 0; }
#line 2448 "grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 313 "grammar.y" /* yacc.c:1646  */
    { (yyval.encoding) = encoding_from_string((yyvsp[0].string), ctx); if (ndt_err_occurred(ctx)) YYABORT; }
#line 2454 "grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 316 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_bytes((yyvsp[0].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2460 "grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 319 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_fixed_bytes((yyvsp[-1].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2466 "grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 322 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_ref((yyvsp[-1].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2472 "grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 323 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = ndt_ref((yyvsp[0].ndt), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2478 "grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 326 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_categorical((yyvsp[-1].typed_value_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2484 "grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 329 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value_seq) = ndt_value_seq_new((yyvsp[0].typed_value), ctx); if ((yyval.typed_value_seq) == NULL) YYABORT; }
#line 2490 "grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 330 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value_seq) = ndt_value_seq_append((yyvsp[-2].typed_value_seq), (yyvsp[0].typed_value), ctx); if ((yyval.typed_value_seq) == NULL) YYABORT; }
#line 2496 "grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 333 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value) = ndt_value_from_number(ValInt64, (yyvsp[0].string), ctx); if ((yyval.typed_value) == NULL) YYABORT; }
#line 2502 "grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 334 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value) = ndt_value_from_number(ValFloat64, (yyvsp[0].string), ctx); if ((yyval.typed_value) == NULL) YYABORT; }
#line 2508 "grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 335 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value) = ndt_value_from_string((yyvsp[0].string), ctx); if ((yyval.typed_value) == NULL) YYABORT; }
#line 2514 "grammar.c" /* yacc.c:1646  */
    break;

  case 88:
#line 336 "grammar.y" /* yacc.c:1646  */
    { (yyval.typed_value) = ndt_value_na(ctx); if ((yyval.typed_value) == NULL) YYABORT; }
#line 2520 "grammar.c" /* yacc.c:1646  */
    break;

  case 89:
#line 339 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Nonvariadic; }
#line 2526 "grammar.c" /* yacc.c:1646  */
    break;

  case 90:
#line 340 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Variadic; }
#line 2532 "grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 343 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Nonvariadic; }
#line 2538 "grammar.c" /* yacc.c:1646  */
    break;

  case 92:
#line 344 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Nonvariadic; }
#line 2544 "grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 345 "grammar.y" /* yacc.c:1646  */
    { (yyval.variadic_flag) = Variadic; }
#line 2550 "grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 348 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_tuple((yyvsp[-1].variadic_flag), NULL, NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2556 "grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 349 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_tuple((yyvsp[-1].variadic_flag), (yyvsp[-2].field_seq), NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2562 "grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 350 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_tuple(Nonvariadic, (yyvsp[-3].field_seq), (yyvsp[-1].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2568 "grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 353 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_new((yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2574 "grammar.c" /* yacc.c:1646  */
    break;

  case 98:
#line 354 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_append((yyvsp[-2].field_seq), (yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2580 "grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 357 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field(NULL, (yyvsp[0].ndt), NULL, ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2586 "grammar.c" /* yacc.c:1646  */
    break;

  case 100:
#line 358 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field(NULL, (yyvsp[-3].ndt), (yyvsp[-1].attribute_seq), ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2592 "grammar.c" /* yacc.c:1646  */
    break;

  case 101:
#line 361 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_record((yyvsp[-1].variadic_flag), NULL, NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2598 "grammar.c" /* yacc.c:1646  */
    break;

  case 102:
#line 362 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_record((yyvsp[-1].variadic_flag), (yyvsp[-2].field_seq), NULL, ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2604 "grammar.c" /* yacc.c:1646  */
    break;

  case 103:
#line 363 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_record(Nonvariadic, (yyvsp[-3].field_seq), (yyvsp[-1].attribute_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2610 "grammar.c" /* yacc.c:1646  */
    break;

  case 104:
#line 366 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_new((yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2616 "grammar.c" /* yacc.c:1646  */
    break;

  case 105:
#line 367 "grammar.y" /* yacc.c:1646  */
    { (yyval.field_seq) = ndt_field_seq_append((yyvsp[-2].field_seq), (yyvsp[0].field), ctx); if ((yyval.field_seq) == NULL) YYABORT; }
#line 2622 "grammar.c" /* yacc.c:1646  */
    break;

  case 106:
#line 370 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field((yyvsp[-2].string), (yyvsp[0].ndt), NULL, ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2628 "grammar.c" /* yacc.c:1646  */
    break;

  case 107:
#line 371 "grammar.y" /* yacc.c:1646  */
    { (yyval.field) = mk_field((yyvsp[-5].string), (yyvsp[-3].ndt), (yyvsp[-1].attribute_seq), ctx); if ((yyval.field) == NULL) YYABORT; }
#line 2634 "grammar.c" /* yacc.c:1646  */
    break;

  case 108:
#line 374 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2640 "grammar.c" /* yacc.c:1646  */
    break;

  case 109:
#line 375 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2646 "grammar.c" /* yacc.c:1646  */
    break;

  case 110:
#line 376 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2652 "grammar.c" /* yacc.c:1646  */
    break;

  case 111:
#line 379 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = NULL; }
#line 2658 "grammar.c" /* yacc.c:1646  */
    break;

  case 112:
#line 380 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = (yyvsp[-1].attribute_seq); if ((yyval.attribute_seq) == NULL) YYABORT; }
#line 2664 "grammar.c" /* yacc.c:1646  */
    break;

  case 113:
#line 383 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = ndt_attr_seq_new((yyvsp[0].attribute), ctx); if ((yyval.attribute_seq) == NULL) YYABORT; }
#line 2670 "grammar.c" /* yacc.c:1646  */
    break;

  case 114:
#line 384 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute_seq) = ndt_attr_seq_append((yyvsp[-2].attribute_seq), (yyvsp[0].attribute), ctx); if ((yyval.attribute_seq) == NULL) YYABORT; }
#line 2676 "grammar.c" /* yacc.c:1646  */
    break;

  case 115:
#line 387 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute) = mk_attr((yyvsp[-2].string), (yyvsp[0].string), ctx); if ((yyval.attribute) == NULL) YYABORT; }
#line 2682 "grammar.c" /* yacc.c:1646  */
    break;

  case 116:
#line 388 "grammar.y" /* yacc.c:1646  */
    { (yyval.attribute) = mk_attr_from_seq((yyvsp[-4].string), (yyvsp[-1].string_seq), ctx); if ((yyval.attribute) == NULL) YYABORT; }
#line 2688 "grammar.c" /* yacc.c:1646  */
    break;

  case 117:
#line 391 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_seq_new((yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2694 "grammar.c" /* yacc.c:1646  */
    break;

  case 118:
#line 392 "grammar.y" /* yacc.c:1646  */
    { (yyval.string_seq) = ndt_string_seq_append((yyvsp[-2].string_seq), (yyvsp[0].string), ctx); if ((yyval.string_seq) == NULL) YYABORT; }
#line 2700 "grammar.c" /* yacc.c:1646  */
    break;

  case 119:
#line 395 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2706 "grammar.c" /* yacc.c:1646  */
    break;

  case 120:
#line 396 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2712 "grammar.c" /* yacc.c:1646  */
    break;

  case 121:
#line 397 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2718 "grammar.c" /* yacc.c:1646  */
    break;

  case 122:
#line 398 "grammar.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); if ((yyval.string) == NULL) YYABORT; }
#line 2724 "grammar.c" /* yacc.c:1646  */
    break;

  case 123:
#line 401 "grammar.y" /* yacc.c:1646  */
    { (yyval.ndt) = mk_function((yyvsp[-2].type_seq), (yyvsp[0].type_seq), ctx); if ((yyval.ndt) == NULL) YYABORT; }
#line 2730 "grammar.c" /* yacc.c:1646  */
    break;

  case 124:
#line 404 "grammar.y" /* yacc.c:1646  */
    { (yyval.type_seq) = (yyvsp[0].type_seq); if ((yyval.type_seq) == NULL) YYABORT; }
#line 2736 "grammar.c" /* yacc.c:1646  */
    break;

  case 125:
#line 405 "grammar.y" /* yacc.c:1646  */
    { (yyval.type_seq) = ndt_type_seq_empty(ctx); if ((yyval.type_seq) == NULL) YYABORT; }
#line 2742 "grammar.c" /* yacc.c:1646  */
    break;

  case 126:
#line 408 "grammar.y" /* yacc.c:1646  */
    { (yyval.type_seq) = ndt_type_seq_new((yyvsp[0].ndt), ctx); if ((yyval.type_seq) == NULL) YYABORT; }
#line 2748 "grammar.c" /* yacc.c:1646  */
    break;

  case 127:
#line 409 "grammar.y" /* yacc.c:1646  */
    { (yyval.type_seq) = ndt_type_seq_append((yyvsp[-2].type_seq), (yyvsp[0].ndt), ctx); if ((yyval.type_seq) == NULL) YYABORT; }
#line 2754 "grammar.c" /* yacc.c:1646  */
    break;


#line 2758 "grammar.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, scanner, ast, meta, ctx, YY_("syntax error"));
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
        yyerror (&yylloc, scanner, ast, meta, ctx, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, scanner, ast, meta, ctx);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, scanner, ast, meta, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, scanner, ast, meta, ctx, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner, ast, meta, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, scanner, ast, meta, ctx);
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
