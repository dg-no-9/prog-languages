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

// Maximum lexeme length
#define MAX_LEXEME_LEN 100

// List of token codes

#define TOK_EOF          5000  // end of file
#define TOK_EOF_SL       5001  // end of file while parsing string literal
#define TOK_UNKNOWN      6000  // unknown lexeme
#define TOK_IDENTIFIER   4000  //Identifier

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
#define TOK_SEMICOLON 2000
#define TOK_OPENPAREN   2001
#define TOK_CLOSEPAREN  2002
#define TOK_OPENBRACKET 2003
#define TOK_CLOSEBRACKET    2004
#define TOK_OPENBRACE   2005
#define TOK_CLOSEBRACE  2006
#define TOK_COMMA   2007

#endif

