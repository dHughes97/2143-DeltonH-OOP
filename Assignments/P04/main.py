from dice import Die
from dice import Dice

#########################################
# def dieTester(d_d, runs=10, test_type="sum")
#
# Descripition: This uses concatenation to print 
# given numbers entered for user convenience. Will 
# also print the rolls and put them into a visible
# list on the console. 
# Usage:
#   - dieTester(d1, 10)
#   - dieTester(d2, 20)
#   - dieTester(d3, 10, "max")
#   - dieTester(d3, 10, "min")
#   - dieTester(d3, 10, "avg") 
#   - dieTester(d4, 20, "max")   
#
###########################################
def dieTester(d_d, runs=10, test_type="sum"):
    """Example function to test a die or dice."""
    if isinstance(d_d, Die):
        print(f"Testing {d_d.sides} sided die for {runs} rolls:")  
        print("[ ", end="")
        for i in range(runs):               #rolls and creates the list on console
            print(d_d.roll(), end=" ")      #actual rolls 
        print("]")
    elif isinstance(d_d, Dice):                 #catch case when running avg,max, min  
        print(f"Rolling {len(d_d.dice)} {d_d.sides} sided dice {runs} times to get the {test_type} value:")
        print("[ ", end="")
        for i in range(runs):
            if test_type == "avg":              #avg
                print(d_d.avgRoll(), end=" ")   
            elif test_type == "min":            #min
                print(d_d.minRoll(), end=" ")
            elif test_type == "max":            #max
                print(d_d.maxRoll(), end=" ")
            else:                               #sum
                print(d_d.rollSum(), end=" ")
        print("]")
    else:
        print("Invalid input: must be a Die or Dice object.")

if __name__ == '__main__':
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
    
    