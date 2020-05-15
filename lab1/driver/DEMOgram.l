                                        /*definitions*/
%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tokens.h"
    #ifdef FLEX_SCANNER
        extern int yylineno;
        #define YYINCR(n) yylineno += n
    #else
       #define YYINCR(n)
    #endif
    extern YYSTYPE yylval;
%}


                                        /*rules*/
%%
"and"         {return AND;}
"by"          {return BY;}
"char"        {return CHAR;}
"else"        {return ELSE;}
"for"         {return FOR;}
"if"          {return IF;}
"int"         {return INT;}
"not"         {return NOT;}
"or"          {return OR;}
"procedure"   {return PROCEDURE;}
"read"        {return READ;}
"then"        {return THEN;}
"to"          {return TO;}
"while"       {return WHILE;}
"write"       {return WRITE;}
"<"         {return LT;}
"<="          {return LE;}
"=="          {return EQ;}
"!="        {return NE;}
">"          {return GT;}
">="          {return GE;}
"+"         {return '+';}
"-"       {return '-';}
"*"       {return '*';}
"/"       {return '/';}
"="      {return '=';}
":"       {return ':';}
";"   {return ';';}
","       {return ',';}
"("     {return '(';}
"["     {return '[';}
"{"     {return '{';}
")"     {return ')';}
"]"     {return ']';}
"}"     {return '}';}


[A-Za-z][A-Za-z0-9]*        {yylval = *yytext; return NAME;}
[0-9]+|[0-9][0-9]*        {yylval = *yytext; return NUMBER;}
['][A-Za-z0-9]+[']   {yylval = *yytext; return CHARCONST;}
'\\n'       {yylval = *yytext; return CHARCONST;}
[\n]       {YYINCR(1);}
[\t]+       ;
"//".*		;
%%
