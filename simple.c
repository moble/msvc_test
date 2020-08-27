/* #include <complex.h> */
/* #include "config.h" */
/* #define FFTW_NO_Complex  /\* with this, fftw just does `typedef double fftw_complex[2]` *\/ */
#include "fftw3.h"

int main() {
  int m;
  int lmax = 8;
  int Nm = 2*lmax+1;
  fftw_complex a = {0.1, 2.3};
  fftw_complex *c = fftw_malloc(Nm*sizeof(fftw_complex));

  for (m=0; m<Nm; m++) {
    /*************************************/
    /* no complex.h; no FFTW_NO_Complex  */
    /*************************************/
    c[m] = {0.0, 0.0};

    c[m][0] = 0.0;
    c[m][1] = 0.0;

    c[m] = (fftw_complex){0.0, 0.0};


    /*************************************/
    /* No complex.h; FFTW_NO_Complex     */
    /*************************************/
    /* c[m] = {0.0, 0.0}; */  /* error C2059: syntax error: '{' */

    /* c[m][0] = 0.0; */  /* works (but linking fftw_malloc fails) */
    /* c[m][1] = 0.0; */

    /* c[m] = (fftw_complex){0.0, 0.0}; */  /* error C2106: '=': left operand must be l-value */


    /*************************************/
    /* complex.h; FFTW_NO_Complex        */
    /*************************************/
    c[m] = {0.0, 0.0};

    c[m][0] = 0.0;
    c[m][1] = 0.0;

    c[m] = (fftw_complex){0.0, 0.0};


    /*************************************/
    /* complex.h                         */
    /*************************************/
    c[m] = {0.0, 0.0};

    c[m][0] = 0.0;
    c[m][1] = 0.0;

    c[m] = (fftw_complex){0.0, 0.0};
  }

  return 0;
}
