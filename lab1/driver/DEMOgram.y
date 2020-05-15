
			/*prologue*/
%{
	#include <stdio.h>
       	int yylineno;
        int syntax_error = 0;
       	char *yytext;

       	int yylex();
       	void yyerror(char *errMsg);
%}


%error-verbose
		/*bison declarations*/
%token AND
%token BY
%token CHAR
%token ELSE
%token FOR
%token IF
%token INT
%token NOT
%token OR
%token PROCEDURE
%token READ
%token THEN
%token TO
%token WHILE
%token WRITE
%token LT
%token LE
%token EQ
%token NE
%token GT
%token GE
%token NAME
%token NUMBER
%token CHARCONST

%start Procedure
		/*grammar rules*/
%%
Procedure	: 	PROCEDURE NAME '{' Decls Stmts '}'
	  	| 	PROCEDURE NAME '{' Decls Stmts {
	  			syntax_error += 1;
				fprintf(stderr, "Parse Error: Missing '}' around line %d .\n", yylineno);
				yyclearin;
			}
		| 	PROCEDURE NAME '{' Decls Stmts '}' '}' {
				syntax_error += 1;
				fprintf(stderr, "Parse Error: Redundant '}' around line %d .\n", yylineno);
                       		yyclearin;
			}
;
Decls	:	Decls Decl ';'
	|	Decl ';'
;

Decl	:	Type SpecList
;

Type	:	INT
	|	CHAR
;

SpecList : 	SpecList ',' Spec
	|	Spec
;

Spec	:	NAME
	|	NAME '[' Bounds ']'
;

Bounds	:	Bounds ',' Bound
	|	Bound
;

Bound	:	NUMBER	':' NUMBER
;

Stmts	:	Stmts Stmt
	|	Stmt
;

Stmt	:	Assignment
	|	Matched_stmt
	|	Open_stmt
;

Matched_stmt:	IF '(' Bool ')' THEN Matched_stmt ELSE Matched_stmt
		|Assignment
;

Open_stmt:	IF '(' Bool ')' THEN Stmt
	|	IF '(' Bool ')' THEN Matched_stmt ELSE Open_stmt
;

Assignment:	Reference '=' Expr ';'
	|	'{' Stmts '}'
	|	'{'  '}'{
			syntax_error += 1;
			fprintf(stderr, "Parse Error: Empty expression around line %d .\n", yylineno);
        		yyclearin;
        	}
        |	';'{
        		syntax_error += 1;
        		fprintf(stderr, "Parse Error: Unexpected semicolon around line %d .\n", yylineno);
                        yyclearin;
        	}
	|	WHILE '(' Bool ')' '{' Stmts '}'
	|	FOR NAME '=' Expr TO Expr BY Expr '{' Stmts '}'
	|	READ Reference ';'
	|	WRITE Expr ';'
        | 	WRITE '=' Expr ';'{
        		syntax_error += 1;
        		fprintf(stderr, "Parse Error: cannot assign to a keyword  around line %d .\n", yylineno);
                	yyclearin;
        	}
        |	Expr '+' '='  Term{
        		syntax_error += 1;
        		fprintf(stderr, "Parse Error: '+=' is not allowed around line %d .\n", yylineno);
        		yyclearin;
        	}
        |	Expr '-' '='  Term{
        		syntax_error += 1;
       			fprintf(stderr, "Parse Error: '-=' is not allowed around line %d .\n", yylineno);
               		yyclearin;
                }
        |	Expr '*' '='  Term{
        		syntax_error += 1;
                       	fprintf(stderr, "Parse Error: '*=' is not allowed around line %d .\n", yylineno);
                        yyclearin;
        	}
        |	Expr '/' '='  Term{
        		syntax_error += 1;
                       	fprintf(stderr, "Parse Error: '/=' is not allowed around line %d .\n", yylineno);
                        yyclearin;
        	}
       	|       Reference Expr ';'{
        	  	syntax_error += 1;
                  	fprintf(stderr, "Parse Error: not a keyword around line %d .\n", yylineno);
                  	yyclearin;
        	}
	|	error ';'
;

Bool	:	NOT OrTerm
	|	OrTerm
;

OrTerm	:	OrTerm OR AndTerm
	|	AndTerm
;

AndTerm	:	AndTerm	AND RelExpr
	|	RelExpr
;

RelExpr	:	RelExpr	LT Expr
	|	RelExpr	LE Expr
	|	RelExpr	EQ Expr
	|	RelExpr	NE Expr
	|	RelExpr	GE Expr
	|	RelExpr	GT Expr
	|	Expr
;

Expr	:	Expr '+' Term
	|	Expr '-' Term
	|	Term
;

Term	:	Term '*' Factor
	|	Term '/' Factor
	|	Factor
;

Factor	:	'(' Expr ')'
	|	Reference
	|	NUMBER
	|	CHARCONST
;

Reference :	NAME
	  |	NAME '[' Exprs ']'
;

Exprs	:	Expr ',' Exprs
	|	Expr
;
%%
					/*Epilogue*/
/* read more files, if meet error, output 0 and read other files, when it returns 1, it means ending*/

int yywrap() {
    return 1;
}

//print error
void yyerror(char *errMsg) {
    syntax_error += 1;
    fprintf(stderr, "Error: '%s' around line %d.\n", errMsg, yylineno);
    yyclearin;
}
