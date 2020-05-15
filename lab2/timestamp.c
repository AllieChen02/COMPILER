#include "demo.h"
#include <time.h>
#include <unistd.h>

/* code lifted freely and legally from the PACE Resource Characterization
 * tools ... written by KDC during PACE
 *
 */

char *CodeBase;

char *TimeStamp()
{
  time_t    t;
  char *p, *q;

  t = time(NULL);
  q = asctime(localtime(&t));

  /* get rid of the line feed at end of 'q' */
  p = q;
  while(*p != '\0')
  {
    if (*p == '\n')
    {
      *p = '\0';
      break;
    }
    p++;
  }

  return q;
}

/* The top of each log file should begin with a record of 
 * the machine, the date, and the code base.
 *
 */

void Setup( FILE *f, char *name, int t ) {
  if (f == NULL)
  {
    fprintf(stderr, "Setup( %s) passed NULL FILE pointer.\n",name);
    fprintf(stderr, "Redirected to 'stderr'.\n");
    f = stderr;
  }
  else { /* turn off buffering */
    if (setvbuf(f, NULL, _IONBF, 0) == EOF) {
      if (t) 
	fprintf(LOG,"\t%s is buffered.\n",name);
      else
	fprintf(LOG,"%s is buffered.\n",name);
    }
    else {
      if (t)
	fprintf(LOG,"\t%s is unbuffered.\n",name);
      else
	fprintf(LOG,"%s is unbuffered.\n",name);
    }
  }
}


void SetupAndMark( FILE *f, char *name, int t )
{
  char hn[128];  /* buffer to hold hostname */

  Setup( f, name, t);

  /* now, mark the file. */
  (void) gethostname(hn,128);
  fprintf(f,"\nCOMP 506 DEMO Compiler\nRun on '%s' at %s\nUsing code base %s\n\n",
	  hn,TimeStamp(),CodeBase);

}
