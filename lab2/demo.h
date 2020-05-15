/* include file for the DEMO parser */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

#define CHILD_NUM 20

#define INVALID -1
#define TYPE_UNK  0
#define TYPE_INT  1
#define TYPE_CHAR   2
#define NODE_NAME 3

#define NODE_STATEMENTS 9
#define NODE_ASSIGN 10
#define NODE_PLUS 11
#define NODE_MINUS 12
#define NODE_TIMES 13
#define NODE_DIVIDE 14

#define NODE_WRITE 15

#define NODE_LT 16
#define NODE_LE 17
#define NODE_EQ 18
#define NODE_NE 19
#define NODE_GT 20
#define NODE_GE 21
#define NODE_OR 22
#define NODE_AND 23
#define NODE_NOT 24

#define NODE_IF 25
#define NODE_IF_ELSE 26
#define NODE_WHILE 27
#define NODE_READ 28
#define NODE_WRITE 29

/* some interface definitions */
char *TimeStamp();
void Setup( FILE *f, char *name, int t );
void SetupAndMark( FILE *f, char *name, int t );
char *ssave( char *s );
void  sfree( char *s );

/* some declarations on the flex-bison interface */
extern int yylex(void);
void yyerror( char *s );
int  yyparse();

void die();

struct NODE {
	int node_type;      /* ex. add, assign, if, while...*/
	char *var_name;     /* used in write and assign nodes*/
	int var_val;        /* value of variable op node */
	int var_type;       /* type of variable */
	struct NODE * children[CHILD_NUM];
    int child_num;
};

#define NODENULL (struct NODE*)-1

struct NODE *make_leaf_node(int node_type, char *var_name, int var_value);
struct NODE *make_op_node(int t, struct NODE *children[], int child_num);
void add_sybling_node( struct NODE *root, struct NODE *sybling);
struct NODE *copy_node( struct NODE *orig );

struct symrec {
	char *name;   /* var_name of symbol */
    int type;     /* node_type of symbol */
	int val;  /* pointer to the node in AST*/
	struct symrec *next; /* link field */
	int isInitialize;
};

struct symrec *putsym (char const *name, int const type, int val);
struct symrec *getsym (char const *name);
struct symrec *sym_table;
void walk(struct NODE* root);

int cur; // this should convey the node_type to variables in declaration