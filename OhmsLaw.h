// Ohms Law Function
/* Function evaluates the Ohms Law Equation: V = IR, to solve for the missing value.
 Function takes in variables V, I , and R. These Values should be initilized to -1,
 and then assigned a value so that the program can determine which value is the
 missing value and solve for it*/

int OhmsLaw(double *V, double *I, double *R) {

    // V = IR, Solve for V
    if (*V < 0 && *I > 0 && *R > 0) {
        *V = *I * *R;
        return 0;
    }
    // I = V/R, Solve for I
    if (*I < 0 && *V > 0 && *R > 0) {
        *I = *V / *R;
        return 0;
    }
    // R = V/I, Solve for R
    if (*R < 0 && *V > 0 && *I > 0) {
        *R = *V/ *I;
        //printf("rvi!");
        return 0;
    }
    // if values are bad
     else {
        return -1; // program using function will require value >0
    }
}
