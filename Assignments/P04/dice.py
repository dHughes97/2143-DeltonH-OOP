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
 #     
 #          
 #        
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
#
#
###########################################
class Die(object):
  #self is variable name not reserved 
  def __init__(self,sides=None):
        if not sides: 
            self.sides = 6
        else: 
            if not isinstance(sides, int):
                print("error: sides is not an integer!")
                sys.exit()
            self.sides = sides 
      
      
#returns a random value between whatever sides we have 
  def roll(self, shuffles=1):
      values = [x for x in range(self.sides)]
      random.shuffle(values)
      return values[0]+1

  
#if you dont print conversion of string 
#it will return just an address 
  def __str__(self): 
    return f"[sides: {self.sides}]"


###########################################
# Name: Dice
#
# Descripition:
#
# Methods:
#
# Usage:
#
#
###########################################

class Dice(object):
  #creating some number of dices based of the sides 
  def __init__(self,sides=None,num_dice=1):
    if not sides: 
      print("Need to pass in sides!!")
      sys.exit()
      
      #create a container
    self.dice=[]
    
    for die in range(num_dice):
      self.dice.append(Die(sides))

  def stringDice(self,dStr):
      box1 = dStr.split(".d.")
      box2 = [int(box1[0]),int(box1[1])]
      if self.dice : self.dice.clear()
      for x in range(box2[0]):
         self.dice.append(Die(box2[1]))

  def rollSum(self): 
    total = 0
    for d in self.dice:
      #is calling roll from Die class
      total += d.roll()
    return total 

  def maxRoll(self, rolls=1):
      roll_result = [d.roll() for d in self.dice]
      #max_roll keeps track of largest number real time
      max_num = roll_result[0]
      #checking for the largest number 
      for r in roll_result: 
        if r > max_num: 
          max_num = r
      return max_num 
  

  def avgRoll(self):
    avg = self.rollSum()
    nDice = len(self.dice)
    avg = avg / nDice
    #formats the avg to 2nd decimal place
    return "{:.2f}".format(avg)
  
  
  def roll(self,rollType=None): 
    if rollType == 'max':
      return self.max()
    elif rollType =='min':
      return self.min()
    elif rollType =='min':
      return self.avg()
    else:
      return self.sum()
 

  def __str__(self): 
    s = ""
    for d in self.dice: 
      s = s + f"[sides: {d.sides}]\n"
    
    return s





