/*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 2 lexeical parser using flex
// created at: 10-11-2015
//  Assignment By:Deepak Gautam
//  Net ID: dg1308
*****************************************************************************/
%option noyywrap
%{
#include "lexer.h"
int yyLine = 1;
%}

DIGIT		[0-9]
LETTER		[a-zA-Z]
STRING_LITERAL	 \"(\\.|[^\\"])*\"
EOF_SL		\"(\\.|[^\\"])*

%%
"\r"|"\t"|" "	{} 
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

{LETTER}({LETTER}|{DIGIT}|_)* 	{return TOK_IDENTIFIER;}	/*Identifier can only start with letter but can have any number of digits or underscores afterward*/
({DIGIT})*("."(({DIGIT})+))?	{return TOK_FLOATLIT;}		/*Float Literal( both integer and float)  can have zero or more digits befor dot(.) and can have at least one or more digit after dot (.)*/
{STRING_LITERAL} 		{return TOK_STRINGLIT;}
{EOF_SL}			{return TOK_EOF_SL;}
[\n]      { yyLine++; }
.				{return TOK_UNKNOWN;}

<<EOF>> { return TOK_EOF;}
