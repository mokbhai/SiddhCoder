# Importing time and random  module
import time
import random
import math

# Assigning Variables
staticNum = i = losses = score = 0
# i = staticNum = losses = score = int(i)
dice = random.randint(1, 6)
# dice = int(random.randint(1, 6))

def inputYourGuess(staticNum):
    staticNum = input("Input your number")
    return staticNum

def inputUnknown():
    print("Error: Unknown Value")
    printIntro(i)

def printIntro(i):
    print("Input 0 to Play the game. \nInput 1 to Show your score \nInput 2 to Exit the game.")
    i = input()
    if i == 3: inputUnknown()
    return i

def throwingDice(dice):
    print("Trowing a dice", end='.')
    animation()
    dice = random.randint(1, 6)
    return dice

def animation():
    count_seconds = 6
    for i in reversed(range(count_seconds + 1)):
        if i > 0:
            print(end='.', flush=True)
            time.sleep(0.3)
        else:
            print("\n\nDice Shows", dice)

def matchWithInput(staticNum, dice, score, losses):
    if dice == staticNum:
        score += 1
        print("\nHurray!! You guessed correct\n")
    else:
        losses += 1
        print("\nOOPS!! You guessed wrong. \nBetter Luck Next Time\n")
    return score, losses

def showScore(score, losses):
    print("Your score is", score, "\nYou Lost", losses, "times" "\n")

def exitGame():
    print("Exiting The Game")
    animation()
    showScore(score, losses)


while i != 2:
    printIntro(i)
    if i == 1: 
        showScore(score, losses)
        continue
    if i == 2:
        exitGame()
        break
    inputYourGuess(staticNum)
    throwingDice(dice)
    matchWithInput(staticNum, dice, score, losses)
    showScore(score, losses)


def gameOn():
    pass