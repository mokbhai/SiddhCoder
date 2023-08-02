# Importing time and random  module
import time
import random

# Assigning Variables
staticNum = i = j = 1
losses = score = 0

# While Loop
while j != 0:
    print("Input 1 to Play the game. \nInput 2 to Show your score \nInput 0 to Exit the game.")
    i = input()
    j = i

    if i == 0:
        break

    print("\n")
    while i != 0:
        print("Input your number")
        staticNum = input()
        print("\n")
        print("Trowing a dice", end='.')
        count_seconds = 6
        dice = random.randint(1, 6)
        for i in reversed(range(count_seconds + 1)):
            if i > 0:
                print(end='.', flush=True)
                time.sleep(0.3)
            else:
                print("\n\nDice Shows", dice)
        if dice == staticNum:
            print("\nHurray!! You guessed correct\n")
            score += 1
            print("Your score is", score, "\nYou Lost", losses, "time"  "\n")

        else:
            losses += 1
            print("\nOOPS!! You guessed wrong. \nBetter Luck Next Time\n")
            print("Your score is", score, "\nYou Lost", losses, "times" "\n")
