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
int is_uoperator(char);
//*****************************************************************************
// Do the lexical parsing
char lexeme[MAX_LEXEME_LEN];  // Character buffer for lexeme

const char* keywords[] = {"if","else", "for","while","print","return","continue","break","debug","read","let"}; //language keywords, Token Id starts from 1001
const char* operator_keywords[] = {"and","or","not","length"}; //operator keywords, Token Id starts from 3009
const char* datatype_keywords[] = {"int","float","string"}; //data type keywords, Token Id starts from 3009
const char punctuations[] = {';','(',')','[',']','{','}',','};

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
  if( feof(yyin) )
  {
    // Ready for next time
    c = -1;
    // Done!
    return( TOK_EOF );
  }

  if (isspace(c) != 0)      //If whitespace is encountered, eat the character, and move pointer to next character.
  {
    c = fgetc(yyin);
  }

  if(isalpha(c))            //Check for indentifiers and keywords, enter if character encountered is alphabet.
  {
  	// Store current character and read the next
  	lexeme[yyleng++] = c;
  	c = fgetc( yyin );
        while(isalpha(c) || isdigit(c) || c == '_') // If character is alphabet or digit or underscore, add and get next, else endof while loop, return Identifier Token.
        {
            lexeme[yyleng++]=c;
    		c = fgetc( yyin );
        }
        if((token_id = is_keyword(lexeme)) != 0) //If lexeme is keyword, return respective token id, else return as identifier.
        {
       		return token_id;
        }
        else
        {
            return TOK_IDENTIFIER;
        }
  }

  if(isdigit(c))        //Check for integer and floating point integers, enter if character encountered is digit.
  {
    // Store current character and read the next
  	lexeme[yyleng++] = c;
  	c = fgetc( yyin );
        while(isdigit(c)) // If character is digit, add and get next character, else endof while loop, return integer literal Token.
        {
            lexeme[yyleng++]=c;
    		c = fgetc( yyin );
        }
        if(c != '.')
            return TOK_INTLIT;
        else
        {
            lexeme[yyleng++] = c;
            c = fgetc( yyin );
            while(isdigit(c))
            {
                lexeme[yyleng++] = c;
                c = fgetc( yyin );
            }
            return TOK_FLOATLIT;
        }

  }

  if(c == '"')
  {
    lexeme[yyleng++] = c;
    c = fgetc( yyin );
    while(c != '"' && yyleng < MAX_LEXEME_LEN - 1) //Add up all characters to lexeme till ending quote is encountered or maxmum lexeme length limit is reached.
    {
        lexeme[yyleng++] = c;
        c = fgetc ( yyin );
    }
    lexeme[yyleng++] = c;
    c = fgetc( yyin );
    return TOK_STRINGLIT;
  }

  if ((token_id=is_punctuation(c)) != 0) //Check for punctuation tokens.
  {
    lexeme[yyleng++] = c;
    c = fgetc( yyin );
    return token_id;
  }

  if ((token_id=is_uoperator(c)) != 0) //Check for mathematical operators
  {
    lexeme[yyleng++] = c;
    c = fgetc(yyin);
    return token_id;
  }

  if (c == ':') //Check for assignment operator
  {
    lexeme[yyleng++] = c;
    c = fgetc(yyin);
    if(c == '=')
    {
        lexeme[yyleng++] = c;
        c = fgetc(yyin);
        return TOK_ASSIGN;
    }
    return TOK_UNKNOWN;
  }

  if (c == '=') //Check for equalsto operator
  {
    lexeme[yyleng++] = c;
    c = fgetc(yyin);
    if(c == '=')
    {
        lexeme[yyleng++] = c;
        c = fgetc(yyin);
        return TOK_EQUALTO;
    }
    return TOK_UNKNOWN;
  }

  if (c == '<') //Check for check for less than and not equals operator
  {
    lexeme[yyleng++] = c;
    c = fgetc(yyin);
    if(c == '>')
    {
        lexeme[yyleng++] = c;
        c = fgetc(yyin);
        return TOK_NOTEQUALTO;
    }
    else return TOK_LESSTHAN;
  }

  if(c == '>') //Check for greater than operator.
  {
    lexeme[yyleng++] = c;
    c = fgetc(yyin);
    return TOK_GREATERTHAN;
  }

    //Token is not recognized by lexer, continue reading next character token.

    lexeme[yyleng++] = c;
    c = fgetc ( yyin );
    return( TOK_UNKNOWN );

}

int is_keyword(char* current_token)
{
    int i;
    /*Check for basic language keywords*/
    for(i =0; i < keywords_size; i++)
    {
        if (strcmp(current_token, keywords[i]) == 0)
        {
            return 1001 + i;    //Keyword Token ID starts from 1001.
        }
    }

    /*Check for operator keywords*/
    for (i = 0; i < op_keywords_size; i++)
    {
        if (strcmp(current_token, operator_keywords[i]) == 0)
        {
            return 3009 + i;       //Operator keywords token id starts from 3009
        }
    }

    /*Check for datatype keywords*/
    for (i = 0; i < datatype_keywords_size; i++)
    {
        if (strcmp(current_token, datatype_keywords[i]) == 0)
        {
            return 1100 + i;       //Datatype keywords token id starts from 1100
        }
    }
}

int is_uoperator(char current_token)
{
   int token_id = 0;
    switch(current_token)
    {
        case '+':
            token_id = TOK_PLUS;
            break;

        case '-':
            token_id = TOK_MINUS;
            break;

        case '*':
            token_id = TOK_MULTIPLY;
            break;

        case '/':
            token_id = TOK_DIVIDE;
            break;

        default:
            break;
    }
    return token_id;

}

int is_punctuation(char current_token)
{
    int i;
    for (i = 0; i < punctuations_size; i++)
    {
        if (current_token == punctuations[i])
        {
            return 2000 + i;
        }
    }

}
