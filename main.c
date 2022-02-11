
// Peter Sanchez Final Project

/*
The purpose of this program is to take an input line and run an equation for electrical measurements.
The program first copies data from the line into  3 strings. The first string is a command and the other 2 are values
the command in the first string is used to determine which equation will be operated. The program can preform
*   the equation for Ohms Law (V = IR) and the equation for cutoff frequency Fc = 1/(2piRC).
    The given values to compute
*   with are originally taken in as strings and are changed into a double using a function to get the number represented by the strings.
    Additionally the strings for the values contain the unit that is represented by the numerical value.  The program also allows
    units such as mV, uF etc.... instead of just V,F,etc. These are units are converted to their base units using another function
    all of these characteristics of a value are stored in the value structure.
*   The values are then inserted into the equation called for by the first string. The program automatically determines which
    value is being solved for based on the units of the value

    See functions for commments on their individual operation



*/





#define MAX 100
#include <stdio.h>
#include "OhmsLaw.h"         // Ohms Law function reads in values as double V, double I, double R
#include "StringToDouble.h"
#include "PrintCommandList.h"
#include "CutoffFreq.h"
typedef struct values {
    double valNum; // the actual number
    int conversion; // what to units to convert to if a conversion is required
    int placeVal; // the place value of the number, represents value * 10^placeVal
    int unit; // Carries an integer representation of the unit of the value
} value;
// Ex: OhmsLaw R=15ohms v=2v
// the program will return the value of i
int main() {
    // variable declarations
    value val1; // create a value to store data from inputstring 2
    value val2; // create a value to store data from inputstring 3
    char inputstring1 [MAX];
    char inputstring2 [MAX];
    char inputstring3 [MAX];
    char unitString [20]; // prints units
    char valueString [20];
    value output; // value for the output of the executed function






    // while loop to exit the program
    while(!(inputstring1[0] == 69)){
        printf("Enter input Press E to exit ");
     // read in the first string that is typed
      scanf("%s",inputstring1 );
      if(inputstring1[0] == 69){
          return  0;
      }
      // read in the second string that is typed
      scanf("%s",inputstring2 );
      // read in the third string that is typed
      scanf("%s", inputstring3);

      // determine which string is the command and which strings are the values
      // the first string read in will be the command



      //stringToDouble is used to fill the variables in val 1
      //void StringToDouble(char *string[],double* value, int* conversion, int* placeVal, int* unit)
     StringToDouble(inputstring2, &val1.valNum, &val1.conversion, &val1.placeVal, &val1.unit );


     //stringToDouble is used to fill the variables in val 2
      //void StringToDouble(char *string[],double* value, int* conversion, int* placeVal, int* unit)
      StringToDouble(inputstring3, &val2.valNum, &val2.conversion, &val2.placeVal, &val2.unit );

       // now that the values are assigned, The function to be used can be determined from the inputstring1

     output.valNum = -1;

     if(inputstring1[0] == 79 || inputstring1[0] == 111){
             //OhmsLaw? (ASCII 79 & 111 are O & o)
             //evaluate other characters in the string in order to check if the spelling is correct
            // if the spelling is correct, evaluate the ohmsLaw function
            // if the spelling is not correct print an error and evaluate ohmslaw anyway
            //double OhmsLaw(double V, double I, double R) {
           if(val1.unit == 1 ) {
                // val 1 is V
                // program will check for val 2

            if(val2.unit == 2){
                // Val 1 is V and Val 2 is I
                OhmsLaw(&val1.valNum, &val2.valNum, &output.valNum);
                output.unit = 3; // Unit is R
                output.placeVal = 1; // Place val is 10^0
                output.conversion = 0; // No conversion is needed
            }
            else if(val2.unit == 3){
                // Val 1 is V and Val 2 is R
                OhmsLaw(&val1.valNum, &output.valNum, &val2.valNum);
                output.unit = 2; // Unit is I
                output.placeVal = 1;
                output.conversion = 0;
            }

        }

        else if(val1.unit == 2) {
            // Val 1 is I
            // program will check for val 2

            if(val2.unit == 1){
                // Val 1 is I and Val 2 is V
                OhmsLaw(&val2.valNum, &val1.valNum, &output.valNum);
                output.unit = 3; // Unit is R
                output.placeVal = 1; // Place val is 10^0
                output.conversion = 0; // No conversion is needed
            }
            else if(val2.unit == 3){
                // Val 1 is I and Val 2 is R
                OhmsLaw(&output.valNum, &val1.valNum , &val2.valNum);
                output.unit = 2; // Unit is I
                output.placeVal = 1;
                output.conversion = 0;
            }

        }

        else if(val1.unit == 3) {
            // Val 1 is R
            // program will check for val 2

            if(val2.unit == 1){
                // Val 1 is R and Val 2 is V
                OhmsLaw(&val2.valNum, &output.valNum, &val1.valNum);
                output.unit = 2; // Unit is I
                output.placeVal = 1; // Place val is 10^0
                output.conversion = 0; // No conversion is needed
            }
            else if(val2.unit == 3){
                // Val 1 is R and Val 2 is I
                OhmsLaw(&output.valNum, &val2.valNum , &val1.valNum);
                output.unit = 1; // Unit is V
                output.placeVal = 1;
                output.conversion = 0;
            }
        }
           else {
               printf("bad vals\n");
               printf( "Val unit is %d",val1.unit);
           }
    }

else if(inputstring1[0] == 70 || inputstring1[0] == 102){
    // CutoffFreq? (ASCII 70 & 102 are O & o)
    //double CutoffFreq(double *Fc, double *R, double *C) {
    printf("In FC\n");
    if(val1.unit == 5){
       // given value is Fc
       // solve for R
       // val.2 is C
       CutoffFreq(&val1.valNum, &output.valNum, &val2.valNum);
       output.unit = 3; // Unit is R
       output.placeVal = 1;
       output.conversion = 0;
    }

    else if(val1.unit == 3){
       // given value is R
       // solve for Fc
        // val.2 is C
         CutoffFreq(&output.valNum, &val1.valNum, &val2.valNum);
         output.unit = 5; // Unit is Fc
         output.placeVal = 1;
         output.conversion = 0;
    }
    else {
        printf("bad vals\n");
        printf( "Val unit is %d",val1.unit);
    }
}

printf("Val1 %lf\n ", val1.valNum);
printf("Val2 %lf\n ", val2.valNum);
//printf("Val1 %d\n ", val1.unit);
//printf("Val2 %d\n ", val2.unit);
//printf(" input 1 %s\n", inputstring1);
//printf("input 2 %s\n",inputstring2);
//printf(" input3 %s\n",inputstring3);
//printf("input 2 %c\n",inputstring2[0]);
//printf(" input3 %c\n",inputstring3[0]);
/*
V  Voltage     Volts  1
I  Current     Amps   2
R  Resistance  Ohms   3
C  Capacitence Farad  4
Fc Cutoff freq Hz     5
*/
    // print output
    if(output.unit == 1){
        strcpy(unitString, " Volts");
        strcpy(valueString, "V = ");
    }

    if(output.unit == 2){
        strcpy(unitString, " Amps");
        strcpy(valueString, "I = ");
    }

    if(output.unit == 3){
        strcpy(unitString, " Ohms");
        strcpy(valueString, "R = ");
    }

    if(output.unit == 4){
        strcpy(unitString, " Farad");
        strcpy(valueString, "C = ");
    }

    if(output.unit == 5){
        strcpy(unitString, " Hz");
        strcpy(valueString, "Fc = ");
    }




        printf("%s %lf %s\n", valueString, output.valNum, unitString);





}


    return 0;
}
