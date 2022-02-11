
#include "IsNum.h"
#include "UnitConvert.h"
#include <strings.h>
#include <stdio.h>





// convert a string to an double

/*
Unit Assignments:
StringToDouble allows different units. Each unit is symbolized by a different integer.
Unit: Int
V  Voltage     Volts  1
I  Current     Amps   2
R  Resistance  Ohms   3
C  Capacitence Farad  4
Fc Cutoff freq Hz     5

if the unit is not a base unit, it is set up to be converted with the UnitConvert function

*/
// string must be structured as type = value unit
// Ex: V = 15.0V   ---> Value: 15.0, Conversion: 0, PlaceVal: 0, Unit: 1
// Ex: A = 1000mA  ---> Value: 1000.0, Conversion: 2, PlaceVal: -3, Unit: 2


//is function call


// pow function, but with integers. used for changing the place value of a number
int intpow(int base, int exp) {
    int i;
    int power = 1;
    for (i = 0; i < exp; i++) {
        power = power * base;
    }
  return power;
}

//int stringlength,

void StringToDouble(char *string,double* value, int* conversion, int* placeVal, int* unit) {

    // first the unit type is taken out and assigned to the unit

    if(string[0] == 86 || string[0] == 118) {
        // string location 0 is either V or v, this means that the unit is volts
        // volts is represented by 1, so unit is assigned as 1
        *unit = 1;
    }

    else if(string[0] == 73 || string[0] == 105) {
        // string location 0 is either I or i, this means that the unit is Amps
        // Amps is represented by 2, so unit is assigned as 2
        *unit = 2;
    }

    else if(string[0] == 82 || string[0] == 114) {
        // string location 0 is either R or r, this means that the unit is Ohms
        // Ohms is represented by 3, so unit is assigned as 3
        *unit = 3;
    }

    else if(string[0] == 67 || string[0] == 99) {
        // string location 0 is either C or c, this means that the unit is Farads
        // Farads is represented by 4, so unit is assigned as 4
        *unit = 4;
    }

    else if((string[0] == 70 || string[0] == 102)) {
        // string location 0 is either F or f, this means that the unit is Hz
        // Frequency is represented by 5, so unit is assigned as 5
        *unit = 5;
    }

    // Now the unit has been read, j is set to 1 so the while loop begins after the unit

    int j = 1;
    int num;
    int convint[20];
    int deci;
    int deciNum;
    double convDeci[20];
    int count;
    int start = 0;
    int intct;
    int dcifg = 0;
    double newFloat = 0;
    // while loop while string at j is a number, decimal point (46), or equal sign (61)
    while(((IsNum(string[j]) == 1) || string[j] == 61) && dcifg == 0) {
        if(string[j] == 61) { // skip over the equal sign
            j++;

        }
        start = j;
        // find numbers before the decimal point
        if(IsNum(string[j]) == 1) {
            num = string[j];
           // printf("numstrng %d\n", string[j]);
          //  printf("stringg %s\n", &string[j]);
            convint[j] = (num - 48);
           // printf("convint%d ", convint[j]);
           // printf("j = %d\n", j);
            j++;
            //printf("num: %d\n", num);
        }


        }

        // if there is a decimal
       // if(string[j] == 46 ) {
           // printf("founddeci/n");
            deci = j;
            j++;
            dcifg = 1;

            intct = j;
            j++;

            while((IsNum(string[j]) == 1) && dcifg == 1) {
               // printf("inwhileYYYYYYY");
                deciNum = string[j];
                convDeci[j] = deciNum - 48;
                //printf("convdeci%lf ", convDeci[j]);
                j++;
            }
        //}
        // if there is no decimal, assign the decimal place to the place after the number
       /* else {
            deci = j;
            j++;
            intct = j;
        }*/
       // printf("deci %d\n", deci);
       for (count = (start-1); count < (deci); count++) {
            convint[count] = convint[count] * (intpow(10,(intct-count-2)));
           // printf("j = %d\n", j);
          //  printf("convint%d ", convint[count]);
          //  printf("count%d\n", count);
            newFloat = (convint[count] + newFloat);
        }

        if ((j-deci) > 1){
           // printf("in j-deci/n");
            for(int ct = (deci+1); ct < j; ct++) {
                convDeci[ct] = (convDeci[ct] * (pow(10,(deci+1)-ct)));
                //printf("condeci is %lf\n", convDeci[ct]);
                newFloat = (convDeci[ct] + newFloat);


            }
        }

        *value = newFloat;
        //printf("newFloat is %lf\n", newFloat);


int d = deci;
// after the value has been assigned, the function reads the unit at the end of the string and prepares the value for a unit conversion
// this conversion is then executed with unit convert
// the function allows values of base, milli, and micro. milli and micro will be converted to base
//j++;
        //printf("string j %c", string[deci]);
    if(string[d] != 109 && string[d] != 117 ) {
        // string location j is either V or v or A or a or O or o or F or f or H or h
        // if no unit is given this is the default
        // this means that a unit conversion is not necessary
        *conversion = 0; // do not convert
        *placeVal = 1; // is base
    }
    else if(string[d] == 109){
        // string location j is m, this means that the value is in milli
        // this means that it must be converted from milli to base
        *conversion = 2; // convert from milli to base
        *placeVal = -3; // place val is 10^-3
    }
    else if(string[d] == 117){
        // string location j is u, this means that the value is in micro
        // this means that it must be converted from micro to base
        *conversion = 4; // convert from micro to base
        *placeVal = -6; // place val is 10^-6
    }


    // if a unit conversion is needed, it is preformed here
    // the function will always output in base units
    // void UnitConvert(double* value, int* conversion, int* placeVal)
    UnitConvert(  value,conversion, placeVal );

//printf("\nconv %d\n", *conversion);
//printf("plcvl %d\n",*placeVal);








}
