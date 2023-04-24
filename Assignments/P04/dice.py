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
 #     In this program we are going to be making instances of Die and 
 # Dice, we are goign to implement methods which will allow us to pass
 # in as many sides dice as needed. Also be able to pass in a string 
 # in DND notation "4d20" and allow a user to roll N amounts of chosen       
 # sides of dice. 
 #  Usage:
 #       - 
 #       -
 #       - 
 #
 #  Files:
 #       main.py      :testing file
 #       dice.py      :implementation file
 ########################################################################
import sys
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
# -d2.roll()
# -Dice(10,5) or Dice("4.d.20")
# -Die() or Die(20)
###########################################
class Die(object):
  ###########################################
  #  def __init__(self,sides=None)
  #
  # Descripition: Sets die sides to default 
  # to 6. If anything else is put in it will 
  # return the else. Allows the user to put 
  # in a manual # of sides. 
  # Usage:
  # -Dice(10,5) or Dice("4.d.20")
  #
  ###########################################
  def __init__(self,sides=None):
        if not sides: 
            self.sides = 6
        else: 
            if not isinstance(sides, int):
                print("error: sides is not an integer!")
                sys.exit()
            self.sides = sides 
      

###########################################
#  def __init__(self,sides=None)
#
# Descripition: Returns the numbers of sides 
# in given format. 
#
# Usage: if you dont print conversion of string 
#it will return just an address
# -Die() or Die(20)
#
###########################################
 
  def __str__(self): 
    return f"[sides: {self.sides}]"

###########################################
# def roll(self, shuffles=1)
#
# Descripition: Will return a random number 
# between 1 and the number entered. 
#
# Usage:
# -d2.roll()
#
###########################################      
#returns a random value between whatever sides we have 
  def roll(self, shuffles=1):
      values = [x for x in range(self.sides)]
      random.shuffle(values)
      return values[0]+1



###########################################
# Name: Dice
#
# Descripition: Allows the user to create 
# instances of multiple dice and roll them.
# Will implement the average, minimum, maximum
# and sum of the rolls. 
#
# Methods:
# -def __init__(self,sides=None,num_dice=1)
# -def rollSum(self)
# -def maxRoll(self, rolls=1)
# -def minRoll(self, rolls=1)
# -def avgRoll(self)
# -def __str__(self)
# Usage:
# -Dice(10,5) or Dice("4.d.20")
# -d2.rollSum()
# -dieTester(d3, 10, "sum")
###########################################

class Dice(object):
  ###########################################
  #  def __init__(self,sides=None,num_dice=1)
  #
  # Descripition: Defaults the dice to one 1 die,
  # gives some catch cases for wrong input(error checking).
  # appends die to the a list and also checks for string 
  # syntax as a parameter and if entered will split the 
  # string into the list and convert to integers. 
  # Usage:
  # -Dice(10,5) or Dice("4.d.20")
  #
  ###########################################
  def __init__(self,sides=None,num_dice=1):
    if not sides: 
      print("Need to pass in sides!!")
      sys.exit()
    
    elif isinstance(sides, str):
      test = sides.split('.')                      #splits the list by '.'
      num_dice, sides = int(test[0]), int(test[2]) #turns whats in the index to int
    self.sides = sides
                                                  
    self.dice=[]                                   #create a container
    
    for die in range(num_dice):                    #append dice to list
      self.dice.append(Die(sides))


  #########################################
  # def rollSum(self):
  #
  # Descripition: Will caluclate the dum of 
  # all dice rolled.
  # Methods:
  #
  # Usage:
  # -d2.rollSum()
  # -dieTester(d3, 10, "sum")
  #
  ###########################################
  def rollSum(self): 
    total = 0
    for d in self.dice:
                         #is calling roll from Die class
      total += d.roll()  #adds all the dice rolled
    return total 

  #########################################
  # def maxRoll(self, rolls=1)
  #
  # Descripition: This will find the maximum
  # number rolled out of multiple given dice 
  # rolled.
  #
  # Usage:
  # -d2.maxRoll()
  # -dieTester(d3, 10, "max")
  #
  ###########################################
  def maxRoll(self, rolls=1):
      roll_result = [d.roll() for d in self.dice]
      #max_roll keeps track of largest number real time
      max_num = roll_result[0]
      #checking for the largest number 
      for r in roll_result: 
        if r > max_num:    
          max_num = r
      return max_num 
  
  #########################################
  # def minRoll(self, rolls=1)
  #
  # Descripition:This will find the minimum
  # number rolled out of multiple given dice 
  # rolled.
  #
  # Usage: 
  # -d2.minRoll()
  # -dieTester(d3, 10, "min")
  #
  ###########################################
  def minRoll(self, rolls=1):
       roll_result = [d.roll() for d in self.dice]
      #min_roll keeps track of largest number real time
       min_num = roll_result[0]
      #checking for the largest number 
       for r in roll_result: 
        if r < min_num: 
          min_num = r
       return min_num 

  #########################################
  # def avgRoll(self)
  #
  # Descripition: Will use the rollSum() 
  #function and will divide by n amounts times
  #the dice has been rolled. 
  #
  # Usage: 
  # -d2.avgRoll()
  # -dieTester(d3, 10, "avg")
  #
  ###########################################
  def avgRoll(self):
    avg = self.rollSum()    #sets the sum to avg
    nDice = len(self.dice)
    avg = avg / nDice       #computes the avg 
    #formats the avg to 2nd decimal place
    return "{:.2f}".format(avg)
  
  


  
 
  #########################################
  # def __str__(self)
  #
  # Descripition:Just converts the number of 
  # sides entered into a string and puts in 
  # given notation. 
  #
  ###########################################
  def __str__(self): 
    s = ""
    for d in self.dice: 
      s = s + f"[sides: {d.sides}]\n"
    
    return s





