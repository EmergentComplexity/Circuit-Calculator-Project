

// Cutoff Frequency function.
/*function evaluates the cutoff frequency equation Fc = 1/(2piRC)
  function guesses different capacitor values to use. If given a Fc value,
 it will compute the R value for the given list of capacitor values */
#define pi 3.14
#include <stdio.h>

double CutoffFreq(double *Fc, double *R, double *C) {




  // Fc = 1/(2piRC), Solve for Fc
  if (*Fc < 0 && *R > 0 && *C > 0) {
      *Fc = 1/(2 * pi * *R * *C);
      return *Fc;
  }
  // R = 1/(2piFcC), Solve for R
  if (*R < 0 && *Fc > 0 && *C > 0) {
      *R = 1/(2 * pi * *Fc * *C);
      return * R;
  }

  // if values are bad
   else {
      return -1; // program using function will require value >0
  }

}
