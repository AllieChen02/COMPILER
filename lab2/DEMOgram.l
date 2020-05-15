%{

 /* DEMO parser (parser for the language "DEMO")
  * Copyright 2015, Keith D. Cooper 
  * 
  * Written at Rice University, Houston, Texas.
  * The University may have some rights in this work.
  *
  */

#ifdef FLEX_SCANNER
extern int yylineno;
#define YYINCR(n) yylineno += n
#else
#define YYINCR(n)
#endif

#include "tokens.h"
#include "strings.h"
#include "demo.h"

int CTRL_M = 0;

%}
%%
"by"                          { return BY; }
"char"                        { return CHAR; }
":"                           { return COLON; }
","                           { return COMMA; }
"="                           { return EQUALS; }
"for"                         { return FOR; }
"int"                         { return INT; }
"{"                           { return LBRACKET; }
"}"                           { return RBRACKET; }
"("                           { return LPAREN; }
")"                           { return RPAREN; }
"["                           { return LSQUARE; }
"]"                           { return RSQUARE; }

"-"                           { return MINUS; }
"+"                           { return PLUS; }
"*"                           { return TIMES; }
"/"                           { return DIVIDE; }

"read"                        { return READ; }
"write"                       { return WRITE; }

"procedure"                   { return PROCEDURE; }

"<"                           { return LT; }
"<="                          { return LE; }
"=="                          { return EQ; }
"!="                          { return NE; }
">"                           { return GT; }
">="                          { return GE; }
"and"                         { return AND; }
"or"                          { return OR; }
"not"                         { return NOT; }


";"                           { return SEMICOLON; }

"to"                          { return TO; }
"while"                       { return WHILE; }
"if"                          { return IF; }
"then"                        { return THEN; }
"else"                        { return ELSE; }

[\n]                          { YYINCR(1); }
[A-Za-z][A-Za-z0-9]*	      {
                                (void) strcpy(TokenString,yytext);
			        return NAME;
			      }
[0-9]+                        { (void) strcpy(TokenString,yytext);
                                return NUMBER; 
                              }

'[ -~]'                 { (void) strcpy(TokenString,yytext);
                                return CHARCONST;
                              }
'\\[abfnrtv0]'                    { (void) strcpy(TokenString,yytext);
                                return CHARCONST;
                              }

\/\/[^\n]*                    { /* Comment */}

[ \t]+                        ;
.                             { 
                                char this = *yytext;
                                if (this == 0xd && 0 == CTRL_M++)
                                   fprintf(stderr,"CTRL/LF problem\n");
                                else
                                   (void) strcpy(TokenString,yytext);
                                   return UNKNOWN;
			           
                              }

<<EOF>>   {return ENDOFFILE;}
