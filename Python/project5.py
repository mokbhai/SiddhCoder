import random
k = int(input('To PLAY GAME enter 0 \nTo EXIT GAME enter 1 \n'))
wins = fails = 0
while k in range(0, 1):
    b=0
    print("You have 5 chances")
    rad = random.randrange(0, 9)

    while b<6:
        c = int(input("\nguess the number: "))
        if c<rad:
            print("low")
        elif c>rad:
            print("High")
        else:
            print("\nCongratulation!! you won")
            print(b,"no of guess you took")
            wins+=1
            break
        print(5-b,"no of gueess left")
        b=b+1
        if(b>5):
            print("\nOOPS!! game over you lose")
            print("The number was ", rad)
            fails += 1
    k = int(input('To PLAY GAME enter 0 \nTo Play Last GAME enter 1 \n'))

print('Exiting the game...')
print('Your score is')
print("Wins", wins, '/nLosese', fails)

