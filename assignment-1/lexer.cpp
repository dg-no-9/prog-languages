//*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 1: Lexical Analyzer
// created: 8-25-2015
//  author: J. Edward Swan II
//*****************************************************************************
#include "lexer.h"
#include <ctype.h>
#include <assert.h>
#include <string.h>

int is_keyword(char*);
int is_punctuation(char);
//*****************************************************************************
// Do the lexical parsing
char lexeme[MAX_LEXEME_LEN];  // Character buffer for lexeme
int yylex()
{
  static char c = -1;         // Have we read the first character yet?
  int char_type;              // Hold the character type
  int token_id=0;
  //yyleng = 0
  // Prepare the buffer to hold the lexeme
  for( int i = 0; i < MAX_LEXEME_LEN; i++ )
    lexeme[i] = '\0';
  yytext = lexeme;
  yyleng = 0;

  // If the very first character has not yet been read, read it
  if( c < 0 )
    c = fgetc( yyin );

  // Test for end of file
  if( feof(yyin) ) {
    // Ready for next time
    c = -1;
    // Done!
    return( TOK_EOF );
  }

  if(isalpha(c))
  {
  	// Store current character and read the next
  	lexeme[yyleng++] = c;
  	c = fgetc( yyin );
        while(isalpha(c) || isdigit(c) || c == '_') // If character is alphabet or digit or underscore, add and get next, else endof while loop, return Identifier Token.
        {
		lexeme[yyleng++]=c;
    		c = fgetc( yyin );
        }
        if((token_id = is_keyword(lexeme)) != 0)
        {
       		return token_id;
        }
        else
	{
            return TOK_IDENTIFIER;
        }
  }
  else if ((token_id=is_punctuation(c)) != 0)
  {
    lexeme[yyleng++] = c;
    c = fgetc( yyin );
    return token_id;
  }
  else
  {
      	//lexeme[yyleng++] = c;
  	c = fgetc ( yyin );
	//return( TOK_UNKNOWN );
  }
  // We don't yet know how to recognize any lexemes
}

int is_punctuation(char current_token)
{
    if (current_token== ';')
    {
        return TOK_SEMICOLON;
    }
    if (current_token== '(')
    {
        return TOK_OPENPAREN;
    }
    if (current_token== ')')
    {
        return TOK_CLOSEPAREN;
    }
    if (current_token== '[')
    {
        return TOK_OPENBRACKET;
    }
    if (current_token== ']')
    {
        return TOK_CLOSEBRACKET;
    }
    if (current_token== '{')
    {
        return TOK_OPENBRACE;
    }
    if (current_token== '}')
    {
        return TOK_CLOSEBRACE;
    }

    return 0;

}
int is_keyword(char* current_token)
{
   if (strcmp(current_token, "if")==0)
   {
      return TOK_IF;
   }
   else if(strcmp(current_token, "else")==0)
   {
     return TOK_ELSE;
   }
   else if(strcmp(current_token, "for")==0)
   {
     return TOK_FOR;
   }

   else if(strcmp(current_token, "while")==0)
   {
     return TOK_WHILE;
   }

   else if(strcmp(current_token, "print")==0)
   {
     return TOK_PRINT;
   }

   else if(strcmp(current_token, "return")==0)
   {
     return TOK_RETURN;
   }

   else if(strcmp(current_token, "continue")==0)
   {
     return TOK_CONTINUE;
   }

   else if(strcmp(current_token, "break")==0)
   {
     return TOK_BREAK;
   }

   else if(strcmp(current_token, "debug")==0)
   {
     return TOK_DEBUG;
   }
   else if(strcmp(current_token, "read")==0)
   {
     return TOK_READ;
   }

   else if(strcmp(current_token, "int")==0)
   {
     return TOK_INT;
   }

   else if(strcmp(current_token, "float")==0)
   {
     return TOK_FLOAT;
   }

   else if(strcmp(current_token, "string")==0)
   {
     return TOK_STRING;
   }

   return 0;
}
