from dice import Die
from dice import Dice


if __name__ == '__main__':
    #d1 = Die()
    #d2 = Die(20)
    
    #print(d1)
    #print(d2)
    #print(d1.roll())
    #print(d2.roll())

    # threeD6 = Dice(sides=20, num_dice=6)
    # rolls = threeD6.rollSum()
    # print(f"Result: {rolls}")
    # findMax = threeD6.maxRoll()
    # avgR = threeD6.avgRoll()
   
    # print(threeD6)
    # #finds the maximum number out of the list of rolls
    # print("This is the maximum: ", findMax)
    # #find the average of the dice rolls 
    # print("This is the average of the rolls: ", avgR)
    
    d20_4 = Dice(1,6)
    d20_4.stringDice("4.d.20")
    
    print("This is the sum: ",d20_4.rollSum())
    print("This is the maximum: ",d20_4.maxRoll())
    