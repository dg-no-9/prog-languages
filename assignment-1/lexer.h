//*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 1: Lexical Analyzer
// created: 8-25-2015
//  author: J. Edward Swan II
//*****************************************************************************

#ifndef LEXER_H
#define LEXER_H

// Include standard IO streams
#include <stdio.h>

// The lexical analyzer global variables and functions
extern int   yylex();
extern FILE *yyin;         // input stream
extern FILE *yyout;        // output stream
extern int   yyleng;       // length of current lexeme
extern char *yytext;       // text of current lexeme

extern const char* keywords[];
extern const char* operator_keywords[];
extern const char* datatype_keywords[];
extern const char punctuations[];

#define keywords_size (sizeof (keywords) / sizeof (const char *))
#define op_keywords_size (sizeof (operator_keywords) / sizeof (const char *))
#define datatype_keywords_size (sizeof (datatype_keywords) / sizeof (const char *))
#define punctuations_size (sizeof(punctuations)/ sizeof (const char))
// Maximum lexeme length
#define MAX_LEXEME_LEN 100

// List of token codes

#define TOK_EOF          5000  // end of file
#define TOK_EOF_SL       5001  // end of file while parsing string literal
#define TOK_UNKNOWN      6000  // unknown lexeme

/*Keywords*/
#define TOK_IF 		1001
#define TOK_ELSE	1002
#define TOK_FOR		1003
#define TOK_WHILE	1004
#define TOK_PRINT	1005
#define TOK_RETURN	1006
#define TOK_CONTINUE	1007
#define TOK_BREAK	1008
#define TOK_DEBUG	1009
#define TOK_READ	1010
#define TOK_LET		1011

/*Datatype Specifiers*/
#define TOK_INT		1100
#define TOK_FLOAT	1101
#define TOK_STRING	1102

/*Punctuations*/
#define TOK_SEMICOLON       2000
#define TOK_OPENPAREN       2001
#define TOK_CLOSEPAREN      2002
#define TOK_OPENBRACKET     2003
#define TOK_CLOSEBRACKET    2004
#define TOK_OPENBRACE       2005
#define TOK_CLOSEBRACE      2006
#define TOK_COMMA           2007

/*Operators*/
#define TOK_PLUS        3000
#define TOK_MINUS       3001
#define TOK_MULTIPLY    3002
#define TOK_DIVIDE      3003

#define TOK_ASSIGN      3004
#define TOK_EQUALTO     3005
#define TOK_LESSTHAN    3006
#define TOK_GREATERTHAN 3007
#define TOK_NOTEQUALTO  3008
#define TOK_AND         3009
#define TOK_OR          3010
#define TOK_NOT         3011
#define TOK_LENGTH      3012

/*Literals*/
#define TOK_IDENTIFIER      4000    //Identifiers
#define TOK_INTLIT          4001    //Integer Literals
#define TOK_FLOATLIT        4002    //Floating Point Literals
#define TOK_STRINGLIT       4003    //String Literals

#endif

