/*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 2 example flex file
// created: 9-22-2015
//  author: J. Edward Swan II
*****************************************************************************/
%option noyywrap
%{
#include "lexer.h"
%}

DIGIT		[0-9]
LETTER		[a-zA-Z]
STRING_LITERAL	 \"(\\.|[^\\"])*\"
EOF_SL		\"(\\.|[^\\"])*

%%
"\n"|"\r"|"\t"|" "	{} 
if 		{return TOK_IF; }
else 		{return TOK_ELSE;}
for 		{return TOK_FOR;}
while 		{return TOK_WHILE;}
print 		{return TOK_PRINT;}
return 		{return TOK_RETURN;}
continue 	{return TOK_CONTINUE;}
break		{return TOK_BREAK;}
debug		{return TOK_DEBUG;}
read		{return TOK_READ;}
let		{return TOK_LET;}

int		{return TOK_INT;}
float		{return TOK_FLOAT;}
string		{return TOK_STRING;}

";"		{return TOK_SEMICOLON;}
","		{return TOK_COMMA;}
"("		{return TOK_OPENPAREN;}
")"		{return TOK_CLOSEPAREN;}
"{"		{return TOK_OPENBRACE;}
"}"		{return TOK_CLOSEBRACE;}
"["		{return TOK_OPENBRACKET;}
"]"		{return TOK_CLOSEBRACKET;}

"+"		{return TOK_PLUS;}
"-"		{return TOK_MINUS;}
"*"		{return TOK_MULTIPLY;}
"/"		{return TOK_DIVIDE;}

":="		{return TOK_ASSIGN;}
"=="		{return TOK_EQUALTO;}
"<"		{return TOK_LESSTHAN;}
">"		{return TOK_GREATERTHAN;}
"<>"		{return TOK_NOTEQUALTO;}
and		{return TOK_AND;}
or		{return	TOK_OR;}
not		{return TOK_NOT;}
length		{return TOK_LENGTH;}

{LETTER}({LETTER}|{DIGIT})* 	{return TOK_IDENTIFIER;}
({DIGIT})*			{return TOK_INTLIT;}
({DIGIT})*"."(({DIGIT})*)?	{return TOK_FLOATLIT;}
{STRING_LITERAL} 		{return TOK_STRINGLIT;}
{EOF_SL}			{return TOK_EOF_SL;}
.				{return TOK_UNKNOWN;}

<<EOF>> { return TOK_EOF; }
