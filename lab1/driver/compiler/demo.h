/* include file for the DEMO parser */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *LOG;     /* LogFile, used to record debugging and other info */

char *code_file_name;
char *sl_file_name;

char basename[128];
int  Debug;
int  syntax_error;
int  Verbose;
int  TrackValues;
int  TrackRegisters;
int  TrackBuffers;
int  LastPreassignedRegister;

char TokenString[128];
char *ProcedureName;

/* some interface definitions */
char *TimeStamp();
void Setup( FILE *f, char *name, int t );
void SetupAndMark( FILE *f, char *name, int t );
char *ssave( char *s );
void  sfree( char *s );

/* some declarations on the flex-bison interface */
extern int yylex(void);
void yyerror( const char *s );
int  yyparse();

void die();

struct VALUE {
  int ordinal;
  int index;
  int type;
  int reg;
  int literal;
  int address;
  int lifetime;
  struct VALUE *next;
 };

