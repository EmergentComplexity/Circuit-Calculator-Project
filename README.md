# Circuit-Calculator-Project


The purpose of this project was to create a program that could be used to evaluate a various electrical engineering equation based on input syntax



Input(s): 
     For the input, the program will take read in three strings from a line of code separated by spaces. The first string refers to the function that is being performed, and the other two strings are the values which will be operated on. The two functions include Ohms which calculates Ohm’s law, and Fc which calculates the cutoff frequency equation
Shown below are some of the possible inputs. Notice how the case size of the units does not matter. The program also allows units such as mV. In addition, it does not matter whether there is a decimal.  If there is no decimal in the input value, one is added when the value is converted from a string to a float

        1.  Fc F=12Hz C=0.000003F
        2.  Ohms V=15mv R=12.97Ohms
        3.  Ohms v=15v r=12.97Ohms
        
     
Output(s):
     The program takes the input data and solves the equation requested in the input. The equation may be solved in different ways for example both v = IR and I = v/R.  The program outputs the value from the requested equation that is missing from the input. The program itself is able to determine which value is missing and then conduct the proper transformation of the input values in order to calculate this missing value.
The shown outputs are the outputs which would be printed out for each of their respective inputs in the above section.
         1.  R =  442.321302  Ohms
         2.  I =  0.001181  Amps
         3.  I =  1.181102  Amps
      
      
 -  Two basic formulas are used in this program: Ohms Law: V = I * R , and the Cutoff Frequency Equation: Fc = 1/(2piRC). 
 -  Pi is defined as 3.14
 -  The Ohms law equation is able to be manipulated in the program to solve for any value V,I, or R
 -  The Cutoff Frequency equation is able to be manipulated to solve for either Fc or R. ( C is always given)
 -  ASCII decimal equivalents are used to convert strings 
    
    
The program can accept a wide variety of syntax. The only assumptions made are that the input must be 3 strings, the first letter of the first string must correspond to an accepted function (‘F’ for Cutoff frequency, ‘O’ for Ohm’s law, capitalization is not important). The 2nd and 3rd strings must have a first character that informs of the quantity being measured (Ex: ‘V’ for volts ‘I’ for current ‘F’ for frequency etc...) an equal sign then may or may not follow. After this the string must contain numbers representing the magnitude of the value. The value may or may not have a decimal point. After the number there may be a unit. If the value is in mV for example, the unit must be given so it can be converted to V, otherwise base units are assumed for all values
       
![Screen Shot 2022-02-10 at 11 33 15 PM](https://user-images.githubusercontent.com/84114155/153547020-f4f47add-0161-4ba9-bf0a-30f81e82a32d.png)


In this image, variety of different input syntax is used, each with the same result. Ah error is only shown on the 2nd to last  run of the program because The quantity to which 12.97 represents is not given.

