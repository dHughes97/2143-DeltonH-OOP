## P04- Roll them Bones!
### Delton Hughes 

### Description:

- Creating two classes Die and Dice, these classes will make 
instance of one die or multiple dice and roll them if need be. 
It will implement convenience of use for the user converting 
strings entered in parameterized zone in function into an integers/floats.
In the end this program will allow the user to create as many dice or die as 
they want and roll said dice. It also allows the user to input DnD notation 
such as "4d20" in the paramater zone in Dice().


### Files

|   #   | File      | Description                      |
| :---: | --------- | -------------------------------- |
|   1   | main.py  | creating instances of dice and rolls . |
|   2   | dice.py  | Implementation file. |
|   3  | Banner.cpp| Banner uploaded.                 |                  

### Instructions
 -dice. py should have the following imported 
 ```
    import sys
    import random
 ```
 -To use the main.py file all that is need is to import the files 
 ```
 from dice import Die
 from dice import Dice
 ```
 -Example of usage will be in example command area below 
 -Below is what the final output will look like on the console
 ```
    Testing 6 sided die for 10 rolls:
        [ 6 1 2 4 4 1 3 3 2 1 ]
    Testing 20 sided die for 20 rolls:
        [ 1 12 7 12 10 14 11 3 16 15 12 7 14 16 20 16 18 3 14 15 ]
    Rolling 5 10 sided dice 10 times to get the max value:
        [ 8 10 10 10 8 6 9 10 10 8 ]
    Rolling 5 10 sided dice 10 times to get the min value:
        [ 2 2 1 4 2 1 2 2 1 2 ]
    Rolling 5 10 sided dice 10 times to get the avg value:
        [ 4.40 3.40 6.20 5.80 5.60 5.20 5.00 6.80 3.80 5.60 ]
    Rolling 8 20 sided dice 20 times to get the max value:
        [ 18 19 20 19 17 9 20 13 20 20 13 17 20 20 19 19 20 20 19 20 ]
 ```

### Example Command
- This is an example to get desired output in console for testing dice rolls viability
```
    #creating instances of the dice/die
    d1 = Die()
    d2 = Die(20)
    d3 = Dice(10, 5)
    d4 = Dice("8.d.20")
    #testing the created instances and printing to console
    dieTester(d1, 10)
    dieTester(d2, 20)
    dieTester(d3, 10, "max")
    dieTester(d3, 10, "min")
    dieTester(d3, 10, "avg") 
    dieTester(d4, 20, "max")
    
```
