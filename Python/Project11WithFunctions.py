# importing Randome module
import random

# input starting and ending Value from user
startingValue = input("Starting value: ")
endingValue = input('Ending Value: ')

# defining int
startingValue = int(startingValue)
endingValue = int(endingValue)
arr = (startingValue, endingValue)

# Approch
pickRandom = random.randint(startingValue, endingValue)

print("Range is", arr, "and randomly picked number is", pickRandom)


# Creating Functions

def checkPositiveOrNegative():
    # Is random number positive or negative
    print(pickRandom, "is a positive" if pickRandom>0 else "is a negative", "number")


def checkOddOrEven():
    # Is random number even or odd
    print(pickRandom, "is an even number" if pickRandom%2==0 else "is an odd number")


def checkPrimeOrNot():
    # prime numbers can't be negative
    if pickRandom > 1:
        # Iterate from 2 to n / 2
        for i in range(2, int(pickRandom/2)+1):
            # If Random is divisible by any number between 2 and n / 2, it is not prime
            if (pickRandom % i) == 0:
                print(pickRandom, "is a composite number")
                break
        else:
            print(pickRandom, "is a prime number")
    else:
        print(pickRandom, "is a composite number")

# Calling Functions
checkPositiveOrNegative()
checkOddOrEven()
checkPrimeOrNot()
