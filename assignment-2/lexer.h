/*** purpose: CSE 4713 / 6713 Assignment 1: Lexical Analyzer
created at: 10-11-2015
Assignment by: Deepak Gautam
NetID: dg1308
*****************************************************************************
*/
#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>


// List of token codes

#define TOK_EOF          5000  //Token ID of end of file
#define TOK_EOF_SL       5001  //Token ID for  end of file while parsing string literal
#define TOK_UNKNOWN      6000  //Token ID for unknown lexeme

/*Keywords*/
#define TOK_IF 		1001	//Token ID of 'if'
#define TOK_ELSE	1002	//Token ID of 'else'
#define TOK_FOR		1003	//Token ID of 'for'
#define TOK_WHILE	1004	//Token ID for 'while'
#define TOK_PRINT	1005	//Token ID for 'print'
#define TOK_RETURN	1006	//Token ID for 'return'
#define TOK_CONTINUE	1007	//Token ID for 'continue'
#define TOK_BREAK	1008	//Token ID for 'break'
#define TOK_DEBUG	1009	//Token ID for 'debug'
#define TOK_READ	1010	//Token ID for 'read'
#define TOK_LET		1011	//Token ID for 'let'

/*Datatype Specifiers*/
#define TOK_INT		1100	//Token ID for 'int'
#define TOK_FLOAT	1101	//Token ID for 'float'
#define TOK_STRING	1102	//Token ID for 'string'

/*Punctuations*/
#define TOK_SEMICOLON       2000	//Token ID for semicolon, ';'
#define TOK_OPENPAREN       2001	//Token ID for open parenthesis, '('
#define TOK_CLOSEPAREN      2002	//Token ID for closing parenthesis, ')'
#define TOK_OPENBRACKET     2003	//Token ID for open bracket, '['
#define TOK_CLOSEBRACKET    2004	//Token ID for close bracket, ']'
#define TOK_OPENBRACE       2005	//Token ID for open brace, '{'
#define TOK_CLOSEBRACE      2006	//Token ID for close brace, '}'
#define TOK_COMMA           2007	//Token ID for comma, ','

/*Operators*/
#define TOK_PLUS        3000		//Token ID for arithmatic plus operator, '+'
#define TOK_MINUS       3001		//Token ID for arithmatic minus operator, '-'
#define TOK_MULTIPLY    3002		//Token ID for arithmatic multiply operator, '*'
#define TOK_DIVIDE      3003		//Token ID for arithmatic divide operator, '/'

#define TOK_ASSIGN      3004		//Token ID for assignment operator, ':='
#define TOK_EQUALTO     3005		//Token ID for equal to operator, '='
#define TOK_LESSTHAN    3006		//Token ID for less than operator, '<' 
#define TOK_GREATERTHAN 3007		//Token ID for greater than operator, '>'
#define TOK_NOTEQUALTO  3008		//Token ID for not equal to operator, '<>'
#define TOK_AND         3009		//Token ID for logical and operator, 'and'
#define TOK_OR          3010		//Token ID for logical or operator, 'or'
#define TOK_NOT         3011		//Token ID for logical not operator, 'not'
#define TOK_LENGTH      3012		//Token ID for length operator, 'length'

/*Literals*/
#define TOK_IDENTIFIER      4000    //Token ID for identifiers
#define TOK_INTLIT          4001    //Token ID for Integer Literals
#define TOK_FLOATLIT        4002    //Token ID for Floating Point Literals
#define TOK_STRINGLIT       4003    //Token ID for String Literals

#endif

