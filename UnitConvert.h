

#include <math.h>


// Unit Conversion Function
/*Function can convert the units of a value */

void UnitConvert(double* value, int* conversion, int* placeVal){
    // Convert base to milli
    if(*conversion == 1 && *placeVal == 1) {       // Check if right conversion and place value
        *value = *value * 1000;                    // multiply the value by 1000
        *placeVal = -3;                            // value is now value * 10^-3
        *conversion = 0;                           // conversion is done, so = 0
    }

    // Convert milli to base
    if(*conversion == 2 && *placeVal == -3) {      // Check if right conversion and place value
        *value = *value / 1000;                    // divide the value by 1000
        *placeVal = 1;                             // value is now value * 10^0
        *conversion = 0;                           // conversion is done, so = 0
    }

    // Convert base to micro
    if(*conversion == 3 && *placeVal == 1) {       // Check if right conversion and place value
        *value = *value * pow(10,6);               // multiply the value by 10^6
        *placeVal = -6;                            // value is now value * 10^-6
        *conversion = 0;                           // conversion is done, so = 0
    }

    // Convert micro to base
    if(*conversion == 4 && *placeVal == -6) {      // Check if right conversion and place value
        *value = *value / pow(10,6);               // divide the value by 10^6
        *placeVal = 1;                             // value is now value * 10^0
        *conversion = 0;                           // conversion is done, so = 0
    }
    // Base to Base (No Conversion)
    // conversion is 0 and placeVal is 0
    // no if statements execute

}
