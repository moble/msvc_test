#include <complex>
// #define FFTW_NO_Complex /* fftw just does `typedef double fftw_complex[2]` */
#include "fftw3.h"

int main() {
  int m;
  int lmax = 8;
  int Nm = 2*lmax+1;
  fftw_complex a = {0.1, 2.3};
  // fftw_complex *c = fftw_malloc(Nm*sizeof(fftw_complex));  /* error C2440: 'initializing': cannot convert from 'void *' to 'fftw_complex (*)' */
  fftw_complex *c = (fftw_complex *) fftw_malloc(Nm*sizeof(fftw_complex));

  for (m=0; m<Nm; m++) {
    c[m] = {0.0, 0.0};  /* error C3863: array type 'fftw_complex' is not assignable */

    c[m] = fftw_complex(0.0, 0.0);

    c[m] = fftw_complex({0.0, 0.0});

    c[m] = (fftw_complex){0.0, 0.0};  /* error C4576: a parenthesized type followed by an initializer list is a non-standard explicit type conversion syntax */

    c[m][0] = 0.0;  /* works */
    c[m][1] = 0.0;

    /* Obviously, this one errors out differently if complex.h is not included */
    c[m] = _Dcomplex{0.0, 0.0};  /* error C2275: '_Dcomplex': illegal use of this type as an expression
        C:\Program Files (x86)\Windows Kits\10\include\10.0.19041.0\ucrt\complex.h(47): note: see declaration of '_Dcomplex'
        simple.c(56): error C2143: syntax error: missing ';' before '{'
        simple.c(56): error C2143: syntax error: missing ';' before '}' */

    /* Obviously, this one errors out differently if complex.h is not included */
    c[m] = 1.2 + 3.4 * I;  /* error C2088: '*': illegal for struct */
  }

  return 0;
}
