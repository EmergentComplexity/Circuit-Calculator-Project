// ISNum Function
// Determines if a character can be converted into a number. ASCII 48-57 represent numbers

int IsNum (int charNum) {
    int isNumber;
    if (charNum > 47 && charNum < 58) {
        isNumber = 1;
    }
    else {
        isNumber = 0;
    }
    return isNumber;
}
