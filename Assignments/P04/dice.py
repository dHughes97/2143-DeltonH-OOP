 #########################################################################
 #
 #  Author:           Delton Hughes
 #  Email:            dlhughes0129@my.msutexas.edu
 #  Label:            P03
 #  Title:            Graphviz
 #  Course:           CMPS 2143
 #  Semester:         Spring 2023
 #
 #  Description:
 #    This program is to create and compile the syntax for the 
 #    Graphviz online compiler. Essentially we will make a program
 #    which will link nodes and style said nodes. Whether that be an
 #    edge or the node itself. Then it will print out syntax to 
 #    the compiler and the "outfile.txt".
 # 
 #  Usage:
 #       -Allows the user to dynamicall create a linked list or a Vector
 #       -Also allows for user to +,-,*, print to outfile using fout <<, 
 #         print to console using cout <<, use [] to insert an integer, 
 #         and lastly check if 2 vectors are equivalent using ==. 
 #
 #  Files:
 #       main.cpp      :driver program
 #       output.txt    :txt file printint program output
 ########################################################################

import random
###########################################
# Name: Die
#
# Descripition: Will initialize the default
#sides of a die to 6 or give the user the 
#option to enter the amount of sides of
#said dice. Also will ask the user how many
#times they want to roll the die. Will lastly
#do a conversion of the integer into a string
#(so we can see output).
# Methods:
# -def __init__(self, sides=6)
# -def __init__(self, sides)
# -def roll(self, rolls=1)
# Usage:
#
#
###########################################
class Die:
    def __init__(self, sides=6):
        self.sides = sides


    def roll(self, rolls=1):
        #initialize sum to 0 
        sum = 0 
        #makes a for loop increment the amount of rolls
        for _ in range(rolls):
            #returns the sum of the randim int + 1
            sum += random.randint(1, self.sides)
        return sum 
    
    def __str__(self):
        pass
    
    


###########################################
# Name: Dice
#
# Descripition:
#
# Private Methods:
#
#
# Public Methods:
#
# Usage:
#
#
###########################################
class Dice: 
    pass




