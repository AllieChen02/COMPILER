/* The DEMO parser */

#include "demo.h"

char *CodeBase = "R02.02";

static char *InputFile;

static void help_message( char *p ) {
  fprintf(stdout,"Syntax: %s [-d] [filename]\n",p);
  fprintf(stdout,"\t-d increments debugging flag.\n");
  fprintf(stdout,"\tif 'filename' is omitted %s reads from 'stdin'.\n\n",p);
  exit(-1);
}

static void truncate_filename( char *filename ) {
  char *p;
  int count;

  p = filename;
  count = 0;

  while( *p != '\0' ) {
    if (*p == '.')
      count++;
    p++;
  }
  if (count > 0) {
    while( p != filename ) {
      if (*p == '.') {
	*p = '\0';
	p--;
	break;
      }
      p--;
    }
  }
  if (Debug > 1)
    fprintf(LOG,"Input file basename is '%s'.\n",filename);
}

static void Initialize( char *bn ) {
  char fn[128];

  fprintf(stdout,"COMP 506 DEMO Compiler\n");

  /* for the moment, make stdout unbuffered */
  Setup(stdout, "stdout",1);
  fprintf(LOG,"\n");
}

char *TypeNames[] = {"unknown","int","char","boolean","procedure"};

int main( int argc, char **argv ) {
  int count, file;
  char *p, *filename;
  FILE *infile;

  LOG = fopen("./LogFile","w");
  SetupAndMark(LOG,"LogFile",0);
  fprintf(LOG,"File disposition:\n");

  file = 0;
  Debug = 0;
  syntax_error = 0;
  Verbose = 0;
  TrackValues = 0;
  TrackRegisters = 0;
  TrackBuffers = 0;
  LastPreassignedRegister = 0;

  count = 1;

  while (count < argc) {
    if (*argv[count] == '-') {
      p = argv[count];
      p++;
      switch(*p) {
      case 'd':
	Debug++;
	break;
      default: 
	fprintf(stderr,"Command-line flag '%c' not recognized.\n",*p);
	help_message(argv[0]);
	break;
      }
    }
    else { /* a filename */
      if (file > 0)
	help_message(argv[0]);

      file = 1;
      filename = ssave(argv[count]);
      fprintf(LOG,"\topening file '%s'\n",filename);
      infile = freopen(filename,"r",stdin);
      if (infile == NULL) {
	fprintf(LOG,"\tFile open of '%s' failed. Reading stdin instead.\n",
		filename);
	fprintf(stderr,"File open of '%s' failed. Reading stdin instead.\n",
		filename);
	file = 0;
      }
      else {
	InputFile = ssave(filename);
	truncate_filename(filename);
	stdin = infile;
      }
    }
    count++;
  }

  if (file == 0) {
    filename = ssave("stdin");
    InputFile = filename;
    fprintf(LOG,"\tReading from stdin.\n");
  }

//  Initialize(filename);

  yyparse();

  if (syntax_error == 0) {
    fprintf(stderr,"Parser succeeds.\n");
  }
  else { /* first, complain */
    fprintf(stderr,"\nParser fails with %d error messages.\nExecution halts.\n",
	    syntax_error);
    fprintf(LOG,"\nParser fails with %d error messages.\nExecution halts.\n",
	    syntax_error);

    die(); /* then, quit */
  }
}

void die() {
    /* delete the CODE and SLFILE files */
    fprintf(LOG,"Due to errors, deleting files %s and %s\n",
	    code_file_name,sl_file_name);
    exit(-1);
}

char *ssave( char *s ) {
  char *ns = (char*) malloc(strlen(s)+1);
  (void) strcpy(ns,s);
  return s;
}

void sfree( char *s ) {
  free(s);
}
