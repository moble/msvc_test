#include <stdio.h>
#include <math.h>
/* #include <complex.h> */
/* #include "config.h" */
#define FFTW_NO_Complex  /* with this, fftw just does `typedef double fftw_complex[2]` */
#include "fftw3.h"

int main() {
  int m;
  int lmax = 8;
  int Nm = 2*lmax+1;
  fftw_complex a = {0.1, 2.3};
  fftw_complex *c = fftw_malloc(Nm*sizeof(fftw_complex));

  for (m=0; m<Nm; m++) {
    /* c[m] = {0.0, 0.0}; */
    c[m][0] = 0.0;
    c[m][1] = 0.0;
  }

  printf("Made it to the end.\n");
  return 0;
}
