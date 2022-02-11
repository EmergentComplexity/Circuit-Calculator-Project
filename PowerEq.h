// Power Equation Fuction
/* Function evaluates the Power Equation: P = IV, to solve for the missing value.
 Function takes in variables P, I , and V. These Values should be initilized to -1,
 and then assigned a value so that the program can determine which value is the
 missing value and solve for it*/
double PowerEq(double P, double I, double V) {

    // P = IV, Solve for P
    if (P < 0 && I > 0 && V > 0) {
        P = I * V;
        return P;
    }
    // I = V/P, Solve for I
    if (I < 0 && P > 0 && V > 0) {
        I = V/P;
        return I;
    }
    // V = P/I, Solve for V
    if (V < 0 && P > 0 && I > 0) {
        V = P/I;
        return V;
    }
    // if values are bad
     else {
        return -1;
    }
}
